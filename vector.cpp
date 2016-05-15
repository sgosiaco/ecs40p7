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
    if((count + vec.count) < (2 * storage))
      storage *= 2;
    else
      storage = count + vec.count;
    T* temp = array;
    array = new T[storage];
    for(int i = 0; i < count; i++)
      array[i] = temp[i];

    for(int j = 0; j < vec.count; j++)
      array[j + count] = vec.array[j];

    delete [] temp;
    count += vec.count;
  }
  else
  {
    for(int i = 0; i < vec.count; i++)
      array[i + count] = vec.array[i];
    count += vec.count;
  }
  return *this;
}

template <class T>
size_t Vector<T>::find(const Vector<T> in) const
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
Vector<T>& Vector<T>::insert(int start, const Vector<T> in)
{
  if((count + in.count) > storage)
  {
    while((count + in.count) > storage)
      storage *= 2;
    T* temp = array;
    array = new T[storage];
    for(int i = 0; i < start + 1; i++)
      array[i] = temp[i];
    for(int i = 0; i < in.count; i++)
      array[start + i] = in.array[i];
    for(int i = 0; i < count - start; i++)
      array[start + in.count + i] = temp[start + i];
    delete [] temp;
  }
  else
  {
    for(int i = storage - 1; i > start; i--)
      array[i] = array[i - in.count];
    for(int i = start; i < in.count + start; i++)
      array[i] = in.array[i - start];
  }
  count += in.count;
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
