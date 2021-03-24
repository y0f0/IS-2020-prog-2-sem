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

  Polynomial operator-() const;

  friend bool operator==(const Polynomial& lhs, const Polynomial& rhs);
  friend bool operator!=(const Polynomial& lhs, const Polynomial& rhs);

  friend Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs);
  friend Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs);
  friend Polynomial operator*(const Polynomial& lhs, const Polynomial& rhs);

  friend Polynomial operator*(const Polynomial& p, int value);
  friend Polynomial operator*(int value, const Polynomial& p);
  Polynomial operator/(int value) const;

  //fixed friend outside class

  //fixed inside class
  //fixed Polynomial&
  friend Polynomial& getValueOperationResult(Polynomial* p, const int& value,
                                             char operation);
  Polynomial& operator*=(int value);
  Polynomial& operator/=(int value);

  Polynomial& getResultOfAddOrSubOperation(const Polynomial& other,
                                                  int operation);
  Polynomial& operator+=(const Polynomial& other);
  Polynomial& operator-=(const Polynomial& other);

  int& operator[](int i);
  int operator[](int i) const;

  friend std::ostream& operator<<(std::ostream& out, const Polynomial &polynomial);
  friend std::istream& operator>>(std::istream& in, Polynomial &polynomial);

  double get(int value);
};


#endif //HOMEWORK2_POLYNOMIAL_H
