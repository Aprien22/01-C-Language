#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int info;
} NodeEntry;

typedef NodeEntry* node;

int main(){
	node P = (node) malloc(sizeof(NodeEntry)); 
	P->info = 3; 
	node Q = (node) malloc(sizeof(NodeEntry)); 
	Q->info = 2; 

	P->info = Q->info; 
	Q->info = 0; 
	printf("%d %d", P->info, Q->info);

    
     free(P);
    free(Q);
    return 0;
}