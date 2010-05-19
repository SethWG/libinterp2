
#include "libinterp2.h"

void interp2_i_linear2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = 0;
    currentFunc.incEnd          = 1;
    currentFunc.interpFunction  = &interp2_k_linear2;

    perform_interp2(in, out, x0, y0, currentFunc);
}

double interp2_k_linear2(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 1.0))
    {
        result = 1.0 - x;
    }
    return result;
}
