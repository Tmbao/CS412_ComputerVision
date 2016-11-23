//
//  RotateImage.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "RotateImage.hpp"
#include "Convert2GrayOpencv.hpp"


RotateImage::RotateImage(double angle): _angle(angle) {}

void RotateImage::perform(cv::Mat &frame) {
  Convert2GrayOpencv().perform(frame);
  
  cv::Mat rotatedFrame;
  cv::Mat rotationMat = cv::getRotationMatrix2D(cv::Point(frame.cols / 2, frame.rows / 2), _angle, 1);
  cv::warpAffine(frame, rotatedFrame, rotationMat, frame.size());
  frame = rotatedFrame;
}
