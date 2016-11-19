//
//  Convert2GrayOpencv.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "Convert2GrayOpencv.hpp"

Convert2GrayOpencv::Convert2GrayOpencv() {}

void Convert2GrayOpencv::perform(cv::Mat &frame) {
  if (frame.channels() > 1) {
    cv::Mat newFrame;
    cv::cvtColor(frame, newFrame, cv::COLOR_BGR2GRAY);
    frame = newFrame;
  }
}
