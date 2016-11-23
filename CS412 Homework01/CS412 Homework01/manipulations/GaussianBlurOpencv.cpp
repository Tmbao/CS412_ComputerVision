//
//  GaussianBlurOpencv.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "GaussianBlurOpencv.hpp"
#include "Convert2GrayOpencv.hpp"


GaussianBlurOpencv::GaussianBlurOpencv(int sigma): _sigma(sigma), _kernelSize(sigma * 4 + 1) {}

GaussianBlurOpencv::GaussianBlurOpencv(int kernelSize, int sigma): _kernelSize(kernelSize), _sigma(sigma) {}

void GaussianBlurOpencv::setKernelSize(int kernelSize) {
  _kernelSize = kernelSize;
}

void GaussianBlurOpencv::setSigma(int sigma) {
  _sigma = sigma;
}

void GaussianBlurOpencv::perform(cv::Mat &frame) {
  Convert2GrayOpencv().perform(frame);
  
  cv::Mat blurredFrame;
  cv::GaussianBlur(frame, blurredFrame, cv::Size2d(_kernelSize, _kernelSize), _sigma);
  frame = blurredFrame;
}
