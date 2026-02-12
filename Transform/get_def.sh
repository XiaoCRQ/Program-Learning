#!/usr/bin/env bash
set -euo pipefail
infile=${1:-get/test.cpp}
outfile=${2:-get/test_out.cpp}
tmp_include=$(mktemp)
tmp_body=$(mktemp)
trap 'rm -f "$tmp_include" "$tmp_body"' EXIT
grep '^[[:space:]]*#include' "$infile" >"$tmp_include"
grep -v '^[[:space:]]*#include' "$infile" >"$tmp_body"
g++ -E -P -x c++ "$tmp_body" >>"$tmp_include"
mv "$tmp_include" "$outfile"
echo "生成完成: $outfile"
