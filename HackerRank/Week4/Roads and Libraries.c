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

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int total;
    struct Node** neighbor;
};

struct Node* createNode(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->vertex=val;
    node->next=NULL;
    return node;
}

struct Graph* createGraph(int n){
    struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->total=n;
    graph->neighbor=(struct Node**)malloc((n+1) * sizeof(struct Node*));
    for(int i=0;i<=n;i++){
        graph->neighbor[i]=NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph,int c1,int c2) {
    struct Node* node = createNode(c1);
    node->next=graph->neighbor[c2];
    graph->neighbor[c2]=node;

    node=createNode(c2);
    node->next=graph->neighbor[c1];
    graph->neighbor[c1]=node;
}

int count(struct Graph* graph,int city,int* visit){
    visit[city]=1;
    int total=1;
    struct Node* temp=graph->neighbor[city];
    while(temp!=NULL){
        if(!visit[temp->vertex]){
            total+=count(graph,temp->vertex,visit);
        }
        temp=temp->next;
    }
    return total;
}

long long roadsAndLibraries(int n,int c_lib,int c_road,int m,int roads[m][2]){
    if(c_lib<=c_road){
        return (long long)n*c_lib;
    }

    struct Graph* graph=createGraph(n);
    for(int i=0;i<m;i++){
        addEdge(graph,roads[i][0],roads[i][1]);
    }

    int visit[n+1];
    for (int i=0;i<=n;i++){
        visit[i]=0;
    }
    long long total=0;

    for(int i=1;i<=n;i++){
        if(!visit[i]){
            int connectCities=count(graph,i,visit);
            total+=(long long)c_lib+(long long)(connectCities-1)*c_road;
        }
    }

    return total;
}

int main(){
    int q;
    scanf("%d",&q);
    while (q--){
        int n,m,c_lib,c_road;
        scanf("%d %d %d %d",&n,&m,&c_lib,&c_road);
        int roads[m][2];
        for(int i=0;i<m;i++){
            scanf("%d %d",&roads[i][0],&roads[i][1]);
        }
        printf("%lld\n",roadsAndLibraries(n,c_lib,c_road,m,roads));
    }
    return 0;
}
