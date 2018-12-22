//
// Created by Yuval on 12/9/2018.
//

#include "Matrix3D.h"

/**
 * cpp file implementing the Matrix3D calss
 */

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
Matrix3D::Matrix3D(double a, double b, double c, double d, double e, double f, double g, double h, double i)
{
    vec_array[0] = Vector3D(a, b, c);
    vec_array[1] = Vector3D(d, e, f);
    vec_array[2] = Vector3D(g, h, i);
}

/**
 * Constructor which recives 2D array of doubles a input
 * @param input 2D array of doubles
 */
Matrix3D::Matrix3D(double input[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        *(vec_array + i) = Vector3D(*input);
        input++;
    }
}


/**
 * Default constructor to 0 matrix
 */
Matrix3D::Matrix3D(): Matrix3D(0.0){}


/**
 * Constructor of a eye matrix multiplied by a scalar
 * @param a scalar which multiplies the matrix
 */
Matrix3D::Matrix3D(double a)
{
    vec_array[0] = Vector3D(a, 0.0, 0.0);
    vec_array[1] = Vector3D(0.0, a, 0.0);
    vec_array[2] = Vector3D(0.0, 0.0, a);
}

/**
 * Constructor which recives an array of 9 doubles
 * @param input the array of 9 doubles
 */
Matrix3D::Matrix3D(double input[9])
{
    for (int i = 0; i < SIZE; i++)
    {
        *(vec_array + i) = Vector3D(*input, *(input + 1), *(input + 2));
        input += SIZE;
    }
}


/**
 * Constructor which recives 3 vectors (3 lines of matrix)
 * @param vec1
 * @param vec2
 * @param vec3
 */
Matrix3D::Matrix3D(const Vector3D& vec1, const Vector3D& vec2, const Vector3D& vec3)
{
    vec_array[0] = Vector3D(vec1);
    vec_array[1] = Vector3D(vec2);
    vec_array[2] = Vector3D(vec3);
}

/**
 * + operator
 * @param other
 * @return addition result
 */
Matrix3D Matrix3D::operator+(const Matrix3D& other)
{
    return Matrix3D(vec_array[0] + other.vec_array[0], vec_array[1] + other.vec_array[1],
            vec_array[2] + other.vec_array[2]);
}

/**
 * subtraction operator
 * @param other
 * @return result
 */
Matrix3D Matrix3D::operator-(const Matrix3D& other)
{
    return Matrix3D(vec_array[0] - other.vec_array[0], vec_array[1] - other.vec_array[1],
            vec_array[2] - other.vec_array[2]);
}

/**
 * scalar multipication with a matrix
 * @param other matrix to multiply with
 * @return
 */
Matrix3D Matrix3D::operator*(const Matrix3D& other)
{
    return Matrix3D(vec_array[0] * other.vec_array[0], vec_array[1] * other.vec_array[1],
            vec_array[2] * other.vec_array[2]);
}

/**
 * += operator
 * @param other
 * @return result
 */
Matrix3D& Matrix3D::operator+=(const Matrix3D& other)
{
    for (int i = 0; i<SIZE; i++)
    {
        vec_array[i] += other.vec_array[i];
    }
    return *this;
}

/**
 * *= operator
 * @param other
 * @return result
 */
Matrix3D& Matrix3D::operator*=(const Matrix3D& other)
{
    for (int i = 0; i<SIZE; i++)
    {
        vec_array[i] *= other.vec_array[i];
    }
    return *this;
}

/**
 * *= operator with a scalar
 * @param other scalar to be multiplied by
 * @return vector itself after operation
 */
Matrix3D& Matrix3D::operator*=(const double other)
{
    for (int i = 0; i<SIZE; i++)
    {
        vec_array[i] *= other;
    }
    return *this;
}

/**
 * /= operator with a scalar
 * @param other scalar to by divided by
 * @return vector itself
 */
Matrix3D& Matrix3D::operator/=(const double other)
{
    double temp = 1 / other;
    return (*this) *= temp;
}

/**
 * -= operator
 * @param other
 * @return result
 */
Matrix3D& Matrix3D::operator-=(const Matrix3D& other)
{
    Matrix3D temp = Matrix3D();
    *this += (temp - other);
    return *this;
}

/**
 * << operator
 * @param stream stream to send the mat to
 * @param other the matrix to be sent
 * @return the stream
 */
std::ostream& operator<<(std::ostream& stream, const Matrix3D& other)
{
    stream << *(other.vec_array) << std::endl;
    stream << *(other.vec_array + 1) << std::endl;
    stream << *(other.vec_array + 2);

    return stream;
}

/**
 * >> operator
 * @param is input stream
 * @param vec vector3d
 * @return the stream
 */
std::istream& operator>>(std::istream& is, Matrix3D& mat)
{
    is >> mat.vec_array[0];
    is >> mat.vec_array[1];
    is >> mat.vec_array[2];
    return is;
}


/**
 * Matrix and vector multipication
 * @param other vector to be multiplied from the right of the matrix (Mat*Vec)
 * @return product (Vector)
 */
Vector3D Matrix3D::operator*(const Vector3D& other)
{
    double temp[] = {0, 0, 0};
    for (int i = 0; i < SIZE; ++i)
    {
        temp[i] = (vec_array[i] * other).sumVector();
    }
    return Vector3D(temp);
}

/**
 * [] access operator to a vector in the matrix
 * @param index scalar which represents the index (0-2)
 * @return a refrence to the vector
 */
Vector3D& Matrix3D::operator[](int index)
{
    return vec_array[index];
}

const Vector3D Matrix3D::operator[](int index) const
{
    Vector3D const temp = vec_array[index];
    return temp;
}

/**
 * = operator
 * @param other
 * @return a copy of the other matrix
 */
Matrix3D& Matrix3D::operator=(Matrix3D& other)
{
    for (int i = 0; i < SIZE; ++i)
    {
        vec_array[i] = Vector3D(other.vec_array[i]);
    }
    return *this;
}

/**
 * Determinante of the matrix
 * @return result
 */
double Matrix3D::determinant()
{
    double result = 0;
    for (int i = 0; i < SIZE; ++i)
    {
        result += (vec_array[0][i] * (vec_array[1][(i + 1) % 3] * vec_array[2][(i + 2) % 3] -
                vec_array[2][(i + 1) % 3] * vec_array[1][(i + 2) % 3]));
    }
    return result;
}
