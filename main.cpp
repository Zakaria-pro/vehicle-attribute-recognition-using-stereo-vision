#include "mainwindow.h"
#include "scenario.h"
#include "vehicle.h"

#include <QApplication>

#include <iostream>

#define NOMINMAX
#include <Windows.h>
#include <conio.h>


// ----------------------------------- Colors ----------------------------------------//
const cv::Scalar SCALAR_BLACK = cv::Scalar(0.0, 0.0, 0.0);
const cv::Scalar SCALAR_WHITE = cv::Scalar(255.0, 255.0, 255.0);
const cv::Scalar SCALAR_YELLOW = cv::Scalar(0.0, 255.0, 255.0);
const cv::Scalar SCALAR_GREEN = cv::Scalar(0.0, 200.0, 0.0);
const cv::Scalar SCALAR_RED = cv::Scalar(0.0, 0.0, 255.0);
// -----------------------------------------------------------------------------------//


// ------------------------------ Functions prototypes ------------------------------ //
void mouseMoveCallback(int event, int x, int y, int flags, void* userData);
void drawCross(cv::Mat &img, cv::Point center, cv::Scalar color);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);
void onTrackbarSlide( int pos, void *);
// -----------------------------------------------------------------------------------//





cv::Point mousePosition(0, 0);

int g_slider_position = 0;
int g_run = 1,
g_dontset = 0; //start out in single step mode

cv::VideoCapture g_cap;





int main(){



    // ------------------------------- create a scenario -------------------------------------------------//
    #if 0
    std::string pathvl = "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi";
    std::string pathvr = "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi";
    Scenario scenario43(pathvl, pathvr);
    #endif
    // ---------------------------------------------------------------------------------------------------//



    // ----------------------- Create a trackbar to play and pause video --------------------------------//
#if 1
    cv::namedWindow( "test", cv::WINDOW_AUTOSIZE );

    g_cap.open( "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi" );

    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "Video has " << frames << " frames of dimensions("       << tmpw << ", " << tmph << ")." << std::endl;

    cv::createTrackbar("Position", "test", &g_slider_position, frames, onTrackbarSlide);

    cv::Mat frame;

    for(;;) {

        if( g_run != 0 ) {

            g_cap >> frame;

            if(frame.empty())

                break;

            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);

            g_dontset = 1;

            cv::setTrackbarPos("Position", "test", current_pos);

            cv::resize(frame, frame, cv::Size(), 0.35, 0.35);
            cv::imshow( "test", frame );

            g_run-=1;

        }

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

        if( c == 27 )      break;

    }
#endif
    // --------------------------------------------------------------------------------------------------//





    // ------------------Play and Pause a video when clicking on Space bar --------------------------------//
    #if 0
    std::string pathvr = "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi";
    cv::VideoCapture cap2(pathvr);
    cv::Mat frame2;

    if(GetAsyncKeyState(VK_SPACE) & 0x8000/*Check if high-order bit is set (1 << 15)*/)
    {
        while(true){
            cap2.read(frame2);
            cv::resize(frame2, frame2, cv::Size(), 0.35, 0.35);
            cv::imshow("Video Right", frame2);
            cv::waitKey(70);

        }
    }
    #endif
    // ---------------------------------------------------------------------------------------------------------//








    // ------------------------------get mouse position on a blank Image----------------------------------------//
    #if 0
    //    cv::Mat img = cv::imread("C:/Resources/Test4.jpg");
    //    cv::resize(img, img, cv::Size(), 0.5, 0.5);

    //if fail to read the image
    if ( img.empty() )
    {
        std::cout << "Error loading the image" << std::endl;
        return -1;
    }

    cv::Mat imgBlank(700, 900, CV_8UC3, cv::Scalar::all(0));

    Create a window
    cv::namedWindow("My Window", 1);

    cv::setMouseCallback("My Window", CallBackFunc, NULL);

    cv::imshow("My Window", imgFrame1);

    cv::waitKey(0);

    #endif
    // ---------------------------------------------------------------------------------------------------------//







    // ------------------------------ get mouse position on a frame of the video ---------------------------------//
    #if 0
    cv::VideoCapture capVideo;
    cv::Mat imgFrame1;

    capVideo.open("C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi");

    if (!capVideo.isOpened()) {
        std::cout << "error reading video file" << std::endl << std::endl;
        _getch();
        return(0); // exit program
    }
    if (capVideo.get(CV_CAP_PROP_FRAME_COUNT) < 2) {
        std::cout << "error: video file must have at least two frames";
        _getch();
        return(0);
    }

    capVideo.read(imgFrame1);
    cv::resize(imgFrame1, imgFrame1, cv::Size(), 0.35, 0.35);

    cv::namedWindow("My Window", 1);

    cv::setMouseCallback("My Window", CallBackFunc, NULL);

    cv::imshow("My Window", imgFrame1);

    cv::waitKey(0);
    #endif
    // ---------------------------------------------------------------------------------------------------------//




    // Record Mouse position on click




    return 0;
}

















// --------------------------------------Functions Implementation --------------------------------------//
/////////////////////////////////////////////////////////////////////////////////////////////////
void onTrackbarSlide( int pos, void *){
    g_cap.set( cv::CAP_PROP_POS_FRAMES, pos );

    if( !g_dontset )

        g_run = 1;  g_dontset = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     if  ( event == cv::EVENT_LBUTTONDOWN )
     {
          std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
     }
     else if  ( event == cv::EVENT_RBUTTONDOWN )
     {
          std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
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


//////////////////////////////////////////////////////////////////////////////////////////////////
void mouseMoveCallback(int event, int x, int y, int flags, void* userData) {
    if (event == CV_EVENT_MOUSEMOVE) {
        mousePosition.x = x;
        mousePosition.y = y;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////
void drawCross(cv::Mat &img, cv::Point center, cv::Scalar color) {
    cv::line(img, cv::Point(center.x - 5, center.y - 5), cv::Point(center.x + 5, center.y + 5), color, 2);
    cv::line(img, cv::Point(center.x + 5, center.y - 5), cv::Point(center.x - 5, center.y + 5), color, 2);

}
// ---------------------------------------------------------------------------------------------------------//
