//
//  main.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/10/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include <map>

#include "image_provider/ImageProviderInterface.hpp"
#include "image_provider/StaticImageProvider.hpp"
#include "image_provider/CameraImageProvider.hpp"

#include "manipulations/ManipulationInterface.hpp"
#include "manipulations/ResetChanges.hpp"
#include "manipulations/SaveImage.hpp"
#include "manipulations/Convert2GrayOpencv.hpp"
#include "manipulations/Convert2GrayManually.hpp"
#include "manipulations/GaussianBlurOpencv.hpp"
#include "manipulations/GaussianBlurManually.hpp"
#include "manipulations/IterateChannels.hpp"
#include "manipulations/ComputeDerivativeWrtX.hpp"
#include "manipulations/ComputeDerivativeWrtY.hpp"
#include "manipulations/ComputeGradientMagnitude.hpp"
#include "manipulations/DrawGradient.hpp"
#include "manipulations/RotateImage.hpp"
#include "manipulations/ShowHelp.hpp"

const std::string windowName = "Cs412 Assignment 1";
const std::string defaultPrefix = "out";
const std::string trackbarName = "Intensitive";
const int maxSliderValue = 100;

const int delayTime = 10;
const int defaultSigma = 1;
const int defaultStepSize = 5;
const float defaultAngle = 360 / maxSliderValue;


ImageProviderInterface * imageProvider;
cv::Mat currentFrame;

std::map<char, ManipulationInterface *> actions;

int sliderValue;


void setUpKeyStrokes(cv::Mat originalImage,
                     std::string prefix=defaultPrefix,
                     int sigma=defaultSigma,
                     int stepSize=defaultStepSize,
                     float angle=defaultAngle) {
  actions.clear();
  
  actions['i'] = new ResetChanges(originalImage);
  actions['w'] = new SaveImage(prefix);
  actions['g'] = new Convert2GrayOpencv();
  actions['G'] = new Convert2GrayManually();
  actions['c'] = new IterateChannels();
  actions['s'] = new GaussianBlurOpencv(sigma);
  actions['S'] = new GaussianBlurManually(sigma);
  actions['x'] = new ComputeDerivativeWrtX();
  actions['y'] = new ComputeDerivativeWrtY();
  actions['m'] = new ComputeGradientMagnitude();
  actions['d'] = new DrawGradient(stepSize);
  actions['r'] = new RotateImage(angle);
  actions['h'] = new ShowHelp();
}

void setUpKeyStrokes(cv::Mat originalImage,
                     int sliderValue) {
  setUpKeyStrokes(originalImage, defaultPrefix, defaultSigma * sliderValue, defaultStepSize * sliderValue, defaultAngle * sliderValue);
}

void onTrackbarChange(int sliderValue, void * data) {
  setUpKeyStrokes(currentFrame, sliderValue);
}

void setUpDisplayWindow() {
  cv::namedWindow(windowName);
  sliderValue = 1;
  cv::createTrackbar(trackbarName, windowName, &sliderValue, maxSliderValue, onTrackbarChange);
}

void edit(cv::Mat frame) {
  currentFrame = frame;
  setUpKeyStrokes(currentFrame, sliderValue);
  
  while (true) {
    imshow(windowName, frame);
    
    int key = cv::waitKey(delayTime);
    if (key == 27) { // ESC key
      return;
    } else if (actions.count(key) > 0) {
      actions[key]->perform(frame);
    }
  }
}

void run(ImageProviderInterface * imageProvider) {
  while (true) {
    cv::Mat frame = imageProvider->getNextFrame();
    imshow(windowName, frame);
    
    int key = cv::waitKey(delayTime);
    switch (key) {
      case 10: // Enter key
      case 13: // Return key
        
        edit(frame);
        break;
      case 27: // ESC key
        return;
    }
  }
}


int main(int argc, char ** argv) {
  // Config parameters
  if (argc == 1) {
    imageProvider = new CameraImageProvider();
  } else {
    imageProvider = new StaticImageProvider(argv[1]);
  }
  
  setUpDisplayWindow();
  run(imageProvider);
  
  return 0;
}
