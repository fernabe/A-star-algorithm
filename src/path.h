#ifndef PATH__H
#define PATH_H

#include <iostream>
#include <vector>

#include "node.h"

class Node;
class Path
{
    private:

        // directional deltas
        const int delta[4][2]{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        std::vector<Node*> open_list;
        std::vector<Node*> closed_list;
        std::vector<std::vector<int>> maze;
        Node *start_node{nullptr};
        Node *end_node{nullptr};
        void SortOpenList();
        void CheckNeighbors(Node *current);
        
        bool CheckValidNeighbor(int x, int y);
        bool CheckOpenList(int x, int y, Node *current);
        bool CheckClosedList(int x, int y);
        void PrintPath(Node *end_node);

    public:
        Path(std::vector<std::vector<int>> maze, Node *start, Node *end);
        ~Path(){
            for( auto &node : open_list)
                {
                    delete node;
                }

                for( auto &node : closed_list)
                {
                    delete node;
                }
        };
        void CalculatePath();
};

#endif
