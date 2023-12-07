#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <regex>

std::unordered_map<std::string, std::string> numbers = {
    {"one", "1"},
    {"two", "2"},
    {"three", "3"},
    {"four", "4"},
    {"five", "5"},
    {"six", "6"},
    {"seven", "7"},
    {"eight", "8"},
    {"nine", "9"},
};

bool is_number(const std::string &str)
{
    return !str.empty() && std::find_if(str.begin(), str.end(), [](unsigned char c)
                                        { return !std::isdigit(c); }) == str.end();
}

template <typename InputIt, typename OutputIt>
void numberize(InputIt first, InputIt last, OutputIt d_first)
{
    std::regex re("(?=(one|two|three|four|five|six|seven|eight|nine|\\d))"); // positive lookahead to allow overlapping matches.
    auto re_first = std::sregex_iterator(first, last, re);
    auto re_last = std::sregex_iterator();
    for (auto it=re_first; it!=re_last; ++it)
    {
        std::smatch match = *it;
        for (auto m : match)
        {
            auto mstr = m.str();
            if (!mstr.empty())
            {
                *d_first++ = is_number(mstr) ? std::stoi(mstr) : std::stoi(numbers[mstr]);
            }
        }
    }
}

int main(int, char **)
{

    std::ifstream ifs("./data");
    std::string line;
    std::vector<int> nums = { 0 };
    while (std::getline(ifs, line))
    {
        std::vector<int> lst = {};
        numberize(line.begin(), line.end(), std::back_inserter(lst));
        
        int a = lst.size() > 0 ? *lst.begin() : 0;
        int b = lst.size() > 1 ? *lst.rbegin() : a;
        nums.push_back(a * 10 + b);
    }
    int num = std::accumulate(nums.begin(), nums.end(), 0);

    return 0;
}
