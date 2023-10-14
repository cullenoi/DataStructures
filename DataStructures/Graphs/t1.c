
#include <stdio.h>
#include <stdlib.h>
#include "t1.h"



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <stdbool.h>

int mallocs=0;
int frees=0;
typedef struct queue{//defining queue here
    Adj_Node* head;
    Adj_Node* tail;
}queue;

void init_queue(queue*q);
bool enqueue(queue* myqueue, int value);
int  dequeue(queue* myqueue);

void init_queue(queue*q);
bool enqueue(queue* myqueue, int value);
int  dequeue(queue* myqueue);
void init_queue(queue*q){
    q->head =NULL;
    q->tail =NULL;

}
bool enqueue(queue* q, int value){
    Adj_Node* new = (Adj_Node*)malloc(sizeof(Adj_Node));
    mallocs++;
    if(new==NULL)return false;//malloc failed try again
    new->dest=value;
    new->next=NULL;
    if(q->tail){//!=NULL
        q->tail->next=new;
    }
    q->tail=new;
    if(q->head==NULL){//first case
        q->head = new;
    }
    return true;
}

int  dequeue(queue* q){
    int x=0;
    if(q->head==NULL)return -1;//Q id empty

    Adj_Node* buffer=NULL;
    buffer=q->head;
    x=buffer->dest;//equate to the value of dest

    if(buffer->next==NULL){//last stack
    q->tail=NULL;
    free(buffer);
    frees++;
    q->head=NULL;
    return x;
    }  
    q->head=buffer->next;
    frees++;
    free(buffer);
    return x;

}


////////////////////////////////////////////////////////////////////////////
Graph* create_graph(int num_nodes) // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)
{
Graph* new = (Graph*)malloc(sizeof(Graph));
mallocs++;
(*new).Vertices=num_nodes;

new->array=(Adj_list*)malloc(sizeof(Adj_Node)*num_nodes); //have to allocate a space of memory which will
// hold X nodes. 
new->visited=(int*)malloc(sizeof(int)*num_nodes);//array marker

    for (int i = 0; i < num_nodes; i++){
        new->visited[i]=0;//make all of the array =0..
        new->array[i].head = NULL;//start off by making each vertice =0 as we dont yet know the connections between each other...
    }
    
return new;
}

// int search(Graph *g, int from, int to){
//     Graph* buffer=NULL;
//     if(g->array[from].head){//!=NULL
//         if(g->array[from].head->dest==to)return 1;
//         else
//         buffer=g->array[from].head->next;
//         return search(buffer,from,to);
//     }
//     else return 0;
// }
void add_edge(Graph *g, int from, int to)// adds a directed edge
{
    int here =0;
    Adj_Node* new=(Adj_Node*)malloc(sizeof(Adj_Node));
    mallocs++;
        (*new).dest=to;
        new->next=NULL;
    Adj_Node* check =NULL;//will check to ensure no repeats
    //!=NULL
    //IF NULL ADD SOMETHING TO FRONT
    //ELSE ADD TO BACK 
  //  if(search(g,from,to)){//!=0 will return
  check=g->array[from].head;
  while(check!=NULL){
    if(check->dest==new->dest){//present
    here =1;
    break;
    }
    check=check->next;//update to iterate down through loop
  }
  if(1==here){
    printf("Already present not allowed to be included!\n");
    return;}
  
    new->next=g->array[from].head;//adds to front
    g->array[from].head=new;
    //}
    //else{printf("Already present not allowed to be included!\n");}
    
    
    return;
}

void bfs(Graph* g, int origin)//implements breath first search and prints the results
{
    printf("BFS: ");
     for (int i = 0; i < g->Vertices; i++){
        g->visited[i]=0;//make all of the array =0..
     }
    int check=0;
    queue* q=(queue*)malloc(sizeof(queue));
    mallocs++;
    init_queue(q);
    
    Adj_Node* Buffer =NULL;//protective measure.....
    int next=0;
    if(g->visited[origin]==1)return;//already visited this node..
    g->visited[origin]=1;//Visited
    PrintLetter(origin);
    // printf("BFS Visited Node : %d\n",origin);
    enqueue(q,origin);
    while(q!=NULL){

        next= dequeue(q);
        if(next==-1)break;
        Buffer=g->array[next].head;
        while(Buffer!=NULL){//checks all adjacent nodes for this node
                check =Buffer->dest;
            // if(g->visited[check]==1)Buffer=Buffer->next;//been there done that

             if(g->visited[check]!=1){//Have an issue with the way we are queing this aside from that everything else works
                g->visited[check]=1;
                // printf("B00M %d\n",Buffer->dest);
                PrintLetter(check);
                enqueue(q,check);
            }
            Buffer=Buffer->next;// update this fecking thing....
        }
    }
    free(q);
    frees++;
    printf(" \n");
return;
 
}

void dfs(Graph* g, int origin) //implements depth first search and prints the results
{
    printf("DFS: ");
    for (int i = 0; i < g->Vertices; i++){
        g->visited[i]=0;//make all of the array =0..
     }
    dfs2(g,origin);
    printf(" \n");
    return;
}
void dfs2(Graph* g,int origin){
    Adj_Node* Buffer =NULL;//protective measure.....

      // if(g==NULL)return NULL//EDGE CASE 1

    if(g->visited[origin]==1)return;//already visited this node..
    else{
     g->visited[origin]=1;//Visited
    // printf("Visited Node : %d\n",origin);
    PrintLetter(origin);
    // init_queue(q);
    Buffer=g->array[origin].head;
    while(Buffer!=NULL){//PUSH ADJ NODES
    dfs2(g,Buffer->dest);
    Buffer=Buffer->next;//updates list so we check whole list
    
   }
  }
}
void delete_graph(Graph* g){// works seemingly fine...
    Adj_Node* Buffer =NULL;
    Adj_Node* tmp =NULL;
    for(int i=0;i<g->Vertices;i++){//cycle through the 2d linked lists
         Buffer=g->array[i].head;

        while(Buffer){    
            tmp=Buffer->next;
            frees++;
            free(Buffer);
            Buffer=tmp;
           } 
    }
   
    
    // frees++;  //Loose lips sink ships
    free(g->array);
    free(g->visited);
    free(g);
    frees++;
    frees++;
    frees++;

    return;    
}



void PrintLetter( int x ) {
		char c=x+'A';
        printf("%c ",c);


	return ;
    }
    /////////////////////////////////////////////////////////////////////////////////////

    
// static int char2val ( char c ) {
// 	if ( c < 'A' || c > 'Z' ) {
// 		return -1;
// 	}

// 	return c-'A';
	
// }

// int main(){
//     int num_nodes = 6;
//     Graph *graph = create_graph(num_nodes);
   
//     add_edge(graph, char2val('A'), char2val('E'));
//     add_edge(graph, char2val('B'), char2val('D'));
//     add_edge(graph, char2val('A'), char2val('D'));
//     add_edge(graph, char2val('A'), char2val('B'));
//     add_edge(graph, char2val('B'), char2val('C'));
//     add_edge(graph, char2val('C'), char2val('B'));
//     add_edge(graph, char2val('E'), char2val('D'));
//     add_edge(graph, char2val('D'), char2val('F'));
//     add_edge(graph, char2val('F'), char2val('C'));
//     add_edge(graph, char2val('C'), char2val('D'));
//     dfs(graph,char2val('A'));
//     printf("\n");
//     bfs(graph, char2val('A'));

//     delete_graph(graph);

//     return 0;
// }