#include "Instructions.h"

int Color [6];
void info_color(char c) {
  if (c == 'R')
    ++Color[0];
  else if (c == 'O')
    ++Color[1];
  else if (c == 'B')
    ++Color[2];
  else if (c == 'G')
    ++Color[3];
  else if (c == 'Y')
    ++Color[4];
  else if (c == 'W')
    ++Color[5];
}

void read(Functions &flow, std::ifstream &input) {
  char color;

  input >> color;
  info_color(color);
  flow.front.a = color;
  input >> color;
  info_color(color);
  flow.front.b = color;
  input >> color;
  info_color(color);
  flow.front.c = color;
  input >> color;
  info_color(color);
  flow.front.d = color;
  input >> color;
  info_color(color);
  flow.front.e = color;
  input >> color;
  info_color(color);
  flow.front.f = color;
  input >> color;
  info_color(color);
  flow.front.g = color;
  input >> color;
  info_color(color);
  flow.front.h = color;
  input >> color;
  info_color(color);
  flow.front.i = color;

  input >> color;
  info_color(color);
  flow.back.a = color;
  input >> color;
  info_color(color);
  flow.back.b = color;
  input >> color;
  info_color(color);
  flow.back.c = color;
  input >> color;
  info_color(color);
  flow.back.d = color;
  input >> color;
  info_color(color);
  flow.back.e = color;
  input >> color;
  info_color(color);
  flow.back.f = color;
  input >> color;
  info_color(color);
  flow.back.g = color;
  input >> color;
  info_color(color);
  flow.back.h = color;
  input >> color;
  info_color(color);
  flow.back.i = color;

  input >> color;
  info_color(color);
  flow.left.a = color;
  input >> color;
  info_color(color);
  flow.left.b = color;
  input >> color;
  info_color(color);
  flow.left.c = color;
  input >> color;
  info_color(color);
  flow.left.d = color;
  input >> color;
  info_color(color);
  flow.left.e = color;
  input >> color;
  info_color(color);
  flow.left.f = color;
  input >> color;
  info_color(color);
  flow.left.g = color;
  input >> color;
  info_color(color);
  flow.left.h = color;
  input >> color;
  info_color(color);
  flow.left.i = color;

  input >> color;
  info_color(color);
  flow.right.a = color;
  input >> color;
  info_color(color);
  flow.right.b = color;
  input >> color;
  info_color(color);
  flow.right.c = color;
  input >> color;
  info_color(color);
  flow.right.d = color;
  input >> color;
  info_color(color);
  flow.right.e = color;
  input >> color;
  info_color(color);
  flow.right.f = color;
  input >> color;
  info_color(color);
  flow.right.g = color;
  input >> color;
  info_color(color);
  flow.right.h = color;
  input >> color;
  info_color(color);
  flow.right.i = color;

  input >> color;
  info_color(color);
  flow.up.a = color;
  input >> color;
  info_color(color);
  flow.up.b = color;
  input >> color;
  info_color(color);
  flow.up.c = color;
  input >> color;
  info_color(color);
  flow.up.d = color;
  input >> color;
  info_color(color);
  flow.up.e = color;
  input >> color;
  info_color(color);
  flow.up.f = color;
  input >> color;
  info_color(color);
  flow.up.g = color;
  input >> color;
  info_color(color);
  flow.up.h = color;
  input >> color;
  info_color(color);
  flow.up.i = color;

  input >> color;
  info_color(color);
  flow.down.a = color;
  input >> color;
  info_color(color);
  flow.down.b = color;
  input >> color;
  info_color(color);
  flow.down.c = color;
  input >> color;
  info_color(color);
  flow.down.d = color;
  input >> color;
  info_color(color);
  flow.down.e = color;
  input >> color;
  info_color(color);
  flow.down.f = color;
  input >> color;
  info_color(color);
  flow.down.g = color;
  input >> color;
  info_color(color);
  flow.down.h = color;
  input >> color;
  info_color(color);
  flow.down.i = color;
}

