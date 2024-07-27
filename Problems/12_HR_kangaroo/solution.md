```cpp
void compute() {
  if (x1 == x2) {
    result = "YES";
    return;
  }
  if (v1 == v2) { // and x1!=x2 as checked above
    result = "NO";
    return;
  }
  double y{static_cast<double>(x2 - x1) / (v1 - v2)};
  if (y > 0 && floor(y) == y) {
    result = "YES";
  } else {
    result = "NO";
  }
}
```

- We need $$x_1 + y * v_1 = x_2 + y* v_2$$
where y is the jump. We need this equality because only when these values are equal for the same jump, y, the 2 kangaroos are at the same position. If y is negative, then they meet if they were going in reverse, if y is in fraction then they don't meet on an integer point, they can't jump fractionally so this doesn't work either, for them to meet the y has to be a positive integer and that's what we check.