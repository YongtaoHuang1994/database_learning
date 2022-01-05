Mining Precision Interfaces From Query Logs


Sloan Digital Sky Survey query 斯隆数字天空测量查询日志

### 摘要
Interactive tools make data analysis more efficient and more accessible to end-users by hiding the underlying query complexity and exposing interactive widgets for the parts of the query that matter to the analysis. 

However, creating custom tailored (i.e., precise) interfaces is very costly, and automated approaches are desirable. 

We propose a syntactic approach that uses queries from an analysis to generate a tailored interface. 

We model interface widgets as functions I(q) → q′ that modify the current analysis query q, and interfaces as the set of queries that its widgets can express. 

Our system, Precision Interfaces, analyzes structural changes between input queries from an analysis, and generates an output interface with widgets to express those changes. 

Our experiments on the Sloan Digital Sky Survey query log suggest that Precision Interfaces can generate useful interfaces for simple unanticipated tasks, and our optimizations can generate interfaces from logs of up to 10,000 queries in ≤ 10s


交互式工具通过隐藏底层查询的复杂性并为查询中与分析有关的部分公开交互式小部件，使数据分析更高效，最终用户更容易访问。

然而，创建定制（即精确）接口的成本非常高，并且需要自动化方法。

我们提出了一种语法方法，使用分析中的查询生成定制的接口。

我们将接口小部件建模为函数I（q）→ q′，修改当前分析查询q，并将接口作为其小部件可以表达的查询集。

我们的系统Precision Interfaces从分析中分析输入查询之间的结构变化，并生成带有小部件的输出接口来表示这些变化。

我们在斯隆数字天空测量查询日志上的实验表明，精确接口可以为简单的意外任务生成有用的接口，我们的优化可以从中多达10000个查询的日志生成接口≤ 10秒

### 结论

Interactive visual interfaces are increasingly relied upon in analysis and for end-users to interact with data. 

However, knowing what analyses users want to perform is challenging, and creating interfaces for those analyses requires technical expertise. 

This paper proposed syntactic analysis of query logs for automatic interface generation, and a unified model to connect queries, changes between queries, interactive widgets, and interfaces. 

We found that our approach is wellsuited to analyses where query changes are structured and repeated, and less well-suited when there is unpredictable variation between queries (e.g., ad hoc analyses, or heterogeneous logs). Our optimizations are able to generate interfaces for query logs with up to 10,000 queries within 10 seconds. 

Stepping back, Precision Interfaces is a “quick and dirty” approach towards custom analysis interface creation. 

This data-driven approach does not work for analyses that have never been performed but that the user anticipates will be
useful. 
However, it is potentially “good enough” for a long tail of simple analyses. Further expanding the scope of what analysis and settings Precision Interfaces can scalably support can be viewed a progressive approach to this problem.


交互式可视界面在分析和最终用户与数据交互中越来越受到依赖。

然而，了解用户想要执行的分析是一项挑战，为这些分析创建界面需要技术专业知识。

本文提出了用于自动生成接口的查询日志的语法分析，以及连接查询、查询之间的更改、交互式小部件和接口的统一模型。

我们发现，我们的方法非常适合于结构化和重复查询更改的分析，而不太适合于查询之间存在不可预测变化的分析（例如，即席分析或异构日志）。我们的优化能够在10秒内为查询日志生成多达10000个查询的接口。

退一步说，Precision接口是一种“快速且肮脏”的自定义分析接口创建方法。

这种数据驱动的方法不适用于从未执行过但用户预期会执行的分析有用的

然而，对于简单的长尾分析来说，它可能“足够好”。进一步扩大分析和设置精度接口可扩展支持的范围可以看作是解决此问题的渐进方法。

Future Directions: 

Using logs and data to generate analysis interfaces is a rich research direction. 

Interface quality can be improved by using metadata, language semantics, database content, as well as HCI user interface layout and design guidelines. 

Multi-level interactions between widgets can leverage subtree co-occurrence statistics, and dependencies between queries can be identified as relationships between query results and subsequent queries. 


Data cleaning can help distinguish queries from different tasks, anomalous queries, and different languages. 

Finally, can our interface abstraction generate multi-modal applications, or bootstrap and enhance data science workflows such as Ava [26]?

未来方向：

使用日志和数据生成分析界面是一个丰富的研究方向。

通过使用元数据、语言语义、数据库内容以及HCI用户界面布局和设计指南，可以提高界面质量。

小部件之间的多级交互可以利用子树共现统计信息，查询之间的依赖关系可以识别为查询结果和后续查询之间的关系。

数据清理有助于区分不同任务、异常查询和不同语言的查询。

最后，我们的接口抽象能否生成多模式应用程序，或引导并增强数据科学工作流，如Ava[26]？