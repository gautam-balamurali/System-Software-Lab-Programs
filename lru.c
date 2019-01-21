#include<stdio.h>

int findLRU(int time[], int n){
	int i, min = time[0], pos = 0;
	for(i = 1; i < n; i++){
		if(time[i] < min){
			min = time[i];
			pos = i;
		}
	}
	return pos;
}

int main(){
	int nof, nop, f[10], p[30], c = 0, time[10], flag1, flag2, i, j, pos, faults = 0;
	printf("Enter no. of frames\n");
	scanf("%d",&nof);
	printf("Enter no. of pages\n");
	scanf("%d",&nop);
	printf("Enter reference string\n");
	for(i = 0; i < nop; ++i)
		scanf("%d",&p[i]);
	for(i = 0; i < nof; ++i)
		f[i] = -1;
	for(i = 0; i < nop; ++i){
		flag1 = flag2 = 0;
		for(j = 0; j < nof; ++j){
			if(f[j] == p[i]){
				c++;
				time[j] = c;
				flag1 = flag2 = 1;
				break;
			}
		}
		if(flag1 == 0){
			for(j = 0; j < nof; ++j){
				if(f[j] == -1){
					c++;
					faults++;
					f[j] = p[i];
					time[j] = c;
					flag2 = 1;
					break;
				}
			}
		}
		if(flag2 == 0){
			pos = findLRU(time, nof);
			c++;
			faults++;
			f[pos] = p[i];
			time[pos] = c;
		}
		printf("\n");
		for(j = 0; j < nof; ++j)
			printf("%d\t",f[j]);
		
	}
	
	printf("\n\nTotal page faults = %d",faults);
	printf("\n");
	return 0;
}
