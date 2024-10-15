# Toy and Budget balancing
- Given an array of prices and a target integer called budget
- Find the max number of toys that can be bought with that budget. Return an int, i.e., amongst all possible combinations of toys that can fit in the budget, i.e., sum of all elements in their array <= budget, find the size of the array with the maximum no. of elements.

- Constraints:
  n >= 1 and <= 1e5
  k (target) >= 1 and <= 1e9
  price[i] >= 1 and <= 1e9

Only positive values. No negative values.

# Classification: Sorting

- One solution off the top of my head is, we can do sort + sliding window, that is, we first sort. Then we take 2 pointers, start them at start and start+1, then increase the right pointer to increase the sum and do so until sum of all elements in the sequence is <= target and stop once it goes over, then we store the count of elements in the section and increase the left pointer, reducing sum and changing the sequence, and repeat the process.
- TC: O(nlogn) in worst case. as we sort taking nlogn, then we go over each element at most 2 times.

```cpp
void compute() {
    result=1;
  for (int i{1}; i < n; ++i) { // if size is 1, won't run.
    if (arr[i] < arr[i - 1]) {
      sort(arr.begin(), arr.end());
      break;
    }
  }

  auto ptr1{arr.begin()};
  auto ptr2{arr.begin() + 1};
  int c_sum{*ptr1}; // current sum
  int c_count{1};   // current count
  while (ptr1 < ptr2 &&
         ptr2 < arr.end()) { // if size is 1, ptr2 is already at end, no work.
    if (c_sum + *ptr2 <= k) {
      c_sum += *ptr2;
      ++c_count;
      ++ptr2;
      result = max(result, c_count);

    } else {
      c_count = 1;
      ++ptr1;
    }
  }
}
```