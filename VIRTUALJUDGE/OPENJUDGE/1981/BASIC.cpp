#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
#include <cstring>
using namespace std;

const int maxn = 4000;

struct BIGN
{
	int len;
	int s[maxn];
	BIGN()
	{
		len = 1;
		memset(s,0,sizeof(s));
	}
	BIGN (int num) {*this = num	;}
	BIGN (const char * num){*this = num	;}
	BIGN operator = (const int num)
	
	{
		char s[maxn];
		sprintf(s,"%d",num);
		*this = s;
		return *this;
	}
	BIGN operator = (const char * num)
	{
		for( int i = 0 ; num[i]=='0';num++);
		len = strlen(num);
		for(int i = 0 ; i < len ; i++)
		{
		 	s[i]= num[len-i-1] - '0';
			
		}
		return *this; 
	}
	void clean()  
    {  
        while(len > 1 && !s[len-1]) len--;  
    }  
	BIGN operator + (const BIGN &B) const
	{
		BIGN c;
		c.len = 0;
		for( int i = 0 , g = 0; g||i<max(len,B.len);i++)
		{
			int x = g;
			if( i < len) x+= s[i];
			if(i < B.len) x+= B.s[i];
			c.s[c.len++] = x%10;
			g = x/10;
		}
		return c;
	}
	
	BIGN operator * (const BIGN &B)
	{
		BIGN c;
		c.len = len + B.len;
		for( int i = 0; i < len ;  i ++)
		{
			for( int j = 0 ; j < B.len ; j++)
			{
				c.s[i+j] = s[i] * B.s[j] + c.s[i+j];
			}
		}
		for( int i = 0 ; i < c.len; i ++)
		{
			c.s[i+1] = c.s[i]/10 + c.s[i+1];
			c.s[i+1] %= 10;
		}
		c.clean();
		return c;
	}
	
	string str() const
	{
		string res = "";
		for( int i = 0 ; i < len ; i++ ) res = char(s[i]+'0') + res;
		return res;
	}
};	


istream& operator >> (istream &in, BIGN &x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
} 
 
ostream& operator << (ostream &out, const BIGN &x)
{
	out << x.str();
	return out ;
}

 
 
 
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	
	BIGN A;
	BIGN B;
	cin >> A >> B;
	cout << A*B;
	 
	
	
	

	return 0;
} 
