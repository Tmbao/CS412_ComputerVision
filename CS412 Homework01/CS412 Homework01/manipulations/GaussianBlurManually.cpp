//
//  GaussianBlurManually.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "GaussianBlurManually.hpp"
#include "Convert2GrayManually.hpp"

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
  if (frame.channels() == 1) {
    cv::Mat newFrame = frame.clone();
    int padding = _kernelSize / 2;
    for (int i = padding; i + padding < frame.rows; ++i) {
      for (int j = padding; j + padding < frame.cols; ++j) {
        double color = 0;
        for (int x = i - padding; x <= i + padding; ++x) {
          for (int y = j - padding; y <= j + padding; ++y) {
            color += frame.at<unsigned char>(x, y) * _kernel.at<double>(x - (i - padding)) * _kernel.at<double>(y - (j - padding));
          }
        }
        newFrame.at<unsigned char>(i, j) = MIN((int) color, 255);
      }
    }
    frame = newFrame.clone();
  }
}