void print(Functions &flow, std::ofstream &output) {
  output << std::endl;
  output << flow.front.a << flow.front.b << flow.front.c
         << flow.front.d << flow.front.e << flow.front.f <<
         flow.front.g << flow.front.h << flow.front.i << std::endl;

  output << flow.back.a << flow.back.b << flow.back.c
         << flow.back.d << flow.back.e << flow.back.f <<
         flow.back.g << flow.back.h << flow.back.i << std::endl;

  output << flow.left.a << flow.left.b << flow.left.c
         << flow.left.d << flow.left.e << flow.left.f <<
         flow.left.g << flow.left.h << flow.left.i << std::endl;

  output << flow.right.a << flow.right.b << flow.right.c
         << flow.right.d << flow.right.e << flow.right.f <<
         flow.right.g << flow.right.h << flow.right.i << std::endl;

  output << flow.up.a << flow.up.b << flow.up.c
         << flow.up.d << flow.up.e << flow.up.f <<
         flow.up.g << flow.up.h << flow.up.i << std::endl;

  output << flow.down.a << flow.down.b << flow.down.c
         << flow.down.d << flow.down.e << flow.down.f <<
         flow.down.g << flow.down.h << flow.down.i << std::endl;
  output << std::endl;
}

bool info_center(Functions &flow) {
  // Проверка на 9 цветов на грани
  for (int i : Color)
    if (i != 9) {
      return false;
    }

  return flow.front.e == 'R' && flow.back.e == 'O'
      && flow.up.e == 'Y' && flow.down.e == 'W'
      && flow.left.e == 'B' && flow.right.e == 'G';
}

void random(Functions &flow, std::ofstream &output) {
  srand( (unsigned)time(NULL) );
  int count = rand() % 10 + 1;
  int commands[count];

  for (int i = 0; i < count; ++i) {
    commands[i] = rand() % 12 + 1;
    if (commands[i] == 1)
      flow.turn_front(output);
    else if (commands[i] == 2)
      flow.turn_hatch_front(output);
    else if (commands[i] == 3)
      flow.turn_back(output);
    else if (commands[i] == 4)
      flow.turn_hatch_back(output);
    else if (commands[i] == 5)
      flow.turn_left(output);
    else if (commands[i] == 6)
      flow.turn_hatch_left(output);
    else if (commands[i] == 7)
      flow.turn_right(output);
    else if (commands[i] == 8)
      flow.turn_hatch_right(output);
    else if (commands[i] == 9)
      flow.turn_up(output);
    else if (commands[i] == 10)
      flow.turn_hatch_up(output);
    else if (commands[i] == 11)
      flow.turn_down(output);
    else if (commands[i] == 12)
      flow.turn_hatch_down(output);
  }
}

bool info_one_corner(Functions &flow) {
  return ((flow.up.i == 'Y' && flow.front.c == 'R' && flow.right.a == 'G')
      || (flow.up.i == 'Y' && flow.front.c == 'G' && flow.right.a == 'R')
      || (flow.up.i == 'R' && flow.front.c == 'Y' && flow.right.a == 'G')
      || (flow.up.i == 'R' && flow.front.c == 'G' && flow.right.a == 'Y')
      || (flow.up.i == 'G' && flow.front.c == 'R' && flow.right.a == 'Y')
      || (flow.up.i == 'G' && flow.front.c == 'Y' && flow.right.a == 'R')) ||
      ((flow.front.a == 'R' && flow.left.c == 'B' && flow.up.g == 'Y')
          || (flow.front.a == 'R' && flow.left.c == 'Y' && flow.up.g == 'B')
          || (flow.front.a == 'B' && flow.left.c == 'Y' && flow.up.g == 'R')
          || (flow.front.a == 'B' && flow.left.c == 'R' && flow.up.g == 'Y')
          || (flow.front.a == 'Y' && flow.left.c == 'B' && flow.up.g == 'R')
          || (flow.front.a == 'Y' && flow.left.c == 'R' && flow.up.g == 'B')) ||
      ((flow.up.c == 'Y' && flow.right.c == 'G' && flow.back.i == 'O')
          || (flow.up.c == 'Y' && flow.right.c == 'O' && flow.back.i == 'G')
          || (flow.up.c == 'G' && flow.right.c == 'Y' && flow.back.i == 'O')
          || (flow.up.c == 'G' && flow.right.c == 'O' && flow.back.i == 'Y')
          || (flow.up.c == 'O' && flow.right.c == 'G' && flow.back.i == 'Y')
          || (flow.up.c == 'O' && flow.right.c == 'Y' && flow.back.i == 'G')) ||
      ((flow.up.a == 'Y' && flow.back.g == 'O' && flow.left.a == 'B')
          || (flow.up.a == 'Y' && flow.back.g == 'B' && flow.left.a == 'O')
          || (flow.up.a == 'B' && flow.back.g == 'O' && flow.left.a == 'Y')
          || (flow.up.a == 'B' && flow.back.g == 'Y' && flow.left.a == 'O')
          || (flow.up.a == 'O' && flow.back.g == 'Y' && flow.left.a == 'B')
          || (flow.up.a == 'O' && flow.back.g == 'B' && flow.left.a == 'Y'));
}

