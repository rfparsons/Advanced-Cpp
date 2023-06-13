/*
* Name: Bobby Parsons
* Date: 10/10/21
* Email: rfparsons@dmacc.edu
*
* Description: Uses derived classes to represent different shapes
*/
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Shape {
private:
    string lineColor;
    string fillColor;
public:
    virtual double area() {
        return 0;
    }
    Shape(string lineColor, string fillColor) : lineColor(lineColor), fillColor(fillColor) { }
    void setLineColor(string lineColor) { this->lineColor = lineColor; }
    void setFillColor(string fillColor) { this->fillColor = fillColor; }
    string getLineColor() { return lineColor; }
    string getFillColor() { return fillColor; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string lineColor, string fillColor, double width, double height) :
        Shape(lineColor, fillColor), width(width), height(height) { }
    double area() {
        return (width * height);
    }
};

class Box : public Shape {
private:
    double width, height, depth;
public:
    Box(string lineColor, string fillColor, double width, double height, double depth) :
        Shape(lineColor, fillColor), width(width), height(height), depth(depth) { }
    double area() { 
        return (width * height * depth);
    }
};

class Triangle : public Shape {
private:
    double width, height;
public:
    Triangle(string lineColor, string fillColor, double width, double height) :
        Shape(lineColor, fillColor), width(width), height(height) { }
    double area() {
        return (width * height) / 2;
    }
};

int main() {
    vector<unique_ptr<Shape>> toyBox;
    toyBox.push_back(make_unique<Rectangle>("black", "black", 10, 10));
    toyBox.push_back(make_unique<Triangle>("black", "red", 10, 10));
    toyBox.push_back(make_unique<Box>("black", "yellow", 10, 10, 5));
    // for compilers that don't support make_unique like xCode
           // toyBox.push_back((unique_ptr<Shape>) new Rectangle("a","b",10, 10));
           // toyBox.push_back((unique_ptr<Shape>) new Circle("a","b",5));

    for (auto& shape : toyBox) {
        cout << shape->getFillColor() << " shape with an area of " << shape->area() << endl;
    }
    return 0;
}
