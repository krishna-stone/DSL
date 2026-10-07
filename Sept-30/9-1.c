#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node* left;
    int data;
    struct Node* right;
}*root;

struct Node* createNode(int val){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->data = val;
    newNode->right = NULL;
    return newNode;
}

void insert(struct Node** root, int val){
    if(*root == NULL){
        struct Node* newNode = createNode(val);
        *root = newNode;
    }
    if(val == (*root)->data){
        return;
    }
    
    if(val > (*root)->data){
        insert(&(*root)->right,val);
    }

    if(val < (*root)->data){
        insert(&(*root)->right,val);
    }
}

void preorder(struct Node* r){
    if(r){
        printf("%d ",r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct Node* r){
    if(r){
        postorder(r->left);
        postorder(r->right);
        printf("%d ",r->data);
    }
}

void inorder(struct Node* r){
    if(r){
        inorder(r->left);
        printf("%d ",r->data);
        inorder(r->right);
    }
}

struct Node* search(struct Node* r, int key){
    if(r == NULL){
        printf("Empty Tree\n");
        return NULL;
    }
    if(key == r->data){
        return r;
    }
    if(key > r->data){
        search(r->left, key);
    }
    if(key < r->data){
        search(r->right, key);
    }

}

int main(){
    struct Node* root;
    printf("Enter no of nodes in tree: ");
    int n,info,choice;
    scanf("%d",&n);
    printf("Enter elements of BST: \n");
    for(int i=0; i<n; i++){
        printf("Element %d: ",i+1);
        scanf("%d",&info);
        insert(&root,info);
    }
    printf("BST created\n");
    printf("===MENU===\n");
    printf("1. Preorder\n2. Postorder\n3. Inorder\n4. Search\n5. Exit\n\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                preorder(root);
                break;
            case 2:
                postorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
        printf("Enter your Value: ");
        int key;
        scanf("%d",&key);
                search(root, key);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
        }
    }
}
