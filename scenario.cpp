#include "scenario.h"
#include "vehicle.h"
#include "mainwindow.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>



Scenario::Scenario(std::string pathVleft, std::string pathVright){ // Constructor
    Scenario::path1 = pathVleft;
    Scenario::path2 = pathVright;
    Scenario::id = "43";
}

void Scenario::playVideoLeft(){
    cv::VideoCapture cap1(Scenario::path1); // VideoLeft
    cv::Mat frame1;

    while (true) {
        cap1.read(frame1);
        cv::resize(frame1, frame1, cv::Size(), 0.25, 0.25);
        cv::imshow("Video Left", frame1);
        cv::waitKey(70);
    }
}

void Scenario::playVideoRight(){ // VideoRight
    cv::VideoCapture cap2(Scenario::path2);
    cv::Mat frame2;

    while (true) {
        cap2.read(frame2);
        cv::resize(frame2, frame2, cv::Size(), 0.25, 0.25);
        cv::imshow("Video Right", frame2);
        cv::waitKey(70);
    }
}

void Scenario::playTwoVideos(){
    cv::VideoCapture cap1(Scenario::path1); // VideoLeft
    cv::VideoCapture cap2(Scenario::path2); // VideoRight

    cv::Mat frame1;
    cv::Mat frame2;

    while (true) {
        cap1.read(frame1);
        cv::resize(frame1, frame1, cv::Size(), 0.25, 0.25);
        cv::imshow("Video Left", frame1);

        cap2.read(frame2);
        cv::resize(frame2, frame2, cv::Size(), 0.25, 0.25);
        cv::imshow("Video Right", frame2);

        cv::waitKey(40);
    }


}

void Scenario::openExcelFile(){
    std::string filename = "scenario" + Scenario::id + ".xlsx";
    std::string path = "C:/Users/hp/OneDrive/Bureau/Scenario43"+filename;
    Scenario::ExcelFile.open(path);
}



