//
//  ComputeGradientMagnitude.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ComputeGradientMagnitude.hpp"
#include "ComputeDerivativeWrtX.hpp"
#include "ComputeDerivativeWrtY.hpp"


ComputeGradientMagnitude::ComputeGradientMagnitude() {}

void ComputeGradientMagnitude::perform(cv::Mat &frame) {
  cv::Mat gradX = frame.clone();
  ComputeDerivativeWrtX().perform(gradX);
  cv::Mat gradY = frame.clone();
  ComputeDerivativeWrtY().perform(gradY);
  
  cv::Mat grad(frame.size(), CV_8U);
  for (int i = 0; i < frame.rows; ++i) {
    for (int j = 0; j < frame.cols; ++j) {
      grad.at<unsigned char>(i, j) = MIN(255,
                                         sqrt(gradX.at<unsigned char>(i, j) * 1.0 * gradX.at<unsigned char>(i, j)
                                              + gradY.at<unsigned char>(i, j) * 1.0 * gradY.at<unsigned char>(i, j)));
    }
  }
  frame = grad;
}
