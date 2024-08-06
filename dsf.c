#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// structure for a node in the graph
struct Node {
    int val;
    struct Node* next;
};

// structure for the graph
struct Graph {
    int num_vertices;
    struct Node** adj_list;
};

// create a new node with the given value
struct Node* create_node(int val) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

// create a graph with the given number of vertices
struct Graph* create_graph(int num_vertices) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->num_vertices = num_vertices;
    graph->adj_list = (struct Node**) malloc(num_vertices * sizeof(struct Node*));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

// add an edge to the graph between nodes u and v
void add_edge(struct Graph* graph, int u, int v) {
    struct Node* new_node = create_node(v);
    new_node->next = graph->adj_list[u];
    graph->adj_list[u] = new_node;

    new_node = create_node(u);
    new_node->next = graph->adj_list[v];
    graph->adj_list[v] = new_node;
}
// depth-first search traversal of the graph starting from the given vertex
void dfs_helper(struct Graph* graph, int vertex, int visited[]) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    struct Node* temp = graph->adj_list[vertex];
    while (temp != NULL) {
        int adj_vertex = temp->val;
        if (!visited[adj_vertex]) {
            dfs_helper(graph, adj_vertex, visited);
        }
        temp = temp->next;
    }
}

void dfs(struct Graph* graph, int start) {
    int visited[MAX_SIZE] = {0};

    printf("DFS Traversal: ");
    dfs_helper(graph, start, visited);

    printf("\n");
}
int main() {
    int num_vertices = 6;
    struct Graph* graph = create_graph(num_vertices);

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    dfs(graph, 0);
    return 0;
}