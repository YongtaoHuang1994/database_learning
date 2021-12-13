User-defined function (UDF) optimization

### 摘要
An important class of database queries in machine learning and data science workloads is the opaque filter query: a query with a selection predicate that is implemented with a UDF, with semantics that are unknown to the query optimizer. Some typical examples would include a CNN-style trained image classifier, or a textual sentiment classifier. Because the optimizer does not know the predicate’s semantics, it cannot employ standard optimizations, yielding long query times.

We propose voodoo indexing, a two-phase method for optimizing opaque filter queries. Before any query arrives, the method builds a hierarchical “query-independent” index of the database contents, which groups together similar objects. At query-time, the method builds a map of how much each group satisfies the predicate, while also exploiting the map to accelerate execution. 

Unlike past methods, voodoo indexing does not require insight into predicate semantics, works on any data type, and does not require in-query model training. We describe both standalone and SparkSQL-specific implementations, plus experiments on both image and text data, on more than 100 distinct opaque predicates. We show voodoo indexing can yield up to an 88% improvement over standard scan behavior, and a 79% improvement over the previous best method adapted from research literature.


机器学习和数据科学工作负载中一类重要的数据库查询是不透明过滤器查询：一种带有选择谓词的查询，该选择谓词由UDF实现，其语义查询优化器不知道。一些典型的例子包括CNN风格的训练图像分类器或文本情感分类器。由于优化器不知道谓词的语义，因此无法采用标准优化，从而产生较长的查询时间。

我们提出voodoo索引，这是一种优化不透明过滤器查询的两阶段方法。在任何查询到达之前，该方法构建数据库内容的分层“独立于查询”索引，将相似的对象分组在一起。在查询时，该方法构建每个组满足谓词的程度的映射，同时还利用该映射来加速执行。

与过去的方法不同，voodoo索引不需要深入了解谓词语义，适用于任何数据类型，并且不需要查询模型内培训。我们描述了独立的和特定于SparkSQL的实现，以及在100多个不同的不透明谓词上对图像和文本数据的实验。我们表明，voodoo索引可以产生高达88%的改善标准扫描行为，和79%的改善比以前最好的方法改编自研究文献。


### 结论
As opaque filter queries in machine learning workloads become ubiquitous, an efficient filter strategy is required. However, due to its opaque semantic and unstable characteristic, real-world systems just execute these queries by simple scan. In summary, we present a novel two-phase indexing mechanism for opaque filter query optimization, which can select data that satisfies UDF predicate quickly, yielding to query time reduction. 

In addition, we build standalone and SparkSQL-integrated systems, and verify that both of them can achieve high performance on real-world datasets. 

In this work, we focus on basic filter queries with one UDF predicate. We view this version of voodoo indexing mechanism as the initial step towards a family of methods for opaque query optimization. We believe it may be possible to apply our method to filter queries with multiple predicates by adjusting the reward function. Applying our method to aggregation queries that include a selection is likely to be straightforward, but using a UDF in the HAVING clause of an aggregation query is a serious challenge. 

This latter situation might appear in large machine learning workloads that use database queries to feed training data to a vast number of model production pipelines; we believe that examining the larger context in which opaque filter queries operate is a promising direction for future projects. Finally, we would like to address the optimization challenge for more elaborate queries such as JOIN queries. A possible way is to adapt our mechanism for cardinality estimation.

由于机器学习工作负载中的不透明过滤查询变得无处不在，因此需要一种有效的过滤策略。然而，由于其不透明的语义和不稳定的特性，现实世界中的系统只是通过简单的扫描来执行这些查询。总之，我们提出了一种新的用于不透明过滤器查询优化的两阶段索引机制，它可以快速选择满足UDF谓词的数据，从而减少查询时间。

此外，我们构建了独立的和SparkSQL集成的系统，并验证了它们都可以在真实数据集上实现高性能。

在这项工作中，我们主要关注具有一个UDF谓词的基本过滤器查询。我们将此版本的voodoo索引机制视为朝着一系列不透明查询优化方法迈出的第一步。我们相信，通过调整奖励函数，可以将我们的方法应用于过滤具有多个谓词的查询。将我们的方法应用于包含选择的聚合查询可能很简单，但在聚合查询的HAVING子句中使用UDF是一个严重的挑战。

后一种情况可能出现在使用数据库查询向大量模型生产管道提供训练数据的大型机器学习工作负载中；我们相信，检查不透明过滤器查询操作的更大上下文是未来项目的一个有希望的方向。最后，我们希望解决更复杂查询（如连接查询）的优化挑战。一种可能的方法是调整我们的基数估计机制。