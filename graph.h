#pragma once
#include <iostream>
#include <string>
#define SIZE 10

class Graph {
public:
    Graph();

    void addVertex(std::string name);
    void addEdge(std::string vi, std::string v2, int weight = 1);
    void delVertex(std::string name);
    void delEdge(int v1, int v2);
    int findMinWayDFS(int from, int to);
    void inner(int current, int to, bool visited[], int& min, int currentDistance);
    void show_vertex(int i);
    void width(int start);
    size_t find_i_by_name(std::string name);
    std::string find_name_by_i(int i);

private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(std::string v);

    int matrix[SIZE][SIZE];

    std::string vertexes[SIZE];
    int vertexCount;
};