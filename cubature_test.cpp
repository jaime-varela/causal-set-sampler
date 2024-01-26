#include <stdio.h>
#include <math.h>
#include "cubature.h"

int f(unsigned ndim, const double *x, void *fdata, unsigned fdim, double *fval) {
    double sigma = *((double *) fdata); // we can pass σ via fdata argument
    double sum = 0;
    unsigned i;
    for (i = 0; i < ndim; ++i) sum += x[i] * x[i];
    // compute the output value: note that fdim should == 1 from below
    fval[0] = exp(-sigma * sum);
    return 0; // success*
}

int main(int argc, char const *argv[])
{
    double xmin[3] = {-2,-2,-2}, xmax[3] = {2,2,2}, sigma = 0.5, val, err;
    hcubature(1, f, &sigma, 3, xmin, xmax, 0, 0, 1e-4, ERROR_INDIVIDUAL, &val, &err);
    printf("Computed integral = %0.10g +/- %g\n", val, err);
    return 0;
}
