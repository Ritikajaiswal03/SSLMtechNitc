#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct disease{
	int sn;
	char disease[30];
	char vaccine_adults[30];
	char vaccine_child[30];
};

void listVaccines(struct disease *A, char *v, int n){
	int i =0;
	int flag = 0;
	FILE *fp;
	fp = fopen("diseases.txt","w");
	for(i=0;i<n;i++){
		if(strcmp(A[i].vaccine_adults,v)==0 || strcmp(A[i].vaccine_child,v)==0){
			fprintf(fp,"%s\n",A[i].disease);
			flag = 1;
		} 
	}
	if(flag == 0) fprintf(fp,"NIL");
	fclose(fp);
}

int main(){
int n,i;
scanf("%d",&n);
char v[20];
struct disease arr[n];
for(i=0;i<n;i++){
	scanf("%d%s%s%s",&arr[i].sn,arr[i].disease,arr[i].vaccine_adults,arr[i].vaccine_child);
}
scanf("%s",v);
listVaccines(arr,v,n);
return 0;
}
