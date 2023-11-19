#include "graph.h"

// @brief Construct a Graph with the given number of vertices.
// @param nV The number of vertices in the graph.
Graph::Graph(int nV){
    numVerts = nV;
    for (int i=0; i<numVerts; i++){
        Vertex x(i);
        vertices.push_back(x);
        vector<Edge> y;
        adjList.push_back(y);
    }
}

// @brief destructor
Graph::~Graph(){
    // TODO: Add your code here
}

// @brief add a vertex to the graph
void Graph::addVertex(Vertex v){
    vertices.push_back(v);
    vector<Edge> x;
    adjList.push_back(x);
    numVerts++;
    // TODO: Add a vertex to the vertex vector
    // TODO: Add an empty list to the adjacency list
}

// @brief add a directed edge v1->v2 to the graph
void Graph::addDirectedEdge(int v1, int v2, float weight){
    if(v1 < numVerts && v2 < numVerts){
        Edge edge(v1, v2, weight);
        adjList[v1].push_back(edge);
    }    
    // TODO: Add an edge to the adjacency list of v1
}

// @brief add an undirected edge to the graph
void Graph::addUndirectedEdge(int v1, int v2, float weight){
    if(v1 < numVerts && v2 < numVerts){
        Edge edge1(v1, v2, weight);
        Edge edge2(v2, v1, weight);
        adjList[v1].push_back(edge1);
        adjList[v2].push_back(edge2);
        // TODO: Add edge v1->v2
        // TODO: Add edge v2->v1
    }
}

// @brief the number of outgoing edges from a vertex
int Graph::outDegree(int v)
{
    if(v < numVerts){
        return (int)adjList[v].size();
    }
    return -1;
}

// @brief depth first search from vertex v
vector<int> Graph::DepthFirstSearch(int v){
    if(v < numVerts){
        stack<int> vertexStack;
        vector<int> visitedSet;
        vertexStack.push(v);

        while(!vertexStack.empty()){
            int cur = vertexStack.top();
            vertexStack.pop();
            bool found = false;
            for(vector<int>::iterator it=visitedSet.begin(); it != visitedSet.end(); ++it){
                if(cur == *it){
                    found = true;
                    break;
                }
            }
            if(!found){
                visitedSet.push_back(cur);
                for(vector<Edge>::reverse_iterator i = adjList[cur].rbegin(); i != adjList[cur].rend(); ++i ){
                    int adjV = i->to_vertex;
                    vertexStack.push(adjV);
                }
            }
        }
        return visitedSet;
    }
    else{
        vector<int> x;
        return x;
    }
    // TODO: Implement the depth first search algorithm
    // Add the vertex ID to a vector when it is visited
}

// @brief breadth first search from a vertex
vector<int> Graph::BreadthFirstSearch(int v){
    if(v < numVerts){
        vector<int> visitedList;
        queue<int> frontierQueue;
        list<int> discoveredSet;
        frontierQueue.push(v);
        discoveredSet.push_back(v);
        while(!frontierQueue.empty()){
            int cur = frontierQueue.front();
            frontierQueue.pop();
            visitedList.push_back(cur);
            for(Edge edge : adjList[cur]){
                int adjV = edge.to_vertex;
                bool found = false;
                for(list<int>::iterator it=discoveredSet.begin(); it != discoveredSet.end(); ++it){
                    if(adjV == *it){
                        found = true;
                        break;
                    }
                }
                if(!found){
                    frontierQueue.push(adjV);
                    discoveredSet.push_back(adjV);
                }
            }
        }
        return visitedList;
    }
    else{
        vector<int> x;
        return x;
    }
    // TODO: Implement the breadth first search algorithm
    // Add the vertex ID to a vector when it is visited
}

/**
 * @brief Check if the graph has cycles
 * @return true if the graph has cycles
 */
bool Graph::checkCycle(){
    vector<bool> visited(numVerts, false);
    for(int i=0; i<numVerts; i++){
        if(!visited[i]){
            if(checkCycleHelper(i, visited, -1)){
                return true;
            }
        }
    }
    // TODO: Implement the algorithm to check if the graph has cycles
    // Assume an undirected graph
    return false;
}

bool Graph::checkCycleHelper(int v, vector<bool> &visited, int parent){
    visited[v] = true;
    for(Edge edge : adjList[v]){
        if(!visited[edge.to_vertex]){
            if(checkCycleHelper(edge.to_vertex, visited, v)){
                return true;
            }
        }
        else if(edge.to_vertex != parent){
            return true;
        }
    }
    return false;
}

// @brief print the graph
void Graph::printGraph()
{
    cout << "Graph:" << endl;
    for (int i = 0; i < numVerts; i++)
    {
        cout << i << ": ";
        for(auto j = adjList[i].begin(); j != adjList[i].end(); ++j)
        {
            cout << (*j).to_vertex << " " ;
        }
        cout << endl;
    }
    cout << endl;
}
