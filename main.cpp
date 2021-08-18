#include "mainwindow.h"
#include "scenario.h"
#include "vehicle.h"
#include "vehicle.cpp"

#include <QApplication>

#include <iostream>
#include <fstream>

#include <conio.h>




#if 1


// ----------------------------------- Colors ----------------------------------------//
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);
// -----------------------------------------------------------------------------------//


// ------------------------------ Functions prototypes ------------------------------ //
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
// -----------------------------------------------------------------------------------//



std::fstream mycsvFile; // output File




int g_run = 1;

// left video
cv::VideoCapture g_cap;
cv::Mat frameL;

// right video
cv::VideoCapture g_capR;
cv::Mat frameR;

Vehicle vehicles[500];
int idVeh=1;

int leftClicksNumber = 0;
int rightClicksNumber = 0;

int main(){

    mycsvFile.open("C:/Users/hp/OneDrive/Bureau/click_px/Vehicles.csv", std::ofstream::out | std::ofstream::app);

    if(mycsvFile.is_open()){
        std::cout << "File opened successfuly" <<std::endl;
    }

    //mycsvFile << "Make,Model,Height,Width,Legth\n";


    // Video Left
    cv::namedWindow( "video left", cv::WINDOW_AUTOSIZE );
    g_cap.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi" );



    // Video Right
    cv::namedWindow( "video right", cv::WINDOW_AUTOSIZE );
    g_capR.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi" );



    // info about the videos
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    //g_cap.get(cv::CAP_PROP_XI_HEIGHT)
    std::cout << "Video has " << frames << " frames of dimensions("       << tmpw << ", " << tmph << ")." << std::endl;


    // routine, async execution
    cv::setMouseCallback("video left", CallBackFunc, 0);
    cv::setMouseCallback("video right", CallBackFunc, 0);


    for(;;) {

        // g_run = 1 --> g_run = g_run - 1 --> g_run = 0 --> so makiwalich yadkhal l had l if
        if( g_run != 0 ) {

            g_cap >> frameL;
            g_capR >> frameR;

            std::cout << "frame number : " << g_cap.get(cv::CAP_PROP_POS_FRAMES) << std::endl;

            if(frameL.empty())
                break;

            cv::resize(frameL, frameL, cv::Size(), 0.35, 0.35);
            std::cout << "Dimension of frame : " << frameL.cols << "," << frameL.rows << std::endl;

            cv::resize(frameR, frameR, cv::Size(), 0.35, 0.35);


            cv::imshow( "video left", frameL );
            cv::imshow("video right", frameR);

            std::cout << "---- ENTER Points for calculating HEIGHT :" << std::endl;
            g_run-=1;

        }
        //std::cout << "im here" << std::endl;


        char c = (char) cv::waitKey(10);

        if( c == 's' ) // single step
        {

            g_run = 1;

            std::cout << "Single step, run = " << g_run << std::endl;

        }

        if( c == 'r' ) // run mode
        {

            g_run = -1;

            std::cout << "Run mode, run = " << g_run <<std::endl;

        }

        if( c == 27 )      break; // break if ESC is Pressed

    }


    mycsvFile.close();
    return 0;
}











// --------------------------------------Functions Implementation --------------------------------------//

