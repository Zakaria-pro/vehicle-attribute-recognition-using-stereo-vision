#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>

std::fstream csvFile;

float f=1060, //en pixel
    b=11.991; //en cm


// ---------------------------------- 3 dimension --------------------------------//

//void Vehicle::depth(){
//    double z1,z2,
//            x1,x2,
//            y1,y2,
//             dist;


//    float dp1=abs(points.phl1.x-points.phr1.x);
//    float zDepth1 = f*b/dp1;
//    z1 = zDepth1;
//    x1=((points.phl1.x)*z1)/f;
//    y1=((points.phl1.y)*z1)/f;


//    //
//    float dp2=abs(points.phl2.x-points.phr2.x);
//    float zDepth2 = f*b/dp2;
//    z2 = zDepth2;
//    x2=((points.phl2.x)*z2)/f;
//    y2=((points.phl2.y)*z2)/f;

//    std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
//    std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";



//    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
//    std::cout << "The distance between the two Points is : " << dist/100 << "m";




////    float dp2=abs(points.phl2.x-points.phr2.x);
////    float zDepth2 = f*b/dp2;
////    std::cout << "the distance between the point 2 and the camera is : " << std::abs(zDepth2)/1000 << "m\n";



////    std::cout << dp1;
////    std::cout << dp2;
//}

//void Vehicle::disparity(){

//    double z1,z2,
//            x1,x2,
//            y1,y2,
//            dp1,dp2, dist;

//    dp1=abs(points.phl1.x-points.phr1.x);
//    // calculate height :
//    z1=(f*b)/(dp1);
//    x1=((points.phl1.x)*z1)/f;
//    y1=((points.phl1.y)*z1)/f;


//    dp2=abs(points.phl2.x-points.phr2.x);
//    // calculate height :
//    z2=(f*b)/(dp2);
//    x2=((points.phl2.x)*z2)/f;
//    y2=((points.phl2.y)*z2)/f;

//    std::cout << "x1 = " << x1 << " y1 = " << y1 << " z1 = " << z1 << std::endl;
//    std::cout << "x2 = " << x2 << " y2 = " << y2 << " z2 = " << z2 << std::endl;

//    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

//    std::cout << "disparity of the point 1 : " << dp1 << std::endl;
//    std::cout << "disparity of the point 2 : " << dp2 << std::endl;

//    std::cout << "depth of the point 1 : " << 1/dp1 << std::endl;
//    std::cout << "depth of the point 2 : " << 1/dp2 << std::endl;

//    std::cout << "distance virtuelle entre les deux points : " << dist << std::endl;


//    csvFile << x1 << ","
//              << y1 << ","
//              << z1 << "\n";


    //dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
    //std::cout<<"Height: "<< height <<"m"<<std::endl;
    //height = dist_dep/1000;

    //features.dimensions.height = height;
//}



