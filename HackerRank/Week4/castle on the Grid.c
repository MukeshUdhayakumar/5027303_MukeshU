#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int total;
    struct Node** neighbor;
};

struct Node* createNode(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->vertex=val;
    newNode->next=NULL;
    return newNode;
}


struct Graph* createGraph(int vertex){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->total=vertex;
    graph->neighbor=(struct Node**)malloc(vertex*sizeof(struct Node*));

    for(int i=0;i<vertex;i++){
        graph->neighbor[i]=NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
    struct Node* newNode=createNode(dest);
    newNode->next=graph->neighbor[src];
    graph->neighbor[src]=newNode;

    newNode=createNode(src);
    newNode->next=graph->neighbor[dest];
    graph->neighbor[dest]=newNode;
}

void insertGraph(struct Graph* graph,int n,char grid[][100]){
    int lr[4]={-1,1,0,0};
    int ud[4]={0,0,-1,1};

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(grid[r][c]!='X'){
                int src=r*n+c; 

                for (int k=0;k<4;k++) {
                    int nr=r,nc=c;
                    while (1) {
                        nr+=lr[k];
                        nc+=ud[k];
                        if(nr<0||nr>=n||nc<0||nc>=n) break; 
                        if(grid[nr][nc]=='X') break;
                        int dest=nr*n+nc;
                        addEdge(graph, src, dest);
                    }
                }    
            }
        }
    }
}

int minimumMoves(struct Graph* graph,int start,int goal){
    int n=graph->total;
    int visit[n];
    int dist[n];
    int queue[n];
    int f=0,r=0;
    for(int i=0;i<n;i++){
        visit[i]=0;
    }
    
    visit[start]=1;
    dist[start]=0;
    queue[r++]=start;

    while(f<r){
        int cur=queue[f++];
        if(cur==goal){
            return dist[cur];
        }

        struct Node* temp=graph->neighbor[cur];
        while(temp){
            int node=temp->vertex;
            if (!visit[node]){
                visit[node]=1;
                dist[node]=dist[cur]+1;
                queue[r++]=node;
            }
            temp=temp->next;
        }
    }
    return -1;
}

int main() {
    int n;
    scanf("%d",&n);

    char grid[n][100];
    for(int i=0;i<n;i++) {
        scanf("%s",grid[i]);
    }

    int startX, startY, goalX, goalY;
    scanf("%d %d %d %d", &startX, &startY, &goalX, &goalY);

    int vertex=n*n;
    struct Graph* graph=createGraph(vertex);
    insertGraph(graph,n,grid);

    int startNode=startX*n+startY;
    int goalNode=goalX*n+goalY;
    int totDis=minimumMoves(graph,startNode,goalNode);
    printf("%d\n",totDis);

    return 0;
}
