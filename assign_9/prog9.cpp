#include "graph.h"
#include <fstream>
#include <ctime>

//using namespace std;

int main(int argc, char *argv[]){

    //using ctime STL, get the current time
    std::time_t currentTime = std::time(nullptr);
    // Convert the current time to a local time struct
    std::tm* localTime = std::localtime(&currentTime);
    //using local time, get the year, month, and day to print out todays date
    int year = localTime->tm_year + 1900; // Years since 1900
    int month = localTime->tm_mon + 1;    // Months start from 0
    int day = localTime->tm_mday;
    //3 arguments are necessary for program operation: ./prog9 [city code 1] [city code 2]
    //if 3 arguments are not provided, print error code as well as usage statement
    if(argc != 3){
        cout << "Invalid city arguments.\n";
        cout << "Usage:\t./prog9 [From_City code] [To_City code]\n\n";
        return 0;
    }
    //print out standardized project information including group contributor information, todays date, course information, 
    //and program information
    cout << "Author: Jason Gray, Jacob Zacharia, Gavin Rosander\n";
    cout << "Date: " << month << "/" << day << "/" << year << endl; //include date MM/DD/YYYY
    cout << "Course: CS311 (Data Structures and Algorithms)\n";
    cout << "Description: Program to find the shortest route between cities\n";
    cout << "----------------------------------------------------------------\n";

    //initialize file stream object. This will be used to read the input .txt files containing the City list and Roads list
    ifstream fin;
    //open the city text file into filestream
	fin.open("city.txt");
    //if the file does not open properly, throw an error
	if (!fin.good()) throw "I/O error";
    //initialize graph object. This will be used to create the map of all existing cities and roads
    Graph graph;
    //Parse each line of the city text file, creating a new city and adding it to the graph for each line
	while(true) {
        City city;
        if(fin >> city){
            graph.addCity(city);
        }
		else{
            break;
        }
	}
    //close the city.txt file
    fin.close();

    //open the road text file into filestream
    fin.open("road.txt");
    //if the file does not open properly, throw an error
	if (!fin.good()) throw "I/O error";
    //Parse each line of the road text file, creating a new road and adding it to the graph for each road
    while(true){
        Road road;
        if(fin >> road){
            graph.addDirectedRoad(road);
        }
        else{
            break;
        }
    }
    //close the road.txt file
    fin.close();

    //set from_city and to_city to -1, so they are currently invalid city codes
    int from_city = -1;
    int to_city = -1;
    //store the two input city codes into s1 and s2 strings
    string s1 = argv[1];
    string s2 = argv[2];
    //initialize a boolean for tracking if the input cities are valid
    bool validCities = false;
    //loop through all cities in the graph. If the input cities match a city existing on the map, update from_city and to_city with the
    //city codes, and set validCities bool to true;
    for(int i=0; i<graph.numCities; i++){
        if(graph.cities[i].code == s1){
            from_city = i;
        }
        if(graph.cities[i].code == s2){
            to_city = i;
        }
        if(from_city > -1 && to_city > -1){
            validCities = true;
            break;
        }
    }
    //if the input cities are both valid, and they are not the same city, print city information as well as distance and path between them
    if(validCities && from_city != to_city){
        graph.printCities(from_city, to_city);
    }
    //if one or both of the input cities are not valid, print an error message showing the invalid city(ies) code that was input
    else if(!validCities){
        if(from_city == -1){
            cout << "Invalid city code: " << s1 << endl << endl;
        }
        if(to_city == -1){
            cout << "Invalid city code: " << s2 << endl << endl;
        }
    }
    //if the input cities are valid, but they are the same city, print out an error code specifying an input for two different cities
    else{
        cout << "From City and To City are the same location\nPlease enter different locations.\n\n";
    }
    return 0;
}