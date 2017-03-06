#include <iostream>
#include "stdio.h"

using namespace std;

int max_f(int nums[],int len){
	int max=nums[0];
	for(int i=1; i<len; i++){
		max=max>nums[i]?max:nums[i];
	}
	return max;
}

int sum_f(int nums[],int len){
	int sum=0;
	for(int i=0; i<len; i++)
		sum+=nums[i];
	return sum;
}

int mid_f(int min,int max){
	return (min+max)/2;
}

int part_f(int nums[],int value,int len){
	int count=1,sum=nums[0];
	for(int i=1; i<len; i++){
		if(value<nums[i])
			return -1;
		sum+=nums[i];
		if(sum>value){
			count++;
			sum=nums[i];
		}
		//printf("-->%d\n", count);
	}
	return count;
}

int main(){
	int len=7,part=3;
	scanf("%d %d",&len,&part);
	int nums[len];
	for(int i=0; i<len; i++){
		scanf("%d",&nums[i]);
	}	
	int max,min,mid,count=0;
	min=max_f(nums,len);
	max=sum_f(nums,len)+1;
	mid=mid_f(min,max);
	//printf("***%d %d %d\n", min,max,mid);

	int part_now=part_f(nums,mid,len);
	int part_now_l=part_f(nums,mid-1,len);
	while(!(part_now<=part && (part_now_l>part || part_now_l==-1)) && count<100) {
		//printf("-->%d %d %d %d %d\n", part_now, mid,min,max,part_f(nums,mid-1,len));
	    if(part_now>part){	//目前分的比较多，需要扩大单个容量
	    	min=mid_f(min,max);
	    }else{				//目前分的比较少，有精简的余地，或者目前已经达标，尝试进一步精简
	    	max=mid_f(min,max);
	    }
	    mid=mid_f(min,max);
	    part_now=part_f(nums,mid,len);
	    part_now_l=part_f(nums,mid-1,len);
	    count++;
	}

	printf("%d\n",mid);

	return 0;
}
