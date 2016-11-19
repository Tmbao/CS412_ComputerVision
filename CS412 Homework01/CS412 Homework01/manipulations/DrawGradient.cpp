//
//  DrawGradient.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "DrawGradient.hpp"
#include "ComputeDerivativeWrtX.hpp"
#include "ComputeDerivativeWrtY.hpp"

#include <iostream>


DrawGradient::DrawGradient(int stepSize): _stepSize(stepSize) {}

void DrawGradient::perform(cv::Mat &frame) {
  cv::Mat gradX = frame.clone();
  ComputeDerivativeWrtX().perform(gradX);
  cv::Mat gradY = frame.clone();
  ComputeDerivativeWrtY().perform(gradY);
  
  for (int i = _stepSize; i < frame.rows; i += _stepSize) {
    for (int j = _stepSize; j < frame.cols; j += _stepSize) {
      if (gradX.at<unsigned char>(i, j) == 0 && gradY.at<unsigned char>(i, j) == 0) {
        continue;
      }
      unsigned int magnitude = sqrt(gradX.at<unsigned char>(i, j) * 1.0 * gradX.at<unsigned char>(i, j)
                                    + gradY.at<unsigned char>(i, j) * 1.0 * gradY.at<unsigned char>(i, j));
      float angle = atan2(gradY.at<unsigned char>(i, j), gradX.at<unsigned char>(i, j));
      
      printf("%d %d %d\n", i, j, magnitude);
      
      cv::Point start(j, i);
      cv::Point end(j + magnitude * sin(angle), i - magnitude * cos(angle));
      cv::arrowedLine(frame, start, end, cv::Scalar(255));
    }
  }
}
