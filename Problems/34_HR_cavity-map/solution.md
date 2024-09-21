```cpp
void compute() {
  for (int i{1}; i < n - 1; ++i) {
    for (int j{1}; j < n - 1; ++j) {
      int &p{arr[i][j]};
      int &up{arr[i - 1][j]};
      int &left{arr[i][j - 1]};
      int &down{arr[i + 1][j]};
      int &right{arr[i][j + 1]};
      if (p > up && p > left && p > right && p > down) {
        result[i][j] = -1;
      }
    }
  }
}
```
- We simply compare the 4 positions, we don't need to traverse the boundaries.
