//
//  ComputeDerivativeWrtY.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ComputeDerivativeWrtY_hpp
#define ComputeDerivativeWrtY_hpp

#include "ManipulationInterface.hpp"

class ComputeDerivativeWrtY : public ManipulationInterface {
private:
  cv::Mat _kernel;
public:
  ComputeDerivativeWrtY();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* ComputeDerivativeWrtY_hpp */
