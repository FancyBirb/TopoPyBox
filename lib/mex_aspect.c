#include "mex.h"
#include "aspect.c"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
    // Überprüfen der Anzahl der Eingangs- und Ausgangsargumente
    if (nrhs != 3) {
        mexErrMsgIdAndTxt("MyToolbox:myCFunction:nrhs", "Three inputs required.");
    }
    if (nlhs != 1) {
        mexErrMsgIdAndTxt("MyToolbox:myCFunction:nlhs", "One output required.");
    }

    // Überprüfen, ob die Eingabeargumente die erwarteten Datentypen haben
    if (!mxIsSingle(prhs[0]) || mxIsComplex(prhs[0]) || !mxIsScalar(prhs[1]) || !mxIsScalar(prhs[2])) {
        mexErrMsgIdAndTxt("MyToolbox:myCFunction:invalidInput", "Invalid input types.");
    }

    // Eingabevariablen abrufen
    float *input = (float *)mxGetData(prhs[0]);
    int rows = (int)mxGetScalar(prhs[1]);
    int cols = (int)mxGetScalar(prhs[2]);

    // Ausgabematrix erstellen
    mxArray *outputMatrix = mxCreateNumericMatrix(rows, cols, mxSINGLE_CLASS, mxREAL);
    float *output = (float *)mxGetData(outputMatrix);

    // Aufruf der C-Funktion
    aspect(input, rows, cols, output);

    // Ausgabe setzen
    plhs[0] = outputMatrix;
}