# Topological-Order
拓扑排序输出课表（大学四年）

大一上：
高等数学-I，线性代数(理工)，高级语言程序设计-I，数字逻辑，UNIX操作系统，计算机导论
1高数1，2线性代数，3高语1，4数字逻辑，5UNIX操作系统，6计算机导论

大一下：
高数2(高数1)，概率统计(理工)(高数1)，高级语言程序设计-II(高级语言程序设计-I)，汇编语言程序设计(数字逻辑,高级语言程序设计-I)

大二上：
数据结构(高级语言程序设计-II)，离散数学(高数2,高数1)，计算机组成原理(汇编语言程序设计,数字逻辑)，Java程序设计(高级语言程序设计-II)

大二下：
操作系统原理(计算机组成原理,数据结构)，微机接口原理技术(计算机组成原理，数字逻辑)

大三上：
数据库系统原理(数据结构,操作系统原理)，计算机网络(数据结构,操作系统原理)

大三下：
计算机体系结构(计算机组成原理)，编译原理(操作系统原理)

##### 拓扑排序算法

建立一个队列存放入度为0的顶点，每输出一个，就把他所有相关的边删除，本次输出完了之后，再扫描剩下的顶点，录入入度为0的顶点，以此往复，直到全部输出。