#include<stdio.h>
#include<string.h>
#define maxn 1005
char a[maxn],b[maxn];
int num[2]={0},n[2]={0},len;
void suan(char s[],int ac)
{
	int flat=0,flat2=0,ans=0,i;	
	if(len==1&&s[0]=='i')
	{
		num[ac]=0;
		n[ac]=1;
		return ;
	}
	for(i=0;i<len;i++)
	{
	if(s[i]=='-'&&i==0)
	{
	flat=1;	continue;
	}
	if((s[i]=='-'||s[i]=='+')&&i!=0)
	{
		if(s[i]=='-')flat2=-1;
		else flat2=1;
		num[ac]=ans;
		ans=0;
		continue;
	}
	if(s[i]=='i')
	{
		if(s[i-1]=='+')n[ac]=1;
		else if(s[i-1]=='-')n[ac]=1;
		else n[ac]=ans;
		ans=0;
		continue;
	}
	ans=ans*10+s[i]-'0';
	}
	if(flat2==-1)n[ac]=n[ac]*-1;
	if(num[ac]==0)num[ac]=ans;	
	if(flat)
	{
	if(num[ac]!=0)num[ac]=num[ac]*-1;
	else n[ac]=n[ac]*-1;	
	}	
}
int main()
{
	scanf("%s %s",a,b);
	len=strlen(a);
	suan(a,0);
	len=strlen(b);
	suan(b,1); 
	int n1=num[0]+num[1],i1=n[0]+n[1];
	printf("%d%d\n",num[0],n[0]);
	printf("%d%d\n",num[1],n[1]);
	if(i1==0)printf("%d\n",n1);
	else if(n1==0&&i1==1)printf("i\n");
	else if(n1==0&&i1==-1)printf("-i\n");
	else if(n1==0)printf("%di\n",i1);
	else if(i1==1)printf("%d+i\n",n1);
	else if(i1==-1)printf("%d-i\n",n1);
	else if(i1>=1)printf("%d+%di\n",n1,i1);
	else printf("%d%di\n",n1,i1);
	return 0;
}
