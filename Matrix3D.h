//
// Created by Yuval on 12/9/2018.
//

#ifndef EX1_MATRIX3D_H
#define EX1_MATRIX3D_H
#define SIZE 3

#include <iostream>
#include "Vector3D.h"

/**
 * class which represents a 3X3 Matrix
 */
class Matrix3D
{
private:
    Vector3D vec_array[SIZE];

public:
    //Constructors

    /**
     * Constructor which recieves 9 doubles as input
     * @param a
     * @param b
     * @param c
     * @param d
     * @param e
     * @param f
     * @param g
     * @param h
     * @param i
     */
    Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i);

    /**
     * Constructor which recives 2D array of doubles a input
     * @param input 2D array of doubles
     */
    Matrix3D(double input[][3]);

    /**
     * Constructor of a eye matrix multiplied by a scalar
     * @param a scalar which multiplies the matrix
     */
    Matrix3D(double a);

    /**
     * Default constructor to 0 matrix
     */
    Matrix3D();

    /**
     * Constructor which recives an array of 9 doubles
     * @param input the array of 9 doubles
     */
    Matrix3D(double input[9]);

    /**
     * Constructor which recives 3 vectors (3 lines of matrix)
     * @param vec1
     * @param vec2
     * @param vec3
     */
    Matrix3D(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3);

    /**
     * copy constructor
     * @param mat matrix to by copied
     */
    Matrix3D(const Matrix3D& mat): Matrix3D(mat.vec_array[0], mat.vec_array[1], mat.vec_array[2]){}


    //Operators - in each of this operators the "other" parameter is either another matrix or a scalar - depending on
    // the operator. It is easy to understand from context. If not, it is clearly stated.

    /**
     * + operator
     * @param other
     * @return addition result
     */
    Matrix3D operator+(const Matrix3D& other);

    /**
     * scalar multipication with a matrix
     * @param other matrix to multiply with
     * @return
     */
    Matrix3D operator*(const Matrix3D& other);

    /**
     * Matrix and vector multipication
     * @param other vector to be multiplied from the right of the matrix (Mat*Vec)
     * @return product (Vector)
     */
    Vector3D operator*(const Vector3D& other);

    /**
     * subtraction operator
     * @param other
     * @return result
     */
    Matrix3D operator-(const Matrix3D& other);

    /**
     * += operator
     * @param other
     * @return result
     */
    Matrix3D&operator+=(const Matrix3D& other);

    /**
     * -= operator
     * @param other
     * @return result
     */
    Matrix3D&operator-=(const Matrix3D& other);

    /**
     * *= operator
     * @param other
     * @return result
     */
    Matrix3D&operator*=(const Matrix3D& other);

    /**
     * *= operator with a scalar
     * @param other scalar to be multiplied by
     * @return vector itself after operation
     */
    Matrix3D&operator*=(const double other);

    /**
     * /= operator with a scalar
     * @param other scalar to by divided by
     * @return vector itself
     */
    Matrix3D&operator/=(const double other);

    /**
     * [] access operator to a vector in the matrix
     * @param index scalar which represents the index (0-2)
     * @return a refrence to the vector
     */
    Vector3D&operator[](int index);
    const Vector3D operator[](int index) const;


        /**
         * = operator
         * @param other
         * @return a copy of the other matrix
         */
    Matrix3D&operator=(Matrix3D& other);

    //Methods

    /**
     * get a row in the matrix as a vector
     * @param i index of the row (0-2)
     * @return row as a vector (not a refrence)
     */
    Vector3D row(short i) { return Vector3D(vec_array[i]); }

    /**
     * get a column in the matrix as a vector
     * @param i index of the row (0-2)
     * @return coulmn as a vector (not a refrence)
     */
    Vector3D column(short i){ return Vector3D(vec_array[0][i], vec_array[1][i], vec_array[2][i]); }

    /**
     * get the trace of the matrix
     * @return trace as a scalar
     */
    double trace(){ return (vec_array[0][0] + vec_array[1][1] + vec_array[2][2]); }

    /**
     * Determinant of the matrix
     * @return result
     */
    double determinant();

    /**
     * << operator
     * @param stream stream to send the mat to
     * @param other the matrix to be sent
     * @return the stream
     */
    friend std::ostream&operator<<(std::ostream& stream, const Matrix3D& other);

    /**
     * >> operator
     * @param is input stream
     * @param vec vector3d
     * @return the stream
     */
    friend std::istream& operator>>(std::istream& is, Matrix3D& mat);


};

#endif //EX1_MATRIX3D_H


