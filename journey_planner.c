// C program to develop a journey planner
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct tree{
	char name[20];
	struct tree *parent, *child[10];
	int num, dist;
}tree;

typedef struct edge{
	tree *from, *to;
	int weight;
}edge;

tree *create_n(char *name){
	tree *node = (tree*)malloc(sizeof(tree));
	strcpy(node->name, name);
	node->parent = NULL;
	node->num = 0;
	node->dist = -1;
	return node;
}

edge *create_e(tree *from, tree *to, int weight){
	edge *e = (edge*)malloc(sizeof(edge));
	e->from = from;
	e->to = to;
	e->weight = weight;
	return e;
}

void add(tree *parent, tree *child){
	parent->child[parent->num] = child;
	parent->num++;
	child->parent = parent;
}

void bfs(tree *source, tree *dest){
	tree *queue[100];
	int front=0, rear =0;
	queue[rear++] = source;
	source->dist = 0;
	while(front<rear){
		tree *curr = queue[front++];
		if(curr == dest){
			printf("path found ");
			while(curr != NULL){
				printf("%s ", curr->name);
				curr = curr->parent;
			}
			printf("\n");
			return;
		}
		for (int i = 0; i < curr->num; i++)
		{
			tree *child = curr->child[i];
			if (child->dist == -1)
			{
				child->dist = curr->dist + 1;
				queue[rear++] = child;
			}
		}
	}
	printf("no path\n");
}

int main(){
	tree *nodeA = create_n("A");
	tree *nodeB = create_n("B");
	tree *nodeC = create_n("C");
	tree *nodeD = create_n("D");
	tree *nodeE = create_n("E");
	tree *nodeF = create_n("F");
    edge *ab = create_e(nodeA, nodeB, 5);
    edge *ac = create_e(nodeA, nodeC, 8);
    edge *bd = create_e(nodeB, nodeD, 10);
    edge *be = create_e(nodeB, nodeE, 13);
    edge *cf = create_e(nodeC, nodeF, 1);
    add(nodeA, nodeB);
    add(nodeA, nodeC);
    add(nodeB, nodeD);
    add(nodeB, nodeE);
    add(nodeC, nodeF);
    bfs(nodeA, nodeF);
    return 0;
}