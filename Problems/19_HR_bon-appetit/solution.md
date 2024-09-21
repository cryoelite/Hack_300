```cpp
void compute() {
  int bill_ana{(accumulate(arr.begin(), arr.end(), 0) - arr[k]) / 2};
  if (bill_ana == b) {
    result = "Bon Appetit";
  } else {
    result = to_string(b - bill_ana);
  }
}
```
- Just get the actual bill for ana, and subtract it from the charged amount, that's the extra she has paid.