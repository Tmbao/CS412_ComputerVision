//
//  ComputeDerivativeWrtX.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ComputeDerivativeWrtX.hpp"
#include "Convert2GrayOpencv.hpp"


ComputeDerivativeWrtX::ComputeDerivativeWrtX() {
  _kernel = cv::Mat(cv::Size(3, 3), CV_32F, cv::Scalar(0));
  _kernel.at<float>(0, 0) = _kernel.at<float>(2, 0) = -1;
  _kernel.at<float>(1, 0) = -2;
  _kernel.at<float>(0, 2) = _kernel.at<float>(2, 2) = 1.0;
  _kernel.at<float>(1, 2) = 2;
}

cv::Mat ComputeDerivativeWrtX::getKernel() {
  return _kernel;
}

void ComputeDerivativeWrtX::perform(cv::Mat &frame) {
  Convert2GrayOpencv().perform(frame);
  
  cv::Mat gradX(frame.size(), CV_8U);
  cv::filter2D(frame, gradX, CV_32F, _kernel);
  double minVal, maxVal;
  cv::minMaxLoc(gradX, &minVal, &maxVal);
  gradX.convertTo(frame, CV_8U, 255 / (maxVal - minVal), -255 * minVal / (maxVal - minVal));
}
