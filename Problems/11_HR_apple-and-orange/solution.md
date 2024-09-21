```cpp
void compute() {
  for (int i{}; i < m; ++i) {
    if (apples[i] + a >= s && apples[i] + a <= t) {
      ++apples_fallen;
    }
  }
  for (int i{}; i < n; ++i) {
    if (oranges[i] + b >= s && oranges[i] + b <= t) {
      ++oranges_fallen;
    }
  }
}
```