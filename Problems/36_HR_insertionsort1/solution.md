```cpp
void compute() {
  int unsorted_elem_index{0}; // given there'd be one
  for (int i{1}; i < n; ++i) {
    if (arr[i] < arr[i - 1]) {
      unsorted_elem_index = i;
      break;
    }
  }
  for (int i{unsorted_elem_index - 1}, copy_elem{}; i >= 0; --i) {
    if (arr[i] > arr[i + 1]) {
      copy_elem = arr[i+1];
      arr[i+1] = arr[i];
      output();
      arr[i] = copy_elem; //smaller value, goes in the left
    }
  }
  output();
}
```
