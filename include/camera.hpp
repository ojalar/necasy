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
    Camera(std::string stream)
    : stream_(stream) {}; 
    


private:
    std::string stream_;
};
