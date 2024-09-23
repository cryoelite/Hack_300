```cpp
void compute() {
  merge_sort(arr.begin(),arr.end());
  int min_diff{numeric_limits<int>::max()};
  for (int i{1}; i < n; ++i) {
    min_diff = min(arr[i] - arr[i - 1], min_diff);
  }

  for (int i{1}, j{}; i < n; ++i) {
    if (arr[i] - arr[i - 1] == min_diff) {
      result[j++] = arr[i - 1];
      result[j++] = arr[i];
    }
  }
}
```
- We simply sort the array and then find the min diff between any 2 pair, then find all pairs that have the same min diff. The sorting alg Merge Script is explained in in `Misc Scripts`.