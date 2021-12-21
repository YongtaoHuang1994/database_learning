iQCAR inter-Query Contention Analyzer for Data Analytics Frameworks


Resource interferences caused by concurrent queries is one of the key reasons for unpredictable performance and missed workload SLAs in cluster computing systems. Analyzing these inter-query resource interactions is critical in order to answer time-sensitive questions like ‘who is creating resource conflicts to my query’. 

More importantly, diagnosing whether the resource blocked times of a ‘victim’ query are caused by other queries or some other external factor can help the database administrator narrow down the many possibilities of query performance degradation. We introduce iQCAR, an inter-Query Contention Analyzer, that attributes blame for the slowdown of a query to concurrent queries. 

iQCAR models the resource conflicts using a multi-level directed acyclic graph that can help administrators compare impacts from concurrent queries, identify most contentious queries, resources and hosts in an online execution for a selected time window. Our experiments using TPCDS queries on Apache Spark show that our approach is substantially more accurate than other methods based on overlap time between concurrent queries



在集群计算系统中，并发查询引起的资源干扰是导致性能不可预测和工作负载SLA缺失的关键原因之一。为了回答诸如“谁在为我的查询创建资源冲突”之类的时间敏感问题，分析这些查询间资源交互至关重要。

更重要的是，诊断“牺牲品”查询的资源阻塞时间是由其他查询还是其他外部因素造成的，可以帮助数据库管理员缩小查询性能下降的可能性。我们介绍了iQCAR，一个查询间竞争分析器，它将查询速度减慢归咎于并发查询。

iQCAR使用多级有向无环图对资源冲突进行建模，该图可帮助管理员比较并发查询的影响，识别选定时间窗口在线执行中最具争议的查询、资源和主机。我们在ApacheSpark上使用TPCDS查询的实验表明，我们的方法比其他基于并发查询之间重叠时间的方法更精确


Resource interferences due to concurrent executions are one of the primary and yet highly misdiagnosed causes of query slowdowns in shared clusters today. 


This paper discusses some of thechallenges in detecting accurate causes of contentions, and illustrateswhy blame attribution using existing methodologies can be inaccurate. We propose a theory for quantifying blame for slowdown, and present techniques to filter genuine concurrency related slowdowns from other known and unknown issues. 

We further showed how our graph-based framework allows for consolidation of blame and generate explanations allowing an admin to explore the contentions and contributors of these contentions systematically. An interesting direction of future research is to develop a contention-aware cluster scheduler that can dynamically reprioritize contentious or victim queries, and/or delay stage submissions to avoid possible resource conflicts

并发执行导致的资源干扰是当今共享集群中查询速度减慢的主要原因之一，但被高度误诊。

本文讨论了在发现争论的准确原因方面所面临的一些挑战，并举例说明了为什么使用现有方法的责任归因可能不准确。我们提出了一个理论来量化减速的原因，并提出了从其他已知和未知问题中过滤真正的并发相关减速的技术。

我们进一步展示了我们基于图形的框架如何整合指责，并生成解释，使管理员能够系统地探索这些争论和争论的贡献者。未来研究的一个有趣方向是开发一个支持争用的集群调度器，它可以动态地重新设置有争议或受害者查询的优先级，和/或延迟阶段提交以避免可能的资源冲突