#pragma once

#include <iostream>
#include <fstream>

struct Parts {
  char a;
  char b;
  char c;
  char d;
  char e;
  char f;
  char g;
  char h;
  char i;
};

class Functions {
 public:
  Parts right;
  Parts left;
  Parts front;
  Parts back;
  Parts up;
  Parts down;

  void rotate(char &a, char &b, char &c, char &d);

  void turn_front(std::ofstream &output);

  void turn_hatch_front(std::ofstream &output);

  void turn_back(std::ofstream &output);

  void turn_hatch_back(std::ofstream &output);

  void turn_left(std::ofstream &output);

  void turn_hatch_left(std::ofstream &output);

  void turn_right(std::ofstream &output);

  void turn_hatch_right(std::ofstream &output);

  void turn_up(std::ofstream &output);

  void turn_hatch_up(std::ofstream &output);

  void turn_down(std::ofstream &output);

  void turn_hatch_down(std::ofstream &output);
};