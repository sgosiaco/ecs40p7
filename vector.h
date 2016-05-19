#ifndef VECTOR_H
#define	VECTOR_H

#include <iostream>
//replace const?
using namespace std;

template <class T>
class Vector;

template <class T>
class VectorIterator
{
  private:
    Vector<T> *vectorPtr;
    int position;
  protected:

  public:
    VectorIterator(Vector<T> *vp = NULL, int pos = 0);
    const VectorIterator<T>& operator++(int);
    bool operator!=(const VectorIterator<T>& rhs) const;
    const T operator*() const;
}; //VectorIterator

template <class T>
class ReverseVectorIterator
{
  private:
    Vector<T> *vectorPtr;
    int position;
  protected:

  public:
    ReverseVectorIterator(Vector<T> *vp = NULL, int pos = 0);
    const ReverseVectorIterator<T>& operator++(int);
    bool operator!=(const ReverseVectorIterator<T>& rhs) const;
    const T operator*() const;
}; //ReverseVectorIterator

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
    Vector(const Vector<T>& in);
    ~Vector();
    int size() const;
    int capacity() const;
    Vector<T>& operator=(const Vector<T>& vec);
    Vector<T>& operator+=(const Vector<T>& vec);
    size_t find(const Vector<T> in) const;
    const Vector<T> substr(int start, int length) const;
    Vector<T>& insert(int start, const Vector<T> in);
    Vector<T>& replace(int st, int len, const Vector<T> in, int sst, int slen);
    friend ostream& operator<<<T>(ostream& os, const Vector& vec);
    typedef VectorIterator<T> iterator;
    typedef ReverseVectorIterator<T> reverse_iterator;
    friend class VectorIterator<T>;
    friend class ReverseVectorIterator<T>;
    VectorIterator<T> begin();
    VectorIterator<T> end();
    ReverseVectorIterator<T> rbegin();
    ReverseVectorIterator<T> rend();
} ;  // class Vector
#include "vector.cpp"
#endif	// VECTOR_H
