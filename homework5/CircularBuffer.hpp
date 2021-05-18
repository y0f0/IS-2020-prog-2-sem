#pragma once
#include <iostream>
#include <exception>

template<typename T>
class CircularBuffer {
 private:
  T* data;
  int capacity;
  int head;
  int tail;
 public:
  class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
   private:
    T* iterator;
   public:
    using difference_type = typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    Iterator() : iterator(nullptr) {}
    explicit Iterator(T* it) : iterator(it) {}
    Iterator(const Iterator &other) : iterator(other.iterator) {}
    ~Iterator() = default;
    bool operator==(const Iterator& other) const { return iterator == other.iterator; }
    bool operator!=(const Iterator& other) const { return iterator != other.iterator; }
    T& operator*() const { return *iterator; }
    T* operator->() const { return iterator; }
    Iterator& operator++() { ++iterator; return *this; }
    Iterator operator++(T) { Iterator tmp(*this); ++iterator; return tmp; }
    Iterator& operator--() { --iterator; return *this; }
    Iterator operator--(T) { Iterator tmp(*this); --iterator; return tmp; }
    Iterator operator+(difference_type it) const { return Iterator(iterator + it); }
    Iterator operator-(difference_type it) const { return Iterator(iterator - it); }
    bool operator>(const Iterator& other) const { return iterator > other.iterator; }
    bool operator<(const Iterator& other) const { return iterator < other.iterator; }
    bool operator>=(const Iterator& other) const { return iterator >= other.iterator; }
    bool operator<=(const Iterator& other) const { return iterator <= other.iterator; }
    Iterator& operator+=(difference_type it) { iterator += it; return *this; }
    Iterator& operator-=(difference_type it) { iterator -= it; return *this; }
    T& operator[](difference_type i) const { return iterator[i]; }
    difference_type operator-(const Iterator& it) const { return iterator - it.iterator; }
    friend Iterator operator+(difference_type lhs, const Iterator& rhs) { return Iterator(lhs + rhs.iterator); }
    friend Iterator operator-(difference_type lhs, const Iterator& rhs) { return Iterator(lhs - rhs.iterator); }
  };

  Iterator begin() const {
    return Iterator(data);
  }

  Iterator end() const {
    return Iterator(data + head);
  }

  explicit CircularBuffer(int capacity = 1)
      : capacity(capacity)
      , head(0)
      , tail(0)
      , data(new T[capacity])
  {
    for (auto i = 0; i < capacity; ++i)
      data[i] = 0;
  }

  ~CircularBuffer() {
    delete[] data;
    capacity = 0;
    head = 0;
    tail = 0;
  }

  void addLast(T x) {
    if (tail >= capacity) {
      tail = 0;
    }
    if (head == capacity) {
      data[tail] = x;
    }
    else {
      T* new_data = new T[head + 1];
      for (auto i = 0; i < head; ++i) {
        new_data[i] = data[i];
      }
      new_data[head] = x;
      delete[] data;
      data = new_data;
      ++head;
    }
    tail++;
  }

  void delLast() {
    if (head == 0) {
      throw std::out_of_range("Empty array!");
    }
    T* new_data = new T[head - 1];
    for (auto i = 0; i < head - 1; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    --head;
  }

  void addFirst(T x) {
    if (head == capacity) {
      T* new_data = new T[head];
      new_data[0] = x;
      for (auto i = 1; i < head; ++i) {
        new_data[i] = data[i - 1];
      }
      delete[] data;
      data = new_data;
    }
    else {
      T* new_data = new T[head + 1];
      for (auto i = 1; i < head + 1; ++i) {
        new_data[i] = data[i - 1];
      }
      new_data[0] = x;
      delete[] data;
      data = new_data;
      ++head;
    }
  }

  void delFirst() {
    if (head == 0) {
      throw std::out_of_range("Empty array!");
    }
    T* new_data = new T[head - 1];
    for (auto i = 0; i < head; ++i) {
      new_data[i] = data[i + 1];
    }
    delete[] data;
    data = new_data;
    --head;
  }

  T& first() {
    if (head == 0) {
      throw std::out_of_range("Empty array!");
    }
    return data[0];
  }

  T& last() {
    if (head == 0) {
      throw std::out_of_range("Empty array!");
    }
    return data[head - 1];
  }

  void changeCapacity(int newCapacity) {
    if (newCapacity <= capacity) {
      throw std::bad_alloc();
    }
    T* new_data = new T[newCapacity];
    for (auto i = 0; i < head; ++i) {
      new_data[i] = data[i];
    }
    delete[] data;
    data = new_data;
    capacity = newCapacity;
    tail = head;
  }

  T& operator[](int index) const {
    if (index < 0 || index > head - 1) {
      throw (std::out_of_range("Index is out of range!"));
    }
    return data[index];
  }
};