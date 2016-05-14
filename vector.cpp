#include <iostream>

using namespace std;

template <class T>
Vector<T>::Vector()
{
  storage = count = 0;
  array = NULL;
}

template <class T>
Vector<T>::Vector(const T arr[])
{
  for(count = 0; arr[count] != 0; count++);
  storage = count;
  array = (T*) arr;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T> vec)
{
  count = vec.count;
  storage = vec.storage;
  array = new T[storage];
  for(int i = 0; i < storage; i++)
    array[i] = vec.array[i];
  return *this;
}

template <class T>
int Vector<T>::size() const
{
  return count;
}

template <class T>
int Vector<T>::capacity() const
{
  return storage;
}

template <class T>
ostream& operator<<(ostream& os, const Vector<T>& vec)
{
  for(int i = 0; i < vec.count; i++)
      os << vec.array[i];
  return os;
}
