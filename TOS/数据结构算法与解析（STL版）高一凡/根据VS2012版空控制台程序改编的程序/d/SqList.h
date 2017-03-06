//SqList.h ˳�����ࣨSqList�ࣩ
#ifndef _SQLIST_H_
#define _SQLIST_H_
template<typename T>class SqList
{//��ģ���˳�����
	friend void MergeList(const SqList<T>&, const SqList<T>&, SqList<T>&);
	//������ͨ����MergeList()ΪSqList�����Ԫ��ʹ����Ե���SqList��˽�г�Ա
private://3��˽�����ݳ�Ա
	T *elem;//���Ա�洢�ռ�Ļ�ַ
	int length;//���Ա�ĵ�ǰ��
	int listsize;//���Ա�ǰ�Ĵ洢����
public://14����Ա����
	SqList(int k=1)
	{//���캯������̬���ɾ���k����ʼ�洢�ռ�Ŀ����Ա��޲�ʱk=1
		elem=new T[k];//��̬����k���洢�ռ�
		assert(elem!=NULL);//�洢����ʧ�����˳�
		length=0;//�ձ���Ϊ0
		listsize=k;//���ó�ʼ�洢����
	}
	SqList(const SqList &L)
	{//�ṩ��ĸ��ƹ��캯��������Ĭ�ϰ汾
		length=L.length;//��ͬL
		listsize=L.listsize;//�洢����ͬL
		elem=new T[listsize];//����listsize���·���ռ�
		assert(elem!=NULL);//�洢����ʧ�����˳�
		for(int i=0; i<length; i++)
			elem[i]=L.elem[i];//�����������
	}
	SqList& operator=(const SqList &L)
	{//���ظ�ֵ���������Ϊ��Ҫ��������ݳ�Ա��̬����ռ䣩
		if(this!=&L)//û����L=L�����
		{
			if(elem!=NULL)//elemָ��ĳ�洢�ռ�
				delete elem;//�ͷ�elemԭ�д洢�ռ�
			elem=new T[L.listsize];//����L.listsize���·���ռ�
			assert(elem!=NULL);//�洢����ʧ�����˳�
			for(int i=0; i<L.length; i++)
				elem[i]=L.elem[i];//�����������
		}
		return *this;
	}
	~SqList()
	{//��������
		delete[]elem;//�ͷ�elem��ָ�Ĵ洢�ռ�����
	}
	void ClearList()
	{//�������Ա�Ϊ�ձ�
		length=0;
	}
	bool ListEmpty()const//����Ա����������ı�����ֵ
	{//�����Ա�Ϊ�ձ��򷵻�true�����򷵻�false
		return length==0;
	}
	int ListLength()const
	{//�������Ա�ĳ���
		return length;
	}
	bool GetElem(int i, T &e)const
	{//��e�������Ա��i�����ݵ�ֵ��0��i��ListLength()-1��
		if(i<0 || i>=length)//i���ڱ�ķ�Χ֮��
			return false;
		e=*(elem+i);//��elem[i]��ֵ����e
		return true;
	}
	int LocateElem(T e, bool(*eq)(T, T))const
	{//���ص�һ����e�����ϵeq()�����ݵ�λ��0��ListLength()-1����
	 //�����������ݲ����ڣ��򷵻�ֵΪ-1
		int i=0;//i�ĳ�ֵָʾ��һ������
		while(i<length && !eq(*(elem+i), e))
		//iû������ķ�Χ��i��ָ��������e�������ϵeq()
			i++;//������1�����������
		if(i<length)//�ҵ������ϵeq()������
			return i;//������λ��
		else//û�ҵ������ϵ������
			return -1;
	}
	bool PriorElem(T e, bool(*eq)(T, T), T &pre_e)const
	{//��e����ĳ�������㶨���eq()��ȹ�ϵ���Ҹ����ݲ��Ǳ��е�һ������ǰ������
	 //����pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
		int i=LocateElem(e, eq);//����һ����e����eq()��ȹ�ϵ�����ݵ�λ�򸳸�i
		if(i<=0)//û�ҵ������ǵ�һ��Ԫ�أ�û��ǰ����
			return false;//����ʧ��
		else//�ҵ�ֵΪe��Ԫ�أ���λ��Ϊi
		{
			pre_e=*(elem+i-1);//��elem[i]ǰһ��Ԫ�ص�ֵ����pre_e
			return true;//�����ɹ�
		}
	}
	bool NextElem(T e, bool(*eq)(T, T), T &next_e)const
	{//��e����ĳ�������㶨���eq()��ȹ�ϵ���Ҹ����ݲ��Ǳ������һ�����к�̣���
	 //����next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
		int i=LocateElem(e, eq);//����һ����e����eq()��ȹ�ϵ�����ݵ�λ�򸳸�i
		if(i==-1 || i==length-1)//û�ҵ����������һ��Ԫ��
			return false;//����ʧ��
		else//�ҵ�ֵΪe��Ԫ�أ���λ��Ϊi
		{
			next_e=*(elem+i+1);//��elem[i]��һ��Ԫ�ص�ֵ����next_e
			return true;//�����ɹ�
		}
	}
	bool ListInsert(int i, T e)
	{//�����Ա�λ��i��0��i��ListLength()���������µ�����e
		T *newbase, *q, *p;
		if(i<0 || i>length)//iֵ���Ϸ�
			return false;
		if(length==listsize)//��ǰ�洢�ռ�����
		{//����
			newbase=new T[listsize*2];//�¿��ٿռ�Ϊԭ�ȵ�2��
			assert(newbase!=NULL);//�洢����ʧ�����˳�
			for(int j=0; j<length; j++)
				*(newbase+j)=*(elem+j);//��ԭ��ռ��е����ݸ��Ƶ��±�ռ�
			delete[]elem;//�ͷ�ԭ��ռ�
			elem=newbase;//�»�ַ����elem
			listsize*=2;//���´洢����
		}
		q=elem+i;//qΪ����λ��
		for(p=elem+length-1; p>=q; p--)//����λ�ü�֮���Ԫ�غ��ƣ��ɱ�βԪ�ؿ�ʼ�ƣ�
			*(p+1)=*p;
		*q=e;//����e
		length++;//����1
		return true;
	}
	bool ListDelete(int i, T &e)
	{//ɾ�����Ա�λ��Ϊi�����ݣ�0��i��ListLength()-1��������e������ֵ
		T *p, *q;
		if(i<0 || i>=length)//iֵ���Ϸ�
			return false;
		p=elem+i;//pΪ��ɾ��Ԫ�ص�λ��
		e=*p;//��ɾ��Ԫ�ص�ֵ����e
		q=elem+length-1;//qΪ��βԪ�ص�λ��
		for(p++; p<=q; p++)//��ɾ��Ԫ��֮���Ԫ��ǰ�ƣ��ɱ�ɾ��Ԫ�صĺ��Ԫ�ؿ�ʼ�ƣ�
			*(p-1)=*p;
		length--;//����1
		if(length<=listsize/4)//�������ڴ洢�������ķ�֮һ
		{
			p=new T[listsize/2];//�����±����ȼ���
			for(int j=0; j<length; j++)
				*(p+j)=*(elem+j);//��ԭ��ռ��е����ݸ��Ƶ��±�ռ�
			delete[]elem;//�ͷ�ԭ��ռ�
			elem=p;//�»�ַ����elem
			listsize/=2;//���´洢����
		}
		return true;
	}
	void ListTraverse(void(*visit)(T&))const;//������������Ա����
};
template<typename T>
void SqList<T>::ListTraverse(void(*visit)(T&))const//�����ⶨ���Ա����
{//���ζ�ÿ�����ݵ��ú���visit()
	for(int i=0; i<length; i++)//�ӱ�ĵ�һ��Ԫ�ص����һ��Ԫ��
		visit(elem[i]);//��ÿ�����ݵ���visit()
	cout<<endl;
}
#endif
