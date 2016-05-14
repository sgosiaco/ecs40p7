#include <iostream>

using namespace std;

template <class T>
Vector<T>::Vector()
{
  storage = count = 0;
  array = NULL;
}

template <class T>
Vector<T>::~Vector()
{
  delete [] array;
}

template <class T>
Vector<T>::Vector(const T arr[])
{
  for(count = 0; arr[count] != 0; count++);
  storage = count;
  array = new T[storage];

  for(int i = 0; i < storage; i++)
    array[i] = arr[i];
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
  if(this == &vec)
    return *this;

  count = vec.count;
  storage = vec.storage;
  if(array)
    delete [] array;

  array = new T[storage];

  for(int i = 0; i < storage; i++)
    array[i] = vec.array[i];

  return *this;
}

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vec)
{
  if((count + vec.count) > storage)
  {
    storage = count + vec.count;
    T* temp = array;
    array = new T[storage];
    for(int i = 0; i < count; i++)
      array[i] = temp[i];

    for(int j = count; j < storage; j++)
      array[j] = vec.array[j - count];

    delete [] temp;
    count = storage;
  }
  else
  {

  }
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
