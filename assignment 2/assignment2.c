#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


/*printarray(int *v,int n){ // v is the array
    for(int i=0;i<n;i++){
        printf("%d",*v[i]);
    }
}


void dfs(Graph g, Vertex rootv, int numV) {//'wrapper' for recursive dfs
    int *visited = malloc(numV*sizeof(int));// ... handles disconnected graphs
    for(int i=0;i<numv;i++){
        *visited[i]=-1;
        
    }
    
    int longest;
    int lengthofpath;
    
    printarray(visited,numV);
    for(int g=0;g<numV;g++){
        int order = 0;
        Vertex startv = rootv;             // this is the starting vertex
        int allVis = 0;                    // assume not all visited
        while (!allVis) {                  // as long as there are vertices
            dfsR(g, startv, numV, &order, visited);
            allVis = 1;                     // are all visited now?
            for (Vertex w = 0; w < numV && allVis; w++) { // look for more
                if (visited[w] == -1) {
                    printf("Graph is disconnected\n"); // debug
                    allVis = 0;               // found an unvisited vertex
                    startv = w;              // next loop dfsR this vertex
                
                }
            
            }
        
        }
        printArray("Visited: ", visited, numV);
        free(visited);
        return;
    
}
    
}

void dfsR(Graph g, Vertex v, int numV, int *order, int *visited) {
    visited[v] = *order;                // records the order of visit
    *order = *order+1;
    for (Vertex w = 0; w < numV; w++) {
        if (isEdge(newEdge(v,w), g) && *) {
            dfsR(g, w, numV, order, visited);
            
        }
        
    }
    return;
    
}
*/
    
