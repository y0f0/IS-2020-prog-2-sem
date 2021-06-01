#include <ctime>

#include "Options.h"

void info_color(char c);

void read(Functions &flow, std::ifstream &input);

void print(Functions &flow, std::ofstream &output);

// Проверка на соответсвие цетров
bool info_center(Functions &flow);

void random(Functions &flow, std::ofstream &output);

bool info_one_corner(Functions &flow);

bool info_all_corners(Functions &flow);

bool info_full(Functions &flow);
