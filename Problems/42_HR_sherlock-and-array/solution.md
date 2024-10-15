# Middle element
- Given an array of ints
- If there's an element such that the sum of elements to its left, is equal to the sum of elements to its right, return YES, else NO.
  Constraints:
  T, Test cases, 1 to 10
  n, array size, 1 to 1e5
  arr[i], 1 to 2*1e5
  i, >=0 and `<n`. Hm, wonder why this is given
We can see values are only positive.

# Classification: Prefix Postfix, hm and 2 pointers
- We have solved a problem like this before (Leetcode products of array discluding self), since we would need the sum of elements to the left of all elements, and same for the right, we can preprocess that and then directly look at these 2 processed arrays for each index, and just compare the left of i in preprocessed array, and right of i in postprocessed array, and compare for each i. We can use an optimization on it to simply use 1 singular extra array, and put preprocessed values in it then for postprocessed values . TC is O(n) but SC is also O(n).
- Another alternative is, we take 2 pointers and 2 sums, left sum and right sum, left pointer and right pointer, then we compare the sums, from left of array to left pointer, and right to right pointer and if left is greater than right, we increase right pointer, the opposite for the opposite, if they are equal we increment either of them. And we do this till the distance between remain >2. Then when that becomes the case, we compare left sum and right sum, and if it is still equal, that means there was an element where its left and right sums became equal. By trying to balance left sum and right sum, and checking if the distance between them became 2 (left pointer < right pointer - 1), we can find an element whose left and right sums are equal. Since the integers can only be positive, we know that increasing the pointers from either direction mean increasing the sum, it wouldn't be the case if there could be negative values too, in that case, we could increase the pointer to reduce the sum too, which would mean even if the right sum is greater, increasing the left pointer doesn't guarantee increasing the sum, so maybe we can increase the right, or maybe the left if next is positive, and our algorithm would be more complex, so we can use this approach here. 

```cpp
void compute() {
  int l_sum{0};
  int r_sum{0};
  auto l_ptr{arr.begin()};
  auto r_ptr{arr.end()};
  while (r_ptr > l_ptr + 1) { // or distance(r_ptr,l_ptr) >= 1
    if (r_ptr == l_ptr + 2) {
      if (l_sum == r_sum) {
        result = "YES";
        return;
      } else {
        result = "NO";
        return;
      }
    } else {
      if (l_sum + *(l_ptr + 1) <= r_sum + (*r_ptr - 1)) {
        ++l_ptr;
        l_sum += *(l_ptr + 1);
      } else {
        --r_ptr;
        r_sum += *(r_ptr - 1);
      }
    }
  }
}
```
- Fails on n=5, arr=[1,1,4,1,1], gives false when True because l_ptr starts at 1 while r_ptr starts at 0 (end is 0, undefined though).

The original solution with prefix array is much simpler to implement, takes SC of n fixed, but O(n).
```cpp

void compute() {
  // prefix
  int sum{0};
  prefix[0] = 0;
  for (size_t i{1}; i < n; ++i) {
    sum += arr[i - 1];
    prefix[i] = sum; // sum till i (exclusive)
  }

  sum = 0;
  for (size_t i{n - 1}; i >= 0 && i < n; --i) {
    if (prefix[i] == sum) {
      result = "YES";
      return;
    }
    sum += arr[i];
  }
}

```