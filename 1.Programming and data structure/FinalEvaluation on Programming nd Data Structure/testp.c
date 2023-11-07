#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
	char student_id[30];
	char student_name[30];
	struct student *left;
	struct student *right;
	struct student *parent;
}BST;

void insertStudentDetails(BST **t,char *w,char *name){
	BST *ptr = (BST *)malloc(sizeof(BST));
	strcpy(ptr->student_id,w);
	strcpy(ptr->student_name,name);
	ptr->left = NULL;
	ptr->parent = NULL;
	ptr->right = NULL;
	
	BST *y = NULL;
	BST *x = NULL;
	x = *t;
	if(x == NULL){
		*t = ptr;
	}
	else{
		while(x!=NULL){
			y = x;
			if(strcmp(ptr->student_id,x->student_id)<0){
				x = x->left;
			}else x = x->right;
		}
		ptr->parent = y;
		if(strcmp(ptr->student_id,y->student_id)<0){
			y->left = ptr;
		} 
		else y->right = ptr;
	}
}

void printSortedList(BST *t){
	if(t!=NULL){
		printSortedList(t->left);
		printf("%s %s\n",t->student_id,t->student_name);
		printSortedList(t->right);
	}
}

int main(){
		int i = 0;
    	int n;
    	BST *List = NULL;
		FILE *f = fopen("input.txt", "r");
		if(f == NULL){
        	printf("file can't be opened \n");
    	}
    	else{
        	while (!feof(f)) {
        		fscanf(f,"%d\n",&n);
        		for(i =0;i<n;i++){
        		char sid[30],sname[30];
				fscanf(f,"%s %s\n",sid,sname);
				insertStudentDetails(&List,sid,sname);
			}
			char ch = 'y';
			while(ch!='e'){
				fscanf(f,"%c\n",&ch);
				if(ch=='p'){
					 printSortedList(List);
				}
			}
			
        	}
        	fclose(f);
	}
return 0;
}
