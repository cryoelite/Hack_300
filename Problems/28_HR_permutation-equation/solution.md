```cpp
void compute() {
  int y{};
  int x{};
  for (int i{1}; i <= n; ++i) {
    y = arr[i];
    x = arr[arr[y]];

    result[x] = y;
  }
}
```
- We know for every value of x from 1 to n, we have to find y, we know y is p(p(y))=x, and we simply return this y array b, where b(i)=y for each value of x from 1 to n. 
If the array is a.
If we directly search for each value, i.e. for x being 1 what is the y, it will be O(n*n). Instead we can go the opposite way around, we find where each arr(i) will end up in b. We know p(p(y)) = x, so if we know y, which we do traversing from arr(0) to arr(n), we can find its x, we simply do a(a(y)) to get the x, and then simply do b(x)=y. 