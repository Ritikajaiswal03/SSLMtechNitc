#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bst{
	struct bst *parent;
	char name[20];
	struct bst *left;
	struct bst *right;
};

struct Course{
	char code[10];
	char name[3];
	int credits;
	struct bst *regList;
};

struct Course arr[20];

void createList(struct Course *cs,int n){
	int i = 0;
	for(i = 0;i<n;i++){
		scanf("%s%s%d",cs[i].code,cs[i].name,&cs[i].credits);
		cs[i].regList = NULL;
	}
}

int coursevalid(struct Course *cs,char *cde,int n){
	int i = 0;
	for(i = 0;i<n;i++){
		if(strcmp(cs[i].code,cde)==0) return i;	
	}
	return -1;
}

struct bst* treeMinimum(struct bst *x){
	while(x->left!=NULL){
		x = x->left;
	}
	return x;
}

void insert(char *ch,struct bst **t){
	struct bst *ptr = (struct bst*)malloc(sizeof(struct bst));
	strcpy(ptr->name,ch);
	ptr->left = NULL;
	ptr->parent = NULL;
	ptr->right = NULL;
	
	struct bst *y = NULL;
	struct bst *x = NULL;
	x = *t;
	if(x == NULL){
		*t = ptr;
	}
	else{
		while(x!=NULL){
			y = x;
			if(strcmp(ptr->name,x->name)<0){
				x = x->left;
			}else x = x->right;
		}
		ptr->parent = y;
		if(strcmp(ptr->name,y->name)<0){
			y->left = ptr;
		} 
		else y->right = ptr;
	}
}

struct bst* deleted(struct bst *t,char *ch){
	if(t == NULL) return t;
	else if(strcmp(ch,t->name)<0) t->left = deleted(t->left,ch);
	else if(strcmp(ch,t->name)>0) t->right = deleted(t->right,ch);
	else{
		if(t->left == NULL && t->right == NULL){
			free(t);
			t = NULL;
		}
		else if(t->left == NULL){
			struct bst *temp = t;
			t = t->right;
			free(temp);
		}
		else if(t->right == NULL){
			struct bst *temp = t;
			t = t->left;
			free(temp);
		}
		else{
			struct bst *temp = treeMinimum(t->right);
			strcpy(t->name,temp->name);
			t->right = deleted(t->right,temp->name);
		}
	}
	return t;
}

int countnodes(struct bst *t){
	if(t==NULL) return 0;
	else{
		int x = countnodes(t->left);
		int y = countnodes(t->right);
		return x+y+1;
	}
}


void getMaxRegisteredCourse(int n){
	int count = 0;
	char xe[30];
	int cnt_node[n];
	int k = 0;
	for(int i=0;i<n;i++){
		int temp = countnodes(arr[i].regList);
		cnt_node[i] = temp;
		if(count<=temp){
			count = temp;
		}
	}
	for(int j=0;j<n;j++){
		if(cnt_node[j] == count){
			printf("%s ",arr[j].code);
		} 
	}

}

int main(){

	int n;
	scanf("%d",&n);
	createList(arr,n);
	
	char str[30];
	char ch = 'y';

	while(ch!='e'){
		scanf("%c",&ch);
		if(ch == 'i'){
			char nm[20];
			scanf("%s",nm);
			scanf("%s",str);
			int x = coursevalid(arr,str,n);
			if(x == -1) printf("Course code invalid\n");
			else{
				insert(nm,&(arr[x].regList));
			}
		}
		if(ch == 'd'){
			char nm[20];
			scanf("%s",nm);
			scanf("%s",str);
			int y = coursevalid(arr,str,n);
			if(y == -1) printf("Course code invalid\n");
			else{
				arr[y].regList = deleted(arr[y].regList,nm);
			}
		}
		if(ch == 'm'){
			getMaxRegisteredCourse(n);
		}

	}
	return 0;
}
