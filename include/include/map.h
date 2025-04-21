#ifndef __MAP_H
#define __MAP_H

typedef struct Node { 
    int x, y;
    int adj_nodes[6];
    int distance[6];
    int num_of_adj_nodes;
} Node; 

void show_map();
void dijkstra(struct Node *start, struct Node *end);

#endif