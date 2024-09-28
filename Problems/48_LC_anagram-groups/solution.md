```cpp
void compute() {
  int n{static_cast<int>(arr.size())};
  result=vvs();
  words = map<array<int, 26>, vector<string>>();

  for (int i{}; i < n; ++i) {
    array<int, 26> word{};
    int k{static_cast<int>(arr[i].size())};
    for (int j{}; j < k; ++j) {
      ++word[arr[i][j] % 26];
    }
    words[word].push_back(arr[i]);
  }
  auto it{words.begin()};
  while(it!=words.end()){
    result.push_back(std::move(it->second));
    ++it;   
  }
}
```

- 3 solutions, as with the previous is_anagram, we can use either sorting (create a umap where key is the sorted string and value is vector with indices of anagrams and we sort and check, and then store the indices together O(nklogk) if n is the size of the array and k is the maximum size of any string and we don't consider umap retrieval which can be O(n) hence we can have O(n^2 \* klogk)) or we use a modified version of the previous solution, with a vector of fixed size arrays O(26\*n\*k), where we have to check potentially n elements in the vector with 26 places for all k elements in the strings, a map can uplift the checking from an O(k) operation to a O(logk) operation, meaning retrieval is O(n\*logk), and total TC is O(n*klogk).
- 