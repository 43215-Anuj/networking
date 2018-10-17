#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;
void addError(string &a)
{
	int flip,i;
	srand(time(0));
	for(i=0;i<a.length();i++)
	{
		flip=(rand()%2);
		if(flip==0)
		{
			if(!(a.compare(i,1,"0")))
			{
				a.replace(i,1,"1");
			}
			else
			{
				a.replace(i,1,"0");
			}
		}
	}
	cout<<"\n CodeWord Received is :";
	cout<<a;
}

void checkOdd(string a)
{
	int f=0,i;	
	for(i=0;i<a.length();i++)
	{
		if(!(a.compare(i,1,"1")))
		{
			f++;
		}
	}

	if(f%2==1)
	{
		cout<<"\n It is a valid CodeWord\n";
	}
	else
	{
		cout<<"\n It is an Invalid CodeWord\n ";
	} 
}

void checkEven(string a)
{
	int f=0,i;	
	for(i=0;i<a.length();i++)
	{
		if(!(a.compare(i,1,"1")))
		{
			f++;
		}
	}

	if(f%2==0)
	{
		cout<<"\n It is a valid CodeWord\n";
	}
	else
	{
		cout<<"\n It is an Invalid CodeWord\n";
	} 
}
	
void Even(string &a)
{	
	int i,f=0;
	for(i=0;i<a.length();i++)
	{
		if(!(a.compare(i,1,"1")))
		{
			f++;
		}
	}

	if(f%2==0)
	{
		a.append("0");
	}
	else
	{
		a.append("1");
	} 

	cout<<"\n The CodeWord sent : ";
	cout<<a;
	
	//Adding error
	addError(a);
}

void Odd(string &a)
{	
	int i,f=0;
	for(i=0;i<a.length();i++)
	{
		if(!(a.compare(i,1,"0")))
		{
			f++;
		}
	}

	if(f%2==1)
	{
		a.append("0");
	}
	else
	{
		a.append("1");
	} 
	cout<<"\n The CodeWord is : ";
	cout<<a;
	addError(a);
}
int main()
{
	int i;
	string a;
	char ch,c;
	do{
	//cout<<"\n Enter the number of bits :";
	//cin>>n;
	
	cout<<"\n Enter the binary combination :";
	cin>>a;	

	for(i=0;i<a.length();i++)
	{
		if(!(!(a.compare(i,1,"0")!=0)||(!(a.compare(i,1,"1")!=0))))
		{
			cout<<"\n Invalid Entry\n";
			return 0;
		}
	}
	
	cout<<"\n 1. Even Parity";
	cout<<"\n 2. Odd Parity";
	cout<<"\n Enter Your Choice :";
	cin>>ch;
	
	switch(ch)
	{
		case '1': {	Even(a);	
					checkEven(a);
					break;
				}
		case '2': {	Odd(a);	
					checkOdd(a);
					break;
				}
		default:	cout<<"\n Wrong Choice";
	}
	cout<<"\n Do you want to goto menu again?";
	cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}


