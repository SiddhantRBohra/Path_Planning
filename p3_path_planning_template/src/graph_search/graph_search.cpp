#include <iostream>
#include <cmath>
#include <queue>
#include <functional>

#include <path_planning/utils/math_helpers.h>
#include <path_planning/utils/graph_utils.h>

#include <path_planning/graph_search/graph_search.h>

/**
 * General graph search instructions:
 *
 * First, define the correct data type to keep track of your visited cells
 * and add the start cell to it. If you need to initialize any properties
 * of the start cell, do that too.
 *
 * Next, implement the graph search function. Save the result in the path
 * variable defined for you.
 *
 * To visualize which cells are visited in the navigation webapp, save each
 * visited cell in the vector in the graph struct as follows:
 *      graph.visited_cells.push_back(c);
 * where c is a Cell struct corresponding to the visited cell you want to
 * visualize.
 *
 * The tracePath() function will return a path (which you should assign to
 * the path variable above) given the goal index, if you have kept track
 * of the parent of each node correctly and have implemented the
 * getParent() function. If you do not find a path, return an empty path
 * vector.
*/

std::vector<Cell> depthFirstSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);

    // *** Task: Implement this function if completing the advanced extensions *** //

    // *** End student code *** //

    return path;
}

std::vector<Cell> breadthFirstSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.
    int start_idx = cellToIdx(start.i, start.j, graph);
    int goal_idx = cellToIdx(goal.i, goal.j, graph);
    initGraph(graph); // Make sure all the node values are reset.
    std::queue<int> visit_queue;
    visit_queue.push(start_idx);
    graph.nodes[start_idx].visited = false;
    graph.nodes[start_idx].distance = 0;
    graph.nodes[start_idx].parent = -1;

    while(!visit_queue.empty()) {
        int curr = visit_queue.front();
        visit_queue.pop();

        
        if (curr == goal_idx) {
            std::cout << "goal index: " << curr << std::endl;
            path = tracePath(curr, graph);
            return path;
        }

        if (graph.nodes[curr].visited != true) {
            graph.nodes[curr].visited = true;
        } else {
            continue;
        }
        
        std::vector<int> neighbours = findNeighbors(curr, graph);

        for (int i = 0; i < neighbours.size(); i++) {
            int neighbour = neighbours[i];
            // std::cout << graph.nodes[neighbour].i << ", " << graph.nodes[neighbour].j << std::endl;
            if ((graph.nodes[neighbour].visited == false) && (checkCollision(neighbour, graph) == false)) {
                visit_queue.push(neighbour);
                Cell neighbour_coords = idxToCell(neighbour, graph);
                Cell current_coords = idxToCell(curr, graph);
                int edge_cost = sqrt(pow(neighbour_coords.i - current_coords.i, 2) + pow(neighbour_coords.j - current_coords.j, 2));
                if ((graph.nodes[curr].distance + edge_cost) < (graph.nodes[neighbour].distance)) {
                    graph.nodes[neighbour].distance = graph.nodes[curr].distance + edge_cost;
                    graph.nodes[neighbour].parent = curr;
                }
            } 
        }
    }

    return path;
}

std::vector<Cell> iterativeDeepeningSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);

    // *** Task: Implement this function if completing the advanced extensions *** //

    // *** End student code *** //

    return path;
}

std::vector<Cell> aStarSearch(GridGraph &graph, const Cell &start, const Cell &goal)
{
    std::vector<Cell> path; // The final path should be placed here.

    initGraph(graph); // Make sure all the node values are reset.

    int start_idx = cellToIdx(start.i, start.j, graph);

    // *** Task: Implement this function if completing the advanced extensions *** //

    // *** End student code *** //

    return path;
}