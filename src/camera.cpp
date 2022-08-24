#include "camera.hpp"

Camera::Camera(std::string stream, unsigned int id)
: stream_(stream), id_(id) {
    // open camera stream
    cap_.open(stream_, cv::CAP_ANY);
    if (!cap_.isOpened()) {
        std::cout << "ID " << id_ << " Failed to open camera stream: " << stream_ << '\n';
    }
} 

void Camera::Capture() {
    cap_.read(frame_);
}
