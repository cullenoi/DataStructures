#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "bst.h"


int nodes = 0;
int frees = 0;

void tree_insert(Tree_Node** root, char data){//adds  a tree in the appropiate spot
    //TODO
    if(*root!=NULL){
        if((data < (*root)->data)){//Go left
            tree_insert(&(*root)->left,data);
        }
        if((data >= (*root)->data)){//Go Right
            tree_insert(&(*root)->right,data);
        }
    }
    else//root is null!
    {
    *root =(Tree_Node*) malloc(sizeof(Tree_Node));//because its null it must accocate space!
    nodes++;
        (*root)->data=data;
        (*root)->left=NULL;
        (*root)->right=NULL;
    }
return;

}

Tree_Node* create_bst (char data[]){
    // TODO
    // int X = sizeof(data);
    // int Y = sizeof(data[0]);
    // int length =strlen(data);//X/Y;
   // Tree_Node* root =(Tree_Node*) malloc(sizeof(Tree_Node));
    Tree_Node* root = NULL;
    //insert first thingy...
    // (*root).data=data[0];
    int i=0;
    while(data[i]!='\0'){
        tree_insert(&root,data[i]);
        i++;
    }
//printf("**INSERTION FINISHED**\n");
return root;
}

Tree_Node* tree_search(Tree_Node* root, char data){//returns the pointer of the thing your searching for
    //TODO
    Tree_Node* buffer;
    if(root==NULL){printf("%c is not in the data set\n",data);
        return NULL;} 
    while((root!=NULL)&&(root->left != NULL || root->right != NULL)){
     if(root==NULL){printf("%c is not in the data set\n",data);
        return NULL;}  

         if((*root).data > data){//Go left
            buffer=root;
            root = buffer->left;
            continue;
        }

        if((*root).data < data){//Go Right
            buffer=root;
            root = buffer->right;
            continue;
        }

        if((*root).data ==data){//EQUAL go left for now //TODO
            printf("%c is Found\n",data);
            return root;

        }        
    }
    //ELSE NOT THERE
   printf("%c is not in the data set\n",data);
    return NULL;
}
void print_Recursion(Tree_Node* root){
Tree_Node* leftRoot;
Tree_Node* rightRoot;
// printf("IN HERE\n");
// if (root)
// {
// printf("nothng here\n");
// }
   
if (root) printf("Data is %c\n",root->data);
 if(root->right!=NULL){
    rightRoot=root->right;
    print_Recursion(rightRoot);

 }
 if(root->left!=NULL){
    leftRoot=root->left;
    print_Recursion(leftRoot);
 }
return;
}
void tree_print_sorted(Tree_Node* root){
    //TODO
    print_Recursion(root);    
return;
}

void tree_delete(Tree_Node* root){
    //TODO
    Tree_Node* bufferR =NULL;
    Tree_Node* bufferL =NULL;

   if (root)//!=NULL
   {

    bufferL=root->left;

    bufferR=root->right;
   if(bufferL!=NULL){
    
    tree_delete(bufferL);
    
   }
   if(bufferR!=NULL){
        tree_delete(bufferR);
   }
     free(root);
     frees++;
}
}
