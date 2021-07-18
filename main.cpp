#include "mainwindow.h"
#include "scenario.h"
#include "vehicle.h"

#include <QApplication>

#include <iostream>

using namespace std;



int main(){
    // create a scenario
    string pathvl = "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi";
    string pathvr = "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi";
    Scenario scenario43(pathvl, pathvr);
    scenario43.playVideoLeft();
    scenario43.playVideoRight();
    return 0;

}
