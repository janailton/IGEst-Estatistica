/*************************************************************************
Copyright (c) 2005-2007, Sergey Bochkanov (ALGLIB project).

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

#ifndef _spddet_h
#define _spddet_h

#include "ap.h"
#include "ialglib.h"

#include "cholesky.h"


/*************************************************************************
Determinant calculation of the matrix given by the Cholesky decomposition.

Input parameters:
    A   -   Cholesky decomposition,
            output of SMatrixCholesky subroutine.
    N   -   size of matrix A.

As the determinant is equal to the product of squares of diagonal elements,
it�s not necessary to specify which triangle - lower or upper - the matrix
is stored in.

Result:
    matrix determinant.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixcholeskydet(const ap::real_2d_array& a, int n);


/*************************************************************************
Determinant calculation of the symmetric positive definite matrix.

Input parameters:
    A       -   matrix. Array with elements [0..N-1, 0..N-1].
    N       -   size of matrix A.
    IsUpper -   if IsUpper = True, then the symmetric matrix A is given by
                its upper triangle, and the lower triangle isn�t used by
                subroutine. Similarly, if IsUpper = False, then A is given
                by its lower triangle.

Result:
    determinant of matrix A.
    If matrix A is not positive definite, then subroutine returns -1.

  -- ALGLIB --
     Copyright 2005-2008 by Bochkanov Sergey
*************************************************************************/
double spdmatrixdet(ap::real_2d_array a, int n, bool isupper);


/*************************************************************************
Obsolete subroutine
*************************************************************************/
double determinantcholesky(const ap::real_2d_array& a, int n);


/*************************************************************************
Obsolete subroutine
*************************************************************************/
double determinantspd(ap::real_2d_array a, int n, bool isupper);


#endif

