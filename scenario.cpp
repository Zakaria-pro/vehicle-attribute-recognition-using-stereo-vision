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
    cap1(pathVleft); // VideoLeft
    cap2(pathVright); // VideoRight
    id = "43";

    // Output
    string filename = "scenario";
    filename = filename << id << ".xlsx";
    path = "C:/Users/hp/OneDrive/Bureau/Scenario43";
    sFileExcel(filename);
}

void Scenario::playVideoLeft(){
    Mat img;
    while (true) {
        cap1.read(img);
        imshow("image", img);
        waitKey(20);
    }
}
void Scenario::playVideoRight(){
    Mat img;
    while (true) {
        cap2.read(img);
        imshow("image", img);
        waitKey(20);
    }
}

void Scenario::WritetoExcel(){
    MyFile << "Files can be tricky, but it is fun enough!";
}

