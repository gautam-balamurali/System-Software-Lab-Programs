#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct process{
	char pname[10];
	int at,bt,wt,tt,ct,status;
}p[40],temp;

struct done{
	int st,ct;
	char dname[10];
}d[40];

void main(){
	int n,k,x,idle=0,i,flag,found,num;
	float sumtt=0.0f,sumwt=0.0f;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
	for(i = 0; i < n; i++){
		printf("Enter the name of the process\n");
		__fpurge(stdin);
		scanf("%s",&p[i].pname);
		printf("Enter the arrival time of the process\n");
		scanf("%d",&p[i].at);
		printf("Enter the burst time of the process\n");
		scanf("%d",&p[i].bt);
		p[i].status = 0;
	}

	/*for(i = 0; i < n-1; i++){
		for(int j = 0; j < n; j++){
			if(p[j].at > p[j+1].at){
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	} */
	
	for(i = 0,x = 0,num=0; x < n;){
		flag = 0; found = 0;
		for(int j = 0; j < n; j++){
			if((p[j].status == 0) && (p[j].at <= i) && (found == 0)){
				k=j;
				flag ++;
				found ++;
			}
			else if((p[j].status == 0) && (p[j].at <= i) && (found > 0))
				if(p[j].bt < p[k].bt)
					k = j;
		}
		
		if(flag == 0 && idle ==0){
			strcpy(d[num].dname,"idle");
			d[num].st = i;
			i++;
			idle = 1;
		}
		
		else if(flag > 0){
			if(idle == 1){
				d[num].ct = i;
				num ++;
			}
			
			strcpy(d[num].dname,p[k].pname);
			d[num].st = i;
			d[num].ct = i + p[k].bt;
			p[k].tt = d[num].ct - p[k].at;
			p[k].wt = p[k].tt - p[k].bt;
			i = d[num].ct;
			p[k].status = 1;
			x++;
			num++;
			idle = 0;
		}

		else{
			i++;	
		}
	}
	printf("TAT and WT is as follows\n");
	printf("Name\t\tAT\t\tBT\t\tTAT\t\tWT\n");
	for(i = 0; i < n; i++){
		puts(p[i].pname);
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
	for(i = 0; i < n; i++)
	printf("_____________");

	printf("\n");
	for(i = 0; i < num - 1; i++)
	printf("%s\t|",d[i].dname);
	printf("%s\t|",d[i].dname);
	printf("\n");
	for(i = 0; i < n; i++)
	printf("_____________");
	printf("\n");
	for(i = 0; i < num; i++)
	printf("%d\t",d[i].st);
	printf("%d\t",d[num - 1].ct);
	printf("\n");
	
}
			
			
