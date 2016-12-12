params = {
    'harris': {
      'quality_level': 0.01,
      'block_size': 3,
      'aperture_size': 3,
      'alpha': 0.04,
      'feature_size': 1
      },
    'blob': {
      'filter_by_area': True,
      'min_area': 25.0,
      'max_area': 5000.0,
      'filter_by_color': True,
      'blob_color': 255,
      'min_threshold': 0,
      'max_threshold': 10000,
      'filter_by_circularity': True,
      'min_circularity': 0.1,
      'filter_by_convexity': True,
      'min_convexity': 0.2,
      'filter_by_inertia': True,
      'min_inertia_ratio': 0.01
      },
    'dog': {
      'n_features': 0,
      'n_octave_layers': 3,
      'contrast_threshold': 0.04,
      'edge_threshold': 10,
      'sigma': 1.6
      }
    }
