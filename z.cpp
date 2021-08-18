/*
#include "mainwindow.h"
#include <QApplication>

#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void on_mouse( int e, int x, int y, int d, void *ptr )
{
    Point*p = (Point*)ptr;
    p->x = x;
    p->y = y;
}

void dsp1(){

    float xl, yl,    // P1 left
          xr, yr;    // P1 right


    // Read image from file

    Mat left  = imread("C:/Resources/left.jpg",IMREAD_COLOR);
    Mat right = imread("C:/Resources/right.jpg",IMREAD_COLOR);

    Point p;


    //Create a window
    namedWindow("My Window", 1);

    //set the callback function for any mouse event

    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", left);

    // Wait until user press some key
    waitKey(0);
    xl=p.x;
    yl=p.y;
    //    cout<<"xl is "<<xl<<endl;
    //    cout<<"yl is "<<yl<<endl;





    //Create a window
    namedWindow("My Window", 1);
    //set the callback function for any mouse event
    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", right);
    // Wait until user press some key
    waitKey(0);

    xr=p.x;
    yr=p.y;
    //    cout<<"xr is "<<xr<<endl;
    //    cout<<"yr is "<<yr<<endl;







    // Calculate width, length and height.

    float f=1060,b=119.91;
    float z1, x1, y1, dp1;

    dp1=abs(xl-xr);
    //cout<<"disparité 1:"<<dp1<<endl;
    z1=(f*b)/(dp1); // Calculer ..
    x1=((xr)*z1)/f; // Calculer ..
    y1=((yr)*z1)/f; // Calculer ..

}

void dsp2(){

    float xl1, yl1,  // P2 left
            xr1, yr1;  // P2 right

    Mat left1  = imread("/home/hamza/wheel_spd/S2/Left/30m.png",IMREAD_COLOR);
    Mat right1 = imread("/home/hamza/wheel_spd/S2/Right/30m.png",IMREAD_COLOR);


    namedWindow("My Window", 1);
    setMouseCallback("My Window", on_mouse, &p );
    imshow("My Window", left1);
    waitKey(0);
    xl1=p.x;
    yl1=p.y;
    //    cout<<"xl1 is "<<p.x<<endl;
    //    cout<<"yl1 is "<<p.y<<endl;





    namedWindow("My Window", 1);
    setMouseCallback("My Window", on_mouse, &p );
    imshow("My Window", right1);
    waitKey(0);
    xr1=p.x;
    yr1=p.y;
    //    cout<<"xr1 is "<<p.x<<endl;
    //    cout<<"yr1 is "<<p.y<<endl;




    float f=1060,b=119.91;
    float z2, x2, y2, dp2;

    dp2=abs(xl1-xr1);
    //cout<<"disparité 2 est:"<<dp2<<endl;
    z2=(f*b)/(dp2);
    x2=(xl1*z2)/f;
    y2=(yl1*z2)/f;

}

void distance_deplacement(){
    dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
    cout<<"distance de déplacement:"<<dist_dep/1000<<"m"<<endl;
}
*/

//void on_mouse( int e, int x, int y, int d, void *ptr )
//{
//    Point*p = (Point*)ptr;
//    p->x = x;
//    p->y = y;
//}

#if 0
using namespace std;
using namespace cv;

void on_mouse( int e, int x, int y, int d, void *ptr )
{
    Point*p = (Point*)ptr;
    p->x = x;
    p->y = y;
}

int main(int argc, char** argv)
{
    float xl,yl,xr,yr,xl1,yl1,xr1,yr1;
    // Read image from file

    //
    Mat left  = imread("/home/hamza/wheel_spd/S2/Left/5m.png",IMREAD_COLOR);
    Mat right = imread("/home/hamza/wheel_spd/S2/Right/5m.png",IMREAD_COLOR);

    Mat left1  = imread("/home/hamza/wheel_spd/S2/Left/30m.png",IMREAD_COLOR);
    Mat right1 = imread("/home/hamza/wheel_spd/S2/Right/30m.png",IMREAD_COLOR);


    //Create a window
    namedWindow("My Window", 1);

    //set the callback function for any mouse event
    Point p;
    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", left);

    // Wait until user press some key


    waitKey(0);
    xl=p.x;
    yl=p.y;
//    cout<<"xl is "<<xl<<endl;
//    cout<<"yl is "<<yl<<endl;




    //Create a window
    namedWindow("My Window", 1);
    //set the callback function for any mouse event
    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", right);
    // Wait until user press some key
    waitKey(0);

    xr=p.x;
    yr=p.y;
//    cout<<"xr is "<<xr<<endl;
//    cout<<"yr is "<<yr<<endl;





    //Create a window
    namedWindow("My Window", 1);
    //set the callback function for any mouse event
    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", left1);
    // Wait until user press some key
    waitKey(0);
    xl1=p.x;
    yl1=p.y;
//    cout<<"xl1 is "<<p.x<<endl;
//    cout<<"yl1 is "<<p.y<<endl;




    //Create a window
    namedWindow("My Window", 1);
    //set the callback function for any mouse event
    setMouseCallback("My Window", on_mouse, &p );
    //show the image
    imshow("My Window", right1);
    // Wait until user press some key
    waitKey(0);
    xr1=p.x;
    yr1=p.y;
//    cout<<"xr1 is "<<p.x<<endl;
//    cout<<"yr1 is "<<p.y<<endl;




    float f=1060,b=119.91;
    float z1,z2,x1,x2,y1,y2,dp1,dp2,dist_dep;


    dp1=abs(xl-xr);
//    cout<<"disparité 1:"<<dp1<<endl;

    z1=(f*b)/(dp1);
    x1=((xr)*z1)/f;
    y1=((yr)*z1)/f;

    dp2=abs(xl1-xr1);
//    cout<<"disparité 2 est:"<<dp2<<endl;

    z2=(f*b)/(dp2);
    x2=(xl1*z2)/f;
    y2=(yl1*z2)/f;


    dist_dep=sqrt(pow((y2-y1),2)+pow((x2-x1),2)+pow((z2-z1),2));
    cout<<"distance de déplacement:"<<dist_dep/1000<<"m"<<endl;


    return 0;
}

#endif





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
