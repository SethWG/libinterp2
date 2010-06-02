
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

void interp2_i_nn1(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0)
{
    int totalPixels         = out.xSize * out.ySize;
    int index               = 1;
    double *currentOutPt    = out.data;
    double *currentX0Pt     = x0;
    double *currentY0Pt     = y0;
    ptrdiff_t increment     = (ptrdiff_t) NULL;
    int x                   = 0;
    int y                   = 0;
    while(index <= totalPixels)
    {
        x = (int) round(*currentX0Pt);
        y = (int) round(*currentY0Pt);
        if(isPointNotValid(in, x, y))
        {
            *currentOutPt = 0.0;
        }
        else
        {
            increment = (ptrdiff_t) ((in.ySize * x) + y);
            *currentOutPt = *(in.data+increment);
        }

        ++index;
        ++currentOutPt;
        ++currentX0Pt;
        ++currentY0Pt;
    }
}
