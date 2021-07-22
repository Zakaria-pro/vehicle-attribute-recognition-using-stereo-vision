#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <iostream>
#include "vehicle.h"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>

using namespace std;
class Scenario{
    public:
        // ------ Attributes ------//
        string id;
        string path1;
        string path2;

        // Vehicle vehicles[500];
        vector<Vehicle> vehicles;
        ofstream ExcelFile;


        // ------ Methods ------//

        Scenario(string pathVleft,string pathVright); // Constructor

        void playVideoLeft();
        void playVideoRight();
        void playTwoVideos();

        void openExcelFile();
};

#endif // SCENARIO_H
