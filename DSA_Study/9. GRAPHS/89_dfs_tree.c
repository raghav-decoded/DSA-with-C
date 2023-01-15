/*
Depth First Search

Make a stack
Pick a random node and push it in the stack
repeat:
    pop from the stack and mark the element as visited
    push all unvisited nodes connected to the pop(node) in the stack

Input: A graph G = (V,E) and source node s in V
Algorithm:
DFS(G, u)
u.visited = true
    for each v € G.adj(u)
        if v.visited == false
        DFS(G, v)
init()
    for each u € G
        u.visited = false
    for each u € G
        DFS(G,u)

*/
#include<stdio.h>
#include<stdlib.h>
 
/*
        0 - 1
        | \ |
        3 - 2
         \ /
          4
         / \
        5   6
    Start(0) = 0 1 2 3 4 5 6 
*/

int visited[7] = {0,0,0,0,0,0,0};
    int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };
 
void DFS(int i){
    printf("%d ", i); // printing the first element
    visited[i] = 1; // Marking the first element as visited
    for (int j = 0; j < 7; j++)
    {
        //if there is a connection and j has not been visited call DFS(j)
        if(A[i][j]==1 && !visited[j]){
            DFS(j);
        }
    }
}
 
int main(){ 
    // DFS Implementation  
    DFS(0); 
    return 0;
}
