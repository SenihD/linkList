
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node* previous;
};

class doubleLinkedList {

    Node* head = NULL;
    Node* tail = NULL;

    public :

    //O(n)
    void display(){
        Node* tempAddress = head;
        while(tempAddress){
            cout << tempAddress->value << " ";
            tempAddress = tempAddress->next;
        }
    }

    //O(n)
    void displayInverse(){
        Node* tempAddress = tail;
        while (tempAddress){
            cout << tempAddress->value << " ";
            tempAddress = tempAddress->previous;
        }
    }

    //O(n)
    int countLength(){
        Node* tempAddress = head;
        int count = 0;
        while (tempAddress){
            count++;
            tempAddress = tempAddress->next;
        }
        return count;
    }

    //O(1)
    void insertAtBeginning(int index){
        Node* newNode = new Node();
        newNode->value = index;
        newNode->next = head;
        newNode->previous = NULL;
        if (head && tail){
            head->previous = newNode;
        }
        else{
            tail = newNode;
        }
        head = newNode;
    }

    //O(1)
    void inserAtEnd(int index){
        Node* newNode = new Node();
        newNode->value = index;
        newNode->next = NULL;
        newNode->previous = tail;
        if (head && tail){
            tail->next = newNode;
        }
        else{
            head = newNode;
        }
        tail = newNode;
    }

    //O(n)
    void insertAtPosition(int index, int position){
        
        if(head){
            Node* tempAddress = head;
            Node* newNode = new Node();
            newNode->value = index;
            //node(s) exists
            while (position > 1){
                if(tempAddress == tail && position == 2){
                    newNode->previous = tail;
                    newNode->next = NULL;
                    tail->next= newNode;
                    tail = newNode;
                }
                else {
                    tempAddress = tempAddress->next;
                }
                position--;
                
            }
            if (tail != newNode){
                newNode->next = tempAddress;
                newNode->previous = tempAddress->previous;
                if (head != tempAddress){
                    tempAddress->previous->next = newNode;
                    tempAddress->previous = newNode;
                }
                else{
                    tempAddress->previous = newNode;
                    head = newNode;
                }
            }
        }
        else if (position == 1){
            insertAtBeginning(index);
        }
    }

    //O(1)
    void deleteAtBeginning(){
        Node* tempAddress = head;
        head = head->next;
        head->previous = NULL;
        delete tempAddress;
    }

    //O(1)
    void deleteAtEnd(){
        Node* tempAddress = tail;
        tail = tail->previous;
        tail->next = NULL;
        delete tempAddress;
    }

    //O(n)
    void deleteAtPosition(int position){
        Node* tempAddress = head;
        for (int i = 1; i < position ; i++){
            tempAddress = tempAddress->next;
        }
        if (tempAddress->next && tempAddress->previous){
            tempAddress->previous->next =  tempAddress->next;
            tempAddress->next->previous = tempAddress->previous;
            delete tempAddress;
        }
        else if (tempAddress->previous){
            tail = tempAddress->previous;
            tail->next = NULL;
            delete tempAddress;
        }
        else{
            head = head->next;
            if(head) {
                head->previous = NULL;
            }
            else {
                tail = head;
            }
            delete tempAddress;
        }
    }
};

int main(){

    doubleLinkedList list1;
    list1.insertAtPosition(9, 1);
    list1.insertAtPosition(10, 2);
    list1.insertAtPosition(9, 3);
    list1.deleteAtPosition(1);

    list1.display();
    cout << endl;
    list1.displayInverse();
    cout << endl;
    
    int n = list1.countLength();
    cout << n;
}
