#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

class Point {
public:
    double x, y, z;

    Point() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Point(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Vector {
private:
    double x, y, z, length;
    void update_length() {
        this->length = sqrt(x * x + y * y + z * z);
    }

public:
    Vector operator*(double k) {
        Vector ans(this->x * k, this->y * k, this->z * k);
        return ans;
    }

    Vector() {
        this->x = 0;
        this->y = 0;
        this->z = 0;
        this->length = 0;
    }

    Vector(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        update_length();
    }

    Vector(const Point Head_point, const Point Tail_point) {
        this->x = Tail_point.x - Head_point.x;
        this->y = Tail_point.y - Head_point.y;
        this->z = Tail_point.z - Head_point.z;
        update_length();
    }

    void set_component(double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
        update_length();
    }

    void setX(double x) {
        this->x = x;
        update_length();
    }
    void setY(double y) {
        this->y = y;
        update_length();
    }
    void setZ(double z) {
        this->z = z;
        update_length();
    }

    double getX() {
        return x;
    }
    double getY() {
        return y;
    }
    double getZ() {
        return z;
    }
    double get_length() {
        return length;
    }

    void construct_vector(const Point Head_point, const Point Tail_point) {
        this->x = Tail_point.x - Head_point.x;
        this->y = Tail_point.y - Head_point.y;
        this->z = Tail_point.z - Head_point.z;
        update_length();
    }

    void construct_vector(double length, double angle1, double angel2) {
        // Angle in radian
        // Using 3D polar coordinates
        // Implement later
    }

    void show() {
        std::cout << "[" << x << ", " << y << ", " << z << "]"
                  << "\n";
    }
};

double dot_product(Vector v1, Vector v2) {
    return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ());
}

Vector cross_product(Vector v1, Vector v2) {
    Vector ans;

    ans.setX(v1.getY() * v2.getZ() - v1.getZ() * v2.getY());
    ans.setY(v1.getZ() * v2.getX() - v1.getX() * v2.getZ());
    ans.setZ(v1.getX() * v2.getY() - v1.getY() * v2.getX());

    return ans;
}

double angle_between(Vector v1, Vector v2) {
    double _dot_prod = dot_product(v1, v2);
    double _length_prod = v1.get_length() * v2.get_length();

    return acos(_dot_prod / _length_prod);
}

double convert_to_degree(double radian) {
    return radian * 180 / M_PI;
}

double convert_to_radian(double degree) {
    return degree * M_PI / 180;
}

double get_distance(const Point A, const Point B) {
    return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2) + pow(A.z - B.z, 2));
}
