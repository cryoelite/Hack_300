// https://www.google.com/url?q=https://www.hackerrank.com/challenges/closest-numbers?isFullScreen%3Dtrue&sa=D&source=editors&ust=1717685260339434&usg=AOvVaw3bT6m7kSrUSRcaTWhz0Y7s

// Force Local Mode
// #define ForceLOCAL

// Headers
#include <algorithm>
#include <array>
#include <cassert>
#include <complex>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
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
using viit = std::vector<int>::iterator;

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
      std::string envVar{};
      std::getline(file, envVar, '=');
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
  IOS;
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

int n{};
vi arr{};
vi result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {
  cin >> n;
  arr = vi(n, 0);
  result = vi(2 * n, 0);
  ARR_INT_INPUT(arr, n);
}

void merge(viit a, viit a_end, viit b, viit b_end, viit temp_it) {
  viit a_copy{a}, a_end_copy{a_end}, b_copy{b}, b_end_copy{b_end},
      temp_it_copy{temp_it};
  while (a_copy < a_end_copy && b_copy < b_end_copy) {
    if (*a_copy < *b_copy) {
      *temp_it_copy = *a_copy;
      a_copy++;
    } else {
      *temp_it_copy = *b_copy;
      b_copy++;
    }
    temp_it_copy++;
  }

  while (a_copy < a_end_copy) {
    *temp_it_copy = *a_copy;
    a_copy++;
    temp_it_copy++;
  }
  while (b_copy < b_end_copy) {
    *temp_it_copy = *b_copy;
    b_copy++;
    temp_it_copy++;
  }
  viit a_copy_2{a}, b_end_copy_2{b_end}, temp_it_copy_2{temp_it};
  swap_ranges(a_copy_2, b_end_copy_2, temp_it_copy_2);
}

void merge_sort(viit start, viit end) {
  int n{std::distance(start, end)};
  vi temp{vi(n, 0)};

  for (int m{1}; m < n; m *= 2) {

    for (int i{}; i < n; i += 2 * m) {
      viit a{start + i};
      viit a_end{min(a + m, end)}; // end exclusive
      viit b{a_end};
      viit b_end{min(b + m, end)}; // end exclusive

      merge(a, a_end, b, b_end, temp.begin() + i);
    }
  }
}

void compute() {
  merge_sort(arr.begin(), arr.end());
  int min_diff{numeric_limits<int>::max()};
  for (int i{1}; i < n; ++i) {
    min_diff = min(arr[i] - arr[i - 1], min_diff);
  }

  for (int i{1}, j{}; i < n; ++i) {
    if (arr[i] - arr[i - 1] == min_diff) {
      result[j++] = arr[i - 1];
      result[j++] = arr[i];
    }
  }
}

void output() {
  int i{0};
  while (result[i] != 0) {
    cout << result[i] << " ";
    ++i;
  }

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
