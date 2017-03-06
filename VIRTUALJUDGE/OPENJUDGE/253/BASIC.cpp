void insert_B( element_type x, Node* &p, int &b )
{                                               /* 平衡树插入函数 */
	if ( !p )
	{
		p	= new Node();
		p->data = x;
		p->Lson = p->Rson = NULL; p->bal = 0;
		b	= 1;                    /* p点升高 */
		return;
	}
	if ( x <= p->data )
	{
		insert_B( x, p->Lson, b );
		if ( b )
			Ibalance_L( p, b );     /* “左”平衡处理 */
	}else  {
		insert_B( x, p->Rson, b )
		if ( b )
			Ibalance_R( p, b );     /* “右”平衡处理 */
	}
}


void Ibalance_L( Node* &p, int &b )
/* 左平衡树处理函数 */
{
	Node* p1, p2;
	if ( p->bal == 1 )                      /*不再向上层回溯 */
	{
		p->bal = 0; b = 0; return;
	}else
	if ( p->bal == 0 )                      /* 向上层回溯 */
	{
		p->bal = -1; return;
	}else                       { /* 旋转以p为根的子树 */
		p1 = p->Lson;                   /* 取p的左儿子p1 */
		if ( p1->bal == -1 )           /* LL 旋转 */
		{
			p->Lson		= p1->Rson; p->bal = 0;
			p1->Rson	= p;
			p1->bal		= 0;
			p		= p1;   /* 将p的父亲的链域改为p1 */
			b		= 0;    /* 置停止回溯标记 */
			return;
		}else  { /* LR双旋 */
/* LR旋转 */
			p2		= p1->Rson;
			p1->Rson	= p2->Lson;
			p2->Lson	= p1;
			p->Lson		= p2->Rson;
			p2->Rson	= p;

			if ( p2->bal == 0 )
				p->bal = p1->bal = 0;   /* p2是新叶 */
			else
			if ( p2->bal == -1 )           /* x插在p2的左子树上 */
			{
				p1->bal = 0; p->bal = 1;
			}else                           { /* x插在p2的右子树上 */
				p1->bal = -1; p->bal = 0;
			}
			p	= p2;                   /* 改将p之父的链域改为p2 */
			p->bal	= 0;
			b	= 0;                    /* 置停止回溯标记 */
			return;
		}
	}
}


…
b=0; 
insert_B(x,root, b );//b=0表示平衡树的高不变，=1表示高增高了 


