#include<stdio.h>
int main(){
	int q[20], n, head, i, j, k, seek = 0, max, diff, temp, q1[20], q2[20], temp1 = 0, temp2 = 0;
	float avg;
	printf("Enter max range of disk\n");
	scanf("%d",&max);
	printf("Enter head position\n");
	scanf("%d",&head);
	printf("Enter size of queue\n");
	scanf("%d",&n);
	printf("Enter disk positions to be read\n");
	for(i = 1; i <= n; i++){
		scanf("%d",&temp);
		if(temp >= head){
			q1[temp1] = temp;
			temp1++;
		}
		else{
			q2[temp2] = temp;
			temp2++;
		}
	}
	for(i = 0; i < temp1-1; i++){
		for(j = i+1; j < temp1; j++){
			if(q1[i] > q1[j]){
				temp = q1[i];
				q1[i] = q1[j];
				q1[j] = temp;
			}
		}
	}
	for(i = 0; i < temp2-1; i++){
		for(j = i+1; j < temp2; j++){
			if(q2[i] > q2[j]){
				temp = q2[i];
				q2[i] = q2[j];
				q2[j] = temp;
			}
		}
	}
	for(i = 1, j = 0; j < temp1; i++, j++)
		q[i] = q1[j];
	q[i] = max;
	q[i+1] = 0;
	for(i = temp1+3, j = 0; j < temp2; i++, j++)
		q[i] = q2[j];
	q[0] = head;
	
	for(j = 0; j <= n+1; j++){
		diff = abs(q[j+1] - q[j]);
		seek += diff;
		printf("Disk head moves from %d to %d with seek %d",q[j], q[j+1], diff);
		printf("\n");
	}
	seek = seek - max;
	printf("Total head count = %d",seek);
	printf("\n");
	return 0;
}
