import cv2
import harris


def get_detector(detector_name, params):
  
  if detector_name == 'harris':
    detector = harris.HarrisDetector(
      params['quality_level'],
      params['block_size'],
      params['aperture_size'],
      params['alpha'],
      params['feature_size'])
  elif detector_name == 'blob':
    detector = cv2.SimpleBlobDetector()
  elif detector_name == 'dog':
    detector = cv2.xfeatures2d.SIFT_create(
      params['n_features'],
      params['n_octave_layers'],
      params['contrast_threshold'],
      params['edge_threshold'],
      params['sigma'])

  return detector
