#ifndef VEHICLE_H
#define VEHICLE_H

#include<opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

#include<string>

using namespace cv;
using namespace std;

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

//void on_mouse( int e, int x, int y, int d, void *ptr )
//{
//    Point*p = (Point*)ptr;
//    p->x = x;
//    p->y = y;
//}



class Vehicle {
    public:
        /* --------------------- Attributs -------------------------*/
        int id;
        Mat imgLeft;
        Mat imgRight;


        Points points; // 12 points (4 points for each dimension) // 24 cordonnées

        Dimension dim; // 3 dimension (width, height, length)


        Info CurrentInfo; // Made by me (hadi mercedes benz class C)

        Info predictedInfo; // Made by the machine (tal model 9al 3la anaha mercedes benz class C )


        /* --------------------- Methods -------------------------*/
        Vehicle();
        Vehicle(string pathImg1, string pathImg2);

        // 12 points
        void TakePointsHeight();
        void TakePointsWidth();
        void TakePointsLength();

        // 3 dimension
        float calculateHeight();
        float calculateWidth();
        float calculateLength();


        // by me (ta9afa 3ama)
        void setCurrentInfo(string type, string make, string model);

        //
        void addVehicleToSheet();
};


#endif // VEHICLE_H
