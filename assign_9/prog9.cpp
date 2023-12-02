#include "graph.h"
#include <fstream>
#include <ctime>

//using namespace std;

int main(int argc, char *argv[]){

    std::time_t currentTime = std::time(nullptr);

    // Convert the current time to a local time struct
    std::tm* localTime = std::localtime(&currentTime);
    int year = localTime->tm_year + 1900; // Years since 1900
    int month = localTime->tm_mon + 1;    // Months start from 0
    int day = localTime->tm_mday;
    if(argc != 3){
        cout << "Invalid city arguments.\n";
        cout << "Usage:\t./prog9 [From_City code] [To_City code]\n\n";
        return 0;
    }

    cout << "Author: Jason Gray, Jacob Zacharia, Gavin Rosander\n";
    cout << "Date: " << month << "/" << day << "/" << year << endl; //include date MM/DD/YYYY
    cout << "Course: CS311 (Data Structures and Algorithms)\n";
    cout << "Description: Program to find the shortest route between cities\n";
    cout << "----------------------------------------------------------------\n";
    ifstream fin;
	fin.open("city.txt");
	if (!fin.good()) throw "I/O error";
    Graph graph;
	while(true) {
        City city;
        if(fin >> city){
            graph.addCity(city);
        }
		else{
            break;
        }
	}
    fin.close();
    fin.open("road.txt");
    while(true){
        Road road;
        if(fin >> road){
            graph.addDirectedRoad(road.from_city, road.to_city, road.weight);
        }
        else{
            break;
        }
    }
    fin.close();

    int from_city = -1;
    int to_city = -1;
    string s1 = argv[1];
    string s2 = argv[2];
    bool validCities = false;

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
    if(validCities && from_city != to_city){
        graph.printCities(from_city, to_city);
    }
    else if(!validCities){
        if(from_city == -1){
            cout << "Invalid city code: " << s1 << endl << endl;
        }
        if(to_city == -1){
            cout << "Invalid city code: " << s2 << endl << endl;
        }
        return 0;
    }
    else{
        cout << "From City and To City are the same location\nPlease enter different locations.\n\n";
    }

    return 0;

}