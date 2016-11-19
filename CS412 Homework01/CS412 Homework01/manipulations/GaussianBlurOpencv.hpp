//
//  GaussianBlurOpencv.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef GaussianBlurOpencv_hpp
#define GaussianBlurOpencv_hpp

#include "ManipulationInterface.hpp"


class GaussianBlurOpencv : public ManipulationInterface {
private:
  int _kernelSize;
  int _sigma;
public:
  GaussianBlurOpencv(int sigma);
  GaussianBlurOpencv(int kernelSize, int sigma);
  
  void setKernelSize(int kernelSize);
  void setSigma(int sigma);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* GaussianBlurOpencv_hpp */
