#include "Polynomial.h"
#include <fstream>
#include <cmath>

using namespace std;

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

Polynomial Polynomial::operator-() const {
  Polynomial res = *this;
  for (int i = 0; i < res.n_; i++) {
    res.coefficients_[i] *= -1;
  }
  return res;
}

bool checkForEquality(const Polynomial &big, const Polynomial &small) {
  for (int i = 0; i < small.n_; i++)
    if (big.coefficients_[i] != small.coefficients_[i])
      return false;

  for (int i = small.n_; i < big.n_; i++)
    if (big.coefficients_[i] != 0)
      return false;

  return true;
}

bool operator==(const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs.n_ == 0 && rhs.n_ == 0)
    return true;
  else if (!(lhs.n_ && rhs.n_))
    return false;

  if (lhs.n_ > rhs.n_)
    return checkForEquality(lhs, rhs);

  return checkForEquality(rhs, lhs);
}

bool operator!=(const Polynomial &lhs, const Polynomial &rhs) {
  return !(lhs == rhs);
}

#define MIN(a, b) ((a<b) ? (a) : (b))
#define MAX(a, b) ((a>b) ? (a) : (b))

Polynomial getResultOfAddOrSubOperation(const Polynomial &lhs,
                                     const Polynomial &rhs, int operation) {
  if (lhs == Polynomial()) {
    return rhs;
  }
  if (rhs == Polynomial()) {
    return lhs;
  }
  auto res = Polynomial();
  res.min_d_ = MIN(lhs.min_d_, rhs.min_d_);
  res.max_d_= MAX(lhs.max_d_, rhs.max_d_);
  res.n_ = res.max_d_ - res.min_d_ + 1;
  res.coefficients_ = new int[res.n_];
  for (int i = res.min_d_; i <= res.max_d_; i++) {
    if (i <= lhs.max_d_ && i <= rhs.max_d_ && i >= lhs.min_d_
        && i >= rhs.min_d_) {
      res.coefficients_[i - res.min_d_] = lhs.coefficients_[i - lhs.min_d_]
                            + operation * rhs.coefficients_[i - rhs.min_d_];
    } else if (i <= lhs.max_d_ && i >= lhs.min_d_) {
      res.coefficients_[i - res.min_d_] = lhs.coefficients_[i - lhs.min_d_];
    } else if (i <= rhs.max_d_ && i >= rhs.min_d_) {
      res.coefficients_[i - res.min_d_] = rhs.coefficients_[i - rhs.min_d_];
    }
  }
  return res;
}

Polynomial operator+(const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs == Polynomial()) {
    return rhs;
  }
  if (rhs == Polynomial()) {
    return lhs;
  }

  return Polynomial(lhs) += rhs;
}


Polynomial operator-(const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs == Polynomial()) {
    return rhs;
  }
  if (rhs == Polynomial()) {
    return lhs;
  }

  return Polynomial(lhs) -= rhs;
}

Polynomial operator*(const Polynomial &lhs, const Polynomial &rhs) {
  if (lhs == Polynomial() || rhs == Polynomial()) {
    return Polynomial();
  }

  auto res = Polynomial();
  res.min_d_ = lhs.min_d_ + rhs.min_d_;
  res.max_d_= lhs.max_d_ + rhs.max_d_;
  res.n_ = res.max_d_ - res.min_d_ + 1;
  res.coefficients_ = new int[res.n_];
  for (int i = lhs.min_d_; i <= lhs.max_d_; i++) {
    for (int j = rhs.min_d_; j <= rhs.max_d_; j++) {
      res.coefficients_[i + j - res.min_d_] = 0;
    }
  }
  for (int i = lhs.min_d_; i <= lhs.max_d_; i++) {
    for (int j = rhs.min_d_; j <= rhs.max_d_; j++) {
      res.coefficients_[i + j - res.min_d_] += lhs.coefficients_[i - lhs.min_d_] * rhs.coefficients_[j - rhs.min_d_];
    }
  }
  return res;
}

//fixed function
Polynomial getValueOperationResult(const Polynomial& p, const int& value,
                                   char operation) {
  int *coefficients = new int[p.n_];
  for (int i = 0; i < p.n_; i++) {
    if (operation == '*')
      coefficients[i] = p.coefficients_[i] * value;
    else
      coefficients[i] = p.coefficients_[i] / value;
  }
  auto res = Polynomial();
  res.min_d_ = p.min_d_;
  res.max_d_ = p.max_d_;
  for (int i = 0; i < p.n_; i++) {
    if (coefficients[i] == 0)
      res.min_d_++;
    else
      break;
  }
  for (int i = p.n_ - 1; i >= 0; i--) {
    if (coefficients[i] == 0)
      res.max_d_--;
    else
      break;
  }
  res.n_ = res.max_d_ - res.min_d_ + 1;
  int *new_coefficients = new int[res.n_];
  for (int i = res.min_d_; i <= res.max_d_; i++)  {
    new_coefficients[i - res.min_d_] = coefficients[i - p.min_d_];
  }
  res.coefficients_ = new_coefficients;
  return res;
}

