# 数值分析函数库

本项目中的公式参考自*数值分析, 颜庆津, 北京航空航天大学出版社*

##日志

- 2015.10.11 新增Mat类， 完成了一些基本的矩阵操作

- 2015.10.11 新增顺序高斯消去法解线性方程组的算法 
```
bool solveLinearSimultaneousEquations(
	const Mat& A, 
	Vec& x, 
	const Vec& b, 
	enum_method method=METHOD_SEQUENTIAL_GAUSSIAN_ELIMINATION
);
```
	
- 2015.10.12 引入gtest库，编写了若干单元测试样例

- 2015.10.12 新增了Mat类的子类Vec类

- 2015.10.12 新增了列主元素高斯消去法解线性方程组的算法<br>
```
bool solveLinearSimultaneousEquations(
	const Mat& A, 
	Vec& x, 
	const Vec& b, 
	enum_method method=METHOD_COLUMN_MAJOR_ELEMENT_GAUSSIAN_ELIMINATION
);
```
	
- 2015.10.12 新增了Doolittle分解法法解线性方程组的算法
```
bool solveLinearSimultaneousEquations(
	const Mat& A, 
	Vec& x, 
	const Vec& b, 
	enum_method method=METHOD_DOOLITTLE
);
```

- 2015.10.13 新增了选主元的Doolittle分解法法解线性方程组的算法
```
bool solveLinearSimultaneousEquations(
	const Mat& A, 
	Vec& x, 
	const Vec& b, 
	enum_method method=METHOD_MAJOR_ELEMENT_DOOLITTLE
);
```

- 2015.10.15 新增了三角分解法解带状线形方程组的算法
```
bool solveBandLinearSimultaneousEquations(
	const Mat& A, 
	Vec& x, 
	const Vec& b, 
	int s, 
	int r
);
```