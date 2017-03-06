//Main1-1.cpp 验证顺序表SqList<T>类的成员函数
#include "C.h"//文件包含宏命令
#include "SqList.h"//SqList<T>类
//以下两行可根据需要选其一（且只能选其一），而无须改变SqList.h
typedef int T;//定义以下的数据类型T为整型，print()需要。第5行
//typedef double T;//定义以下的数据类型T为双精度型，print()需要。第6行
#include "Func1-1.h"//4个常用的函数
void main()
{
	bool i;
	int j, k;
	T e, e0;
	SqList<T> L;//顺序表类的对象，主程序第4行
	for(j=1; j<=5; j++)
		L.ListInsert(0, j);//在L的表头插入j
	cout<<"在L的表头依次插入1～5后，L=";
	L.ListTraverse(print);//依次对表L中的元素调用print()函数（输出元素的值）
	cout<<"L是否空？"<<boolalpha<<L.ListEmpty()<<"，表长="
	<<L.ListLength()<<endl;
	L.GetElem(3, e);//用e返回L的elem[3]个数据的值
	cout<<"elem[3]的值为"<<e<<endl;
	for(j=L.ListLength()-1; j<=L.ListLength()+1; j++)
	{
		k=L.LocateElem(j, equal);//查找表L中与j相等的元素，并将其位序赋给k
		if(k>=0)//有符合条件的元素
			cout<<"值为"<<j<<"的元素位于L.elem["<<k<<"]，";
		else//k<0，没有符合条件的元素
			cout<<"没有值为"<<j<<"的元素\n";
	}
	k=L.LocateElem(2, sq);//查找表L中与2的平方相等的元素，并将其位序赋给k
	cout<<"与2的平方相等的元素其位序为["<<k<<"]\n";//上句在T为整型时可用
	for(j=0; j<=1; j++)//测试头两个数据
	{
		L.GetElem(j, e);//将L.elem[j]的值赋给e
		i=L.PriorElem(e, equal, e0);//求e的前驱，如成功，将值赋给e0
		if(i)//操作成功
			cout<<"元素"<<e<<"的前驱为"<<e0<<endl;
		else//操作失败
			cout<<"元素"<<e<<"无前驱，";
	}
	for(j=L.ListLength()-2; j<L.ListLength(); j++)//测试最后两个数据
	{
		L.GetElem(j, e);//将表L中的第j个元素的值赋给e
		i=L.NextElem(e, equal, e0);//求e的后继，如成功，将值赋给e0
		if(i)//操作成功
			cout<<"元素"<<e<<"的后继为"<<e0;
		else//操作失败
			cout<<"，元素"<<e<<"无后继"<<endl;
	}
	k=L.ListLength();//k为表长
	for(j=k; j>=k-1; j--)
	{
		i=L.ListDelete(j, e);//删除L.elem[j]，如成功，将值赋给e
		if(i)//删除成功
			cout<<"删除L.elem["<<j<<"]成功，其值为"<<e;
		else//表中不存在第j个数据
			cout<<"删除L.elem["<<j<<"]失败。";
	}
	L.ListTraverse(dbl);//依次对表L中的元素调用dbl()函数（使元素的值加倍）
	L.ListTraverse(print);//依次对表L中的元素调用print()函数（输出元素的值）
	SqList<T> L1;
	L1=L;//此句需要重载赋值运算符，主程序倒数第7行
	SqList<T> L2=L;//此句需要提供类的复制构造函数，主程序倒数第6行
	SqList<T> L3(L);//此句需要提供类的复制构造函数，主程序倒数第5行
	L.ClearList();//清空表L
	cout<<endl<<"清空L后，L是否空？"<<boolalpha<<L.ListEmpty();
	cout<<"，表长="<<L.ListLength()<<endl;
}
