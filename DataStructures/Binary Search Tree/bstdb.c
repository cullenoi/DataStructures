#include "bstdb.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX_POSSIBLE_ARRAY 105000
long int g_ID;
int lefts;
int rights;
static int g_num_searches;;
static int g_num_comps;
typedef struct Tree_Node{
char* data;
int  wordcount;
int ID;
struct Tree_Node* left;
struct Tree_Node* right;
} Tree_Node;
Tree_Node *root =NULL;
int IDs[MAX_POSSIBLE_ARRAY];
int count=0;

void fill_ascending( int size)
{
for(int k=0;k<size;k++){
 IDs[k]=k;
}
return;
}

 void medianSort(int size){
    int count=0;
    int pos=0;
    int posVal=0;

    while(count<size-1){
        if(count%2==0){
        pos=(((size-count)/2)+count);//starts at 0
        pos=pos-1;
        posVal=IDs[pos];
        
          for(int i = pos; i > count; i--) {
                IDs[i] = IDs[i - 1];   
            }
            IDs[count] = posVal;  
    }
    else{
            pos=(size-count+1)/2+count;//ODD so must treat like even
            pos=pos-1;
            posVal=IDs[pos];
            
          for(int i = pos; i > count; i--) {
                IDs[i] = IDs[i - 1];   
            }
            IDs[count] = posVal;  
            
        }
    count++;
    }
    return;
 }

// void medianSort(int r ){
// int size=r;

// IDs[count]=size;
// // int LR =0;
// if(count<8){
// if(size!=0){
// // size=r/2;
// count++;
// int left =size/2;
// int right= size+left;
// if(left==0)right=size+2;
// if(r==3)left=right=0;
// // if (right<OG)
// // {
// //     right=OG+1;
// // }

// // IDs[count]=left;
// // count++;
// // IDs[count]=right;
// // count++;
// if(left)medianSort(left);

// if(right)medianSort(right);
// }
// }
// return; 
// }


Tree_Node* tree_insert(Tree_Node** root, char* data, int wordcount,int g_next_id){//adds  a tree in the appropiate spot
    //TODO
  //  Tree_Node* buffer =NULL;
	size_t L_name;
    if(*root){//DOC ID NEEDED AS PARAMETER TO CHECK THEN SORT BY DOC ID
        if((g_next_id < (*root)->ID)){//Go left 
        lefts++;
//        buffer =   tree_insert(&(*root)->left,data,wordcount,g_next_id);
        return tree_insert(&(*root)->left,data,wordcount,g_next_id);

        }
        if((g_next_id >= (*root)->ID)){//Go Right
        rights++;
        return tree_insert(&(*root)->right,data,wordcount,g_next_id);
        }
    }
    else//root is null!
    {
    *root =(Tree_Node*) malloc(sizeof(Tree_Node));//because its null it must accocate space!
        L_name=strlen(data)+1;
		(*root)->data=calloc(L_name,sizeof(char));
        (*root)->wordcount=wordcount;
        (*root)->left=NULL;
        (*root)->right=NULL;
		(*root)->ID=g_next_id;//hash_function(data);
		if((*root)->data) {strcpy((*root)->data,data);
		}else{
			printf("ERROR ON BOARD");
			(*root)->left=NULL;
			(*root)->right=NULL;
			 (*root) =NULL;
		}

    }
return(*root);
}


// int hash_function(char* s){
    // int hash = 0;
	// const int  m = 1e9 + 7;
	// long R_pow = 1;
	// int weight=1102;
	// int weight2=3101;

    // int R=31;
    // while(*s){
	// 	// if(s=='o'||s=='O')*s=*s*weight;
	// 	// if(s=='M'||s=='m')*s=*s*weight2;

    //     hash = (hash + (*s*R_pow));
    //     s++;
	// R_pow=(R_pow*R)%m;

    // }
    // return (abs(hash % ARRAY_SIZE));
// return count++;
//  }


int bstdb_init ( void ) {
	// This function will run once (and only once) when the database first
	// starts. Use it to allocate any memory you want to use or initialize 
	// some globals if you need to. Function should return 1 if initialization
	// was successful and 0 if something went wrong.
	root = NULL;
    count=0;
	g_ID=0;
    lefts=0;
    rights =0;
    g_num_comps = 0;
    g_num_searches = 0;
	int size =MAX_POSSIBLE_ARRAY;
	// IDs[size];
	// fill_ascending(size);
	medianSort(size);
	// medianSort(size);
	// medianSort(size);
	if(root!=NULL) return 0;
    else
	return 1;
	
}

int
bstdb_add ( char *name, int word_count ) {
	// insert_counter++;
	// if (insert_counter%500 == 0) {printf("%d insertions\n", insert_counter);}
	int x =IDs[g_ID];

	Tree_Node* temp =NULL;
	temp =	tree_insert(&root,name, word_count,x);
	if(temp){
		g_ID++;
	return x;
	}
	else
	return -1;
}


int bstdb_get_word_count ( int doc_id ) {
 Tree_Node* buffer=NULL;
 Tree_Node* R =NULL;
        g_num_searches++;
 R=root;
    while(R->left != NULL || R->right != NULL ){
        g_num_comps++;
        if((*R).ID > doc_id){//Go left
            buffer=R;
            R = buffer->left;
        }

        if((*R).ID < doc_id){//Go Right
            buffer=R;
            R = buffer->right;
        }

        if((*R).ID ==doc_id){//EQUAL go left for now //TODO
           // printf("%c is present!!\n",data);
            return (*R).wordcount;
        }        
    }
    //ELSE NOT THERE
return 0;
}

char* bstdb_get_name ( int doc_id ) {
	Tree_Node* buffer;
	Tree_Node* R;
	R=root;

        g_num_searches++;
    while(R->left != NULL || R->right != NULL ){
        g_num_comps++;
        if((*R).ID > doc_id){//Go left
            buffer=R;
            R= buffer->left;
        }

        if((*R).ID < doc_id){//Go Right
            buffer=R;
            R = buffer->right;
        }

        if((*R).ID ==doc_id){//EQUAL go left for now //TODO
		
        //    printf(" is present!!\n");
		//    size_t Len;
		   //Len=strlen((*R->data));
		//    char* name =sizeof((*R).data);
		//    strcpy(name,(*R).data);
            return (*R).data;
        }        
    }
    //ELSE NOT THERE
return NULL;
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
     
}
if(root==NULL){
return;
}
}



void
bstdb_stat ( void ) {
	

  printf("STAT\n");
    printf("Avg comparisons per search  -> %lf\n",
        (double)g_num_comps/g_num_searches);
    printf("List size matches expected? -> %d\n",
        ((g_ID == (lefts+rights))? 'Y' : 'N') );
    printf("Num of Lefts =%d\n",lefts);
    printf("Num of Rights =%d\n",rights);

	//  + Check if your tree is balanced and print the result
	//

	//  + Does the number of nodes in the tree match the number you expect
	//    based on the number of insertions you performed?
	//
	//  + How many nodes on average did you need to traverse in order to find
	//    a search result? 
	//
	//  + Can you prove that there are no accidental duplicate document IDs
	//    in the tree?
	return;
}

void
bstdb_quit ( void ) {
tree_delete(root);


	return;
}


