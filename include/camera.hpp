#pragma once
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"

/**
    * \brief Class for a network camera.
    *
    * This class implements the functionalities of a network camera added to the system.
    *
    * \param camera_stream The address of a camera stream
    */

class Camera {
public:
    Camera(std::string stream, unsigned int id);
 
    void Capture();

private:
    std::string stream_;
    unsigned int id_;
    cv::Mat frame_;
    cv::VideoCapture cap_;
};
