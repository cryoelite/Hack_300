// https://www.google.com/url?q=https://www.hackerrank.com/challenges/mark-and-toys?isFullScreen%3Dtrue&sa=D&source=editors&ust=1717685260340646&usg=AOvVaw3P796hdgsWONaUzZBG_1R7 

/*
Has to buy toys
Input
> Prices: Array
> k (Budget): Int

Find
The maximum sized set of elements of prices that produce sum k

Constraints:
A toy can't be bought multiple times.
n >=1 and <=10^5
k >=1 and <=10^9
prices[i] >=1 and <=10^9

Unsorted
Do we need to sort the input ?

For every element i, we can either take/skip
if we take prices[i], we have to then find the elements that fit for the budget k-prices[i]
if we skip prices[i], we can only move ahead and repeat the relation.

Base cases:
if prices[i] > k then we can only skip
if prices array is over and we still have some budget, then we cannot do anything and stop with our set.
Set can be potentially empty since we can skip all the elements.



*/

// Force Local Mode
// #define ForceLOCAL

// Headers

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
/*
#include <algorithm>
#include <array>
#include <complex>
#include <filesystem>
#include <functional>
#include <iomanip>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string_view>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

*/

namespace Definitions {

#define int long long
#define double long double
#define LOG(x) static_cast<int>(std::floor(std::log2(x)))
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);
/* template <typename... T> void INPUT(T &...args) { ((std::cin >> args), ...);
} template <typename... T> void OUTPUT(T &...args) {
  ((std::cout << args << " "), ...);
  std::cout << "\n";
} */
#define ARR_INT_INPUT(arr, n)                                                  \
  for (int i{0}, arg{}; i < n; ++i) {                                          \
    std::cin >> arg;                                                           \
    arr[i] = arg;                                                              \
  }

#define cast(i) static_cast<int>(i)
#define X real()
#define Y imag()
#define tiii std::tuple<int, int, int>
#define mmi std::make_move_iterator
} // namespace Definitions

namespace Constants {
/* using namespace Definitions;
constexpr int cmod10_e9_7{1000000007}; // const mod 10e9^7
constexpr int cIN{200005};             // const N (fits in int)
constexpr int cLN{1000005};            // const long N(fits in long long)
constexpr int intmax{std::numeric_limits<int>::max()};
constexpr int intmin{std::numeric_limits<int>::min()}; */
} // namespace Constants
 
namespace Type_Aliases {
using namespace Definitions;
using vi = std::vector<int>;
/* using usi = std::unordered_set<int>;
using umii = std::unordered_map<int, int>;

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
using viit= std::vector<int>::iterator; */
} // namespace Type_Aliases

namespace Environment {
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

} // namespace Environment

namespace Solution {
using namespace Definitions;
using namespace Environment;
using namespace Constants;
using namespace Type_Aliases;
using namespace std;
void start();
void initialize();
void compute();
void output();

int testCases{1};

int n{};
vi arr{};
int result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {}

void compute() {}

void output() {
  cout << result;
  cout << '\n';
}

} // namespace Solution

#define SOLVE                                                                  \
  Environment::setupIO();                                                      \
  Solution::start();

signed main() {

  SOLVE;

  return 0;
}
