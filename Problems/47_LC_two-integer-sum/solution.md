```cpp
void compute() {
  result = vi(2, 0);
  bucket = umii();
  int n{static_cast<int>(arr.size())};
  for (int i{}; i < n; ++i) {
    auto it{bucket.find(target - arr[i])};
    if (it != bucket.end()) {
      result[0] = it->second;
      result[1] = i;
      break;
    } else {
      bucket[arr[i]] = i;
    }
  }
}
```
- We simply use a hashmap (and not a normal map because whilst normal maps could take lesser memory, and are ordered by their keys, they are faster when keys are non trivial like ints, this is because with ints the whole value is used for everything but with other data structures such as strings, only the first few characters until a difference is found is the search executed, source: https://stackoverflow.com/a/2197457/13036358), and store all the values as we come across them, then later when another value that when subtracted from the target need this value to add up and make the target, and when we have such a pair, we get our result. Since we are only going one way, and once, we ensure that if a pair (i , j) exist, and `i<j` then we would have gone over i and not found j, then at j found out i and get our value. And so our pair never repeats.