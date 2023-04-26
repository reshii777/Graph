#include <iostream>
#include "graph.h"
#define VERYBIGINT 1000000000

int Graph::findMinWayDFS(int from, int to)
{
    bool visited[SIZE];
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    int min = VERYBIGINT;
    int currentDistance(0);
    inner(from, to, visited, min, currentDistance);

    return min;
}

void Graph::inner(int current, int to, bool visited[], int& min, int currentDistance)
{

    visited[current] = true;
    if (current == to)
    {

        if (min > currentDistance)
            min = currentDistance;

    }
    else
    {
        // int i = current;                  //для незамкнутого цикла
        for (int i = 0; i < SIZE; i++)
        {

            if (edgeExists(current, i) && !visited[i])
            {
                currentDistance += matrix[current][i];
                inner(i, to, visited, min, currentDistance);
            }

        }
    }

    visited[current] = false;
    currentDistance = 0;


}

