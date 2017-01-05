//
//  main.cpp
//  CS412 Bonus Assignment
//
//  Created by Bao Truong on 1/4/17.
//  Copyright © 2017 Bao Truong. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace cv;

#include "harris.h"
#include "earthmover.h"
#include "canny.h"


int main(int argc, const char * argv[]) {
  
  if (argc == 1) {
    // Show help
    return 0;
  }
  
  // Apply harris' algorithm to detect corners
  if (strcmp(argv[1], "edge") == 0) {
    // Input matrix
    Mat inputMat = imread(argv[2]), greyMat, cornerMat;
    cvtColor(inputMat, greyMat, COLOR_BGR2GRAY);
    
    // Detect edges
    auto edges = cannyEdge(greyMat);
    
    // Visualize edges
    imshow("Edges", edges);
    waitKey(0);
  } else if (strcmp(argv[1], "corner") == 0) {
    // Input matrix
    Mat inputMat = imread(argv[2]), greyMat, cornerMat;
    cvtColor(inputMat, greyMat, COLOR_BGR2GRAY);
    
    // Detect corners
    auto corners = harrisCorner(greyMat);
    
    // Visualize corners
    drawKeypoints(inputMat, corners, cornerMat);
    imshow("Image and Corners", cornerMat);
    waitKey(0);
  } else if (strcmp(argv[1], "similarity") == 0) {
    Collection P = readCollection(argv[2]);
    Collection Q = readCollection(argv[3]);
    
    // Print out distance
    printf("%f\n", earthMoversDistance(P, Q));
  }
  
  return 0;
}
