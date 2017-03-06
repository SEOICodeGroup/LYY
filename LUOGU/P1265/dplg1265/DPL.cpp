#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int main(){
	while(true){
		system("randomdata > data.in");
		system("right < data.in > right.out");
		system("wrong < data.in > wrong.out");
		if(system("fc right.out wrong.out"))break;
	}
	system("pause");
	return 0;
}