#include"Delivery.h"
#include <limits.h> 
#define V 14
using namespace std;

delivery_worker::delivery_worker(string s,int p):person(s){
	max_packs = p;
	packs = 0;
	listCust = NULL;
	numCust = 0;
}


void delivery_worker::add_cust(const customer& cust) {
	
	customer* new_list = new customer[numCust+1];
	for (int i = 0; i < numCust; i++) {
		new_list[i] = listCust[i];
	}
	new_list[numCust] = cust;
	delete[] listCust;
	listCust = new_list;
	numCust++;

    cout << "you added a cutomer" << endl;

}


/*const delivery_worker& delivery_worker::operator =(const delivery_worker& theOther) {
    this->numCust = theOther.numCust;
    this->packs = theOther.packs;
    delete[] this->listCust;
    this->listCust = new customer[numCust];
    for (int i = 0; i < numCust; i++) {
        this->listCust[i] = theOther.listCust[i];
    }
    return theOther;
}      */                     //operator overloading was needed because of the dynamic memory, but I had no use of it in the program
 
bool delivery_worker::check(const customer& cust,int n) {

	if (packs + n < max_packs) {  //add the time faza if possible
		packs += n;
		return true;
	}
	else
		return false;
}


//this is shortest path algorithm I've taken it from geeks for geeks
// Number of vertices in the graph 
 

// A utility function to find the vertex with minimum distance value, from 
// the set of vertices not yet included in shortest path tree 
int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value 
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance array 
void printSolution(int dist[])
{
    cout<<"Vertex \t\t Distance from Source"<<endl;
    for (int i = 0; i < V; i++)
        cout<<i<<"\t\t"<< dist[i]<<endl;
}


//This is a function from geeksforgeeks
// Function that implements Dijkstra's single source shortest path algorithm 
// for a graph represented using adjacency matrix representation 
void dijkstra(int graph[V][V], int src)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest 
    // distance from src to i 

    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest 
    // path tree or shortest distance from src to i is finalized 

    // Initialize all distances as INFINITE and stpSet[] as false 
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0 
    dist[src] = 0;

    // Find shortest path for all vertices 
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed 
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int v = 0; v < V; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // print the constructed distance array 
    printSolution(dist);
}



void delivery_worker::order() {

    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                        { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                        { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                        { 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                        { 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                        { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
                        { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1},
                        { 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0},
                        { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
                        { 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                        { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0} };

    dijkstra(graph, 0);

}