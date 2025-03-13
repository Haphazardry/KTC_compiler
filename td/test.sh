<<<<<<< HEAD
cd ~/llvm-project-main/llvm/build
ninja llvm-min-tblgen 
./bin/llvm-min-tblgen --ktc-decls ../tests/ktc.td -o ../tests/ktc.h.inc
=======
export td_dir=$(pwd)
cd ~/llvm-project/build
ninja llvm-min-tblgen 
./bin/llvm-min-tblgen --ktc-decls "$td_dir/ktc.td" -o "$td_dir/ktc.h.inc" -I "$td_dir"
>>>>>>> fd272d2af98b7bbdb1ae3c5d49fc1d4690d4d787
echo "generate ktc.h.inc done "