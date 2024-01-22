#include <iostream>

class Node {
	private:
		int value;
		Node* next;

	public:
		Node(int value, Node* next) {
			this->value = value;
			this->next = next;
		}
		int getValue() {
			return value;
		}
		Node* getNext() {
			return next;
		}
};

class Stack {
	private:
		Node* top;

	public:
		Stack(){
			top = nullptr;
		}
		
		~Stack() {
			while (top != nullptr) {
				Node* temp = top;
				top = top->getNext();
				delete temp;
			}
		}
    void push(int value){
    	top = new Node(value, top);
	}
	int pop(){
    	Node* temp = top;
    	top = top->getNext();
    	int value = temp->getValue();
    	delete temp;
    	return value;
	}
    bool isEmpty(){
    	return top == nullptr;
	}
	int peek(){
		return top->getValue();
	}
};

int main(int argc, char** argv) {
	Stack stack;
	std::cout << "empty=" << stack.isEmpty() << "\n";
	for(int i=1; i<argc; ++i){
		stack.push(std::stoi(argv[i]));
		std::cout << stack.peek() << " ";
	}
	std::cout << "\nempty=" << stack.isEmpty();
	stack.pop();
	stack.pop();
	stack.pop();
	std::cout << "\nempty=" << stack.isEmpty();


	return 0;
}