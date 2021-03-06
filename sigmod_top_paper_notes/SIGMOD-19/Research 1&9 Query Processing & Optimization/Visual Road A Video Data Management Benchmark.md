Visual Road: A Video Data Management Benchmark

#### 摘要
Recently, video database management systems (VDBMSs) have re-emerged as an active area of research and development. To accelerate innovation in this area, we present Visual Road, a benchmark that evaluates the performance of these systems. Visual Road comes with a data generator and a suite of queries over cameras positioned within a simulated metropolitan environment. 
最近，视频数据库管理系统（VDBMS）重新成为一个活跃的研究和开发领域。为了加速这一领域的创新，我们推出了VisualRoad，这是一个评估这些系统性能的基准。VisualRoad附带了一个数据生成器和一套通过模拟大都市环境中的摄像机进行的查询。

Visual Road’s video data is automatically generated with a high degree of realism, and annotated using a modern simulation and visualization engine. This allows for VDBMS performance evaluation while scaling up the size of the input data. Visual Road is designed to evaluate a broad variety of VDBMSs: realtime systems, systems for longitudinal analytical queries, systems processing traditional videos, and systems designed for 360◦ videos. We use the benchmark to evaluate three recent VDBMSs both in capabilities and performance.
VisualRoad的视频数据以高度真实感自动生成，并使用现代模拟和可视化引擎进行注释。这允许VDBMS性能评估，同时放大输入数据的大小。VisualRoad设计用于评估各种VDBMS：实时系统、纵向分析查询系统、处理传统视频的系统以及专为360◦ 视频。我们使用该基准评估了最近三个VDBMS的能力和性能。


#### 结论
We presented Visual Road, a benchmark for video data management systems (VDBMSs). Visual Road comes with a data generator that produces an unlimited amount of synthetic video generated by simulating an active metropolitan area, along with a suite of queries that evaluate VDBMS performance.
我们介绍了视频数据管理系统（VDBMS）的基准VisualRoad。VisualRoad附带了一个数据生成器，该生成器通过模拟活跃的大都市区生成无限量的合成视频，并提供了一套用于评估VDBMS性能的查询。
Our results show that video generated using Visual Road closely matches real-world, manually-annotated video corpora and allows VDBMSs to be evaluated at any scale. We used an initial implementation of the Visual Road benchmark to evaluate the performance of several modern VDBMSs and show that it is a useful tool for capturing meaningful performance comparisons between systems. As visualization and simulation tools evolve, future versions of Visual Road will automatically fuse tiles, track objects across tiles, and support increasingly complex procedurally-generated tiles.

我们的结果表明，使用VisualRoad生成的视频与真实世界的手动注释视频语料库非常匹配，并允许在任何尺度上对VDBMS进行评估。我们使用VisualRoad基准的初始实现来评估几个现代VDBMS的性能，并表明它是捕获系统之间有意义的性能比较的有用工具。

随着可视化和模拟工具的发展，未来版本的VisualRoad将自动融合tiles，跟踪tiles上的对象，并支持越来越复杂的程序生成tiles。