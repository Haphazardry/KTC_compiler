export td_dir=$(pwd)
cd ~/llvm-project/build
ninja llvm-min-tblgen 
./bin/llvm-min-tblgen --ktc-decls "$td_dir/ktc.td" -o "$td_dir/ktc.h.inc"
echo "generate ktc.h.inc done "