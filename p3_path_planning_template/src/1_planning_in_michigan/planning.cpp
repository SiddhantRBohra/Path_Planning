#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

#include "planning.h"


void printPath(std::vector<int>& path, Graph& g) {

    if (path.size() < 1)
    {
        std::cout << "No path found :(\n";
        return;
    }

    std::cout << "Path: ";
    for (int i = 0; i < path.size() - 1; i++)
    {
        std::cout << g.data[path[i]] << " -> ";
    }
    std::cout <<  g.data[path.back()] << "\n";
};

std::vector<int> tracePath(int n, Graph& g) {
    std::vector<int> path;
    int curr = n;
    do {
        path.push_back(curr);
        curr = getParent(curr, g);
    } while (curr != -1);

    // Since we built the path backwards, we need to reverse it.
    std::reverse(path.begin(), path.end());
    return path;
};

std::vector<int> getNeighbors(int n, Graph& g)
{
    return g.edges[n];
}

std::vector<float> getEdgeCosts(int n, Graph& g)
{
    return g.edge_costs[n];
}

int getParent(int n, Graph& g)
{

    return g.nodes[n].parent;
    return -1;

}

void initGraph(Graph& g)
{
    g.nodes.clear();
    for (int i = 0; i < g.data.size(); i++)
    {
        Node n;
        n.city = g.data[i];
        g.nodes.push_back(n);
        n.visited = false;
        n.queued = false;
        n.parent = -1;
        n.distance = 9999;
    }
}

std::vector<int> bfs(int start, int goal, Graph& g)
{
    initGraph(g);
    std::vector<int> path;
    std::queue<int> visit_queue;
    visit_queue.push(start);
    g.nodes[start].visited = true;
    g.nodes[start].queued = true;
    g.nodes[start].parent = -1;
    g.nodes[start].distance = 0;
    
    while (!visit_queue.empty()) {
        int curr = visit_queue.front();
        visit_queue.pop();

        if (curr == goal) {
            path = tracePath(curr, g);
            for (int i = 0; i < path.size(); i++) {
                std::cout << path[i] << std::endl;
            }
            return path;
        }

        std::vector<int> neighbours = getNeighbors(curr, g);
        std::vector<float> edgeCosts = getEdgeCosts(curr, g);

        for (int i = 0; i < neighbours.size(); i++) {
            int neighbour = neighbours[i];
            float cost = edgeCosts[i];
            if (g.nodes[neighbour].queued == false && g.nodes[neighbour].visited == false) {
                visit_queue.push(neighbour);
                g.nodes[neighbour].queued = true;
                if ((g.nodes[curr].distance + cost) < (g.nodes[neighbour].distance)) {
                    g.nodes[neighbour].distance = g.nodes[curr].distance + cost;
                    g.nodes[neighbour].parent = curr;                } 
            }
        }
        g.nodes[curr].visited = true;
    }
}

std::vector<int> dfs(int start, int goal, Graph& g)
{
    initGraph(g);
    std::vector<int> path;

    std::stack<int> visit_stack;

    // *** Task: Implement this function if completing the advanced extension *** //

    // *** End student code *** //

    return path;
}
