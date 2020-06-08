#include "path.h"
#include <algorithm>

Path::Path(std::vector<std::vector<int>> maze, Node *start, Node *end)
    : maze(maze),
      start_node(start),
      end_node(end)
{
    open_list.emplace_back(start_node);
    start_node->SetG(0);
    start_node->SetH(end_node->GetPosX(), end_node->GetPosY());
}

void Path::CalculatePath()
{
    while (open_list.size() > 0)
    {
        SortOpenList();
        Node *current_node = open_list.back();
        open_list.pop_back();
        closed_list.emplace_back(current_node);

        if( *current_node == *end_node)
        {
            // Dibujaremos matriz;
            PrintPath(current_node);
            return;
        }
        CheckNeighbors(current_node);
    }
}

bool Compare(Node *a, Node *b)
{
    return a->GetF() > b->GetF();
}

void Path::SortOpenList()
{
    std::sort(open_list.begin(), open_list.end(), Compare);
}  

void Path::CheckNeighbors(Node *current)
{
    int x = current->GetPosX();
    int y = current->GetPosY();
    
    for(size_t i = 0; i < 4; ++i)
    {
        int neighbor_x = x + delta[i][0];
        int neighbor_y = y + delta[i][1];
    
        if( !CheckValidNeighbor(neighbor_x, neighbor_y) )
            continue;
        
        if( CheckClosedList(neighbor_x, neighbor_y) )
            continue;

        if( !CheckOpenList(neighbor_x, neighbor_y, current) )
        {
            Node *node = new Node(current, neighbor_x, neighbor_y);
            node->SetG(current->GetG()+1);
            node->SetH(end_node->GetPosX(), end_node->GetPosY());
            open_list.emplace_back(node);
        }
    }
}

bool Path::CheckValidNeighbor(int x, int y)
{
    if( x < 0 || x >= maze.size())
        return false;

    if( y < 0 || y >= maze[0].size())
        return false;

    if(maze.at(x).at(y) != 0)
        return false;
    
    return true;
}

bool Path::CheckClosedList(int x, int y)
{
    for(const auto &node : closed_list)
    {
        if( node->GetPosX() == x && node->GetPosY() ==  y)
            return true;
    }
    return false;
}


bool Path::CheckOpenList(int x, int y, Node *current)
{
    for(const auto &node : open_list)
    {
        if( node->GetPosX() == x && node->GetPosY() ==  y)
        {
            if( current->GetG() + 1 > node->GetG())
            {
                node->SetG(current->GetG() + 1);
                node->SetParent(current);
            }

            return true;
        }
    }
    return false;
}


void Path::PrintPath(Node *end_node)
{
  
    while( end_node->GetParent() != nullptr){
        maze.at(end_node->GetPosX()).at(end_node->GetPosY()) = 2;
        end_node = end_node->GetParent();
    }

    maze.at(end_node->GetPosX()).at(end_node->GetPosY()) = 2;

    for(size_t i = 0; i < maze.size(); ++i)
    {
        for(size_t j = 0; j < maze[i].size(); ++j)
        {
            if( maze.at(i).at(j) == 0)
                std::cout << "." << "\t";
            else if( maze.at(i).at(j) == 1 )
                std::cout << "|" << "\t";
            else
                std::cout << "*" << "\t";
        }
        std::cout << std::endl;
    }
}
