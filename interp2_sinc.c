
/*
 * Copyright - 2010 - Seth Weith-Glushko
 *
 * This file is part of libinterp2.
 *
 * Libinterp2 is free software: you can redistribute it and/or modify
 * it under the terms of the Lesser GNU General Public License as 
 * published by the Free Software Foundation, either version 3 of the 
 * License, or (at your option) any later version.
 *
 * Libinterp2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public 
 * License along with libinterp2.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
 
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
