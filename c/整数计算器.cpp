#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string s,sn;
int count=0,count1=0;
class Stack
{
	private:
		char a[1005];
		int b[1005];
	public:
		void push(int x)
		{
			b[count++]=x;
			return ;
		}
		void cpush(char h)
		{
			a[count1++]=h;
		}
		int top()
		{
			return b[count-1];
		}
		char ctop()
		{
			return a[count1-1];
		}
		int length()
		{
			return count;
		}
		int clength()
		{
			return count1;
		}
		int pop()
		{
			int len1=length();
			if(len1==0)
			{
				return -1;
			}
			count--;
			return b[count];
		}
		char cpop()
		{
			int len1=clength();
			if(len1==0)
			{
				return -1;
			}
			count1--;
			return a[count1];
		}
}s1,s2;
//栈 
int cmp(char x)
{
	if(x=='+'||x=='-')return 1;
	else if(x=='*'||x=='/')return 2;
	else return 0;
} 
//比较优先级 
int main()
{
	cin>>s;
	sn="";
	s1.cpush('#');
	int len=s.size(),i=0,num;//len是长度，i是当前字符 
	for(i=0;i<len;i++)
	{
		if(s[i]=='('){s1.cpush(s[i]);continue;}
		else if(s[i]==')')
		{
			//遇到 )则将距离S1栈栈顶最近的(之间的运算符，逐个送入sn 
			while(s1.ctop()!='(')
			{
				sn+=s1.ctop();
				sn+=' ';//' '分隔数字跟符号  1+9  1 9 + 19+95 19 95 +； 
				s1.cpop();
			}
			s1.cpop();
			continue;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			//若取出的字符是运算符，根据优先级安排先后
			//例a*b+c*d优先输出* 
			while(cmp(s1.ctop())>=cmp(s[i]))
			{
				sn+=s1.ctop();
				sn+=' ';
				s1.cpop();
			}
			s1.cpush(s[i]);
			continue;
		}
		else 
		{
			//数字直接放入sn中 
			while(s[i]>='0'&&s[i]<='9')
			{
				sn+=s[i];i++;
			}
			sn+=' ';i--;
			continue;
		}
	}
	//将未导入的符号导入 
	while(s1.ctop()!='#')
	{
		sn+=s1.ctop();
		sn+=' ';
		s1.cpop();
	}
	i=0;
	len=sn.size();
	//计算后缀表达式 
	while(i<len)
	{
		//两者相加 
		if(sn[i]=='+') 
		{
			num=s2.top();
			s2.pop();
			num+=s2.top();
			s2.pop();
			i++; 
		}
		//两者相减 
		else if(sn[i]=='-')
		{
			num=s2.top();
			s2.pop();
			num=s2.top()-num;
			s2.pop();
			i++; 
		}
		//两者相乘 
		else if(sn[i]=='*')
		{
			num=s2.top();
			s2.pop();
			num*=s2.top();
			s2.pop();
			i++; 
		}
		//两者相除 
		else if(sn[i]=='/')
		{
			num=s2.top();
			if(num==0)return 0; 
			s2.pop();
			num=s2.top()/num;
			s2.pop();
			i++; 
		}
		//数字 
		else 
		{
			num=0;
			while(sn[i]>='0'&&sn[i]<='9')
			{
				num=num*10+(sn[i]-'0');
				i++;
			}
		}
		//数字入栈 
		s2.push(num); 
		if(sn[i]==' ')i++;
	} 
	cout<<s2.top()<<endl;
	return 0;
}
