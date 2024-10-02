# Is-Palindrome
* To find if a string is palindrome, case-insensitive, ignore non-alphanumeric characters, i.e., the string `"x X?"` is a palindrome. Return `true` if yes or `false` if not.
* Constraints: Size can be min 1 element in string, max 1000.
  
* Classification: 2 pointers.
* We can use 2 pointers, one at start one at end, tolower the value and compare and run while ptr1 != ptr2, if the size is 1, then it wont run in the first place. 
* tolower(non alphanumeric character) returns the int value for the non alphanumeric character as-is.

```cpp
void compute() {
  result = false;
  auto ptr1{s.begin()};
  auto ptr2{s.end()};

  while (ptr1 < ptr2) {
    if (!((*ptr1 >= '0' && *ptr1 <= '9') || (*ptr1 >= 'a' && *ptr1 <= 'z') ||
          (*ptr1 >= 'A' && *ptr1 <= 'Z'))) {
      ++ptr1;
      continue;
    }
    if (!((*ptr2 >= '0' && *ptr2 <= '9') || (*ptr2 >= 'a' && *ptr2 <= 'z') ||
          (*ptr2 >= 'A' && *ptr2 <= 'Z'))) {
      --ptr2;
      continue;
    }
    if (tolower(*ptr1) != tolower(*ptr2)) {
      result = false;
      return;
    }

    ++ptr1;
    --ptr2;
  }

  result = true;
}
```