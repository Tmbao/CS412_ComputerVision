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

const int delayTime = 100;
const int defaultSigma = 1;
const int defaultStepSize = 20;
const float defaultAngle = 360 / maxSliderValue;


ImageProviderInterface * imageProvider;

std::map<char, ManipulationInterface *> actions;

int sliderValue;
int savingCounter;


void setUpKeyStrokes(int sigma,
                     int stepSize,
                     float angle) {
  sigma = fmax(sigma, defaultSigma);
  stepSize = fmax(stepSize, defaultStepSize);
  angle = fmax(angle, defaultAngle);
  
  actions.clear();
  actions['g'] = new Convert2GrayOpencv();
  actions['G'] = new Convert2GrayManually();
  actions['c'] = new IterateChannels();
  actions['s'] = new GaussianBlurOpencv(sigma);
  actions['S'] = new GaussianBlurManually(sigma);
  actions['x'] = new ComputeDerivativeWrtX();
  actions['y'] = new ComputeDerivativeWrtY();
  actions['m'] = new ComputeGradientMagnitude();
  actions['p'] = new DrawGradient(stepSize);
  actions['r'] = new RotateImage(angle);
  actions['h'] = new ShowHelp();
}

void setUpKeyStrokes(int sliderValue) {
  setUpKeyStrokes(defaultSigma * sliderValue, defaultStepSize * sliderValue, defaultAngle * sliderValue);
}

void onTrackbarChange(int sliderValue, void * data) {
  setUpKeyStrokes(sliderValue);
}

void setUpDisplayWindow() {
  cv::namedWindow(windowName);
  sliderValue = 1;
  cv::createTrackbar(trackbarName, windowName, &sliderValue, maxSliderValue, onTrackbarChange);
  savingCounter = 0;
}

void run(ImageProviderInterface * imageProvider) {
  std::vector<char> keys;
  while (true) {
    cv::Mat frame = imageProvider->getNextFrame();
    setUpKeyStrokes(sliderValue);
    
    for (int key : keys) {
      actions[key]->perform(frame);
    }
    
    imshow(windowName, frame);
    
    int key = cv::waitKey(delayTime);
    switch (key) {
      case 'i': // Reload
        keys.clear();
        break;
      case 'w': // Write
        cv::imwrite(defaultPrefix + std::to_string(++savingCounter), frame);
        break;
      case 27: // ESC key
        return;
      default:
        if (actions.count(key)) {
          keys.clear(); // Comment out this line to sequencially manipulation functions
          keys.push_back(key);
        }
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
