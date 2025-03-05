#set page(width: 8.5in, height: 11in, margin: 0.5in)
#show table.cell.where(y: 0): strong
#set table(
  stroke: (x, y) => if y == 0 {
    (bottom: 0.7pt + black)
  },
  align: (x, y) => (
    if x > 0 { center }
    else { left }
  )
)
#set heading(numbering: "1.")
#set math.equation(numbering: "(1)")
#align(center, text(17pt)[
  *Compiler 构建顺序
  *
])
#align(center, text(12pt)[
  *2025/3/5 v1.0
  *
])


= Compiler 梗概
+ 寄存器分配 线性分配(linear scanning)
   通用寄存器 暂存到  浮点寄存器
+ 缓存优化 (循环展开 循环交换顺序)
+ inline 函数内联
+ gvngcm  死代码删除 常量传播 
+ 多线程 做矩阵乘法分块
以上顺序从上往下优化效果 逐渐微弱

= 工程建议

== 使用 tablegen 生成 ir 和 reg 的结构体

#image("base.td.png",width:  60%)

注意，llvm并没有使用类似于 Variant 的机制，而是使用一个枚举类型来表示不同的类型，但这样的问题就在于需要写很多的子类来实现多态




