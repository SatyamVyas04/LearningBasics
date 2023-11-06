#include "queue.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

GraphRep *init_graph(int num_vertices, bool is_directed) {
    GraphRep *graph = (GraphRep *)malloc(sizeof(GraphRep));
    graph->nE = 0;
    graph->nV = num_vertices;
    graph->is_directed = is_directed;
    graph->edges = (int **)malloc(sizeof(int *) * num_vertices * num_vertices);
    graph->distance = (int *)malloc(sizeof(int) * num_vertices);
    graph->predecessor = (Vertex *)malloc(sizeof(Vertex) * num_vertices);
    graph->color = (Color *)malloc(sizeof(Color) * num_vertices);

    for (int i = 0; i < num_vertices; i++) {
        graph->edges[i] = (int *)malloc(sizeof(int) * num_vertices);
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->edges[i][j] = 0;
        }
    }
    return graph;
}

void insert_edge(GraphRep *graph, Edge e) {
    graph->nE++;
    graph->edges[e.u][e.v] = 1;
    if (!(graph->is_directed)) {
        graph->edges[e.v][e.u] = 1;
        graph->nE++;
    }
}

void remove_edge(GraphRep *graph, Edge e) {
    graph->nE--;
    graph->edges[e.u][e.v] = 0;
    if (!(graph->is_directed)) {
        graph->edges[e.v][e.u] = 0;
        graph->nE--;
    }
}

// NOTE: During both DFS and BFS traversals, when at a vertex that is connected with multiple vertices, always pick the connecting vertex which has the lowest value first
// Both traversals will always update the following attributes of the Graph:
// 1. source -> stores the value of the starting vertex for the traversal
// 2. type -> stores the traversal type (BFS or DFS)
// 3. color --> indicates if all vertices have been visited or not. Post traversal, all vertices should be BLACK
// 4. predecessor --> this array would hold the predecessor for a given vertex (indicated by the array index).

// NOTE: BFS Traversal should additionally update the following in the graph:
// 1. distance --> this array would hold the number of hops it takes to reach a given vertex (indicated by the array index) from the source.
void traverse_bfs(GraphRep *graph, Vertex source) {
    graph->type = BFS;
    graph->source = source;
    for (int i = 0; i < graph->nV; i++) {
        graph->color[i] = WHITE;
        graph->distance[i] = 100;
        graph->predecessor[i] = -1;
    }

    graph->color[source] = GRAY;
    graph->distance[source] = 0;
    graph->predecessor[source] = -1;

    printf("\n>>> HERE---\n");
    Queue *q = initialize_queue(graph->nV);
    enqueue(q, source);

    while (!(isEmpty(q))) {
        Vertex u = dequeue(q);
        for (int i = 0; i < graph->nV; i++) {
            Vertex v = i;
            if (graph->color[v] == WHITE) {
                graph->color[v] = GRAY;
                graph->distance[v] = graph->distance[u] + 1;
                graph->predecessor[i] = u;
                enqueue(q, v);
            }
        }
        graph->color[u] = BLACK;
    }
    for (int i = 0; i < graph->nV; i++) {
        printf("\n> %d  ", graph->distance[i]);
    }
    printf("\n------\n");
    for (int i = 0; i < graph->nV; i++) {
        printf("\n> %d  ", graph->predecessor[i]);
    }
}

// NOTE: DFS Traversal should additionally update the following in the graph:
// 1. distance --> Assuming 1 hop to equal 1 time unit, this array would hold the time of discovery a given vertex (indicated by the array index) from the source.
// 2. finish --> Assuming 1 hop to equal 1 time unit, this array would hold the time at which exploration concludes for a given vertex (indicated by the array index).
void traverse_dfs(GraphRep *graph, Vertex source);

// displays the path from the current 'source' in graph to the provided 'destination'.
// The graph holds the value of the traversal type, so the function should let the caller know what kind of traversal was done on the graph and from which vertex, along with the path.
void display_path(GraphRep *graph, Vertex destination);

// display the graph in the matrix form
void display_graph(GraphRep *graph) {
    printf("\n\n------------------ Graph ------------------\n");
    for (int i = 0; i < graph->nV; i++) {
        printf("\t[%d]", i);
    }
    for (int i = 0; i < graph->nV; i++) {
        printf("\n[%d]", i);
        for (int j = 0; j < graph->nV; j++) {
            printf("\t %d", graph->edges[i][j]);
        }
    }
}

void main() {
    GraphRep *g = init_graph(5, true);
    display_graph(g);
    Edge e;
    e.u = 1;
    e.v = 2;
    insert_edge(g, e);
    e.u = 0;
    e.v = 1;
    insert_edge(g, e);
    e.u = 4;
    e.v = 3;
    insert_edge(g, e);
    e.u = 1;
    e.v = 4;
    insert_edge(g, e);
    display_graph(g);

    Vertex v;
    v = 0;
    traverse_bfs(g, v);
}