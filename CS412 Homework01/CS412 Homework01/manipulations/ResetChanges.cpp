//
//  ResetChanges.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ResetChanges.hpp"

ResetChanges::ResetChanges(cv::Mat originalImage) {
  _originalImage = originalImage.clone();
}

void ResetChanges::perform(cv::Mat &frame) {
  frame = _originalImage.clone();
}