Polynomial operator*(const Polynomial& p, int value) {
  if (value == 1)
    return p;
  return Polynomial(p) *= value;
}

Polynomial operator*(int value, const Polynomial& p) {
  if (value == 1)
    return p;
  return Polynomial(p) *= value;
}

Polynomial Polynomial::operator/(int value) const {
  if (value == 1)
    return *this;
  return Polynomial(*this) /= value;
}

int& Polynomial::operator[](int i) {
  if (i < min_d_) {
    int *new_coeff = new int [max_d_ - i + 1];
    for (int j = 0; j < max_d_ - i + 1; j++) {
      new_coeff[j] = 0;
    }
    for (int j = 0; j < n_; j++) {
      new_coeff[max_d_ - i - n_] = coefficients_[j];
    }
    min_d_ = i;
    n_ = max_d_ - min_d_ + 1;
    coefficients_ = new_coeff;
  } else if (i > max_d_) {
    int *new_coeff = new int [i - min_d_ + 1];
    for (int j = 0; j < i - min_d_ + 1; j++) {
      new_coeff[j] = 0;
    }
    for (int j = 0; j < n_; j++) {
      new_coeff[j] = coefficients_[j];
    }
    max_d_ = i;
    n_ = max_d_ - min_d_ + 1;
    coefficients_ = new_coeff;
  }
  return this->coefficients_[i - min_d_];
}

int Polynomial::operator[](int i) const {
  if (i > max_d_ || i < min_d_) {
    return 0;
  }
  return this->coefficients_[i - min_d_];
}

std::ostream &operator<<(std::ostream &out, const Polynomial &polynomial) {
  if (polynomial.n_ == 0) {
    out << 0;
    return out;
  }
  int i = polynomial.n_ - 1; // index of coefficients NB: polnomial.coefficiends_[i] != 0
  int j = polynomial.max_d_; // current power

  if (j != 0) {
    if (polynomial.coefficients_[i] != 1 && polynomial.coefficients_[i] != -1) {
      out << polynomial.coefficients_[i];
    } else if (polynomial.coefficients_[i] == -1){
      out << "-";
    }

    if (j == 1) {
      out << "x";
    } else {
      out << "x^" << j;
    }
  } else {
    if (polynomial.coefficients_[i] > 0)
      out << "+" << polynomial.coefficients_[i];
    else
      out << polynomial.coefficients_[i];
  }

  for (i--, j--; i >= 0; i--, j--) {
    if (polynomial.coefficients_[i]) {
      if (j != 0) {
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
        if (j == 1) {
          out << "x";
        } else {
          out << "x^" << j;
        }
      } else {
        if (polynomial.coefficients_[i] > 0)
          out << "+" << polynomial.coefficients_[i];
        else
          out << polynomial.coefficients_[i];
      }
    }
  }
  return out;
}

std::istream &operator>>(std::istream &in, Polynomial &polynomial) {
  int min_d, max_d;
  in >> min_d >> max_d;
  int n = max_d - min_d + 1;
  int *coeff = new int[n];
  for (int i = 0; i < n; i++) {
    in >> coeff[i];
  }
  polynomial = Polynomial(min_d, max_d, coeff);
  return in;
}

double Polynomial::get(int value) {
  double res = 0;
  for (int i = n_ - 1, power = max_d_; i >= 0; i--, power--) {
    res += coefficients_[i] * pow(value + 0.0, power + 0.0);
  }
  return res;
}

Polynomial& Polynomial::operator*=(int value) {
  *this = getValueOperationResult(*this, value, '*');
  return *this;
}

Polynomial& Polynomial::operator/=(int value) {
  if (value == 0)
    throw invalid_argument("Error : division by zero");
  *this = getValueOperationResult(*this, value, '/');
  return *this;
}

Polynomial& Polynomial::operator+=(const Polynomial &other) {
  *this = getResultOfAddOrSubOperation(*this, other, 1);
  return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial &other) {
  *this = getResultOfAddOrSubOperation(*this, other, -1);
  return *this;
}
