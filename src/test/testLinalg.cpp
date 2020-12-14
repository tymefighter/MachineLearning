#include <linalg/linalg.hpp>
#include <cassert>
#include <vector>

using namespace std;

void matrixTest() {
    assert (
        Matrix({
            {1.0, 2.1, 3.2, 4.2},
            {1.2, -3.1, -5.3, 9.0},
            {3.1, 2.2, 3.3, 5.5}
        }) + Matrix({
            {3.5, 7.2, 1.1, 1.43},
            {-1, -5, 3, -0.33},
            {-1.12, 3.44, 5.56, -6.71}
        }) == Matrix({
            {4.5 ,  9.3,  4.3 ,  5.63},
            {0.2 , -8.1, -2.3 ,  8.67},
            {1.98,  5.64,  8.86, -1.21}
        })
    );

    assert (
        Matrix({
            {4.5, -9.91, 3.31, 4.54, -0.34},
            {2.331, 4.54, 6.75, 9.10, 0.4451}
        }) - Matrix({
            {-11.23, -0.45, 45.5, 7.11, 1.3},
            {55.0, -531.2, 11.1, 4.2, -5.59}
        }) == Matrix({
            {15.73,  -9.46, -42.19, -2.57, -1.64},
            {-52.669, 535.74, -4.35, 4.9, 6.0351}
        })
    );
}

void operationTest() {

    // Transpose

    Matrix a({
        {4.5, 1.33, -0.45, -4.5},
        {3.5, -5.3, 1.73, 4.41}
    });

    Matrix aTranspose({
        {4.5, 3.5},
        {1.33, -5.3},
        {-0.45, 1.73},
        {-4.5, 4.41}
    });

    assert (transpose(a) == aTranspose);
    assert (transpose(transpose(a)) == a);

    // Elementwise Multiplication

    Matrix b({
        {7.43, 0.34, 0.0021, -4.5},
        {11.34, -45.31, 0.033, -102.2}
    });

    Matrix mulMat({
        {33.435, 0.4522, -0.000945, 20.25},
        {39.69,  240.143, 0.05709, -450.702}
    });

    assert (mul(a, b) == mulMat);

    // Elementwise Division

    Matrix divMat({
        {0.60565276, 3.91176471, -214.28571429, 1.0},
        {0.30864198, 0.11697197, 52.42424242, -0.04315068}
    });
    
    assert (div(a, b) == divMat);
}

void reduceTest() {
    Matrix a({
        {1, 2, 3, 4},
        {3, 6, 7, 2},
        {4, 7, 5, -3},
        {0, 0, 2, 1}
    });

    // REF

    Matrix ref({
        {1, 2, 3, 4},
        {0, -1, -7, -19},
        {0, 0, -2, -10},
        {0, 0, 0, -9}
    });

    assert (getREF(a) == ref);
}

void runTests() {
    matrixTest();
    operationTest();
    reduceTest();
}

int main() {
    runTests();
    return 0;
}
