```cpp
void compute() {
  int on_time_counter{0};
  for (int i{}; i < n; ++i) {
    on_time_counter += arr[i] <= 0 ? 1 : 0;
  }
  if (on_time_counter < k) {
    result = "YES"; //Cancel Class
  } else {
    result = "NO";
  }

}
```
- Simply track the number of times students did come on time and compare.