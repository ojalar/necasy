#include "necasy.hpp"

Necasy::Necasy(std::string camera_path)
: camera_path_(camera_path) {
    // read camera stream addresses from config file
    std::cout << "Reading camera streams: " << camera_path_ << '\n';
    std::ifstream camera_file;
    camera_file.open(camera_path_);
    // check if file was succesfully opened 
    if (!camera_file) {
        std::cerr << "Could not read camera stream file\n";
    }
    // read each stream address row by row
    std::string stream_address;
    unsigned int id = 0;
    while (getline(camera_file, stream_address)) {
        std::cout << "Read camera stream: " << stream_address << '\n';
        cameras_.push_back(std::make_shared<Camera>(stream_address, id));
        id++;
    }
    camera_file.close();  
}

void Necasy::Update() {
    // capture frames from each camera
    this->Capture();
    // process the latest frames
    this->Process();
}

void Necasy::Capture() {
    // parallel loop through cameras, acquire new frame from each
    #pragma omp parallel for
    for (std::size_t i = 0; i < cameras_.size(); i++) {
        cameras_[i]->Capture();
    }    
}
