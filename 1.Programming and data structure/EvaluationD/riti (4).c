//code submitted by Ritika Jaiswal

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Course{
	char name[30];
	char code[30];
};

struct node{
	int x;
	struct node *next;
};

struct AdjList{
  struct node *head;
};

struct Graph {
    int V;
    struct AdjList* array;
};

typedef struct _SNode 
{
    int data;
    struct _SNode *next;
}SNode;

typedef struct _Stack
{
    SNode *head;
}Stack;

Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->head = NULL;
    return s;
}

int isStackEmpty(Stack *s)
{
    if(s->head == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *s, int data)
{
    SNode *node = (SNode *)malloc(sizeof(SNode));
    node->data = data;
    node->next = s->head;
    s->head = node;
}

int pop(Stack *s)
{
    if(isStackEmpty(s))
        return -1;
    SNode *node = s->head;
    int rval = node->data;
    s->head = node->next;
    free(node);
    return rval;       
}

struct node* newAdjListNode(int y){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->x = y;
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int n){
	int i;
	struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = n;
	
	graph->array = (struct AdjList*)malloc(n*sizeof(struct AdjList));
	
	for(i=0;i<n;i++){
		graph->array[i].head = NULL;
	}
	
	return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
	struct node* newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;
}

void printGraph(struct Graph* graph){
	int v;
	for(v=0;v<graph->V;v++){
		struct node* pr = graph->array[v].head;
		printf("Adjacency list of vertex %d\n head",v);
		while(pr){
			printf("->%d",pr->x);
			pr = pr->next;
		}
		printf("\n");
	}
}

int courseindex(struct Course *cs,char *ch,int n){
	int i;
	for(i = 0;i<n;i++){
		if(strcmp(cs[i].code,ch)==0) return i;
	}
	return -1;
}

void dfs(int u,int visited[],Stack *s,struct Graph* graph){
	visited[u] = 1;
	
	struct node* pr = graph->array[u].head;
	while(pr){
		int v = pr->x;
		if(!visited[v]) dfs(v,visited,s,graph);
		pr = pr->next;
	}
	
	push(s,u);
}

int* topology_sort(int n,struct Graph* graph){
	Stack *s = initStack();
	int vis[n];
	
	int i;
	
	for(i =0;i<n;i++){
		vis[i] = 0;
	}
	
	for(i = 0;i<n;i++){
		if(!vis[i]) dfs(i,vis,s,graph);
	}
	
	int * Arr = (int *)malloc(sizeof(int)*n);
    for(i = 0; !isStackEmpty(s); i++)
	    Arr[i] = pop(s);
	    
	return Arr;
}

void getMaxPreRequisitesCourse(struct Graph *graph,int n,struct Course *cs){
	int maxpre[n];
	int maxi = 0;
	int i,v,y;
	for(y=0;y<graph->V;y++){
		int count = 0;
	for(v=0;v<graph->V;v++){
		
		struct node* pr = graph->array[v].head;
		while(pr){
			if(pr->x == y){
				count++;
				break;	
			}
			pr = pr->next;
		}
		
	}
		maxpre[y] = count;
		if(maxi < maxpre[y])
		{
		 maxi = maxpre[y];
		 }
	}
	for(i=0;i<graph->V;i++){
		if(maxpre[i] == maxi)
			printf("%s ",cs[i].code);
	}
	printf("\n");
}

int main(){
    	int i = 0;
    	int n,m;
    	struct Course arr[100];
	FILE *f = fopen("input.txt", "r");
	if(f == NULL){
        	printf("file can't be opened \n");
    	}
    
    	else{
        	while (!feof(f)) {
        		fscanf(f,"%d\n",&n);
        		fscanf(f,"%d\n",&m);
        		for(i =0;i<n;i++){
				fscanf(f,"%s %s\n",arr[i].code,arr[i].name);
			}
            		struct Graph* graph = createGraph(n);
            		
            		for(i=0;i<m;i++){
				char str1[30];
				char str2[30];
				fscanf(f,"%s %s\n",str1,str2);
				int x = courseindex(arr,str1,n);
				int y = courseindex(arr,str2,n);
				if(x == -1 || y == -1) printf("course code invalid\n");
				else addEdge(graph,x,y);
			}
			
			/*int *Arr = topology_sort(n,graph);*/
			/*printGraph(graph);*/
			char ch = 'y';
			while(ch!='e'){
				fscanf(f,"%c\n",&ch);
				if(ch=='p'){
					 getMaxPreRequisitesCourse(graph,n,arr);
				}
			}
			
        	}
        	fclose(f);
        	
    	}
	
	
    
	
	return 0;
}
