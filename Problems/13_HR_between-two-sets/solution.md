```cpp
void compute() {
  int lcm_a{a[0]};
  int gcd_b{b[0]};
  for (int i{1}; i < n; ++i) {
    lcm_a = lcm(lcm_a, a[i]);
  }
  for (int i{1}; i < m; ++i) {
    gcd_b = gcd(gcd_b, b[i]);
  }
  for (int i{lcm_a}; i <= gcd_b; i += lcm_a) {
    if (gcd_b % i == 0) {
      ++result;
    }
  }
}
```
- The logic is simple, we need the count of numbers such that each number, say x, is firstly divisible by all numbers of array a, meaning x is an lcm or a multiple of the lcm of a, lcm is the least common multiple or the smallest number that is divisble by all elements of a set, which is array a here. Then secondly x must divide all numbers of b, meaning x is the gcd or a divisor of the gcd. And we need the count of these x's that satisfy both these conditions. 
- x can be a multiple of lcm because we know if a divides x, then c\*x must still be divisible with a where c is an integer, like if 2 divides 4 then 2 will still divide any integer number times 4, such as 5, like 5*4, this is because it shares some factors, its factors are 2\*2\*5, so if we divide it by 2, then one of them will be gone leaving 2\*5, hence if a divides x, then a divides kx, as the factors divisible by 2 still remain.
- x can be a divisor of the gcd because if x divides a, then if c divides x, c divides a, this is because of the same principle. Say a = k\*x, as x divides a but is smaller so some integer times x will divide a, now x= m\*c, similarly. So, a = k\*m\*c, and hence we can see that similar to our previous logic c still has factors that can divide a, if c divides x, because it must have the same factors to divide x, and x will have the same factors to divide a. 
- Hence, we can find numbers in the range lcm(array a) to gcd(array b), checking if lcm(array a) divides gcd(array b) avoiding unneeded iteration of b, and if we go with jumps of lcm(array a) we know that it will still be divisible by a, and will be the next smallest number of that kind, because it will be lcm(array a) + lcm(array a), it shares the exact same factors but more of them and hence it will still be divisible, and it will be the smallest because its the lcm being added, its the smallest number that is divisble by all the numbers of a, like, lcm(2,5) is 10, and then 10+10 is still divisible by 2 and 5, and its the next smallest too, because a jump of either 2 (making 12) or 5(making 15) is not divisible by 10, and the number that is divisible, i.e., 10, is the lcm, which is the point of the lcm.  