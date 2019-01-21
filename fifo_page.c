#include<stdio.h>
#include<string.h>
int f,page_fault=0,pos=0,c=0;
int m[50];

void insert(int page){
	int flag = 0;
	for(int i = 0; i < f; i++){
		if(m[i] == page)
			flag = 1;
		//printf("%d",&m[i]);
	}
	printf("\n");
	if(flag == 0){
		page_fault++;
		pos = (pos+1)%f;
		m[pos] = page;
		//c = c+1;
	}
}

void main(){
	int n;
	printf("Enter no. of pages\n");
	scanf("%d",&n);
	int page[n];
	printf("Enter frame size\n");
	scanf("%d",&f);
	printf("Enter the reference string\n");
	for(int i = 0; i < n; i++)
		scanf("%d",&page[i]);
	printf("Reference string is\n");
	for(int i = 0; i < n; i++)
		printf("%d",page[i]);
	printf("\n");
	for(int i = 0; i < n; i++)
		insert(page[i]);
	printf("After FIFO page replacement:\n");
	for(int i = 0; i < f; i++){
		printf("%d",m[i]);
		
	}
	printf("\n");
	printf("Page fault is %d ",page_fault);
	printf("\n");
}


	
