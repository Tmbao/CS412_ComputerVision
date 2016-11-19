//
//  SaveImage.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef SaveImage_hpp
#define SaveImage_hpp

#include <string>

#include "ManipulationInterface.hpp"

class SaveImage : public ManipulationInterface {
private:
  int _id;
  std::string _prefix;

public:
  SaveImage(std::string prefix);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* SaveImage_hpp */
