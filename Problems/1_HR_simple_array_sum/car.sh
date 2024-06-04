#!/bin/bash

echo "Getting env variable"
env_var=$(<../../.env)
export "${env_var?}"=true
clang++ problem.cpp -o problem -std=c++20 && ./problem
