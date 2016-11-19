//
//  Convert2GrayManually.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef Convert2GrayManually_hpp
#define Convert2GrayManually_hpp

#include "ManipulationInterface.hpp"


class Convert2GrayManually : public ManipulationInterface {
public:
  Convert2GrayManually();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* Convert2GrayManually_hpp */
