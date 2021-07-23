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

cv::Point mousePosition(0, 0);

// ------------------------------ Functions prototypes ------------------------------ //
void mouseMoveCallback(int event, int x, int y, int flags, void* userData);
void drawCross(cv::Mat &img, cv::Point center, cv::Scalar color);
// -----------------------------------------------------------------------------------//




int main(){



    // ------------------------------- create a scenario -------------------------------------------------//
    #if 0
    std::string pathvl = "C:/Users/hp/OneDrive/Bureau/Scenario43/1.avi";
    std::string pathvr = "C:/Users/hp/OneDrive/Bureau/Scenario43/2.avi";
    Scenario scenario43(pathvl, pathvr);
    #endif
    // ---------------------------------------------------------------------------------------------------//






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






    // -----Play
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

    // --------


    // ------------------------------get mouse position on a blank Image----------------------------------------//
    #if 1
    while (capVideo.isOpened() ){


        cv::Mat imgBlank(700, 900, CV_8UC3, cv::Scalar::all(0));
        std::vector<cv::Point> mousePositions;

        cv::setMouseCallback("imgBlank", mouseMoveCallback);

        while(true){
            mousePositions.push_back(mousePosition);        // get the current position
            std::cout << "current position        = " << mousePositions.back().x << ", " << mousePositions.back().y << "\n";
            drawCross(imgBlank, mousePositions.back(), SCALAR_WHITE);
            cv::imshow("imgBlank", imgBlank);         // show the image
            cv::waitKey(10);                    // pause for a moment to get operating system to redraw the imgBlank
            imgBlank = cv::Scalar::all(0);         // blank the imgBlank for next time around
        }



        currentFrameBlobs.clear();

        imgFrame1 = imgFrame2.clone();           // move frame 1 up to where frame 2 is

        if ((capVideo.get(CV_CAP_PROP_POS_FRAMES) + 1) < capVideo.get(CV_CAP_PROP_FRAME_COUNT)) {
            capVideo.read(imgFrame2);
        } else {
            std::cout << "end of video\n";
            break;
        }

        blnFirstFrame = false;
        frameCount++;
        chCheckForEscKey = cv::waitKey(1);
        // --------------------------------------------------------------------------//


    } //end while

    if (chCheckForEscKey != 27) {               // if the user did not press esc (i.e. we reached the end of the video)
        cv::waitKey(0);                         // hold the windows open to allow the "end of video" message to show
    }


    }
    #endif


    // ---------------------------------------------------------------------------------------------------------//



    // ------------------------------get mouse position on a frame of the video---------------------------------//


    // Record Mouse position on click




    return 0;
}

















// --------------------------------------Functions Implementation --------------------------------------//
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
