# 3 integer sum
* Given an array n, we have to find triplets, i.e., a,b and c values in it that when summed give a 0, and we have to find all possible distinct triplets in it, i.e., triplet array x mustn't have the same a, b and c as a triplet array y if x and y 2 distinct triplets, they can have 2 same or 1 same elements but not all 3. 
* a,b,c must have distinct indices, but the values theirselves needn't be distinct amongst each other, i.e., a=b=c is ok, but their indices in n must be distinct.
* x[], y[] etc. all triplets must be distinct (i.e., they should all have atleast 1 different element amongst these triplet arrays).

* Constraints:
  
    3 <= nums.length <= 1000
    -10^5 <= nums[i] <= 10^5
Hm, there will atleast be 3 elements and they can be in a range which is quite large.

* Classification: 2 pointer
* Hm, some observations, firstly if we are using 2 pointers and finding the third element, then an order is a good idea, *sorting* can be first step.
* 