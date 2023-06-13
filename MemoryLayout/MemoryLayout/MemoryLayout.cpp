#include <iostream>

using namespace std;



double length = 10;

double area;



double feetToCm(double feet) {
    // << HERE >>

    return feet * 30.48;

}



double areaInCm(double lengthInFeet) {

    double lengthInCm = feetToCm(lengthInFeet);

    return lengthInCm * lengthInCm;

}



int main() {

    area = areaInCm(length);

    cout << area << endl;



    return 0;

}