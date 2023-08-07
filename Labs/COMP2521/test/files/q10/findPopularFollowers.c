
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

bool dfs(Graph g, int v, int *visited, int src);
bool depthFirstSearch(Graph g, int src);

// Worst case time complexity of this solution: O(...)
void findPopularFollowers(Graph g, int src, int followers[]) {
	// TODO
	int i = 0;
	while (i < g->nV) {
		if (depthFirstSearch(g, src)) {
		}
		if (g->edges[i][src]) {
			followers[i] = 1;
		}
		i++;
	}
	followers[src] = 1;
}

bool depthFirstSearch(Graph g, int src) {
	int *visited = calloc(g->nV, sizeof(int));
	bool is_reachable = dfs(g, 0, visited, src);
	free(visited);
	return is_reachable;
}

bool dfs(Graph g, int v, int *visited, int src) {
	visited[v] = 1;
	if (visited[src] == 1) {
		return true;
	}
	for (int w = 0; w < g->nV; w++) {
		if (GraphIsAdjacent(g, v, w) && !visited[w]) {
			dfs(g, w, visited, src);
		}
	}
	return false;
}


