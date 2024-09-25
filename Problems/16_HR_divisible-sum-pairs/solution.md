```cpp
void compute() {
  for (int i{}; i < n; ++i) {
    ++f[arr[i] % k];
  }

  for (int i{0}; i < k; ++i) {
    int value{(k - i) % k};
    if (value > i) {
      result += f[value] * f[i];
    } else if (value == i) {
      result += (f[value] * (f[value] - 1) / 2);   //if i and k-value%k is 0, then to find number of 2 element pairs from a list of n elements we use the formula n(n-1)/2
    }
  }
}
```
TC: O(n+k)
SC: O(k)

A better solution 
```cpp
 int divisibleSumPairs(int n, int k, vector<int>ar) {
   auto bucket{vector<int>(k,0)};
    int count = 0;
    for (int elem : ar) {
        int modValue = elem % k;
        count += bucket[(k - modValue) % k]; // adds # of elements in complement bucket
        bucket[modValue]++;                  // saves in bucket
    }
    return count;
}
```
TC: O(n+k)
SC: O(k)

- The problem is quite simple but it requires usage of mod and its properties. 
  We can know that there can be an element i, and then its compliment j, when i+j mod k, they make 0. So this means, if we have i, we can find j as k-(i mod k) mod k (say i is 5 and k is 5, then 5 mod 5 will be 0 and 5-0 will make 5, we don't really need another 5, we need another 0), now why is so ? Because all the elements in arr when modded with k will fall into k places, say we have k as 5, and have 2 values, 1 and 4, we know 1+4 = 5 and 5%5 = 0 so thats a valid pair, then if we have just 4, we can do 4%5 we get a 4, and we can see we need a 1, so we go 5-4%5, which gives us a 1, if we count how many values make value%5 = 1, and then add that count, we have that many pairs, so here we have 1 such value and hence, we have 1 pair. The second code is quite elegant because it removes the problem of duplicate pairs, that is, whilst we know 1 needs a 4, 4 also needs a 1, since it is going one way once, it will have one count as 0 at one point and then when its at the other value, the other would have been initialized so it'll get the correct count exactly once.
- 