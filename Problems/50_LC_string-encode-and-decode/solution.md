```cpp
void encode() {
  encoded_value = "";
  for (string &str : arr) {
    encoded_value += str + sep;
  }
}

void decode() {
  result = vector<string>();
  size_t index{0};
  for (size_t pos{encoded_value.find(sep, 0)}; pos != std::string::npos;
       pos = encoded_value.find(sep, sep.size() + pos)) {
    result.emplace_back(encoded_value.substr(index, pos - index));
    index += sep.size() + pos - index;
    if (index >= encoded_value.size()) {
      break;
    }
  }
}

void compute(int mode) { // 0 for encode, 1 for decode
  if (!mode) {
    encode();
  } else {
    decode();
  }
}
```