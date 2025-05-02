# NOTHING
学习中^_^

## cpu和gpu的gemv（个人理解）

在学习中，我们通常把向量写成列向量的形式，例如，这是一个典型的GEMV公式：

```math

\begin{bmatrix}
1 & 2 & 3 \\
4 & 5 & 6 \\
7 & 8 & 9
\end{bmatrix}
\begin{bmatrix}
1 \\
1 \\
1
\end{bmatrix}
=
\begin{bmatrix}
6 \\
15 \\
24
\end{bmatrix}

```

### GPU算子

在实现GPU版本算子的时候，我们直接按照如上形式进行计算。

### CPU算子

而在计算CPU版本的时候，有所不同：

`numpy`给出的实现是这样：

$`Ans = input \cdot weight^T`$

这里的`input`是一个行向量。

而我们使用的数学库`armadillo`在存储矩阵的时候采用列优先存储（只有一维的向量不会如此），这个行为相当于自带一个转置操作。

所以，我们的CPU算子计算过程应该是这样的：

```math

\begin{bmatrix}
1 & 1 & 1
\end{bmatrix}
\begin{bmatrix}
1 & 4 & 7\\
2 & 5 & 8\\
3 & 6 & 9\\
\end{bmatrix}
=
\begin{bmatrix}
6 & 15 & 24
\end{bmatrix}

```

### 总结

即GPU版本计算时，以列向量方式进行；CPU版本按照行向量方式进行。


