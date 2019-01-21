#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
void main()
{
	char opc[20],opcode[20],opcnum[20],op[20],lbl[20],symbol[20],addr[20],ex[20],len[20],c;
	int locctr,sa,flag,flag2,i=2;
	FILE *finter,*foptab,*fsymtab,*fobject,*flen;
	finter = fopen("output.txt","r");
	foptab = fopen("op.txt","r");
	fsymtab = fopen("symtab.txt","r");
	fobject = fopen("object.txt","w");
	flen = fopen("len.txt","r");
	fscanf(finter,"%s %s %s",lbl,opc,op);
	if(strcmp(opc,"START")==0)
	{
		sa = atoi(op);
		fscanf(flen,"%s",len);
		fprintf(fobject,"H^%s^%d^%s\n",lbl,sa,len);
		fscanf(finter,"%s %s %s %s",addr,lbl,opc,op);
	}
	fprintf(fobject,"T^%d^%s^",sa,len);
	while(strcmp(opc,"END") != 0)
	{
		flag2 = 0;
		rewind(foptab);
		fscanf(foptab,"%s %s",opcode,opcnum);
		while(!feof(foptab))
		{
			if(strcmp(opc,opcode)==0)
			{
				flag2 = 1;
				break;
			}
			fscanf(foptab,"%s %s",opcode,opcnum);
		}
		if (flag2==1)
		{
			flag = 0;
			rewind(fsymtab);
			fscanf(fsymtab,"%s %s",symbol,addr);
			while(!feof(fsymtab))
			{
				if(strcmp(op,symbol)==0)
				{
					flag = 1;
					break;
				}
				fscanf(fsymtab,"%s %s",symbol,addr);
			}
			if (flag==1)
				fprintf(fobject,"%s%s^",opcnum,addr);
			else
				printf("Invalid symbol\n");
		}
		else if(strcmp(opc,"WORD")==0)
		{
			fprintf(fobject,"^00000%s",op);
		}
		else if(strcmp(opc,"BYTE")==0)
		{
			c=op[2];
			fprintf(fobject,"^000");
			while(c!='\'')
			{
				fprintf(fobject,"%c",c);
				i+=1;
				c=op[i];
			}
		}
		fscanf(finter,"%s %s %s %s",addr,lbl,opc,op);
	}
	fprintf(fobject,"\nE^00%d",sa);
	fclose(foptab);
	fclose(fsymtab);
}
