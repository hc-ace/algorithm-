#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int b[1005];
char s[1005]; 
int main()
{
	int n,num,len,flat=0;//标记有几个元素 
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);		
		if(s[0]=='I')
		{
			scanf("%d",&num);
			b[flat]=num;
			flat++;
		}
		else if(s[0]=='P')
		{
			if(!flat)continue;
			flat--;
		}
		//算差值 
		else if(s[0]=='A') 
		{
			if(flat<2)continue;
			num=abs(b[flat-1]-b[flat-2]);
			b[flat-2]=num;
			flat--;
		}
		//复制一个元素 
		else if(s[0]=='C')
		{
			if(flat)
			{
				num=b[flat-1];
				b[flat]=num;
				flat++;
			}
		}
	}
	//cout<<flat<<endl; 
	//求和 
	num=0;
	for(int i=0;i<=flat-1;i++)
	{
		num+=b[i];
	}
	printf("%d\n",num);
	return 0;
}
