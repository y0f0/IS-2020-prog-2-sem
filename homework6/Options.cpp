#include "Options.h"

void Functions::rotate(char &a, char &b, char &c, char &d) {
  char temp1 = a;
  a = b;
  char temp2 = c;
  c = temp1;
  temp1 = d;
  d = temp2;
  b = temp1;
}

void Functions::turn_front(std::ofstream &output) {
  Parts flow{};

  flow.a = front.a;
  flow.b = front.b;
  flow.c = front.c;
  flow.d = front.d;
  flow.e = front.e;
  flow.f = front.f;
  flow.g = front.g;
  flow.h = front.h;
  flow.i = front.i;

  front.a = flow.g;
  front.b = flow.d;
  front.c = flow.a;
  front.d = flow.h;
  front.e = flow.e;
  front.f = flow.b;
  front.g = flow.i;
  front.h = flow.f;
  front.i = flow.c;

  rotate(right.g, up.i, down.a, left.c);
  rotate(right.d, up.h, down.b, left.f);
  rotate(right.a, up.g, down.c, left.i);

  output << "Turn front" << std::endl;
}

void Functions::turn_hatch_front(std::ofstream &output) {
  Parts flow{};

  flow.a = front.a;
  flow.b = front.b;
  flow.c = front.c;
  flow.d = front.d;
  flow.e = front.e;
  flow.f = front.f;
  flow.g = front.g;
  flow.h = front.h;
  flow.i = front.i;

  front.a = flow.c;
  front.b = flow.f;
  front.c = flow.i;
  front.d = flow.b;
  front.e = flow.e;
  front.f = flow.h;
  front.g = flow.a;
  front.h = flow.d;
  front.i = flow.g;

  rotate(up.i, right.g, left.c, down.a);
  rotate(up.h, right.d, left.f, down.b);
  rotate(up.g, right.a, left.i, down.c);

  output << "Turn hatch front" << std::endl;
}

void Functions::turn_back(std::ofstream &output) {
  Parts flow{};

  flow.a = back.a; flow.b = back.b; flow.c = back.c;
  flow.d = back.d; flow.e = back.e; flow.f = back.f;
  flow.g = back.g; flow.h = back.h; flow.i = back.i;

  back.a = flow.g; back.b = flow.d; back.c = flow.a;
  back.d = flow.h; back.e = flow.e; back.f = flow.b;
  back.g = flow.i; back.h = flow.f; back.i = flow.c;

  rotate(left.a, up.c, down.g, right.i);
  rotate(left.d, up.b, down.h, right.f);
  rotate(left.g, up.a, down.i, right.c);

  output << "Turn back" << std::endl;
}

void Functions::turn_hatch_back(std::ofstream &output) {
  Parts flow{};

  flow.a = back.a;
  flow.b = back.b;
  flow.c = back.c;
  flow.d = back.d;
  flow.e = back.e;
  flow.f = back.f;
  flow.g = back.g;
  flow.h = back.h;
  flow.i = back.i;

  back.a = flow.c;
  back.b = flow.f;
  back.c = flow.i;
  back.d = flow.b;
  back.e = flow.e;
  back.f = flow.h;
  back.g = flow.a;
  back.h = flow.d;
  back.i = flow.g;

  rotate(right.i, up.c, down.g, left.a);
  rotate(right.f, up.b, down.h, left.d);
  rotate(right.c, up.a, down.i, left.g);

  output << "Turn hatch back" << std::endl;
}

void Functions::turn_left(std::ofstream &output) {
  Parts flow{};

  flow.a = left.a;
  flow.b = left.b;
  flow.c = left.c;
  flow.d = left.d;
  flow.e = left.e;
  flow.f = left.f;
  flow.g = left.g;
  flow.h = left.h;
  flow.i = left.i;

  left.a = flow.g;
  left.b = flow.d;
  left.c = flow.a;
  left.d = flow.h;
  left.e = flow.e;
  left.f = flow.b;
  left.g = flow.i;
  left.h = flow.f;
  left.i = flow.c;

  rotate(up.a, back.a, front.a, down.a);
  rotate(up.d, back.d, front.d, down.d);
  rotate(up.g, back.g, front.g, down.g);

  output << "Turn left" << std::endl;
}

void Functions::turn_hatch_left(std::ofstream &output) {
  Parts flow{};

  flow.a = left.a;
  flow.b = left.b;
  flow.c = left.c;
  flow.d = left.d;
  flow.e = left.e;
  flow.f = left.f;
  flow.g = left.g;
  flow.h = left.h;
  flow.i = left.i;

  left.a = flow.c;
  left.b = flow.f;
  left.c = flow.i;
  left.d = flow.b;
  left.e = flow.e;
  left.f = flow.h;
  left.g = flow.a;
  left.h = flow.d;
  left.i = flow.g;

  rotate(up.a, front.a, back.a, down.a);
  rotate(up.d, front.d, back.d, down.d);
  rotate(up.g, front.g, back.g, down.g);

  output << "Turn hatch left" << std::endl;
}

