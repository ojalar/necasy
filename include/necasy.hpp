#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "camera.hpp"
#include <utility>
#include <memory>
#include <vector>

/**
    * \brief Main class for the system.
    *
    * Implements the overall functionality of Necasy.
    */

class Necasy {
public:
    /**
        * \brief Constructor for the class.
        *
        * Create a Necasy object based on config file.
        *
        * \param camera_path The path to the file listing the camera stream addresses
        */
    Necasy(std::string camera_path = "config/cameras.txt");
    
    /* 
    // copy constructor
    Necasy(const Necasy& ncs){};
    
    // copy assignment operator
    Necasy& operator=(const Necasy& ncs){
        return *this;
    };
    // destructor
    ~Necasy() {};
    */
    void Update();
    void Capture();
    void Process() {;};

private:
    /**
        * Path to the config file with the cameras.
        */
    std::string camera_path_;
    /**
        * Vector of the Cameras.
        */
    std::vector<std::shared_ptr<Camera>> cameras_;
};
