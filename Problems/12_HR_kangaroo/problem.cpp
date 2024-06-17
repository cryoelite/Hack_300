// https://www.google.com/url?q=https://www.hackerrank.com/challenges/kangaroo/problem?isFullScreen%3Dtrue&sa=D&source=editors&ust=1717685260292140&usg=AOvVaw0Bd6tGAW3qLmB-WUDeOsZV

// Force Local Mode
// #define ForceLOCAL

// Headers
#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
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

int x1{};
int x2{};
int v1{};
int v2{};
string result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {
  cin >> x1 >> v1 >> x2 >> v2;
  result = "";
}

// x1+y*v1 = x2+ y*v2, as the series has to be x1+ v1 + v1 + v1 + ... + v1 = x2
// + v2 + v2 + ... + v2, we need the jumps to be the same so we can say x1 + y
// times v1 = x2 + y times v2, as the jumps have to be the same, just the value
// needs to intersect.
// Now we get y = (x2 - x1)/ (v1 - v2), y is the jump at which they intersect
// and we can see if y is > 0 then they intersect,
// if y < 0 then we can't have negative jumps so they never intersect
// if y > 1 then they intersect
// if v1 == v2 then they will never meet and y can't be computed because of it.

void compute() {
  if (x2 - x1 == 0 || v1 - v2 == 0) {
    result = "NO";
    return;
  }
  double y{static_cast<double>((x2 - x1)) / (v1 - v2)};
  if (y > 0 && y == floor(y)) { // y > 0 and y is a whole number
    result = "YES";
  } else {
    result = "NO";
  }
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
