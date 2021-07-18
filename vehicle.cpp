#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;


Vehicle::Vehicle(){}

Vehicle::Vehicle(string pathImg1, string pathImg2){ // Contructor
    Vehicle::imgLeft = imread(pathImg1);
    Vehicle::imgRight = imread(pathImg2);
}

// 12 points
void Vehicle::TakePointsHeight(){ // 4 points

    points.ph.pl1 = ;
    points.ph.pr1 = ;

    points.ph.pl2 = ;
    points.ph.pr2 = ;
}
void Vehicle::TakePointsWidth(){ // 4 points

    points.pw.pl1 = ;
    points.pw.pr1 = ;

    points.pw.pl2 = ;
    points.pw.pr2 = ;
}
void Vehicle::TakePointsLength(){ // 4 points

    points.pl.pl1 = ;
    points.pl.pr1 = ;

    points.pl.pl2 = ;
    points.pl.pr2 = ;
}

// 3 dimension
float Vehicle::calculateHeight(){
    string height;
    //
    return height;
}
float Vehicle::calculateWidth(){
    string width;
    //
    return width;
}
float Vehicle::calculateLength(){
    string length;
    //
    return length;
}


// by me (ta9afa 3ama)
void Vehicle::setCurrentInfo(string type, string make, string model){
    CurrentInfo.type = type;
    CurrentInfo.make = make;
    CurrentInfo.model = model;
}

//
void Vehicle::addVehicleToSheet(){

}





