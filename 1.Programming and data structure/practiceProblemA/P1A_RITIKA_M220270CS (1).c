#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Course{
	char code[15];
	char name[15];
	int credits;
};

/*void ques1(){
	int arr[10][4];
	int n,t;
	int i = 0,j = 0,k = 0;
	printf("Enter how many courses you want to add: ");
	scanf("%d",&n);
	char str[15];
	for(i = 0;i<n;i++){
		scanf("%s",str);
		t = strlen(str);
		for(j =0;j<t;j++){
			if(str[j]>='0' && str[j]<='9'){
			arr[i][k] = str[j] - '0';
			k++;
			}
		}
		strcpy(str,"");	
		k = 0;
	}

	printf("Entered codes are: \n");
	for(i = 0;i<n;i++){
		for(j = 0;j<4;j++){
			printf("%d",arr[i][j]);
		}
		printf("\n");
	}
}*/

/*void ques2(){
	char arr[10][10];
	int n;
	printf("How many courses you  want to add, give their respective codes:\n");
	scanf("%d",&n);
	for(int i = 0;i<n;i++){
		scanf("%s",arr[i]);
	}
	printf("Entered course code are:\n");
	for(int j = 0;j<n;j++) printf("%s\n",arr[j]);
}*/

/*void createList(struct Course *arr,int n){
	printf("For each course give its code , name and credits respectively:\n");
	for(int i = 0;i<n;i++){
		scanf("%s%s%d",arr[i].code,arr[i].name,&arr[i].credits);
	}
}*/

/*int getCredit1(struct Course *s,char* cd , int n){
    int i, value;
    for(i = 0;i<n;i++){
    	value = strcmp(s[i].code,cd);
        if(value==0) return s[i].credits;
    }
    return 0;
}*/

/*int getCredit(struct Course **s,char cd , int n){
    int i, value;
    for(i = 0;i<n;i++){
        value = strcmp(s[i]->code,cd);
        if(value==0) return s[i]->credits;
    }
    return 0;
}*/

/*void createFile(struct Course* s,int n_c){
	FILE *fp;
	FILE *file;
	struct Course *cs[100];
	int i = 0;
	fp = fopen ("course.txt", "w");
	if(fp == NULL){
		printf("file not found\n");
		exit(1);
	}
	
	for(i = 0;i<n_c;i++){
		fprintf(fp,"%s ",s[i].code);
		fprintf(fp,"%s ",s[i].name);
		fprintf(fp,"%d \n",s[i].credits);
	}
	printf("Data stored successfully\n");
	fclose(fp);
	
}*/


int main(int argc, char *argv[]){
	//ques1();
	//ques2();
	//struct Course arr[10];
	//char cde[15];
	//int n;

	//printf("How many courses you want to add:\n");
	//scanf("%d",&n);
	//createList(arr,n);

	//printf("Enter the code for which you want the code:\n");
	//scanf("%s",cde);
	//int x  = getCredit1(arr,cde,n);
	//printf("Desired credit for code:%d\n",x);

	//createFile(arr,n);

	struct Course *arr[100];
    	int i = 0;
    	int j =0;
    	FILE *f = fopen(argv[1], "r");
    	if(f == NULL){
        	printf("file can't be opened \n");
    	}
    
    	else{
        	while (!feof(f)) {
            		arr[i] = (struct Course*)malloc(sizeof(struct Course));
            		fscanf(f,"%s %s %d",arr[i]->code,arr[i]->name,&arr[i]->credits);
            		i++;
        	}
    	}
	fclose(f);
    
    	printf("content of this file are \n");

    	for(j=0;j<i;j++)
    	{
        	printf("%s %s %d \n",arr[j]->code,arr[j]->name,arr[j]->credits);
    	}	


	return 0;
}





















