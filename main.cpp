#include "mainwindow.h"
#include "scenario.h"
#include "vehicle.h"
#include "vehicle.cpp"

#include <QApplication>

#include <iostream>

#include <conio.h>


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





int g_run = 1;

cv::VideoCapture g_cap;
cv::VideoCapture g_capR;

Vehicle vehicles[500];
int idVeh=1;

int leftClicksNumber = 0;
int rightClicksNumber = 0;

int main(){




    // ----------------------- Create a trackbar to play and pause video and get position --------------------------------//

    // Video Left
    cv::namedWindow( "video left", cv::WINDOW_AUTOSIZE );
    g_cap.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi" );
    cv::Mat frameL;


    // Video Right
    cv::namedWindow( "video right", cv::WINDOW_AUTOSIZE );
    g_capR.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi" );
    cv::Mat frameR;



    // info on video
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
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

    // --------------------------------------------------------------------------------------------------//



    // ------------------Play and Pause a video when clicking on Space bar --------------------------------//

    /*
    cv::namedWindow( "video right", cv::WINDOW_AUTOSIZE );

    g_cap.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi" );

    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has " << frames << " frames of dimensions("       << tmpw << ", " << tmph << ")." << std::endl;

    cv::createTrackbar("Position", "video right", &g_slider_position, frames, onTrackbarSlide);

    cv::Mat frame;




    // routine, async execution
    //cv::setMouseCallback("test", CallBackFunc, 0);

    // routine, async execution
    //int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
    //cv::setTrackbarPos("Position", "test", current_pos);


    for(;;) {

        // g_run = 1 --> g_run = g_run - 1 --> g_run = 0 --> so makiwalich yadkhal l had l if
        if( g_run != 0 ) {


            g_cap >> frame;


            if(frame.empty())
                //std::cout << "EOF" << std::endl;
                break;

            g_dontset = 1;

            cv::resize(frame, frame, cv::Size(), 0.35, 0.35);
            cv::imshow( "test", frame );

            std::cout << "up" << std::endl;

            g_run-=1;
            std::cout << "g_run = " << g_run << std::endl;
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
    */

    // ---------------------------------------------------------------------------------------------------------//

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
            break;
        case 2:
            vehicles[idVeh].points.phl2 = cv::Point(x, y);
            break;
        case 3:
            vehicles[idVeh].points.phr1 = cv::Point(x, y);
            break;
        case 4:
            vehicles[idVeh].points.phr2 = cv::Point(x, y);
            std::cout << "---- ENTER Points for calculating WIDTH :" << std::endl;
            break;
        case 5:
            vehicles[idVeh].points.pwl1 = cv::Point(x, y);
            break;
        case 6:
            vehicles[idVeh].points.pwl2 = cv::Point(x, y);
            break;
        case 7:
            vehicles[idVeh].points.pwr1 = cv::Point(x, y);
            break;
        case 8:
            vehicles[idVeh].points.pwr2 = cv::Point(x, y);
            std::cout << "---- ENTER Points for calculating LENGTH :" << std::endl;
            break;
        case 9:
            vehicles[idVeh].points.pll1 = cv::Point(x, y);
            break;
        case 10:
            vehicles[idVeh].points.pll2 = cv::Point(x, y);
            break;
        case 11:
            vehicles[idVeh].points.plr1 = cv::Point(x, y);
            break;
        case 12:
            vehicles[idVeh].points.plr2 = cv::Point(x, y);
            vehicles[idVeh].calculateDimensions();
            std::cout << "---- ENTER Points for calculating The Distance Between Wheels :" << std::endl;
            break;



        default:

            std::cout << "--------------------------------------------------------------------------------" << std::endl;

            vehicles[idVeh].showInfo();

            std::cout << "--------------------------------------------------------------------------------" << std::endl;


            // code block

        }


        //std::cout << "points for calculating height : ";
        //cv::setMouseCallback("test", CallBackFunc, 0);

        // cv::circle(frame, cv::Point(x, y), 155, SCALAR_YELLOW, cv::FILLED);
    }




    else if  ( event == cv::EVENT_RBUTTONDOWN )
    {
        std::cout << "Writing Vehicle Attributes to Excel sheet ..." << std::endl;
        vehicles[idVeh].addVehicleToSheet();

        std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
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
        //std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;
    }
}

// ------------------------------------------------------------------------------------------------------//

