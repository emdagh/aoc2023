#include "string.hpp"
#include <fstream>
#include <iostream>
#include <regex>
#include <unordered_map>

std::unordered_map<std::string, int> constraints = {
    // 12 red cubes, 13 green cubes, and 14 blue cubes.
    {"red", 12},
    {"green", 13},
    {"blue", 14}};

int main(int, char **)
{
  std::ifstream ifs("./input.txt");
  std::string line;
  int sum = 0;

  while (std::getline(ifs, line))
  {
    bool didPass = true;
    auto game = split(line, ":");
    for (auto turn : split(game[1], ";"))
    {
      for (auto action : split(turn, ","))
      {
        auto kv = split(ltrim(action), " ");
        auto key = kv[1];
        auto value = std::stoi(kv[0]);
        if (value > constraints[key])
        {
          didPass = false;
          break;
        }
      }
    }
    if (didPass)
    {
      auto id = std::stoi(ltrim(split(game[0], " ")[1]));
      sum += id;
    }
  }
  std::cout << sum << std::endl;
  return 0;
}