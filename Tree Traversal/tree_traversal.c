#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void tree_initialize(Tree *tree);
void tree_insert(Tree *tree, int data);

void inorder(Tree *tree);
void preorder(Tree *tree);
void postorder(Tree *tree);
void tree_destroy(Tree *tree);

int main()
{
    int choice, loop = 1;
    Tree my_tree;
    tree_initialize(&my_tree);
    while (loop)
    {
        scanf("%d", &choice);
        switch (choice)
        {
            int number_of_elements, element, index;
            int data;
        case 1:
            /* Insert elements */
            scanf("%d", &element);
            tree_insert(&my_tree, element);
            break;
        case 2:
            /* Print elements in the inorder fashion */
            preorder(&my_tree);
            break;
        case 3:
            /* Print elements in the preorder fashion */
            inorder(&my_tree);
            break;
        case 4:
            /* Print elements in the postorder fashion */
            postorder(&my_tree);
            break;
        default:
            tree_destroy(&my_tree);
            loop = 0;
            break;
        }
    }
    return 0;
}
void tree_initialize(Tree *tree)
{
    tree->root==NULL;
}

Node* create_Node(int data){
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->left = new->right = NULL;

    return new;
}

Node* rec_Insert_Node(Node *root, int data){
    Node *new = create_Node(data);

    if (root == NULL){
        root = new;
    }
    else if (root->data > new->data){
        root->left = rec_Insert_Node(root->left, data);
    }
    else if (root->data < new->data){
        root->right = rec_Insert_Node(root->right, data);
    }
    return root;
}

void tree_insert(Tree *tree, int data){
    tree->root=rec_Insert_Node(tree->root, data);
}

void tree_inorder(Node *r)
{
    if(r!=NULL){
        tree_inorder(r->left);
        printf("%d ",r->data);
        tree_inorder(r->right);
    }
}

void tree_preorder(Node *r)
{
    if (r != NULL){
        printf("%d ", r->data);
        tree_preorder(r->left);
        tree_preorder(r->right);
    }
}

void tree_postorder(Node *r)
{
    if (r != NULL){
        tree_postorder(r->left);
        tree_postorder(r->right);
        printf("%d ", r->data);
    }
}

void postorder(Tree *t)
{
    tree_postorder(t->root);
    printf("\n");
}

void preorder(Tree *t)
{
    tree_preorder(t->root);
    printf("\n");
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r)
{
    r=NULL;
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}