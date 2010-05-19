
#include "libinterp2.h"

void interp2_i_tsinc5(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 2;
    currentFunc.interpFunction  = &interp2_k_tsinc5;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_tsinc6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_tsinc6;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_tsinc7(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -3;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_tsinc7;

    perform_interp2(in, out, x0, y0, currentFunc);
}

double interp2_k_tsinc5(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 2.5))
    {
        result = interp2_k_sinc(x);
    }
    return result;
}

double interp2_k_tsinc6(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 3.0))
    {
        result = interp2_k_sinc(x);
    }
    return result;
}

double interp2_k_tsinc7(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 3.5))
    {
        result = interp2_k_sinc(x);
    }
    return result;
}

double interp2_k_sinc(double x)
{
    double result = 0.0;
    if(nearly_equal(x,0.0))
    {
        result = 1.0;
    }
    else
    {
        result = sin(PI * x) / (PI * x);
    }
    return result;
}
