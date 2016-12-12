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
    blob_params = cv2.SimpleBlobDetector_Params()
    blob_params.filterByArea = params['filter_by_area']
    blob_params.minArea = params['min_area']
    blob_params.maxArea = params['max_area']
    blob_params.minThreshold = params['min_threshold']
    blob_params.maxThreshold = params['max_threshold']
    blob_params.filterByColor = params['filter_by_color'];
    blob_params.blobColor = params['blob_color'];
    blob_params.filterByCircularity = params['filter_by_circularity'] 
    blob_params.minCircularity = params['min_circularity']
    blob_params.filterByConvexity = params['filter_by_convexity']
    blob_params.minConvexity = params['min_convexity']
    blob_params.filterByInertia = params['filter_by_inertia']
    blob_params.minInertiaRatio = params['min_inertia_ratio']
    detector = cv2.SimpleBlobDetector_create(blob_params)
  elif detector_name == 'dog':
    detector = cv2.xfeatures2d.SIFT_create(
      params['n_features'],
      params['n_octave_layers'],
      params['contrast_threshold'],
      params['edge_threshold'],
      params['sigma'])

  return detector
