#include "camera.hpp"

Camera::Camera(std::string name, std::string stream, unsigned int id)
: name_(name), stream_(stream), id_(id) {
    // open camera stream
    cap_.open(stream_, cv::CAP_ANY);
    if (!cap_.isOpened()) {
        std::cerr << "ID " << id_ << " Failed to open camera stream: " << stream_ << '\n';
    }
    // create directory for storing recorded frames
    std::stringstream directory_ss;
    directory_ss << "recordings/" << name_;
    directory_name_ = directory_ss.str();
} 

void Camera::Capture() {
    // read a frame from the camera stream
    cap_.read(frame_);
    if (frame_.empty()) {
        std::cerr << "ID " << id_ << " Failed to read frame from stream: " << stream_ << '\n'; 
    }
    // capture the timestamp
    frame_time_ = std::time(nullptr);
    this->Record();
}

void Camera::Record() {
    std::stringstream filename;
    filename << "recordings/1/" << frame_time_ << ".png";
    cv::imwrite(filename.str(), frame_);
}
