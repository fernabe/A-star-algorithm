#include <iostream>
#include <vector>

#include "node.h"
#include "path.h"

int main()
{   
    constexpr int MAZE_SIZE{10};

    std::vector<std::vector<int>> maze;
    for(size_t i = 0; i < MAZE_SIZE ; i++)
    {
        std::vector<int> vec;
        for(size_t j = 0; j < MAZE_SIZE ; j++)
        {
            int n = rand()%(1 - 0 + 1);
            vec.push_back(n);
           
        }
        maze.push_back(vec);
    }
    
    Node *start = new Node(nullptr, 0, 0);
    Node *end = new Node(nullptr, 1, 5);

    Path path{maze, start, end};
    path.CalculatePath();


    return 0;
}