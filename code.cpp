#include "area.hpp"

std::vector<std::string> p_values;
std::vector<std::string> c_values;
std::vector<std::string> r_values;
std::vector<std::string> t_values;

std::vector<Point> points;
std::vector<Circle> circles;
std::vector<Rectangle> rectangles;
std::vector<Triangle> triangles;

void accuracy_check(const std::string& input)
{
    int i = 0;
    char key{};
    std::string line{};
    Point p_obj;
    Circle c_obj;
    Rectangle r_obj;
    Triangle t_obj;
    uint p_arg_count = 2;
    uint c_arg_count = 3;
    uint r_arg_count = 4;
    uint t_arg_count = 6;
    

    while (i != input.size())
    {    
        while (input[i] != '\n')
        {
            line.push_back(input[i]);
            ++i;
        }

        key = line[0];
        if (key == 'P')
        {    
            get_arguments(p_values,line);
            if (p_arg_count != p_values.size())
            {
                std::cout << "Wrong number of parameters for shape identifier shape-identifier" << std::endl;
                exit(0);
            }
            is_arguments_valid(p_values);
            const double x = stod(p_values[p_arg_count - 2]);
            const double y = stod(p_values[p_arg_count - 1]);
            p_obj.setPoint(x,y);
            points.push_back(p_obj);
            p_arg_count += 2;
        }

        else if (key == 'C')
        {
            get_arguments(c_values,line);   
            if (c_arg_count != c_values.size())
            {
                std::cout << "Wrong number of parameters for shape identifier shape-identifier" << std::endl;
                exit(0);
            } 
            is_arguments_valid(c_values);
            const double x = stod(c_values[c_arg_count - 3]);
            const double y = stod(c_values[c_arg_count - 2]);
            const double radius = stod(c_values[c_arg_count - 1]);
            c_obj.setCircle(x,y,radius);
            circles.push_back(c_obj);
            c_arg_count += 3;
        }

        else if (key == 'R')
        {          
            get_arguments(r_values,line); 
            if (r_arg_count != r_values.size())
            {
                std::cout << "Wrong number of parameters for shape identifier shape-identifier" << std::endl;
                exit(0);
            }  
            is_arguments_valid(r_values);
            const double left = stod(r_values[r_arg_count - 4]);
            const double top = stod(r_values[r_arg_count - 3]);
            const double right = stod(r_values[r_arg_count - 2]);
            const double buttom = stod(r_values[r_arg_count - 1]);
            r_obj.setRectangle(left,top,right,buttom);
            rectangles.push_back(r_obj);
            r_arg_count += 4;
        }

        else if (key == 'T')
        {
            get_arguments(t_values,line);
            if (t_arg_count != t_values.size())
            {
                std::cout << "Wrong number of parameters for shape identifier shape-identifier" << std::endl;
                exit(0);
            }
            is_arguments_valid(t_values);
            const double x1 = stod(t_values[t_arg_count - 6]);
            const double y1 = stod(t_values[t_arg_count - 5]);
            const double x2 = stod(t_values[t_arg_count - 4]);
            const double y2 = stod(t_values[t_arg_count - 3]);
            const double x3 = stod(t_values[t_arg_count - 2]);
            const double y3 = stod(t_values[t_arg_count - 1]);
            t_obj.setTriangle(x1,y1,x2,y2,x3,y3);
            triangles.push_back(t_obj);
            t_arg_count += 6;
        }

        else
        {
            std::cout << "There was found unrecognized shape identifier" << std::endl;
            exit(0);
        } 
        ++i;
        line.clear();
    }   
}

void get_arguments (std::vector<std::string>& observed, const std::string& line)
{
    bool test = false;
    std::string value;
    for (size_t i = 1; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            continue;
        }
        if (line[i] == '<')
        {
            test = true;
            continue;
        }
        else if (line[i] == '>')
        {
            test = false;
            observed.push_back(value);
            value = "";
        } 

        if (test)
        {
            value.push_back(line[i]);
        }  
    }
}

void is_arguments_valid(std::vector<std::string>& observed)
{
    std::string value{};
    for (size_t i = 0; i < observed.size(); i++)
    {
        value = observed[i];
        try
        {
            stod(value);
        }
        catch(std::invalid_argument)
        {
            std::cout << "Non-numeric parameter value value" << std::endl;
            exit(0);
        }    
    }    
}

void Point::setPoint(const double& x,const double& y)
{
    this->x_coord = x;
    this->y_coord = y;
}

void Circle::setCircle(const double& x,const double& y,const double& radius)
{
    this->x_coord = x;
    this->y_coord = y;
    this->radius = radius;
}

