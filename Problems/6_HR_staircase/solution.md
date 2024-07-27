```cpp
void output() {
  for (int i{}; i < n; ++i) {
    for (int j{}; j < n; ++j) {
      if (j < (n - i - 1)) {
        cout << " ";
      } else {
        cout << "#";
      }
    }
    cout << '\n';
  }
}
```