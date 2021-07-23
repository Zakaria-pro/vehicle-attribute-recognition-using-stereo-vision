#ifndef VEHICLE_H
#define VEHICLE_H

#include<opencv2/highgui.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/core.hpp>
#include<opencv2/imgcodecs.hpp>
#include<opencv2/imgproc.hpp>

#include<string>


struct Points{
    /* ----- the points needed to calculate height----- */
    struct ph{
        // The two points in the left image
        cv::Point pl1, pl2;
        // The two points in the right image
        cv::Point pr1, pr2;
    };

    /* ----- the points needed to calculate width----- */
    struct pw{
        // The two points in the left image
        cv::Point pl1, pl2;
        // The two points in the right image
        cv::Point pr1, pr2;
    };

    /* ----- the points needed to calculate length----- */
    struct pl{
        // The two points in the left image
        cv::Point pl1, pl2;
        // The two points in the right image
        cv::Point pr1, pr2;
    };
};

struct Dimension{
    float height;
    float width;
    float length;
};

struct Info{
    std::string type;
    std::string make;
    std::string model;
};


class Vehicle {
    public:
        /* --------------------- Attributs -------------------------*/
        int id;
        cv::Mat imgLeft;
        cv::Mat imgRight;

        Points points; // 12 points (4 points for each dimension) // 24 cordonnées

        Dimension dim; // 3 dimension (width, height, length)

        Info CurrentInfo; // Made by me (hadi mercedes benz class C)

        Info predictedInfo; // Made by the machine (tal model 9al 3la anaha mercedes benz class C )


        /* --------------------- Methods -------------------------*/
        Vehicle();
        Vehicle(std::string pathImg1, std::string pathImg2);

        // 12 points
        void TakePointsHeight();
        void TakePointsWidth();
        void TakePointsLength();

        // 3 dimension
        float calculateHeight();
        float calculateWidth();
        float calculateLength();


        // by me (ta9afa 3ama)
        void setCurrentInfo(std::string type, std::string make, std::string model);

        //
        void addVehicleToSheet();
};


#endif // VEHICLE_H
