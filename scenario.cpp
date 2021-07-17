#include "scenario.h"
#include "vehicle.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>


using namespace std;
using namespace cv;

#define Size 500


class Scenario{
    public :

        // ------ Attributes ------//
        int id = 42;
        VideoCapture cap1;
        VideoCapture cap2;
        Vehicle vehicles[Size];
        ofstream sFileExcel;


        // ------ Methods ------//
        Scenario(string pathVleft, string pathVright){ // Constructor
            // Input
            cap1(pathVleft); // VideoLeft
            cap2(pathVright); // VideoRight
            id = ++id;
            // Output

            string filename = "scenario";
            filename = filename << (string)id << ".xlsx";
            path = "C:/Input/Scenario43";
            sFileExcel(filename);
        }

        void playVideoLeft(){
            Mat img;
            while (true) {
                cap1.read(img);
                imshow("image", img);
                waitKey(20);
            }
        }
        void playVideoRight(){
            Mat img;
            while (true) {
                cap2.read(img);
                imshow("image", img);
                waitKey(20);
            }
        }


        string ReadFromFolder(){
            // Create a text string, which is used to output the text file
            string myText;

            // Read from the text file
            ifstream MyReadFile("filename.txt");

            // Use a while loop together with the getline() function to read the file line by line
            while (getline (MyReadFile, myText)) {
              // Output the text from the file
              cout << myText;
            }

            MyReadFile.close();
            return myText;
        }
        void WritetoExcel(){
            MyFile << "Files can be tricky, but it is fun enough!";
        }






        // ------ Constructor ------//


};
