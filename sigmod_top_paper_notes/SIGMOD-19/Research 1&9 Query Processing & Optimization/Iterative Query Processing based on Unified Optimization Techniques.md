Iterative Query Processing based on Unified Optimization Techniques


ETL


### 摘要
Hybrid transactional and analytical processing (HTAP) systems like SAP HANA make it much simpler to manage both operational loads and analytical queries without ETL, separate data warehouses, etc. To represent both transactional and analytical business logic in a single database system, stored procedures are often used to express analytical queries using control flow logic and DMLs. 

Optimizing these complex procedures requires a fair knowledge of imperative programming languages as well as a declarative query language. Therefore, unified optimization techniques involving both program and query optimization techniques are essential to achieve optimal query performance.

In this study, we propose a novel unified optimization technique for efficient iterative query processing. We present the notion of query motion that allows SQL queries to be moved in and out of loops. 

Additionally, we define a novel cost model in which the quality of the execution plan is evaluated based on the queries and loop iterations. An experimental evaluation demonstrated the advantages of the proposed technique using both a standard decision support benchmark and realworld workloads. Further investigation revealed that the proposed unified optimization technique enumerates plans that provide performance improvements of up to an order of magnitude compared with plans generated by the existing loop-invariant code motion 
techniques.

SAP HANA等混合事务和分析处理（HTAP）系统使管理操作负载和分析查询变得更加简单，而无需ETL、单独的数据仓库等，以在单个数据库系统中表示事务和分析业务逻辑，存储过程通常用于使用控制流逻辑和DML表示分析查询。

优化这些复杂的过程需要对命令式编程语言以及声明式查询语言有相当的了解。因此，涉及程序和查询优化技术的统一优化技术对于实现最佳查询性能至关重要。

在这项研究中，我们提出了一种新的统一优化技术，用于高效的迭代查询处理。我们提出了查询运动的概念，它允许SQL查询在循环中移入和移出。

此外，我们定义了一个新的成本模型，其中执行计划的质量是基于查询和循环迭代来评估的。实验评估表明，所提出的技术的优势，使用标准的决策支持基准和现实世界的工作负载。进一步研究表明，与现有循环不变代码运动生成的计划相比，所提出的统一优化技术列举的计划可提供高达一个数量级的性能改进技术。
### 结论
The demand for transactional and analytical processing in the same database system makes it essential to optimize database programs containing both analytical queries and imperative program constructs. In particular, iterative analytical queries often require a significant amount of time. In this paper, we proposed a new code motion that considers both the quality of the query plans and impact of loop-invariant code motions. We chose the optimal solution from alternative execution plans based on their estimated costs which are generated by the proposed plan enumeration algorithm. 

Additionally, we proposed a cost model that estimates the benefit of a query motion using the loop iteration count and the query execution cost. Experimental results show that the proposed code motion technique improves the performance of up to an order of magnitude compared to those of existing loop-invariant code motion techniques using both synthetic and real-world datasets.

The proposed algorithm also enhances the performances of other optimization techniques that are used in database and compiler research. For example, for CTE optimization, SQL inlining improved the quality of the execution plans for CTE variables and queries. Hence, the proposed cost model can be directly applied to CTE to explore the inlining alternatives. 

In addition, for runtime adaptation optimization, a loop-optimization technique (ECM) based on the exact cost and number of loop iterations, assists in the selection of the best plan for a procedure. Finally, the technique of propagating statistical summaries can be applied to classical UDFs and used for stored procedure optimization.

As future work, we are planning to apply other source code optimization techniques such as runtime adaptation and loop unrolling to the stored procedures. In addition, we will conduct research to maximize the parallelism of the stored procedures via dependency analyses.