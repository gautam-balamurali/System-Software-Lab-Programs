#include<stdio.h>
#include<string.h>
void main(){
	int flag = 0,v,pf=0,j,np,nf,i,nof;
	int page[20],frm[20];
	printf("Enter no. of pages\n");
	scanf("%d",&np);
	printf("Enter the reference string\n");
	for(int i = 0; i < np; i++)
		scanf("%d",&page[i]);
	printf("Enter frame size\n");
	scanf("%d",&nf);
	for(int i = 0; i < nf; i++)
		frm[i]=-1;
	v=-1;
	for(int i = 0; i < np; i++){
		flag = 0;
	for(int j = 0; j < nf; j++)
	{
		if(frm[j] == page[i])
			flag = 1;
	}
	if(flag == 0)
	{
		pf++;
		v++;
		v = v%nf;
		frm[v] = page[i];
		for(int j = 0; j < nf; j++)
			printf("%d",frm[j]);
		printf("\n");
		
	}
	}
	printf("\n");
	printf("Page fault is %d ",pf);
	printf("\n");
}

	