void Rectangle::setRectangle(const double& left_x, const double& top_y,const double& right_x, const double& buttom_y)
{
    this->left_x_coord = left_x;
    this->top_y_coord = top_y;
    this->right_x_coord = right_x;
    this->buttom_y_coord = buttom_y;
}

void Triangle::setTriangle(const double& x1,const double& y1,const double& x2,const double& y2,const double& x3,const double& y3)
{
    this->x1_coord = x1;
    this->y1_coord = y1;
    this->x2_coord = x2;
    this->y2_coord = y2;
    this->x3_coord = x3;
    this->y3_coord = y3;
}

double Point::calculate_area()
{
    return 0;
}

std::string Point::to_string()
{
    std::string result{};
    result += '<' + std::to_string(calculate_area()) + "> Point <";
    result += std::to_string(x_coord) + "> <" + std::to_string(y_coord) + ">\n";
    return result;
}

double Circle::calculate_area()
{
    double result{};
    const double pi = 3.141592;
    result = pi * pow(radius,2);
    return result;
}

std::string Circle::to_string()
{
    std::string result{};
    result += '<' + std::to_string(calculate_area()) + "> Circle <";
    result += std::to_string(x_coord) + "> <" + std::to_string(y_coord) + "> <";
    result += std::to_string(radius) + ">\n";
    return result;
}

double Rectangle::calculate_area()
{
    double side_a;
    double side_b;
    double result;
    side_a = right_x_coord - left_x_coord;
    side_b = top_y_coord = buttom_y_coord;
    result = side_a * side_b;
    return result;
}

std::string Rectangle::to_string()
{
    std::string result;
    result += '<' + std::to_string(calculate_area()) + "> Rectangle <";
    result += std::to_string(left_x_coord) + "> <" + std::to_string(top_y_coord) + "> <";
    result += std::to_string(right_x_coord) + "> <" + std::to_string(buttom_y_coord) + ">\n";
    return result;
}
double Triangle::calculate_area()
{
    double side_a;
    double side_b;
    double side_c;
    double s;
    double result;
    side_a = sqrt(pow(x2_coord - x1_coord,2) + pow(y2_coord - y1_coord,2));
    side_b = sqrt((pow(x3_coord - x2_coord,2)) + pow(y3_coord - y2_coord,2));
    side_c = sqrt(pow(x1_coord - x3_coord,2) + pow(y1_coord - y3_coord,2));
    s = (side_a + side_b + side_c) / 2;
    result = sqrt(s * (s - side_a) * (s - side_b) * (s - side_c));
    return result;
}

std::string Triangle::to_string()
{
    std::string result;
    result += '<' + std::to_string(calculate_area()) + "> Triangle <";
    result += std::to_string(x1_coord) + "> <" + std::to_string(y1_coord) + "> <";
    result += std::to_string(x2_coord) + "> <" + std::to_string(y2_coord) + "> <";
    result += std::to_string(x3_coord) + "> <" + std::to_string(y3_coord) +">\n";
    return result;
}

double get_area(const std::string& line)
{
    std::string area;
    for (size_t i = 1; i < line.size(); i++)
    {
        if (line[i] != '>') 
        {
            area.push_back(line[i]);
        }
        else
        {
            break;
        }    
    } 
    return stod(area); 
}

std::string sort_shape_areas(const std::string& input)
{
    accuracy_check(input);
    std::vector<std::string> all_lines{};
    std::vector<std::string> result{};
    
    for (size_t i = 0; i < points.size(); i++) {all_lines.push_back(points[i].to_string());}   
    for (size_t i = 0; i < circles.size(); i++) {all_lines.push_back(circles[i].to_string());}  
    for (size_t i = 0; i < rectangles.size(); i++) {all_lines.push_back(rectangles[i].to_string());}    
    for (size_t i = 0; i < triangles.size(); i++) {all_lines.push_back(triangles[i].to_string());}
    
    double lowest_area{};
    int index{};
    const int iteration = all_lines.size();
    for(size_t i = 0; i < iteration; ++i)
    {
        lowest_area = get_area(all_lines[0]);
        index = 0;
        for(size_t j = 0; j < all_lines.size(); ++j)
        { 
            if (get_area(all_lines[j]) < lowest_area)
            {   
                lowest_area = get_area(all_lines[j]);
                index = j;    
            }
            if (j == all_lines.size() - 1)
            {
                result.push_back(all_lines[index]);
                all_lines.erase(all_lines.begin() + index);
            }   
        }
    }

    std::string output{};
    for (size_t i = 0; i < result.size(); i++)
    {
        output += result[i];
    }

    return output;    
}