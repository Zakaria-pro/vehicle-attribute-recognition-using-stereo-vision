#include "scenario.h"
#include "vehicle.h"
#include "mainwindow.h"

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>


using namespace std;
using namespace cv;

Scenario::Scenario(string pathVleft, string pathVright){ // Constructor
    Scenario::path1 = pathVleft;
    Scenario::path2 = pathVright;
    Scenario::id = "43";
}

void Scenario::playVideoLeft(){
    VideoCapture cap1(Scenario::path1); // VideoLeft
    Mat frame1;

    while (true) {
        cap1.read(frame1);
        resize(frame1, frame1, Size(), 0.25, 0.25);
        imshow("Video Left", frame1);
        waitKey(70);
    }
}

void Scenario::playVideoRight(){ // VideoRight
    VideoCapture cap2(Scenario::path2);
    Mat frame2;

    while (true) {
        cap2.read(frame2);
        resize(frame2, frame2, Size(), 0.25, 0.25);
        imshow("Video Right", frame2);
        waitKey(70);
    }
}

void Scenario::playTwoVideos(){
    VideoCapture cap1(Scenario::path1); // VideoLeft
    VideoCapture cap2(Scenario::path2); // VideoRight

    Mat frame1;
    Mat frame2;

    while (true) {
        cap1.read(frame1);
        resize(frame1, frame1, Size(), 0.25, 0.25);
        imshow("Video Left", frame1);
        waitKey(40);

        cap2.read(frame2);
        resize(frame2, frame2, Size(), 0.25, 0.25);
        imshow("Video Right", frame2);
        waitKey(40);
    }
    waitKey(0);

}

void Scenario::openExcelFile(){
    string filename = "scenario" + Scenario::id + ".xlsx";
    string path = "C:/Users/hp/OneDrive/Bureau/Scenario43"+filename;
    Scenario::ExcelFile.open(path);
}



