#include "Solving.h"

void flower(Functions &flow, std::ofstream &output) {
  while (flow.up.b != 'W' || flow.up.d != 'W' || flow.up.f != 'W' || flow.up.h != 'W') {
    if (flow.front.f == 'W') {
      while (flow.up.f == 'W')
        flow.turn_up(output);
      flow.turn_right(output);
    }

    if (flow.front.d == 'W') {
      while (flow.up.d == 'W')
        flow.turn_up(output);
      flow.turn_hatch_left(output);
    }

    if (flow.right.d == 'W') {
      while (flow.up.h == 'W') {
        flow.turn_up(output);
      }
      flow.turn_hatch_front(output);
    }

    if (flow.right.f == 'W') {
      while (flow.up.b == 'W')
        flow.turn_up(output);
      flow.turn_back(output);
    }

    if (flow.left.f == 'W') {
      while (flow.up.h == 'W')
        flow.turn_up(output);
      flow.turn_front(output);
    }

    if (flow.left.d == 'W') {
      while (flow.up.b == 'W')
        flow.turn_up(output);
      flow.turn_hatch_back(output);
    }

    if (flow.back.f == 'W') {
      while (flow.up.f == 'W')
        flow.turn_up(output);
      flow.turn_hatch_right(output);
    }

    if (flow.back.d == 'W') {
      while (flow.up.d == 'W')
        flow.turn_up(output);
      flow.turn_left(output);
    }

    if (flow.down.f == 'W') {
      while (flow.up.f == 'W')
        flow.turn_up(output);
      flow.turn_right(output);
      flow.turn_right(output);
    }

    if (flow.down.h == 'W') {
      while (flow.up.b == 'W')
        flow.turn_up(output);
      flow.turn_hatch_back(output);
      flow.turn_hatch_back(output);
    }

    if (flow.down.d == 'W') {
      while (flow.up.d == 'W')
        flow.turn_up(output);
      flow.turn_hatch_left(output);
      flow.turn_hatch_left(output);
    }

    if (flow.down.b == 'W') {
      while (flow.up.h == 'W')
        flow.turn_up(output);
      flow.turn_front(output);
      flow.turn_front(output);
    }

    if (flow.front.h == 'W') {
      flow.turn_front(output);
      while (flow.up.d == 'W')
        flow.turn_up(output);
      flow.turn_hatch_left(output);
    }

    if (flow.front.b == 'W') {
      flow.turn_front(output);
      while (flow.up.f == 'W')
        flow.turn_up(output);
      flow.turn_right(output);
    }

    if (flow.right.h == 'W') {
      flow.turn_right(output);
      while (flow.up.h == 'W')
        flow.turn_up(output);
      flow.turn_hatch_front(output);
    }

    if (flow.right.b == 'W') {
      flow.turn_right(output);
      while (flow.up.b == 'W')
        flow.turn_up(output);
      flow.turn_back(output);
    }

    if (flow.back.b == 'W') {
      flow.turn_hatch_back(output);
      while (flow.up.d == 'W')
        flow.turn_up(output);
      flow.turn_left(output);
    }

    if (flow.back.h == 'W') {
      flow.turn_hatch_back(output);
      while (flow.up.f == 'W')
        flow.turn_up(output);
      flow.turn_hatch_right(output);
    }

    if (flow.left.h == 'W') {
      flow.turn_hatch_left(output);
      while (flow.up.h == 'W')
        flow.turn_up(output);
      flow.turn_front(output);
    }

    if (flow.left.b == 'W') {
      flow.turn_hatch_left(output);
      while (flow.up.b == 'W')
        flow.turn_up(output);
      flow.turn_hatch_back(output);
    }
  }
}

