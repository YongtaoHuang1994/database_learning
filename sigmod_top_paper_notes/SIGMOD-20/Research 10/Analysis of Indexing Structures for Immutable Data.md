Analysis of Indexing Structures for Immutable Data



In emerging applications such as blockchains and collaborative data analytics, there are strong demands for data immutability, multi-version accesses, and tamper-evident controls. To provide efficient support for lookup and merge operations, three new index structures for immutable data, namely Merkle Patricia Trie (MPT), Merkle Bucket Tree (MBT), and Pattern-Oriented-Split Tree (POS-Tree), have been proposed. Although these structures have been adopted in real applications, there is no systematic evaluation of their pros and cons in the literature, making it difficult for practitioners to choose the right index structure for their applications.

To alleviate the above problem, we present a comprehensive analysis of the existing index structures for immutable data, and evaluate both their asymptotic and empirical performance. Specifically, we show that MPT, MBT, and POS-Tree are all instances of a recently proposed framework, dubbed Structurally Invariant and Reusable Indexes (SIRI). We propose to evaluate the SIRI instances on their index performance and deduplication capability. We establish the worst-case guarantees of each index, and experimentally evaluate all indexes in a wide variety of settings. Based on our theoretical and empirical analysis, we conclude that POS-Tree is a favorable choice for indexing immutable data.

不可变数据的索引结构分析

在区块链和协作数据分析等新兴应用中，对数据不变性、多版本访问和防篡改控制有着强烈的需求。为了有效地支持查找和合并操作，提出了三种新的不可变数据索引结构，即Merkle-Patricia-Trie（MPT）、Merkle-Bucket-Tree（MBT）和面向模式的拆分树（POS-Tree）。虽然这些结构已在实际应用中采用，但文献中没有对其优缺点进行系统评估，这使得从业者难以为其应用选择正确的索引结构。

为了缓解上述问题，我们对现有的不变数据指数结构进行了综合分析，并对其渐近性能和实证性能进行了评估。具体来说，我们展示了MPT、MBT和POS树都是最近提出的框架的实例，称为结构不变和可重用索引（SIRI）。我们建议评估SIRI实例的索引性能和重复数据消除能力。我们建立每个指标的最坏情况保证，并在各种设置下对所有指标进行实验评估。基于我们的理论和实证分析，我们得出结论，POS树是索引不变数据的有利选择。