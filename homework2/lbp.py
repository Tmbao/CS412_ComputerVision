import cv2


class LBP(object):

  _neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

  def compute(self, image, keypoints):
    ret_keypoints = []
    descriptors = []
    for keypoint in keypoints:
      x, y = keypoint.pt
      if 0 < x < image.shape[0] - 1 and 0 < y < image.shape[1] - 1:
        lbp_value = 0
        for index, neighbor in enumerate(self._neighbors):
          dx, dy = neighbor
          if image[x + dx, y + dy] < image[x, y]:
            lbp_value |= 1 << index
        descriptors.add(lbp_value)
        ret_keypoints.add(keypoint)
    return ret_keypoints, descriptor


         

