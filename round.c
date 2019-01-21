#include<stdio.h>
#include<string.h>
int q[100];
int front=-1,rear=0;

struct process
	{
		char pname[20];
		int at,bt,wt,tt,status,left;
	}p[20];

struct done
	{
		char name[20];
		int st,ct;
	}d[20];

void enq(int j)
{
	q[rear]=j;
	rear++;
	if(front==-1)
	{
		front++;
	}
}

int deq()
{
	int item;
	item=q[front];
	front++;
	if(front==rear)
	{
		front=-1;
		rear=0;
	}
	return item;
}

void main()
{
	int i=0,j,k,x,num,status,idle=0,ls,t,n,l,m,h,g;
	float sumwt=0.0,sumtt=0.0;
	printf("\n Enter the number of processes: ");
	setbuf(stdin,NULL);
	scanf("%d",&n);
	printf("\n Enter the timeslice: ");
	scanf("%d",&t);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the name of process: ");
		scanf("%s",&p[i].pname);
		printf("\n Enter the arrival time: ");
		scanf("%d",&p[i].at);
		printf("\n Enter the burst time: ");
		scanf("%d",&p[i].bt);
		p[i].status=0;
		p[i].left=p[i].bt;
	}
	printf("pname\tat\tbt");
	for(i=0;i<n;i++)
	{
		printf("\n%s\t%d\t%d\n",p[i].pname,p[i].at,p[i].bt);
	}
		
	for(i=0,x=0,num=0;x<n;)
	{
		for(j=0;j<n;j++)
		{
			if((p[j].status==0) && (p[j].at<=i))
			{
				enq(j);
				p[j].status=1;
			}
		}
		if(idle==0 && front==-1)
		{
			strcpy(d[num].name,"idle");
			d[num].st=i;
			idle=1;
			i++;
		}
		else if(front!=-1)
		{
			if(idle==1)
			{
				d[num].ct=i;
				idle=0;
				num++;
			}
			k=deq();
			d[num].st=i;
			strcpy(d[num].name,p[k].pname);
		
			if(p[k].left<=t)
			{
				d[num].ct=i+p[k].left;
				i=d[num].ct;	
				p[k].tt=d[num].ct-p[k].at;
				p[k].wt=p[k].tt-p[k].bt;
				p[k].status=2;
				x++;
				num++;
			}
			else
			{
				d[num].ct=i+t;
				i=i+t;
				p[k].left=p[k].left-t;
				num++;
				for(j=0;j<n;j++)
				{
					if((p[j].status==0) && (p[j].at<=i))
					{
						enq(j);
						p[j].status=1;
					}
				}
				enq(k);
			}
		}		
		else
		{
			i++;
		}
	}
		
	
	for(l=0;l<n+6;l++)
	{
		printf("__________\t");
	}
	
	for(i=0;i<num;i++)
	{
		if(i==0)
		{
			printf("\n|%s\t|",d[i].name);
		}
		else
		{	
			printf("%s\t|",d[i].name);
		}
	
	}
	printf("\n");
	for(m=0;m<n+6;m++)
	{
		printf("__________\t");
	}
	printf("\n");
	for(h=0;h<num;h++)
	{
		printf("%d\t",d[h].st);
	}
	printf("%d\t",d[num-1].ct);
	printf("\n");
	for(g=0;g<num;g++)
	{
		sumtt=sumtt+p[g].tt;
		sumwt=sumwt+p[g].wt;	
	}
	printf("Average of tt:%f\n",sumtt/n);
	printf("Average of wt:%f\n",sumwt/n);	
	printf("\n");
}

