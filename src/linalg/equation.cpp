#include <vector>
#include <linalg/matrix.hpp>
#include <linalg/reduce.hpp>
#include <linalg/equation.hpp>

enum Value {SINGLE, INFINITE};

Matrix constructAugmentedMatrix(const Matrix &A, const Matrix &b) {
    int n = A.getNumRows(), m = A.getNumCols();
    Matrix augMat(n, m + 1);

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++)
            augMat(i, j) = A(i, j);
    }

    for(int i = 0;i < n;i++)
        augMat(i, m) = b(i, 0);

    return augMat;
}

bool checkZeroCoeffRow(const Matrix &ref, int rowIdx) {
    int m = ref.getNumCols() - 1;

    for(int i = 0;i < m;i++) {
        if(!isZero(ref(rowIdx, i)))
            return false;
    }

    return true;
}

int getPivotIdx(const Matrix &ref, int rowIdx) {
    int m = ref.getNumCols() - 1;

    for(int i = 0;i < m;i++) {
        if(!isZero(ref(rowIdx, i)))
            return i;
    }

    throw MatError("There is no pivot element");
    return -1;
}

Solution solveEquations(
    const Matrix &A,
    const Matrix &b,
    Matrix &x
) {
    if(A.getNumRows() != b.getNumRows() || b.getNumCols() != 1)
        throw MatError("Input shapes do not agree");

    int n = A.getNumRows(), m = A.getNumCols();

    std::vector<Value> xValue(m, INFINITE);
    x = Matrix(m, 1);

    // Construct Augmented Matrix
    Matrix augMat = constructAugmentedMatrix(A, b);

    // Perform Gaussian Elimination to get REF
    Matrix ref = getREF(augMat);

    // Go over all rows which have zeros in the
    // first m columns (last column can have anything)
    int rowIdx = n - 1;
    while(rowIdx >= 0 && checkZeroCoeffRow(ref, rowIdx)) {
        // If mth column (0 based) is not zero, we
        // have: zero = non zero, hence no solution
        if(!isZero(ref(rowIdx, m)))
            return NO_SOLUTION;

        rowIdx --;
    }

    // Now, we are sure to have atleast one solution
    // Hence, we perform back substitution
    while(rowIdx >= 0) {

        // Get pivot index in row with index rowIdx
        int pivotIdx = getPivotIdx(ref, rowIdx);

        // Assume this has a single solution
        xValue[pivotIdx] = SINGLE;

        x(pivotIdx, 0) = ref(rowIdx, m);
        for(int i = pivotIdx + 1;i < m;i++) {

            // If any variable it depends on has
            // infinite solutions, then it too has
            // infinite solutions (since that can take
            // infinite values)
            if(!isZero(ref(rowIdx, i)) && xValue[i] == INFINITE) {
                xValue[pivotIdx] = INFINITE;
                break;
            }

            // This variable currently does not seem to have
            // infinite values, hence keep on computing its
            // value
            x(pivotIdx, 0) -= ref(rowIdx, i) * x(i, 0);
        }

        if(xValue[pivotIdx] == SINGLE)
            x(pivotIdx, 0) /= ref(rowIdx, pivotIdx);

        rowIdx --;
    }

    for(int i = 0;i < m;i++) {
        if(xValue[i] == INFINITE)
            return INFINITE_SOLUTIONS;
    }

    return ONE_SOLUTION;
}
