```cpp
void compute() {
  int max_height{1};
  int letters{static_cast<int>(word.size())};
  for (int i{}; i < letters; ++i) {
    max_height = max(max_height, sizes[static_cast<int>(word[i]) - 97]);
  }
  result = max_height * letters;
}
```
- We simply find the max height and then multiply it with the number of letters in the word.