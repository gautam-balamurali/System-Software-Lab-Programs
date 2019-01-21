#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data[100];
	struct node *next;

};
struct node2
{
	char data2[100];
	struct node *next2;

};
struct node *top=NULL,*temp,*g;
struct node2 *top2=NULL,*g2;
char s[100];
//==========================================================
void create1()
{
int flag=0;
struct node *p;
p=(struct node *)malloc(sizeof(struct node));
printf("Enter the name of the file:\n");
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
		printf("File Name already exists !!\n");
		}
		else
		{
		p->next=top;
		top=p;
		printf("\nFile created\n");
		}
		
		
		
	}
}
//======================================================================
void delete1()
{

if(top==NULL)
{
	printf("No file in the directory\n");
}
else
{
char name[100];
int fg=0;
printf("Enter the name of the file to be deleted:\n");
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

//=======================================================================
void display1()
{
struct node *q;
q=top;
printf("=============================================\n");
		while(q!=NULL)
		{
		
		printf("%s \n",q->data);
		
		q=q->next;
		
		}




}
//========================================================================================

void create2()
{
struct node2 *p;
int flag=0;
p=(struct node2 *)malloc(sizeof(struct node2));
printf("Enter the name of the file:\n");
		scanf("%s",&p->data2);

p->next2=NULL;
if(top2==NULL)
{
	top2=p;
	printf("\nFile created\n");
}
else
{
g2=top2;
	while(g2!=NULL)
		{
			
			if(strcmp(g2->data2,p->data2)==0)
			{
				flag=1;
			}
			g2=g2->next2;
		
		}
		if(flag==1)
		{
		printf("File Name already exists !!\n");
		}
		else
		{
		p->next2=top2;
		top2=p;
		printf("\nFile created\n");
		}
		
		
		
	}
}

//================================================================================
void delete2()
{

if(top2==NULL)
{
	printf("No file in the directory\n");
}
else
{
char name[100];
int fg=0;
printf("Enter the name of the file to be deleted:\n");
		scanf("%s",&name);
	struct node2 *a,*g2,*i,*j,*temp1;
	g2=top2;
	while(g2!=NULL)
		{
			
			if(strcmp(g2->data2,name)==0)
			{
				fg=1;
				a=g2;
				break;
			}
			g2=g2->next2;
		
		}
		if(fg==0)
		{
		printf("No such file !!\n");
		}
		else
		{
		printf("\nFile deleted\n");
	
		i=top2;
		if(i==a)
		{
		temp1=top2;
	top2=temp1->next2;
	}
	else
	{
		j=i->next2;
		while(j!=a)
		{
		
		i=i->next2;
		j=j->next2;
		
		//i=i->next;
		}
		i->next2=j->next2;
		free(j);
		}
		}
		}
}

//==================================================


void display2()
{
struct node2 *q;
q=top2;
printf("=============================================\n");
		while(q!=NULL)
		{
		
		printf("%s \n",q->data2);
		
		q=q->next2;
		
		}




}


//======================================================================
void main()
{
int n;
do
{
printf("\n1.Create a file in directory 1\t2.Delete a file from directory 1\t3.Display files of directory 1\t4. Create a file in directory 2\t5. Delete a file from directory 2\t6. Display files of directory 2\t7. Exit\tChoice: ");
scanf("%d",&n);
switch(n)
{
	case 1:
		create1();
		
		break;
	case 2:delete1();
		break;
		
	case 3:display1();
		break;
	case 4:create2();
		break;
	case 5:delete2();
		break;
	case 6:display2();
		break;
}
}while(n!=7);
}
