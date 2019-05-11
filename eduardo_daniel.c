#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ord 5
#define t 3

struct b_tree {
	int nodes_num;
	int keys[ord-1];
	int leaf;
	struct b_tree* nodes[ord];
	struct b_tree* root;
	
};

struct b_tree* create();
void search();
void insert_non_full(struct b_tree* tree, int node_key);
void insert(struct b_tree* tree, int node_key);
void split(struct b_tree* tree, int index);

int main(){

	struct b_tree* tree = (struct b_tree*)malloc(sizeof(struct b_tree));
	tree = create();
	int input;
	scanf("%d", &input);
	insert(tree, input);
	while (input != 0){
		scanf("%d",&input);
		insert(tree, input);
		}
}


struct b_tree* create(){
	struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
	current -> leaf = 1;
	current-> nodes_num = 0;
	return current;
}

void split(struct b_tree* tree, int index){

	struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
	struct b_tree* node = (struct b_tree*)malloc(sizeof(struct b_tree));
	
	node = tree -> nodes[index];
	current -> leaf = node -> leaf;
	current -> nodes_num = t-1;
	for (int i = 1; i < t-1; i++){
		 current -> nodes[i] = node -> nodes[t+i];
		 }
	if (!(node -> leaf)){
		for(int i = 01; i<t-1; i++){
			current -> keys[i] = node -> keys[t+i];
			}
		}
	node -> nodes_num = t-1;
	
	for (int i = tree -> nodes_num; i==index;i--){
		tree -> nodes[i+1] = tree -> nodes[i];
		}
		
	tree -> keys[index] = node -> keys[t];
	tree -> nodes_num = tree -> nodes_num +1;
	
	
		
}
void insert(struct b_tree* tree, int node_key){

	struct b_tree* rt;
	if (rt-> nodes_num == 2*(t)-1){
		struct b_tree* current = (struct b_tree*)malloc(sizeof(struct b_tree));
		printf("split");
		return;
		tree -> root = current;
		current -> leaf = false;
		current -> nodes_num = 0;
		current -> nodes[0] = rt;
		split(current, 1);
		insert_non_full(current, node_key);
	} else{
		insert_non_full(tree, node_key);
		}
}

void insert_non_full(struct b_tree* tree, int node_key){
	
	printf("add key = %d non full\n", node_key);
	int index = tree -> nodes_num;
	if (tree -> leaf == 1){
		while (index >=1 && node_key < (tree ->keys[index])){
			tree -> nodes[index+1] = tree -> nodes[index];
			index = index-1;
		}
		tree -> keys[index] = node_key;		
		tree -> nodes_num = tree -> nodes_num +1;
	} 
	if(tree-> leaf == 0) {
		while (index>=1 && node_key < (tree -> keys[index]))
			index = index-1;
		index = index+1;
		if (tree -> nodes[index] -> nodes_num == 2*(t)-1){
			split(tree -> nodes[index], index);
			if (node_key > tree -> keys[index])
				index = index +1;
		}
		insert_non_full(tree -> nodes[index], node_key); 	
	}
		
}




















