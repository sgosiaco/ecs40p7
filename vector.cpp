#include <iostream>

using namespace std;

template <class T>
VectorIterator<T>::VectorIterator(const Vector<T> *vp, int pos)
{
  vectorPtr = vp;
  position = pos;
} //con

template <class T>
const VectorIterator<T>& VectorIterator<T>::operator++(int)
{
  if((position + 1) < vectorPtr->size())
    position++;
  else //dne
    position = - 1;
  return *this;
} //++

template <class T>
bool VectorIterator<T>::operator!=(const VectorIterator<T>& rhs) const
{
  return position != rhs.position;
} //!=

template <class T>
const T VectorIterator<T>::operator*() const
{
  return vectorPtr->array[position];
} //deref

template <class T>
ReverseVectorIterator<T>::ReverseVectorIterator(const Vector<T> *vp, int pos)
{
  vectorPtr = vp;
  position = pos;
} //con

template <class T>
const ReverseVectorIterator<T>& ReverseVectorIterator<T>::operator++(int)
{
  if((position - 1) > -1)
    position--;
  else //dne
    position = - 1;
  return *this;
} //++

template <class T>
bool ReverseVectorIterator<T>::operator!=(const ReverseVectorIterator<T>& rhs)
const
{
  return position != rhs.position;
} //!=

template <class T>
const T ReverseVectorIterator<T>::operator*() const
{
  return vectorPtr->array[position];
} //deref

template <class T>
Vector<T>::Vector()
{
  storage = count = 0;
  array = NULL;
} //con

template <class T>
Vector<T>::~Vector()
{
  delete [] array;
} //decon

template <class T>
Vector<T>::Vector(const T arr[])
{
  for(count = 0; arr[count] != 0; count++);
  storage = count;
  array = new T[storage];

  for(int i = 0; i < storage; i++)
    array[i] = arr[i];
} //array con

template <class T>
Vector<T>::Vector(const Vector<T>& in)
{
  count = in.count;
  storage = in.storage;

  if(in.array)
  {
    array = new T[storage];

    for(int i = 0; i < storage; i++)
      array[i] = in.array[i];
  } //if
  else //no array
    array = NULL;
} //copy con

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
} //=

template <class T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& vec)
{
  if((count + vec.count) > storage)
  {
    if((count + vec.count) < (TWO * storage))
      storage *= TWO;
    else //exact
      storage = count + vec.count;
    T* temp = array;
    array = new T[storage];

    for(int i = 0; i < count; i++)
      array[i] = temp[i];

    for(int j = 0; j < vec.count; j++)
      array[j + count] = vec.array[j];

    delete [] temp;
    count += vec.count;
  } //if
  else //no resize
  {
    for(int i = 0; i < vec.count; i++)
      array[i + count] = vec.array[i];
    count += vec.count;
  } //else

  return *this;
} //+=

template <class T>
size_t Vector<T>::find(const Vector<T> in) const
{
  int found = 1, insize = in.capacity();

  for(int i = 0; i < count; i++)
  {
    if(array[i] == in.array[ 0 ])
    {
      found = 1;

      for(int j = 0; j < insize; j++)
        if(array[i + j] != in.array[j])
          found = 0;

      if(found)
        return i;
    } //if
  } //for

  return (size_t) - 1;
} //find()

template <class T>
const Vector<T> Vector<T>::substr(int start, int length) const
{
  Vector<T> temp;
  temp.array = new T[length];

  for(int i = 0; i < length; i++)
    temp.array[i] = array[i + start];

  temp.count = temp.storage = length;
  return temp;
} //substr()

template <class T>
Vector<T>& Vector<T>::insert(int start, const Vector<T> in)
{
  if((count + in.count) > storage)
  {
    while((count + in.count) > storage)
      storage *= TWO;
    T* temp = array;
    array = new T[storage];

    for(int i = 0; i < start + 1; i++)
      array[i] = temp[i];

    for(int i = 0; i < in.count; i++)
      array[start + i] = in.array[i];

    for(int i = 0; i < count - start; i++)
      array[start + in.count + i] = temp[start + i];
    delete [] temp;
  } //if
  else //no resize
  {
    for(int i = storage - 1; i > start; i--)
      array[i] = array[i - in.count];

    for(int i = start; i < in.count + start; i++)
      array[i] = in.array[i - start];
  } //else

  count += in.count;
  return *this;
} //insert()

template <class T>
Vector<T>&
Vector<T>::replace(int st, int len, const Vector<T> in, int sst, int slen)
{
  if((count - len + slen) > storage)
  {
    if((count - len + slen) < (TWO * storage))
      storage *= TWO;
    else //not more than double
      storage = count - len + slen;
    T* temp = array;
    array = new T[storage];

    for(int i = 0; i < count; i++)
      array[i] = temp[i];
    delete [] temp;
  } //if

  for(int i = count - st - len - 1; i > - 1; i--)
    array[st + slen + i] = array[st + len + i];

  for(int i = 0; i < slen; i++)
    array[st + i] = in.array[i + sst];
  count += (slen - len);
  return *this;
} //replace()

template <class T>
int Vector<T>::size() const
{
  return count;
} //size()

template <class T>
int Vector<T>::capacity() const
{
  return storage;
} //capacity()

template <class T>
ostream& operator<<(ostream& os, const Vector<T>& vec)
{
  for(int i = 0; i < vec.count; i++)
      os << vec.array[i];
  return os;
} //<<

template <class T>
VectorIterator<T> Vector<T>::begin() const
{
  return VectorIterator<T> (this, 0);
} //begin()

template <class T>
VectorIterator<T> Vector<T>::end() const
{
  return VectorIterator<T> (this, - 1);
} //end()

template <class T>
ReverseVectorIterator<T> Vector<T>::rbegin() const
{
  return ReverseVectorIterator<T> (this, count - 1);
} //rbegin()

template <class T>
ReverseVectorIterator<T> Vector<T>::rend() const
{
  return ReverseVectorIterator<T> (this, - 1);
} //rend()
