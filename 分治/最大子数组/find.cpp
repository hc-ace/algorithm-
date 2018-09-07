#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define intmin INT_MIN
/*
求最大子数组可以考虑把数组分为两个数组，
然后再考虑三种情况： 
都在左半边，都在右半边，以及经过中间
*/
int* find_max_crossing_subarray(int* a,int low, int mid, int high)	//求经过中点的 
{
	int *res;
	res=(int*)malloc(sizeof(int)*3);
	int sum=0;
	int left_sum=intmin,right_sum=intmin;
	int max_right,max_left;
	for(int i=mid;i>=low;i--)
	{
		sum+=a[i];
		if(sum>left_sum)
		{
			left_sum=sum;
			res[0]=i;
		}
	}
	sum=0;
	for(int j=mid+1;j<=high;j++)
	{
		sum+=a[j];
		if(sum>right_sum)
		{
			right_sum=sum;
			res[1]=j;
		}	
	}
	res[2]=left_sum+right_sum;
	return res;
} 
int* find_maximun_subarray(int* a,int low,int high)
{
	int *res;
	int *lres,*rres,*cres;
	res =(int*)malloc(sizeof(int)*3);
	lres =(int*)malloc(sizeof(int)*3);
	rres =(int*)malloc(sizeof(int)*3);
	cres =(int*)malloc(sizeof(int)*3);
	if(high == low)
	{
		res[0]=low;
		res[1]=high;
		res[2]=a[low];
		//return (low,high,a[low]);
		return res;
	}
	else
	{
		int mid=(low+high)/2;
		lres=find_maximun_subarray(a,low,mid);
		rres=find_maximun_subarray(a,mid+1,high);
		cres=find_max_crossing_subarray(a,low, mid, high);
		if(max(lres[2],max(cres[2],rres[2]))==lres[2])
			return lres;
		else if(max(lres[2],max(cres[2],rres[2]))==rres[2])
			return rres;	
		else
			return cres;
	}
} 
int main()
{
	int i,j;
	int a[]={13,-3,-25,20,18,20,-3,-16,-23,-7,12,-5,-22,15,-4,7};
	int *sum;
	sum=find_maximun_subarray(a,0,sizeof(a)/sizeof(int)-1);
	cout<<"最长子数组范围及大小："<<sum[0]<<" "<<sum[1]<<" "<<sum[2];
	return 0;
}

