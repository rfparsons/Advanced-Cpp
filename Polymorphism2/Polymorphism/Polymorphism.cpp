/*
* Name: Bobby Parsons
* Date: 10/11/21
* Email: rfparsons@dmacc.edu
*
* Description: Uses derived classes to represent different shapes
*/
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Drawing {
private:
    string lineColor;
    string fillColor;
public:
    Drawing(string lineColor, string fillColor) : lineColor(lineColor), fillColor(fillColor) { }
    void setLineColor(string lineColor) { this->lineColor = lineColor; }
    void setFillColor(string fillColor) { this->fillColor = fillColor; }
    string getLineColor() { return lineColor; }
    string getFillColor() { return fillColor; }
    
};

class Shape {
public:
    virtual double area() = 0;
    virtual string shapeName() = 0;
};

class Polygon : public Shape {
public:
    virtual int getSides() = 0;
};

class Polyhedron : public Shape {
public:
    virtual int getFaces() = 0;
    virtual int getEdges() = 0;
    virtual double volume() = 0;
    // area() now refers to surface area
};

class Rectangle : public Drawing, public Polygon {
private:
    double width, height;
public:
    Rectangle(string lineColor, string fillColor, double width, double height) :
        Drawing(lineColor, fillColor), width(width), height(height) { }
    double area() {
        return (width * height);
    }
    int getSides() {
        return 4;
    }
    string shapeName() {
        return "Rectangle";
    }
};

class Circle : public Drawing, public Shape {
private:
    double radius;
public:
    Circle(string lineColor, string fillColor, double radius) :
        Drawing(lineColor, fillColor), radius(radius) { }
    double area() {
        return 3.14 * radius * radius;
    }
    int getSides() {
        return -1;
    }
    string shapeName() {
        return "Circle";
    }
};

class Box : public Drawing, public Polyhedron {
private:
    double width, height, depth;
public:
    Box(string lineColor, string fillColor, double width, double height, double depth) :
        Drawing(lineColor, fillColor), width(width), height(height), depth(depth) { }
    double volume() { 
        return (width * height * depth);
    }
    double area() {
        return 2 * (width * height + height * depth + width * depth);
    }
    int getEdges() {
        return 12; 
    }
    int getFaces()
    {
        return 6;
    }
    string shapeName() {
        return "Box";
    }
};

class Triangle : public Drawing, public Polygon {
private:
    double width, height;
public:
    Triangle(string lineColor, string fillColor, double width, double height) :
        Drawing(lineColor, fillColor), width(width), height(height) { }
    double area() {
        return (width * height) / 2;
    }
    int getSides() {
        return 3;
    }
    string shapeName() {
        return "Triangle";
    }
};

class Trapezoid : public Drawing, public Polygon {
private:
    double height, length1, length2;
public:
    Trapezoid(string lineColor, string fillColor, double height, double length1, double length2) :
        Drawing(lineColor, fillColor), height(height), length1(length1), length2(length2) { }
    double area() {
        return ((length1 + length2) / 2) * height;
    }
    int getSides() {
        return 4;
    }
    string shapeName() {
        return "Trapezoid";
    }
};

int main() {
    // unique_ptr was giving me a bit of trouble trying to get all objects into two differently-typed arrays, so now they're regular pointers
    vector<Drawing*> toyBox;
    vector<Shape*> toyBox2;

    Rectangle* rectangle = new Rectangle("black", "black", 10, 10);
    Circle* circle = new Circle("black", "blue", 5);
    Triangle* triangle = new Triangle("black", "red", 10, 10);
    Box* box = new Box("black", "yellow", 10, 10, 5);
    Trapezoid* trapezoid = new Trapezoid("black", "green", 10, 7, 5);
    Polyhedron* poly3d;

    toyBox.push_back(rectangle);
    toyBox.push_back(circle);
    toyBox.push_back(triangle);
    toyBox.push_back(box);
    toyBox.push_back(trapezoid);

    toyBox2.push_back(rectangle);
    toyBox2.push_back(circle);
    toyBox2.push_back(triangle);
    toyBox2.push_back(box);
    toyBox2.push_back(trapezoid);

    // no iterator, again to make using different types smoother
    for (int i = 0; i < toyBox.size(); i++) {
        cout << toyBox[i]->getFillColor() << " ";
        cout << toyBox2[i]->shapeName() << " with an area of " << toyBox2[i]->area() << endl;
    }

    poly3d = box; //assign box to the Polyhedron pointer

    cout << "The " << poly3d->shapeName() << " has a volume of " << poly3d->volume() << " and " << poly3d->getFaces() << " faces.";

    // Clean up my pointers manually (since i'm no longer using smart pointers)
    delete rectangle;
    delete circle;
    delete triangle;
    delete box;
    delete trapezoid;

    return 0;
}

/*
* Polymorphism would be useful to implement any time you have classes with different sets of
* overlapping attributes. By consolodating them into multiple sub-classes, you can reduce the
* amount of time spent rewriting the same code, and not have to worry about updating it in 
* multiple different places when it needs to change. Implementing multiple different classes
* could also be useful to "bridge" them together and combine their functionality, or create
* compatibility between the two.
*/

/*
black Rectangle with an area of 100
blue Circle with an area of 78.5
red Triangle with an area of 50
yellow Box with an area of 400
green Trapezoid with an area of 60
The Box has a volume of 500 and 6 faces.
*/