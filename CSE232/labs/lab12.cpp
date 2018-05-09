#ifndef MYVECTOR
#define MYVECTOR

#include<cstdlib>
#include<ostream>
using std::ostream;
#include<algorithm>
using std::copy; using std::swap;
#include<iterator>
using std::begin; using std::end; using std::ostream_iterator;
#include<stdexcept>
using std::range_error;
#include<initializer_list>
using std::initializer_list;

namespace student{
  template<typename T>
  class vector{
    private:
      T *data_;
      size_t capacity_;
      size_t size_;
    public:
      vector(size_t cap=10) : capacity_(cap), size_(0)
           {data_ = new T[cap];};
      vector(initializer_list<T> il) : capacity_(il.size() ), size_(il.size() )
           {data_ = new T[il.size() ]; copy(il.begin(), il.end(), data_); };
      ~vector() {delete [] data_;};
      size_t capacity(){return capacity_;};
      size_t size(){return size_;};
      vector<T> (vector<T> &v);
      vector<T>& operator=(vector<T> v);
      void push_back(T );
      T& operator[](size_t);
      T front();
      T back();
      void clear();
      T pop_back();
    };

  template<typename T>
  vector<T>::vector(vector<T>& v){
    capacity_ = v.capacity_;
    size_ = v.size_;
    data_ = new T[capacity_];
    // Copy old array to new array
    copy(v.data_, v.data_+v.size_, data_);
  }

  template<typename T>
  vector<T>& vector<T>::operator=(vector<T> v){
    capacity_ = v.capacity_;
    size_ = v.size_;
    // Swap pointers
    swap(v.data_, data_);
    return *this;
  }

  template<typename T>
  void vector<T>::push_back(T val){
    if (size_ == capacity_){
      capacity_ *= 2; // Double capacity
      T *new_data = new T[capacity_]; // New array with double capacity
      copy(data_, data_+size_, new_data); // Copy over
      swap(data_, new_data); // Swap pointers
      delete [] new_data; // Delete old array pointer (old since swapped)
    }
    data_[size_++] = val;
  }

    template<typename T>
    T& vector<T>::operator[](size_t indx){
      if (indx > size_-1)
        throw range_error("access out of range");
      else
        return data_[indx];
    }

    template<typename T>
    T vector<T>::front(){
      if (size_ != 0)
        return data_[0];
      else
        throw range_error("access out of range");
    }

    template<typename T>
    T vector<T>::back(){
    	if (size_ != 0)
  	  return data_[size_ - 1];
	else
          throw range_error("access out of range");
    }

    template<typename T>
    void vector<T>::clear(){
      delete [] data_;
      size_ = 0;
      capacity_ = 10;
      data_ = new T [capacity_];
    }

    template<typename T>
    T vector<T>::pop_back(){
      T *new_data;
      if (size_ == 0)
        throw range_error("access out of range");
      // Reduce size because unnecessary
      if(size_ == capacity_/2){
    	capacity_ = capacity_/2;
    	new_data = new T[capacity_];
    	copy(data_, data_+size_, new_data);
    	swap(data_, new_data);
    	delete [] new_data;
      }
      return data_[size_--];
    }
}

#endif