#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#define SIZE 15
#define VERYBIGINT 1000000

using namespace std;

class Graph {
private:
    int matrix[SIZE][SIZE]; // матрица смежности
    string name[SIZE]; // хранилище имён
    int nameCount; // количество добавленных имён

    bool edgeExists(int v1, int v2);
    bool vertexExists(string gname);

public:
    Graph();
    string getName(int index) const;
    int getIndexOfName(string gname) const;
    void addName(string gname);
    void addEdge(int v1, int v2, int weight);
    void all_pairs_within_three_edges(); // based on Floyd-Warshall's algorithm
    friend ostream& operator<<(ostream& os, const Graph& gr);
};