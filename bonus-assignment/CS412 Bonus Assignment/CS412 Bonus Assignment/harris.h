//
//  harris.h
//  CS412 Bonus Assignment
//
//  Created by Bao Truong on 1/4/17.
//  Copyright © 2017 Bao Truong. All rights reserved.
//

#ifndef harris_h
#define harris_h

#include <opencv2/opencv.hpp>

#include <vector>

using namespace cv;
using namespace std;

vector<KeyPoint> harrisCorner(Mat img,
                              int apertureSize = 3,
                              float alpha = 0.04,
                              float quality = 0.01) {

  // Compute gradient w.r.t x and y
  Mat gradX, gradY;
  Sobel(img, gradX, CV_32F, 1, 0);
  Sobel(img, gradY, CV_32F, 0, 1);
  
  Mat gradX2, gradY2, gradXY;
  multiply(gradX, gradX, gradX2);
  multiply(gradY, gradY, gradY2);
  multiply(gradX2, gradY2, gradXY);
  
  Mat blurGradX2, blurGradY2, blurGradXY;
  GaussianBlur(gradX2, blurGradX2, Size(apertureSize, apertureSize), apertureSize / 6.0);
  GaussianBlur(gradY2, blurGradY2, Size(apertureSize, apertureSize), apertureSize / 6.0);
  GaussianBlur(gradXY, blurGradXY, Size(apertureSize, apertureSize), apertureSize / 6.0);
  
  // Compute determinants and traces
  Mat determinants, traces, temp;
  multiply(blurGradX2, blurGradY2, temp);
  subtract(temp, blurGradXY, determinants);
  add(blurGradX2, blurGradY2, temp);
  multiply(temp, temp, traces);
  
  // Compute harris respones
  Mat responses;
  addWeighted(determinants, 1, traces, -alpha, 0, responses);
  
  // Detect corner based on response values
  float maxResponse = -1e9;
  for (int i = 0; i < img.rows; ++i) {
    for (int j = 0; j < img.cols; ++j) {
      maxResponse = max(maxResponse, responses.at<float>(i, j));
    }
  }
  
  vector<KeyPoint> corners;
  for (int i = 0; i < responses.rows; ++i) {
    for (int j = 0; j < responses.cols; ++j) {
      if (responses.at<float>(i, j) >= maxResponse * quality) {
        corners.push_back(KeyPoint(j, i, 1));
      }
    }
  }
  return corners;
}

#endif /* harris_h */
