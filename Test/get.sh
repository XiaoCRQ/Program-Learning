#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
compile() {
  src=$1
  out=$2
  echo "  -> $src"
  g++ -O2 -Wall "$src" -o "$out"
}
echo "[*] Compiling generators..."
compile get/get_in.cpp Output/get_in
compile get/get_out.cpp Output/get_out
compile get/get_in_up.cpp Output/get_in_up
compile get/get_in_down.cpp Output/get_in_down
compile get/get_in_mix.cpp Output/get_in_mix
compile get/get_in_hash.cpp Output/get_in_hash
echo "[+] Compile done."
mkdir -p io
rm -f io/in_* io/out_*
echo "[*] Generating random inputs..."
for i in {1..6}; do
  echo "  -> in_$i"
  ./Output/get_in >io/in_$i
done
echo "[*] Generating special inputs..."
echo "  -> in_7"
./Output/get_in_up >io/in_7
echo "  -> in_8"
./Output/get_in_down >io/in_8
echo "  -> in_9"
./Output/get_in_mix >io/in_9
echo "  -> in_10"
./Output/get_in_hash >io/in_10
echo "[*] Generating outputs..."
for i in {1..10}; do
  echo "  -> out_$i"
  ./Output/get_out <io/in_$i >io/out_$i
done
echo "[+] All done."
