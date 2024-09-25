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

- There are many solutions, one is sorting, one is by using hashmap or just a map and then we store the counts for each letter in 2 maps, one for s and one for t, and then firstly compare the sizes of s and t, if they are same then that means same no. of characters, this means there can't be a situation like "bcaaa" and "aaabcd", why is that a problem is given in a second. Then we simply iterate over keys of the first map and compare it with the keys of second map and see if all the counts are the same, now since we already checked the sizes, this means the total sum of all values will be same for both, but if we hadn't there could be a situation like "bcaaa" and "aaabcd" where whilst the counts of the letters would come out same, there'd be more elements in the second map.
- Then my solution is that since we know the constraints by the question (there are only letters, meaning the 26 ascii english alphabets), we can have 2 fixed size arrays and we do something similar to the above solution, we simply store the counts and then since we can use an array, and there are fixed no. of elements, we don't need to worry about TC and can directly just check all 26 values in both the arrays if all their counts are the same. But having the size comparison early on can short circuit and save time.
