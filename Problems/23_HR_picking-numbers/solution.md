```cpp
void compute() {
  for(int i{};i<n;++i){
    f[arr[i]]++;
  }
  for(int i{};i<100;++i){
    result=max(result, f[i-1]+f[i]);
  }
}
```
- The logic is simple, we use a frequency array. Firstly, the problem statement is about the maximum subsequence not subarray, with difference between any 2 elements being 1. Secondly, since the difference can only be 1 between any 2 elements, that means either the subsequence can have an element x as the smallest element by value or the biggest, but not both, so [4,3,5] can have subsequences [4,3] or [4,5] from 4, but not both as [4,3,5] would have 5-3=2 as difference.
Now there can only be limited number of integer values, (100 here), as given in the problem statement, we simply index the occurences of all the elements and then check the frequency of every consecutive element in the frequency array, this is paired with the above fact, meaning every consecutive pair is checked. This works because there can only be 2 different numbers in the subsequence and their position in the array has no implication, if it's [4,3] then all 4 and 3 in the array withh be in the subsequence, regardless of where they are. This is why we can directly check the frequency array and get out max subsequence element count.