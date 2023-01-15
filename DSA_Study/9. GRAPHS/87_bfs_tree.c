/*
Breadth First Search(BFS)

Method 1 : BFS Spanning Tree
    pick a random node
    construct a tree with random node as root node
    mark all sideways or duplicate edges as dashed
    LOT(Level Order Traversal) along each breadth is valid

Method 2 : BFS (Queue)
    Visited array:
    Exploration queue:

    pick a random node
    insert that node in the visited_array and exploration_queue 
   
    repeat until the exploration_queue is empty:
        explore the node: visit all nodes connected to the node 
        pop the explored node
        push the visited nodes into the exploration_queue


PSEUDOCODE:
Input: A graph G = (V,E) and source node s in V

Mark all nodes v in V as unvisited
Mark source node as visited
enq(Q,s) //First-in first-out Queue

- while (Q is not empty)
{ 
    u = deq(Q);
    for each unvisited neighbour v of u 
    { 
        mark v as visited
    enq(Q,v);
    }
}
*/
#include<stdio.h>
#include<stdlib.h>
 
struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};
 
int isEmpty(struct queue *q){
    if(q->r==q->f){
        return 1;
    }
    return 0;
}
 
int isFull(struct queue *q){
    if(q->r==q->size-1){
        return 1;
    }
    return 0;
}
 
void enqueue(struct queue *q, int val){
    if(isFull(q)){
        printf("This Queue is full\n");
    }
    else{
        q->r++;
        q->arr[q->r] = val;
        // printf("Enqued element: %d\n", val);
    }
}
 
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("This Queue is empty\n");
    }
    else{
        q->f++;
        a = q->arr[q->f]; 
    }
    return a;
}
 
int main(){
    // Initializing Queue (Array Implementation)
    struct queue q;
    q.size = 400;
    q.f = q.r = 0;
    q.arr = (int*) malloc(q.size*sizeof(int));
    
    // BFS Implementation 
    /*
        0 - 1
        | \ |
        3 - 2
         \ /
          4
         / \
        5   6
    Start(0) = 0123456
    */
    int node;
    //Picking 0 as our root element(Starting point)
    int i = 0;
    int visited[7] = {0,0,0,0,0,0,0};
    //Adjacency matrix: [x][y] x corresponds to node values
    int a [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
    printf("%d", i);    // Printing i
    visited[i] = 1; // i was visited
    enqueue(&q, i); // Enqueue i for exploration

    while (!isEmpty(&q))
    {
        int node = dequeue(&q); // pop from the queue and assign to node
        //Iterating for every node connection
        for (int j = 0; j < 7; j++)
        {
            //if there is a connection between node and j and j is not visited 
            if(a[node][j] == 1 && visited[j] == 0){
                printf("%d", j);
                visited[j] = 1; // Visit j
                enqueue(&q, j); // Enqueue j
            }
        }
    }
    return 0;
}
