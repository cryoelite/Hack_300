```cpp
void compute() {
  int diagsum_1{0};
  int diagsum_2{0};
  for (int i{}, diag_1{0}, diag_2{n - 1}; i < n; ++i, ++diag_1, --diag_2) {
    diagsum_1 += arr[i][diag_1];
    diagsum_2 += arr[i][diag_2];
  }
  result = abs(diagsum_1-diagsum_2);
}
```

- We simply add the 2 diagonals individually, then subtract their sum.