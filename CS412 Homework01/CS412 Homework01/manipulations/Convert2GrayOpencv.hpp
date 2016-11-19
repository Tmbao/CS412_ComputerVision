//
//  Convert2GrayOpencv.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef Convert2GrayOpencv_hpp
#define Convert2GrayOpencv_hpp

#include "ManipulationInterface.hpp"


class Convert2GrayOpencv : public ManipulationInterface {
public:
  Convert2GrayOpencv();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* Convert2GrayOpencv_hpp */
