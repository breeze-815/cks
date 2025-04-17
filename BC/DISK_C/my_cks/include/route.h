#ifndef ROUTE_H
#define ROUTE_H

typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
} Node; 

void draw_route();
void dijkstra(struct Node *start, struct Node *end);
void route();
#endif