#include <iostream>
#include "opencv2/opencv.hpp"
#include "camera.hpp"
#include "algorithms.hpp"
#include "necasy.hpp"
#include <memory>
#include <vector>
#include <chrono>
#include <thread>

int main(int argc, char *argv[]) {
    Necasy ncs;
    int counter = 0;
    std::chrono::milliseconds timespan(10000);
    while (counter < 10) {
        ncs.Update();
        std::this_thread::sleep_for(timespan);
        counter++;
    }
}
