
几个重要词汇没太理解
band-joins??
θ联接（Theta Join）和交叉联接（Cross Join）


我们考虑在分布式系统（例如，云）中的频带连接的运行时间优化。为了在工作机器之间平衡负载，必须对输入进行分区，这会导致重复。我们将探讨如何解决每个工人的最大负载和两个关系之间的带状连接的输入重复之间的紧张关系。以前的工作面临着高优化成本或考虑过的分区过于受限（导致连接性能不理想）。我们的主要观点是，使用适当的分割评分度量对连接属性空间进行递归划分可以实现低优化成本和低连接成本。这是第一种不仅对一维带状连接有效，而且对多属性连接有效的方法。实验表明，我们的方法能够在很大范围的设置下找到每个工作人员的最大负载和输入重复下限10%以内的分区，与以前的工作相比有了显著的改进。

实验设备和实验参数

MapReduce [6] and Spark [43]
[6] Jeffrey Dean and Sanjay Ghemawat. 2008. MapReduce: Simplified Data Processing on Large Clusters. Commun. ACM 51, 1 (2008), 107–113. https://doi.org/10.1145/1327452.1327492


[43] Matei Zaharia, Mosharaf Chowdhury, Michael J Franklin, Scott Shenker, and Ion Stoica. 2010. Spark: cluster computing with working sets. In USENIX HotCloud. https://dl.acm.org/doi/10.5555/1863103.1863113


Amazon’s Elastic MapReduce (EMR) cloud, using 30 m3.xlarge machines (15GB RAM, 40GB disk, high network performance) by default.

