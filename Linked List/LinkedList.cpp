#include <iostream>
using namespace std;

/*
    this code is for linked lists, we have our node struct that has the item and a pointer to the next node, then in it we also have a constructor for the node (in case we want to create a new node).

    In the linkedList class we just have a head, which is of type node and this is where the linked list expands from using append, or we can use other functions like deleteItem to remove a specific node, or print to print all of them, in main you will find a test for the class that showss you the linked list in action when you run it
*/
struct Node
{
    int item;
    Node *next;
    Node(int newItem, Node *nextItem) : item(newItem), next(nextItem) {}
};

class LinkedList
{
private:
    Node *head;

public:
    //* constructors, one default and one parameterized*//
    LinkedList() : head(nullptr) {}
    LinkedList(Node *newHead) : head(newHead) {}

    // Append adds an item to the END of the linked list
    void append(int item)
    {
        Node *current = head;                    // used to iterate through the list
        Node *newNode = new Node(item, nullptr); // the node we want to add

        // if the the linked list has no nodes in it, we just make the newNode the head node
        if (current == nullptr)
        {
            head = newNode;
            return;
        }

        // iterates through the linked list until the end, once we reach the end it sets the last nodes *next* node to newNode
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    // Checks list isnt empty, then iterates through and prints the list
    void print()
    {
        Node *current = head;
        if (current == nullptr)
        {
            cout << "This List is Empty\n";
            return;
        }

        while (current != nullptr)
        {
            cout << current->item << " ";
            current = current->next;
        }
        cout << "\n";
    }

    // this function searches for specific item, then deletes it from the linkedlist
    void deleteItem(int item)
    {
        // checks if list is empty
        if (head == nullptr)
        {
            cout << "This list is empty; cannot delete item\n";
            return;
        }

        // checks if the head item is the item were looking for then deletes it
        if (head->item == item)
        {
            Node *todelete = head; // this with the delete ensures we dont have any memory leaks
            head = head->next;
            delete todelete;
            return;
        }

        // sets 2 pointers that we use to iterate through the linked list
        Node *prevNode = head;
        Node *current = head->next;

        while (current != nullptr)
        {
            // checks if we found the item, if so, it sets the previous nodes next to
            // current nodes next, this makes it so we sort of "jump" over the node were
            // trying to delete, then we delete the current pointer and exit the function
            if (current->item == item)
            {
                prevNode->next = current->next;
                delete current;
                return;
            }
            prevNode = current;
            current = current->next;
        }
        cout << "Item is already not in the list\n";
    }
};

// test for the linked list
int main()
{
    LinkedList list;

    cout << "Initial: ";
    list.print(); // empty

    list.append(10);
    list.append(20);
    list.append(30);
    cout << "After appends: ";
    list.print(); // 10 20 30

    list.deleteItem(20);
    cout << "After deleting 20: ";
    list.print(); // 10 30

    list.deleteItem(10);
    cout << "After deleting head 10: ";
    list.print(); // 30

    list.deleteItem(999); // not present
    cout << "After deleting 999 (not found): ";
    list.print(); // 30

    list.deleteItem(30); // last item
    cout << "After deleting last item 30: ";
    list.print(); // empty

    return 0;
}