void Vehicle::calculateHeight(){
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.phl1.x-points.phr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.phl1.x)*z1)/f;
    y1=((points.phl1.y)*z1)/f;


    //
    float dp2=abs(points.phl2.x-points.phr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.phl2.x)*z2)/f;
    y2=((points.phl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.dimensions.height = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}


void Vehicle::calculateWidth(){
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pwl1.x-points.pwr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pwl1.x)*z1)/f;
    y1=((points.pwl1.y)*z1)/f;


    //
    float dp2=abs(points.pwl2.x-points.pwr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pwl2.x)*z2)/f;
    y2=((points.pwl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.dimensions.width = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}


void Vehicle::calculateLength(){
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pll1.x-points.plr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pll1.x)*z1)/f;
    y1=((points.pll1.y)*z1)/f;


    //
    float dp2=abs(points.pll2.x-points.plr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pll2.x)*z2)/f;
    y2=((points.pll2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.dimensions.length = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}

// ------------------------------------------------------------------------------//


void Vehicle::calculateDistanceBetweenWheels() // Distance entre les roues
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pwhl1.x-points.pwhr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pwhl1.x)*z1)/f;
    y1=((points.pwhl1.y)*z1)/f;


    //
    float dp2=abs(points.pwhl2.x-points.pwhr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pwhl2.x)*z2)/f;
    y2=((points.pwhl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.distanceBetweenWheels = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}

void Vehicle::calculateDistanceBetweenHeadlights() // L’espacement(distance) entre les phares .
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.phdll1.x-points.phdlr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.phdll1.x)*z1)/f;
    y1=((points.phdll1.y)*z1)/f;


    //
    float dp2=abs(points.phdll2.x-points.phdlr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.phdll2.x)*z2)/f;
    y2=((points.phdll2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.distanceBetweenHeadlights = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}

void::Vehicle::calculateDistanceBetweenHandles() // Distance entre les poignées.
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.phdl1.x-points.phdr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.phdl1.x)*z1)/f;
    y1=((points.phdl1.y)*z1)/f;


    //
    float dp2=abs(points.phdl2.x-points.phdr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.phdl2.x)*z2)/f;
    y2=((points.phdl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.distanceBetweenHandles = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}


void::Vehicle::calculateWheelsDiameter() // Diamètres des roues.
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pwhdl1.x-points.pwhdr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pwhdl1.x)*z1)/f;
    y1=((points.pwhdl1.y)*z1)/f;


    //
    float dp2=abs(points.pwhdl2.x-points.pwhdr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pwhdl2.x)*z2)/f;
    y2=((points.pwhdl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.wheelDiameter = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}

void Vehicle::calculateMaxWindowHeight() // La hauteur maximum des fenêtres.
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pmwhl1.x-points.pmwhr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pmwhl1.x)*z1)/f;
    y1=((points.pmwhl1.y)*z1)/f;


    //
    float dp2=abs(points.pmwhl2.x-points.pmwhr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pmwhl2.x)*z2)/f;
    y2=((points.pmwhl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.maxHeightOfWindows = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}



void::Vehicle::calculateDistanceBetweenWindowAndGround() // La distance entre le bas de la fenêtre et le sol.
{
    double z1,z2,
            x1,x2,
            y1,y2,
             dist;


    float dp1=abs(points.pwgl1.x-points.pwgr1.x);
    float zDepth1 = f*b/dp1;
    z1 = zDepth1;
    x1=((points.pwgl1.x)*z1)/f;
    y1=((points.pwgl1.y)*z1)/f;


    //
    float dp2=abs(points.pwgl2.x-points.pwgr2.x);
    float zDepth2 = f*b/dp2;
    z2 = zDepth2;
    x2=((points.pwgl2.x)*z2)/f;
    y2=((points.pwgl2.y)*z2)/f;

    //std::cout << "the distance between the point 1 and the camera is : " << z1/100 << "m\n";
    //std::cout << "the distance between the point 2 and the camera is : " << z2/100 << "m\n";

    dist = sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));

    features.distanceBetweenWindowAndGround = dist/100; //
    //std::cout << "The distance between the two Points is : " << dist/100 << "m";

}


// ----------------------------------- Ratio .. ---------------------------------//
void Vehicle::calculateRatios(){
    // Le ratio de la hauteur et la distance entre les roues .


    // Le ratio de la hauteur  et la longueur.


    // Le ratio de la distance entre les roues et la longueur .


    // Le ratio de la distance entre les phares  et la largeur du véhicule.
}

// ------------------------------------------------------------------------------//




/*void Vehicle::setCurrentInfo(std::string type, std::string make, std::string model){
//    CurrentInfo.type = type;
//    CurrentInfo.make = make;
//    CurrentInfo.model = model;
}*/


void Vehicle::showInfo(){

    std::cout << "height : " << features.dimensions.height << std::endl;
    std::cout << "width : " << features.dimensions.width << std::endl;
    std::cout << "length : " << features.dimensions.length << std::endl;

    std::cout << "distanceBetweenWheels : " << features.distanceBetweenWheels << std::endl;

    std::cout << "distanceBetweenHeadlights : " << features.distanceBetweenHeadlights << std::endl;

    std::cout << "distanceBetweenHandles : " << features.distanceBetweenHandles << std::endl;

    std::cout << "wheelDiameter : " << features.wheelDiameter << std::endl;

    std::cout << "maxHeightOfWindows : " << features.maxHeightOfWindows << std::endl;

    std::cout << "distanceBetweenWindowAndGround : " << features.distanceBetweenWindowAndGround << std::endl;
}



void Vehicle::addVehicleToSheet(){

}







//    std::cout << "ID of the vehicle : " << id << std::endl;

//    std::cout << "points for calculating height : " << std::endl;
//    std::cout << points.phl1 << "|" << points.phl2 << "|" << points.phr1 << "|" << points.phr2 <<std::endl;

//    std::cout << "points for calculating width" << std::endl;
//    std::cout << points.pwl1 << "|" << points.pwl2 << "|" << points.pwr1 << "|" << points.pwr2 <<std::endl;

//    std::cout << "points for calculating length" << std::endl;
//    std::cout << points.pll1 << "|" << points.pll2 << "|" << points.plr1 << "|" << points.plr2 <<std::endl;



