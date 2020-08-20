#include <iostream>
#include <limits.h>
#define VERTEX 7

using namespace std;

//to calculate minimum distance
int minDistance(int distArray[], bool shortPth[])
{
//minimum
int minimum = INT_MAX, minIndex;

// v are vertices
for (int v = 0; v < VERTEX; v++)

//check for short path
if (shortPth[v] == false && distArray[v] <= minimum)
minimum = distArray[v], minIndex = v;

return minIndex;
}

void dijkstra(int graphArr[VERTEX][VERTEX], int source)
{
int distArray[VERTEX];

bool shortPth[VERTEX];
for (int i = 0; i < VERTEX; i++)
distArray[i] = INT_MAX, shortPth[i] = false;
distArray[source] = 0;


for (int count = 0; count < VERTEX - 1; count++) {
int u = minDistance(distArray, shortPth);

shortPth[u] = true;

for (int v = 0; v < VERTEX; v++)


if (!shortPth[v] && graphArr[u][v] && distArray[u] != INT_MAX
&& distArray[u] + graphArr[u][v] < distArray[v])
distArray[v] = distArray[u] + graphArr[u][v];
}
cout<<"Vertex"<< "\t"<< "Distance from source"<<"\n";
for (int i = 0; i < VERTEX; i++)
cout<<i<< "\t"<< distArray[i]<<"\n";

}
int main()
{
int graphArr[VERTEX][VERTEX] ={
{ 0, 1, 0, 0, 0, 0, 0},
{ 0, 0, 1, 1, 0, 1, 1},
{ 0, 0, 0, 1, 0, 0, 0 },
{ 0, 0, 0, 0, 1, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 },
{ 0, 0, 0, 0, 0, 0, 0 }, };

dijkstra(graphArr, 0);

return 0;
}
