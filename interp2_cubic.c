
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

void interp2_i_cubic2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = 0;
    currentFunc.incEnd          = 1;
    currentFunc.interpFunction  = &interp2_k_cubic2;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_cubic4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -1;
    currentFunc.incEnd          = 2;
    currentFunc.interpFunction  = &interp2_k_cubic4;

    perform_interp2(in, out, x0, y0, currentFunc);
}

void interp2_i_cubic6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    INTERP2_INFO currentFunc;

    currentFunc.incStart        = -2;
    currentFunc.incEnd          = 3;
    currentFunc.interpFunction  = &interp2_k_cubic6;

    perform_interp2(in, out, x0, y0, currentFunc);
}

double interp2_k_cubic2(double x)
{
    double result = 0.0;
    result = (2.0 * x * x * x) - (3.0 * x * x) + 1.0;
    return result;
}

double interp2_k_cubic4(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 1.0))
    {
        result = (x * x * x) - (2.0 * x * x) + 1.0;
    }
    else if((x >= 1.0) && (x < 2.0))
    {
        result = (-1.0 * x * x * x) + (5.0 * x * x) - (8.0 * x) + 4.0;
    }
    return result;
}

double interp2_k_cubic6(double x)
{
    double result = 0.0;
    if((x >= 0.0) && (x < 1.0))
    {
        result = ((6.0/5.0) * x * x * x) - ((11.0/5.0) * x * x) + 1.0;
    }
    else if((x >= 1.0) && (x < 2.0))
    {
        result = ((-3.0/5.0) * x * x * x) + ((16.0/5.0) * x * x)
                - ((27.0/5.0) * x) + (14.0/5.0);
    }
    else if((x >= 2.0) && (x < 3.0))
    {
        result = ((1.0/5.0) * x * x * x) - ((8.0/5.0) * x * x)
                + ((21.0/5.0) * x) - (18.0/5.0);
    }
    return result;
}
