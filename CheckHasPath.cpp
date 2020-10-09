#include<bits/stdc++.h>
using namespace std;

bool hasPath(int **edges, int n, int sv, int ev) {
	if(sv== ev) {
		return true;
	}
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	queue<int> pendingVertices;
	pendingVertices.push(sv);
	visited[sv] = true;
	while(!pendingVertices.empty()) {
		int currentVertex = pendingVertices.front();
		pendingVertices.pop();
		for(int i=0;i<n;i++) {
			if(edges[currentVertex][i] == 1 && !visited[i]) {
				if(i == ev) {
					return true;
				}
				pendingVertices.push(i);
				visited[i] = true;
			}
		}
	}
	return false;
}

int main() {
	int n, e;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	int **edges = new int *[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cin>>f>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	int sv, ev;
	cout<<"Enter the starting vertex: ";
	cin>>sv;
	cout<<"Enter the ending vertex: ";
	cin>>ev;
	bool ans = hasPath(edges, n, sv, ev);
	if(ans) {
		cout<<"Yes";
	} else {
		cout<<"No";
	}
	for(int i=0;i<n;i++) {
		delete[] edges[i];
	}
	delete[]edges;
	return 0;
}
