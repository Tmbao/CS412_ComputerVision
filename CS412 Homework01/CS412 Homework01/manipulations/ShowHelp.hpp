//
//  ShowHelp.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ShowHelp_hpp
#define ShowHelp_hpp

#include "ManipulationInterface.hpp"


class ShowHelp : public ManipulationInterface {
public:
  ShowHelp();
  virtual void perform(cv::Mat &frame);
};

#endif /* ShowHelp_hpp */
