#include <fstream>
#include <regex>
#include <unordered_map>
#include <iostream>

std::unordered_map<std::string, int> game = {
    //12 red cubes, 13 green cubes, and 14 blue cubes.
    { "red", 12 },
    { "green", 13 },
    { "blue", 14 }
};


int main(int, char**) {
    std::ifstream ifs("./input.txt");
    std::string line;

    auto re_red     = std::regex("(\\d+)\\s+red");
    auto re_green   = std::regex("(\\d+)\\s+green");
    auto re_blue    = std::regex("(\\d+)\\s+blue");

    while(std::getline(ifs, line)) {
        std::smatch sm;
        std::regex_search(line, sm, re_red);
        for(auto it: sm) {
            std::cout << it.str() << std::endl;
        }

        
    }

}