#include "scenario.h"
#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>


using namespace std;
using namespace cv;

Scenario::Scenario(string pathVleft, string pathVright){ // Constructor

    // Input
    Scenario::path1 = pathVleft;
    Scenario::path2 = pathVright;
    Scenario::id = "43";

    // Output
    string filename = "scenario" + Scenario::id + ".xlsx";
    string path = "C:/Users/hp/OneDrive/Bureau/Scenario43"+filename;
    Scenario::sFileExcel.open(path);
}

void Scenario::playVideoLeft(){
    VideoCapture cap1(Scenario::path1); // VideoLeft
    Mat img;
    while (true) {
        cap1.read(img);
        imshow("image", img);
        waitKey(20);
    }
}
void Scenario::playVideoRight(){
    VideoCapture cap2(Scenario::path2);
    Mat img;
    while (true) {
        cap2.read(img);
        imshow("image", img);
        waitKey(20);
    }
}

void Scenario::WritetoExcel(){
    Scenario::sFileExcel << "Files can be tricky, but it is fun enough!";
    Scenario::sFileExcel.close();
}

