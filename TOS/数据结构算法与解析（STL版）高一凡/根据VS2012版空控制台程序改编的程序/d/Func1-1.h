//Func1-1.h 5�����õĺ���
bool equal(int c1, int c2)//PriorElem()�ȿɵ���
{//�ж��Ƿ���ȵĺ���������TΪint����
	return c1==c2;//�����ж����
}
bool sq(int c1, int c2)
{ // ����Ԫ���ж�����(ƽ����ϵ)��LocateElem()���õĺ���
	return c1==c2*c2;
}
bool equal(double c1, double c2)//PriorElem()�ȿɵ���
{//�ж��Ƿ���ȵĺ���������TΪdouble����
	return abs(c1-c2)<1.0e-6;//ʵ���ж϶���֮��С��һ����С����
}
inline void print(T &c)//ListTraverse()�ɵ��ã���������
{//���c������TΪ�������ͣ��ṹ����������ݾ���ṹ�رࣩ
	cout<<c<<" ";
}
inline void dbl(T &c)//ListTraverse()�ɵ��ã���������
{//ʹc��ֵ�ӱ�������TΪ�������ͣ��ɸ��ݲ�ͬ�ľ���Ҫ���رࣩ
	c*=2;
}
