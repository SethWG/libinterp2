
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

void interp2_i_lagrange3(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -1;
    currentFunc.incEnd          = 1;
    currentFunc.interpFunction  = &interp2_k_lagrange3;
    
    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_lagrange4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -1;
    currentFunc.incEnd          = 2;
    currentFunc.interpFunction  = &interp2_k_lagrange4;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_lagrange5(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 2;
    currentFunc.interpFunction  = &interp2_k_lagrange5;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_lagrange6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_lagrange6;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_lagrange7(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -3;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_lagrange7;
    
    perform_interp2(in, out, x0, y0, currentFunc);
}

double interp2_k_lagrange3(double x)
{
    double result = 0.0;
    if((x >= 0.0) & (x < 0.5))
    {
        result = ((-1.0) * x * x)
                + 1.0;
    }
    else if((x >= 0.5) & (x < 1.5))
    {
        result = ((1.0/2.0) * x * x)
                + ((-3.0/2.0) * x)
                + 1.0;
    }
    return result;
}

double interp2_k_lagrange4(double x)
{
    double result = 0.0;
    if((x >= 0.0) & (x < 1.0))
    {
        result = ((1.0/2.0) * x * x * x)
                + ((-2.0/2.0) * x * x)
                + ((-1.0/2.0) * x)
                + 1.0;
    }
    else if((x >= 1.0) & (x < 2.0))
    {
        result = ((-1.0/6.0) * x * x * x)
                + ((6.0/6.0) * x * x)
                + ((-11.0/6.0) * x)
                + 1.0;
    }
    return result;
}

double interp2_k_lagrange5(double x)
{
    double result = 0.0;
    if((x >= 0.0) & (x < 0.5))
    {
        result = ((1.0/4.0) * x * x * x * x)
                + ((-5.0/4.0) * x * x)
                + 1.0;
    }
    else if((x >= 0.5) & (x < 1.5))
    {
        result = ((-1.0/6.0) * x * x * x * x)
                + ((5.0/6.0) * x * x * x)
                + ((-5.0/6.0) * x * x)
                + ((-5.0/6.0) * x)
                + 1.0;
    }
    else if((x >= 1.5) & (x < 2.5))
    {
        result = ((1.0/24.0) * x * x * x * x)
                + ((-5.0/12.0) * x * x * x)
                + ((35.0/24.0) * x * x)
                + ((-25.0/12.0) * x)
                + 1.0;
    }
    return result;
}

double interp2_k_lagrange6(double x)
{
    double result = 0.0;
    if((x >= 0.0) & (x < 1.0))
    {
        result = ((-1.0/12.0) * x * x * x * x * x)
                + ((3.0/12.0) * x * x * x * x)
                + ((5.0/12.0) * x * x * x)
                + ((-15.0/12.0) * x * x)
                + ((-4.0/12.0) * x)
                + 1.0;
    }
    else if((x >= 1.0) & (x < 2.0))
    {
        result = ((1.0/24.0) * x * x * x * x * x)
                + ((-9.0/24.0) * x * x * x * x)
                + ((25.0/24.0) * x * x * x)
                + ((-15.0/24.0) * x * x)
                + ((-26.0/24.0) * x)
                + 1.0;
    }
    else if((x >= 2.0) & (x < 3.0))
    {
        result = ((-1.0/120.0) * x * x * x * x * x)
                + ((15.0/120.0) * x * x * x * x)
                + ((-85.0/120.0) * x * x * x)
                + ((225.0/120.0) * x * x)
                + ((-274.0/120.0) * x)
                + 1.0;
    }
    return result;
}

double interp2_k_lagrange7(double x)
{
    double result = 0.0;
    if((x >= 0.0) & (x < 0.5))
    {
        result = ((-1.0/36.0) * x * x * x * x * x * x)
                + ((14.0/36.0) * x * x * x * x)
                + ((-49.0/36.0) * x * x)
                + 1.0;
    }
    else if((x >= 0.5) & (x < 1.5))
    {
        result = ((1.0/48.0) * x * x * x * x * x * x)
                + ((-7.0/48.0) * x * x * x * x * x)
                + ((7.0/48.0) * x * x * x * x)
                + ((35.0/48.0) * x * x * x)
                + ((-56.0/48.0) * x * x)
                + ((-29.0/48.0) * x)
                + 1.0;
    }
    else if((x >= 1.5) & (x < 2.5))
    {
        result = ((-1.0/120.0) * x * x * x * x * x * x)
                + ((14.0/120.0) * x * x * x * x * x)
                + ((-70.0/120.0) * x * x * x * x)
                + ((140.0/120.0) * x * x * x)
                + ((-49.0/120.0) * x * x)
                + ((-154.0/120.0) * x)
                + 1.0;
    }
    else if((x >= 2.5) & (x < 3.5))
    {
        result = ((1.0/720.0) * x * x * x * x * x * x)
                + ((-21.0/720.0) * x * x * x * x * x)
                + ((175.0/720.0) * x * x * x * x)
                + ((-735.0/720.0) * x * x * x)
                + ((1624.0/720.0) * x * x)
                + ((-1764.0/720.0) * x)
                + 1.0;
    }
    return result;
}
