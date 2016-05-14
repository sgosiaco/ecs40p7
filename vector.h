#ifndef VECTOR_H
#define	VECTOR_H

#include <iostream>

using namespace std;

template <class T>
class Vector;

template <class T>
ostream& operator<<(ostream& os, const Vector<T>& vec);

template <class T>
class Vector
{
  private:
    int count, storage;
    T* array;
  protected:

  public:
    int size() const;
    int capacity() const;
    Vector<T>& operator=(const Vector<T>& vec);
    Vector<T>& operator+=(const Vector<T>& vec);
    Vector(const T* arr);
    Vector();
    ~Vector();
    friend ostream& operator<<<T>(ostream& os, const Vector& vec);
} ;  // class Vector
#include "vector.cpp"
#endif	// VECTOR_H
