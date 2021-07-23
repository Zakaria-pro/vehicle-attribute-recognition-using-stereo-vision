#ifndef SCENARIO_H
#define SCENARIO_H

#include <string>
#include <iostream>
#include <vehicle.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <fstream>


class Scenario{
    public:
        // ------ Attributes ------//
        std::string id;
        std::string path1;
        std::string path2;

        //Vehicle vehicles[500];

        std::ofstream ExcelFile;


        // ------ Methods ------//

        Scenario(std::string pathVleft, std::string pathVright); // Constructor

        void playVideoLeft();
        void playVideoRight();
        void playTwoVideos();

        void openExcelFile();
};

#endif // SCENARIO_H
