#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int a[100005];
void ain(int num)
{
	for(int i=1;i<=num;i++)
		scanf("%d",&a[i]);	
	return ;
}
void aout(int num)
{
	for(int i=1;i<=num;i++)
		printf("%d ",a[i]);
	printf("\n");
	return ;
}
void amerge(int* a,int be,int end)
{
	int n1,n2,i=0,j=be;			//�ֽⲿ�֣��ѳ���Ϊn�����зֽ�Ϊ2��������ȷ���������ж�������� 
	if(end<=be)	
		return ;				//���������г���Ϊ1��ʼ���� 
	int mid=(end+be)/2;
	amerge(a,be,mid);			
	amerge(a,mid+1,end);		
	int len=end-be+1,b[len];	//�ϲ����� 
	n1=be;
	n2=mid+1;
	while(n1<=mid&&n2<=end)
	{
		if(a[n1]<a[n2])
		{
			b[i++]=a[n1];
			n1++;
		}
		else
		{
			b[i++]=a[n2];
			n2++;
		}
	}
	while(n1<=mid)
		b[i++]=a[n1++];
	while(n2<=end)
		b[i++]=a[n2++];	
	i=0;
	while(i<len)
		a[j++]=b[i++];	
	return ;
}
int main()
{
	int n;
	cin>>n;
	ain(n);
	amerge(a,1,n); 
	aout(n);
	return 0;
}

