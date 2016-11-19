//
//  ShowHelp.cpp
//  CS412 Homework01
//
//  Created by Bao Truong on 11/19/16.
//  Copyright © 2016 Bao Truong. All rights reserved.
//

#include "ShowHelp.hpp"


ShowHelp::ShowHelp() {}

void ShowHelp::perform(cv::Mat &frame) {
  printf("i - reload the original image (i.e. cancel any previous processing).\n"
         "w - save the current (possibly processed) image into the file out.jpg.\n"
         "g - convert the image to grayscale using the openCV conversion function.\n"
         "G - convert the image to grayscale using your implementation of conversion function.\n"
         "c - cycle through the color channels of the image showing a different channel every time the key is pressed.\n"
         "s - convert the image to grayscale and smooth it using the openCV function. Use a trackbar to control the amount of smoothing."
         "S - convert the image to grayscale and smooth it using your function which should perform convolution with a suitable filter. Use a track bar to control the amount of smoothing."
         "x - convert the image to grayscale and perform convolution with an x derivative filter.\n"
         "y - convert the image to grayscale and perform convolution with a y derivative filter.\n"
         "m - show the magnitude of the gradient normalized to the range [0,255].\n"
         "p - convert the image to grayscale and plot the gradient vectors of the image every N pixels and let the plotted gradient vectors have a length of K. Use a track bar to control N. Plot the vectors as short line segments of length K.\n"
         "r - convert the image to grayscale and rotate it using an angle of Q degrees. Use a trackbar to control the rotation angle. The rotation of the image should be performed using an inverse map so there are no holes in it.\n"
         "h - Display a short description of the program, its command line arguments, and the keys it supports.\n");
}
