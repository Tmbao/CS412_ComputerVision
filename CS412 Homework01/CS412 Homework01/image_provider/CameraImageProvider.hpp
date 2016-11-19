//
//  CameraImageProvider.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef CameraImageProvider_hpp
#define CameraImageProvider_hpp

#include "ImageProviderInterface.hpp"

class CameraImageProvider : public ImageProviderInterface {
private:
  cv::VideoCapture _capture;

public:
  CameraImageProvider();
  
  CameraImageProvider(int cameraId);
  
  virtual cv::Mat getNextFrame();
};

#endif /* CameraImageProvider_hpp */
