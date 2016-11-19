//
//  ComputeDerivativeWrtX.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ComputeDerivativeWrtX_hpp
#define ComputeDerivativeWrtX_hpp

#include "ManipulationInterface.hpp"

class ComputeDerivativeWrtX : public ManipulationInterface {
private:
  cv::Mat _kernel;
public:
  ComputeDerivativeWrtX();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* ComputeDerivativeWrtX_hpp */
