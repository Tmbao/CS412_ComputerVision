//
//  StaticImageProvider.hpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#ifndef StaticImageProvider_hpp
#define StaticImageProvider_hpp

#include <string>

#include "ImageProviderInterface.hpp"

class StaticImageProvider : public ImageProviderInterface {
private:
  cv::Mat _resource;
public:
  StaticImageProvider(std::string fileName);

  virtual cv::Mat getNextFrame();
};

#endif /* StaticImageProvider_hpp */
