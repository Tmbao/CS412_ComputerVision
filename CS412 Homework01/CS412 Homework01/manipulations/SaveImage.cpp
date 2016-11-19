//
//  SaveImage.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "SaveImage.hpp"

SaveImage::SaveImage(std::string prefix) {
  _prefix = prefix;
  _id = 0;
}

void SaveImage::perform(cv::Mat &frame) {
  cv::imwrite(_prefix + std::to_string(++_id), frame);
}
