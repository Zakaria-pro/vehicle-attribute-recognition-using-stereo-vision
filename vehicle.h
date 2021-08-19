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

    // The two points in the left image
    cv::Point phl1, phl2;
    // The two points in the right image
    cv::Point phr1, phr2;


    /* ----- the points needed to calculate width----- */

    // The two points in the left image
    cv::Point pwl1, pwl2;
    // The two points in the right image
    cv::Point pwr1, pwr2;


    /* ----- the points needed to calculate length----- */

    // The two points in the left image
    cv::Point pll1, pll2;
    // The two points in the right image
    cv::Point plr1, plr2;

    /* ----- the points needed to calculate distance between wheels----- */

    // The two points in the left image
    cv::Point pwhl1, pwhl2;
    // The two points in the right image
    cv::Point pwhr1, pwhr2;


    /* ----- the points needed to calculate distance between headlights----- */

    // The two points in the left image
    cv::Point phdll1, phdll2;
    // The two points in the right image
    cv::Point phdlr1, phdlr2;

    /* ----- the points needed to calculate distance between handles----- */

    // The two points in the left image
    cv::Point phdl1, phdl2;
    // The two points in the right image
    cv::Point phdr1, phdr2;

    /* ----- the points needed to calculate wheel diameter----- */

    // The two points in the left image
    cv::Point pwhdl1, pwhdl2;
    // The two points in the right image
    cv::Point pwhdr1, pwhdr2;


    /* ----- the points needed to calculate max window height----- */

    // The two points in the left image
    cv::Point pmwhl1, pmwhl2;
    // The two points in the right image
    cv::Point pmwhr1, pmwhr2;


    /* ----- the points needed to calculate distance between window and ground----- */

    // The two points in the left image
    cv::Point pwgl1, pwgl2;
    // The two points in the right image
    cv::Point pwgr1, pwgr2;


};

struct Dimension{
    double height;
    double width;
    double length;
};

struct Ratios{
    double ratioHeightAndDistancebetweenwheels;    // Le ratio de la hauteur et la distance entre les roues .
    double ratioHeightAndLegth;                    // Le ratio de la hauteur  et la longueur.
    double ratioDistancebetweenwheelsAndLegth;     // Le ratio de la distance entre les roues et la longueur .
    double ratioDistancebetweenheadlightsAndWidth; // Le ratio de la distance entre les phares  et la largeur du véhicule.

};

struct Features{
    struct Dimension dimensions;            // Hauteur, Largeur, et longueur.
    double distanceBetweenWheels;           // La distance entre les roues
    double distanceBetweenHeadlights;       // La distance entre les phares
    double distanceBetweenHandles;
    struct Ratios ratios;                   // Calcul des ratios
    double maxHeightOfWindows;              // La hauteur maximum des fenêtres.
    double wheelDiameter;                   // Diamètres des roues.
    double distanceBetweenWindowAndGround;  // La distance entre le bas de la fenêtre et le sol.
};

struct CurrentInfo{
    std::string type;
    std::string make;
    std::string model;
};



class Vehicle {
    public:
        /* --------------------- Attributs -------------------------*/
        int id;

        struct Points points;

        struct Features features;

        struct CurrentInfo info; // Made by me (hadi mercedes benz class C)

        struct CurrentInfo predictedInfo; // Made by the machine (tal model 9al 3la anaha mercedes benz class C )


        /* --------------------- Methods -------------------------*/

        void calculateHeight();
        void calculateWidth();
        void calculateLength();

        //void disparity();
        //void depth();


        void calculateDistanceBetweenWheels();
        void calculateDistanceBetweenHeadlights();
        void calculateDistanceBetweenHandles();
        void calculateWheelsDiameter();
        void calculateMaxWindowHeight();
        void calculateDistanceBetweenWindowAndGround();

        void calculateRatios();








        void showInfo();

        // by me (ta9afa 3ama)
        void setCurrentInfo(std::string type, std::string make, std::string model);

        //
        void addVehicleToSheet();
};


#endif // VEHICLE_H
