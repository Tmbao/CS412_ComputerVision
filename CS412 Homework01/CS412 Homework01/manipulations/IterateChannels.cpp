//
//  IterateChannels.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "IterateChannels.hpp"

IterateChannels::IterateChannels(): _channelId(0) {}

void IterateChannels::perform(cv::Mat &frame) {  
  if (frame.channels() == 3) {
    cv::Mat channels[3] = {
      cv::Mat(frame.size(), CV_8U, cv::Scalar(0)),
      cv::Mat(frame.size(), CV_8U, cv::Scalar(0)),
      cv::Mat(frame.size(), CV_8U, cv::Scalar(0))};

    cv::Mat frameChannels[3];
    cv::split(frame, frameChannels);
    frame = frameChannels[(_channelId + 2) % 3];
    _channelId = (_channelId + 1) % 3;
  }
}
