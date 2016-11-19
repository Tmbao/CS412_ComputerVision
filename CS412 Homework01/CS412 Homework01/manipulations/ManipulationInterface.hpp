//
//  ManipulationInterface.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ManipulationInterface_h
#define ManipulationInterface_h

#include <opencv2/opencv.hpp>


class ManipulationInterface {
public:
  virtual void perform(cv::Mat &frame) = 0;
};


#endif /* ManipulationInterface_h */
