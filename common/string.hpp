#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

template <typename InputIt>
std::string join(InputIt begin, InputIt end, const char *delim) {
  std::ostringstream ss;
  std::copy(begin, end, std::ostream_iterator<std::string>(ss, delim));
  return ss.str();
}

template <typename OutputIt>
inline void split(const std::string &s, char delim, OutputIt it) {
  std::istringstream ss(s);
  std::string token;
  while (std::getline(ss, token, delim)) {
    *(it++) = token;
  }
}

template <typename OutputIt>
static inline void split(const std::string &in, const std::string &delim,
                         OutputIt it) {
  size_t start = 0, end = 0;
  while ((end = in.find_first_of(delim, start)) != std::string::npos) {
    *it++ = in.substr(start, end - start);
    start = end + delim.length();
  }
  *it++ = in.substr(start);
}

static inline std::vector<std::string> split(const std::string &in,
                                             const std::string &delim) {
  std::vector<std::string> res;
  split(in, delim, std::back_inserter(res));
  return res;
}

std::string ltrim(const std::string &in) {
  auto str = in;
  str.erase(str.begin(),
            std::find_if(str.begin(), str.end(),
                         [](unsigned char c) { return !std::isspace(c); }));
  return str;
}