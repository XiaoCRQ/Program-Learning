#!/usr/bin/env bash
set -e
INPUT_FILE="${1:-test.cpp}"
mkdir -p result
mkdir -p bin
echo "编译 bin/transform_line.cpp ..."
g++ -std=c++17 -O2 bin/transform_line.cpp -o bin/transform_line
echo "编译 bin/transform.cpp ..."
g++ -std=c++17 -O2 bin/transform.cpp -o bin/transform
echo "运行 transform ..."
./bin/transform <"$INPUT_FILE" >result/res.cpp
echo "运行 transform_line ..."
./bin/transform_line <"$INPUT_FILE" >result/res_line.cpp
echo "完成！输出文件在 result/ 目录下："
echo "  res.cpp"
echo "  res_line.cpp"
