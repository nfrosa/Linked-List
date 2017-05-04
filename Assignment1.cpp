using namespace std;
#include <iostream> 
#include <string> 

class Node {
    public:
		Node * next;
   		int val;
        Node(int value) {
            val = value;
            next = NULL;
        }
	
};

class LinkedList {
    private:
        Node * head;
        Node * tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }
    void insert(int value) {
        if (head == NULL) {
            head = new Node(value);
            tail = head;
            head -> next = head;
            return;
        } else {
       	    Node * newNode = new Node(value);
            tail -> next = newNode;
            tail = newNode;
            tail -> next = head;
		}
    }
    // Printing the list
    void Print(){
    	Node * curr = head;
    	do{
    		cout << curr->val << " ";
    		curr = curr -> next;
		} while(curr != head);
		cout << "\n";
	}
	//counts how many of the value there is
	int valCount (int value){
		int count = 0;
		Node * curr = head;
        do{
   	 		if (value == curr -> val)
   	 			count++;
    		curr = curr -> next;
		} while(curr != head);
		return count;
	}
	//Deleting a node
     void del(Node * delNode){
		 Node * curr = head;
		 Node * prev;
    	 do{
    		if(curr == delNode){
	   			if(curr == head){
	   				head = curr -> next;
	   				tail -> next = head;
	   			} else if (curr == tail){
	   				prev -> next = head;
	   				tail = prev;
				   } else {
	   				prev -> next = curr -> next;
				   }
	   			return;
			}
			prev = curr;
			prev -> next = curr -> next;
    		curr = curr -> next;
		 } while(curr != head);
	}
	 void DeleteInput(int start, int end, int step){
	 	Node * curr = head;
	 	int stepsTaken = 0;
	 	//getting to the start
	 	do{
        	curr = curr -> next;
		} while(curr->val != start);
		//deleting the values
	 	do{
	 		Node * temp = curr-> next;
   		    if(stepsTaken == step-1){
   		    	stepsTaken = 0;
   		    	del(curr);
   		    	curr = temp;
 			} else {
    		    curr = temp;
    		  	stepsTaken++;
			}
			if (curr -> val == end && stepsTaken == step-1){
				del(curr);
				}
	    }while(curr -> val != end);
	 }
};

int main(int argc, char * * argv) {
	LinkedList list;
	int N;
	cin >> N;
	for(int i = 1; i <= N; i++){
		int value;
		cin >> value;
		list.insert(value);
	}
	//	list.Print();	
	int M;
	cin >> M;
	for(int i = 0; i<M; i++){
		int start;
		cin >> start;
		int end;
		cin >> end;
		int step;
		cin >> step;
		//checks if the start and end exist and aren't the same, or if they are the same and there is more than 1 occurence
        if ((list.valCount(start)>0 && list.valCount(end)>0 && (start != end)) ||
		   ((start == end) && (list.valCount(start) > 1)) ){
			list.DeleteInput(start,end,step);
		}
	}
	list.Print();
	return 0;
};

