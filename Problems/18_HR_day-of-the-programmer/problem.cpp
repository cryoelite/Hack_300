// https://www.google.com/url?q=https://www.hackerrank.com/challenges/day-of-the-programmer/problem?isFullScreen%3Dtrue&sa=D&source=editors&ust=1717685260302857&usg=AOvVaw1HJ50AZMPlfFR5oNtWpePh

// Force Local Mode
// #define ForceLOCAL

// Headers
#include <algorithm>
#include <array>
#include <complex>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Definitions

{
// Defines
#define int long long
#define double long double
#define LOG(x) static_cast<int>(std::floor(std::log2(x)))
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);
template <typename... T> void INPUT(T &...args) { ((std::cin >> args), ...); }
template <typename... T> void OUTPUT(T &...args) {
  ((std::cout << args << " "), ...);
  std::cout << "\n";
}
#define ARR_INT_INPUT(arr, n)                                                  \
  for (int i{0}, arg{}; i < n; ++i) {                                          \
    std::cin >> arg;                                                           \
    arr[i] = arg;                                                              \
  }

#define cast(i) static_cast<int>(i)
#define intmax std::numeric_limits<int>::max()
#define intmin std::numeric_limits<int>::min()
#define pb push_back
#define X real()
#define Y imag()
#define tiii std::tuple<int, int, int>
#define mmi std::make_move_iterator

// Constants
constexpr int cmod10_e9_7{1000000007}; // const mod 10e9^7
constexpr int cIN{200005};             // const N (fits in int)
constexpr int cLN{1000005};            // const long N(fits in long long)

// Type Aliases
using usi = std::unordered_set<int>;
using umii = std::unordered_map<int, int>;
using vi = std::vector<int>;
using si = std::set<int>;
using sd = std::set<double>;
using vvi = std::vector<vi>;
using pivi = std::pair<int, vi>; // first is node's value and second is node's
                                 // adjacent elements
using pii = std::pair<int, int>;
using vpii = std::vector<pii>; // edge list
using vtiii = std::vector<tiii>;
using vvtiii = std::vector<vtiii>; // adjacency list with adjacent node id, edge
                                   // weight and an extra value.
using vpivi = std::vector<pivi>;
using vvpii =
    std::vector<vpii>; // adjacency list with edge weights, the pii has first as
                       // node id and second as the edge weight
using mii = std::map<int, int>;
using vmii = std::vector<mii>;
using vb = std::vector<bool>; // vector<bool> is a special explicit definition
                              // of vector and behaves more like a bitset than a
                              // vector, also it is faster than array<bool>
                              // https://stackoverflow.com/a/55762317/13036358
using vvb = std::vector<vb>;
using ri = std::reverse_iterator<vi::iterator>;
using ski = std::stack<int>;
using CD = std::complex<double>;
using CI = std::complex<int>; // DEPRECATED
using pqd = std::priority_queue<double>;
using pqi = std::priority_queue<int>;
using pqpii = std::priority_queue<pii>;
using vcd = std::vector<CD>;
using vci = std::vector<CI>;
using pcd = std::pair<CD, CD>;
using pci = std::pair<CI, CI>;
using vpcd = std::vector<pcd>;
using vpci = std::vector<pci>;
using vs = std::vector<std::string_view>;

} // namespace Definitions

namespace SetupEnvironment {
using namespace Definitions;

bool isLocalMode() {
#ifdef ForceLOCAL
  return true;
#else
  std::string envFilePath{"../../.env"};
  std::ifstream file(envFilePath, std::ios::in | std::ios::binary);
  if (file.good()) {
    // Env var file exists

    if (file.is_open()) {
      // Env var file isn't already open
      std::string envVar{std::istreambuf_iterator<char>(file),
                         std::istreambuf_iterator<char>()};
      // Env variable retrieved

      char *envVarValue{std::getenv(envVar.c_str())};

      if (envVarValue != nullptr) {
        // Env var exists, now checking if it is true
        return envVarValue == std::string("true");
      }
    }
  }
  return false;
#endif
}

void setupIO() {
  IOS;

  if (isLocalMode()) {
    // I/O Stream pointed at local text files
#ifdef freopen_s // windows
    FILE *inpStream;
    FILE *outStream;

    freopen_s(&inpStream, "input.txt", "r", stdin);
    freopen_s(&outStream, "output.txt", "w", stdout);

#else // linux
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
  }
}

} // namespace SetupEnvironment

namespace Solution {
using namespace Definitions;
using namespace SetupEnvironment;
using namespace std;
void start();
void initialize();
void compute();
void output();

int testCases{1};

constexpr int day_to_find{256};
int month_days[]{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int year{};
string result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}
bool isleap(int year) {
  if (year < 1918) {
    return year % 4 == 0;
  } else {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
  }
}
void initialize() {
  cin >> year;
  result = "";
  if (year == 1918) {
    month_days[1] = 15;
  } else if (isleap(year)) {
    month_days[1] = 29;
  } else {
    month_days[1] = 28;
  }
}

void compute() {
  int days{0};
  string day{};
  string month{};
  for (int i{}; i < 12; ++i) {
    if (month_days[i] + days >= day_to_find) {
      if (year == 1918 && i == 1) {
        day = to_string(day_to_find - days + 14);
      } else {
        day = to_string(day_to_find - days);
      }
      month = to_string(i + 1);
      break;
    }
    days += month_days[i];
  }

  if (day.length() == 1) {
    day = "0" + day;
  }
  if (month.length() == 1) {
    month = "0" + month;
  }
  result = day + "." + month + "." + to_string(year);
}

void output() {
  cout << result;
  cout << '\n';
}

} // namespace Solution

#define SOLVE                                                                  \
  SetupEnvironment::setupIO();                                                 \
  Solution::start();

signed main() {

  SOLVE;

  return 0;
}
