```cpp
int reverse_num(int num) {
  int reverse{0};
  while (num > 0) {
    reverse = (reverse * 10) + (num % 10);
    num /= 10;
  }
  return reverse;
}

void compute() {
  for (int i{i_day}; i <= j_day; ++i) {
    if ((i - reverse_num(i)) % k == 0) {
      ++result;
    }
  }
}
```
- There may be a more efficient solution but haven't found that out yet. O(j-i)
