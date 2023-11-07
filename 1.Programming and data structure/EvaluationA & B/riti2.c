#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct disease{
	char ds[30];
	char vaccine_adults[30];
	char vaccine_child[30];
	struct disease *next;
};

struct disease *arr;

void insert(){
	struct disease *ptr = (struct disease*)malloc(sizeof(struct disease));
	char d[20],va[20],vc[20];
	scanf("%s%s%s",d,va,vc);
	strcpy(ptr->ds,d);
	strcpy(ptr->vaccine_adults,va);
	strcpy(ptr->vaccine_child,vc);
	
	struct disease *curr;
	if(arr == NULL || strcasecmp(arr->ds ,ptr->ds)>=0){
		ptr->next = arr;
		arr = ptr;
	}
	else{
		curr = arr;
		while(curr->next!=NULL && strcasecmp(curr->next->ds , ptr->ds)<=0){
			curr = curr->next;
		}
		ptr->next = curr->next;
		curr->next = ptr;
	}
	
}

void delete(){
	char nm[30];
	scanf("%s",nm);
	struct disease *temp,*prev;
	temp = arr;
	if(temp == NULL) return;
	else{
		if(temp != NULL && !strcmp(temp->ds,nm)){
			arr = temp->next;
			free(temp);
		}
		else{
			while(temp!=NULL && strcmp(temp->ds, nm)){
				prev = temp;
				temp = temp->next;
			}
			if(temp == NULL) return;
			prev->next = temp->next;
			free(temp);
		}	
	}
}

void display(){
	struct disease *temp = arr;
	while(temp!= NULL){
		printf("%s ",temp->ds);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
char ch = 'y';

while(ch!='s'){
	scanf("%c",&ch);
	if(ch == 'i'){
		insert();
	}
	if(ch == 'd'){
		delete();
	}
	if(ch == 'p'){
		display();
	}

}


return 0;
}
