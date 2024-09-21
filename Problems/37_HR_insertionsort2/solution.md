```cpp
void compute() {
  for (int i{}, j{}; i < n-1; ++i) {
    if (arr[i] > arr[i + 1]) {
      j = i;
      while (arr[j] > arr[j + 1] && j>=0) {
        swap(arr[j], arr[j + 1]);
        --j;
      }
    }
    output();
  }
}
```