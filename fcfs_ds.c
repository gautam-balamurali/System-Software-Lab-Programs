#include<stdio.h>
void main(){
	int q[100], n, head, i, j, k, seek = 0, diff;
	float avg;
	printf("Enter the size of queue\n");
	scanf("%d",&n);
	printf("Enter the disks\n");
	for(i = 1; i <= n; i++)
		scanf("%d", &q[i]);
	printf("Enter the head position\n");
	scanf("%d",&head);
	q[0] = head;
	for(j = 0; j <= n-1; j++){
		diff = abs(q[j+1] - q[j]);
		seek += diff;
		printf("Move from %d to %d with seek %d",q[j], q[j+1], diff);
		printf("\n");
	}
	printf("\n");
	printf("Total head count %d",seek);
	printf("\n");
} 
