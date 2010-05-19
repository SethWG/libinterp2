
#include "libinterp2.h"

INTERP2_IMAGE interp2_create_image(double *data, int xSize, int ySize, int isAllValid)
{
    INTERP2_IMAGE image;
    image.data = data;
    image.xSize = xSize;
    image.ySize = ySize;
    image.map = NULL;
    return image;
}

int nearly_equal(double x1, double x2)
{
    return (x1 == x2) || (fabs((x2-x1)/x2) < 0.00001);
}

void perform_interp2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0, INTERP2_INFO info)
{
    int totalPixels                 = out.xSize * out.ySize;
    int index                       = 1;
    double *currentOutPt            = out.data;
    double *currentX0Pt             = x0;
    double *currentY0Pt             = y0;
    ptrdiff_t increment             = (ptrdiff_t) NULL;
    int x1,y1                       = 0;
    int x2,y2                       = 0;
    int *increments                 = NULL;
    int N_SIZE                      = 0;
    int i,j                         = 0;
    double result                   = 0.0;
    double diff_x,diff_y            = 0.0;
    double current_factor           = 0.0;
    int isNotValid                  = 0;
    INTERP2_KERNEL_FUNCTION kernel  = info.interpFunction;

    // Calculate what the x and y increments are
    N_SIZE      = info.incEnd - info.incStart + 1;
    increments  = (int *) malloc(N_SIZE*sizeof(int));
    if(increments == NULL)
    {
        return;
    }
    index = 0;
    for(i = info.incStart; i <= info.incEnd; i++)
    {
        increments[index] = i;
        ++index;
    }

    // Perform the interpolation
    index = 0;
    while(index <= totalPixels)
    {
        x1              = (int) floor(*currentX0Pt);
        y1              = (int) floor(*currentY0Pt);
        result          = 0.0;
        isNotValid      = 0;

        for(j = 0; j < N_SIZE; j++)
        {
            for(i = 0; i < N_SIZE; i++)
            {
                x2              = x1 + increments[i];
                y2              = y1 + increments[j];
                if(isPointNotValid(in, x2, y2))
                {
                    result      = 0.0;
                    isNotValid  = 1;
                    break;
                }
                diff_x          = fabs(*currentX0Pt - ((double) x2));
                diff_y          = fabs(*currentY0Pt - ((double) y2));
                increment       = (ptrdiff_t) ((in.ySize * x2) + y2);
                current_factor  = (*kernel)(diff_x) * (*kernel)(diff_y);
                result          += *(in.data+increment) * current_factor;
            }
            if(isNotValid)
            {
                break;
            }
        }
        *currentOutPt = result;

        ++currentOutPt;
        ++currentX0Pt;
        ++currentY0Pt;
        ++index;
    }

    // Free any memory
    free(increments);
    increments = NULL;
}

double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

int isPointNotValid(INTERP2_IMAGE in, int x, int y)
{
    if((x < 0) || (x > (in.xSize - 1)) || (y < 0) || (y > (in.ySize - 1)))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}