void Functions::turn_right(std::ofstream &output) {
  Parts flow{};

  flow.a = right.a;
  flow.b = right.b;
  flow.c = right.c;
  flow.d = right.d;
  flow.e = right.e;
  flow.f = right.f;
  flow.g = right.g;
  flow.h = right.h;
  flow.i = right.i;

  right.a = flow.g;
  right.b = flow.d;
  right.c = flow.a;
  right.d = flow.h;
  right.e = flow.e;
  right.f = flow.b;
  right.g = flow.i;
  right.h = flow.f;
  right.i = flow.c;

  rotate(up.c, front.c, back.c, down.c);
  rotate(up.f, front.f, back.f, down.f);
  rotate(up.i, front.i, back.i, down.i);

  output << "Turn right" << std::endl;
}

void Functions::turn_hatch_right(std::ofstream &output) {
  Parts flow{};

  flow.a = right.a;
  flow.b = right.b;
  flow.c = right.c;
  flow.d = right.d;
  flow.e = right.e;
  flow.f = right.f;
  flow.g = right.g;
  flow.h = right.h;
  flow.i = right.i;

  right.a = flow.c;
  right.b = flow.f;
  right.c = flow.i;
  right.d = flow.b;
  right.e = flow.e;
  right.f = flow.h;
  right.g = flow.a;
  right.h = flow.d;
  right.i = flow.g;

  rotate(up.c, back.c, front.c, down.c);
  rotate(up.f, back.f, front.f, down.f);
  rotate(up.i, back.i, front.i, down.i);

  output << "Turn hatch right" << std::endl;
}

void Functions::turn_up(std::ofstream &output) {
  Parts flow{};

  flow.a = up.a;
  flow.b = up.b;
  flow.c = up.c;
  flow.d = up.d;
  flow.e = up.e;
  flow.f = up.f;
  flow.g = up.g;
  flow.h = up.h;
  flow.i = up.i;

  up.a = flow.g;
  up.b = flow.d;
  up.c = flow.a;
  up.d = flow.h;
  up.e = flow.e;
  up.f = flow.b;
  up.g = flow.i;
  up.h = flow.f;
  up.i = flow.c;

  rotate(front.a, right.a, left.a, back.i);
  rotate(front.b, right.b, left.b, back.h);
  rotate(front.c, right.c, left.c, back.g);

  output << "Turn up" << std::endl;
}

void Functions::turn_hatch_up(std::ofstream &output) {
  Parts flow{};

  flow.a = up.a;
  flow.b = up.b;
  flow.c = up.c;
  flow.d = up.d;
  flow.e = up.e;
  flow.f = up.f;
  flow.g = up.g;
  flow.h = up.h;
  flow.i = up.i;

  up.a = flow.c;
  up.b = flow.f;
  up.c = flow.i;
  up.d = flow.b;
  up.e = flow.e;
  up.f = flow.h;
  up.g = flow.a;
  up.h = flow.d;
  up.i = flow.g;

  rotate(right.a, front.a, back.i, left.a);
  rotate(right.b, front.b, back.h, left.b);
  rotate(right.c, front.c, back.g, left.c);

  output << "Turn hatch up" << std::endl;
}

void Functions::turn_down(std::ofstream &output) {
  Parts flow{};

  flow.a = down.a;
  flow.b = down.b;
  flow.c = down.c;
  flow.d = down.d;
  flow.e = down.e;
  flow.f = down.f;
  flow.g = down.g;
  flow.h = down.h;
  flow.i = down.i;

  down.a = flow.c;
  down.b = flow.f;
  down.c = flow.i;
  down.d = flow.b;
  down.e = flow.e;
  down.f = flow.h;
  down.g = flow.a;
  down.h = flow.d;
  down.i = flow.g;

  rotate(front.g, right.g, left.g, back.c);
  rotate(front.h, right.h, left.h, back.b);
  rotate(front.i, right.i, left.i, back.a);

  output << "Turn down" << std::endl;
}

void Functions::turn_hatch_down(std::ofstream &output) {
  Parts flow{};

  flow.a = down.a;
  flow.b = down.b;
  flow.c = down.c;
  flow.d = down.d;
  flow.e = down.e;
  flow.f = down.f;
  flow.g = down.g;
  flow.h = down.h;
  flow.i = down.i;

  down.a = flow.g;
  down.b = flow.d;
  down.c = flow.a;
  down.d = flow.h;
  down.e = flow.e;
  down.f = flow.b;
  down.g = flow.i;
  down.h = flow.f;
  down.i = flow.c;

  rotate(right.g, front.g, back.c, left.g);
  rotate(right.h, front.h, back.b, left.h);
  rotate(right.i, front.i, back.a, left.i);

  output << "Turn hatch down" << std::endl;
}