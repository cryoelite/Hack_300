```cpp
void compute() {
  sort(arr.begin(), arr.end());
  int prev_elem{};
  int similar_elems{0};
  int arr_size{n};
  int index_result{0};
  for (int i{}; i < n; ++i) {
    if (prev_elem != arr[i]) {
      arr_size = arr_size - similar_elems;
      result[index_result] = (arr_size);
      similar_elems = 1;
      ++index_result;
    } else {
      ++similar_elems;
    }
    prev_elem = arr[i];
  }
}
```

- O(nlogn), We simply sort the array and then traverse it. We know the smallest values will be grouped together and then just a single instance of the value will be subtracted
from all the other values.
Meaning if we track the similar smallest elements in the array and then find where they change, we know those similar small elements will go in the next pass of cutting, so we simply store
`array's current size - the no. of similar elements` to get the size array will be after those elements are cut.
