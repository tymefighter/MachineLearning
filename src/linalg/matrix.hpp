#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>

using namespace std;

const double EPS = 1e-7;

inline double fabs(double x) {return (x < 0 ? -x : x);}

inline bool isZero(double x) {return fabs(x) < EPS;}

/** Matrix Error */

class MatError {
    private:
    
    string msg;
    
    public:

    MatError(const string &msg_);

    ~MatError();

    inline string getMsg() {return msg;}
};


/** Matrix Shape */

struct Shape {
    int n, m;

    Shape(int n_, int m_);

    Shape(const Shape &shape);

    ~Shape();

    const Shape& operator= (const Shape &shape);

    inline bool operator== (const Shape &shape) {
        return n == shape.n && m == shape.m;
    }

    inline bool operator!= (const Shape &shape) {
        return n != shape.n || m != shape.m;
    }
};

/** Matrix */

class Matrix {

    private:

    int n, m;
    double **a;

    public:

    Matrix();

    Matrix(int n_, int m_);

    Matrix(const Shape &shape);

    Matrix(double **mat, int n_, int m_);

    Matrix(const vector<vector<double> > &mat);

    Matrix(const Matrix &mat);

    ~Matrix();

    inline int getNumRows() const {return n;}

    inline int getNumCols() const {return m;}

    inline Shape getShape() const {return Shape(n, m);}

    bool operator== (const Matrix &mat);

    const Matrix& operator= (const Matrix &mat);

    double& operator() (int i, int j);

    const double& operator() (int i, int j) const;

    Matrix operator+ (const Matrix &mat) const;

    Matrix operator- (const Matrix &mat) const;
    
    static Matrix identity(int n);

    static Matrix ones(int n, int m);

    static Matrix zeros(int n, int m);
};

ostream& operator<< (ostream& os, const Matrix &mat);

#endif
