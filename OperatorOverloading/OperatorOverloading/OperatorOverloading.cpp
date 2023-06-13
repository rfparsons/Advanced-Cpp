/*
* Name: Bobby Parsons
* Date: 10/22/21
* Email: rfparsons@dmacc.edu
*
* Description: Overrides operators for the Shape classes
*/

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Shape {
private:
public:
    virtual double area() {
        return 0;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double width, double height) : width(width), height(height) { }
    double area() {
        return (width * height);
    }

    Rectangle operator*(double mult) {
        Rectangle output(width * mult, height);
        return output;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) { }
    double area() {
        return 3.14 * radius * radius;
    }

    Circle operator*(double mult) {
        Circle output(radius * sqrt(mult)); // Intention is to multiply the area by the input, not the radius
        return output;
    }
};

double operator+(Shape& s1, Shape& s2) {
    return s1.area() + s2.area();
}

double operator+(double area, Shape& s) {
    return area + s.area();
}

double operator-(Shape& s1, Shape& s2) {
    return s1.area() - s2.area();
}

double operator-(double area, Shape& s) {
    return area - s.area();
}

int main() {
    Rectangle property(50, 100);
    Rectangle road(6, 100);
    Circle roundabout(9);

    // The example is of the available space on a property after various things are constructed on it.
    // This provides a grounded example of a use for the Shape classes as well as the overloaded operators.

    cout << "Initial size of property: " << property.area() << endl;
    property = property * 2; // buy adjacent property
    cout << "Size of property after acquiring adjecent property: " << property.area() << endl;
    cout << "After a road is built through it: " << property - road << endl;
    cout << "After a roundabout is built on the road: " << property - road - roundabout << endl;
    roundabout = roundabout * 1.5;
    cout << "After the roundabout is expanded: " << property - road - roundabout << endl;

    return 0;
}

/*
* A real life example of how I would use this would be if I had some sort of 
* data structure, I would overload the addition operator so that it would
* combine elements in two structures of the same type.
*/