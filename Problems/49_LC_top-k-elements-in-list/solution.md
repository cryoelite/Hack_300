```cpp
void compute() {
  n = static_cast<int>(arr.size());
  count = unordered_map<int, int>();
  bucket = vector<vi>(n + 1, vi());
  result = vi();
  for (int i{}; i < n; ++i) {
    ++count[arr[i]];
  }

  for (auto &elem : count) {
    bucket[elem.second].push_back(elem.first);
  }

  for (auto it{bucket.end() - 1}; it >= bucket.begin() && k > 0; it--) {
    int size{static_cast<int>(it->size())};
    for (int i{0}; i < size && k > 0; ++i, --k) {
      result.push_back((*it)[i]);
    }
  }
}
```
- Multiple solutions, one, since we have only -1000 to 1000 as range of n[i], we can create an array of size 2000, and store every element at index (n[i] + 1000) in it with its count as the value, and then simply iterate over the array to find the biggest count, then the next smaller one and so on for k times, so O(n+2000*k), basically O(n+k) with a decent constant factors.
- Another solution is to store the elements and their counts as pairs in an unordered map, then we simply create a bucket, a vector of vectors where we simply go, for each bucket[i], the i is the actual count and its vector will have elements that have the i count, so if we have [1,2,3,3] then bucket[2] will be [3] and bucket[1] will be [1,2], this bucket will be of size n because we can have at most n elements so the total count of any 1 element cannot exceed n. Now we simply iterate from this bucket's back and get k elements from it. TC will be $$O(n^2 + k)$$ in the worst case where each element insertion in the unordered map takes O(n), but since this is highly unlikely and can be improved by improving the hashing algorithm, we can rely on the average case most of the times, which is O(1) so O(n+k) is our most probably TC, SC is O(k). 
- And yet another solution is to instead of having a bucket, we simply move all elements of the map into a vector or a set and sort by the count, then simply take k elements, TC will be O(nlogn).