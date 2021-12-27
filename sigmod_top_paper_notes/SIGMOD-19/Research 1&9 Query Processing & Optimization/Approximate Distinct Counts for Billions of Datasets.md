Approximate Distinct Counts for Billions of Datasets


基数(cardinality，也译作势)，是指一个集合中不重复元素的个数。这里的集合和我们学过的严格定义的集合不同，允许存在重复元素，被称作multi-set，如给定这样的一个集合{1,2,3,1,2}，它有5个元素, 基数是3。

基数计数(cardinality counting)，则是指计算一个集合的基数，意即count-discint。 基数计算的场景很广泛，例如计算网站的访问uv，计算网络流量网络包请求header中的源地址的distinct数来作为网络攻击的重要指标。想要实现基数计数最直接想到的方式就是通过字典/HashSet，每条数据流入后直接保存相应的key，最后统一次集合的size就得到集合的基数。但是，这种方法的空间复杂度很高，在面对大数据的场景下做这样的统计代价很高。在近几十年有学者提出了很多基数估算的算法，在容许一定的误差的情况下，基于统计概率进行估算，本文就来介绍其中比较有名的几个基数估计算法。


### 摘要

Cardinality estimation plays an important role in processing big data. We consider the challenging problem of computing millions or more distinct count aggregations in a single pass and allowing these aggregations to be further combined into coarser aggregations. These arise naturally in many applications including networking, databases, and real-time business reporting. 

We demonstrate existing approaches to solve this problem are inherentlyfl awed, exhibiting bias that can be arbitrarily large, and propose new methods for solving this problem that have theoretical guarantees of correctness and tight, practical error estimates. 

This is achieved by carefully combining CountMin and HyperLogLog sketches and a theoretical analysis using statistical estimation techniques. These methods also advance cardinality estimation for individual multisets, as they provide a provably consistent estimator and tight con"dence intervals that have exactly the correct asymptotic coverage.


基数估计在大数据处理中起着重要作用。我们认为在单程中计算数以百万计或更多的不同计数聚合的挑战性问题，并允许这些聚合进一步组合成粗聚合。这些问题自然会出现在许多应用程序中，包括网络、数据库和实时业务报告。

我们证明了现有的解决这个问题的方法是固有的，表现出可以任意大的偏差，并提出了解决这个问题的新方法，具有正确性的理论保证和严密的、实际的误差估计。

这是通过仔细结合CountMin和HyperLogLog草图以及使用统计估计技术的理论分析来实现的。这些方法还改进了单个多集的基数估计，因为它们提供了一个可证明的一致估计量和具有精确渐近覆盖的紧置信区间。

### 数据集
dataset


### 结论

We tackle approximate distinct counting for many datasets under a strict space budget while retaining many of the properties of the strategy of storing individual HLL sketches for each dataset. Much of our work focuses on correct estimation of the background distribution and cardinalities.

This allows us to create the aggregate construction which performs well except in cases of extreme overlap. We note, however, that applying our estimation methods to the vHLL construction also yields good empirical results and may be a good option for those interested in only partially solving the many distinct count problem without theoretical guarantees. 

我们在严格的空间预算下处理许多数据集的近似不同计数，同时保留存储每个数据集的单个HLL草图的策略的许多属性。我们的大部分工作集中在背景分布和基数的正确估计上。
这使我们能够创建性能良好的骨料结构，但在极端重叠的情况下除外。然而，我们注意到，将我们的估计方法应用于vHLL构造也会产生良好的经验结果，对于那些只想部分解决许多不同计数问题而没有理论保证的人来说，这可能是一个很好的选择。

For future work, we believe the design of the aggregate construction can lead to other interesting designs, such as cases where there may be a natural hierarchy of aggregations. 

Furthermore, it may be possible to estimate an average bias for the aggregate construction and further improve the overall RRMSE. One last area of future work is addressing the question of asymptotic e$ciency as it is the one property of the MLE that is not provably retained by our cl estimator.

对于未来的工作，我们相信聚合结构的设计可以导致其他有趣的设计，例如可能存在聚合的自然层次结构的情况。
此外，可以估计骨料结构的平均偏差，并进一步改善总体RRMSE。未来工作的最后一个领域是解决渐近有效性问题，因为它是MLE的一个性质，我们的cl估计无法证明保留。