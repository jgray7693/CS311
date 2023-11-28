#include "graph.h"
#include <iostream>
#include <fstream>
//#include <cstring>
//#include <ctime>

using namespace std;

int main(int argc, char *argv[]){

    /*CString strTime;
    CTime date;
    date = GetCurrentTime();
    strTime = date.Format(_T("%m/%d/%Y"));
    */
    if(argc != 3){
        cout << "Invalid city arguments.\n";
        cout << "Usage:\t./prog9 [From_City code] [To_City code]\n\n";
        return 0;
    }

    cout << "Author: Jason Gray, Jacob Zacharia, Gavin Rosander\n";
    cout << "Date: \n"; //include date MM/DD/YYYY
    cout << "Course: CS311 (Data Structures and Algorithms)\n";
    cout << "Description: Program to find the shortest route between cities\n";
    cout << "----------------------------------------------------------------\n";
    ifstream fin;
	fin.open("city.txt");
	if (!fin.good()) throw "I/O error";
    Graph graph;
	while(true) {
        Vertex vertex;
        if(fin >> vertex){
            graph.addVertex(vertex);
        }
		else{
            break;
        }
	}
    fin.close();
    fin.open("road.txt");
    while(true){
        Edge edge;
        if(fin >> edge){
            graph.addDirectedEdge(edge.from_vertex, edge.to_vertex, edge.weight);
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
    bool valid = false;

    for(int i=0; i<graph.numVerts; i++){
        if(graph.vertices[i].code == s1){
            from_city = i;
        }
        if(graph.vertices[i].code == s2){
            to_city = i;
        }
        if(from_city > -1 && to_city > -1){
            valid = true;
            break;
        }
    }
    if(valid && from_city != to_city){
        graph.printCities(from_city, to_city);
    }
    else if(!valid){
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