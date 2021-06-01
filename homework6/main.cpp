#include "Solving.h"
#include <iostream>

int main() {
  std::cout << "Scan or generate a Rubik's cube? \n"
               "S - scan, G - generate" << std::endl;
  char type;
  std::cin >> type;

  std::ifstream input("input.txt");
  std::ofstream output("output.txt");

  Functions flow{};
  read(flow, input);

  if (type == 'G') {
    random(flow, output);
  }

  if (!info_center(flow)) {
    std::cout << "You have problems with file!";
    return 1;
  }

  conditions(flow, output);
  print(flow, output);

  input.close();
  output.close();
  return 0;
}
