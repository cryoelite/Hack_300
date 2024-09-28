```cpp

void compute() {
  if (s.size() != t.size()) {
    result = false;
    return;
  }

  fill(letters_s.begin(), letters_s.end(), 0);
  fill(letters_t.begin(), letters_t.end(), 0);

  int n{static_cast<int>(s.size())};
  for (int i{}; i < n; ++i) {
    int index = static_cast<int>(s[i]) % 26;
    letters_s[index]++;
  }
  for (int i{}; i < n; ++i) {
    int index = static_cast<int>(t[i]) % 26;
    letters_t[index]++;
  }
  for (int i{}; i < 26; ++i) {
    if (letters_s[i] != letters_t[i]) {
      result = false;
      return;
    }
  }
```

- There are many solutions, one is sorting (we simply sort both and compare, O(nlogn + klogk)), one is by using hashmap or just a map and then we store the counts for each letter in 2 maps, one for s and one for t, and then firstly compare the sizes of s and t, if they are same then that means same no. of characters, this means there can't be a situation like "bcaaa" and "aaabcd", why is that a problem is given in a second. Then we simply iterate over keys of the first map and compare it with the keys of second map and see if all the counts are the same, now since we already checked the sizes, this means the total sum of all values will be same for both, but if we hadn't there could be a situation like "bcaaa" and "aaabcd" where whilst the counts of the letters would come out same, there'd be more elements in the second map.
Map Retrieval is Logn no matter best or worst case, unordered map retrieval (find) is O(n) in worst cast but its average case is O(1) and a good hashing algorithm and its implementation can ensure that the worst case (collisions) occur very rarely, so the tradeoff of using an unordered map may be small, (The hashing alg matters a lot in this case, there are a lot of hashing algorithms and one such is splitmix, codeforces https://codeforces.com/blog/entry/62393 and stackoverflow https://stackoverflow.com/a/12996028/13036358 have some better info on it, this is a splitmix implementation http://xorshift.di.unimi.it/splitmix64.c, https://github.com/rurban/smhasher and https://stackoverflow.com/a/69812981/13036358 have furthermore hashing algs with rapidhash being a good one, and https://github.com/skeeto/hash-prospector for integer hashing algs specifically), the basic implementation in unordered map is still good enough though.

- Then my solution is that since we know the constraints by the question (there are only letters, meaning the 26 ascii english alphabets), we can have 2 fixed size arrays and we do something similar to the above solution, we simply store the counts and then since we can use an array, and there are fixed no. of elements, we don't need to worry about TC and can directly just check all 26 values in both the arrays if all their counts are the same. But having the size comparison early on can short circuit and save time.
