
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
