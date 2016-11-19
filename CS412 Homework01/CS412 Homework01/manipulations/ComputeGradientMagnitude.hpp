//
//  ComputeGradientMagnitude.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ComputeGradientMagnitude_hpp
#define ComputeGradientMagnitude_hpp

#include "ManipulationInterface.hpp"


class ComputeGradientMagnitude : public ManipulationInterface {
public:
  ComputeGradientMagnitude();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* ComputeGradientMagnitude_hpp */
