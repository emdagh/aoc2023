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

template <typename T>
auto sum(const T& t) {
  return std::accumulate(t.begin(), t.end(), 0);
}

template <typename T>
auto mul(const T& t) {
  return std::accumulate(t.begin(), t.end(), 1, [] (const auto& a, const auto& b) { return a * b; });
}

template <typename T1, typename T2>
auto values(const std::unordered_map<T1,T2>& m) {
  std::vector<T2> values = { };
  for(auto kv: m) {
    values.push_back(kv.second);
  }
  return values;
}

int main(int, char **)
{
  std::ifstream ifs("./input.txt");
  std::string line;
  int sum_ids = 0;
  int sum_power = 0;

  while (std::getline(ifs, line))
  {
    bool didPass = true;
    auto game = split(line, ":");
    std::unordered_map<std::string, int> maxvals = { 
      { "red", 0 },
      { "green", 0 },
      { "blue", 0 }
    };

    for (auto turn : split(game[1], ";"))
    {
      auto actions = split(turn, ",");
      for (auto action : split(turn, ","))
      {
        auto kv = split(ltrim(action), " ");
        auto key = kv[1];
        auto value = std::stoi(kv[0]);
        maxvals[key] = std::max(maxvals[key], value);
        if (value > constraints[key])
        {
          didPass = false;
          // break; //no early out, power calculation needs exhaustive  behavior (or a separate loop....)
        }
      }
    }
    if (didPass)
    {
      auto id = std::stoi(ltrim(split(game[0], " ")[1]));
      sum_ids += id;
    }
    auto power = mul(values(maxvals));
    sum_power += power;
  }
  std::cout << sum_ids << std::endl;
  std::cout << sum_power << std::endl;
  return 0;
}



