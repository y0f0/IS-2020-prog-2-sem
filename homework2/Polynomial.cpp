#include "Polynomial.h"
#include <iostream>
#include <vector>

Polynomial::Polynomial()
  : min_d_(0),
    max_d_(0),
    n_(0),
    coefficients_(nullptr) {}

Polynomial::Polynomial(int min_d, int max_d, const int* coefficients)
  : min_d_(min_d),
    max_d_(max_d),
    n_(max_d - min_d + 1) {
  coefficients_ = new int [n_];
  for (int i = 0; i < n_; i++) {
    coefficients_[i] = coefficients[i];
  }
}

Polynomial::Polynomial(const Polynomial &other)
  : min_d_(other.min_d_),
    max_d_(other.max_d_),
    n_(other.n_) {
  coefficients_ = new int [n_];
  for (int i = 0; i < n_; i++) {
    coefficients_[i] = other.coefficients_[i];
  }
}

Polynomial &Polynomial::operator=(const Polynomial &other) {
  if (this == &other) {
    return *this;
  }
  delete []coefficients_;
  min_d_ = other.min_d_;
  max_d_ = other.max_d_;
  n_ = other.n_;
  coefficients_ = new int [n_];
  for (int i = 0; i < n_; i++) {
    coefficients_[i] = other.coefficients_[i];
  }
  return *this;
}

Polynomial::~Polynomial() {
  delete[] coefficients_;
}

bool operator==(const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs.min_d_ != rhs.min_d_ || lhs.max_d_ != rhs.max_d_) {
    return false;
  }
  for (int i = 0; i < lhs.n_; i++) {
    if (lhs.coefficients_[i] != rhs.coefficients_[i]) {
      return false;
    }
  }
  return true;
}

bool operator!=(const Polynomial &lhs, const Polynomial &rhs) {
  return !(lhs == rhs);
}

#define MIN(a, b) ((a<b) ? (a) : (b))
#define MAX(a, b) ((a>b) ? (a) : (b))

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs) {
  auto res = Polynomial();
  res.min_d_ = MIN(lhs.min_d_, rhs.min_d_);
  res.max_d_= MAX(lhs.min_d_, rhs.min_d_);
  res.n_ = res.max_d_ - res.min_d_ + 1;
  res.coefficients_ = new int[res.n_];
  for (int i = res.min_d_; i <= res.max_d_; i++) {
    if (i>=lhs.max_d_ && i>=rhs.max_d_ && i<=lhs.min_d_ && i<=rhs.min_d_) {
      res.coefficients_[i] = lhs.coefficients_[i] + rhs.coefficients_[i];
    } else if (i >= lhs.max_d_ && i <= lhs.min_d_) {
      res.coefficients_[i] = lhs.coefficients_[i];
    } else if (i >= rhs.max_d_ && i <= rhs.min_d_) {
      res.coefficients_[i] = rhs.coefficients_[i];
    }
  }
  return res;
}

Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs) {
  auto res = Polynomial();
  res.min_d_ = MIN(lhs.min_d_, rhs.min_d_);
  res.max_d_= MAX(lhs.min_d_, rhs.min_d_);
  res.n_ = res.max_d_ - res.min_d_ + 1;
  res.coefficients_ = new int[res.n_];
  for (int i = res.min_d_; i <= res.max_d_; i++) {
    if (i>=lhs.max_d_ && i>=rhs.max_d_ && i<=lhs.min_d_ && i<=rhs.min_d_) {
      res.coefficients_[i] = lhs.coefficients_[i] - rhs.coefficients_[i];
    } else if (i >= lhs.max_d_ && i <= lhs.min_d_) {
      res.coefficients_[i] = lhs.coefficients_[i];
    } else if (i >= rhs.max_d_ && i <= rhs.min_d_) {
      res.coefficients_[i] = -rhs.coefficients_[i];
    }
  }
  return res;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs) {
  auto res = Polynomial();
  res.min_d_ = MIN(lhs.min_d_, rhs.min_d_);
  res.max_d_= MAX(lhs.min_d_, rhs.min_d_);
  res.n_ = 2 * (res.max_d_  - res.min_d_) + 1;
  res.coefficients_ = new int[res.n_];
  for (int i = lhs.min_d_; i <= lhs.max_d_; i++) {
    for (int j = rhs.min_d_; j <= rhs.max_d_; j++) {
      res.coefficients_[i * j - res.min_d_] = lhs.coefficients_[i] * rhs.coefficients_[j];
    }
  }
  return res;
}


#define GetLeftOperationResult(p, value, operation) {       \
  int *coefficients = new int[p.n_];                        \
  for (int i = 0; i < p.n_; i++) {                          \
    coefficients[i] = p.coefficients_[i] operation value;   \
  }                                                         \
  return Polynomial(p.min_d_, p.max_d_, coefficients);      \
}

Polynomial operator+(const Polynomial &p, int value) {
  GetLeftOperationResult(p, value, +);
}

Polynomial operator-(const Polynomial &p, int value) {
  GetLeftOperationResult(p, value, -);
}

Polynomial operator*(const Polynomial &p, int value) {
  GetLeftOperationResult(p, value, *);
}

