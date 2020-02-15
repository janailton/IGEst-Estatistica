/*************************************************************************
Copyright (c) 1992-2007 The University of Tennessee.  All rights reserved.

Contributors:
    * Sergey Bochkanov (ALGLIB project). Translation from FORTRAN to
      pseudocode.

See subroutines comments for additional copyrights.

>>> SOURCE LICENSE >>>
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation (www.fsf.org); either version 2 of the 
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

A copy of the GNU General Public License is available at
http://www.fsf.org/licensing/licenses

>>> END OF LICENSE >>>
*************************************************************************/

#ifndef _rcond_h
#define _rcond_h

#include "ap.h"
#include "ialglib.h"

#include "lu.h"
#include "trlinsolve.h"


/*************************************************************************
Estimate of a matrix condition number (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))
*************************************************************************/
double rmatrixrcond1(const ap::real_2d_array& a, int n);


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition (1-norm)

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUDcmp      -   LU decomposition of a matrix in compact form. Output of
                    the RMatrixLU subroutine.
    N           -   size of matrix A.

Result: 1/LowerBound(cond(A))
*************************************************************************/
double rmatrixlurcond1(const ap::real_2d_array& ludcmp, int n);


/*************************************************************************
Estimate of a matrix condition number (infinity-norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    A   -   matrix. Array whose indexes range within [0..N-1, 0..N-1].
    N   -   size of matrix A.

Result: 1/LowerBound(cond(A))
*************************************************************************/
double rmatrixrcondinf(const ap::real_2d_array& a, int n);


/*************************************************************************
Estimate of the condition number of a matrix given by its LU decomposition
(infinity norm).

The algorithm calculates a lower bound of the condition number. In this case,
the algorithm does not return a lower bound of the condition number, but an
inverse number (to avoid an overflow in case of a singular matrix).

Input parameters:
    LUDcmp  -   LU decomposition of a matrix in compact form. Output of
                the RMatrixLU subroutine.
    N       -   size of matrix A.

Result: 1/LowerBound(cond(A))
*************************************************************************/
double rmatrixlurcondinf(const ap::real_2d_array& ludcmp, int n);


/*************************************************************************
Obsolete 1-based version, see RMatrixRCond1 for 0-bases replacement
*************************************************************************/
double rcond1(ap::real_2d_array a, int n);


/*************************************************************************
Obsolete 1-based subroutine, see RMatrixLURCond1 for 0-based replacement.
*************************************************************************/
double rcond1lu(const ap::real_2d_array& ludcmp, int n);


/*************************************************************************
Obsolete 1-based subroutine, see RMatrixRCondInf for 0-based replacement.
*************************************************************************/
double rcondinf(ap::real_2d_array a, int n);


/*************************************************************************
Obsolete 1-based subroutine, see RMatrixLURCondInf for 0-based replacement
*************************************************************************/
double rcondinflu(const ap::real_2d_array& ludcmp, int n);


#endif

