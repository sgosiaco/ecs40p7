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
    //NEEDS TO BE IMPLEMENTED
  }
  return *this;
}

template <class T>
size_t Vector<T>::find(Vector<T> in) const
{
  int found = 1, insize = in.capacity();

  for(int i = 0; i < count; i++)
  {
    if(array[i] == in.array[0])
    {
      found = 1;
      for(int j = 0; j < insize; j++)
        if(array[i + j] != in.array[j])
          found = 0;
      if(found)
        return i;
    }
  }
  return (size_t)-1;
}

template <class T>
Vector<T> Vector<T>::substr(int start, int length)
{
  Vector<T> temp;
  temp.array = new T[length];
  for(int i = 0; i < length; i++)
    temp.array[i] = array[i + start];

  temp.count = temp.storage = length;
  return temp;
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
