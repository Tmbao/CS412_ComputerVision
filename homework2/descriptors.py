import cv2
import lbp


def get_descriptor(descriptor_name):

  if descriptor_name == 'sift':
    descriptor = cv2.xfeatures2d.SIFT_create()
  elif descriptor_name == 'lbp':
    descriptor = lbp.LBP()

  return descriptor
