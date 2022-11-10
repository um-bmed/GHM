#include "Node.h"


/**
 * CLASS: Node
 * Author:
 * Remarks: Node class defines a generic data structure representing a node, the basic unit of a linked list
 *          this class stores a NodeItem object as the data
 */

Node::Node()
{
    this->nextNode = nullptr;
    this->item = nullptr;
}


/**
 * getNext
 *
 * @PURPOSE get the next node in the list
 *
 * @return Node - the next node in the list
 */
Node* Node::getNext()
{
    return this->nextNode;
}

/**
 * setNext
 *
 * @PURPOSE: sets the next node in the list
 */
void Node::setNext( Node* newNode )
{
    this->nextNode = newNode;
}

/**
 * getItem
 *
 * @PURPOSE get the NodeItem stored in the node
 *
 * @return NodeItem - the NodeItem object stored in the node
 */
Item* Node::getItem()
{
    return this->item;
}

// /**
//  * toString
//  *
//  * @PURPOSE get a string representation of the node
//  *
//  * @return String - a string representation of the node
//  */
// string Node::toString()
// {
//     return item.toString();
// }


/**
 * CLASS: Node
 * Author: Joseffus Santos, 6829382
 * Remarks: Node class defines a generic data structure representing a node, the basic unit of a linked list
 *          this class stores a NodeItem object as the data
 */

public class Node {

    private Node nextNode; // pointer to the next node in the list
    private NodeItem item; // pointer to an item

    /** 
     * constructor 
     * 
     * @PURPOSE: initialize the Node object
     *
     * @param item the NodeItem to be stored in the node 
     */
    public Node(NodeItem item) {
        nextNode = null;
        this.item = item;
    }

    /**
     * getNext
     * 
     * @PURPOSE get the next node in the list 
     * 
     * @return Node - the next node in the list
     */
    public Node getNext() {
        return nextNode;
    }

    /**
     * setNext
     * 
     * @PURPOSE: sets the next node in the list
     */ 
    public void setNext(Node newNode) {
        nextNode = newNode;
    }

    /**
     * getItem
     * 
     * @PURPOSE get the NodeItem stored in the node 
     * 
     * @return NodeItem - the NodeItem object stored in the node
     */
    public NodeItem getItem() {
        return this.item;
    }

    /**
     * toString
     * 
     * @PURPOSE get a string representation of the node 
     * 
     * @return String - a string representation of the node
     */
    public String toString() {
        return item.toString();
    }

}
