#include <iostream>
#include <vector>
#define int long long
signed main() {
  using namespace std;

  cout << sizeof(vector<int>::iterator&) << " and " << sizeof(int);
  cout << endl;
  return 0;
}
