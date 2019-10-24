include <stdio.h>
#include <stdlib.h>

struct node {
   int data;

   struct node *lChild;
   struct node *rChild;
};

struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->lChild = NULL;
   tempNode->rChild = NULL;

   
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) {
         parent = current;
         if(data < parent->data) {
            current = current->lChild;

            if(current == NULL) {
               parent->lChild = tempNode;
               return;
            }
         }
         else {
            current = current->rChild;


            if(current == NULL) {
               parent->rChild = tempNode;
               return;
            }
         }
      }
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data);


      if(current->data > data) {
         current = current->lChild;
      }

      else {
         current = current->rChild;
      }


      if(current == NULL) {
         return NULL;
      }
   }

   return current;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->lChild);
      pre_order_traversal(root->rChild);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->lChild);
      printf("%d ",root->data);
      inorder_traversal(root->rChild);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->lChild);
      post_order_traversal(root->rChild);
      printf("%d ", root->data);
   }
}

int main() {
   int i;
   int array[7] = { 29, 14, 32, 8, 19, 30, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);

   return 0;
}
