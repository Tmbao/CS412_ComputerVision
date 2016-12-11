import cv2
import numpy as np


class HarrisDetector(object):
  def __init__(self, 
      quality_level, 
      block_size, 
      aperture_size, 
      alpha, 
      feature_size):
    self._quality_level = quality_level
    self._block_size = block_size
    self._aperture_size = aperture_size
    self._alpha = alpha
    self._feature_size = feature_size

  def detect(self, image):
    harrisResponse = cv2.cornerHarris(image, 
        self._block_size,
        self._aperture_size,
        self._alpha)
    points = np.argwhere(harrisResponse > harrisResponse.max() * self._quality_level)
    return [cv2.KeyPoint(point[0], point[1], self._feature_size) for point in points]
