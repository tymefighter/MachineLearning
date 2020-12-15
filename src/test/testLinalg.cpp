#include <linalg/linalg.hpp>
#include <cassert>
#include <vector>

using namespace std;

/** Core Matrix Test */

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

/** Matrix Operations Test */

bool inverseTest(
    const Matrix &mat, 
    const Matrix &inv,
    bool inverseExists
) {
    bool testPass;

    try {
        Matrix invOut = inverse(mat);
        testPass = inverseExists && (invOut == inv);
    } catch(MatError &matError) {
        testPass = !inverseExists;
    }

    return testPass;
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

    // Inverse

    assert(inverseTest(
        Matrix({
            {3, 3, 4, 5},
            {8, 2, 1, 0},
            {4, 8, 2, 2},
            {7, 7, 1, 3}
        }),
        Matrix({
            {
                -0.003937007874015748043, 
                0.11417322834645669289, 
                -0.078740157480314960647, 
                0.059055118110236220502
            },
            {
                -0.066929133858267716543,
                -0.059055118110236220435,
                0.16141732283464566935,
                0.0039370078740157479517
            },
            {
                0.16535433070866141732,
                0.20472440944881889775,
                0.30708661417322834663,
                -0.48031496062992126005
            },
            {
                0.1102362204724409449,
                -0.19685039370078740168,
                -0.29527559055118110252,
                0.34645669291338582696
            }
        }),
        true
    ));

    assert(inverseTest(
        Matrix({
            {4, 5, 1, 2},
            {2, 4, 1, 2}
        }),
        Matrix(),
        false
    ));

    assert(inverseTest(
        Matrix({
            {1, 2, 3, 4},
            {5, 10, 15, 20},
            {0, 12, 4, 5},
            {3, 4, 2, 1}
        }),
        Matrix(),
        false
    ));
}

/** Matrix Row Reduction Test */

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

    // RREF

    assert(getRREF(a) == Matrix::identity(4));
}

/** Linear System of Equations Test */

void equationTest() {

    Matrix A, b, x;

    // Test 1 - One Solution

    A = Matrix({
        {1, 2, 4},
        {6, 2, 3},
        {2, 4, 7}
    });

    b = Matrix({{4}, {2}, {6}});

    assert(solveEquations(A, b, x) == ONE_SOLUTION);
    assert (x == Matrix(vector<vector<double> > {{0}, {-2}, {2}}));

    // Test 2 - One Solution

    A = Matrix({
        {1, 2, 4},
        {6, 2, 3},
        {2, 4, 7},
        {1, 22, 41}
    });

    b = Matrix({{4}, {2}, {6}, {38}});

    assert(solveEquations(A, b, x) == ONE_SOLUTION);
    assert (x == Matrix(vector<vector<double> > {{0}, {-2}, {2}}));

    // Test 3 - One Solution

    A = Matrix({
        {3, 0, 0, 4, 0},
        {0, 2, 3, 45, 0},
        {2, 0, 0, 0, 11},
        {0, 3, 0, 3, 0},
        {13, 14, 0, 15, 0}
    });

    b = Matrix({{12}, {17}, {34}, {33}, {7}});

    assert(solveEquations(A, b, x) == ONE_SOLUTION);
    assert (x == Matrix(vector<vector<double> > {
        {-600.0 / 49.0}, 
        {-58.0 / 49.0}, 
        {-25916.0 / 147.0},
        {597.0 / 49.0},
        {2866.0 / 539.0}
    }));

    // Test 4 - No Solution

    A = Matrix({
        {0, 1, 0, 2, 4},
        {0, 6, 0, 2, 3},
        {0, 2, 0, 4, 7},
        {0, 1, 0, 22, 41}
    });

    b = Matrix({{4}, {2}, {6}, {32}});
    assert(solveEquations(A, b, x) == NO_SOLUTION);

    // Test 5 - No Solution

    A = Matrix({
        {0, 0, 0, 0, 0},
        {1, 2, 4, 0, 0},
        {0, 0, 0, 0, 0},
        {6, 2, 3, 0, 0},
        {2, 4, 7, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 4, 8, 3, 0},
        {2, 3, 0, 4, 0},
    });

    b = Matrix({{0}, {4}, {0}, {2}, {6}, {0}, {45}, {91}});
    assert(solveEquations(A, b, x) == NO_SOLUTION);

    // Test 6 - Infinite Solutions

    A = Matrix({
        {3, 0, 0, 4, 0, 3},
        {0, 2, 3, 45, 0, 4},
        {2, 0, 0, 0, 11, 5},
        {0, 3, 0, 3, 0, 6},
        {13, 14, 0, 15, 0, 7}
    });

    b = Matrix({{12}, {17}, {34}, {33}, {7}});
    assert(solveEquations(A, b, x) == INFINITE_SOLUTIONS);

    // Test 7 - Infinite Solutions
    A = Matrix({
        {1, 2, 0, 4},
        {2, 4, 0, 7},
        {1, 22, 0, 41}
    });

    b = Matrix({{4}, {6}, {38}});
    assert(solveEquations(A, b, x) == INFINITE_SOLUTIONS);
}

/** Run Tests */

void runTests() {
    matrixTest();
    operationTest();
    reduceTest();
    equationTest();
}

int main() {
    runTests();
    return 0;
}
