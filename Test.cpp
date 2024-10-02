#include <algorithm>
#include <bitset>
#include <chrono>
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

signed main() {
  using namespace std;
  int x{0};
  x=840;
  cout<<bitset<32>(x)<<'\n';
  cout<<((x& (1<<7)))<<'\n';

  cout << endl;
  return 0;
}
