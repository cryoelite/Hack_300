# jim-and-the-orders
- Given n and 2 arrays, order and prep of size n both, where order[i] and prep[i] mean customer `i`, 1 indexed. 
- Time for each order = order[i] +prep[i]
- We have to find which customers get their orders first by the time needed to prepare their order, if 2 customers get at the same time then the the customers get orders in ascending order of their id. 
- Constraints:
  n>=1 and <= 1e3
  i>=1 and i<=n
  order[i], prep[i] >=1 and <= 1e6

Everything is positive, no negative values, furthermore 1e6 is the highest value so input can fit in an int (which can fit ~1e10 unique values)

# Classification - Sorting ?
- We can create an array time which is an array of pairs, pair<int,int>, first value can be the time taken and second can be customer id, then we can simply store all the times and then sort the array (based on first element of the pair) and simply output that. We have to sort based on customer id too so when 2 `time`s are similar, we compare the customer ids which are guaranteed to be unique for each customer. Definining a custom comparator.
- Seems like a valid solution and can't figure out a better one yet. TC will be O(n logn) in worst case, and SC will be n. 
```cpp
bool is_pair_smaller_customer_comparator(const pair<int, int> &a,
                              const pair<int, int> &b) {
  if (a.first < b.first) {
    return true;
  } else if (a.first > b.first) {
    return false;
  } else { // a.first == b.first
    if (a.second <
        b.second) { // not handling edge case a.second==b.second, which can't be
                    // but if it is, it passes through.
      return true;
    } else {
      return false;
    }
  }
}
void compute() {
  for (size_t i{1}; i <= n; ++i) {
    result[i - 1].first = order[i] + prep[i]; // time
    result[i - 1].second = i;
  }
  sort(result.begin(), result.end(), is_pair_smaller_customer_comparator);
  
}
```
works.