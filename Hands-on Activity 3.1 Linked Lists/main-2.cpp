#include <iostream>
#include "singly_ll.h"
#include "double_LL.h"


// ***************************************** EACH CODE IS COMMENTED FOR SEPARATE USE ***************************************

/* FOR TABLE 3.1
    class Node{
    public:
        char data;
        Node* next;
};
*/

int main(){

    /*FOR TABLE 3.1
    //making pointer variables or "nodes" with the Node data type
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;
    Node* fifth = nullptr;

    //dynamically allocating memory, now this variable is pointing to an address in the heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;
    fifth = new Node;

    // first node's data value is T and it's next value is pointed to the address of the second node
    head->data = 'T';
    head->next = second;

    // second node's data value is W and it's next value is pointed to the address of the second node
    second->data = 'W';
    second->next = third;

    third->data = 'A';
    third->next = fourth;

    fourth->data = 'I';
    fourth->next = fifth;

    fifth->data = 'N';
    fifth->next = nullptr;

    std::cout << head->data << second->data << third->data << fourth->data << fifth->data;

    delete head, second, third, fourth, fifth;
    head, second, third, fourth, fifth = nullptr;

    */

    /* FOR TABLE 3.2 AND 3.3
    SingleList<char>* head   = new SingleList<char>;
    SingleList<char>* second = new SingleList<char>;
    SingleList<char>* third  = new SingleList<char>;
    SingleList<char>* fourth = new SingleList<char>;
    SingleList<char>* fifth  = new SingleList<char>;
    SingleList<char>* sixth  = new SingleList<char>;

    head->data   = 'C';
    second->data = 'P';
    third->data  = 'E';
    fourth->data = '1';
    fifth->data  = '0';
    sixth->data  = '1';

    head->next   = second;
    second->next = third;
    third->next  = fourth;
    fourth->next = fifth;
    fifth->next  = sixth;
    sixth->next  = nullptr;

    std::cout << "Linked List Traversal:\n";
    listTraversal(head);

    std::cout << "New Head Insertion:\n";
    sllinsterHead('G', &head);
    listTraversal(head);

    std::cout << "General Insertion:\n";
    sllGeneralinsertion('E', second->next);
    listTraversal(head);

    std::cout << "Deleting.. \n";
    sllDelete('C', &head);
    listTraversal(head);

    std::cout << "Deleting.. \n";
    sllDelete('P', &head);
    listTraversal(head);

    listTraversal(head);

    sllDeleteList(&head);
    */


    /* FOR TABLE 3.4
    doubleList<char>* head = new_Node('C');
    doubleList<char>* second = new_Node('P');
    doubleList<char>* third = new_Node('E');

    //LINKING THE NODES

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    std::cout <<"Initial Traversal\n";
    dllTraverse(head);

    std::cout << "Inserting..\n";
    dllGeneralinsertion('Z', second);
    dllTraverse(head);

    std::cout <<"\n";
    dllDelete('E',&head);
    std::cout <<"Deleting..\n";
    dllTraverse(head);

    */
    return 0;
}