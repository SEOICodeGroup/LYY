//SqList.h 顺序表的类（SqList类）
#ifndef _SQLIST_H_
#define _SQLIST_H_
template<typename T>class SqList
{//带模板的顺序表类
	friend void MergeList(const SqList<T>&, const SqList<T>&, SqList<T>&);
	//声明普通函数MergeList()为SqList类的友元，使其可以调用SqList的私有成员
private://3个私有数据成员
	T *elem;//线性表存储空间的基址
	int length;//线性表的当前表长
	int listsize;//线性表当前的存储容量
public://14个成员函数
	SqList(int k=1)
	{//构造函数，动态生成具有k个初始存储空间的空线性表，无参时k=1
		elem=new T[k];//动态生成k个存储空间
		assert(elem!=NULL);//存储分配失败则退出
		length=0;//空表长度为0
		listsize=k;//设置初始存储容量
	}
	SqList(const SqList &L)
	{//提供类的复制构造函数来代替默认版本
		length=L.length;//表长同L
		listsize=L.listsize;//存储容量同L
		elem=new T[listsize];//根据listsize重新分配空间
		assert(elem!=NULL);//存储分配失败则退出
		for(int i=0; i<length; i++)
			elem[i]=L.elem[i];//逐个复制数据
	}
	SqList& operator=(const SqList &L)
	{//重载赋值运算符（因为需要给类的数据成员动态分配空间）
		if(this!=&L)//没出现L=L的情况
		{
			if(elem!=NULL)//elem指向某存储空间
				delete elem;//释放elem原有存储空间
			elem=new T[L.listsize];//根据L.listsize重新分配空间
			assert(elem!=NULL);//存储分配失败则退出
			for(int i=0; i<L.length; i++)
				elem[i]=L.elem[i];//逐个复制数据
		}
		return *this;
	}
	~SqList()
	{//析构函数
		delete[]elem;//释放elem所指的存储空间数组
	}
	void ClearList()
	{//重置线性表为空表
		length=0;
	}
	bool ListEmpty()const//常成员函数，不会改变对象的值
	{//若线性表为空表，则返回true；否则返回false
		return length==0;
	}
	int ListLength()const
	{//返回线性表的长度
		return length;
	}
	bool GetElem(int i, T &e)const
	{//用e返回线性表第i个数据的值（0≤i≤ListLength()-1）
		if(i<0 || i>=length)//i不在表的范围之内
			return false;
		e=*(elem+i);//将elem[i]的值赋给e
		return true;
	}
	int LocateElem(T e, bool(*eq)(T, T))const
	{//返回第一个与e满足关系eq()的数据的位序（0～ListLength()-1）。
	 //若这样的数据不存在，则返回值为-1
		int i=0;//i的初值指示第一个数据
		while(i<length && !eq(*(elem+i), e))
		//i没超出表的范围且i所指的数据与e不满足关系eq()
			i++;//计数加1，继续向后找
		if(i<length)//找到满足关系eq()的数据
			return i;//返回其位序
		else//没找到满足关系的数据
			return -1;
	}
	bool PriorElem(T e, bool(*eq)(T, T), T &pre_e)const
	{//若e与表的某数据满足定义的eq()相等关系，且该数据不是表中第一个（有前驱），
	 //则用pre_e返回它的前驱；否则操作失败，pre_e无定义
		int i=LocateElem(e, eq);//将第一个与e满足eq()相等关系的数据的位序赋给i
		if(i<=0)//没找到，或是第一个元素（没有前驱）
			return false;//操作失败
		else//找到值为e的元素，其位序为i
		{
			pre_e=*(elem+i-1);//将elem[i]前一个元素的值赋给pre_e
			return true;//操作成功
		}
	}
	bool NextElem(T e, bool(*eq)(T, T), T &next_e)const
	{//若e与表的某数据满足定义的eq()相等关系，且该数据不是表中最后一个（有后继），
	 //则用next_e返回它的后继；否则操作失败，next_e无定义
		int i=LocateElem(e, eq);//将第一个与e满足eq()相等关系的数据的位序赋给i
		if(i==-1 || i==length-1)//没找到，或是最后一个元素
			return false;//操作失败
		else//找到值为e的元素，其位序为i
		{
			next_e=*(elem+i+1);//将elem[i]后一个元素的值赋给next_e
			return true;//操作成功
		}
	}
	bool ListInsert(int i, T e)
	{//在线性表位置i（0≤i≤ListLength()）处插入新的数据e
		T *newbase, *q, *p;
		if(i<0 || i>length)//i值不合法
			return false;
		if(length==listsize)//当前存储空间已满
		{//扩容
			newbase=new T[listsize*2];//新开辟空间为原先的2倍
			assert(newbase!=NULL);//存储分配失败则退出
			for(int j=0; j<length; j++)
				*(newbase+j)=*(elem+j);//将原表空间中的数据复制到新表空间
			delete[]elem;//释放原表空间
			elem=newbase;//新基址赋给elem
			listsize*=2;//更新存储容量
		}
		q=elem+i;//q为插入位置
		for(p=elem+length-1; p>=q; p--)//插入位置及之后的元素后移（由表尾元素开始移）
			*(p+1)=*p;
		*q=e;//插入e
		length++;//表长增1
		return true;
	}
	bool ListDelete(int i, T &e)
	{//删除线性表位序为i的数据（0≤i≤ListLength()-1），并用e返回其值
		T *p, *q;
		if(i<0 || i>=length)//i值不合法
			return false;
		p=elem+i;//p为被删除元素的位置
		e=*p;//被删除元素的值赋给e
		q=elem+length-1;//q为表尾元素的位置
		for(p++; p<=q; p++)//被删除元素之后的元素前移（由被删除元素的后继元素开始移）
			*(p-1)=*p;
		length--;//表长减1
		if(length<=listsize/4)//表长不大于存储容量的四分之一
		{
			p=new T[listsize/2];//开辟新表，长度减半
			for(int j=0; j<length; j++)
				*(p+j)=*(elem+j);//将原表空间中的数据复制到新表空间
			delete[]elem;//释放原表空间
			elem=p;//新基址赋给elem
			listsize/=2;//更新存储容量
		}
		return true;
	}
	void ListTraverse(void(*visit)(T&))const;//在类内声明成员函数
};
template<typename T>
void SqList<T>::ListTraverse(void(*visit)(T&))const//在类外定义成员函数
{//依次对每个数据调用函数visit()
	for(int i=0; i<length; i++)//从表的第一个元素到最后一个元素
		visit(elem[i]);//对每个数据调用visit()
	cout<<endl;
}
#endif
