#include "necasy.hpp"

Necasy::Necasy(std::string camera_path)
: camera_path_(camera_path) {
    // read camera info from config file
    std::cout << "Reading camera streams: " << camera_path_ << '\n';
    rapidcsv::Document camera_file(camera_path_);
    std::vector<std::string> names = camera_file.GetColumn<std::string>("Name");
    std::vector<std::string> addresses = camera_file.GetColumn<std::string>("Address");
    std::string camera_name;
    std::string stream_address;

    for(unsigned int i = 0; i < names.size(); i++) {
        // read the comma separated camera info
        camera_name = names[i];
        stream_address = addresses[i];
        std::cout << "Read camera with name: " << camera_name << " and stream: " << stream_address << '\n';
        cameras_.push_back(std::make_shared<Camera>(camera_name, stream_address, i));
    }
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
