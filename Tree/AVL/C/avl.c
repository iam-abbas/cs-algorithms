#include <stdio.h>
#include <stdlib.h>


struct node{

   int height;
   int info;
   struct node* left;
   struct node* right;

};

typedef struct node root;

void creation(root**,int);
void left_rotation(root**);
void right_rotation(root**);
void checker(root**,int);
void inorder_traverse(root*);
void preorder_traerse(root*);
void postorder_traverse(root*);
int height(root*);
int main(){

root* Tree=NULL;

creation(&Tree,11);
creation(&Tree,13);
creation(&Tree,12);
inorder_traverse(Tree);

return 0;	
}

void creation(root** ROOT,int info){

if (*ROOT==NULL){
*ROOT=(root*)malloc(sizeof(root));
(*ROOT)->left=NULL;
(*ROOT)->right=NULL;
(*ROOT)->height=0;
if(*ROOT==NULL)
{printf("No memory available\n");
exit(-1);}  
else{
(*ROOT)->info=info;
   return;
}
}
else{
//printf("%d\n",info);
if((*ROOT)->info <= info) 
	{  
		creation(&((*ROOT)->right),info);

	}
else{
		
creation(&((*ROOT)->left),info);
}
}
//printf("%d",info);
checker(ROOT,info);

}

void checker(root** ROOT,int info){
     
     int a,b;
    (*ROOT)->height=1+(a=height((*ROOT)->right))>(b=height((*ROOT)->left))?a:b;
     int diff = b-a;
    if (diff>1 || diff<-1){
    	
    		if (info >= (*ROOT)->info){
    			if (info < (*ROOT)->right->info){
    				right_rotation(&((*ROOT)->right));
    			   }
    		     }


    		else{
    			if (info >= (*ROOT)->left->info){
    				left_rotation(&((*ROOT)->left));
    			}
    		}
    		if (diff>0){
    		right_rotation(ROOT);
    	}
    	else{
    		left_rotation(ROOT);
    	}
    }
    return ;

}
void right_rotation(root** ROOT){
    root* temp= (*ROOT)->left;
    *ROOT=temp;
    (*ROOT)->left=temp->right;	
   }

 void left_rotation(root** ROOT){
 	root* temp= (*ROOT)->right;
 	*ROOT=temp;
 	(*ROOT)->right=temp->left;
 }

 void inorder_traverse(root* ROOT){
//printf("Entering");
if (ROOT==NULL)
{printf("Empty tree\n");
exit(-1);}
ROOT->left!=NULL ? inorder_traverse(ROOT->left):printf("");
printf("%d ",ROOT->info);
ROOT->right!=NULL ? inorder_traverse(ROOT->right):printf("");
}


void postorder_traverse(root* ROOT){
	if (ROOT==NULL)
	{
		printf("Empty tree\n");
		exit(-1);
	}
      ROOT->left!=NULL ? postorder_traverse(ROOT->left):printf("");
      ROOT->right!=NULL? postorder_traverse(ROOT->right):printf("");
      printf("%d ",ROOT->info);


}

void preorder_traverse(root* ROOT){
	if (ROOT==NULL){
		printf("Empty tree");
		exit(-1);
	}
	printf("%d ",ROOT->info);
	ROOT->left!=NULL ? preorder_traverse(ROOT->left):printf("");
    ROOT->right!=NULL? preorder_traverse(ROOT->right):printf("");

}
int height(root* ROOT){

   if (ROOT==NULL){
   	  return 0;
   }
    return ROOT->height;
}
