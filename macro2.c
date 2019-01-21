//MACRO PASS2
#include<stdio.h>
#include<string.h>
void main()
{
char label[100],mne[100],argg[100],name[100];
int flag=0;
int i;
char opc[100],opr[100];
FILE *f1,*f2,*f3,*f4,*f5;
f1=fopen("input11.txt","r");
f2=fopen("deftab.txt","r");
f3=fopen("argtab.txt","w+");
f4=fopen("moutput2.txt","w+");
f5=fopen("nametab1.txt","r");

fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);

while(strcmp(mne,"MEND"))
{

fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);
}
fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);
fprintf(f4,"%s\t%s\t%s\n",label,mne,argg);
fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);


while(strcmp(mne,"END"))
{
	fscanf(f5,"%s",&name);
	//rewind(f5);
	while(!feof(f5))
	{
	//printf("HI");
	if(strcmp(mne,name))
	{
	flag=1;
	break;
	}
	fscanf(f5,"%s",&name);
	}
	//fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);}printf("fl=%d",flag);
	if(flag==1)
	{
		flag=0;
		printf("\ns=%s",argg);
		printf("\nop=%s",mne);
		//fprintf(f4,".\t%s\t%s",mne,argg);
		
		for(i=0;i<strlen(argg);i++)
		{
		if(argg[i]==',')
		{
		fprintf(f3,"\n");
		}
		else
		{
		fprintf(f3,"%c",argg[i]);
		}
		}
		fprintf(f3,"\n");
		
		rewind(f2);
	fscanf(f2,"%s\t%s",&opc,&opr);
//	printf("p=%s=%s",mne,opc);
	if(strcmp(opc,mne)==0)
	{
//printf("p=%s=%s",mne,opc);
	fprintf(f4,".\t%s\t",opc);
	rewind(f3);
	fscanf(f3,"%s",name);
	
	while(!feof(f3))
	{
	fprintf(f4,"%s,",name);
	fscanf(f3,"%s",name);
	
	}
	fscanf(f2,"%s\t%s",&opc,&opr);
	rewind(f3);
	while(strcmp(opc,"MEND"))
	{
	fscanf(f3,"%s",name);
	fprintf(f4,"\n%s\t%s\t%s",label,opc,name);
	fscanf(f2,"%s\t%s",&opc,&opr);
	}
	}
	}
	else
	{
	fprintf(f4,"\n%s\t%s\t%s",label,mne,argg);
	}
fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);
}
fprintf(f4,"\n%s\t%s\t%s",label,mne,argg);

fclose(f1);
fclose(f2);
fclose(f3);
fclose(f5);
fclose(f4);
}
	
		
		
		
		
		
		
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		