int differByOne(char *m, char *n){
    char *x=m;
    char *y=n;
    int count1=0;
    int count2=0;
    while(*x!='\0'){
        count1++;
        x=x+1;
    }
    
    while(*y!='\0'){
        count2++;
        y=y+1;
    }
    /*printf("value of x:%p\n",x);
    printf("value of y:%p\n",y);
    printf("value of m:%p\n",m);
    printf("value of n:%p\n",n);
    */
    x=m;
    y=n;
    /*printf("value of x:%p\n",x);
    printf("value of y:%p\n",y);
    printf("value of m:%p\n",m);
    printf("value of n:%p\n",n);
    
    printf("count1:%d\n",count1);
    printf("count2:%d\n",count2);*/
    
    
    if(abs(count1-count2)==0){
        
        //printf("test1\n");
        
        int flag=0;
        
        
        for(int v=0;v<count1;v++){
            
            if(*(x+v)==*(y+v)){
                
            }
            else{
                flag=flag+1;
            }
            
        }
        if(flag==1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(abs(count1-count2)==1){
        
        char *swap;
        int error=0;
        int d=0;
        int f=0;
        int s;
        
        if (count1>count2){
            
        }
        else{
            swap=x;
            x=y;
            y=swap;
            s=count1;
            count1=count2;
            count2=s;
            
        }
        
        while(d<count1 || f<count2){
            
            if(*(x+d)==*(y+f)){
                d++;
                f++;
                
                
            }
            else{
                d++;
                error=error+1;
            }
        }
        
        if (error!=1){
            return 0;
        }
        else{
            return 1;
            
        }
        
    }
    else{
        return 0;
    }
    
}
        
        
typedef int Vertex;
typedef struct graphRep *Graph;

typedef struct {                  // define an EDGE
    Vertex v;
    Vertex w;
    
} Edge;

struct graphRep {
int nV;       // #vertices
int nE;       // #edges
int **edges;  // matrix of Booleans ... THIS IS THE ADJACENCY MATRIX
};





Graph newGraph(int numVertices) {
    Graph g = NULL;
    if (numVertices < 0) {
        fprintf(stderr, "newgraph: invalid number of vertices\n");
        
    }
    else {
        g = malloc(sizeof(struct graphRep));
        if (g == NULL) {
            fprintf(stderr, "newGraph: out of memory\n");
            exit(1);
            
        }
        g->edges = malloc(numVertices * sizeof(int *));
        if (g->edges == NULL) {
            fprintf(stderr, "newGraph: out of memory\n");
            exit(1);
            
        }
        int v;
        for (v = 0; v < numVertices; v++) {
            g->edges[v] = malloc(numVertices * sizeof(int));
            if (g->edges[v] == NULL) {
                fprintf(stderr, "newGraph: out of memory\n");
                exit(1);
                
            }
            for (int j = 0; j < numVertices; j++) {
                g->edges[v][j] = 0;
                
            }
            
        }
        g->nV = numVertices;
        g->nE = 0;
        
    }
    return g;
    
}
Graph freeGraph(Graph g) {
    
        return g;
    }
void showGraph(Graph g) {
    if (g == NULL) {
        printf("NULL graph\n");
        
    }
    else {
        printf("V=%d, E=%d\n", g->nV, g->nE);
        int i;
        for (i = 0; i < g->nV; i++) {
            int nshown = 0;
            int j;
            for (j = 0; j < g->nV; j++) {
                if (g->edges[i][j] != 0) {
                    printf("<%d %d> ", i, j);
                    nshown++;
                    
                }
                
            }
            if (nshown > 0) {
                printf("\n");
                
            }
            
        }
        
    }
    return;
    
}
static int validV(Graph g, Vertex v) { // checks if v is in graph
    return (v >= 0 && v < g->nV);
    
}
Edge newE(Vertex v, Vertex w) { // create an edge from v to w
    Edge e = {v, w};
    return e;
    
}
void showE(Edge e) { // print an edge
    printf("<%d %d>", e.v, e.w);
    return;
    
}
int isEdge(Graph g, Edge e) { // return 1 if edge found, otherwise 0
    int found = 0;
    
     // code not shown
    return found;
    
}
void insertE(Graph g, Edge e) { // insert an edge into a graph
    if (g == NULL) {
        fprintf(stderr, "insertE: graph not initialised\n");
        
    }
    else {
        if (!validV(g, e.v) || !validV(g, e.w)) {
            fprintf(stderr, "insertE: invalid vertices <%d %d>\n", e.v, e.w);
            
        }
        else {
            if (isEdge(g, e) == 0) { // increment nE only if it is new
                g->nE++;
                
            }
            g->edges[e.v][e.w] = 1;
            g->edges[e.w][e.v] = 1;
            
        }
        
    }
    return;
    
}

void removeE(Graph g, Edge e) { // remove an edge from a graph
    if (g == NULL) {
        fprintf(stderr, "removeE: graph not initialised\n");
        
    }
    else {
        if (!validV(g, e.v) || !validV(g, e.w)) {
            fprintf(stderr, "removeE: invalid vertices\n");
            
        }
        else {
            if (isEdge(g, e) == 1) {   // is edge there?
                g->edges[e.v][e.w] = 0;
                g->edges[e.w][e.v] = 0;
                g->nE--;
                
            }
            
        }
        
    }
    return;
    
}
  

void findLongestPathlength(Graph g,Vertex v,int *maxlength,int d)
{
    // if destination is found, update max_dist
    
    int end=0;
    for(int i=0;i<g->nV;i++){
        
        if(g->edges[v][i]==1 && i>v){
            end=1;
            findLongestPathlength(g,i,maxlength,d+1);
        }
        
        
        
        
        if (end==0)
        {
            if(*maxlength<d){
                *maxlength=d;
            }
            //return;
        }
    }
}



void findLongestPath(Graph g,Vertex v,int first,char *dictionary[],int
                     pathlength[],int maxpath,int d){
    
    int end=0;
    pathlength[0]=first;
    for(int i=0;i<g->nV;i++){
        
        if(g->edges[v][i]==1 && i>v){
            end=1;
            pathlength[d+1]=i;
            
            findLongestPath(g,i,first,dictionary,pathlength,maxpath,d+1);
        }
        
        
        
    }
        if (end==0 && d==maxpath)
        {
            printf("%d %d\n",v,first);
            for(int i=0;i<=maxpath;i++){
                if(i!=maxpath){
                printf("%s-->",dictionary[pathlength[i]]);
                }
                else{
                    printf("%s",dictionary[pathlength[i]]);
                    
            }
            }
            printf("\n");
        }
    }
    



int main(int argc,char *argv[]){
    
    char c;
    char l[1000][20];
    int p=0,flag=0,x=0,m=0;
    printf("enter input\n");
    while ((c = getchar()) != EOF){
        
        if(c=='\n'){
            printf("newline");
        }
        
        if (isalpha(c)==1){
            if (flag==0){
                flag=1;
                x=0;
                l[p][x]=c;
                x++;
            }
            else{
                v[p][x]=c;
                x++;
            } }
        else{
            if (flag==1){
                flag=0;
                l[p][x]='\0';
                p++;
                
                
            }
            else{
                
                
            }
            
            
        }
        
    }
    
    if (flag==1){
        printf("flagerror:");
        v[p][x]='\0';
        p++;
        
    }
    
    
    char *b[p];
    
    //printf("p value is:%d\n",p);
    //printf("flag value:%d\n",flag);
    //printf("debug:%c\n",v[1][2]);
    /* for (int i=0;i<p;i++){
     
     m=0;
     while(v[i][m]=='\0'){
     *(b[i]+m)=v[i][m];
     m++;
     
     
     }
     *(b[i]+m)='\0';
     
     
     }
     */
    
    
    
    for(int i=0;i<p;i++){
        //for (int j=0;j<20;j++){
        
        printf("%s\n",v[i]);
        
    }
    
    
    printf("Dictionary\n");
    char *v[argc];
    int flag=0;
    int count=0;
    
    for(int i=1;i<argc;i++){
        flag=0;
        
        for(int j=1;j<i;j++){
            //printf("%s and %s \n",argv[i],argv[j]);
            
            if(strcmp(argv[i],argv[j])==0){
                //printf("flagset\n");
                flag=1;
                }
        }
            
        if(flag==0){
            v[count]=argv[i];
            count++;
            }
            
        }
        
    
    
    for (int i=0;i<count;i++){
        printf("%d :%s\n",i,v[i]);
    }
    
    Graph g;
    g=newGraph(count);
    
    for(int i=0;i<count;i++){
        
        
        for(int j=0;j<count;j++){
            if (differByOne(v[i],v[j])==1){
                
                // printf("differ:%d",differByOne(argv[i],argv[j]));
                if(i<j){
                    printf("i:%d j:%d\n",i,j);
                    Edge e;
                    e=newE(i,j);
                    insertE(g,e);
                }}}}
    
    showGraph(g);
    int temp=0;
    //int maxcount=0;
    int tempmax=0;
    for (int i=0;i<count;i++){
        temp=0;
        findLongestPathlength(g,i,&tempmax,0);
        if (temp>tempmax){
            tempmax=temp;
        }
        
        
    }
    printf("the max length is %d\n",tempmax+1);
    int path[tempmax+1];
    
    for(int i=0;i<count;i++){
        findLongestPath(g,i,i,v,path,tempmax,0);
    
    }
    

    
    return 1;
}
