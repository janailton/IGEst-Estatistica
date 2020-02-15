/*************************************************************************
Copyright (c) 2007, Sergey Bochkanov (ALGLIB project).

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

#ifndef _spline3_h
#define _spline3_h

#include "ap.h"
#include "ialglib.h"

/*************************************************************************
This subroutine builds linear spline coefficients table.

Input parameters:
    X   -   spline nodes, array[0..N-1]
    Y   -   function values, array[0..N-1]
    N   -   points count, N>=2
    
Output parameters:
    C   -   coefficients table.  Used  by  SplineInterpolation  and  other
            subroutines from this file.

  -- ALGLIB PROJECT --
     Copyright 24.06.2007 by Bochkanov Sergey
*************************************************************************/
void buildlinearspline(ap::real_1d_array x,
     ap::real_1d_array y,
     int n,
     ap::real_1d_array& c);


/*************************************************************************
This subroutine builds cubic spline coefficients table.

Input parameters:
    X           -   spline nodes, array[0..N-1]
    Y           -   function values, array[0..N-1]
    N           -   points count, N>=2
    BoundLType  -   boundary condition type for the left boundary
    BoundL      -   left boundary condition (first or second derivative,
                    depending on the BoundLType)
    BoundRType  -   boundary condition type for the right boundary
    BoundR      -   right boundary condition (first or second derivative,
                    depending on the BoundRType)

Output parameters:
    C           -   coefficients table.  Used  by  SplineInterpolation and
                    other subroutines from this file.
                    
The BoundLType/BoundRType parameters can have the following values:
    * 0,   which  corresponds  to  the  parabolically   terminated  spline
      (BoundL/BoundR are ignored).
    * 1, which corresponds to the first derivative boundary condition
    * 2, which corresponds to the second derivative boundary condition

  -- ALGLIB PROJECT --
     Copyright 23.06.2007 by Bochkanov Sergey
*************************************************************************/
void buildcubicspline(ap::real_1d_array x,
     ap::real_1d_array y,
     int n,
     int boundltype,
     double boundl,
     int boundrtype,
     double boundr,
     ap::real_1d_array& c);


/*************************************************************************
This subroutine builds cubic Hermite spline coefficients table.

Input parameters:
    X           -   spline nodes, array[0..N-1]
    Y           -   function values, array[0..N-1]
    D           -   derivatives, array[0..N-1]
    N           -   points count, N>=2

Output parameters:
    C           -   coefficients table.  Used  by  SplineInterpolation and
                    other subroutines from this file.

  -- ALGLIB PROJECT --
     Copyright 23.06.2007 by Bochkanov Sergey
*************************************************************************/
void buildhermitespline(ap::real_1d_array x,
     ap::real_1d_array y,
     ap::real_1d_array d,
     int n,
     ap::real_1d_array& c);


/*************************************************************************
This subroutine builds Akima spline coefficients table.

Input parameters:
    X           -   spline nodes, array[0..N-1]
    Y           -   function values, array[0..N-1]
    N           -   points count, N>=5

Output parameters:
    C           -   coefficients table.  Used  by  SplineInterpolation and
                    other subroutines from this file.

  -- ALGLIB PROJECT --
     Copyright 24.06.2007 by Bochkanov Sergey
*************************************************************************/
void buildakimaspline(ap::real_1d_array x,
     ap::real_1d_array y,
     int n,
     ap::real_1d_array& c);


/*************************************************************************
This subroutine calculates the value of the spline at the given point X.

Input parameters:
    C           -   coefficients table. Built by BuildLinearSpline,
                    BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    X           -   point

Result:
    S(x)

  -- ALGLIB PROJECT --
     Copyright 23.06.2007 by Bochkanov Sergey
*************************************************************************/
double splineinterpolation(const ap::real_1d_array& c, double x);


/*************************************************************************
This subroutine differentiates the spline.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    X   -   point

Result:
    S   -   S(x)
    DS  -   S'(x)
    D2S -   S''(x)

  -- ALGLIB PROJECT --
     Copyright 24.06.2007 by Bochkanov Sergey
*************************************************************************/
void splinedifferentiation(const ap::real_1d_array& c,
     double x,
     double& s,
     double& ds,
     double& d2s);


/*************************************************************************
This subroutine makes the copy of the spline.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.

Result:
    CC  -   spline copy

  -- ALGLIB PROJECT --
     Copyright 29.06.2007 by Bochkanov Sergey
*************************************************************************/
void splinecopy(const ap::real_1d_array& c, ap::real_1d_array& cc);


/*************************************************************************
This subroutine unpacks the spline into the coefficients table.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    X   -   point

Result:
    Tbl -   coefficients table, unpacked format, array[0..N-2, 0..5].
            For I = 0...N-2:
                Tbl[I,0] = X[i]
                Tbl[I,1] = X[i+1]
                Tbl[I,2] = C0
                Tbl[I,3] = C1
                Tbl[I,4] = C2
                Tbl[I,5] = C3
            On [x[i], x[i+1]] spline is equals to:
                S(x) = C0 + C1*t + C2*t^2 + C3*t^3
                t = x-x[i]

  -- ALGLIB PROJECT --
     Copyright 29.06.2007 by Bochkanov Sergey
*************************************************************************/
void splineunpack(const ap::real_1d_array& c, int& n, ap::real_2d_array& tbl);


/*************************************************************************
This subroutine performs linear transformation of the spline argument.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    A, B-   transformation coefficients: x = A*t + B
Result:
    C   -   transformed spline

  -- ALGLIB PROJECT --
     Copyright 30.06.2007 by Bochkanov Sergey
*************************************************************************/
void splinelintransx(ap::real_1d_array& c, double a, double b);


/*************************************************************************
This subroutine performs linear transformation of the spline.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    A, B-   transformation coefficients: S2(x) = A*S(x) + B
Result:
    C   -   transformed spline

  -- ALGLIB PROJECT --
     Copyright 30.06.2007 by Bochkanov Sergey
*************************************************************************/
void splinelintransy(ap::real_1d_array& c, double a, double b);


/*************************************************************************
This subroutine integrates the spline.

Input parameters:
    C   -   coefficients table. Built by BuildLinearSpline,
            BuildHermiteSpline, BuildCubicSpline, BuildAkimaSpline.
    X   -   right bound of the integration interval [a, x]
Result:
    integral(S(t)dt,a,x)

  -- ALGLIB PROJECT --
     Copyright 23.06.2007 by Bochkanov Sergey
*************************************************************************/
double splineintegration(const ap::real_1d_array& c, double x);


/*************************************************************************
Obsolete subroutine, left for backward compatibility.
*************************************************************************/
void spline3buildtable(int n,
     const int& diffn,
     ap::real_1d_array x,
     ap::real_1d_array y,
     const double& boundl,
     const double& boundr,
     ap::real_2d_array& ctbl);


/*************************************************************************
Obsolete subroutine, left for backward compatibility.
*************************************************************************/
double spline3interpolate(int n, const ap::real_2d_array& c, const double& x);


#endif

