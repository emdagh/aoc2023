#include <fstream>
#include <algorithm>
#include <memory>
#include <vector>
#include "string.hpp"
#include <cstdint>
#include <unordered_map>

const char* sym = "!@#$%^&*()_+-=";

enum {
    N, E, S, W,
    NE, SE, SW, NW, 
    NUM_DIRECTIONS
};

struct coord { int x, int y; };

std::unordered_map<int, coord> coords = {
    { N, { 0, -1 } },
    { E, { 1,  0 } },
    { S, { 0,  1 } },
    { W, {-1,  0 } },
    { NE, { 1, 1 } },
    { SE, { 1,  0 } },
    { SW, { 0, -1 } },
    { NW, { 1,  0 } },
};

int scan(int x, int y, size_t w, size_t h, const std::vector<std::string>& lines) {
    bool checked[NUM_DIRECTIONS] = { false };

    for(int i=0; i < NUM_DIRECTIONS; i++) {
        
    }

    // check all directions for a number
    // mark direction as checked
    // if a number is touched, move to the beginning of that number 
    // find last consecutive digit
    // add to sum

}

int main(int, char**)
{
    std::fstream ifs("input2.txt");
    size_t h = std::count(
        std::istreambuf_iterator<char>(ifs), 
        std::istreambuf_iterator<char>(), 
        '\n');

    std::string vec =  {};
    std::copy(
        std::istreambuf_iterator<char>(ifs),
        std::istreambuf_iterator<char>(),
        std::back_inserter(vec)
    );

    auto lines = split(vec, "\n");
    size_t w = lines[0].length();

    // x + y * w

    for(size_t y=0; y < lines.size(); y++) {
        const auto& line = lines[y];
    //for(const auto& line: lines) {
        size_t first = 0, last = 0;
        while((last = line.find_first_of(sym, first)) != std::string::npos) {
            scan(last, y, w, h, lines);
            first = last + 1; // start after found symbol
        } 
        while(std::find(line.begin(), line.end(), 
    }


    return 0;
}