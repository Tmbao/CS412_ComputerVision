//
//  IterateChannels.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef IterateChannels_hpp
#define IterateChannels_hpp

#include "ManipulationInterface.hpp"


class IterateChannels : public ManipulationInterface {
private:
  int _channelId;
public:
  IterateChannels();
  
  virtual void perform(cv::Mat &frame);
};

#endif /* IterateChannels_hpp */
