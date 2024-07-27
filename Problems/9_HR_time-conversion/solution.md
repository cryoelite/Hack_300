```cpp
void compute() {
  int hour{stoi(s.substr(0, 2))};
  string s_hour{};
  if (s[8] == 'A') {
    if (hour == 12) {
      s_hour = "00";
    } else {
      s_hour = s.substr(0, 2);
    }
    s_converted = s_hour.append(s.substr(2, 6));
  } else {
    string_view s_minute{s.substr(3, 2)};
    string_view s_seconds{s.substr(6, 2)};
    if (hour != 12) {
      hour += 12;
    }
    s_hour = to_string(hour);

    s_converted =
        s_hour.append(":").append(s_minute).append(":").append(s_seconds);
  }
}
```
- Some string manipulation