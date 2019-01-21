#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct pro
{
	char pname;
	int max[10];
	int alloc[10];
	int need[10];
	int finish;
};

int r,ch,avail[10],work[10];

int checka(struct pro a)
{
	int j,count=0;
	for(j=0;j<r;j++)
	{
		if(a.need[j]<=work[j])
		{	count++;
		}
	}
	if(count==r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

	
			
		
void main()
{
	struct pro p[10];
	char req;
	int rer[10];
	char done[10];
	int i,in,j,n,k,count=0,flag=0,w=0,sl=0;
	printf("\nEnter the number of processes?\n");
	scanf("%d",&n);
	printf("\nEnter the number of resources?\n");
	scanf("%d",&r);
	for(i=0;i<n;i++)
	{
		printf("\n Enter the Process name?\n");
setbuf(stdin,NULL);

		scanf("%c",&p[i].pname);
		for(j=0;j<r;j++)
		{
			printf("\nEnter the Max available for resource %d \n",j+1);
			scanf("%d",&p[i].max[j]);
		}
		printf("\n");
		for(j=0;j<r;j++)
		{
			printf("\nEnter the Allocation for resource %d \n",j+1);
			scanf("%d",&p[i].alloc[j]);
		}
		printf("\n");
		p[i].finish=0;
		for(j=0;j<r;j++)
		{
			p[i].need[j]=p[i].max[j]-p[i].alloc[j];
		}
	}
	for(j=0;j<r;j++)
	{
		printf("\n Enter the availability of resource %d \n",j+1);
		scanf("%d",&avail[j]);
	}
	printf("\n");

for(i=0;i<n;i++)
{
	printf("\n%c\n",p[i].pname);
	printf("\nMax\n");
	for(j=0;j<r;j++)
	{
		printf("%d ",p[i].max[j]);	
	}
	printf("\nAllocation\n");
	for(j=0;j<r;j++)
	{
		printf("%d ",p[i].alloc[j]);	
	}
	printf("\nNeed\n");
	for(j=0;j<r;j++)
	{
		printf("%d ",p[i].need[j]);	
	}

}


	
	
	printf("\n Enter the name of process for request?\n");
	setbuf(stdin,NULL);
	scanf("%c",&req);
	for(i=0;i<n;i++)
	{
		if(req==p[i].pname)
		{
			in=i;
		}
	}


		
	for(j=0;j<r;j++)
	{
		printf("\n Enter request for resource %d\n",j+1);
		scanf("%d",&rer[j]);
	}
	int c=0,b=0;
	for(j=0;j<r;j++)
	{
		if(rer[j]<=p[in].need[j])
		{	c++;
		}
	}
	for(j=0;j<r;j++)
	{
		if(rer[j]<=avail[j])
		{	b++;
		}
	}
	if(c!=r||b!=r)
	{
		printf("\nRequest cannot be granted!\n");
	}
	else
	{
		for(j=0;j<r;j++)
		{
			avail[j]=avail[j]-rer[j];
			p[in].alloc[j]=p[in].alloc[j]+rer[j];
			p[in].need[j]=p[in].need[j]-rer[j];
		}
		
		for(k=0;k<r;k++)
		{
			work[k]=avail[k];
		}
	
			

			while(count<n)
		{
			if(w==n)
			{
				w=0;
				
			}
			ch=checka(p[w]);
		
			if(p[w].finish==0 && ch==1)
			{
				for(j=0;j<r;j++)
				{
					work[j]=work[j]+p[w].alloc[j];
				}
				p[w].finish=1;
			 done[count]=p[w].pname;
				count++;
				sl=1;
				
			}
			
			w++;
			if(w==n && sl==0)
			{
				break;
				flag=1;
			}
			
		}	
		if(flag==1)
		{
			printf("\nUnsafe state\n");
		}
		else
		{
			printf("\nSafe state\n");
	
			for(i=0;i<n;i++)
			{
				printf("\t%c",done[i]);
			}
			printf("\n");
		}
	}
}

		
	
	
			
		
	
