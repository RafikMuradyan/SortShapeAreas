#ifndef AREA_HPP
#define AREA_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <exception>

class Point
{
private:
    double x_coord;
    double y_coord;
    double calculate_area();

public:
    void setPoint(const double&, const double&);
    std::string to_string();
};

class Circle
{
private:    
    double x_coord;
    double y_coord;
    double radius;
    double calculate_area();

public:
    void setCircle(const double&, const double&,const double&);
    std::string to_string();
};

class Rectangle
{
private:    
    double left_x_coord;
    double top_y_coord;
    double right_x_coord;
    double buttom_y_coord;
    double calculate_area();

public:
    void setRectangle(const double&, const double&,const double&, const double&);    
    std::string to_string();
};

class Triangle
{
private:
    double x1_coord;
    double y1_coord;
    double x2_coord;
    double y2_coord;
    double x3_coord;
    double y3_coord;
    double calculate_area();

public:
    void setTriangle(const double&, const double&,const double&, const double&,const double&, const double&);
    std::string to_string();
};

void get_area_and_insert(const Point&, std::string&);
void get_area_and_insert(const Circle&, std::string&);
void get_area_and_insert(const Rectangle&, std::string&);
void get_area_and_insert(const Triangle&, std::string&);
void get_arguments (std::vector<std::string>&, const std::string&);
void is_arguments_valid(std::vector<std::string>&); 
std::string sort_shape_areas(const std::string&);
void accuracy_check(const std::string&);
double get_area(const std::string&);

#endif