```cpp
void compute() {
  sort(arr.begin(), arr.end());
  auto it1{arr.begin()};
  auto it2{arr.begin() + 1};
  while (it2 != arr.end() && it1 != arr.end() && *it1 != *it2) {
    ++it1;
    ++it2;
  }
  result = !((it1 == arr.end() - 1 && it2 == arr.end()) || it1 == arr.end());
}

```

- Whilst using a set or unordered set might seem ideal, it has shown worse running time than simply sorting and then comparing consecutive elements. This is because the insert and creation of a set or unordered set takes more time. The worst TC for unordered set insert is O(n(size+1)) which is greater than set insert at O(nlog(size+n)) where size is the size of the container if a rehash is triggered, however in running time the normal loop which should take O(nlogn) worst case performs better by 30ms for some arbitrary input size, than unordered set which is slightly faster than set, which performed the worst. However lots of factors and the difference may be negligible, and it may be better to use set but we haven't encountered the case yet.