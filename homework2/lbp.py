import cv2
import numpy as np


class LBP(object):

  _neighbors = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]


  def __init__(self, window_size=15):
    self._window_size = window_size


  def compute(self, image, keypoints):

    def get_lbp_value(x, y):
      lbp_value = 0
      for index, neighbor in enumerate(self._neighbors):
        dx, dy = neighbor
        if image[x + dx, y + dy] < image[x, y]:
          lbp_value |= 1 << index
      return lbp_value

    ret_keypoints = []
    descriptors = []
    half_window_size = self._window_size / 2
    for keypoint in keypoints:
      x, y = keypoint.pt
      x = int(x)
      y = int(y)
      if 0 < x < image.shape[0] - 1 and 0 < y < image.shape[1] - 1 and 0 < x + half_window_size < image.shape[0] - 1 and 0 < y + half_window_size < image.shape[1] - 1:
        window = []
        for ix in xrange(x - half_window_size, x + half_window_size + 1):
          for iy in xrange(y - half_window_size, y + half_window_size + 1):
            window.append(get_lbp_value(ix, iy))
        window = np.histogram(np.array(window), bins=range(257))
        descriptors.append(window[0])
        ret_keypoints.append(keypoint)
    descriptors = np.array(descriptors)
    descriptors = np.reshape(descriptors, (-1, 256))
    return ret_keypoints, np.uint8(descriptors)        

