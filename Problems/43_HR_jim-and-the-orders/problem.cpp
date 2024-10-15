// https://www.google.com/url?q=https://www.hackerrank.com/challenges/jim-and-the-orders?isFullScreen%3Dtrue&sa=D&source=editors&ust=1717685260343171&usg=AOvVaw2kZbxH1QF9YgwVkuMqCHZf

// Force Local Mode
// #define ForceLOCAL

// Headers
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

namespace Definitions {
#define IOS                                                                    \
  std::ios_base::sync_with_stdio(false);                                       \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);
/* template <typename... T> void INPUT(T &...args) { ((std::cin >> args), ...);
} template <typename... T> void OUTPUT(T &...args) {
  ((std::cout << args << " "), ...);
  std::cout << "\n";
} */
template <typename T, typename X> void ARR_INT_INPUT(T &arr, X &n) {
  X arg{};
  for (X i{0}; i < n; ++i) {
    std::cin >> arg;
    arr[i] = arg;
  }
}
#define X real()
#define Y imag()
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
using li = long long int;
using vi = std::vector<int>;
using vli = std::vector<li>;
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

namespace Solution_LOCAL {
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

size_t n{};
vi order{};
vi prep{};
vector<pair<int, int>> result{};

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
  order = vi(n + 1, 0);
  prep = vi(n + 1, 0);
  for (size_t i{1}; i <= n; ++i) {
    int arg1{}, arg2{};
    cin >> arg1 >> arg2;
    order[i] = arg1;
    prep[i] = arg2;
  }
  result = vector<pair<int, int>>(n, pair<int, int>());
}
bool is_pair_smaller_customer_comparator(const pair<int, int> &a,
                              const pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  } else { // a.first == b.first
    if (a.second <
        b.second) { // not handling edge case a.second==b.second, which can't be
                    // but if it is, it passes through.
      return true;
    } else {
      return false;
    }
  }
}
void compute() {
  for (size_t i{1}; i <= n; ++i) {
    result[i - 1].first = order[i] + prep[i]; // time
    result[i - 1].second = i;
  }
  sort(result.begin(), result.end(), is_pair_smaller_customer_comparator);
  
}

void output() {
  for (auto &elem : result) {
    cout << elem.second << ' ';
  }
  cout << '\n';
}

} // namespace Solution_LOCAL

#define SOLVE                                                                  \
  Environment::setupIO();                                                      \
  Solution_LOCAL::start();

signed main() {

  SOLVE;

  return 0;
}
