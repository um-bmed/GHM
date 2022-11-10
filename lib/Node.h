#pragma once

class Item;

class Node {

private:
    Node* nextNode; // pointer to the next node in the list
    Item* item; // pointer to an item

protected:


public:
    Node();
    Node* getNext();
    void setNext( Node* );
    Item* getItem();
    
};