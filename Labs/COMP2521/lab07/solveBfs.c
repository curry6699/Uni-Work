// BFS maze solver

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cell.h"
#include "helpers.h"
#include "Maze.h"
#include "Queue.h"

bool solve(Maze m) {
    // TODO: Complete this function
    // Feel free to add helper functions


    Cell c = MazeGetStart(m);
    int height = MazeHeight(m);
    int width = MazeWidth(m);


    Cell **visited = createCellMatrix(height, width);




    Queue q = QueueNew();
    QueueEnqueue(q, c);
    visited[c.col][c.row] = 1;

    while(!QueueIsEmpty(q)) {
        Cell front = QueueDequeue(q);
        for (c.row = 0; c.row < height; c.row++) {
            for (c.col = 0; c.col < width; c.col++) {
                Cell temp = {c.row, c.col};
                if (temp && !visited[temp]) {
                    visited[temp] = 1;
                    QueueEnqueue(q, c.col);
                }
                bool found = MazeVisit(m, c);
                if (found) {
                    return true;
                }
            }
            QueueEnqueue(q, c.row);
        }
    }
    return false;


    // Cell c = MazeGetStart(Maze m);
    
    // bool found = false

    // Queue q = QueueNew();
    // QueueEnqueue(q, c);

    // while (!found) {
    //     found = MazeVisit(m, Cell c);
    //     if (found) {
    //     }
    //     else {
    //         for (c.col = 0, c.col < width; c.col++;) {
    //             if (!MazeIsWall(m, c) && visited[c.row][c.col].col == 0 &&
    //             visited[c.row][c.col].row == 0 && isAdj)
    //         }
    //     }

    // }
    
    
    
    //Cell y = {x.row, x.col + 1};
    


    // Cell x = MazeGetStart(Maze m);
    // Cell y = {x.row, x.col + 1};

    // bool is_wall;
    // is_wall = MazeIsWall(m, y);

    // if (is_wall) {
    //     Cell y = {x.row, x.col + 1};
    // }

    // bool is_exit;
    // is_exit = MazeVisit(m, y);

    // if (is_exit) {
    //     MazeMarkPath(m, y);
    // }

    // Cell x = MazeGetStart(Maze m);
    // Cell y = {x.row, x.col + 1};
    // int height = MazeHeight(m);
    // int width = MazeWidth(m);

    // while (x.col < width) {
    //     bool is_wall;
    //     is_wall = MazeIsWall(m, y);

    //     if (is_wall == false) {
            
    //     }
    //     else {
    //         y = {x.row, x.col + 1};
    //     }


    // }





    return false;
}

