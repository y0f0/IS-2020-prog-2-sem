#include <functional>
#include <iostream>
using namespace std;

template<class InputIterator, class UnaryPredicate>
bool allOf (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first != last) {
    if (!pred(*first)) return false;
    ++first;
  }
  return true;
}

template<class InputIterator, class UnaryPredicate>
bool anyOf (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first != last) {
    if (pred(*first)) return true;
    ++first;
  }
  return false;
}

template<class InputIterator, class UnaryPredicate>
bool noneOf (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first != last) {
    if (pred(*first)) return false;
    ++first;
  }
  return true;
}

template<class InputIterator, class UnaryPredicate>
bool oneOf (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  bool flag = false;
  while (first != last) {
    if (pred(*first)) {
      if (flag) {
        return !flag;
      } else {
        flag = true;
      }
    }
    ++first;
  }
  return flag;
}

template <class ForwardIt, class Compare>
bool isSorted(ForwardIt first, ForwardIt last, Compare comp)
{
  if (first != last) {
    ForwardIt next = first;
    while (++next != last) {
      if (comp(*next, *first))
        return next == last;
      first = next;
    }
  }
  return true;
}

template<class ForwardIt>
bool isSorted(ForwardIt first, ForwardIt last)
{
  return isSorted(first, last, std::less<>());
}

template <class InputIterator, class UnaryPredicate>
bool isPartitioned (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last && pred(*first)) {
    ++first;
  }
  while (first!=last) {
    if (pred(*first)) return false;
    ++first;
  }
  return true;
}

template<class InputIterator, class T>
InputIterator findNot (InputIterator first, InputIterator last, const T& val)
{
  while (first!=last) {
    if (*first!=val) return first;
    ++first;
  }
  return last;
}

template<class InputIt, class T>
constexpr InputIt findBackward(InputIt first, InputIt last, const T& value)
{
  InputIt res = last;
  for (; first != last; ++first) {
    if (*first == value) {
      res = first;
    }
  }
  return res;
}

template<class InputIterator, class UnaryPredicate>
bool isPalindrome(InputIterator first, InputIterator last, UnaryPredicate pred)
{
  int len = 0;
  for (InputIterator it = first; it != last; it++) {
    len++;
  }
  for (int i = 0; first != last; first++, i++) {
    InputIterator it = first;
    for (int j = i; j < len - i - 1; j++) {
      it++;
    }
    if (!pred(*first, *it)) {
      return false;
    }
  }
  return true;
}
