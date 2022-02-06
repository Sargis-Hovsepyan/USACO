/*
ID:		sargish1
LANG:	C++
PROG:	friday
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int month[2][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
int day[10];

int leap(int year)
{
	if((year%4==0&&year%100!=0)||(year%400==0))
		return 1;
	return 0;
}
int work(int x,int year,int k)
{
	int date=1;
	for(int i=0;i<12;i++)
	{
		for(int j=1;j<=month[x][i];j++)
		{
			date++;
			date %= month[x][i];
			k++;
			k%=7;
			if(date==13)
				day[k]++;
		}
	}
	return k;
}

int main()
{
	freopen("friday.in","r",stdin);
	freopen("friday.out","w",stdout);
	int n,k=1;

	scanf("%d",&n);
    for(int i=1900;i<=1900+n-1;i++)
         k=work(leap(i),i,k);
     printf("%d %d %d %d %d %d %d\n",day[6],day[0],day[1],day[2],day[3],day[4],day[5]);
     return 0;
 }
