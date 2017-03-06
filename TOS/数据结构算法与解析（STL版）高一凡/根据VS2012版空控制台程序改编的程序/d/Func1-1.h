//Func1-1.h 5个常用的函数
bool equal(int c1, int c2)//PriorElem()等可调用
{//判断是否相等的函数，用于T为int类型
	return c1==c2;//整数判断相等
}
bool sq(int c1, int c2)
{ // 数据元素判定函数(平方关系)，LocateElem()调用的函数
	return c1==c2*c2;
}
bool equal(double c1, double c2)//PriorElem()等可调用
{//判断是否相等的函数，用于T为double类型
	return abs(c1-c2)<1.0e-6;//实数判断二者之差小于一个很小的数
}
inline void print(T &c)//ListTraverse()可调用，内联函数
{//输出c，用于T为基本类型（结构体类型需根据具体结构重编）
	cout<<c<<" ";
}
inline void dbl(T &c)//ListTraverse()可调用，内联函数
{//使c的值加倍，用于T为基本类型（可根据不同的具体要求重编）
	c*=2;
}
