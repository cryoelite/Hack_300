```cpp
void compute() {
  for (int i{}; i < n; ++i) {
    if (arr[i] < 38 || arr[i] % 5 < 3) {
      result[i] = arr[i];
    } else {
      result[i] = arr[i] + (5 - (arr[i] % 5));
    }
  }
}
```