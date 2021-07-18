#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>

#define Size 500

using namespace std;
class Scenario{
    public:
        // ------ Attributes ------//
        int id;
        VideoCapture cap1;
        VideoCapture cap2;

        Vehicle vehicles[Size];

        ofstream sFileExcel;


        // ------ Methods ------//
        Scenario(string pathVleft, string pathVright); // create two videos and an excel file
        void playVideoLeft();
        void playVideoRight();
        void WritetoExcel();
};

#endif // SCENARIO_H
