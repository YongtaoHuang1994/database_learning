### 摘要
数据密集型应用程序推动了基于日志结构合并（LSM）的键值引擎的发展，该引擎采用非本地的范例来支持高摄取率和低读/写干扰。然而，这些好处是以将被删除者视为二等公民为代价的。删除插入一个墓碑，使已删除密钥的旧实例无效。最先进的LSM引擎不能保证墓碑传播到持久删除的速度。此外，LSM引擎只支持删除排序键。要删除另一个属性（例如，时间戳），将读取并重新写入整个树。

我们强调，在不影响读取性能的情况下快速持久删除是支持以下功能的关键：
（i） 在数据窗口上运行的流媒体系统，
（ii）隐私权，对被遗忘的权利提供延迟保障，以及
（iii）数据系统的大规模云部署，使存储成为宝贵的资源。

为了应对这些挑战，在本文中，我们构建了一个新的键值存储引擎Lethe，它使用非常少量的额外元数据、一组新的可删除压缩策略，以及一个新的物理数据布局来编织排序和删除键顺序。我们表明，Lethe支持任何用户定义的删除持久性延迟阈值，从而提供更高的读取吞吐量（1.17 − 1.4×）和下部空间放大（2.1− 9.8×），写入放大率略有增加（在4%到25%之间）。此外，Lethe通过删除整个数据页而不牺牲读取性能，也不采用昂贵的全树合并，从而支持在辅助删除键上进行有效的范围删除


### 几个概念

#### LSM
日志结构合并（LSM，log structure merge）树的结构

#### 读放大


#### 写放大
写入放大（英语：Write amplification，简称WA）是闪存和固态硬盘（SSD）中一种不良的现象，即实际写入的物理数据量是写入数据量的多倍。

### 结论
在这项工作中，我们展示了最先进的基于LSM的键值存储对于即使只有一小部分删除的工作负载的性能也不理想，并且这些数据存储中的删除持久性延迟可能是无限的。

为了解决这个问题，我们构建了Lethe，这是一个基于LSM的新引擎，它引入了一系列新的压缩策略和KiWi（物理数据存储布局的连续体）。

FADE在用户定义的阈值内强制执行删除持久性，同时增加读取吞吐量并减少空间放大，但以适度增加写入放大为代价。

KiWi提供了高效的二级范围删除，可以针对给定的工作负载对其进行调整，使其性能优于最先进的技术。