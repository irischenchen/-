#include<iostream>
#include<bitset>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stack>
using namespace std;
#define N 1000
const double Pi=3.14159265358979323846;

class Calculator
{
public:
	Calculator(){};
};
class stack1
{
public:
	 struct stack
	{
		char ch[N];
		int top;
	}charstack;
	bool empty(stack1 ch)
	{
		if(ch.charstack.top==-1)
			return 1;
		else
			return 0;
	}
	void push(struct stack &ch,char c)
	{
		if(ch.top==N-1)
			cout<<"error"<<endl;
		else
		{
			ch.top++;
			ch.ch[ch.top]=c;
			
		}	
	}
	void pop(struct stack &ch,char &c)
	{
		if(ch.top==-1)
			cout<<"error"<<endl;
		else
		{
			c=ch.ch[ch.top];
			ch.top--;
		}
	}
};
class stacknum
{
public:
	struct Stacknum
	{
		double num[N];
		int top;
	}stacknum1;
	bool empty(stacknum num)
	{
		if(num.stacknum1.top==-1)
			return 1;
		else
			return 0;
	}
	void push(struct Stacknum &num,double n)
	{
		if(num.top==N-1)
			cout<<"error"<<endl;
		else
		{
			num.top++;
			num.num[num.top]=n;
			
		}	
	}
	void pop(struct Stacknum &num,double &n)
	{
		if(num.top==-1)
			cout<<"error "<<endl;
		else
		{
			n=num.num[num.top];
			num.top--;
		}
	}
};
class Yunsuan:public Calculator 
{
	stack1 Ch;
	stacknum Num;
public:
	Yunsuan(){};
	int in(char c)
	{
		if(c=='+'||c=='-')
			return 2;
		else if(c=='*'||c=='/')
			return 4;
		else
			return -1;
	}
	int out(char c)
	{
		if(c=='+'||c=='-')
			return 1;
		else if(c=='*'||c=='/')
			return 3;
		else
			return -1;
	}
	void count(double a,char c,double b)
	{
		double sum;
		switch(c)
		{
		case'+':sum=a+b;break;
		case'-':sum=a-b;break;
		case'*':sum=a*b;break;
		case'/':sum=a/b;break;
		default:break;
		}
		Num.push(Num.stacknum1,sum);
	}
	void yunsuan()
	{
		int i=0,j;
		double a,b,c;
		char x[50],t[20],ch;
		cout<<"输入算式以=结束:\n";
		cin>>x;
		Ch.charstack.top=-1;
		Num.stacknum1.top=-1;
		while(x[i]!='=')
		{
			if(isdigit(x[i]))
			{
				j=0;
				while(isdigit(x[i])||x[i]=='.')
				{
					t[j++]=x[i];
					i++;
				}
				t[j]='\0';
				c=atof(t);
				Num.push(Num.stacknum1,c);
			}
			else
			{
				if(x[i]=='+'||x[i]=='-'||x[i]=='/'||x[i]=='*')
				{
					if(in(Ch.charstack.ch[Ch.charstack.top])<out(x[i])||Ch.empty(Ch))
					{
						Ch.push(Ch.charstack,x[i]);
						i++;
					}
					else
					{
						Ch.pop(Ch.charstack,ch);
						Num.pop(Num.stacknum1,a);
						Num.pop(Num.stacknum1,b);
						count(b,ch,a);
					}
				}
			}
		}
		while(Ch.charstack.top!=-1)
		{
			Ch.pop(Ch.charstack,ch);
			Num.pop(Num.stacknum1,a);
			Num.pop(Num.stacknum1,b);
			count(b,ch,a);
		}
		cout<<"结果:"<<Num.stacknum1.num[Num.stacknum1.top]<<endl;
	}
};
class PFCF:public Calculator
{
	double x;
public:
	PFCF(double x)
	{
		this->x=x;
	}
	void jisuan()
	{
		int a;
		printf("请选择功能：1.平方 2.开方\n");
		cin>>a;
		cout<<"结果:";
		if(a==1)
			cout<<x*x<<endl;
		else if(a==2)
			cout<<sqrt(x)<<endl;
	}
};
class SJHS:public Calculator
{
public:
	SJHS(){}
	double Sin(double x){return sin(x*Pi/180.0);}
	double Cos(double x){return cos(x*Pi/180.0);}
	double Tan(double x){return tan(x*Pi/180.0);}
};
class JZZH:public Calculator
{
public:
	JZZH(){}
	void change10_all(int a,char *str,int b)
	{
		itoa(a,str,b);
		cout<<str<<endl;
	}
	void changeall_10(char *str,int xxx)
	{
		char *stop;
		cout<<strtol(str,&stop,xxx)<<endl;
	}
};
int main()
{
	printf("欢迎使用计算器 ━ (*^_^*)ノ\n");
	while(1)
	{
		printf("                                  **菜单**\n");
		printf("                            *1.    四则运算     *\n");
		printf("                            *2.  平方开方运算   *  \n");
		printf("                            *3.   三角函数      *      \n");
		printf("                            *4.   进制转换      *        \n");
		printf("                            *0.     exit        *        \n");
		printf("请输入所需功能对应的序号：");
		int x;
		scanf("%d",&x);
		if(x==1)
		{
			int xx;
			while(1)
			{
				Yunsuan ys;
				ys.yunsuan();
				printf("   输入0退出\n   输入其他数字继续进行四则运算\n");
				cin>>xx;
				if(xx==0)
					break;
			}
		}
		if(x==2)
		{
			double y;
			printf("请输入数字");
			cin>>y;
			PFCF kfcf(y);
			kfcf.jisuan();
		}
		if(x==3)
		{
			SJHS Sjhs;
			double z;char ch;
			cout<<"输入度数及函数类型s c t(如求sin45 则输入45s):";
			cin>>z>>ch;
			if(ch=='s')cout<<"sin"<<z<<"="<<Sjhs.Sin(z)<<endl;
			if(ch=='c')cout<<"cos"<<z<<"="<<Sjhs.Cos(z)<<endl;
			if(ch=='t')cout<<"tan"<<z<<"="<<Sjhs.Tan(z)<<endl;
			if(ch=='a'||ch=='b'||ch=='d'||ch=='e'||ch=='f'||ch=='g'||ch=='h'||ch=='i'||ch=='j'||ch=='k'||ch=='l'||ch=='m'||ch=='n'||ch=='o'||ch=='p'||ch=='q'||ch=='r'||ch=='u'||ch=='v'||ch=='w'||ch=='x'||ch=='y'||ch=='z')
				cout<<"                  输入错误"<<endl;
		}
		if(x==4)
		{
			JZZH jzzh;
			int zz;
			cout<<"1(10进制转任意进制) 2(任意进制转10进制):";
			cin>>zz;char str[50];
			if(zz==1)
			{
				int a,b;
				cout<<"输入10进制数及目标进制（10进制数 目标进制）:";
				cin>>a>>b;
				jzzh.change10_all(a,str,b);
			}
			else if(zz==2)
			{
				int xxx;
				cout<<"输入任意进制数(数字 数字的进制):";
				cin>>str>>xxx;
				jzzh.changeall_10(str,xxx);
			}
		}
		if(x==0)
		{
			printf("感谢使用\n");
			break;
		}
	}
	return 0;
}

