#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main()
{
	int i,j;
	int a[]={5,3,4,4,1};
	int len=sizeof(a)/sizeof(int);	//求不定长数组长度 
	for(i=1;i<len;i++)			
	{
		int key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
	i=0;
	while(i<len)
	{
		cout<<a[i++]<<" ";
	}
	return 0;
}

