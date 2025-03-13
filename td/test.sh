cd ~/llvm-project-main/llvm/build
ninja llvm-min-tblgen 
./bin/llvm-min-tblgen --ktc-decls ../tests/ktc.td -o ../tests/ktc.h.inc
echo "generate ktc.h.inc done "