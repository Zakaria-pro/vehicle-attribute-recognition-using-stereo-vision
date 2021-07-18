#include "mainwindow.h"
#include "scenario.h"
#include "vehicle.h"

#include <QApplication>

#include <iostream>

using namespace std;
using namespace cv;


int main(){

    // create a scenario
    string pathvl = "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi";
    string pathvr = "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi";
    Scenario scenario43(pathvl, pathvr);


    cout << "path to video left : " << scenario43.path1 << endl;
    cout << "path to video right : " << scenario43.path2 << endl;

    //setup
    scenario43.openExcelFile();

    scenario43.playVideoLeft();
    scenario43.playVideoRight();


//A // detect a vehicle(the same vehicle in the two videos) --> stop the video
    // crop that vehicle from the video1 and video2 and get two images of the vehcile
    // put the two images (left and right) into the folder vehicle+"id"

    // get the path of the two images and create an object Vehicle
    // Call the constructor to build a vehicle with the two images and the id

    // get Points

    // get Dimension(height, length, width)
    // set_info(make, model)
    // add_vehicle_attribute_to_excel
    // start the video from where it has been stopped
    // go to A


    return 0;
}
