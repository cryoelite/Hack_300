```cpp
  void compute()
  {
    int item_value{bill[k]};
    int total_bill{accumulate(bill.begin(), bill.end(), 0) / 2};
    if (b == total_bill - (item_value / 2))
    {
      result = "Bon Appetit";
    }
    else
    {
      result = to_string((item_value) / 2);
    }
  }
  ```
- Simply add all the values in the bill to check if the excluded item's value from the sum is equal to what Brian charged Anna, if it is then he already deducted the value and hence we can show Bon Appetit, otherwise, we give the excluded item by 2 back to Anna. We give the divided by 2 value because Anna and Brian paid their shares together, meaning either only paid 1/2 of an item's value really. 