/////////////////////////////////////////////////////////////////////////////////////////////////
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if  ( event == cv::EVENT_LBUTTONDOWN )
    {



        leftClicksNumber += 1;
        std::cout << "number of left clicks : " << leftClicksNumber << std::endl;

        std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;


        vehicles[idVeh].id = idVeh;

        switch(leftClicksNumber) {
        case 1:
            vehicles[idVeh].points.phl1 = cv::Point(x, y);
            cv::circle(frameL, vehicles[idVeh].points.phl1, 3, SCALAR_GREEN,CV_FILLED, 8,0);
            cv::imshow( "video left", frameL );

//            vehicles[idVeh].points.phr1 = cv::Point(vehicles[idVeh].points.phl1.x-13, vehicles[idVeh].points.phl1.y-3);
//            cv::circle(frameR, vehicles[idVeh].points.phr1, 3, SCALAR_GREEN,CV_FILLED, 8,0);
//            cv::imshow( "video right", frameR );

            break;


        case 2:
            vehicles[idVeh].points.phr1 = cv::Point(x, y);
            cv::circle(frameR, vehicles[idVeh].points.phr1, 3, SCALAR_GREEN,CV_FILLED, 8,0);
            cv::imshow( "video right", frameR );
            vehicles[idVeh].depth();

            break;



//        case 3:
//            vehicles[idVeh].points.phl2 = cv::Point(x, y);
//            cv::circle(frameL, vehicles[idVeh].points.phl2, 3, SCALAR_GREEN,CV_FILLED, 8,0);
//            cv::imshow( "video left", frameL );

//            vehicles[idVeh].points.phr2 = cv::Point(vehicles[idVeh].points.phl2.x-13, vehicles[idVeh].points.phl2.y-3);
//            cv::circle(frameR, vehicles[idVeh].points.phr2, 3, SCALAR_GREEN,CV_FILLED, 8,0);
//            cv::imshow( "video right", frameR );

//            vehicles[idVeh].depth();
            //vehicles[idVeh].disparity();


            //vehicles[idVeh].depth();
            //vehicles[idVeh].calculateHeight();
            //std::cout<<"Height: "<< vehicles[idVeh].features.dimensions.height <<"m"<<std::endl;

//            std::cout << "---- ENTER Points for calculating WIDTH :" << std::endl;
//            break;
//        case 5:
//            vehicles[idVeh].points.pwl1 = cv::Point(x, y);
//            break;
//        case 6:
//            vehicles[idVeh].points.pwl2 = cv::Point(x, y);
//            break;
//        case 7:
//            vehicles[idVeh].points.pwr1 = cv::Point(x, y);
//            break;
//        case 8:
//            vehicles[idVeh].points.pwr2 = cv::Point(x, y);

//            vehicles[idVeh].calculateWidth();

//            std::cout<<"Width: "<< vehicles[idVeh].features.dimensions.width <<"m"<<std::endl;
//            std::cout << "---- ENTER Points for calculating LENGTH :" << std::endl;
//            break;
//        case 9:
//            vehicles[idVeh].points.pll1 = cv::Point(x, y);
//            break;
//        case 10:
//            vehicles[idVeh].points.pll2 = cv::Point(x, y);
//            break;
//        case 11:
//            vehicles[idVeh].points.plr1 = cv::Point(x, y);
//            break;
//        case 12:
//            vehicles[idVeh].points.plr2 = cv::Point(x, y);

//            vehicles[idVeh].calculateLength();

//            std::cout<<"Length: "<< vehicles[idVeh].features.dimensions.length <<"m"<<std::endl;

//            std::cout << "---- ENTER Points for calculating The Distance Between Wheels :" << std::endl;
//            break;



//        default:

//            std::cout << "--------------------------------------------------------------------------------" << std::endl;

//            vehicles[idVeh].showInfo();

//            std::cout << "--------------------------------------------------------------------------------" << std::endl;


//            // code block

        }
      }




    else if  ( event == cv::EVENT_RBUTTONDOWN )
    {
        std::cout << "Writing Vehicle Attributes to csv file ..." << std::endl;
        mycsvFile << vehicles[idVeh].id << ",,,"
                  << vehicles[idVeh].features.dimensions.height << ","
                  << vehicles[idVeh].features.dimensions.width << ","
                  << vehicles[idVeh].features.dimensions.length << "\n";






        std::cout << "Right button of the mouse is clicked"  << std::endl;
        rightClicksNumber += 1;
        std::cout << "number of right clicks : " << rightClicksNumber << std::endl;

        // Moving to another vehicle
        std::cout << "Moving to another vehicle ..." << std::endl;

        idVeh += 1;
        leftClicksNumber = 0;


     }



    else if  ( event == cv::EVENT_MBUTTONDOWN )
    {
        std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    }



    else if ( event == cv::EVENT_MOUSEMOVE )
    {
        //win32api.SetCursor(win32api.LoadCursor(0, win32con.IDC_SIZEALL));
        //std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;
    }
}
#endif
// ------------------------------------------------------------------------------------------------------//

