#include<stdio.h>
#include<string.h>
void main()
{
char label[100],mne[100],argg[100];
FILE *f1,*f2,*f3,*f4;
f1=fopen("input11.txt","r");
f2=fopen("deftab.txt","w+");
f3=fopen("nametab1.txt","w+");
fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);
while(strcmp(mne,"MEND"))
{
if(strcmp(mne,"MACRO")==0)
{
	fprintf(f2,"%s\t%s\n",label,argg);
	fprintf(f3,"%s",label);
}
else
{
	fprintf(f2,"%s\t%s\n",mne,argg);
}
fscanf(f1,"%s\t%s\t%s",&label,&mne,&argg);
}
fprintf(f2,"%s",mne);
fclose(f1);
fclose(f2);
fclose(f3);
}
