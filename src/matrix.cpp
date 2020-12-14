#include <vector>
#include <matrix.hpp>

using namespace std;

/** Matrix Error */

MatError::MatError(const string &msg_):
    msg(msg_) {}

MatError::~MatError() {}

/** Matrix Shape */

Shape::Shape(int n_, int m_):
    n(n_), m(m_) {}

Shape::Shape(const Shape &shape):
    n(shape.n), m(shape.m) {}

Shape::~Shape() {}

const Shape& Shape::operator= (const Shape &shape) {
    n = shape.n;
    m = shape.m;
    return *this;
}

/** Constructors and Destructors */

Matrix::Matrix():
    n(0), m(0), a(nullptr) {}

Matrix::Matrix(int n_, int m_):
    n(n_), m(m_) {
        a = new double *[n];

        for(int i = 0;i < n;i++) {
            a[i] = new double[m];
            for(int j = 0;j < m;j++)
                a[i][j] = 0;
        }
    }

Matrix::Matrix(const Shape &shape):
    n(shape.n), m(shape.m) {
        a = new double *[n];

        for(int i = 0;i < n;i++) {
            a[i] = new double[m];
            for(int j = 0;j < m;j++)
                a[i][j] = 0;
        }
    }

Matrix::Matrix(const Matrix &mat):
    n(mat.n), m(mat.m) {
        a = new double *[n];

        for(int i = 0;i < n;i++) {
            a[i] = new double[m];
            for(int j = 0;j < m;j++)
                a[i][j] = mat.a[i][j];
        }
    }

Matrix::Matrix(double **mat, int n_, int m_):
    n(n_), m(m_) {
        a = new double *[n];

        for(int i = 0;i < n;i++) {
            a[i] = new double[m];
            for(int j = 0;j < m;j++)
                a[i][j] = mat[i][j];
        }
    }

Matrix::Matrix(const vector<vector<int> > &mat, int n_, int m_):
    n(n_), m(m_) {
        a = new double *[n];

        for(int i = 0;i < n;i++) {
            a[i] = new double[m];
            for(int j = 0;j < m;j++)
                a[i][j] = mat[i][j];
        }
    }

Matrix::~Matrix() {
    for(int i = 0;i < n;i++)
        delete a[i];

    delete a;
}

/** Overloaded Operators */

const Matrix& Matrix::operator= (const Matrix &mat) {
    for(int i = 0;i < n;i++)
        delete a[i];

    delete a;

    n = mat.n;
    m = mat.m;
    a = new double *[n];
    
    for(int i = 0;i < n;i++) {
        a[i] = new double[m];
        for(int j = 0;j < m;j++)
            a[i][j] = mat.a[i][j];
    }

    return *this;
}

double& Matrix::operator() (int i, int j) {
    return a[i][j];
}

const double& Matrix::operator() (int i, int j) const {
    return a[i][j];
}

Matrix Matrix::operator+ (Matrix &mat) const {
    if(n != mat.n || m != mat.m)
        throw MatError("Addition cannot be performed - shapes do not match");

    Matrix resMat(n, m);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(i, j) = a[i][j] + mat(i, j);
    }

    return resMat;
}

Matrix Matrix::operator- (Matrix &mat) const {
    if(n != mat.n || m != mat.m)
        throw MatError("Subtraction cannot be performed - shapes do not match");

    Matrix resMat(n, m);
    
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            resMat(i, j) = a[i][j] - mat(i, j);
    }

    return resMat;
}

/** Static Functions for Matrix Construction */

Matrix Matrix::identity(int n) {
    Matrix mat;
    mat.n = mat.m = n;
    mat.a = new double *[n];

    for(int i = 0;i < n;i++) {
        mat.a[i] = new double[n];
        for(int j = 0;j < n;j++)
            mat.a[i][j] = (i == j ? 1 : 0);
    }
}

Matrix Matrix::ones(int n, int m) {
    Matrix mat;
    mat.n = mat.m = n;
    mat.a = new double *[n];

    for(int i = 0;i < n;i++) {
        mat.a[i] = new double[n];
        for(int j = 0;j < n;j++)
            mat.a[i][j] = 1;
    }
}

Matrix Matrix::zeros(int n, int m) {
    return Matrix(n, m);
}
