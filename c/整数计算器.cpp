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
//ջ 
int cmp(char x)
{
	if(x=='+'||x=='-')return 1;
	else if(x=='*'||x=='/')return 2;
	else return 0;
} 
//�Ƚ����ȼ� 
int main()
{
	cin>>s;
	sn="";
	s1.cpush('#');
	int len=s.size(),i=0,num;//len�ǳ��ȣ�i�ǵ�ǰ�ַ� 
	for(i=0;i<len;i++)
	{
		if(s[i]=='('){s1.cpush(s[i]);continue;}
		else if(s[i]==')')
		{
			//���� )�򽫾���S1ջջ�������(֮�����������������sn 
			while(s1.ctop()!='(')
			{
				sn+=s1.ctop();
				sn+=' ';//' '�ָ����ָ�����  1+9  1 9 + 19+95 19 95 +�� 
				s1.cpop();
			}
			s1.cpop();
			continue;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
		{
			//��ȡ�����ַ�����������������ȼ������Ⱥ�
			//��a*b+c*d�������* 
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
			//����ֱ�ӷ���sn�� 
			while(s[i]>='0'&&s[i]<='9')
			{
				sn+=s[i];i++;
			}
			sn+=' ';i--;
			continue;
		}
	}
	//��δ����ķ��ŵ��� 
	while(s1.ctop()!='#')
	{
		sn+=s1.ctop();
		sn+=' ';
		s1.cpop();
	}
	i=0;
	len=sn.size();
	//�����׺���ʽ 
	while(i<len)
	{
		//������� 
		if(sn[i]=='+') 
		{
			num=s2.top();
			s2.pop();
			num+=s2.top();
			s2.pop();
			i++; 
		}
		//������� 
		else if(sn[i]=='-')
		{
			num=s2.top();
			s2.pop();
			num=s2.top()-num;
			s2.pop();
			i++; 
		}
		//������� 
		else if(sn[i]=='*')
		{
			num=s2.top();
			s2.pop();
			num*=s2.top();
			s2.pop();
			i++; 
		}
		//������� 
		else if(sn[i]=='/')
		{
			num=s2.top();
			if(num==0)return 0; 
			s2.pop();
			num=s2.top()/num;
			s2.pop();
			i++; 
		}
		//���� 
		else 
		{
			num=0;
			while(sn[i]>='0'&&sn[i]<='9')
			{
				num=num*10+(sn[i]-'0');
				i++;
			}
		}
		//������ջ 
		s2.push(num); 
		if(sn[i]==' ')i++;
	} 
	cout<<s2.top()<<endl;
	return 0;
}
