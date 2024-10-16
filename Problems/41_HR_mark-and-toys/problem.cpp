// https://www.hackerrank.com/challenges/mark-and-toys

// Force Local Mode
// #define ForceLOCAL

// Headers
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
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
int k{};
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

void initialize() {
  cin >> n >> k;
  arr = vi(n, 0);
  ARR_INT_INPUT(arr, n);
  result = 1;
}

void compute() {
  for (int i{1}; i < n; ++i) { // if size is 1, won't run.
    if (arr[i] < arr[i - 1]) {
      sort(arr.begin(), arr.end());
      break;
    }
  }

  auto ptr1{arr.begin()};
  auto ptr2{arr.begin() + 1};
  int c_sum{*ptr1}; // current sum
  int c_count{1};   // current count
  while (ptr1 < ptr2 &&
         ptr2 < arr.end()) { // if size is 1, ptr2 is already at end, no work.
    if (c_sum + *ptr2 <= k) {
      c_sum += *ptr2;
      ++c_count;
      ++ptr2;
      result = max(result, c_count);

    } else {
      c_count = 1;
      ++ptr1;
    }
  }
}

void output() {
  cout << result;
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
