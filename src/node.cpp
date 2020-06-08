#include <iostream>
#include <node.h>

Node::Node(Node *parent, int x, int y) 
    : parent(parent),
      posx(x), 
      posy(y)
{

}

void Node::SetParent(Node *parent)
{
    this->parent = parent;
}

void Node::SetPosX(int x)
{
    this->posx = x;
}

void Node::SetPosY(int y)
{
    this->posy = y;
}

void Node::SetG(int g)
{
    this->g = g;
}

void Node::SetH(int end_x, int end_y)
{
    this->h = std::abs(end_x - posx) + std::abs(end_y - posy);
}


Node* Node::GetParent()
{ 
    return this->parent;
}

int Node::GetPosX()
{
    return this->posx;
}

int Node::GetPosY()
{
    return this->posy;
}

int Node::GetG()
{
    return this->g;
}

int Node::GetH()
{
    return this->h;
}

int Node::GetF()
{
    return this->g + this->h;
}

bool Node::operator<(const Node& r) const
{
    return this->f < r.f;
}

bool operator==(const Node& a, const Node& b)
{
    return(a.posx == b.posx && a.posy == b.posy);
}
