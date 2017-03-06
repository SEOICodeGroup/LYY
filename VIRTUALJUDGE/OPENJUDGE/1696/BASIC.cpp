#include<iostream>
#include<cstring>
using namespace std;
const int MAXN = 4000;
struct BIGNUM
{
int len,s[MAXN];
BIGNUM(){len=1;memset(s,0,sizeof(s));}

BIGNUM operator = (const char* num){
len=strlen(num);
for(int i =0;i<len;++i) s[i]=num[len-i-1]-'0';
return *this;
}

BIGNUM operator = (const int num){
char a[MAXN];
*this = a;
return *this;
}
BIGNUM(int num){*this=num;}
BIGNUM(const char* num){*this=num;}

BIGNUM operator+(const BIGNUM&a){
BIGNUM c;
c.len=max(len,a.len)+1;
for(int i =0,x=0;i<c.len;++i){
c.s[i]=s[i]+a.s[i]+x;
x=c.s[i]/10;
c.s[i]=c.s[i]%10;
}
if(c.s[c.len-1]==0)--c.len;
return c;
}
BIGNUM operator-(const BIGNUM&a){
BIGNUM c;
c.len=max(len,a.len)-1;//-1
for(int i =0;i<c.len;++i){
if (s[i]<a.s[i]) {s[i]+=10;s[i+1]-1;}
c.s[i]=s[i]-a.s[i];
}
//int x = c.len
/*for(int i = 1;;i--)
{
if(c.s[x-i]==0)--c.len;
if(c.s[x-i]!=0)break;}*/
if(c.s[c.len-1]==0)--c.len;
return c;
}
BIGNUM operator += (const BIGNUM &a){
*this = *this + a;
return *this;
}
bool operator < (const BIGNUM& x) const{
if(len != x.len) return len<x.len;
for(int i = len-1;i>=0;--i){
if(s[i]!=x.s[i])return s[i]<x.s[i];
}
return false;
}
bool operator >(const BIGNUM &x) const{return x<*this;}
bool operator <=(const BIGNUM &x) const{return !(x>*this);}
bool operator >=(const BIGNUM &x) const{return !(x<*this);}
bool operator ==(const BIGNUM &x) const{return !(x<*this||x>*this);}
bool operator !=(const BIGNUM &x) const{return (x<*this||x>*this);}
};
ostream& operator << (ostream &out, const BIGNUM& x){
for (int i =x.len-1;i>=0;--i) cout <<x.s[i];
return out;
}
istream& operator >> (istream &in,BIGNUM &x){
char num[MAXN];
in>>num;
x=num;
return in;
}


int main()
{
	BIGNUM A,B;
	cin >> A>>B;
	cout << A-B;
	return 0;
}






