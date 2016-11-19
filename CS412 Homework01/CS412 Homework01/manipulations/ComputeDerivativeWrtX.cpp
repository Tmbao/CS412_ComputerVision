//
//  ComputeDerivativeWrtX.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ComputeDerivativeWrtX.hpp"


ComputeDerivativeWrtX::ComputeDerivativeWrtX() {
  _kernel = cv::Mat(cv::Size(3, 3), CV_32F);
  _kernel.at<float>(0, 0) = _kernel.at<float>(1, 0) = _kernel.at<float>(2, 0) = -1.0;
  _kernel.at<float>(0, 2) = _kernel.at<float>(1, 2) = _kernel.at<float>(2, 2) = 1.0;
}

void ComputeDerivativeWrtX::perform(cv::Mat &frame) {
  if (frame.channels() == 1) {
    cv::Mat gradX(frame.size(), CV_8U);
    cv::filter2D(frame, gradX, -1, _kernel);
    frame = gradX;
  }
}
