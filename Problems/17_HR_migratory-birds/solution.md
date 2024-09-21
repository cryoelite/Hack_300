```cpp
void compute() {
  for (int i{}; i < n; ++i) {
    ++types[arr[i]];
  }

  for (int i{5}; i >= 0; --i) {
    if (types[i] >= result.second) {
      result.first = i;
      result.second = types[i];
    }
  }
}
```
- We simply create an array with the 5 ids and count the occurences of each id. And then we iterate over the ids from biggest to lowest and wherever the occurence is equal or higher we take that id, the benefit of iterating from biggest id to smallest is that it is guaranteed if the occurence is higher or equal, the next id is smaller and we want the smallest id with the highest occurence.