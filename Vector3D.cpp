//
// Created by Yuval on 12/9/2018.
//

#include "Vector3D.h"
#include <math.h>

/**
 * cpp file implementing the Vector3D class
 */

/**
 * << operator
 * @param stream  stream the vector should be inserted to
 * @param other vector to be printed
 * @return the stream
 */
std::ostream& operator<<(std::ostream& stream, const Vector3D& other)
{
    stream << other._x << " " << other._y << " " << other._z;
    return stream;
}

/**
 * reading operator
 * @param is input stream
 * @param vec vector to read into
 * @return the stream
 */
std::istream& operator>>(std::istream& is, Vector3D& vec)
{
    is >> vec._x;
    is >> vec._y;
    is >> vec._z;
    return is;
}

/**
 * product operator with a scalar from the left
 * @param input scalar as a double
 * @param vector vector to be multiplied
 * @return result of the multipication
 */
Vector3D operator*(const double input, const Vector3D& vector)
{
    return Vector3D((vector._x*input), (vector._y*input), (vector._z*input));
}

/**
 * Length of the vector
 * @return the length
 */
double Vector3D::norm() const
{
    return sqrt(pow(_x, 2) + pow(_y, 2) + pow(_z, 2));
}

/**
 * the distance of the vector from another vector
 * @param other vector to measure distance from
 * @return the distance as a scalar
 */
double Vector3D::dist(const Vector3D& other)
{
    return *this | other;
}

/**
 * Plus operator
 * @param other vector to add
 * @return result of addition
 */
Vector3D Vector3D::operator+(const Vector3D& other)
{
    return Vector3D((_x + other._x), (_y + other._y), (_z + other._z));
}

/**
 * Minus operator
 * @param other vector to subtruct
 * @return result of subtraction
 */
Vector3D Vector3D::operator-(const Vector3D& other)
{
    return Vector3D(_x - other._x, _y - other._y, _z - other._z);
}

/**
 * scalar multipication of the current vector and the other one
 * @param other vector to multiply by
 * @return product
 */
Vector3D Vector3D::operator*(const Vector3D& other)
{
    return Vector3D((_x * other._x), (_y * other._y), (_z * other._z));
}

/**
 * self minus operator
 * @return the vector itself - multiplied by -1
 */
Vector3D Vector3D::operator-()
{
    return *this * (-1);
}

/**
 * mulcipication operator with a double
 * @param other double to multiply the vector with
 * @return the product of the two
 */
Vector3D Vector3D::operator*(const double other)
{
    return Vector3D((_x * other), (_y * other), (_z * other));
}

/**
 * division by scalar
 * @param other scalar to be divided y
 * @return the vector after the division
 */
Vector3D Vector3D::operator/(const double other)
{
    return Vector3D((_x / other), (_y / other), (_z / other));
}

/**
 * += operator
 * @param other vector to add
 * @return the vector itself after the addition of the other vector
 */
Vector3D& Vector3D::operator+=(const Vector3D& other)
{
    this->_x += other._x;
    this->_y += other._y;
    this->_z += other._z;
    return *this;
}

/**
 * *= operator
 * @param other vector to multiply
 * @return vector itself after multipication
 */
Vector3D& Vector3D::operator*=(const Vector3D& other)
{
    this->_x *= other._x;
    this->_y *= other._y;
    this->_z *= other._z;
    return *this;
}

/**
 * -= operator
 * @param other vector to subtract
 * @return the vector itself after the subtraction
 */
Vector3D& Vector3D::operator-=(const Vector3D& other)
{
    this->_x -= other._x;
    this->_y -= other._y;
    this->_z -= other._z;
    return *this;
}

/**
 * *= operator with a scalar
 * @param other scalar ot by multiplied by
 * @return vector itself being the product of the two
 */
Vector3D& Vector3D::operator*=(const double other)
{
    this->_x *= other;
    this->_y *= other;
    this->_z *= other;
    return *this;
}

/**
 * /= operator with a scalar
 * @param other scalar to by devided by
 * @return the vector itself after the division
 */
Vector3D& Vector3D::operator/=(const double other)
{
    this->_x /= other;
    this->_y /= other;
    this->_z /= other;
    return *this;
}

double Vector3D::sumVector()
{
    return _x + _y + _z;
}

/**
 * Distance between two vectors
 * @param other vector to measure the distance from
 * @return distance as a double
 */
double Vector3D::operator|(const Vector3D& other)
{
    Vector3D temp = *this - other;
    return temp.norm();
}

/**
 * Angle between to vectors
 * @param other vector to measure the angle from
 * @return result in radians
 */
double Vector3D::operator^(const Vector3D& other)
{
    Vector3D temp = *this - other;
    double c =  temp.norm();
    double b = this->norm();
    double a = other.norm();
    return acos((pow(c, 2) - pow(b, 2) - pow(a, 2)) / (-2 * a * b));
}

/**
 * Access the i'th location in the vector (from 0 to 2)
 * @param i index to be accessed (0-2)
 * @return refrence to the vector there.
 */
double& Vector3D::operator[](const double i)
{
    if (i == 0.0){
        double& output = _x;
        return output;
    }
    if (i == 1.0){
        double& output = _y;
        return output;
    } else {
        double& output = _z;
        return output;
    }
}

/**
 * Access the i'th location in the vector (from 0 to 2)
 * @param i index to be accessed (0-2)
 * @return refrence to the vector there.
 */
double Vector3D::operator[](const double i) const
{
    if (i == 0.0)
    {
        double const output = _x;
        return output;
    }
    if (i == 1.0)
    {
        double const output = _y;
        return output;
    } else
    {
        double const output = _z;
        return output;
    }
}