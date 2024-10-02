```cpp
void compute() {
  result = 0;
  n = arr.size();
  if (n == 0) {
    return;
  }
  set_arr = unordered_set<int>(arr.begin(), arr.end());
  auto it{set_arr.begin()};

  int current_count{1};
  result = 1;
  while (set_arr.size() > 0) {
    auto prev{set_arr.find(*it - 1)};
    auto next{set_arr.find(*it + 1)};
    if (prev != set_arr.end()) {
      it = prev;
    } else if (next != set_arr.end()) {
      ++current_count;
      result = max(current_count, result);
      set_arr.erase(it);
      it = next;
    } else {
      set_arr.erase(it);
      if (set_arr.size() == 0) {
        return;
      }
      it = set_arr.begin();
      current_count = 1;
    }
  }
}
```
- We need to find the largest conescutive element sequence, where the difference between any 2 consecutive elements is exactly 1. The order of the numbers don't matter from the original array, the count of a single element doesn't matter and we just need to find elements that can create a sequence. 
- To solve this we can simply look at the sequences, and make some observations, the left of every sequence start, that is the first element of every sequence has no element smaller than it, and its last element has no element greater than it. This means, that if we have a queryable data structure we can ask that for a random element if there's an element smaller than it in it, if yes, then this isn't a sequence start element, and then we go to the next random element, see if there's an element smaller than it, if not then we know this is a sequence start so we query the next bigger element, and track sequence size and store it and so on until an element greater than it doesn't exist. Now we go to the next random element in the sequence and so on until its end. The queryable data structure shouldn't have any duplicates, otherwise we might iterate over the same sequences multiple times. Our logic ensures we visit each element exactly twice, once in the general next random element loop and the other in the sub loop of following every element's sequence, we can observe that every element can only exist exactly 1 sequence (as it will be covered in its sequence and mini sequences like [4,5] will be included in larger sequences like [1,2,3,4,5,6]). 
TC will be O(n) in average case if each query takes O(1) and storing each element takes O(1), which would be true for hashable data structures like unordered map or unordered set, but for worst case it can be O(n*n) if the hash collides.

Another solution is sorting the input array, tracking maximum sequence size and ignoring duplicate elements in the trackings by checking if the difference between any 2 consecutive elements is exactly 1, which classifies a sequence as a consecutive element sequence.
TC O(nlogn) 
But this solution could be better in raw performance as the constant factors with hashing and hash based data structures along with their hash algorithm collide chances can take longer.