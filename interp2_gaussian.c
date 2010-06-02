
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

void interp2_i_gaussian4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -1;
    currentFunc.incEnd          = 2;
    currentFunc.interpFunction  = &interp2_k_gaussian4;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_gaussian6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_gaussian6;

    perform_interp2(in, out, x0, y0, currentFunc);
}

double interp2_k_gaussian4(double x)
{
    const double GAMMA_2 = (1.0 / (2.0 * PI)) * pow((1.0 / sqrt(2.0)), 2.0);
    double result = 0.0;
    if((x >= 0.0) && (x < 2.0))
    {
        result = interp2_k_gaussian0(x,(2.0*GAMMA_2))
                - (GAMMA_2 * interp2_k_gaussian0(x,GAMMA_2));
    }
    return result;
}

double interp2_k_gaussian6(double x)
{
    const double GAMMA_2 = (1.0 / (2.0 * PI)) * pow((1.0 / sqrt(2.0)), 2.0);
    double result = 0.0;
    if((x >= 0.0) && (x < 3.0))
    {
        result = interp2_k_gaussian0(x,(2.0*GAMMA_2))
                - (GAMMA_2 * interp2_k_gaussian0(x,GAMMA_2));
    }
    return result;
}

double interp2_k_gaussian0(double x, double b)
{
    double result = 0.0;
    result = (1.0 / sqrt(2 * PI * b)) * exp((-1.0 * x * x) / (2.0 * b));
    return result;
}


