//
//  ImageProviderInterface.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ImageProviderInterface_h
#define ImageProviderInterface_h

#include <opencv2/opencv.hpp>

class ImageProviderInterface {
public:
  virtual cv::Mat getNextFrame() = 0;
};

#endif /* ImageProviderInterface_h */
