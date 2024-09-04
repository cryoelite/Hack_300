```cpp
int changeLevel(int level, char step)
  {
    if (step == 'D')
    {
      return level - 1;
    }
    else
    {
      return level + 1;
    }
  }

  void compute()
  {
    int currentLevel{0};
    for (int i{}; i < steps; ++i)
    {
      if (currentLevel == 0 && arr[i] == 'D') //if the next step is a step down from sea level
      {
        ++result;
      }
      currentLevel= changeLevel(currentLevel, arr[i]);
    }
  }
  ```
  - We simply see how many times we step down from sea level. A better approach (by idea) is to check how many times we come up instead, because it's fairly possible the inputs don't end up at sea level, here they do, but they might not, in which case, it's possible we step down and that's when the array ends, and we dont have a complete valley yet.