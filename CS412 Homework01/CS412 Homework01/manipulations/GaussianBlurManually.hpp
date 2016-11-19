//
//  GaussianBlurManually.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/11/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef GaussianBlurManually_hpp
#define GaussianBlurManually_hpp

#include "ManipulationInterface.hpp"

class GaussianBlurManually : public ManipulationInterface {
private:
  int _kernelSize;
  int _sigma;
  cv::Mat _kernel;
  
  void resetKernel();
  
public:
  GaussianBlurManually(int sigma);
  GaussianBlurManually(int kernelSize, int sigma);
  
  void setKernelSize(int kernelSize);
  void setSigma(int sigma);
  
  virtual void perform(cv::Mat &frame);
};

#endif /* GaussianBlurManually_hpp */
