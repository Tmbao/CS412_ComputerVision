//
//  IterateChannels.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "IterateChannels.hpp"
#include "Convert2GrayOpencv.hpp"

IterateChannels::IterateChannels(): _channelId(0) {}

void IterateChannels::perform(cv::Mat &frame) {
  cv::Mat channels[3] = {
    cv::Mat(frame.size(), CV_8U, cv::Scalar(0)),
    cv::Mat(frame.size(), CV_8U, cv::Scalar(0)),
    cv::Mat(frame.size(), CV_8U, cv::Scalar(0))};
  
  if (frame.channels() == 1) {
    printf("1\n");
    channels[_channelId] = frame;
  } else {
    printf("2\n");
    cv::Mat frameChannels[3];
    cv::split(frame, frameChannels);
    channels[_channelId] = frameChannels[(_channelId + 2) % 3];
  }
  
  cv::Mat newFrame(frame.size(), CV_32FC3);
  cv::merge(channels, 3, newFrame);
  frame = newFrame.clone();
  
  _channelId = (_channelId + 1) % 3;
}
