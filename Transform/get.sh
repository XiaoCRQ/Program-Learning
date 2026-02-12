#!/usr/bin/env bash
set -euo pipefail

# 输入文件，默认 get/test.cpp
INPUT_FILE="${1:-get/test.cpp}"

# 创建结果目录
mkdir -p Template/Transform/result

# 临时文件
tmp_include=$(mktemp)
tmp_body=$(mktemp)
trap 'rm -f "$tmp_include" "$tmp_body"' EXIT

# 宏展开文件路径
RES_DEF="Template/Transform/result/res_def.cpp"
RES="Template/Transform/result/res.cpp"
RES_LINE="Template/Transform/result/res_line.cpp"

echo "生成宏展开内容 -> $RES_DEF ..."
# 提取 include
grep '^[[:space:]]*#include' "$INPUT_FILE" >"$tmp_include"
# 提取主体
grep -v '^[[:space:]]*#include' "$INPUT_FILE" >"$tmp_body"
# 宏展开并合并到 tmp_include
g++ -E -P -x c++ "$tmp_body" >>"$tmp_include"
# 保存到 res_def.cpp
mv "$tmp_include" "$RES_DEF"

# echo "编译 bin/transform_line.cpp ..."
# g++ -O2 Template/Transform/bin/transform_line.cpp -o Template/Transform/bin/transform_line
# echo "编译 bin/transform.cpp ..."
# g++ -O2 Template/Transform/bin/transform.cpp -o Template/Transform/bin/transform

echo "运行 transform ..."
./Template/Transform/bin/transform <"$RES_DEF" >"$RES"

echo "运行 transform_line ..."
./Template/Transform/bin/transform_line <"$RES_DEF" >"$RES_LINE"

echo "完成！输出文件在 Template/Transform/result/ 目录下："
echo "  res_def.cpp  (宏展开后的文件)"
echo "  res.cpp      (transform 结果)"
echo "  res_line.cpp (transform_line 结果)"
