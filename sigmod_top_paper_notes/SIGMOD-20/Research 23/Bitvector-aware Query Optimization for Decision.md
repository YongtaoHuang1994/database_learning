


Bitvector filtering is an important query processing technique that can significantly reduce the cost of execution, especially for complex decision support queries with multiple joins. Despite its wide application, however, its implication to query optimization is not well understood.


In this work, we study how bitvector filters impact query optimization. We show that incorporating bitvector filters into query optimization straightforwardly can increase the plan space complexity by an exponential factor in the number of relations in the query. We analyze the plans with bitvector filters for star and snowflake queries in the plan space of right deep trees without cross products. 

Surprisingly, with some simplifying assumptions, we prove that, the plan of the minimal cost with bitvector filters can be found from a linear number of plans in the number of relations in the query. This greatly reduces the plan space complexity for such queries from exponential to linear. 

Motivated by our analysis, we propose an algorithm that accounts for the impact of bitvector filters in query optimization. Our algorithm optimizes the join order for an arbitrary decision support query by choosing from a linear number of candidate plans in the number of relations in the query. 

We implement our algorithm in a commercial database DBMS-X as a transformation rule. Our evaluation on both industry standard benchmarks and customer workload shows that, compared with DBMS-X, our technique reduces the total CPU execution time by 22%-64% for the workloads, with up to two orders of magnitude reduction in CPU execution time for individual queries.


位向量过滤是一种重要的查询处理技术，可以显著降低执行成本，特别是对于具有多个连接的复杂决策支持查询。然而，尽管它有着广泛的应用，但它对查询优化的意义还没有得到很好的理解。

在这项工作中，我们研究了位向量过滤器如何影响查询优化。我们表明，直接将位向量过滤器纳入查询优化可以通过查询中关系数的指数因子增加计划空间复杂性。我们在没有交叉积的右深树的计划空间中分析了星型和雪花型查询的位向量过滤器计划。

令人惊讶的是，通过一些简化的假设，我们证明了，使用位向量滤波器的最小代价的计划可以从查询中关系数的线性计划数中找到。这大大降低了此类查询的计划空间复杂性，使其从指数级降至线性级。

基于我们的分析，我们提出了一种算法，该算法考虑了位向量过滤器在查询优化中的影响。我们的算法通过在查询中的关系数中选择线性数量的候选计划来优化任意决策支持查询的连接顺序。

作为转换规则，我们在商业数据库DBMS-X中实现了我们的算法。我们对行业标准基准测试和客户工作负载的评估表明，与DBMS-X相比，我们的技术将工作负载的总CPU执行时间减少了22%-64%，单个查询的CPU执行时间最多减少了两个数量级。


Bitvector filters, including bitmap or hash filter [6, 7, 18], Bloom filter and its variants [2, 7, 15, 24, 32], perform ’probabilistic’ semi-join reductions to effectively prune out rows that will not qualify join conditions early in the query execution pipeline. Because they are easy to implement and low in overhead, bitvector filters are widely used in commercial databases [13, 17, 21, 23].

位向量过滤器，包括位图或哈希过滤器[6,7,18]，Bloom过滤器及其变体[2,7,15,24,32]，执行“概率”半连接缩减，以有效地剪除在查询执行管道早期不符合连接条件的行。由于位向量滤波器易于实现且开销低，因此在商业数据库中广泛使用[13、17、21、23]。