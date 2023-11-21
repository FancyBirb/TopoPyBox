#include "mex.h"
#include "aspect.c"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    double *matrix, *result;
    mwSize rows, cols;

    // Get input matrix
    matrix = mxGetPr(prhs[0]);
    rows = mxGetM(prhs[0]);
    cols = mxGetN(prhs[0]);

    // Create output matrix
    plhs[0] = mxCreateDoubleMatrix(rows, cols, mxREAL);
    result = mxGetPr(plhs[0]);

    // Call the C function
    aspect(rows, cols, matrix, result);
}
