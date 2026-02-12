#!/usr/bin/env bash
set -e

SRC="test.cpp"
OUT_DIR="Output"
OUT="$OUT_DIR/test"
IO_DIR="io"
TESTS=10
TIME_LIMIT=3 # 秒

# 创建输出目录
mkdir -p "$OUT_DIR"

# ANSI 颜色
GREEN="\033[1;32m"
RED="\033[1;31m"
YELLOW="\033[1;33m"
RESET="\033[0m"

# 编译
echo -e "\033[1;34mCompiling $SRC...\033[0m"
g++ -O2 -Wall "$SRC" -o "$OUT"

for i in $(seq 1 $TESTS); do
  IN_FILE="$IO_DIR/in_$i"
  REF_FILE="$IO_DIR/out_$i"
  OUT_FILE="$IO_DIR/out"
  TIME_TMP="$OUT_DIR/time.tmp"

  # 开始高精度计时
  start=$(date +%s.%N)

  # 使用 timeout + /usr/bin/time 记录内存
  if timeout "$TIME_LIMIT" /usr/bin/time -f "%M" -o "$TIME_TMP" "$OUT" <"$IN_FILE" >"$OUT_FILE"; then
    # 程序正常结束
    end=$(date +%s.%N)
    TIME_MS=$(awk -v s="$start" -v e="$end" 'BEGIN{printf "%.3f", (e-s)*1000}')
    MEM_KB=$(cat "$TIME_TMP")

    # 对比输出
    if diff -q "$OUT_FILE" "$REF_FILE" >/dev/null; then
      STATUS="${GREEN}✅ AC${RESET}"
    else
      STATUS="${RED}❌ WA${RESET}"
    fi
  else
    # 程序超时或被杀死
    TIME_MS=$(awk -v t="$TIME_LIMIT" 'BEGIN{printf "%.3f", t*1000}')
    MEM_KB=0
    STATUS="${YELLOW}⏰ TLE${RESET}"
    pkill -f "$OUT" || true
  fi

  # 输出格式
  echo -e "Running test case $i —— ${STATUS} ${TIME_MS}ms ${MEM_KB}kb"
done

# 删除临时文件
rm -f "$TIME_TMP"
