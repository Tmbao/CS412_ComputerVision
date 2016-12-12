import sys
import cv2
import numpy as np
import detectors
import descriptors
import settings


PROJ_WIN = 'Assignment 2'
TRACK_WIN = 'Trackbars'
params = settings.params


def print_help():
  print ("harris image.jpg - detect key points using harris\n"
         "   algorithm and show the keypoints in original image.\n"
         "blob image.jpg - detect key points using blob algorithm\n"
         "   and show the keypoints in original image.\n"
         "dog image.jpg - detect key points using DoG Algorithm\n"
         "   and show keypoints in original image.\n"
         "m harris sift - image1.jpg image2.jpg match and show results of image1 and image2\n"
         "   using Harris detector and SIFT descriptor.\n"
         "m dog sift image1.jpg image2.jpg - match and show results of image1 and image2\n"
         "   using DoG detector and SIFT descriptor.\n"
         "m blob sift image1.jpg image2.jpg - match and show results of image1 and image2\n"
         "   using using Blob detector and SIFT descriptor.\n"
         "m harris lbp image1.jpg image2.jpg - match and show results of image1 and image2\n"
         "   using Harris detector and LBP descriptor.\n"
         "m dog lbp image1.jpg image2.jpg - match and show results of image1 and image\n"
         "   using DoG detector and LBP descriptor.\n"
         "m blob lbp image1.jpg image2.jpg - match and show results of image1 and image2\n"
         "   using Blob detector and LBP descriptor.\n"
         "h - display this help windows.")


def wait():
  if cv2.waitKey(0) == 'q':
    sys.exit(0)


def visualize_keypoints(image, keypoints):
  kp_image = np.array([])
  kp_image = cv2.drawKeypoints(image, keypoints, kp_image, flags=cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
  cv2.imshow(PROJ_WIN, kp_image)
  wait()


def visualize_matches(image1, keypoints1, image2, keypoints2, matches):
  m_image = np.array([])
  m_image = cv2.drawMatches(
      image1, keypoints1,
      image2, keypoints2,
      [match[0] for match in matches],
      m_image)
  cv2.imshow(PROJ_WIN, m_image)
  wait()


def main(argv):
  if len(argv) == 2:
    detector = detectors.get_detector(argv[0], params[argv[0]])

    image = cv2.cvtColor(cv2.imread(argv[1]), cv2.COLOR_BGR2GRAY)

    keypoints = detector.detect(image)

    visualize_keypoints(image, keypoints)

  elif len(argv) == 5:
    detector = detectors.get_detector(argv[1], params[argv[1]])
    descriptor = descriptors.get_descriptor(argv[2])
    matcher = cv2.BFMatcher()

    image1 = cv2.cvtColor(cv2.imread(argv[3]), cv2.COLOR_BGR2GRAY)
    image2 = cv2.cvtColor(cv2.imread(argv[4]), cv2.COLOR_BGR2GRAY)

    keypoints1 = detector.detect(image1)
    keypoints2 = detector.detect(image2)

    keypoints1, descriptors1 = descriptor.compute(image1, keypoints1)
    keypoints2, descriptors2 = descriptor.compute(image2, keypoints2)

    print type(descriptors1), type(descriptors2)

    matches = matcher.knnMatch(descriptors1, descriptors2, k=2)
    matches = sorted(matches, key=lambda x: x[0].distance)

    visualize_matches(image1, keypoints1, image2, keypoints2, matches[:100])


def on_quality_level_change(value):
  value = max(value, 1)
  params['harris']['quality_level'] = value / 100.0
  main(sys.argv[1:])


def on_n_octave_layers_change(value):
  value = max(value, 1)
  params['dog']['on_n_octave_layers'] = value
  main(sys.argv[1:])


def on_maximum_area_change(value):
  value = max(value, 1)
  params['blob']['max_area'] = value * params['blob']['min_area']
  main(sys.argv[1:])


def create_trackbar(detector_name):
  if detector_name == 'harris':
    cv2.createTrackbar('Quality level', TRACK_WIN, 1, 100, on_quality_level_change)
  elif detector_name == 'blob':
    cv2.createTrackbar('Maximum area', TRACK_WIN, 1, 400, on_maximum_area_change)
  elif detector_name == 'dog':
    cv2.createTrackbar('Number of octave layers', TRACK_WIN, 1, 10, on_n_octave_layers_change)


def setup_environment(argv):
  global params

  cv2.namedWindow(PROJ_WIN)
  cv2.namedWindow(TRACK_WIN)

  if len(argv) == 2:
    create_trackbar(argv[0])
  elif len(argv) == 5:
    create_trackbar(argv[1])
  else:
    print_help()
    return False

  return True


if __name__ == '__main__':
  if setup_environment(sys.argv[1:]):
    main(sys.argv[1:])
