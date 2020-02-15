#ifndef MATRIX_MD_H
#define MATRIX_MD_H


#include <valarray>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <cassert>


template<class Iter_T>
class stride_iter
{
public:
  // public typedefs
  typedef typename std::iterator_traits<Iter_T>::value_type value_type;
  typedef typename std::iterator_traits<Iter_T>::reference reference;
  typedef typename std::iterator_traits<Iter_T>::difference_type
    difference_type;
  typedef typename std::iterator_traits<Iter_T>::pointer pointer;
  typedef std::random_access_iterator_tag iterator_category;
  typedef stride_iter self;

  // constructors
  stride_iter( ) : m(NULL), step(0) { };
  stride_iter(const self& x) : m(x.m), step(x.step) { }
  stride_iter(Iter_T x, difference_type n) : m(x), step(n) { }

  // operators
  self& operator++( ) { m += step; return *this; }
  self operator++(int) { self tmp = *this; m += step; return tmp; }
  self& operator+=(difference_type x) { m += x * step; return *this; }
  self& operator--( ) { m -= step; return *this; }
  self operator--(int) { self tmp = *this; m -= step; return tmp; }
  self& operator-=(difference_type x) { m -= x * step; return *this; }
  reference operator[](difference_type n) { return m[n * step]; }
  reference operator*( ) { return *m; }

  // friend operators
  friend bool operator==(const self& x, const self& y) {
    assert(x.step == y.step);
    return x.m == y.m;
  }
  friend bool operator!=(const self& x, const self& y) {
    assert(x.step == y.step);
    return x.m != y.m;
  }
  friend bool operator<(const self& x, const self& y) {
    assert(x.step == y.step);
    return x.m < y.m;
  }
  friend difference_type operator-(const self& x, const self& y) {
    assert(x.step == y.step);
    return (x.m - y.m) / x.step;
  }
  friend self operator+(const self& x, difference_type y) {
    assert(x.step == y.step);
    return x += y * x.step;
  }
  friend self operator+(difference_type x, const self& y) {
    assert(x.step == y.step);
    return y += x * x.step;
  }
private:
  Iter_T m;
  difference_type step;
};


/*
template<class Iter_T, class Iter2_T>
double vectorDistance(Iter_T first, Iter_T last, Iter2_T first2) {
  double ret = 0.0;
  while (first != last) {
    double dist = (*first++) - (*first2++);
    ret += dist * dist;
  }
  return ret > 0.0 ? sqrt(ret) : 0.0;
}
*/

template<class Value_T>
class matrix
{
public:
  // public typedefs
  typedef Value_T value_type;
  typedef matrix self;
  typedef value_type* iterator;
  typedef const value_type* const_iterator;
  typedef Value_T* row_type;
  typedef stride_iter< value_type* > col_type;
  typedef const value_type* const_row_type;
  typedef stride_iter<const value_type*> const_col_type;

  // constructors
  matrix( ) : nrows(0), ncols(0), m( ) { }
  matrix(int r, int c) : nrows(r), ncols(c), m(r * c) { }
  matrix(const self& x) : m(x.m), nrows(x.nrows), ncols(x.ncols) { }

  template<typename T>
  explicit matrix(const std::valarray<T>& x)  
  : m(x.size( ) + 1), nrows(x.size( )), ncols(1) 
  {
    for (int i=0; i<x.size( ); ++i) m[i] = x[i];
  }
 
  // allow construction from matricies of other types
  template<typename T>
  explicit matrix(const matrix<T>& x) 
  : m(x.size( ) + 1), nrows(x.nrows), ncols(x.ncols) 
  {
    copy(x.begin( ), x.end( ), m.begin( ));
  }

  // public functions
  int rows( ) const { return nrows; }
  int cols( ) const { return ncols; }
  int size( ) const { return nrows * ncols; }

  // element access
  row_type row_begin(int n) { return &m[n * cols( )]; }
  row_type row_end(int n) { return row_begin( ) + cols( ); }
  col_type col_begin(int n) { return col_type(&m[n], cols( )); }
  col_type col_end(int n) { return col_begin(n) + cols( ); }
  const_row_type row_begin(int n) const { return &m[n * cols( )]; }
  const_row_type row_end(int n) const { return row_begin( ) + cols( ); }
  const_col_type col_begin(int n) const { return col_type(&m[n], cols( )); }
  const_col_type col_end(int n) const { return col_begin( ) + cols( ); }
  iterator begin( ) { return &m[0]; }
  iterator end( ) { return begin( ) + size( ); }
  const_iterator begin( ) const { return &m[0]; }
  const_iterator end( ) const { return begin( ) + size( ); }

  // operators
  self& operator=(const self& x) { 
    m = x.m; nrows = x.nrows; ncols = x.ncols; return *this; 
  }
  self& operator=(value_type x) { m = x; return *this; }
  row_type operator[](int n) { return row_begin(n); }
  const_row_type operator[](int n) const { return row_begin(n); }
  self& operator+=(const self& x) { m += x.m; return *this; }
  self& operator-=(const self& x) { m -= x.m; return *this; }
  self& operator+=(value_type x) { m += x; return *this; }
  self& operator-=(value_type x) { m -= x; return *this; }
  self& operator*=(value_type x) { m *= x; return *this; }
  self& operator/=(value_type x) { m /= x; return *this; }
  self& operator%=(value_type x) { m %= x; return *this; }
  self operator-( ) { return -m; }
  self operator+( ) { return +m; }
  self operator!( ) { return !m; }
  self operator~( ) { return ~m; }

  // friend operators
  friend self operator+(const self& x, const self& y) { return self(x) += y; }
  friend self operator-(const self& x, const self& y) { return self(x) -= y; }
  friend self operator+(const self& x, value_type y) { return self(x) += y; }
  friend self operator-(const self& x, value_type y) { return self(x) -= y; }
  friend self operator*(const self& x, value_type y) { return self(x) *= y; }
  friend self operator/(const self& x, value_type y) { return self(x) /= y; }
  friend self operator%(const self& x, value_type y) { return self(x) %= y; }
private:
	mutable std::valarray<Value_T> m;
  int nrows;
  int ncols;
};

/*

//exemplo

#include <iostream>

using namespace std;

int main( ) {
  matrix<int> m(2,2);
  m = 0;
  m[0][0] = 1;
  m[1][1] = 1;
  m *= 2;
  cout << "(" << m[0][0] << "," << m[0][1] << ")" << endl;
  cout << "(" << m[1][0] << "," << m[1][1] << ")" << endl;
}
*/

#endif
