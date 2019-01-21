#include<stdio.h>
int main(){
	int i, j, sum = 0, n, d[20], disk, temp, max, dloc;
	printf("Enter no. of locations\n");
	scanf("%d",&n);
	printf("Enter head position\n");
	scanf("%d",&disk);
	printf("Enter elements of disk queue\n");
	for(i = 0; i < n; i++)
		scanf("%d",&d[i]);
	d[n] = disk;
	n = n+1;
	for(i = 0; i < n; i++){
		for(j = i; j < n; j++){
			if(d[i] > d[j]){
				temp = d[i];
				d[i] = d[j];
				d[j] = temp;
			}
		}
	}
	max = d[n-1];
	for(i = 0; i < n; i++){
		if(disk == d[i]){
			dloc = i;
			break;
		}
	}
	for(i = dloc; i >= 0; i--)
		printf("%d --> ",d[i]);
	printf("0 --> ");
	for(i = dloc +1; i < n; i++)
		printf("%d --> ",d[i]);
	sum = disk + max;
	printf("\n");
	printf("Movement of total cylinders = %d",sum);
	printf("\n");
	return 0;
}
