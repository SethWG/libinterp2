
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

#ifndef _LIBINTERP2_H
#define	_LIBINTERP2_H

#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef	__cplusplus
extern "C" {
#endif

// CONSTANTS
#define PI          (22.0/7.0)
#define N_SIZE_2    2
#define N_SIZE_3    3
#define N_SIZE_4    4
#define N_SIZE_5    5
#define N_SIZE_6    6
#define N_SIZE_7    7

typedef double (*INTERP2_KERNEL_FUNCTION)(double);

// DATA STRUCTURES
typedef struct INTERP2_STRUCT_IMAGE {
    double  *data;
    int     xSize;
    int     ySize;
    double  *map;
} INTERP2_IMAGE;

typedef struct INTERP2_STRUCT_INTERP_INFO {
    int                     incStart;
    int                     incEnd;
    INTERP2_KERNEL_FUNCTION interpFunction;
} INTERP2_INFO;

// INTERPOLATION FUNCTIONS
void interp2_i_nn1(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_linear2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_cubic2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_quad3(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_lagrange3(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_cubic4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_lagrange4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_gaussian4(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_tsinc5(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_lagrange5(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_tsinc6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_cubic6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_lagrange6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_gaussian6(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_tsinc7(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);
void interp2_i_lagrange7(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0);

// KERNEL FUNCTIONS
double interp2_k_linear2(double x);
double interp2_k_cubic2(double x);
double interp2_k_quad3(double x);
double interp2_k_lagrange3(double x);
double interp2_k_cubic4(double x);
double interp2_k_lagrange4(double x);
double interp2_k_gaussian4(double x);
double interp2_k_tsinc5(double x);
double interp2_k_lagrange5(double x);
double interp2_k_tsinc6(double x);
double interp2_k_cubic6(double x);
double interp2_k_lagrange6(double x);
double interp2_k_gaussian6(double x);
double interp2_k_tsinc7(double x);
double interp2_k_lagrange7(double x);
double interp2_k_gaussian0(double x, double b);
double interp2_k_sinc(double x);

// LIBRARY FUNCTIONS
INTERP2_IMAGE interp2_create_image(double *data, int xSize, int ySize, int isAllValid);
int nearly_equal(double x1, double x2);
void perform_interp2(INTERP2_IMAGE in, INTERP2_IMAGE out, double *x0, double *y0, INTERP2_INFO info);
double round(double r);
int isPointNotValid(INTERP2_IMAGE in, int x, int y);

#ifdef	__cplusplus
}
#endif

#endif	/* _LIBINTERP2_H */

