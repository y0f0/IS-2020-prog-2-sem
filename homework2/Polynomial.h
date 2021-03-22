#ifndef HOMEWORK2_POLYNOMIAL_H
#define HOMEWORK2_POLYNOMIAL_H

#include <ostream>
#include <stdexcept>

class Polynomial {
private:
  int min_d_;
  int max_d_;
  int n_;
  int* coefficients_;
public:
  Polynomial();
  Polynomial(int min_d, int max_d, const int* coefficients);

  Polynomial(const Polynomial& other);
  Polynomial& operator=(const Polynomial& other);
  ~Polynomial();

  friend Polynomial& operator-(Polynomial& p);

  friend bool checkForEquality(const Polynomial& big, const Polynomial& small);
  friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
  friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

  friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
  friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
  friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

  friend Polynomial operator+(const Polynomial& p, int value);
  friend Polynomial operator-(const Polynomial& p, int value);
  friend Polynomial operator*(const Polynomial& p, int value);
  friend Polynomial operator/(const Polynomial& p, int value);

  //todo friend outside class
  friend Polynomial operator+(int value, const Polynomial& p  );
  friend Polynomial operator-(int value, const Polynomial& p);
  friend Polynomial operator*(int value, const Polynomial& p);
  friend Polynomial operator/(int value, const Polynomial& p);

  //todo inside class
  friend Polynomial operator+=(const Polynomial& p, int value);
  friend Polynomial operator-=(const Polynomial& p, int value);
  friend Polynomial operator*=(const Polynomial& p, int value);
  friend Polynomial operator/=(const Polynomial& p, int value);

  friend Polynomial operator+=(int value, const Polynomial& p);
  friend Polynomial operator-=(int value, const Polynomial& p);
  friend Polynomial operator*=(int value, const Polynomial& p);
  friend Polynomial operator/=(int value, const Polynomial& p);

  int& operator[](int i);
  int operator[](int i) const;

  friend std::ostream& operator<<(std::ostream& out, const Polynomial &polynomial);
  friend std::istream& operator>>(std::istream& in, Polynomial &polynomial);

  int* getCoefficients() const { return coefficients_; };
  int getN() const { return n_; };
  int getMinD() const { return min_d_; };
  int getMaxD() const { return max_d_; };
  double get(int value);
};


#endif //HOMEWORK2_POLYNOMIAL_H
