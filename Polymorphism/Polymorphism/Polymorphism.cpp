/*
* Name: Bobby Parsons
* Date: 10/8/21
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
    virtual int getSides() = 0;
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
    int getSides() {
        return 4;
    }
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string lineColor, string fillColor, double radius) :
        Shape(lineColor, fillColor), radius(radius) { }
    double area() {
        return 3.14 * radius * radius;
    }
    int getSides() {
        return -1;
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
    int getSides() {
        return 12; // not sure if this should represent edges or faces
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
    int getSides() {
        return 3;
    }
};

class Trapezoid : public Shape {
private:
    double height, length1, length2;
public:
    Trapezoid(string lineColor, string fillColor, double height, double length1, double length2) :
        Shape(lineColor, fillColor), height(height), length1(length1), length2(length2) { }
    double area() {
        return ((length1 + length2) / 2) * height;
    }
    int getSides() {
        return 4;
    }
};

int main() {
    vector<unique_ptr<Shape>> toyBox;
    toyBox.push_back(make_unique<Rectangle>("black", "black", 10, 10));
    toyBox.push_back(make_unique<Circle>("black", "blue", 5));
    toyBox.push_back(make_unique<Triangle>("black", "red", 10, 10));
    toyBox.push_back(make_unique<Box>("black", "yellow", 10, 10, 5));
    toyBox.push_back(make_unique<Trapezoid>("black", "green", 10, 7, 5));
    // for compilers that don't support make_unique like xCode
           // toyBox.push_back((unique_ptr<Shape>) new Rectangle("a","b",10, 10));
           // toyBox.push_back((unique_ptr<Shape>) new Circle("a","b",5));

    for (auto& shape : toyBox) {
        if (shape->getSides() == -1) { // -1 indicates a round shape, such as a circle or oval
            cout << shape->getFillColor() << " round shape with an area of " << shape->area() << endl;
        }
        else {
            cout << shape->getFillColor() << " " << shape->getSides() << "-sided shape with an area of " << shape->area() << endl;
        }
    }
    return 0;
}
