```cpp
void compute() {
  int max_elem{numeric_limits<int>::min()};
  int max_elem_count{0};
  for (int i{}; i < n; ++i) {
    if (arr[i] > max_elem) {
      max_elem_count = 1;
      max_elem = arr[i];
    } else if (arr[i] == max_elem) {
      ++max_elem_count;
    }
  }
  result = max_elem_count;
}
```

- Track the maximum element and its count, reset it to 1 when a bigger element is found.