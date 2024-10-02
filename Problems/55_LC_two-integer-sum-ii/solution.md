# Integer Sum 
* Find 2 indices in 1-indexed, i1 and i2, such that `i1 < i2` and `i1 + i2`==`target`. Input is an array and target.
* Sorted array
* Constraints

    2 <= numbers.length <= 1000
    -1000 <= numbers[i] <= 1000
    -1000 <= target <= 1000

* Classification: 2 pointer
* We have solved this problem before. If the array wasn't sorted we would use a unordered map and for every element x query it for target-x if such an element exists we have our pair, x and target-x, if not we store x in the unordered map and move on. Here we can take 2 ptrs, ptr1 at 0 and ptr2 at size-1, and for every pair ptr1+ptr2 see if it is less than target, then we increase ptr1 thereby increasing our sum, greater than target, then we reduce ptr2, thereby decreasing our sum and if equal to target then we have our pair.

```cpp
void compute() {
  n = arr.size();
  result = vi(2, 0);
  size_t ptr1{0};
  size_t ptr2{n - 1};

  while (ptr1 < ptr2) {
    if (arr[ptr1] + arr[ptr2] == target) {
      result[0] = ptr1+1;
      result[1] = ptr2+1;
      break;
    } else if (arr[ptr1] + arr[ptr2] < target) {
      ++ptr1;
    } else { // sum is greater than target.
      --ptr2;
    }
  }
}
```