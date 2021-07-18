#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

struct Points{
    /* ----- the points needed to calculate height----- */
    struct ph{
        // The two points in the left image
        Point pl1, pl2;
        // The two points in the right image
        Point pr1, pr2;
    };

    /* ----- the points needed to calculate width----- */
    struct pw{
        // The two points in the left image
        Point pl1, pl2;
        // The two points in the right image
        Point pr1, pr2;
    };

    /* ----- the points needed to calculate length----- */
    struct pl{
        // The two points in the left image
        Point pl1, pl2;
        // The two points in the right image
        Point pr1, pr2;
    };
};

struct Dimension{
    float height;
    float width;
    float length;
};

struct Info{
    string type;
    string make;
    string model;
};

void on_mouse( int e, int x, int y, int d, void *ptr )
{
    Point*p = (Point*)ptr;
    p->x = x;
    p->y = y;
}



Vehicle::Vehicle(string pathImg1, string pathImg2){ // Contructor
    imgLeft = imread(pathImg1);
    imgRight = imread(pathImg2);
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





