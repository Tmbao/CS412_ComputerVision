//
//  StaticImageProvider.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "StaticImageProvider.hpp"

StaticImageProvider::StaticImageProvider(std::string fileName) {
  _resource = cv::imread(fileName);
}

cv::Mat StaticImageProvider::getNextFrame() {
  return _resource.clone();
}
