//
//  CameraImageProvider.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "CameraImageProvider.hpp"

CameraImageProvider::CameraImageProvider() {
  if (!_capture.open(0)) {
    // Throw an error
  }
}

CameraImageProvider::CameraImageProvider(int cameraId) {
  if (!_capture.open(cameraId)) {
    // Throw an error
  }
}

cv::Mat CameraImageProvider::getNextFrame() {
  cv::Mat nextFrame;
  _capture >> nextFrame;
  return nextFrame;
}