bool info_all_corners(Functions &flow) {
  return ((flow.up.i == 'Y' && flow.front.c == 'R' && flow.right.a == 'G')
      || (flow.up.i == 'Y' && flow.front.c == 'G' && flow.right.a == 'R')
      || (flow.up.i == 'R' && flow.front.c == 'Y' && flow.right.a == 'G')
      || (flow.up.i == 'R' && flow.front.c == 'G' && flow.right.a == 'Y')
      || (flow.up.i == 'G' && flow.front.c == 'R' && flow.right.a == 'Y')
      || (flow.up.i == 'G' && flow.front.c == 'Y' && flow.right.a == 'R')) &&
      ((flow.front.a == 'R' && flow.left.c == 'B' && flow.up.g == 'Y')
          || (flow.front.a == 'R' && flow.left.c == 'Y' && flow.up.g == 'B')
          || (flow.front.a == 'B' && flow.left.c == 'Y' && flow.up.g == 'R')
          || (flow.front.a == 'B' && flow.left.c == 'R' && flow.up.g == 'Y')
          || (flow.front.a == 'Y' && flow.left.c == 'B' && flow.up.g == 'R')
          || (flow.front.a == 'Y' && flow.left.c == 'R' && flow.up.g == 'B')) &&
      ((flow.up.c == 'Y' && flow.right.c == 'G' && flow.back.i == 'O')
          || (flow.up.c == 'Y' && flow.right.c == 'O' && flow.back.i == 'G')
          || (flow.up.c == 'G' && flow.right.c == 'Y' && flow.back.i == 'O')
          || (flow.up.c == 'G' && flow.right.c == 'O' && flow.back.i == 'Y')
          || (flow.up.c == 'O' && flow.right.c == 'G' && flow.back.i == 'Y')
          || (flow.up.c == 'O' && flow.right.c == 'Y' && flow.back.i == 'G')) &&
      ((flow.up.a == 'Y' && flow.back.g == 'O' && flow.left.a == 'B')
          || (flow.up.a == 'Y' && flow.back.g == 'B' && flow.left.a == 'O')
          || (flow.up.a == 'B' && flow.back.g == 'O' && flow.left.a == 'Y')
          || (flow.up.a == 'B' && flow.back.g == 'Y' && flow.left.a == 'O')
          || (flow.up.a == 'O' && flow.back.g == 'Y' && flow.left.a == 'B')
          || (flow.up.a == 'O' && flow.back.g == 'B' && flow.left.a == 'Y'));
}

bool info_full(Functions &flow) {
  return flow.front.a == 'R' && flow.front.b == 'R' && flow.front.c == 'R' &&
      flow.front.d == 'R' && flow.front.e == 'R' && flow.front.f == 'R' &&
      flow.front.g == 'R' && flow.front.h == 'R' && flow.front.i == 'R' &&
      flow.back.a == 'O' && flow.back.b == 'O' && flow.back.c == 'O' &&
      flow.back.d == 'O' && flow.back.e == 'O' && flow.back.f == 'O' &&
      flow.back.g == 'O' && flow.back.h == 'O' && flow.back.i == 'O' &&
      flow.right.a == 'G' && flow.right.b == 'G' && flow.right.c == 'G' &&
      flow.right.d == 'G' && flow.right.e == 'G' && flow.right.f == 'G' &&
      flow.right.g == 'G' && flow.right.h == 'G' && flow.right.i == 'G' &&
      flow.left.a == 'B' && flow.left.b == 'B' && flow.left.c == 'B' &&
      flow.left.d == 'B' && flow.left.e == 'B' && flow.left.f == 'B' &&
      flow.left.g == 'B' && flow.left.h == 'B' && flow.left.i == 'B' &&
      flow.up.a == 'Y' && flow.up.b == 'Y' && flow.up.c == 'Y' &&
      flow.up.d == 'Y' && flow.up.e == 'Y' && flow.up.f == 'Y' &&
      flow.up.g == 'Y' && flow.up.h == 'Y' && flow.up.i == 'Y' &&
      flow.down.a == 'W' && flow.down.b == 'W' && flow.down.c == 'W' &&
      flow.down.d == 'W' && flow.down.e == 'W' && flow.down.f == 'W' &&
      flow.down.g == 'W' && flow.down.h == 'W' && flow.down.i == 'W';
}