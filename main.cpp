#include <iostream>
#include <locale>
#include "graph.h"

using namespace std;

int main() {

    setlocale(LC_ALL, "ru_RU");

	int min = 5;
	int count(0);

    Graph g;
	g.addVertex("����");
	g.addVertex("������");
	g.addVertex("�����");
	g.addVertex("����");
	g.addVertex("����");

    g.addEdge("����", "������");
    g.addEdge("������", "�����");
    g.addEdge("�����", "����");
    g.addEdge("����", "����");

	for (int i = 0; i < SIZE; i++)
	{
		int j = i + 1;
		for (; j < SIZE; j++)
		{
			int min_f = g.findMinWayDFS(i, j);
			if (min_f <= 3) {
				g.show_vertex(i);
				cout << "  ";
				g.show_vertex(j);
				std::cout << std::endl;
			}
		}
	}
	std::cout << endl;
	std::cout << "Done!";

    return 0;
}
