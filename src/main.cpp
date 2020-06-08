#include <iostream>
#include <vector>
#include <random>

#include "node.h"
#include "path.h"


bool CheckPoint(int x, int y, const std::vector<std::vector<int>> &maze)
{
    return maze.at(x).at(y) == 0;
}


int main()
{   
    constexpr int MAZE_SIZE{25};
    const double PROBABILITY_ZERO{0.8};

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> probability_dist({ PROBABILITY_ZERO, 1 -  PROBABILITY_ZERO });
  
    std::vector<std::vector<int>> maze;
    for(size_t i = 0; i < MAZE_SIZE ; i++)
    {
        std::vector<int> vec;
        for(size_t j = 0; j < MAZE_SIZE ; j++)
        {
            vec.push_back(probability_dist(gen));
        }
        maze.push_back(vec);
    }

    std::uniform_int_distribution<std::mt19937::result_type> dist(0,MAZE_SIZE - 1);

    int start_x;
    int start_y;
    bool valid_point{false};

    while (!valid_point)
    {
        start_x = dist(gen);
        start_y = dist(gen);
        valid_point = CheckPoint(start_x, start_y, maze);
    }  

    valid_point = false;
    int end_x;
    int end_y;

    while (!valid_point)
    {
        end_x = dist(gen);
        end_y = dist(gen);
        valid_point = CheckPoint( start_x, start_y, maze);
    }

    std::cout << std::endl << std::endl;

    std::cout << "Initial Point: " << start_x << " - " << start_y << std::endl;
    std::cout << "End Point: " << end_x << " - " << end_y << std::endl;

    std::cout << std::endl << std::endl;

    Node *start = new Node(nullptr, start_x, start_y);
    Node *end = new Node(nullptr, end_x, end_y);

    Path path{maze, start, end};
    path.CalculatePath();
    
    return 0;
}