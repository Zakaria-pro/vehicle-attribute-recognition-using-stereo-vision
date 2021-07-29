#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>




float f=1060,b=119.91;

// ---------------------------------- 3 dimension --------------------------------//
void Vehicle::calculateHeight(){
//    double z1,z2,
//            x1,x2,
//            y1,y2,
//            dp1,dp2,
//            dist_dep,height;


//    dp1=abs(points.phl1.x-points.phr1.x);
//    // calculate height :
//    z1=(f*b)/(dp1);
//    x1=((points.phr1.x)*z1)/f;
//    y1=((points.phr1.y)*z1)/f;


//    dp2=abs(points.phl2.x-points.phr2.x);
////    cout<<"disparité 2 est:"<<dp2<<endl;

//    z2=(f*b)/(dp2);
//    x2=(points.phr2.x*z2)/f;
//    y2=(points.phr2.y*z2)/f;



//    dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
//    //std::cout<<"Height: "<< height <<"m"<<std::endl;
//    height = dist_dep/1000;

//    features.dimensions.height = height;

}


void Vehicle::calculateWidth(){
    // The Width is the depth
    double z1,z2,
            x1,x2,
            y1,y2,
            dp1,dp2,
            dist_dep,width;


    dp1=abs(points.pwl1.x-points.pwr1.x);
    // calculate height :
    z1=(f*b)/(dp1);
    x1=((points.pwr1.x)*z1)/f;
    y1=((points.pwr1.y)*z1)/f;


    dp2=abs(points.pwl2.x-points.pwr2.x);
//    cout<<"disparité 2 est:"<<dp2<<endl;

    z2=(f*b)/(dp2);
    x2=(points.pwr2.x*z2)/f;
    y2=(points.pwr2.y*z2)/f;



    dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
    //std::cout<<"Height: "<< height <<"m"<<std::endl;
    width = dist_dep/1000;

    features.dimensions.width = width;

}


void Vehicle::calculateLegth(){
//    double z1,z2,
//            x1,x2,
//            y1,y2,
//            dp1,dp2,
//            dist_dep,length;


//    dp1=abs(points.pll1.x-points.plr1.x);
//    // calculate height :
//    z1=(f*b)/(dp1);
//    x1=((points.plr1.x)*z1)/f;
//    y1=((points.plr1.y)*z1)/f;


//    dp2=abs(points.pll2.x-points.plr2.x);
////    cout<<"disparité 2 est:"<<dp2<<endl;

//    z2=(f*b)/(dp2);
//    x2=(points.plr2.x*z2)/f;
//    y2=(points.plr2.y*z2)/f;



//    dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
//    //std::cout<<"Height: "<< height <<"m"<<std::endl;
//    length = dist_dep/1000;

//    features.dimensions.length = length;

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





