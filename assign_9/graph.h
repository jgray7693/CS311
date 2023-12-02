//CS311 Assignment 9
//Members: Jason Gray, Jacob Zacharia, Gavin Rosander
//Directed, weighted Graph class with a City struct for vertices and Road struct for edges - header file template

#pragma once
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

/**
 * @brief City struct. It represents a location connected by roads.
 */
struct City{
    int id; //The index of the city starting from 0
    string code; //The city code.
    string name; //The name of the city. Additional attributes can be added
    int population; //The city population.
    int elevation; //The city elevation.

    /**
     * @brief City constructor containing all parameters
    */
    City(int id = 0, string code = "", string name="", int population = 0, int elevation = 0){
        this->id = id;
        this->code = code;
        this->name = name;
        this->population = population;
        this->elevation = elevation;
    }

    //This overloads cout for the City class
    //This is a friend function
    friend ostream &operator<<(ostream & os, const City& city){
        os << city.id << " " << city.code << " " << city.name << " " << city.population 
            << " " << city.elevation;
        return os;  
    }

    //This overloads cin for the City class
    //This is a friend function
    friend istream &operator>>(istream & is, City& city){
        is >> city.id >> city.code >> city.name >> city.population >> city.elevation;
        return is; 
    }
};

/**
 * @brief Road struct. It represents a road from one city to another.
 */
struct Road{
    int from_city; // The index of the city where the road starts
    int to_city; // The index of the city where the road ends.
    int weight; // The weight of the road.

    /**
     * @brief Road Constructor containing all parameters
    */
    Road(int from_city = 0, int to_city = 0, int weight = 0){
        this->from_city = from_city;
        this->to_city = to_city;
        this->weight = weight;
    }

    //This overloads cout for the Road object
    //This is a friend function 
    friend ostream &operator<<(ostream & os, const Road & road){
        os << road.from_city << " " << road.to_city << " " << road.weight;
        return os;  
    }

    //This overloads cin for the Road object
    //This is a friend function
    friend istream &operator>>(istream & is, Road & road){
        is >> road.from_city >> road.to_city >> road.weight;
        return is; 
    }
};

/**
 * @brief Graph class
 */
class Graph{
public:
    int numCities;    // No. of cities
    vector<City> cities; // The list of cities
    vector<vector<Road>> adjList; // The adjacency list

    // Default constructor. Create an empty graph
    Graph(){
        numCities = 0;
    }

    // Constructor. Create a graph with n cities
    Graph(int n);

    // Destructor
    ~Graph();

    /**
     * @brief Add a city to the graph
     * @param c The city to be added
     */
    void addCity(City c);

    /**
     * @brief Add a directed road from c1 to c2 to the graph
     * @param c1 The index of the city where the road starts
     * @param c2 The index of the city where the road ends
     * @param weight The weight of the road
     */
    void addDirectedRoad(int c1, int c2, int weight = 1);

    /**
     * @brief Print standardized output from one city to another
     * @param c1 Starting city
     * @param c2 Destination city
    */
    void printCities(int c1, int c2);

    void dijkstrasPath(int c1, int c2);

};