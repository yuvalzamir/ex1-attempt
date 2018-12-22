//
// Created by Yuval on 12/9/2018.
//

#ifndef EX1_VECTOR3D_H
#define EX1_VECTOR3D_H
#include <iostream>

/**
 *class which represent a 3D vector
 */
class Vector3D
{
private:
    double _x;
    double _y;
    double _z;

public:

    //Constructors
    /**
     * Constructor of 3 doubles
     * input: 3 doubles matching 3 sizes of vector
     */
    Vector3D(double a, double b, double c): _x(a), _y(b), _z(c){}
    /**
     * Default constructor - intializes the 0 vector
     */
    Vector3D(): Vector3D(0.0, 0.0, 0.0){}
    /**
     * Consturctors which recives an array of 3 doubles - intialized the same as the first constructor
     * @param input array of 3 doubles
     */
    Vector3D(double* input): Vector3D(input[0], input[1], input[2]){}
    /**
     * Copy constructor
     * @param other the Vector to copy
     */
    Vector3D(const Vector3D& other): _x(other._x), _y(other._y), _z(other._z){}

    //Operators
    /**
     * Plus operator
     * @param other vector to add
     * @return result of addition
     */
    Vector3D operator+(const Vector3D& other);

    /**
     * Minus operator
     * @param other vector to subtruct
     * @return result of subtraction
     */
    Vector3D operator-(const Vector3D& other);

    /**
     * += operator
     * @param other vector to add
     * @return the vector itself after the addition of the other vector
     */
    Vector3D&operator+=(const Vector3D& other);

    /**
     * -= operator
     * @param other vector to subtract
     * @return the vector itself after the subtraction
     */
    Vector3D&operator-=(const Vector3D& other);

    /**
     * *= operator
     * @param other vector to multiply
     * @return vector itself after multipication
     */
    Vector3D&operator*=(const Vector3D& other);

    /**
     * self minus operator
     * @return the vector itself - multiplied by -1
     */
    Vector3D operator-();

    /**
     * mulcipication operator with a double
     * @param other double to multiply the vector with
     * @return the product of the two
     */
    Vector3D operator*(const double other);

    /**
     * scalar multipication of the current vector and the other one
     * @param other vector to multiply by
     * @return product
     */
    Vector3D operator*(const Vector3D& other);

    /**
     * division by scalar
     * @param other scalar to be divided y
     * @return the vector after the division
     */
    Vector3D operator/(const double other);

    /**
     * *= operator with a scalar
     * @param other scalar ot by multiplied by
     * @return vector itself being the product of the two
     */
    Vector3D&operator*=(const double other);

    /**
     * /= operator with a scalar
     * @param other scalar to by devided by
     * @return the vector itself after the division
     */
    Vector3D&operator/=(const double other);

    /**
     * Distance between two vectors
     * @param other vector to measure the distance from
     * @return distance as a double
     */
    double operator|(const Vector3D& other);

    /**
     * Angle between to vectors
     * @param other vector to measure the angle from
     * @return result in radians
     */
    double operator^(const Vector3D& other);

    /**
     * Access the i'th location in the vector (from 0 to 2)
     * @param i index to be accessed (0-2)
     * @return refrence to the vector there.
     */
    double& operator[](const double i);

    double operator[](const double i) const;

    //note that there is no need to implement the = operator for it works just fine as the default cpyconst


    //Methods
    /**
     * Length of the vector
     * @return the length
     */
    double norm() const;

    /**
     * the distance of the vector from another vector
     * @param other vector to measure distance from
     * @return the distance as a scalar
     */
    double dist(const Vector3D& other);

    /**
     * sum the elements of this vector
     * @return th result
     */
    double sumVector();

    //Friends

    /**
     * product operator with a scalar from the left
     * @param input scalar as a double
     * @param vector vector to be multiplied
     * @return result of the multipication
     */
    friend Vector3D operator*(const double input, const Vector3D& vector);

    /**
     * << operator
     * @param stream  stream the vector should be inserted to
     * @param other vector to be printed
     * @return the stream
     */
    friend std::ostream&operator<<(std::ostream& stream, const Vector3D& other);

    /**
     * reading operator
     * @param is input stream
     * @param vec vector to read into
     * @return the stream
     */
    friend std::istream& operator>>(std::istream& is, Vector3D& vec);
};

#endif //EX1_VECTOR3D_H
