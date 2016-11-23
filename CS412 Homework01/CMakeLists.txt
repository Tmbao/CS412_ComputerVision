cmake_minimum_required(VERSION 3.6)
project(CS412_Homework01)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    "CS412 Homework01/image_provider/CameraImageProvider.cpp"
    "CS412 Homework01/image_provider/CameraImageProvider.hpp"
    "CS412 Homework01/image_provider/ImageProviderInterface.hpp"
    "CS412 Homework01/image_provider/StaticImageProvider.cpp"
    "CS412 Homework01/image_provider/StaticImageProvider.hpp"
    "CS412 Homework01/manipulations/ComputeDerivativeWrtX.cpp"
    "CS412 Homework01/manipulations/ComputeDerivativeWrtX.hpp"
    "CS412 Homework01/manipulations/ComputeDerivativeWrtY.cpp"
    "CS412 Homework01/manipulations/ComputeDerivativeWrtY.hpp"
    "CS412 Homework01/manipulations/ComputeGradientMagnitude.cpp"
    "CS412 Homework01/manipulations/ComputeGradientMagnitude.hpp"
    "CS412 Homework01/manipulations/Convert2GrayManually.cpp"
    "CS412 Homework01/manipulations/Convert2GrayManually.hpp"
    "CS412 Homework01/manipulations/Convert2GrayOpencv.cpp"
    "CS412 Homework01/manipulations/Convert2GrayOpencv.hpp"
    "CS412 Homework01/manipulations/DrawGradient.cpp"
    "CS412 Homework01/manipulations/DrawGradient.hpp"
    "CS412 Homework01/manipulations/GaussianBlurManually.cpp"
    "CS412 Homework01/manipulations/GaussianBlurManually.hpp"
    "CS412 Homework01/manipulations/GaussianBlurOpencv.cpp"
    "CS412 Homework01/manipulations/GaussianBlurOpencv.hpp"
    "CS412 Homework01/manipulations/IterateChannels.cpp"
    "CS412 Homework01/manipulations/IterateChannels.hpp"
    "CS412 Homework01/manipulations/ManipulationInterface.hpp"
    "CS412 Homework01/manipulations/RotateImage.cpp"
    "CS412 Homework01/manipulations/RotateImage.hpp"
    "CS412 Homework01/manipulations/ShowHelp.cpp"
    "CS412 Homework01/manipulations/ShowHelp.hpp"
    "CS412 Homework01/main.cpp")

add_executable(CS412_Homework01 ${SOURCE_FILES})

target_link_libraries(CS412_Homework01 ${OpenCV_LIBS})