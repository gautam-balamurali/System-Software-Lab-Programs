#include<stdio.h>
#include<string.h>
struct process
{
 char name[100];
int at,bt,tt,wt,status;
}p[100],t;

struct done
{
 char name[100];
 int st,ct;
}d[100];

void main()
{
  int n,i,j,idle,k,num;
  float sumwt=0.0, sumtt=0.0,st,w;
  printf("enter number of processes ");
  scanf("%d",&n);
  for(i=0; i<n;i++)
  {
   printf("enter process name ");
   __fpurge(stdin);
   gets(p[i].name);
   printf("enter arrival time ");
   scanf("%d",&p[i].at);
   printf("enter burst time ");
   scanf("%d",&p[i].bt);
   p[i].status=0;
  }
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-i-1;j++)
   {
     if(p[j].at>p[j+1].at)
     {
       t=p[j];
       p[j]=p[j+1];
       p[j+1]=t;
     }
   }
  }
  
  idle=0;
  for(i=0,k=0,num=0;k<n;)
  {
   if(p[k].at<=i && p[k].status==0)
   {
	if(idle==1)
	{
		d[num].ct=i;
		num++;
	}
        strcpy(d[num].name,p[k].name);
	d[num].st=i;
	d[num].ct=i+p[k].bt;
	p[k].tt=d[num].ct-p[k].at;
	p[k].wt=p[k].tt- p[k].bt;
	i=d[num].ct;
	p[k].status=1;
	k++;
	num++;
	idle=0;
   }
   else if(idle==0)
	{
		
			strcpy(d[num].name,"idle");
			d[num].st=i;
			i++;
			idle=1;
		
	}
   else
	{
		i++;
	}
  }
  /*for(i=0;i<n;i++)
  {
	printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].at,p[i].bt,p[i].tt,p[i].wt);
  }*/

  printf("TAT and WT is as follows\n");
  printf("Name\t\tAT\t\tBT\t\tTAT\t\tWT\n");
  for(i=0;i<n;i++)
  {
	puts(p[i].name);
	__fpurge(stdin);
	printf("\t\t\t");
	printf("%d",p[i].at);
	printf("\t\t\t");
	printf("%d",p[i].bt);
	printf("\t\t\t");
	printf("%d",p[i].tt);
	printf("\t\t\t");
	printf("%d",p[i].wt);
	printf("\n");
  }
  for(i=0;i<n;i++)
  {
	printf("____________");
  }
  printf("\n");
  for(i=0;i<num-1;i++)
  {
	printf("%s\t|",d[i].name);
  }
  printf("%s\t|",d[i].name);
  printf("\n");
  for(i=0;i<num;i++)
  {
 	printf("____________");
  }
  printf("\n");
  for(i=0;i<num;i++)
  {
	printf("%d\t",d[i].st);
	
  }
	
	printf("%d\t",d[num-1].ct);
	printf("\n");
}
  


		
  

