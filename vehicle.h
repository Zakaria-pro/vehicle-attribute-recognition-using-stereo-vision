#ifndef VEHICLE_H
#define VEHICLE_H


using namespace std;
using namespace cv;

class Vehicle {
    public:
        /* --------------------- Attributs -------------------------*/
        Mat imgLeft;
        Mat imgRight;

        Points points; // 12 points (4 points for each dimension) // 24 cordonnées

        Dimension dim; // 3 dimension (width, height, length)

        Info CurrentInfo; // Made by me (hadi mercedes benz class C)

        Info predictedInfo; // Made by the machine (tal model 9al 3la anaha mercedes benz class C )


        /* --------------------- Methods -------------------------*/
        Vehicle(string pathImg1, string pathImg2);

        // 12 points
        void TakePointsHeight();
        void TakePointsWidth();
        void TakePointsLength();

        // 3 dimension
        float calculateHeight();
        float calculateWidth();
        float calculateLength();


        // by me (ta9afa 3ama)
        void setCurrentInfo(string type, string make, string model);

        //
        void addVehicleToSheet();
};


#endif // VEHICLE_H
