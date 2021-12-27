Pessimistic Cardinality Estimation: Tighter Upper Bounds for Intermediate Join Cardinalities



cardinality estimation over multijoin queries 多连接查询的基数估计问题

random hash partitioning and data sketching 随机散列分区和数据草图

### 摘要
In this work we introduce a novel approach to the problem of cardinality estimation over multijoin queries. Our approach leveraging randomized hashing and data sketching to tighten these bounds beyond the current state of the art. We demonstrate that the bounds can be injected directly into the cost based query optimizer framework enabling it to avoid expensive physical join plans. 

We outline our base data structures and methodology, and how these bounds may be introduced to the optimizer’s parameterized cost function as a new statistic for physical join plan selection. We demonstrate a complex tradeoff space between the tightness of our bounds and the size and complexity of our data structures. This space is not always monotonic as one might expect. 

In order combat this non-monotonicity, we introduce a partition budgeting scheme that guarantees monotonic behavior. We evaluate our methods on GooglePlus community graphs [11], and the Join Order Benchmark (JOB) [16]. In the presence of foreign key indexes, we demonstrate a 1.7× improvement in aggregate (time summed over all queries in benchmark) physical query plan runtime compared to plans chosen by Postgres using the default cardinality estimation methods. When foreign key indexes are absent, this advantage improves to over 10×.

在这项工作中，我们介绍了一种新的方法来解决多连接查询的基数估计问题。我们的方法利用随机散列和数据草图，将这些界限限制在当前技术水平之外。我们证明了边界可以直接注入到基于成本的查询优化器框架中，从而避免昂贵的物理连接计划。

我们概述了我们的基本数据结构和方法，以及如何将这些边界引入优化器的参数化成本函数，作为物理连接计划选择的新统计信息。我们展示了边界的紧密性与数据结构的大小和复杂性之间的复杂权衡空间。这个空间并不总是像人们所期望的那样单调。

为了克服这种非单调性，我们引入了一种保证单调性的分区预算方案。我们在GooglePlus社区图[11]和连接顺序基准（JOB）[16]上评估了我们的方法。在存在外键索引的情况下，与Postgres使用默认基数估计方法选择的计划相比，我们展示了聚合（在基准测试中所有查询的时间总和）物理查询计划运行时间的1.7倍改进。当缺少外键索引时，这一优势提高到10倍以上。


### 结论
Cardinality estimation is a challenging subproblem for cost based query optimizers and remains a primary challenge for even highly sophisticated systems. In particular, in the presence of multijoins. In this work we develop the use of bounds as a practical tool for multijoin query optimization. In doing so, we introduce a method of further tightening state of the art query bounds via random hash partitioning and data sketching. Furthermore, we introduce a novel bound formula restriction scheme that works in tandem with our partition budgeting approach. We demonstrate a tradeoff space between larger partition budget and plan execution time improvement and demonstrate that our bounds can be easily integrated into most cost based systems to achieve robust plans.

This initial work leaves room for future research. For instance, since our work centers on generating more robust query plans, we do not focus on optimization time efficiency. While it should be the possible to generate each necessary statistic with a single pass of the relation in question, our implementation is not optimized for efficiency, and generating the exact degree statistics requires worst case linear additional storage. Instead, it is possible to use approximations. Ting shows promising results in estimating frequent values and their degree with minimal memory impact [24].

Another promising direction is to broaden the scope of applicable queries. In this work, we focus on noncyclic joins but entropic formulas are not restricted in such a way. This would entail broadening Algorithm 2 to reliably generate a larger but still concise subset of all bounding formulas even in the presence of cycles. Finally, using bounds is overkill for some queries. It might instead be possible to use the default optimizer in most cases and then switch to use bounds when a “high-risk” query is detected. This hybrid approach would strike a balance between robust query plans and fast optimization time.