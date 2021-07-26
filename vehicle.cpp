#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>




float f=1060,b=119.91;

// ---------------------------------- 3 dimension --------------------------------//
void Vehicle::calculateDimensions(){
    double height, width, length;



    features.dimensions.height = height;
    features.dimensions.width = width;
    features.dimensions.length = length;
}


// ------------------------------------------------------------------------------//



void Vehicle::calculateDistanceBetweenWheels() // Distance entre les roues
{

}

void Vehicle::calculateDistanceBetweenHeadlights() // L’espacement(distance) entre les phares .
{

}


// ----------------------------------- Ratio .. ---------------------------------//
void Vehicle::calculateRatios(){
    // Le ratio de la hauteur et la distance entre les roues .


    // Le ratio de la hauteur  et la longueur.


    // Le ratio de la distance entre les roues et la longueur .


    // Le ratio de la distance entre les phares  et la largeur du véhicule.
}

// ------------------------------------------------------------------------------//


void Vehicle::calculateMaxWindowHeight() // La hauteur maximum des fenêtres.
{

}

void::Vehicle::calculateDistanceBetweenHandles() // Distance entre les poignées.
{

}

void::Vehicle::calculateWheelsDiameter() // Diamètres des roues.
{

}

void::Vehicle::calculateDistanceBetweenWindowAndGround() // La distance entre le bas de la fenêtre et le sol.
{

}

/*void Vehicle::setCurrentInfo(std::string type, std::string make, std::string model){
//    CurrentInfo.type = type;
//    CurrentInfo.make = make;
//    CurrentInfo.model = model;
}*/

void Vehicle::showInfo(){
    std::cout << "ID of the vehicle : " << id << std::endl;

    std::cout << "points for calculating height : " << std::endl;
    std::cout << points.phl1 << "|" << points.phl2 << "|" << points.phr1 << "|" << points.phr2 <<std::endl;

    std::cout << "points for calculating width" << std::endl;
    std::cout << points.pwl1 << "|" << points.pwl2 << "|" << points.pwr1 << "|" << points.pwr2 <<std::endl;

    std::cout << "points for calculating length" << std::endl;
    std::cout << points.pll1 << "|" << points.pll2 << "|" << points.plr1 << "|" << points.plr2 <<std::endl;

    std::cout << "height : " << features.dimensions.height << std::endl;

}


void Vehicle::addVehicleToSheet(){

}