void right_cross(Functions &flow, std::ofstream &output) {
  while (flow.front.b != flow.front.e || flow.up.h != 'W')
    flow.turn_up(output);
  flow.turn_front(output);
  flow.turn_front(output);

  while (flow.right.b != flow.right.e || flow.up.f != 'W')
    flow.turn_up(output);
  flow.turn_right(output);
  flow.turn_right(output);

  while (flow.back.h != flow.back.e || flow.up.b != 'W')
    flow.turn_up(output);
  flow.turn_back(output);
  flow.turn_back(output);

  while (flow.left.b != flow.left.e || flow.up.d != 'W')
    flow.turn_up(output);
  flow.turn_left(output);
  flow.turn_left(output);
}

void first_layer(Functions &flow, std::ofstream &output) {
  while (flow.down.a != 'W' || flow.down.c != 'W' || flow.down.g != 'W' || flow.down.i != 'W') {
    // Первый угол
    if (flow.back.i == 'W') {
      if ((flow.up.c == 'G' && flow.right.c == 'O') || (flow.up.c == 'O' && flow.right.c == 'G')) {
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.c == 'G' && flow.right.c == 'R' && flow.back.i == 'W') || (flow.up.c == 'R' && flow.right.c == 'G' && flow.back.i == 'W')) {
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.c == 'R' && flow.right.c == 'B' && flow.back.i == 'W') || (flow.up.c == 'B' && flow.right.c == 'R' && flow.back.i == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.up.c == 'B' && flow.right.c == 'O' && flow.back.i == 'W') || (flow.up.c == 'O' && flow.right.c == 'B' && flow.back.i == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.up.c == 'W') {
      if ((flow.back.i == 'G' && flow.right.c == 'O') || (flow.back.i == 'O' && flow.right.c == 'G')) {
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.back.i == 'G' && flow.right.c == 'R' && flow.up.c == 'W') || (flow.back.i == 'R' && flow.right.c == 'G' && flow.up.c == 'W')) {
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.back.i == 'R' && flow.right.c == 'B' && flow.up.c == 'W') || (flow.back.i == 'B' && flow.right.c == 'R' && flow.up.c == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.back.i == 'B' && flow.right.c == 'O' && flow.up.c == 'W') || (flow.back.i == 'O' && flow.right.c == 'B' && flow.up.c == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.right.c == 'W') {
      if ((flow.up.c == 'G' && flow.back.i == 'O') || (flow.up.c == 'O' && flow.back.i == 'G')) {
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.up.c == 'G' && flow.back.i == 'R' && flow.right.c == 'W') || (flow.up.c == 'R' && flow.back.i == 'G' && flow.right.c == 'W')) {
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.up.c == 'R' && flow.back.i == 'B' && flow.right.c == 'W') || (flow.up.c == 'B' && flow.back.i == 'R' && flow.right.c == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }
      if ((flow.up.c == 'B' && flow.back.i == 'O' && flow.right.c == 'W') || (flow.up.c == 'O' && flow.back.i == 'B' && flow.right.c == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }
    // Второй угол
    if (flow.back.g == 'W') {
      if ((flow.up.a == 'G' && flow.left.a == 'O') || (flow.up.a == 'O' && flow.left.a == 'G')) {
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'G' && flow.left.a == 'R' && flow.back.g == 'W') || (flow.up.a == 'R' && flow.left.a == 'G' && flow.back.g == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'G' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'R' && flow.left.a == 'B' && flow.back.g == 'W') || (flow.up.a == 'B' && flow.left.a == 'R' && flow.back.g == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'B' && flow.left.a == 'O' && flow.back.g == 'W') || (flow.up.a == 'O' && flow.left.a == 'B' && flow.back.g == 'W')) {
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.up.a == 'W') {
      if ((flow.back.g == 'G' && flow.left.a == 'O') || (flow.back.g == 'O' && flow.left.a == 'G')) {
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.back.g == 'G' && flow.left.a == 'R' && flow.up.a == 'W') || (flow.back.g == 'R' && flow.left.a == 'G' && flow.up.a == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.back.g == 'R' && flow.left.a == 'B' && flow.up.a == 'W') || (flow.back.g == 'B' && flow.left.a == 'R' && flow.up.a == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.back.g == 'B' && flow.left.a == 'O' && flow.up.a == 'W') || (flow.back.g == 'O' && flow.left.a == 'B' && flow.up.a == 'W')) {
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.left.a == 'W') {
      if ((flow.up.a == 'G' && flow.back.g == 'O') || (flow.up.a == 'O' && flow.back.g == 'G')) {
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'G' && flow.back.g == 'R' && flow.left.a == 'W') || (flow.up.a == 'R' && flow.back.g == 'G' && flow.left.a == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'R' && flow.back.g == 'B' && flow.left.a == 'W') || (flow.up.a == 'B' && flow.back.g == 'R' && flow.left.a == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.a == 'B' && flow.back.g == 'O' && flow.left.a == 'W') || (flow.up.a == 'O' && flow.back.g == 'B' && flow.left.a == 'W')) {
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    // Третий угол
    if (flow.front.a == 'W') {
      if ((flow.up.g == 'G' && flow.left.c == 'O') || (flow.up.g == 'O' && flow.left.c == 'G')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'G' && flow.left.c == 'R' && flow.front.a == 'W') || (flow.up.g == 'R' && flow.left.c == 'G' && flow.front.a == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'R' && flow.left.c == 'B' && flow.front.a == 'W') || (flow.up.g == 'B' && flow.left.c == 'R' && flow.front.a == 'W')) {
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'B' && flow.left.c == 'O' && flow.front.a == 'W') || (flow.up.g == 'O' && flow.left.c == 'B' && flow.front.a == 'W')) {
        flow.turn_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.up.g == 'W') {
      if ((flow.front.a == 'G' && flow.left.c == 'O') || (flow.front.a == 'O' && flow.left.c == 'G')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.a == 'G' && flow.left.c == 'R' && flow.up.g == 'W') || (flow.front.a == 'R' && flow.left.c == 'G' && flow.up.g == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.a == 'R' && flow.left.c == 'B' && flow.up.g == 'W') || (flow.front.a == 'B' && flow.left.c == 'R' && flow.up.g == 'W')) {
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.a == 'B' && flow.left.c == 'O' && flow.up.g == 'W') || (flow.front.a == 'O' && flow.left.c == 'B' && flow.up.g == 'W')) {
        flow.turn_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.left.c == 'W') {
      if ((flow.up.g == 'G' && flow.front.a == 'O') || (flow.up.g == 'O' && flow.front.a == 'G')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'G' && flow.front.a == 'R' && flow.left.c == 'W') || (flow.up.g == 'R' && flow.front.a == 'G' && flow.left.c == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'R' && flow.front.a == 'B' && flow.left.c == 'W') || (flow.up.g == 'B' && flow.front.a == 'R' && flow.left.c == 'W')) {
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.g == 'B' && flow.front.a == 'O' && flow.left.c == 'W') || (flow.up.g == 'O' && flow.front.a == 'B' && flow.left.c == 'W')) {
        flow.turn_up(output);
        while (flow.down.g != 'W'|| flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }
    // Четвертый угол
    if (flow.front.c == 'W') {
      if ((flow.up.i == 'G' && flow.right.a == 'O') || (flow.up.i == 'O' && flow.right.a == 'G')) {
        flow.turn_hatch_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.i == 'G' && flow.right.a == 'R' && flow.front.c == 'W') || (flow.up.i == 'R' && flow.right.a == 'G' && flow.front.c == 'W')) {
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.i == 'R' && flow.right.a == 'B' && flow.front.c == 'W') || (flow.up.i == 'B' && flow.right.a == 'R' && flow.front.c == 'W')) {
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.up.i == 'B' && flow.right.a == 'O' && flow.front.c == 'W') || (flow.up.i == 'O' && flow.right.a == 'B' && flow.front.c == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.up.i == 'W') {
      if ((flow.front.c == 'G' && flow.right.a == 'O') || (flow.front.c == 'O' && flow.right.a == 'G')) {
        flow.turn_hatch_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'G' && flow.right.a == 'R' && flow.up.i == 'W') || (flow.front.c == 'R' && flow.right.a == 'G' && flow.up.i == 'W')) {
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'R' && flow.right.a == 'B' && flow.up.i == 'W') || (flow.front.c == 'B' && flow.right.a == 'R' && flow.up.i == 'W')) {
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'B' && flow.right.a == 'O' && flow.up.i == 'W') || (flow.front.c == 'O' && flow.right.a == 'B' && flow.up.i == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if (flow.right.a == 'W') {
      if ((flow.front.c == 'G' && flow.up.i == 'O' && flow.right.a == 'W') || (flow.front.c == 'O' && flow.up.i == 'G' && flow.right.a == 'W')) {
        flow.turn_hatch_up(output);
        while (flow.down.i != 'W' || flow.right.i != 'G' || flow.back.c != 'O') {
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'G' && flow.up.i == 'R' && flow.right.a == 'W') || (flow.front.c == 'R' && flow.up.i == 'G' && flow.right.a == 'W')) {
        while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'R' && flow.up.i == 'B' && flow.right.a == 'W') || (flow.front.c == 'B' && flow.up.i == 'R' && flow.right.a == 'W')) {
        flow.turn_up(output);
        while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
        }
      }

      if ((flow.front.c == 'B' && flow.up.i == 'O' && flow.right.a == 'W') || (flow.front.c == 'O' && flow.up.i == 'B' && flow.right.a == 'W')) {
        flow.turn_up(output);
        flow.turn_up(output);
        while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
        }
      }
    }

    if ((flow.front.i == 'W' && flow.right.g == 'G' && flow.down.c == 'R') || (flow.front.i == 'W' && flow.right.g == 'R' && flow.down.c == 'G') ||
        (flow.front.i == 'G' && flow.right.g == 'W' && flow.down.c == 'R') || (flow.front.i == 'R' && flow.right.g == 'W' && flow.down.c == 'G') ||
        (flow.front.i == 'G' && flow.right.g == 'R' && flow.down.c == 'W')) {
      while (flow.down.c != 'W' || flow.front.i != 'R' || flow.right.g != 'G') {
        flow.turn_right(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
        flow.turn_hatch_up(output);
      }
    }
    if ((flow.back.c == 'W' && flow.right.i == 'G' && flow.down.i == 'O') || (flow.back.c == 'W' && flow.right.i == 'O' && flow.down.i == 'G') ||
        (flow.back.c == 'G' && flow.right.i == 'W' && flow.down.i == 'O') || (flow.back.c == 'O' && flow.right.i == 'W' && flow.down.i == 'G') ||
        (flow.back.c == 'G' && flow.right.i == 'O' && flow.down.i == 'W')) {
      while (flow.down.i != 'W' || flow.back.c != 'O' || flow.right.i != 'G') {
        flow.turn_back(output);
        flow.turn_up(output);
        flow.turn_hatch_back(output);
        flow.turn_hatch_up(output);
      }
    }
    if ((flow.back.a == 'W' && flow.left.g == 'B' && flow.down.g == 'O') || (flow.back.a == 'W' && flow.left.g == 'O' && flow.down.g == 'B') ||
        (flow.back.a == 'B' && flow.left.g == 'W' && flow.down.g == 'O') || (flow.back.a == 'O' && flow.left.g == 'W' && flow.down.g == 'B') ||
        (flow.back.a == 'B' && flow.left.g == 'O' && flow.down.g == 'W')) {
      while (flow.down.g != 'W' || flow.back.a != 'O' || flow.left.g != 'B') {
        flow.turn_left(output);
        flow.turn_up(output);
        flow.turn_hatch_left(output);
        flow.turn_hatch_up(output);
      }
    }
    if ((flow.left.i == 'W' && flow.front.g == 'R' && flow.down.a == 'B') || (flow.left.i == 'W' && flow.front.g == 'B' && flow.down.a == 'R') ||
        (flow.left.i == 'R' && flow.front.g == 'W' && flow.down.a == 'B') || (flow.left.i == 'B' && flow.front.g == 'W' && flow.down.a == 'R') ||
        (flow.left.i == 'R' && flow.front.g == 'B' && flow.down.a == 'W')) {
      while (flow.down.a != 'W' || flow.left.i != 'B' || flow.front.g != 'R') {
        flow.turn_front(output);
        flow.turn_up(output);
        flow.turn_hatch_front(output);
        flow.turn_hatch_up(output);
      }
    }

    if ((flow.down.c == 'W' && (flow.front.i != 'R' && flow.front.i != 'G')) || (flow.down.c == 'W' && (flow.right.g != 'R' && flow.right.g != 'G'))) {
      flow.turn_right(output);
      flow.turn_up(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_up(output);
    }

    if ((flow.down.i == 'W' && (flow.right.i != 'O' && flow.right.i != 'G')) || (flow.down.i == 'W' && (flow.back.c != 'O' && flow.back.c != 'G'))) {
      flow.turn_back(output);
      flow.turn_up(output);
      flow.turn_hatch_back(output);
      flow.turn_hatch_up(output);
    }

    if ((flow.down.g == 'W' && (flow.back.a != 'O' && flow.back.a != 'B')) || (flow.down.g == 'W' && (flow.left.g != 'O' && flow.left.g != 'B'))) {
      flow.turn_left(output);
      flow.turn_up(output);
      flow.turn_hatch_left(output);
      flow.turn_hatch_up(output);
    }

    if ((flow.down.a == 'W' && (flow.front.g != 'R' && flow.front.g != 'B')) || (flow.down.a == 'W' && (flow.left.i != 'R' && flow.left.i != 'B'))) {
      flow.turn_front(output);
      flow.turn_up(output);
      flow.turn_hatch_front(output);
      flow.turn_hatch_up(output);
    }
  }
}

