#include<stdio.h>
#include<string.h>
struct process
{
 char name[100];
int at,bt,tt,wt,pr,status;
}p[100],t;

struct done
{
 char name[100];
 int st,ct;
}d[100];

void main()
{
  int n,i,j,idle,k,x,num,flag,found;
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
   printf("enter priority ");
   scanf("%d",&p[i].pr);
   p[i].status=0;
  }
  for(i=0,x=0,num=0;x<n;)
  {
    	flag=0;
	found=0;
	for(j=0;j<n;j++)
	{
		if(p[j].status==0 && p[j].at<=i && found==0)
		{
			k=j;
			flag++;
			found++;
		}
		else if(p[j].status==0 && p[j].at<=i && found>0)
		{
			if(p[j].pr<p[k].pr)
			{
				k=j;
				
			}
		}
	}
        if(flag==0 && idle==0)
	{
		strcpy(d[num].name,"idle");
			d[num].st=i;
			i++;
			idle=1;
	}
	else if(flag>0)
	{
			 if(idle==1)
			 {
				d[num].ct=i;
				num++;
			 }
					
				
        			strcpy(d[num].name,p[x].name);
				d[num].st=i;
				d[num].ct=i+p[x].bt;
				p[x].tt=d[num].ct-p[x].at;
				p[x].wt=p[x].tt- p[x].bt;
				i=d[num].ct;
				p[x].status=1;
				x++;
				num++;
				idle=0;
   			 
		 	
		
		 
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
  printf("Name\t\tAT\t\tBT\t\tTAT\t\tWT\t\tP\n");
  for(i=0;i<n;i++)
  {
	puts(p[i].name);
	__fpurge(stdin);
	printf("\t\t");
	printf("%d",p[i].at);
	printf("\t\t");
	printf("%d",p[i].bt);
	printf("\t\t");
	printf("%d",p[i].tt);
	printf("\t\t");
	printf("%d",p[i].wt);
	printf("\t\t");
	printf("%d",p[i].pr);
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
