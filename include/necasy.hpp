#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "camera.hpp"
/**
    * \brief Main class for the system.
    *
    * This class implements the overall functionality of Necasy.
    *
    * \param camera_path The path to the file listing the camera stream addresses
    */

class Necasy {
public:
    Necasy(std::string camera_path = "config/cameras.txt")
    : camera_path_(camera_path) {
        // read camera stream addresses from config file
        std::ifstream camera_file;
        camera_file.open(camera_path_);

        std::string stream_address;
        std::cout << "Reading camera streams: " << camera_path_ << '\n';
        while (getline(camera_file, stream_address)) {
            std::cout << "Read camera stream: " << stream_address << '\n';
            camera_streams_.push_back(stream_address);
        }
        camera_file.close();  
    }
    // copy constructor
    Necasy(const Necasy& ncs){}
    // copy assignment operator
    Necasy& operator=(const Necasy& ncs){}
    // destructor
    ~Necasy() {};

private:
    std::string camera_path_;
    std::vector<std::string> camera_streams_;
};
