//
//  canny.h
//  CS412 Bonus Assignment
//
//  Created by Bao Truong on 1/5/17.
//  Copyright © 2017 Bao Truong. All rights reserved.
//

#ifndef canny_h
#define canny_h

#include <opencv2/opencv.hpp>

using namespace cv;

#define sqr(x) (x) * (x)
#define ANGLE_EPS 1e-4

int _di[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int _dj[] = {-1, -1, -1, 0, 0, 1, 1, 1};


void connectEdge(int i, int j, Mat &edge) {
  edge.at<uchar>(i, j) = 255;
  for (int k = 0; k < 8; ++k) {
    int ii = i + _di[k];
    int jj = j + _dj[k];
    if (ii < 0 || jj < 0 || ii >= edge.rows || jj >= edge.cols) {
      continue;
    }
    if (edge.at<uchar>(ii, jj) == 127) {
      connectEdge(ii, jj, edge);
    }
  }
}


Mat cannyEdge(Mat img, double minVal = 100, double maxVal = 200, int apertureSize = 5) {
  // Reduce noise
  Mat blurImg;
  GaussianBlur(img, blurImg, Size(apertureSize, apertureSize), apertureSize / 6.0);
  
  // Compute gradient w.r.t x and y
  Mat gradX, gradY;
  Sobel(img, gradX, CV_32F, 1, 0);
  Sobel(img, gradY, CV_32F, 0, 1);
  
  // Compute gradient intensitive and angle
  Mat edgeGrads(blurImg.size(), CV_32F), angles(blurImg.size(), CV_32F);
  for (int i = 0; i < blurImg.rows; ++i) {
    for (int j = 0; j < blurImg.cols; ++j) {
      edgeGrads.at<float>(i, j) = sqrt(sqr(gradX.at<float>(i, j)) + sqr(gradY.at<float>(i, j)));
      angles.at<float>(i, j) = atan2(gradY.at<float>(i, j), gradX.at<float>(i, j));
    }
  }
  
  // Carry out non-maximum suppression
  Mat edgeResponse(blurImg.size(), CV_32F);
  for (int i = 1; i + 1 < blurImg.rows; ++i) {
    for (int j = 1; j + 1 < blurImg.cols; ++j) {
      bool isMaximal = true;
      for (int k = 0; k < 8; ++k) {
        int ii = i + _di[k];
        int jj = j + _dj[k];
        if (remainder(angles.at<float>(i, j) - angles.at<float>(ii, jj), M_PI) < ANGLE_EPS &&
            edgeGrads.at<float>(i, j) < edgeGrads.at<float>(ii, jj)) {
          isMaximal = false;
          break;
        }
      }
      
      if (isMaximal) {
        edgeResponse.at<float>(i, j) = edgeGrads.at<float>(i, j);
      }
    }
  }
  
  // Carry out hysteresis thresholding
  Mat ret(blurImg.size(), CV_8U);
  for (int i = 0; i < ret.rows; ++i) {
    for (int j = 0; j < ret.cols; ++j) {
      if (edgeResponse.at<float>(i, j) >= maxVal) {
        ret.at<uchar>(i, j) = 255;
      } else if (edgeResponse.at<float>(i, j) < minVal) {
        ret.at<uchar>(i, j) = 0;
      } else {
        ret.at<uchar>(i, j) = 127;
      }
    }
  }
  for (int i = 0; i < ret.rows; ++i) {
    for (int j = 0; j < ret.cols; ++j) {
      if (ret.at<uchar>(i, j) == 255) {
        connectEdge(i, j, ret);
      }
    }
  }
  for (int i = 0; i < ret.rows; ++i) {
    for (int j = 0; j < ret.cols; ++j) {
      if (ret.at<uchar>(i, j) < 255) {
        ret.at<uchar>(i, j) = 0;
      }
    }
  }
  
  return ret;
}

#endif /* canny_h */
