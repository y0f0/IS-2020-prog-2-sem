#pragma once
#include <algorithm>
#include <exception>

//fixed std::min and MAX

template<typename T>
class CircularBuffer {
 public:
  int capacity;
  int size;
  int head;
  int tail;
  T* data;
  class Iterator {
   public:
    T* iterator;
    const CircularBuffer<T>* buffer;
    using iterator_category = std::random_access_iterator_tag;
    using value_type = T;
    using difference_type = int;
    using pointer = T*;
    using reference = T&;

    Iterator(pointer it, const CircularBuffer<T>* buffer1) : iterator(it), buffer(buffer1) {}
    Iterator(const Iterator &other) : iterator(other.iterator), buffer(other.buffer) {}
    ~Iterator() = default;

    bool operator==(const Iterator& other) const { return iterator == other.iterator; }
    bool operator!=(const Iterator& other) const { return iterator != other.iterator; }
    Iterator& operator++() { ++iterator; return *this; }
    Iterator& operator--() { --iterator; return *this; }
    Iterator operator+(int it) const { return Iterator(iterator + it, buffer); }
    Iterator operator-(int it) const { return Iterator(iterator - it, buffer); }
    bool operator>(const Iterator& other) const { return iterator > other.iterator; }
    bool operator<(const Iterator& other) const { return iterator < other.iterator; }
    difference_type operator-(const Iterator& it) const { return iterator - it.iterator; }
    reference operator*() const {
      return buffer->data[(buffer->tail + iterator - buffer->begin().iterator) % buffer->capacity];
    }
  };

  Iterator begin() const {
    return Iterator(data, this);
  }

  Iterator end() const {
    return Iterator(data + size, this);
  }

  explicit CircularBuffer(int capacity)
      : capacity(capacity)
      , size(0)
      , head(0)
      , tail(0)
      , data(new T[capacity])
  {
    for (auto i = 0; i < capacity; ++i)
      data[i] = 0;
  }

  ~CircularBuffer() {
    delete[] data;
    //fixed there is no point
  }
  //fixed O(1)
  void addLast(T x) {
    if (size == 0) {
      data[head] = x;
    } else {
      head = (head + 1) % capacity;
      data[head] = x;
    }
    size = std::min(size + 1, capacity);
  }

  void delLast() {
    data[head] = 0;
    head = (head + capacity - 1) % capacity;
    size = std::max(size - 1, 0);
  }

  void addFirst(T x) {
    if (size == 0) {
      data[tail] = x;
    } else {
      tail = (tail + capacity - 1) % capacity;
      data[tail] = x;
    }
    size = std::min(size + 1, capacity);
  }

  void delFirst() {
    data[tail] = 0;
    tail = (tail + 1) % capacity;
    size = std::max(size - 1, 0);
  }

  T& first() {
    return data[tail];
  }

  T& last() {
    return data[head];
  }

  void changeCapacity(int newCapacity) {
    if (newCapacity <= capacity) {
      throw std::bad_alloc();
    }
    T* new_data = new T[newCapacity];
    for (auto i = 0; i < capacity; ++i) {
      new_data[i] = data[(i + tail) % capacity];
    }
    delete[] data;
    data = new_data;
    tail = 0;
    head = capacity;
    capacity = newCapacity;
  }

  //fixed more information
  T& operator[](int index) const {
    if (size == 0) {
      throw std::out_of_range("Array is empty!");
    }
    if (index < 0)  {
      throw std::out_of_range("Index is out of range! The index is less than 0.");
    }
    if (index > size - 1) {
      throw std::out_of_range("Index is out of range! The index greater than " + std::to_string(size - 1));
    }
    return data[(tail + index) % capacity];
  }
};