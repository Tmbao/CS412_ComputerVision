//
//  RotateImage.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef RotateImage_hpp
#define RotateImage_hpp

#include "ManipulationInterface.hpp"


class RotateImage : public ManipulationInterface {
private:
  double _angle;
public:
  RotateImage(double angle);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* RotateImage_hpp */
