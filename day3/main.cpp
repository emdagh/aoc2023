#include "string.hpp"
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <memory>
#include <regex>
#include <unordered_map>
#include <vector>

std::string sym = "!@#$%^&*()_+-=";

enum { N, E, S, W, NE, SE, SW, NW, NUM_DIRECTIONS };

struct coord {
  int x, y;
};

std::unordered_map<int, coord> coords = {
    {N, {0, -1}},  {E, {1, 0}},  {S, {0, 1}},   {W, {-1, 0}},
    {NE, {1, -1}}, {SE, {1, 1}}, {SW, {-1, 1}}, {NW, {-1, -1}}};

int get_number(int x, int y, size_t w, size_t h, const char *data) {
  while (std::isdigit(data[(x - 1) + y * w]) && x != 0 &&
         data[(x - 1) + y * w] != '\n') {
    x--;
  }
  auto first = x;
  while (std::isdigit(data[x + y * w]) && data[x + y * w] != '\n') {
    x++;
  }
  auto last = x;

  int ret = std::stoi(std::string(data, first, last));
  return ret;
}

int scan(int x, int y, size_t w, size_t h, const char *data) {
  bool checked[NUM_DIRECTIONS] = {false};
  // check all directions for a number
  for (int i = 0; i < NUM_DIRECTIONS; i++) {
    int x2 = x + coords[i].x;
    int y2 = y + coords[i].y;

    if (x2 < 0 || x2 > w)
      continue;
    if (y2 < 0 || y2 > h)
      continue;

    if (std::isdigit(data[x2 + y2 * w])) {
      get_number(x2, y2, w, h, data);
    }
    // mark direction as checked
    checked[i] = true;
  }

  // if a number is touched, move to the beginning of that number
  // find last consecutive digit
  // add to sum
}

void replace_all(std::string &src, const std::string &from,
                 const std::string &to) {
  size_t first = 0, found = 0;
  while ((found = src.find_first_of(from, first)) != std::string::npos) {
    src.replace(found, from.length(), to);
    first = found + 1;
  }
}

int main(int, char **) {
  std::fstream ifs("input2.txt");
  if (!ifs.is_open()) {
    return -1;
  }
  size_t h = std::count(std::istreambuf_iterator<char>(ifs),
                        std::istreambuf_iterator<char>(), '\n') +
             1;
  ifs.seekg(0);

  std::string vec = {};
  std::copy(std::istreambuf_iterator<char>(ifs),
            std::istreambuf_iterator<char>(), std::back_inserter(vec));

  auto lines = split(vec, "\n");
  size_t w = lines[0].length();

  // replace_all(vec, "\n", "");

  // x + y * w

  // for(size_t y=0; y < lines.size(); y++) {
  // const auto& line = lines[y];
  size_t first = 0, last = 0;
  while ((last = vec.find_first_of(sym, first)) != std::string::npos) {
    size_t y = last / w;
    size_t x = last % w;
    scan(x, y, w, h, vec.c_str());
    first = last + 1; // start after found symbol
  }
  //}

  return 0;
}