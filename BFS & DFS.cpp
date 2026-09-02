#include <iostream>
#include <queue>
using namespace std;

class Graph
{
int adj[20][20];
int n;
bool visited[20] = {false};

public:
void createGraph()
{
cout << "Enter number of vertices: ";
cin >> n;


for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
adj[i][j] = 0;
}
}


int edges;
cout << "Enter number of edges: ";
cin >> edges;

cout << "Enter edges (source destination):\n";

for (int i = 0; i < edges; i++)
{
int u, v;
cin >> u >> v;

adj[u][v] = 1;
adj[v][u] = 1;
 }
}

void displayMatrix()
{
cout << "\nAdjacency Matrix:\n";

for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
{
cout << adj[i][j] << " ";
}
cout << endl;
}
}


void DFS(int start)
{
visited[start] = true;

cout << start << " ";

for (int i = 0; i < n; i++)
{
if (adj[start][i] == 1 && !visited[i])
{
DFS(i);
}
}
}


void BFS(int start)
{

bool bfsVisited[20] = {false};
queue<int> q;

bfsVisited[start] = true;
q.push(start);

cout << "BFS Traversal: ";
while (!q.empty())
{
int curr = q.front();
q.pop();
cout << curr << " ";

for (int i = 0; i < n; i++)
{
if (adj[curr][i] == 1 && !bfsVisited[i])
{
bfsVisited[i] = true;
q.push(i);
}
}
}
cout << endl;
}
};

int main()
{
Graph g;
int choice, start;
do
{
cout << "\n===== Graph Menu =====";
cout << "\n1. Create a Graph";
cout << "\n2. Display Graph (Adjacency matrix)";
cout << "\n3. DFS traversal";
cout << "\n4. BFS traversal";
cout << "\n5. Exit";
cout << "\nEnter your choice: ";
cin >> choice;

switch (choice)
{
case 1:
g.createGraph();
break;

case 2:
g.displayMatrix();
break;

case 3:
cout << "\nEnter starting vertex: ";
cin >> start;
cout << "DFS Traversal: ";
g.DFS(start);
cout << endl;
break;

case 4:
cout << "\nEnter starting vertex: ";
cin >> start;
g.BFS(start);
break;

case 5:
cout << "Program Exited.";
break;

default:
cout << "Invalid Choice!";
}

} while (choice != 5);

return 0;
}
