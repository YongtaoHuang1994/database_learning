Functional-Style SQL UDFs With a Capital F

We advocate to express complex in-database computation using a functional style in which SQL UDFs use plain selfinvocation to recurse. The resulting UDFs are concise and readable, but their run time performance on contemporary RDBMSs is sobering. 

This paper describes how to compile such functional-style UDFs into SQL:1999 recursive common table expressions. We build on function call graphs to build the compiler’s core and to realize a series of optimizations (reference counting, memoization, exploitation of linear and tail recursion). 

The compiled UDFs evaluate efficiently, challenging the performance of manually tweaked (but often convoluted) SQL code. SQL UDFs can indeed be functional and fast.


我们提倡在数据库计算中使用函数式来表示复杂数据，其中SQLUDF使用普通的自调用来递归。由此产生的UDF简洁易读，但它们在当代RDBMS上的运行时性能令人警醒。

本文描述了如何将这种函数式UDF编译成SQL:1999递归公共表表达式。我们基于函数调用图构建编译器的核心，并实现一系列优化（引用计数、记忆、线性递归和尾部递归的利用）。

编译后的UDF可以有效地进行评估，这对手动调整（但通常是复杂的）SQL代码的性能提出了挑战。SQLUDF确实可以实现功能性和快速性。