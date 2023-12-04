#include "string.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <unordered_map>

std::unordered_map<std::string, int> game = {
    // 12 red cubes, 13 green cubes, and 14 blue cubes.
    {"red", 12},
    {"green", 13},
    {"blue", 14}};

int main(int, char **) {
  std::ifstream ifs("./input.txt");
  std::string line;

  while (std::getline(ifs, line)) {

    auto game = split(line, ":");
    auto turns = split(game[1], ";");
    for (auto turn : turns) {
      auto actions = split(turn, ",");
      for (auto action : actions) {
        auto kv = split(ltrim(action), " ");

        std::cout << "key=" << kv[1] << std::endl;
        auto value = std::stoi(kv[0]);
      }
    }
  }
}