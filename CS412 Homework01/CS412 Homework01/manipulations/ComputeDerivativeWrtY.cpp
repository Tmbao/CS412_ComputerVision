//
//  ComputeDerivativeWrtY.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ComputeDerivativeWrtY.hpp"
#include "Convert2GrayOpencv.hpp"


ComputeDerivativeWrtY::ComputeDerivativeWrtY() {
  _kernel = cv::Mat(cv::Size(3, 3), CV_32F, cv::Scalar(0));
  _kernel.at<float>(0, 0) = _kernel.at<float>(0, 2) = -1;
  _kernel.at<float>(0, 1) = -2;
  _kernel.at<float>(2, 0) = _kernel.at<float>(2, 2) = 1;
  _kernel.at<float>(2, 1) = 2;
}

cv::Mat ComputeDerivativeWrtY::getKernel() {
  return _kernel;
}

void ComputeDerivativeWrtY::perform(cv::Mat &frame) {
  Convert2GrayOpencv().perform(frame);
  cv::Mat gradY;
  cv::filter2D(frame, gradY, CV_32F, _kernel);
  double minVal, maxVal;
  cv::minMaxLoc(gradY, &minVal, &maxVal);
  gradY.convertTo(frame, CV_8U, 255 / (maxVal - minVal), -255 * minVal / (maxVal - minVal));
}
