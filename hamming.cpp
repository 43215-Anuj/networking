#include<iostream>
#include<ios>
#include<limits>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;

int countParity(int n)
{
		int k=0;
		while((pow(2,k)-k)<(n+1))
			{
				k++;
			}
 	return k;
}

//void setInfo(int c[],int n,int m)
string setInfo(string a, int m)
{
	int i,j,l=0;
	string c;
	string t=" ";
	j=0;
	
	
	for(i=0;i<m;i++)
		{
			if((i+1)==pow(2,j))
			{
				//code[i]=0;
				t.replace(i,1,"0");
				j++;
			}
			else
			{
				//code[i]=c[l++];
				c=a[l];
				t.replace(i,1,c);
				l++;
			}
		}
	/*
	for(i=0;i<m;i++)
	{
		c[i]=code[i];
	}
	*/
	return t;
}

int brk(int no)
{	
	int i,j;
	i=0;
	if(no==1)
	{
		return no;
	}
	else
	{
		while(no >= pow(2,i))
		{
			i++;
		}	
		i--;
		return(pow(2,i));	
	}
	
}
//int findParity(int c[],int k,int m,int mat[][10])
int findParity(string a,int k,int m, int mat[][10])
{

	int i,j=0,rem,el,val,c[10],s[50],n=0;
	string t;
	
	for(i=0;i<a.length();i++)
	{
		c[i]=a[i]-'0';	
	}
	for(i=0;i<m;i++)
	{
		if(c[i]==1)
		{
			s[j++]=i+1;
		}
	}
	el=j;
	//rem=s[0];
	for(i=0;i<el;i++)
	{	
		rem=s[i];
		for(j=0;j<k;j--)
		{	
			if(rem==0)
			{
				break;
			}
			else
			{
				val=brk(rem);
			
				for(int x=0;x<k;x++)
				{
					if(pow(2,x)==val)
					{
						mat[i][x]=1;
					}
				}
				rem=rem-val;
			}
		}
	}
	return el;
}
	
int main()
{
	int k,m,i,c[50],mat[10][10],el,j,count,index;
	char ch;
	bool flag=false;
	string a;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			mat[i][j]=0;
		}
	}

do{
	flag=true;
	cout<<"\n Enter the Information Bits :";
	cin>>a;	

	for(i=0;i<a.length();i++)
	{
		if(!(!(a.compare(i,1,"0")!=0)||(!(a.compare(i,1,"1")!=0))))
		{
			cout<<"\n Invalid Entry\n";
			cout<<"\n Enter again";
			flag=false;
		}
	}
	
}while(flag==false);
	/*
	cout<<" \n Enter the number of bits for Information Bits :        ";
	cin>>n;
	cout<<" \n Enter the Information Bits(Array Format) :        ";

	for(i=0;i<n;i++)
	{
		try
		{	cin>>c[i];
			if(c[i]!=0 && c[i]!=1)
			{
				throw i;
			}
		}
		catch(int s)
		{
			cout<<"\n Error in "<<i+1<<"th bit, please enter Again: ";
			i--;

		}			
	}
*/
	cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
	
	cout<<"\n The Sent CodeWord is :				";
	cout<<a;
	/*
	for(i=0;i<n;i++)
		cout<<c[i]<<" ";
	*/
	k=countParity(a.length());
	cout<<"\n The number of parity bits will be :                    "<<k;
	m=a.length()+k;
	cout<<"\n Hence, Size of codeWord will be :                      "<<m;

	//setInfo(c,n,m);
	a=setInfo(a,m);
	cout<<"\nreturn ="<<a;
	//el=findParity(c,k,m,mat);
	el=findParity(a,k,m,mat);

	do{
		flag=true;
	cout<<"\n 1. Even Parity";
	cout<<"\n 2. Odd Parity";
	cout<<"\n Enter Your Choice :";
	cin>>ch;

	switch(ch)
	{	case '1':{
					for(i=0;i<k;i++)
					{	count=0;
						for(j=0;j<el;j++)
						{
							if(mat[j][i]==1)
								count++;
							index=(pow(2,i)-1);
							if(count%2==0)
							{	
								a.replace(index,1,"0");
								//c[index]=0;
							}
							else
							{
								a.replace(index,1,"1");
								//c[index]=1;
							}
						}
					}break;
				}
		case '2':{
					for(i=0;i<k;i++)
					{	count=0;
						for(j=0;j<el;j++)
						{	
							index=(pow(2,i)-1);
							if(mat[j][i]==1)
								count++;
						
							if(count%2==1)
							{
								a.replace(index,1,"0");
								//c[index]=0;
							}
							else
							{
								a.replace(index,1,"1");
								//c[index]=1;
							}
						}
					}break;
				}
		default:{ 
					cout<<"\n Wrong Choice\nEnter Again";
					flag=false;
				}
	}
}while(flag==false);
	cout<<"\n Parity bits are :				        ";
	index=pow(2,i)-1;
	for(i=0;i<k;i++)
	{
		index=pow(2,i)-1;
		cout<<a[index]<<" ";
	}
	
	cout<<"\n Hence, The CodeWord is:                                ";
	cout<<a;
	/*for(i=0;i<m;i++)
		{
			cout<<c[i]<<" ";
		}
		*/
	cout<<"\n";
}
