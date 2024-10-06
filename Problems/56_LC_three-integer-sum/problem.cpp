// https://neetcode.io/problems/three-integer-sum

// Force Local Mode, I can only use this on LC (at the moment)
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
vi arr{};
vector<vi> result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {}

void compute() {
  n = arr.size();

  result = vector<vi>();
  result.reserve(n); // max n triplets

  sort(arr.begin(), arr.end());

  auto ptr1{arr.begin()};
  auto ptr2{arr.end() - 1};
  auto ptr3{arr.begin()};

  while (ptr1 < ptr2 - 1) {
    // meaning distance between ptr 1 and 2 should be of 3
    int sum{*ptr1 + *ptr2};
    if (sum < 0) {
      // means that the value on the left ptr is bigger in magnitude
      ptr3 = ptr2 - 1;
      if (*ptr3 + sum == 0) {
        result.emplace_back(vi({*ptr1, *ptr3, *ptr2}));
      }
      while (*ptr1 == *(++ptr1) && ptr1 < ptr2 - 1) {
        ++ptr1;
      }

    } else {
      // either the sum is > or == 0
      ptr3 = ptr1 + 1;
      while (ptr3 < ptr2 && *ptr3 + sum <= 0) {
        if (*ptr3 + sum == 0) {
          result.emplace_back(vi({*ptr1, *ptr3, *ptr2}));
          break;
        }
        ++ptr3;
      }
      while (*ptr2 == *(--ptr2) && ptr2 > ptr1 + 1) {
        ++ptr1;
      }
    }
  }
}

void output() {
  for (auto &v : result) {
    for (int elem : v) {
      cout << elem << " ";
    }
    cout << '\n';
  }
  cout << '\n';
}

} // namespace Solution_LOCAL

namespace Solution_LC {
using namespace Type_Aliases;
using namespace std;
using namespace Solution_LOCAL;
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    Solution_LOCAL::arr = std::move(nums);
    compute();
    return result;
  }
};
} // namespace Solution_LC

#define SOLVE                                                                  \
  Environment::setupIO();                                                      \
  Solution_LOCAL::start();

#ifdef ForceLOCAL
signed main() {

  SOLVE;

  return 0;
}

#endif
using namespace Solution_LC;

/// LC Boilerplate starts here (unmodifiable on LC, automatically inserted)