void middle_layer(Functions &flow, std::ofstream &output) {
  int pred;
  while (flow.front.d != 'R' || flow.front.f != 'R'  || flow.right.d != 'G' || flow.right.f != 'G' ||
      flow.back.f != 'O' || flow.back.d != 'O' || flow.left.d != 'B' || flow.left.f != 'B') {
    int count = 0;
    pred = -1;
    //сборка двух нижних рядов
    while (count > pred) {
      pred = count;
      if (flow.front.b == 'R' || flow.right.b == 'R'  || flow.back.h == 'R'  || flow.left.b == 'R' ) {
        while (flow.front.b != 'R' )
          flow.turn_up(output);
        if (flow.up.h == 'G') {
          count++;
          flow.turn_up(output);
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
          flow.turn_front(output);
          flow.turn_up(output);
        }
        else {
          if (flow.up.h == 'B') {
            count++;
            flow.turn_hatch_up(output);
            flow.turn_hatch_left(output);
            flow.turn_hatch_up(output);
            flow.turn_left(output);
            flow.turn_up(output);
            flow.turn_front(output);
            flow.turn_up(output);
            flow.turn_hatch_front(output);
            flow.turn_hatch_up(output);
          }
        }
      }

      if (flow.front.b == 'G' || flow.right.b == 'G' || flow.back.h == 'G' || flow.left.b == 'G') {
        while (flow.right.b != 'G')
          flow.turn_up(output);
        if (flow.up.f == 'O') {
          count++;
          flow.turn_up(output);
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
          flow.turn_right(output);
          flow.turn_up(output);
        }
        else {
          if (flow.up.f == 'R') {
            count++;
            flow.turn_hatch_up(output);
            flow.turn_hatch_front(output);
            flow.turn_hatch_up(output);
            flow.turn_front(output);
            flow.turn_up(output);
            flow.turn_right(output);
            flow.turn_up(output);
            flow.turn_hatch_right(output);
            flow.turn_hatch_up(output);
          }
        }
      }

      if (flow.front.b == 'O' || flow.right.b == 'O' || flow.back.h == 'O' || flow.left.b == 'O') {
        while (flow.back.h != 'O')
          flow.turn_up(output);
        if (flow.up.b == 'B') {
          count++;
          flow.turn_up(output);
          flow.turn_left(output);
          flow.turn_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
          flow.turn_back(output);
          flow.turn_up(output);
        }
        else {
          if (flow.up.b == 'G') {
            count++;
            flow.turn_hatch_up(output);
            flow.turn_hatch_right(output);
            flow.turn_hatch_up(output);
            flow.turn_right(output);
            flow.turn_up(output);
            flow.turn_back(output);
            flow.turn_up(output);
            flow.turn_hatch_back(output);
            flow.turn_hatch_up(output);
          }
        }
      }

      if (flow.front.b == 'B' || flow.right.b == 'B' || flow.back.h == 'B' || flow.left.b == 'B') {
        while (flow.left.b != 'B')
          flow.turn_up(output);
        if (flow.up.d == 'R' ) {
          count++;
          flow.turn_up(output);
          flow.turn_front(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_left(output);
          flow.turn_hatch_up(output);
          flow.turn_left(output);
          flow.turn_up(output);
        }
        else {
          if (flow.up.d == 'O') {
            count++;
            flow.turn_hatch_up(output);
            flow.turn_hatch_back(output);
            flow.turn_hatch_up(output);
            flow.turn_back(output);
            flow.turn_up(output);
            flow.turn_left(output);
            flow.turn_up(output);
            flow.turn_hatch_left(output);
            flow.turn_hatch_up(output);
          }
        }
      }
    }
    // добавляем ребра из 2 ряда
    if (flow.front.f != 'R') {
      flow.turn_right(output);
      flow.turn_up(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_up(output);
      flow.turn_hatch_front(output);
      flow.turn_hatch_up(output);
      flow.turn_front(output);
      flow.turn_up(output);
    }
    if (flow.right.f != 'G') {
      flow.turn_back(output);
      flow.turn_up(output);
      flow.turn_hatch_back(output);
      flow.turn_hatch_up(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_up(output);
      flow.turn_right(output);
      flow.turn_up(output);
    }
    if (flow.back.d != 'O') {
      flow.turn_left(output);
      flow.turn_up(output);
      flow.turn_hatch_left(output);
      flow.turn_hatch_up(output);
      flow.turn_hatch_back(output);
      flow.turn_hatch_up(output);
      flow.turn_back(output);
      flow.turn_up(output);
    }
    if (flow.left.f != 'B') {
      flow.turn_front(output);
      flow.turn_up(output);
      flow.turn_hatch_front(output);
      flow.turn_hatch_up(output);
      flow.turn_hatch_left(output);
      flow.turn_hatch_up(output);
      flow.turn_left(output);
      flow.turn_up(output);
    }
  }
}

void yellow_cross(Functions &flow, std::ofstream &output) {
  while (flow.up.d != 'Y' || flow.up.b != 'Y' || flow.up.f != 'Y' || flow.up.h != 'Y') {
    if ((flow.up.f == 'Y' && flow.up.b == 'Y') || (flow.up.b == 'Y' && flow.up.h == 'Y')) {
      flow.turn_left(output);
      flow.turn_front(output);
      flow.turn_up(output);
      flow.turn_hatch_front(output);
      flow.turn_hatch_up(output);
      flow.turn_hatch_left(output);
    }
    else {
      if (flow.up.f == 'Y' && flow.up.h == 'Y') {
        flow.turn_back(output);
        flow.turn_left(output);
        flow.turn_up(output);
        flow.turn_hatch_left(output);
        flow.turn_hatch_up(output);
        flow.turn_hatch_back(output);
      }
      else {
        if (flow.up.d == 'Y' && flow.up.h == 'Y') {
          flow.turn_right(output);
          flow.turn_back(output);
          flow.turn_up(output);
          flow.turn_hatch_back(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_right(output);
        }
        else {
          flow.turn_front(output);
          flow.turn_right(output);
          flow.turn_up(output);
          flow.turn_hatch_right(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_front(output);
        }
      }
    }
  }
  //проверка на правильный желтый крест
  bool checkY = false;
  if (flow.front.b == 'R'  && flow.right.b == 'G' && flow.back.h == 'O' && flow.left.b == 'B')
    checkY = true;
  else {
    flow.turn_up(output);
    if (flow.front.b == 'R'  && flow.right.b == 'G' && flow.back.h == 'O' && flow.left.b == 'B')
      checkY = true;
    else {
      flow.turn_up(output);
      if (flow.front.b == 'R'  && flow.right.b == 'G' && flow.back.h == 'O' && flow.left.b == 'B')
        checkY = true;
      else {
        flow.turn_up(output);
        if (flow.front.b == 'R'  && flow.right.b == 'G' && flow.back.h == 'O' && flow.left.b == 'B')
          checkY = true;
      }
    }
  }
  //в случае, если правильый желтый крест не готов :
  if (!checkY) {
    while (flow.front.b != 'R' || flow.right.b != 'G' || flow.back.h != 'O' || flow.left.b != 'B') {
      flow.turn_up(output);
      if (flow.right.b == 'G' && flow.back.h == 'O') {
        flow.turn_right(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
        flow.turn_up(output);
        flow.turn_right(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
        flow.turn_up(output);
        break;
      }
      if (flow.right.b == 'G' && flow.front.b == 'R' ) {
        flow.turn_front(output);
        flow.turn_up(output);
        flow.turn_hatch_front(output);
        flow.turn_up(output);
        flow.turn_front(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_front(output);
        flow.turn_up(output);
        break;
      }
      if (flow.front.b == 'R' && flow.left.b == 'B') {
        flow.turn_left(output);
        flow.turn_up(output);
        flow.turn_hatch_left(output);
        flow.turn_up(output);
        flow.turn_left(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_left(output);
        flow.turn_up(output);
        break;
      }
      if (flow.left.b == 'B' && flow.back.h == 'O') {
        flow.turn_back(output);
        flow.turn_up(output);
        flow.turn_hatch_back(output);
        flow.turn_up(output);
        flow.turn_back(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_back(output);
        flow.turn_up(output);
        break;
      }
      if (flow.right.b == 'G' && flow.left.b == 'B') {
        flow.turn_back(output);
        flow.turn_up(output);
        flow.turn_hatch_back(output);
        flow.turn_up(output);
        flow.turn_back(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_back(output);
      }
      if (flow.front.b == 'R' && flow.back.h == 'O') {
        flow.turn_right(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
        flow.turn_up(output);
        flow.turn_right(output);
        flow.turn_up(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
      }
    }
  }
}

void last_layer(Functions &flow, std::ofstream &output) {
  while (!info_all_corners(flow)) {
    if ((flow.up.i == 'Y' && flow.front.c == 'R'  && flow.right.a == 'G') || (flow.up.i == 'Y' && flow.front.c == 'G' && flow.right.a == 'R' ) ||
        (flow.up.i == 'R'  && flow.front.c == 'Y' && flow.right.a == 'G') || (flow.up.i == 'R'  && flow.front.c == 'G' && flow.right.a == 'Y') ||
        (flow.up.i == 'G' && flow.front.c == 'R'  && flow.right.a == 'Y') || (flow.up.i == 'G' && flow.front.c == 'Y' && flow.right.a == 'R' )) {
      while (!info_all_corners(flow)) {
        flow.turn_up(output);
        flow.turn_right(output);
        flow.turn_hatch_up(output);
        flow.turn_hatch_left(output);
        flow.turn_up(output);
        flow.turn_hatch_right(output);
        flow.turn_hatch_up(output);
        flow.turn_left(output);
      }
    }
    else {
      if ((flow.front.a == 'R'  && flow.left.c == 'B' && flow.up.g == 'Y') || (flow.front.a == 'R'  && flow.left.c == 'Y' && flow.up.g == 'B') ||
          (flow.front.a == 'B' && flow.left.c == 'Y' && flow.up.g == 'R' ) || (flow.front.a == 'B' && flow.left.c == 'R'  && flow.up.g == 'Y') ||
          (flow.front.a == 'Y' && flow.left.c == 'B' && flow.up.g == 'R' ) || (flow.front.a == 'Y' && flow.left.c == 'R'  && flow.up.g == 'B')) {
        while (!info_all_corners(flow)) {
          flow.turn_up(output);
          flow.turn_front(output);
          flow.turn_hatch_up(output);
          flow.turn_hatch_back(output);
          flow.turn_up(output);
          flow.turn_hatch_front(output);
          flow.turn_hatch_up(output);
          flow.turn_back(output);
        }
      }
      else {
        if ((flow.up.c == 'Y' && flow.right.c == 'G' && flow.back.i == 'O') || (flow.up.c == 'Y' && flow.right.c == 'O' && flow.back.i == 'G') ||
            (flow.up.c == 'G' && flow.right.c == 'Y' && flow.back.i == 'O') || (flow.up.c == 'G' && flow.right.c == 'O' && flow.back.i == 'Y') ||
            (flow.up.c == 'O' && flow.right.c == 'G' && flow.back.i == 'Y') || (flow.up.c == 'O' && flow.right.c == 'Y' && flow.back.i == 'G')) {
          while (!info_all_corners(flow)) {
            flow.turn_up(output);
            flow.turn_back(output);
            flow.turn_hatch_up(output);
            flow.turn_hatch_front(output);
            flow.turn_up(output);
            flow.turn_hatch_back(output);
            flow.turn_hatch_up(output);
            flow.turn_front(output);
          }
        }
        else {
          if ((flow.up.a == 'Y' && flow.back.g == 'O' && flow.left.a == 'B') || (flow.up.a == 'Y' && flow.back.g == 'B' && flow.left.a == 'O') ||
              (flow.up.a == 'B' && flow.back.g == 'O' && flow.left.a == 'Y') || (flow.up.a == 'B' && flow.back.g == 'Y' && flow.left.a == 'O') ||
              (flow.up.a == 'O' && flow.back.g == 'Y' && flow.left.a == 'B') || (flow.up.a == 'O' && flow.back.g == 'B' && flow.left.a == 'Y')) {
            while (!info_all_corners(flow)) {
              flow.turn_up(output);
              flow.turn_left(output);
              flow.turn_hatch_up(output);
              flow.turn_hatch_right(output);
              flow.turn_up(output);
              flow.turn_hatch_left(output);
              flow.turn_hatch_up(output);
              flow.turn_right(output);
            }
          }
          else {
            while (!info_one_corner(flow)) {
              flow.turn_up(output);
              flow.turn_right(output);
              flow.turn_hatch_up(output);
              flow.turn_hatch_left(output);
              flow.turn_up(output);
              flow.turn_hatch_right(output);
              flow.turn_hatch_up(output);
              flow.turn_left(output);
            }
          }
        }
      }
    }
  }
  //разворот углов
  if (flow.up.c != 'Y') {
    while (flow.up.c != 'Y') {
      flow.turn_back(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_back(output);
      flow.turn_right(output);
    }
  }
  flow.turn_up(output);

  if (flow.up.c != 'Y') {
    while (flow.up.c != 'Y') {
      flow.turn_back(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_back(output);
      flow.turn_right(output);
    }
  }
  flow.turn_up(output);

  if (flow.up.c != 'Y') {
    while (flow.up.c != 'Y') {
      flow.turn_back(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_back(output);
      flow.turn_right(output);
    }
  }
  flow.turn_up(output);

  if (flow.up.c != 'Y') {
    while (flow.up.c != 'Y') {
      flow.turn_back(output);
      flow.turn_hatch_right(output);
      flow.turn_hatch_back(output);
      flow.turn_right(output);
    }
  }

  while (!info_full(flow)) {
    flow.turn_up(output);
  }
}

void conditions(Functions &flow, std::ofstream &output) {
  // Цветок
  flower(flow, output);
  // Правильный крест
  right_cross(flow, output);
  // Первый слой
  first_layer(flow, output);
  // Средний слой
  middle_layer(flow, output);
  //сборка желтого креста
  yellow_cross(flow, output);
  //проверка на правильность расположения углов
  last_layer(flow, output);
}