Polynomial operator/(const Polynomial &p, int value) {
  if (value == 0) {
    throw std::invalid_argument("Error: Zero division.");
  }
  GetLeftOperationResult(p, value, /);
}


#define GetRightOperationResult(p, value, operation) {      \
  int *coefficients = new int[p.n_];                        \
  for (int i = 0; i < p.n_; i++) {                          \
    coefficients[i] = value operation p.coefficients_[i];   \
  }                                                         \
  return Polynomial(p.min_d_, p.max_d_, coefficients);      \
}

Polynomial operator+(int value, const Polynomial & p) {
  GetRightOperationResult(p, value, +);
}

Polynomial operator-(int value, const Polynomial & p) {
  GetRightOperationResult(p, value, -);
}

Polynomial operator*(int value, const Polynomial & p) {
  GetRightOperationResult(p, value, *);
}

Polynomial operator/(int value, const Polynomial & p) {
  int *coefficients = new int[p.n_];
  for (int i = 0; i < p.n_; i++) {
    if (p.coefficients_[i]) {
      coefficients[i] = value / p.coefficients_[i];
    }
  }
  return Polynomial(p.min_d_, p.max_d_, coefficients);
}

int Polynomial::operator[](int i) const {
  if (i < 0 || i >= this->n_) {
    throw std::invalid_argument("Error: Invalid index coefficient of polynomial.");
  }
  return this->coefficients_[i];
}

std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial) {
  if (polynomial.n_ == 0) {
    out << 0;
    return out;
  }
  int startI = polynomial.n_ - 1;
  int startJ = polynomial.max_d_;
  while (polynomial.coefficients_[startI] == 0) {
    startI--;
    startJ--;
  }
  if (polynomial.coefficients_[startI] == -1) out << "-";
  else if (polynomial.coefficients_[startI] != 1) out  << polynomial.coefficients_[startI];

  if (startJ == 1) out << 'x';
  else if (startJ != 0) out << "x^" << startJ;

  for (int i = startI - 1, j = startJ - 1; i >= 0; i--, j--) {
    if (polynomial.coefficients_[i]) {
      if (j == 1) {
        if (polynomial.coefficients_[i] != 1 && polynomial.coefficients_[i] != -1) {
          if (polynomial.coefficients_[i] > 0)
            out << "+" << polynomial.coefficients_[i];
          else
            out << polynomial.coefficients_[i];
        } else if (polynomial.coefficients_[i] == 1){
          out << "+";
        } else {
          out << "-";
        }
        out << "x";
      } else if (j == 0) {
        if (polynomial.coefficients_[i] > 0) out << "+" << polynomial.coefficients_[i];
        else out << polynomial.coefficients_[i];
      } else {
        if (polynomial.coefficients_[i] != 1) {
          if (polynomial.coefficients_[i] > 0)
            out << "+" << polynomial.coefficients_[i];
          else
            out << polynomial.coefficients_[i];
        } else if (polynomial.coefficients_[i] == 1){
          out << "+";
        } else {
          out << "-";
        }
        out << "x^" << j;
      }
    }
  }
  return out;
}

std::istream &operator>>(std::istream &in, Polynomial &polynomial) {
  int max_d, min_d, n;
  int *coefficient;
  int cur;
  std::vector<int> v;
  if (in.peek() == 'x') {
    v.push_back(1);
  }
  else if (in.peek() == '-') {
    in.ignore();
    if (in.peek() == 'x') {
      v.push_back(-1);
    }
    else {
      in >> cur;
      v.push_back(cur);
    }
  }
  else {
    in >> cur;
    v.push_back(cur);
  }
  in.ignore();  //x
  in.ignore();  //^
  in >> max_d; //power
  char c;
  while (in.get(c) && (c == '+' || c == '-')) {
    if (in.peek() == 'x') { //ones
      if (c == '-') {
        v.push_back(-1);
      }
      else {
        v.push_back(1);
      }
    }
    else {
      in >> cur;
      v.push_back(cur);
    }
    if (in.peek() == 'x') {
      in.ignore();  //x
      if (in.peek() == '^') {
        in.ignore(); //^
        in >> min_d;
      } else {
        min_d = 1;
      }
    } else {
      min_d = 0;
    }
  }
  n = max_d - min_d + 1;
  coefficient = new int[n];
  for (int i = 0; i < n; i++) {
    coefficient[i] = v[n - 1 - i];
  }
  polynomial = Polynomial(min_d, max_d, coefficient);
  return in;
}

Polynomial operator+=(const Polynomial &p, int value) { return p + value; }
Polynomial operator-=(const Polynomial &p, int value) { return p - value; }
Polynomial operator*=(const Polynomial &p, int value) { return p * value; }
Polynomial operator/=(const Polynomial &p, int value) { return p / value; }

Polynomial operator+=(int value, const Polynomial &p) { return value + p; }
Polynomial operator-=(int value, const Polynomial &p) { return value - p; }
Polynomial operator*=(int value, const Polynomial &p) { return value * p; }
Polynomial operator/=(int value, const Polynomial &p) { return value / p; }
