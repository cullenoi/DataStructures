#ifndef T1_H_
#define T1_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Adj_Node Adj_Node;
struct Adj_Node{// this represents a node in the list of adjacent vertices so that a list can be calculated..
    int dest;
    struct Adj_Node* next;
};

typedef struct Adj_list{// this is the start of the list which will be used to track each vertexs links
    Adj_Node* head;

}Adj_list;

typedef struct Graph{
    int Vertices; // vertices
    int* visited; //1||0 checks if its been visited in DFS//BFS
    Adj_list* array;
} Graph;

Graph* create_graph(int num_nodes); // creates a graph with num_nodes nodes, assuming nodes are stored in alphabetical order (A, B, C..)
void add_edge(Graph *g, int from, int to); // adds a directed edge
void bfs(Graph* g, int origin); //implements breath first search and prints the results
void dfs(Graph* g, int origin); //implements depth first search and prints the results
void delete_graph(Graph* g);
void dfs2(Graph* g,int origin);
void PrintLetter(int x);



#endif