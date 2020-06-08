#ifndef NODE_H
#define NODE_H

class  Node
{
private:
    Node *parent;
    int posx;
    int posy;
    int g; // Distance to current node
    int h; // Heuristic. Estimated distance to the end node.
    int f; // Total cost of the node g + h
    bool operator<(const Node& r) const;
    //bool operator==(const Node& r) const;

public:
    Node(Node *parent, int x, int y);
    ~Node(){};

    void SetParent(Node *parent);
    void SetPosX(int x);
    void SetPosY(int y);
    void SetG(int g);
    void SetH(int end_x, int end_y);
    void SetF(int f);

    Node* GetParent();
    int GetPosX();
    int GetPosY();
    int GetG();
    int GetH();
    int GetF();
    friend bool operator== (const Node &a, const Node &b); 
};



#endif