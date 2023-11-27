#include "graph.h"

/**
 * @brief Construct a Graph with the given number of vertices
 * @param nV The number of vertices in the graph..
**/
Graph::Graph(int nV){
    //set member variable numVerts to input NV
    numVerts = nV;
    //create numVerts new vertices, and push them to the vertices vector
    //additionally, fill adjList edge vector for each vertex
    for (int i=0; i<numVerts; i++){
        Vertex x(i);
        vertices.push_back(x);
        vector<Edge> y;
        adjList.push_back(y);
    }
}

/**
 * @brief Destructor: Removes all free memory
*/
Graph::~Graph(){
    //use default destructor as there is no newly allocated memory for this DS
}

/**
 * @brief Add a vertex to the graph
 * @param v Vertex to add to the graph
*/
void Graph::addVertex(Vertex v){
    //push the new vertex to the vertices vector
    vertices.push_back(v);
    //create a new Edge for the newly added vertex, and push it to the adjList vector
    vector<Edge> x;
    adjList.push_back(x);
    //increment numVerts
    numVerts++;
}

/**
 * @brief Add a directed edge v1->v2 to the graph
 * @param v1 Starting vertex for the directed edge
 * @param v2 Terminal vertex for the directed edge
 * @param weight Optional weight cost for the edge. If unweighted, defaults to 1
*/
void Graph::addDirectedEdge(int v1, int v2, float weight){
    //check that v1 and v2 are proper vertices
    if(v1 < numVerts && v2 < numVerts && v1 >=0 && v2 >= 0){
        //create a new Edge from v1 -> v2 with associated weight, and push to adjList vector
        Edge edge(v1, v2, weight);
        adjList[v1].push_back(edge);
    }    
}

/**
 * @brief Add an undirected (two-way) edge v1->v2 and v2->v1 to the graph
 * @param v1 First vertex for the undirected edge
 * @param v2 Second vertex for the undirected edge
 * @param weight Optional weight cost for the edge. If unweighted, defaults to 1
*/
void Graph::addUndirectedEdge(int v1, int v2, float weight){
    //check that v1 and v2 are proper vertices
    if(v1 < numVerts && v2 < numVerts && v1 >=0 && v2 >= 0){
        //create a new edge from v1 -> v2 and v2 -> v1 with associated weight, and push to adjList vector
        Edge edge1(v1, v2, weight);
        Edge edge2(v2, v1, weight);
        adjList[v1].push_back(edge1);
        adjList[v2].push_back(edge2);
    }
}

/**
 * @brief The number of outgoing edges from a vertex
 * @param v The desired vertex to get the number of outgoing edges
 * @return Number of outgoing edges
*/
int Graph::outDegree(int v){
    //Verify v is a proper vertex
    if(v < numVerts && v >= 0){
        //return the length of the adjList vector for the associated vertex
        return (int)adjList[v].size();
    }
    //If v is not a proper vertex, return -1
    return -1;
}

/**
 * @brief Recursive helper function for DFS
 * @param v Starting vertex for DFS
 * @param visitedSet Vector of ints containing the visited vertices in order
 * @param discovered Vector of bools denoting which vertices have been visited
*/
void Graph::DFSRecurse(int v, vector<int> &visitedSet, vector<bool> &discovered){
    //add v to the visitedSet vector and set v as discovered
    visitedSet.push_back(v);
    discovered[v] = true;
    //for all neighbors of vertex v, recursively run DFSRecurse on undiscovered neighbors
    for(Edge edge : adjList[v]){
        int adjV = edge.to_vertex;
        if(!discovered[adjV]){
            DFSRecurse(adjV, visitedSet, discovered);
        }
    }
}

/**
 * @brief Depth First Search using recursion on an input vertex
 * @param v Initial vertex to start DFS
 * @return Vector with proper order of DFS
*/
vector<int> Graph::DepthFirstSearch(int v){
    //Initialize vectors visitedSet and discovered for use in DFSRecurse
    vector<int> visitedSet;
    vector<bool> discovered(numVerts, false);
    //Ensure v is a proper vector, and run DFSRecurse on V
    if(v < numVerts && v >= 0){
        DFSRecurse(v, visitedSet, discovered);
    }
    return visitedSet;
}


/**
 * @brief Depth First Search without recursion on an input vertex
 * @param v Initial vertex to start DFS
 * @return Vector with proper order of DFS
*/
/*
vector<int> Graph::DepthFirstSearch(int v){
    //try rewriting recursively?
    vector<int> visitedSet;
    if(v < numVerts && v >= 0){
        stack<int> vertexStack; 
        //add a vector of bools to vector<bool> visitedSet(false, numVerts);
        vertexStack.push(v);

        while(!vertexStack.empty()){
            int cur = vertexStack.top();
            vertexStack.pop();
            bool found = false;
            //can then check visitedSet[cur] for true or false rather than looping
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
    }
    return visitedSet;
}*/

/**
 * @brief Breadth First Search on an input vertex
 * @param v Initial vertex to start BFS
 * @return Vector with proper order of BFS
*/
vector<int> Graph::BreadthFirstSearch(int v){
    //initialize vector for list of visited vertices in order
    vector<int> visitedList;
    //Ensure v is a proper vertex
    if(v < numVerts && v >= 0){
        //initialize queue and discovered vector to use in BFS
        queue<int> frontierQueue;
        vector<bool> discoveredSet(numVerts, false);
        //push v to queue and mark v as discovered
        frontierQueue.push(v);
        discoveredSet[v] = true;
        //while queue is not empty, pop the front element and add it to visitedList
        while(!frontierQueue.empty()){
            int cur = frontierQueue.front();
            frontierQueue.pop();
            visitedList.push_back(cur);
            //for each neighbor of the front of the queue, push all undiscovered neighbors to the
            //queue and mark them as discovered
            for(Edge edge : adjList[cur]){
                int adjV = edge.to_vertex;
                if(!discoveredSet[adjV]){
                    frontierQueue.push(adjV);
                    discoveredSet[adjV] = true;
                }
            }
        }
    }
    return visitedList;
}

/**
 * @brief Check if the graph has cycles
 * @return True if the graph has cycles
 */
bool Graph::checkCycle(){
    //initialize visited vector to track visited vertices
    vector<bool> visited(numVerts, false);
    //for all vertices in the graph, recursively check them for cycles while they are unvisited
    for(int i=0; i<numVerts; i++){
        if(!visited[i]){
            if(checkCycleHelper(i, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Recursive helper function for check cycle
 * @param v initial vertex to check for cycles
 * @param visited vector of bools to track visited vertices
 * @param parent the parent of vertex v
 * @return True if a cycle is found
*/
bool Graph::checkCycleHelper(int v, vector<bool> &visited, int parent){
    //Mark v as visited
    visited[v] = true;
    //For all neighbors of v, recursively check for cycle if neighbor is unvisited
    for(Edge edge : adjList[v]){
        if(!visited[edge.to_vertex]){
            if(checkCycleHelper(edge.to_vertex, visited, v)){
                return true;
            }
        }
        //if a neighbor is visited, and it is not the parent, this indicates a cycle exists
        else if(edge.to_vertex != parent){
            return true;
        }
    }
    return false;
}

/**
 * @brief print the graph
*/
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
