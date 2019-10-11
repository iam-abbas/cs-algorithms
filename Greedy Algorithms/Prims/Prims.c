

#include<stdio.h>
#include<stdlib.h>
#include<climits>

int a[100][100], visitedVertices[100], visitedVerticesCount, currentVertex, totalCost, numberOfVertices;

void prims() {
    int i,j,nextMinimumEdge,nextMinimumVertex;
    printf("Enter the starting vertex: ");
    scanf("%d", &currentVertex);
    
    //Add initial to the list of visited vertices
    currentVertex--;
    visitedVertices[currentVertex] = 1;
    printf("The Minimum Cost Spanning Tree is \n");
    
    //Set visited vertices count to zero
    visitedVerticesCount = 0;
    
    while(visitedVerticesCount < numberOfVertices-1) {
        nextMinimumEdge = INT_MAX;
        for(i=0; i<numberOfVertices; ++i) {
        
            //If vertex 'i' is visited
            if(visitedVertices[i] == 1) {
            
                //Find next unvisited vertex
                currentVertex = i;
                for(j=0; j<numberOfVertices; ++j) {
                    if(visitedVertices[j] == 0) {
                    
                        //If the edge exists and the edge cost is less than current minimum edge
                        if(a[i][j]!=0 && a[i][j] < nextMinimumEdge) {
                        
                            //change current minimum edge and vertex values
                            nextMinimumEdge = a[i][j];
                            nextMinimumVertex = j;
                        }
                    }
                }
            }
        }
        
        //mark current minimum vertex as visited
        visitedVertices[nextMinimumVertex] = 1;
        totalCost = totalCost + nextMinimumEdge;

        printf("\n%d -> %d", currentVertex + 1, nextMinimumVertex + 1);
        visitedVerticesCount++;
    }
    printf("\nTotal cost of MST is %d.", totalCost);
}

//Driver Program
int main() {
    /*
    Test Matrix:
    0 1 2 0
    1 0 3 4
    2 3 0 5
    0 4 5 0
    */
    //Read values into the matrix
    int i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &numberOfVertices);
    for(i=0; i<numberOfVertices; ++i) {
        for(j=0; j<numberOfVertices; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    prims();

    return 0;
}
