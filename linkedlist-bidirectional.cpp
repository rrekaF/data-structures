#include <iostream>

class Node {
private:
	int value;
	Node* next;
    Node* prev;

public:
	Node(int value, Node* next, Node* prev = nullptr) {
		this->value=value;
		this->next=next;
        this->prev=prev;
	}
	int getValue() {
		return value;
	}
	Node* getNext() {
		return next;
	}
    Node* getPrev(){
        return prev;
    }
    void setNext(Node* next){
        this->next = next;
    }
    void setPrev(Node* prev){
        this->prev = prev;
    }
};

class LinkedList {
private:
    Node * head = nullptr;
    Node * tail = nullptr;
public:
    ~LinkedList() {
        Node * current = head;
        while (current != nullptr) {
            Node * next = current -> getNext();
            delete current;
            current = next;
        }
    }

    void push_front(int value) {
        head = new Node(value, head);
        if (head->getNext() != nullptr) {
            head->getNext()->setPrev(head);
        }
        if (tail == nullptr) {
            tail = head;
        }
    }

    void pop_front() {
        if (head != nullptr) {
            Node* tmp = head;
            head = head->getNext();
            if (head != nullptr) {
                head->setPrev(nullptr);
            }
            delete tmp;
        }
    }
    void push_back(int value) {
        if (tail != nullptr) {
            tail->setNext(new Node(value, nullptr, tail));
            tail = tail->getNext();
        } else {
            // If the list is empty, create a new node for both head and tail
            head = tail = new Node(value, nullptr, nullptr);
        }
    }

    void pop_back() {
        if (tail != nullptr) {
            Node* tmp = tail;
            tail = tail->getPrev();
            if (tail != nullptr) {
                tail->setNext(nullptr);
            } else {
                // If the list becomes empty, update head to nullptr
                head = nullptr;
            }
            delete tmp;
        }
    }
    int get_head() {
        return (head != nullptr) ? head->getValue() : -1;
    }

    int get_tail() {
        return (tail != nullptr) ? tail->getValue() : -1;
    }
    int at(int n){
        int counter = 0;
        Node* current = head;
        while(current != nullptr){
            Node* next = current -> getNext();
            if(counter == n){
                return current -> getValue();
            }
            current = next;
            counter++;
        }	
        return -1;
    }
    void print(){
        Node* current = head;
        while(current != nullptr){
            std::cout << current->getValue() << " ";
            Node* next = current -> getNext();
            current = next;
        }
        std::cout << std::endl;
    }
};

int main(int argc, char** argv) {
    LinkedList list;
    list.push_front(5);
    list.push_front(10);
    list.push_front(15);
    list.print();
    list.push_back(20);
    list.print();

    return 0;

}