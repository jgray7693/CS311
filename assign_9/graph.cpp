#include "graph.h"

/**
 * @brief Construct a Graph with the given number of vertices
 * @param nV The number of vertices in the graph..
**/
Graph::Graph(int nV){
    //set member variable numVerts to input NV
    numVerts = nV;
    //create numVerts new vertices, and push them to the vertices vector
    //additionally, fill adjList road vector for each city
    for (int i=0; i<numVerts; i++){
        City x(i);
        vertices.push_back(x);
        vector<Road> y;
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
 * @brief Add a city to the graph
 * @param c City to add to the graph
*/
void Graph::addCity(City c){
    //push the new city to the vertices vector
    vertices.push_back(c);
    //create a new Road for the newly added city, and push it to the adjList vector
    vector<Road> x;
    adjList.push_back(x);
    //increment numVerts
    numVerts++;
}

/**
 * @brief Add a directed road v1->v2 to the graph
 * @param v1 Starting city for the directed road
 * @param v2 Terminal city for the directed road
 * @param weight Optional weight cost for the road. If unweighted, defaults to 1
*/
void Graph::addDirectedRoad(int v1, int v2, float weight){
    //check that v1 and v2 are proper vertices
    if(v1 < numVerts && v2 < numVerts && v1 >=0 && v2 >= 0){
        //create a new Road from v1 -> v2 with associated weight, and push to adjList vector
        Road road(v1, v2, weight);
        adjList[v1].push_back(road);
    }    
}

/**
 * @brief Add an undirected (two-way) road v1->v2 and v2->v1 to the graph
 * @param v1 First city for the undirected road
 * @param v2 Second city for the undirected road
 * @param weight Optional weight cost for the road. If unweighted, defaults to 1
*/
void Graph::addUndirectedRoad(int v1, int v2, float weight){
    //check that v1 and v2 are proper vertices
    if(v1 < numVerts && v2 < numVerts && v1 >=0 && v2 >= 0){
        //create a new road from v1 -> v2 and v2 -> v1 with associated weight, and push to adjList vector
        Road road1(v1, v2, weight);
        Road road2(v2, v1, weight);
        adjList[v1].push_back(road1);
        adjList[v2].push_back(road2);
    }
}

/**
 * @brief The number of outgoing roads from a city
 * @param c The desired city to get the number of outgoing roads
 * @return Number of outgoing roads
*/
int Graph::outDegree(int c){
    //Verify c is a proper city
    if(c < numVerts && c >= 0){
        //return the length of the adjList vector for the associated city
        return (int)adjList[c].size();
    }
    //If c is not a proper city, return -1
    return -1;
}

/**
 * @brief Recursive helper function for DFS
 * @param c Starting city for DFS
 * @param visitedSet Vector of ints containing the visited vertices in order
 * @param discovered Vector of bools denoting which vertices have been visited
*/
void Graph::DFSRecurse(int c, vector<int> &visitedSet, vector<bool> &discovered){
    //add c to the visitedSet vector and set c as discovered
    visitedSet.push_back(c);
    discovered[c] = true;
    //for all neighbors of city c, recursively run DFSRecurse on undiscovered neighbors
    for(Road road : adjList[c]){
        int adjV = road.to_city;
        if(!discovered[adjV]){
            DFSRecurse(adjV, visitedSet, discovered);
        }
    }
}

/**
 * @brief Depth First Search using recursion on an input city
 * @param c Initial city to start DFS
 * @return Vector with proper order of DFS
*/
vector<int> Graph::DepthFirstSearch(int c){
    //Initialize vectors visitedSet and discovered for use in DFSRecurse
    vector<int> visitedSet;
    vector<bool> discovered(numVerts, false);
    //Ensure c is a proper vector, and run DFSRecurse on V
    if(c < numVerts && c >= 0){
        DFSRecurse(c, visitedSet, discovered);
    }
    return visitedSet;
}


/**
 * @brief Depth First Search without recursion on an input city
 * @param c Initial city to start DFS
 * @return Vector with proper order of DFS
*/
/*
vector<int> Graph::DepthFirstSearch(int c){
    //try rewriting recursively?
    vector<int> visitedSet;
    if(c < numVerts && c >= 0){
        stack<int> cityStack; 
        //add a vector of bools to vector<bool> visitedSet(false, numVerts);
        cityStack.push(c);

        while(!cityStack.empty()){
            int cur = cityStack.top();
            cityStack.pop();
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
                for(vector<Road>::reverse_iterator i = adjList[cur].rbegin(); i != adjList[cur].rend(); ++i ){
                    int adjV = i->to_city;
                    cityStack.push(adjV);
                }
            }
        }
    }
    return visitedSet;
}*/

/**
 * @brief Breadth First Search on an input city
 * @param c Initial city to start BFS
 * @return Vector with proper order of BFS
*/
vector<int> Graph::BreadthFirstSearch(int c){
    //initialize vector for list of visited vertices in order
    vector<int> visitedList;
    //Ensure c is a proper city
    if(c < numVerts && c >= 0){
        //initialize queue and discovered vector to use in BFS
        queue<int> frontierQueue;
        vector<bool> discoveredSet(numVerts, false);
        //push c to queue and mark c as discovered
        frontierQueue.push(c);
        discoveredSet[c] = true;
        //while queue is not empty, pop the front element and add it to visitedList
        while(!frontierQueue.empty()){
            int cur = frontierQueue.front();
            frontierQueue.pop();
            visitedList.push_back(cur);
            //for each neighbor of the front of the queue, push all undiscovered neighbors to the
            //queue and mark them as discovered
            for(Road road : adjList[cur]){
                int adjV = road.to_city;
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
 * @param c initial city to check for cycles
 * @param visited vector of bools to track visited vertices
 * @param parent the parent of city c
 * @return True if a cycle is found
*/
bool Graph::checkCycleHelper(int c, vector<bool> &visited, int parent){
    //Mark c as visited
    visited[c] = true;
    //For all neighbors of c, recursively check for cycle if neighbor is unvisited
    for(Road road : adjList[c]){
        if(!visited[road.to_city]){
            if(checkCycleHelper(road.to_city, visited, c)){
                return true;
            }
        }
        //if a neighbor is visited, and it is not the parent, this indicates a cycle exists
        else if(road.to_city != parent){
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
            cout << j->to_city << " " ;
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::printCities(int v1, int v2){
    //first verify djikstras algorithm is proper, if it is not print no destination, if it is
    //print all this stuff
    cout << "From City: " << vertices[v1].name << ", population " << vertices[v1].population 
        << ", elevation " << vertices[v1].elevation << endl;
    cout << "To City: " << vertices[v2].name << ", population " << vertices[v2].population 
        << ", elevation " << vertices[v2].elevation << endl;
    cout << "The shortest distance from " << vertices[v1].name << " to " << vertices[v2].name <<
        " is " << "NOW INSERT DJIKSTRAS ALGO HERE AND CALCULATE DISTANCE AND PATH\n\n";
}
