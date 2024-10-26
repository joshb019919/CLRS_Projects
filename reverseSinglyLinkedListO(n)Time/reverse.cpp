#include <iostream>

class Node {
    public:
        int key;
        Node* next;
        Node(): key(-1), next(nullptr) {}
        Node(int key): key(key), next(nullptr) {}
        Node(int key, Node *next): key(key), next(next) {}
};

class LinkedList {

    public:
    Node* head;
    LinkedList(){}

    int listSize() {
        int size = 0;
        Node* temp = head;
        while (temp != nullptr) {
            ++size;
            temp = temp->next;
        }
        return size;
    }

    /**
     * Search list for node with given key.  Return that node if
     * found else nullptr.
     */
    Node* listSearch(int key) {
        Node* n = head;
        if (head == nullptr) {
            std::cout << "List empty." << std::endl;
        }
        while (n != nullptr && n->key != key) {
            n = n->next;
        }
        return n;
    }

    /**
     * Insert new node at beginning of list.  Return new node.
     */
    Node* listPrepend(int key) {
        Node* n = new Node(key);
        if (head == nullptr) {
            n->next = nullptr;
            head = n;
        } else {
            n->next = head;
            head = n;
        }
        return n;
    }   
    
    /**
     * Insert new node at end of list.  Return new node.
     */
    Node* listInsert(int key) {
        Node* n = new Node(key, nullptr);
        Node* temp = head;
        if (temp == nullptr) {
            listPrepend(key);
            delete n;
            return head;
        }

        while (temp != nullptr && temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->next = n;
        }
        return n;
    }

    /**
     * Insert new node after n.  Return new node in position or 
     * nullptr if n wasn't found.
     */
    Node* listInsert(int key, Node* n) {
        Node* m = new Node(key);
        Node* temp = head;
        Node* prev = head;
        while (temp != nullptr && temp != n) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {
            m->next = temp;
            prev->next = m;
        } else {
            std::cout << "Element not found." << std::endl;
        }
        return m;
    } 

    /**
     * Delete node with given key, if found.  Return deleted node if
     * found, else nullptr.
     */
    Node* listDelete(int key) {
        Node* temp = head;
        Node* prev = head;
        while (temp != nullptr && temp->key != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr && temp->next != nullptr) {
            prev->next = temp->next;
        }
        return temp;
    }
    
    /**
     * Print out the list if not empty, else "List empty."
     */
    void listPrint() {
        Node* temp = head;
        if (head == nullptr) {
            std::cout << "List empty." << std::endl << std::endl;
        } else {
            std::cout << std::endl << "Singly-linked list:" << std::endl;
        }

        while (temp != nullptr) {
            std::cout << temp->key << std::endl;
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    Node* listReverse() {
        Node* p1 = head;
        Node* p2 = head;
        Node* p3 = head;
        int count = 0;

        if (p1 == nullptr) {
            std::cout << "This linked list is empty!" << std::endl;
        }

        while (p1 != nullptr) {
            ++count;
            if (count == 1 && p1->next == nullptr) {
                std::cout << "One element lists are already reversed!" << std::endl;
            } else if (count == 1) {
                p2 = p1;
                p1 = p1->next;
                p2->next = nullptr;
            } else if (p1->next == nullptr) {
                p1->next = p2;
                head = p1;
                break;
            } else {
                p3 = p2;
                p2 = p1;
                p1 = p1->next;
                p2->next = p3;
            }
        }
        return head;
    }
};

int main() {
    LinkedList list;
    list.head = nullptr;
    list.listPrint();

    // list.listPrepend(5);
    // list.listPrint();
    // list.listPrepend(3);
    // list.listPrint();
    // list.listInsert(4, list.listSearch(5));
    // list.listPrint();
    // list.listInsert(10);
    // list.listPrint();
    // list.listDelete(4);
    // list.listPrint();

    std::cout << list.listSize() << std::endl;

    list.listInsert(1);
    list.listInsert(2);
    list.listInsert(3);
    list.listInsert(4);
    list.listInsert(5);
    list.listInsert(6);
    list.listPrint();
    
    std::cout << list.listSize() << std::endl;

    list.listReverse();
    list.listPrint();

    list.listReverse();
    list.listPrint();

    return 0;
}