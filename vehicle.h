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

        void calculateDimensions();
        void Vehicle::calculateDistanceBetweenWheels();
        void Vehicle::calculateDistanceBetweenHeadlights();

        void Vehicle::calculateRatios();

        void Vehicle::calculateMaxWindowHeight();
        void::Vehicle::calculateDistanceBetweenHandles();
        void::Vehicle::calculateWheelsDiameter();
        void::Vehicle::calculateDistanceBetweenWindowAndGround();


        void showInfo();

        // by me (ta9afa 3ama)
        void setCurrentInfo(std::string type, std::string make, std::string model);

        //
        void addVehicleToSheet();
};


#endif // VEHICLE_H
