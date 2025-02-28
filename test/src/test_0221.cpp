//1.测试regstate free_once()
#include "builder.h"

#include "regtab.h"
using namespace KTC;
int main(){
    SymIdx sm1 = SymIdx(0,"x");
    SymIdx sm2 = SymIdx(0,"y",0);
    SymIdx sm3 = SymIdx(0,"y",1);
    RegState RS1 = RegState::new_freed(sm1,false);
    RegState RS2 = RegState::new_occupied(sm2,true,2);
    RegState RS3 = RegState::new_released();
    RS2.free_once();
    RegTab regtab;
    std::cout<< regtab;
    // RS3.free_once();

}