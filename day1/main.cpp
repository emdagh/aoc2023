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

////
//// can't use map, or unordered_map; these are lexicogaphically ordered.
////
//
// bool replace_best_match(std::string& s, std::unordered_map<std::string, std::string>& mp) {
//    std::string best_item = "";
//    size_t best_pos = s.size();
//
//    for(auto item: mp)
//    {
//        size_t pos = s.find(item.first);
//        if(pos >= best_pos)  {
//            continue;
//        }
//        best_pos = pos;
//        best_item = item.first;
//    }
//    if(best_pos < s.size()) {
//        s.replace(best_pos, best_item.length(), mp[best_item]);
//    }
//
//    return best_pos != s.size();
//}
//
//
// int main(int, char **)
//{
//
//    std::ifstream ifs("./data2");
//    std::string line;
//    std::vector<int> all_numbers = {};
//    while (std::getline(ifs, line))
//    {
//        // part 2
//        while(replace_best_match(line, numbers)) {}
//
//        // part 1
//        line.erase(std::remove_if(line.begin(), line.end(), [](char c){
//            return !std::isdigit(static_cast<unsigned char>(c)) // erase when [a-zA-Z]
//            || c == '\n' // erase when LF
//            || c == '\r';  // erase when CR
//        }), line.end());
//
//        std::vector<int> numbers;
//        std::transform(
//            line.begin(),
//            line.end(),
//            std::back_inserter(numbers), [](char c)
//            { return c - '0'; });
//
//        int a = numbers.size() > 0 ? *numbers.begin() : 0;
//        int b = numbers.size() > 1 ? *numbers.rbegin() : a;
//
//        all_numbers.push_back(a * 10 + b);
//
//    }
//    auto sum = std::accumulate(all_numbers.begin(), all_numbers.end(), 0);
//    std::cout << sum << std::endl;
//    return 0;
//}