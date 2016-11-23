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


DrawGradient::DrawGradient(int stepSize): _stepSize(stepSize) {}

void DrawGradient::perform(cv::Mat &frame) {
  if (frame.channels() == 1) {
    cv::Mat gradX = frame.clone();
    cv::filter2D(frame, gradX, CV_16S, ComputeDerivativeWrtX().getKernel());
    cv::Mat gradY = frame.clone();
    cv::filter2D(frame, gradY, CV_16S, ComputeDerivativeWrtY().getKernel());
    
    for (int i = _stepSize; i < frame.rows; i += _stepSize) {
      for (int j = _stepSize; j < frame.cols; j += _stepSize) {
        if (gradX.at<short>(i, j) == 0 && gradY.at<short>(i, j) == 0) {
          continue;
        }
        
        int magnitude = sqrt(gradX.at<short>(i, j) * 1.0 * gradX.at<short>(i, j)
                              + gradY.at<short>(i, j) * 1.0 * gradY.at<short>(i, j));
        float angle = atan2(gradY.at<short>(i, j), gradX.at<short>(i, j));
        
        cv::Point start(j, i);
        cv::Point end(j + _stepSize * sin(angle), i - magnitude * cos(angle));
        cv::arrowedLine(frame, start, end, cv::Scalar(255));
      }
    }
  }
  
}
