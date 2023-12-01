#include "graph.h"

/**
 * @brief Construct a Graph with the given number of cities
 * @param nC The number of cities in the graph..
**/
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
 * @param c1 Starting city for the directed road
 * @param c2 Terminal city for the directed road
 * @param weight Optional weight cost for the road. If unweighted, defaults to 1
*/
void Graph::addDirectedRoad(int c1, int c2, int weight){
    //check that c1 and c2 are proper cities
    if(c1 < numCities && c2 < numCities && c1 >=0 && c2 >= 0){
        //create a new Road from c1 -> c2 with associated weight, and push to adjList vector
        Road road(c1, c2, weight);
        adjList[c1].push_back(road);
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
    cout << "The shortest distance from " << cities[c1].name << " to " << cities[c2].name <<
        " is " << "NOW INSERT DJIKSTRAS ALGO HERE AND CALCULATE DISTANCE AND PATH\n\n";
}
