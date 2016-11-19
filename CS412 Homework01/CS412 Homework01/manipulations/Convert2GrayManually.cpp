//
//  Convert2GrayManually.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "Convert2GrayManually.hpp"

Convert2GrayManually::Convert2GrayManually() {}

void Convert2GrayManually::perform(cv::Mat &frame) {
  if (frame.channels() > 1) {
    cv::Mat grayFrame(frame.size(), CV_8UC1);
    for (int i = 0; i < frame.rows; ++i) {
      for (int j = 0; j < frame.cols; ++j) {
        cv::Vec3b color = frame.at<cv::Vec3b>(i, j);
        grayFrame.at<unsigned char>(i, j) =  0.114 * color[0] + 0.587 * color[1] + 0.299 * color[2];
      }
    }
    frame = grayFrame;
  }
}
