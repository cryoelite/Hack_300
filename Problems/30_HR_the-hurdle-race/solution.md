```cpp
void compute() {
  int max_height{0};
  for(int i{};i<n;++i){
    max_height=max(max_height,arr[i]);
  }
  if(k<max_height){
    result=max_height-k;
  }
}
```