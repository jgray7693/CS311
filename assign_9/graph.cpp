#include "graph.h"

/**
 * @brief Construct a Graph with the given number of cities
 * @param nC The number of cities in the graph..
*/
Graph::Graph(int nC){
    //set member variable numCities to input NV
    numCities = nC;
    //create numCities new cities, and push them to the cities vector
    //additionally, fill adjList road vector for each city
    for (int i=0; i<numCities; i++){
        City x(i);
        cities.push_back(x);
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
    //push the new city to the cities vector
    cities.push_back(c);
    //create a new Road for the newly added city, and push it to the adjList vector
    vector<Road> x;
    adjList.push_back(x);
    //increment numCities
    numCities++;
}

/**
 * @brief Add a directed road c1->c2 to the graph
 * @param road The road to be added
*/
void Graph::addDirectedRoad(Road road){
    //check that from_city and to_city are valid cities
    if(road.from_city < numCities && road.to_city < numCities && road.from_city >=0 && road.to_city >= 0){
        //add the road to the adjList for its starting city
        adjList[road.from_city].push_back(road);
    }    
}

/**
 * @brief Print standardized output from one city to another
 * @param c1 Starting city
 * @param c2 Destination city
*/
void Graph::printCities(int c1, int c2){
    //first verify djikstras algorithm is proper, if it is not print no destination, if it is
    //print all this stuff
    cout << "From City: " << cities[c1].name << ", population " << cities[c1].population 
        << ", elevation " << cities[c1].elevation << endl;
    cout << "To City: " << cities[c2].name << ", population " << cities[c2].population 
        << ", elevation " << cities[c2].elevation << endl;
    //call dijkstrasPath to calculate distance and path 
    dijkstrasPath(c1, c2);
}

/**
 * @brief Find shortest path from city c1 to city c2 and print results if path exists
 * @param c1 Starting city
 * @param c2 Destination city
*/
void Graph::dijkstrasPath(int c1, int c2){
    //initialize STL priority queue. Implement PQ using a min heap and pairs as nodes. The pair is implemented as <distance, city id>
    //using distance as the priority value
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //initialize a visited vector, to keep track of cities already visited
    vector<bool> visited(numCities, false);
    //initialize previous vector, to keep track of the previous city visited. Will be used to determine the path to the destination
    vector<int> previous(numCities, -1);
    //initialize distance vector, to keep track of the distance to all adjacent cities
    vector<int> distance(numCities, 99999);

    //set distance of starting city to 0, and add it to the priority queue
    distance[c1] = 0;
    pq.push({0, c1});
    
    //while the priority queue has cities in it:
    while(!pq.empty()){
        //remove the city with the lowest distance from the priority queue and mark it as visited
        int c = pq.top().second;
        pq.pop();
        visited[c] = true;
        //for every outgoing road from the city, if its destination city is unvisited:
        for(Road road : adjList[c]){
            if(!visited[road.to_city]){
                //calculate the distance to the destination city
                int tempDistance = distance[c] + road.weight;
                //if the distance to the destination city through this path is less than through any previous path:
                if(tempDistance < distance[road.to_city]){
                    //update the previous vector with the current city
                    previous[road.to_city] = c;
                    //update the distance vector for the destination city
                    distance[road.to_city] = tempDistance;
                    //add the city to the priority queue with its current attributed
                    pq.push({tempDistance, road.to_city});
                }
            }
        }
    }
    //All shortest paths to all cities has been calculated, and all distances and previous vectors are finalized.
    //if the previous value for the destination city is still -1, it means there is no path to that city from the starting city.
    if(previous[c2] == -1){
        //print out a statement describing that there is no path from the start city to the destination city
        cout << "No route from " << cities[c1].name << " to " << cities[c2].name << "\n\n";
    }
    else{
        //otherwise, print out the distance to the destination city using the destination vector value
        cout << "The shortest distance from " << cities[c1].name << " to " << cities[c2].name <<
            " is " << distance[c2] << endl;
        //initialize a stack (LIFO) so that we can backtrack from the destination city to the starting city
        stack<int> stack;
        //push the destination city to the stack
        stack.push(c2);
        //assign last to the previous city from the shortest path
        int last = previous[c2];
        //loop until the starting city is reached (last will == -1 at the starting city)
        while(last != -1){
            //push each city along the path to the stack, and update last for each previous city
            stack.push(last);
            last = previous[last];
        }
        cout << "through the route: ";
        //while the stack still has cities
        while(stack.top() != c2){
            //print out each city, beginning with the starting city and ending at the destination city as well as an arrow
            cout << cities[stack.top()].name << "->";
            stack.pop();
        }
        //print the final, destination city, remaining in the stack with no arrow
        cout << cities[stack.top()].name << "\n\n";
    }
}
