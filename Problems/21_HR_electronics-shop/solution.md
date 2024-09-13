```cpp
int getMoneySpent(vector keyboards, vector drives, int b) { int n{static_cast(keyboards.size())}; int m{static_cast(drives.size())};

sort(keyboards.begin(),keyboards.end()); //O(nlogn)
sort(drives.begin(), drives.end());     //O(mlogm)

int kb_ptr{n-1};
int d_ptr{0};

int result{-1};
while(kb_ptr >=0 && d_ptr<=m ) {                //O(n+m)
    if(keyboards[kb_ptr]+ drives[d_ptr] <= b){
        result=max(result, keyboards[kb_ptr] + drives[d_ptr]);
        ++d_ptr;
    }
    else{
        --kb_ptr;
    }
}
return result;

}
```
 - The logic is simple, we sort both the arrays, then put pointer 1 on the end of 1 array and pointer 2 at the start of the other. Then just like doing 2 pointer problems, if the sum of value at pointer 1 + pointer 2 is less or equal than our target value, we store the result and increment pointer 2, if its greater then we decrement pointer 1, thereby only traversing both arrays only once.
 - TC: O(n+m + mlogm + nlogn)