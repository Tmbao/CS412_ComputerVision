//
//  ResetChanges.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef ResetChanges_hpp
#define ResetChanges_hpp

#include "ManipulationInterface.hpp"

class ResetChanges : public ManipulationInterface {
private:
  cv::Mat _originalImage;

public:
  ResetChanges(cv::Mat originalImage);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* ResetChanges_hpp */
