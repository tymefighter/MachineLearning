#include <string>
#include <vector>

using namespace std;

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
};

/** Matrix */

class Matrix {

    private:

    int n, m;
    double **a;

    Matrix();

    public:

    Matrix(double **mat, int n_, int m_);

    Matrix(const vector<vector<int> > &mat, int n_, int m_);

    ~Matrix();

    inline int getNumRows() {return n;}

    inline int getNumCols() {return m;}

    inline Shape getShape() {return Shape(n, m);}

    double& operator() (int i, int j);

    Matrix operator+ (Matrix &mat);

    Matrix operator- (Matrix &mat);
    
    static Matrix identity(int n);

    static Matrix ones(int n, int m);

    static Matrix zeros(int n, int m);
};

