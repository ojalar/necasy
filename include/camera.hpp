#pragma once
#include <string>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <ctime>
/**
    * \brief Class for a network camera.
    *
    * This class implements the functionalities of a network camera added to the system.
    *
    * \param camera_stream The address of a camera stream
    */

class Camera {
public:
    Camera(std::string name, std::string stream, unsigned int id);
    /**
        * Capture a frame from the camera.
        */ 
    void Capture();
    /**
        * Record the current frame.
        */ 
    void Record();
private:
    /**
        * Name of the camera.
        */ 
    std::string name_;
    /**
        * The stream address of the camera.
        */ 
    std::string stream_;
    /**
        * ID of the camera.
        */ 
    unsigned int id_;
    /**
        * Latest frame.
        */ 
    cv::Mat frame_;
    /**
        * Timestamp of the latest frame.
        */ 
    std::time_t frame_time_;
    /**
        * OpenCV capture stream for extracting frames from the camera.
        */ 
    cv::VideoCapture cap_;
};
