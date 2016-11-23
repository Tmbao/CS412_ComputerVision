//
//  GaussianBlurManually.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "GaussianBlurManually.hpp"
#include "Convert2GrayOpencv.hpp"

GaussianBlurManually::GaussianBlurManually(int sigma): _sigma(sigma), _kernelSize(sigma * 4 + 1) {
  resetKernel();
}

GaussianBlurManually::GaussianBlurManually(int kernelSize, int sigma): _kernelSize(kernelSize), _sigma(sigma) {
  resetKernel();
}

void GaussianBlurManually::setKernelSize(int kernelSize) {
  _kernelSize = kernelSize;
  resetKernel();
}

void GaussianBlurManually::setSigma(int sigma) {
  _sigma = sigma;
  resetKernel();
}

void GaussianBlurManually::resetKernel() {
  _kernel = cv::getGaussianKernel(_kernelSize, _sigma);
}

void GaussianBlurManually::perform(cv::Mat &frame) {
  Convert2GrayOpencv().perform(frame);

  cv::Mat newFrame;
  cv::filter2D(frame, newFrame, -1, _kernel);
  frame = newFrame;
}

