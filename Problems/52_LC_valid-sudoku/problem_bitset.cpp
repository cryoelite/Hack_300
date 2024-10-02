// https://neetcode.io/problems/valid-sudoku

// Force Local Mode, I can only use this on LC (at the moment)
//#define ForceLOCAL

// Headers
#include <array>
#include <cmath>
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

li testCases{1};

constexpr size_t N{9};
vector<vector<char>> board{};
int count{};
bool result{};

void start() {
  // INPUT(testCases);
  while (testCases-- > 0) {
    initialize();
    compute();
    output();
  }
}

void initialize() {

}

void compute() {
  result = false;
  count = 0;

  for (size_t i{0}; i < N; ++i) {
    for (size_t j{0}; j < N; ++j) { // checking rows
      int value{board[i][j] - '0'};
      if (value > 0) {
        if ((count & (1 << value))) {
          result = false;
          return;
        }
        count = count | (1 << value);
      }
    }
    count = 0;
  }

  for (size_t i{0}; i < N; ++i) {
    for (size_t j{0}; j < N; ++j) { // checking columns
      int value{board[j][i] - '0'};
      if (value > 0) {
        if ((count & (1 << value))) {
          result = false;
          return;
        }
        count = count | (1 << value);
      }
    }
    count = 0;
  }

  const size_t block_size{3};
  const size_t blocks{static_cast<size_t>(floor(N / block_size))};

  for (size_t block_x{0}; block_x < blocks; ++block_x) {
    for (size_t block_y{0}; block_y < blocks; ++block_y) {
      size_t i_end{(block_x * blocks) + block_size};
      size_t j_end{(block_y * blocks) + block_size};

      for (size_t i{block_x * blocks}; i < i_end; ++i) {
        for (size_t j{block_y * blocks}; j < j_end; ++j) {
          int value{board[i][j] - '0'};
          if (value > 0) {
            if ((count & (1 << value))) {
              result = false;
              return;
            }
            count = count | (1 << value);
          }
        }
      }
      count = 0;
    }
  }

  result = true;
}

void output() {
  cout << result;
  cout << '\n';
}

} // namespace Solution_LOCAL

namespace Solution_LC {
using namespace Type_Aliases;
using namespace std;
using namespace Solution_LOCAL;
class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    Solution_LOCAL::board = std::move(board);
    Solution_LOCAL::compute();

    return Solution_LOCAL::result;
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