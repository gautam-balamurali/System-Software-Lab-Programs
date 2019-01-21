#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[100];
	struct node *next;

};
struct node *top=NULL,*temp,*g;
int flag=0;
char s[100];

void create()
{
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
printf("Enter the name of file\n");
		scanf("%s",&p->data);

p->next=NULL;
if(top==NULL)
{
	top=p;
	printf("\nFile created\n");
}
else
{
g=top;
	while(g!=NULL)
		{
			
			if(strcmp(g->data,p->data)==0)
			{
				flag=1;
			}
			g=g->next;
		
		}
		if(flag==1)
		{
		printf("File Name exist !!\n");
		}
		else
		{
		p->next=top;
		top=p;
		printf("\nFile created\n");
		}
		
		
		
	}
}

void delete()
{

if(top==NULL)
{
	printf("No file in dir\n");
}
else
{
char name[100];
int fg=0;
printf("Enter the name of the file \n");
		scanf("%s",&name);
	struct node *a,*g,*i,*j,*temp1;
	g=top;
	while(g!=NULL)
		{
			
			if(strcmp(g->data,name)==0)
			{
				fg=1;
				a=g;
				break;
			}
			g=g->next;
		
		}
		if(fg==0)
		{
		printf("No such file !!\n");
		}
		else
		{
		printf("\nFile deleted\n");
	
		i=top;
		if(i==a)
		{
		temp1=top;
	top=temp1->next;
	}
	else
	{
		j=i->next;
		while(j!=a)
		{
		
		i=i->next;
		j=j->next;
		
		//i=i->next;
		}
		i->next=j->next;
		free(j);
		}
		}
		}
}

void display()
{
struct node *q;
q=top;
printf("------------------------------\n");
		while(q!=NULL)
		{
		
		printf("%s \n",q->data);
		
		q=q->next;
		
		}

//printf("\n--------------------------\n");




}

void main()
{
int n;
do
{
printf("\n1.Create \t2.Delete \t3.Display\t4.Exit\nChoice: ");
scanf("%d",&n);
switch(n)
{
	case 1:
		create();
		
		break;
	case 2:delete();
		break;
		
	case 3:display();
		break;
}
}while(n!=4);
}
