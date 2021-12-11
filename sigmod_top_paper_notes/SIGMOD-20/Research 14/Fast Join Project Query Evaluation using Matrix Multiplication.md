Fast Join Project Query Evaluation using Matrix Multiplication


In the last few years, much effort has been devoted to developing join algorithms to achieve worst-case optimality for join queries over relational databases. Towards this end, the database community has had considerable success in developing efficient algorithms that achieve worst-case optimal runtime for full join queries, i.e., joins without projections.
However, not much is known about join evaluation with projections beyond some simple techniques of pushing down the projection operator in the query execution plan. Such queries have a large number of applications in entity matching, graph analytics and searching over compressed graphs.
In this paper, we study how a class of join queries with projections can be evaluated faster using worst-case optimal algorithms together with matrix multiplication. Crucially, our algorithms are parameterized by the output size of the final result, allowing for choosing the best execution strategy.
We implement our algorithms as a subroutine and compare the performance with state-of-the-art techniques to show they can be improved upon by as much as 50x. More importantly, our experiments indicate that matrix multiplication is a useful operation that can help speed up join processing owing to highly optimized open source libraries that are also highly parallelizable.


In the paper, we study the evaluation of join queries with projections. This is useful for a wide variety of tasks including set similarity, set containment and boolean query answering. We describe an algorithm based on fast matrix multiplication that allows for theoretical speedups. Empirically, we also demonstrate that the framework is practically useful and can provide speedups of up to 50× for some datasets. There are several promising future directions that remain to be explored. The first key direction is to extend our techniques to arbitrary acyclic queries with projections. Second, it remains unclear if the same techniques can also benefit cyclic queries or not. For example, the AYZ algorithm is applicable to counting cycles in graph using matrix multiplication. It would be interesting to extend the algorithm to enumerate the output of join-project queries when the user can choose arbitrary projection variables.


基于矩阵乘法的快速联接项目查询求值


在过去的几年中，人们致力于开发连接算法，以实现关系数据库上连接查询的最坏情况优化。为此，数据库社区已经在开发高效算法方面取得了相当大的成功，这些算法可以为完全连接查询（即无投影连接）实现最坏情况下的最佳运行时间。然而，除了在查询执行计划中下推投影操作符的一些简单技术之外，关于使用投影进行连接计算的知识并不多。这种查询在实体匹配、图形分析和压缩图形搜索中有大量应用。在本文中，我们研究了如何使用最坏情况优化算法和矩阵乘法来更快地计算一类带有投影的连接查询。关键的是，我们的算法由最终结果的输出大小参数化，允许选择最佳执行策略。我们将我们的算法实现为一个子例程，并将其性能与最先进的技术进行比较，以表明它们可以提高50倍。更重要的是，我们的实验表明，矩阵乘法是一种有用的操作，由于高度优化的开放源代码库也是高度可并行的，因此可以帮助加快连接处理。




在本文中，我们研究了带有投影的连接查询的评估。这对于各种各样的任务都很有用，包括集合相似性、集合包含和布尔查询应答。我们描述了一种基于快速矩阵乘法的算法，该算法允许理论上的加速。从经验上看，我们还证明了该框架的实用性，可以为某些数据集提供高达50倍的加速。还有几个有希望的未来方向有待探索。第一个关键方向是将我们的技术扩展到带有投影的任意非循环查询。其次，尚不清楚同样的技术是否也能使循环查询受益。例如，AYZ算法适用于使用矩阵乘法计算图中的循环数。当用户可以选择任意投影变量时，扩展该算法以枚举联接项目查询的输出是很有趣的。