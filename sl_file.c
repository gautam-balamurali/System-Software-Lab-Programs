#include <stdio.h>
#include <string.h>

struct file{
	char name[10];
}F_list[20],temp;

int F_index=0;

int search_file(char* s){
	for(int i=0; i<F_index; i++){
		if(strcmp(F_list[i].name,s)==0){
			return i;
		}
	}
	return -1;
}

void search_file_name(){
	char s[10];
	printf("Enter name of file to search for :");
	scanf("%s", s);
	if(search_file(s)!=-1){
		printf("\nFILE FOUND (at location %d)!\n",search_file(s));
	}
	else{
		printf("\nFILE NOT FOUND!\n");
	}
}

void create_file(){
	char s[10];
	printf("Enter name of file to create :");
	scanf("%s", s);
	if(search_file(s)==-1){
		strcpy(F_list[F_index++].name, s);
	}
	else{
		printf("\nDUPLICATE FILE FOUND! FILE NOT CREATED\n");
	}
}

void swap(int i, int j){
	temp = F_list[i];
	F_list[i] = F_list[j];
	F_list[j] = temp;
}

void delete_file(int i){
	printf("\nDELETING FILE : %s\n", F_list[i].name );
	for(int j=i; j<F_index; j++){
		swap(j,j+1);
	}
	F_index--;
}

void delete_file_name(){
	char s[10];
	printf("Enter name of file to delete :");
	scanf("%s", s);
	int i = search_file(s);
	if(i!=-1){
		delete_file(i);
	}
	else{
		printf("\nFILE NOT FOUND! FILE NOT DELETED\n");
	}
}

void print_files(){
	printf("FILES IN DIRECTORY :\n");
	for(int i=0; i<F_index; i++){
		printf("%d) %s\n",i+1,F_list[i].name);
	}
}

void main(){
	int ch;
	while(ch!=5){
		printf("Enter choice :\n1)Print Files\n2)Search Files\n3)Insert File\n4)Delete file\n5)Quit\n>>");
		scanf("%d",&ch);
		printf("\n-----------------------\n\n");
		if(ch==1){ print_files(); }
		else if(ch==2){ search_file_name(); }
		else if(ch==3){	create_file(); }
		else if(ch==4){	delete_file_name(); }
		printf("\n-----------------------\n");
	}
}
