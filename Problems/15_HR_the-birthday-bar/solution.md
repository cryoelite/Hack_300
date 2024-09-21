```cpp
void compute() {
  int rolling_sum{0};

  for (int i{0}; i < n; ++i) {
    rolling_sum += s[i];
    if (i >= m) {
      rolling_sum -= s[i - m];
    }
    if (i >= m - 1 && rolling_sum == d) {
      ++result;
    }
  }
}
```
- We need consecutive element sum. So, we simply take a sum of m elements from the start and we can think of this like a window, from index i to i+m-1 (0 indexed array), and we simply add the next element of the array and subtract the element we are rolling over from the back. This way we dont have to add m elements for each element of array and we can compare the sum to d.