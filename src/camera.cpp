#include "camera.hpp"

Camera::Camera(std::string name, std::string stream, unsigned int id)
: name_(name), stream_(stream), id_(id) {
    // open camera stream
    cap_.open(stream_, cv::CAP_ANY);
    if (!cap_.isOpened()) {
        std::cerr << "ID " << id_ << " Failed to open camera stream: " << stream_ << '\n';
    }
} 

void Camera::Capture() {
    cap_.read(frame_);
    if (frame_.empty()) {
        std::cerr << "ID " << id_ << " Failed to read frame from stream: " << stream_ << '\n'; 
    }
    frame_time_ = std::time(nullptr);
    this->Record();
}

void Camera::Record() {
    std::stringstream filename;
    filename << "recordings/1/" << frame_time_ << ".png";
    cv::imwrite(filename.str(), frame_);
}
