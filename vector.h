#ifndef VECTOR_H
#define	VECTOR_H

#include <iostream>

using namespace std;

template <class T>
class Vector;

template <class T>
class VectorIterator
{
  private:
    Vector<T> *vectorPtr;
    int position;
    friend class Vector<T>;
  protected:

  public:
    VectorIterator(Vector<T> *vp = NULL, int pos = 0);
    VectorIterator<T>& operator++(int);
    bool operator!=(const VectorIterator<T>& rhs);
    T operator*();
};

template <class T>
ostream& operator<<(ostream& os, const Vector<T>& vec);

template <class T>
class Vector
{
  private:
    int count, storage;
    T* array;
    static const int TWO = 2;
  protected:

  public:
    Vector(const T* arr);
    Vector();
    ~Vector();
    int size() const;
    int capacity() const;
    Vector<T>& operator=(const Vector<T>& vec);
    Vector<T>& operator+=(const Vector<T>& vec);
    size_t find(const Vector<T> in) const;
    Vector<T> substr(int start, int length);
    Vector<T>& insert(int start, const Vector<T> in);
    Vector<T>& replace(int st, int len, Vector<T> in, int sst, int slen);
    friend ostream& operator<<<T>(ostream& os, const Vector& vec);
    typedef VectorIterator<T> iterator;
    friend class VectorIterator<T>;
    VectorIterator<T> begin();
    VectorIterator<T> end();
} ;  // class Vector
#include "vector.cpp"
#endif	// VECTOR_H
