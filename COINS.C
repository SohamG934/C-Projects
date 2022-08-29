#include<stdio.h>
#include<conio.h>
#include <string.h>
char* change(int coins)
{
char str[80],a[20];
int c,p;
int cnt50=0,cnt20=0,cnt10=0,cnt5=0;
strcpy(str,"");
while(coins>0)
{
	if(coins>0&&coins<=95&&coins%5==0)
	{
		if(coins>=50)
		{
		c=50;
		cnt50++;
		p=cnt50*50;
		coins=coins-50;
		itoa(p,a,10) ;
		strcat(str,a);
		strcat(str,",");
		}
		else
		{
		strcat(str,"0,");
		}
		if(coins>=20)
		{
		c=20;
		cnt20++;
		p=cnt20*20;
		coins=coins-20;
		itoa(p,a,10);
		strcat(str,a);
		strcat(str,",");
		}
		else
		{
		strcat(str,"0,");
		}
		if(coins>=10)
		{
		c=10;
		cnt10++;
		p=cnt10*10;
		coins=coins-10;
		itoa(p,a,10);
		strcat(str,a);
		strcat(str,",");
		}
		else
		{
		strcat(str,"0,");
		}
		if(coins>=5)
		{
		c=5;
		cnt5++;
		p=cnt5*5;
		itoa(p,a,10);
		strcat(str,a);
		coins=coins-5;
	       //	strcat(str,",");
		}
		else
		{
		strcat(str,"0,");
		}
	  //printf("\nstr=%s",str);
	}
}
return str;
}
void main()
{
int i,c;
char str[80],name[10],sn[20];
int coins;
FILE *p;
char d[80];
p=fopen("coins.txt","r");
if(p==NULL)
{
printf("file doesn't exist\n");
}
clrscr();
printf("press 1 to enter name\npress 2 to exit");
scanf("%d",&i);
switch(i)
{
case 1:printf("enter name");
       scanf("%s",&sn);
       break;
case 2:break;
default:printf("enter valid number");
	break;
}

while(fscanf(p,"\n%s %d",&name,&coins)!=EOF)
{
if(strcmp(sn,name)==0)
{
printf("\ncustomer:\n%s %d cents",name,coins);
printf("\nchange =%s",str);
break;
}
else
{
printf("not found");
break;
}
}
strcpy(str,change(coins));
fclose(p);
getch();
}