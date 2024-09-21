```cpp
void compute() {
  int n_copy{n};
  int digit{0};
  while (n > 0) {
    digit = n % 10;
    if (digit != 0) {
      result += n_copy % digit == 0 ? 1 : 0;
    }
    n /= 10;
  }
}
```
