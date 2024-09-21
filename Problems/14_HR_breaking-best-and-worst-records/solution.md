```cpp
void compute() {
  int min_score{scores[0]};
  int max_score{scores[0]};
  for (int i{1}; i < n; ++i) {
    if (scores[i] < min_score) {
      min_score=scores[i];
      ++scores_broken[1];
    } else if (scores[i] > max_score) {
      max_score= scores[i];
      ++scores_broken[0];
    }
  }
}
```
