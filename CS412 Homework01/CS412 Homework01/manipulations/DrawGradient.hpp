//
//  DrawGradient.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef DrawGradient_hpp
#define DrawGradient_hpp

#include "ManipulationInterface.hpp"


class DrawGradient : public ManipulationInterface {
private:
  int _stepSize;
public:
  DrawGradient(int stepSize);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* DrawGradient_hpp */
