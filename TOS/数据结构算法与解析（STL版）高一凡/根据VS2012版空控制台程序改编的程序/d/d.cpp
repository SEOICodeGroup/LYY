//Main1-1.cpp ��֤˳���SqList<T>��ĳ�Ա����
#include "C.h"//�ļ�����������
#include "SqList.h"//SqList<T>��
//�������пɸ�����Ҫѡ��һ����ֻ��ѡ��һ����������ı�SqList.h
typedef int T;//�������µ���������TΪ���ͣ�print()��Ҫ����5��
//typedef double T;//�������µ���������TΪ˫�����ͣ�print()��Ҫ����6��
#include "Func1-1.h"//4�����õĺ���
void main()
{
	bool i;
	int j, k;
	T e, e0;
	SqList<T> L;//˳�����Ķ����������4��
	for(j=1; j<=5; j++)
		L.ListInsert(0, j);//��L�ı�ͷ����j
	cout<<"��L�ı�ͷ���β���1��5��L=";
	L.ListTraverse(print);//���ζԱ�L�е�Ԫ�ص���print()���������Ԫ�ص�ֵ��
	cout<<"L�Ƿ�գ�"<<boolalpha<<L.ListEmpty()<<"����="
	<<L.ListLength()<<endl;
	L.GetElem(3, e);//��e����L��elem[3]�����ݵ�ֵ
	cout<<"elem[3]��ֵΪ"<<e<<endl;
	for(j=L.ListLength()-1; j<=L.ListLength()+1; j++)
	{
		k=L.LocateElem(j, equal);//���ұ�L����j��ȵ�Ԫ�أ�������λ�򸳸�k
		if(k>=0)//�з���������Ԫ��
			cout<<"ֵΪ"<<j<<"��Ԫ��λ��L.elem["<<k<<"]��";
		else//k<0��û�з���������Ԫ��
			cout<<"û��ֵΪ"<<j<<"��Ԫ��\n";
	}
	k=L.LocateElem(2, sq);//���ұ�L����2��ƽ����ȵ�Ԫ�أ�������λ�򸳸�k
	cout<<"��2��ƽ����ȵ�Ԫ����λ��Ϊ["<<k<<"]\n";//�Ͼ���TΪ����ʱ����
	for(j=0; j<=1; j++)//����ͷ��������
	{
		L.GetElem(j, e);//��L.elem[j]��ֵ����e
		i=L.PriorElem(e, equal, e0);//��e��ǰ������ɹ�����ֵ����e0
		if(i)//�����ɹ�
			cout<<"Ԫ��"<<e<<"��ǰ��Ϊ"<<e0<<endl;
		else//����ʧ��
			cout<<"Ԫ��"<<e<<"��ǰ����";
	}
	for(j=L.ListLength()-2; j<L.ListLength(); j++)//���������������
	{
		L.GetElem(j, e);//����L�еĵ�j��Ԫ�ص�ֵ����e
		i=L.NextElem(e, equal, e0);//��e�ĺ�̣���ɹ�����ֵ����e0
		if(i)//�����ɹ�
			cout<<"Ԫ��"<<e<<"�ĺ��Ϊ"<<e0;
		else//����ʧ��
			cout<<"��Ԫ��"<<e<<"�޺��"<<endl;
	}
	k=L.ListLength();//kΪ��
	for(j=k; j>=k-1; j--)
	{
		i=L.ListDelete(j, e);//ɾ��L.elem[j]����ɹ�����ֵ����e
		if(i)//ɾ���ɹ�
			cout<<"ɾ��L.elem["<<j<<"]�ɹ�����ֵΪ"<<e;
		else//���в����ڵ�j������
			cout<<"ɾ��L.elem["<<j<<"]ʧ�ܡ�";
	}
	L.ListTraverse(dbl);//���ζԱ�L�е�Ԫ�ص���dbl()������ʹԪ�ص�ֵ�ӱ���
	L.ListTraverse(print);//���ζԱ�L�е�Ԫ�ص���print()���������Ԫ�ص�ֵ��
	SqList<T> L1;
	L1=L;//�˾���Ҫ���ظ�ֵ�����������������7��
	SqList<T> L2=L;//�˾���Ҫ�ṩ��ĸ��ƹ��캯��������������6��
	SqList<T> L3(L);//�˾���Ҫ�ṩ��ĸ��ƹ��캯��������������5��
	L.ClearList();//��ձ�L
	cout<<endl<<"���L��L�Ƿ�գ�"<<boolalpha<<L.ListEmpty();
	cout<<"����="<<L.ListLength()<<endl;
}
