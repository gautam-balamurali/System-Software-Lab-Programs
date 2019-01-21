#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
	char label[10], opc[10], op[10], nm[10], v[10], a[10], oc[10];
	int locctr, sa, flg = 0, n, len;
	FILE *f1, *f2, *f3, *f4;
	f1 = fopen("input.txt", "r");
	f2 = fopen("op.txt", "r");
	f3 = fopen("output.txt", "w");
	f4 = fopen("symtab.txt", "r+");
	fscanf(f1,"%s %s %s",&label,&opc,&op);
	if(strcmp(opc, "START") == 0){
		fprintf(f3,"%s\t %s\t %s\n",label,opc,op);
		sa = atoi(op);
		locctr = atoi(op);
		fscanf(f1,"%s %s %s",&label,&opc,&op);
	}
	while(strcmp(opc, "END") != 0){
		flg = 0;
		fprintf(f3,"%d",locctr);
		if(strcmp(label,"**") != 0){
			rewind(f4);
			fscanf(f4,"%s %s",&nm,&v);
			while(!feof(f4)){
				if(strcmp(label, nm) == 0){
					printf("Duplicate Symbol\n");
					exit(0);
				}
				fscanf(f4,"%s %s",&nm,&v);
			}
			fprintf(f4,"%s %d\n",label, locctr);
		}
		rewind(f2);
		fscanf(f2, "%s %s",&oc,&a);
		while(!feof(f2)){
			if(strcmp(oc, opc) == 0)
				flg = 1;
			fscanf(f2,"%s %s",&oc,&a);
		}
		if(flg == 1)
			locctr = locctr + 3;
		else if(strcmp(opc,"WORD") == 0)
			locctr = locctr + 3;
		else if(strcmp(opc,"RESW") == 0){
			n = atoi(op);
			locctr = locctr + (3*n);
		}
		else if(strcmp(opc,"RESB") == 0){
			n = atoi(op);
			locctr = locctr + n;
		}
		else if(strcmp(opc,"BYTE") == 0){
			if(op[0] == 'X')
				locctr = locctr + 1;
			else if(op[0] == 'C')
				locctr = locctr + (strlen(op) - 3);
		}
		else{
			printf("Invalid Opcode \n");
			exit(0);
		}
		fprintf(f3,"%s\t %s\t %s\n",label,opc,op);
		fscanf(f1, "%s %s %s",&label,&opc,&op);
		}
		
	fprintf(f3,"%d\t %s\t %s\t %s\n",locctr,label,opc,op);
	len = locctr - sa;
	printf("Length %d\n",len);
	fclose(f1);
	fclose(f2);
	fclose(f3);
	fclose(f4);
}
