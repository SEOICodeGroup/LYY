void insert_B( element_type x, Node* &p, int &b )
{                                               /* ƽ�������뺯�� */
	if ( !p )
	{
		p	= new Node();
		p->data = x;
		p->Lson = p->Rson = NULL; p->bal = 0;
		b	= 1;                    /* p������ */
		return;
	}
	if ( x <= p->data )
	{
		insert_B( x, p->Lson, b );
		if ( b )
			Ibalance_L( p, b );     /* ����ƽ�⴦�� */
	}else  {
		insert_B( x, p->Rson, b )
		if ( b )
			Ibalance_R( p, b );     /* ���ҡ�ƽ�⴦�� */
	}
}


void Ibalance_L( Node* &p, int &b )
/* ��ƽ���������� */
{
	Node* p1, p2;
	if ( p->bal == 1 )                      /*�������ϲ���� */
	{
		p->bal = 0; b = 0; return;
	}else
	if ( p->bal == 0 )                      /* ���ϲ���� */
	{
		p->bal = -1; return;
	}else                       { /* ��ת��pΪ�������� */
		p1 = p->Lson;                   /* ȡp�������p1 */
		if ( p1->bal == -1 )           /* LL ��ת */
		{
			p->Lson		= p1->Rson; p->bal = 0;
			p1->Rson	= p;
			p1->bal		= 0;
			p		= p1;   /* ��p�ĸ��׵������Ϊp1 */
			b		= 0;    /* ��ֹͣ���ݱ�� */
			return;
		}else  { /* LR˫�� */
/* LR��ת */
			p2		= p1->Rson;
			p1->Rson	= p2->Lson;
			p2->Lson	= p1;
			p->Lson		= p2->Rson;
			p2->Rson	= p;

			if ( p2->bal == 0 )
				p->bal = p1->bal = 0;   /* p2����Ҷ */
			else
			if ( p2->bal == -1 )           /* x����p2���������� */
			{
				p1->bal = 0; p->bal = 1;
			}else                           { /* x����p2���������� */
				p1->bal = -1; p->bal = 0;
			}
			p	= p2;                   /* �Ľ�p֮���������Ϊp2 */
			p->bal	= 0;
			b	= 0;                    /* ��ֹͣ���ݱ�� */
			return;
		}
	}
}


��
b=0; 
insert_B(x,root, b );//b=0��ʾƽ�����ĸ߲��䣬=1��ʾ�������� 


