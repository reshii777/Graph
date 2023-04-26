#include "graph.h"
#include <stdlib.h>          // size_t

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}

void Graph::addVertex(std::string name)
{
    vertexes[vertexCount] = name;
    vertexCount++;
}

void Graph::addEdge(std::string name1, std::string name2, int weight)
{
    if (vertexExists(name1) || (vertexExists(name2))) {

        int v1 = find_i_by_name(name1);
        int v2 = find_i_by_name(name2);
        matrix[v1][v2] = weight;
        matrix[v2][v1] = weight;
    }

}

bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}

bool Graph::vertexExists(std::string name)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == name)
            return true;
    return false;
}

size_t Graph::find_i_by_name(std::string name)
{
    //int foundindex = -1;
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == name)
            return i;

}

void Graph::delVertex(std::string name)
{
    if (vertexExists(name)) {

        int j = find_i_by_name(name);

        for (int i = 0; i < SIZE; i++)
        {
            matrix[i][j] = 0;
            matrix[j][i] = 0;
        }

        // int foundIndex = -1;
       //  for (int i = 0;i < vertexCount; i++)
        // {
        //     if (vertexes[i] == name)
        //         foundIndex = i;
        // }

        for (size_t i = j; i < vertexCount; i++)
        {
            vertexes[i] = vertexes[i + 1];
        }
        vertexCount--;
    }
}


void Graph::delEdge(int v1, int v2)
{
    if (edgeExists(v1, v2))
    {
        matrix[v1][v2] = 0;
        matrix[v2][v1] = 0;
    }

}

void Graph::show_vertex(int i)
{
    std::cout << vertexes[i] << " ";
}