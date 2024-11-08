#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* next;
};

class linkedList{
    Node* head = NULL;

    public :
        void insertAtBeginning(int index){
            Node* newNode = new Node();
            newNode->value = index;
            newNode->next = head;
            head = newNode;
        }
        void insertAtEnd(int index){
            Node* newNode = new Node();
            newNode->value = index;
            newNode->next = NULL;

            if(!head){
                head = newNode;
            }
            else{
                Node* tempAddress = head;
                while(tempAddress->next){
                    tempAddress = tempAddress->next;
                }
                tempAddress->next = newNode;
            }
        }
        void display(){
            Node* tempAddress = head;
            while(tempAddress){
                cout << tempAddress->value << " ";
                tempAddress = tempAddress->next;
            }
        }
        void insertPosition(int index, int position){
            Node* newNode = new Node();
            newNode->value = index;
            Node* tempAddress = head;
            Node* priorTempAddress = head;
            int priorPosition = position;
            while(position > 1){
                if (position == 2){
                    priorTempAddress = tempAddress;
                }
                tempAddress = tempAddress->next;
                position--;
            }
            newNode->next = tempAddress;
            if (priorPosition > 1){
                priorTempAddress->next = newNode;
            }
            else{
                head = newNode;
            }
        }
        void deleteFromBeginning(){
            if(head){
                Node* tempAddress = head;
                tempAddress = tempAddress->next;
                delete head;
                head = tempAddress;
            }
        }
        void deleteFromEnd(){
            Node* tempAddress = head;
            Node* priorTempAddress = head;
            while(tempAddress->next->next){
                tempAddress = tempAddress->next;
            }
            priorTempAddress = tempAddress;
            tempAddress = tempAddress->next;
            delete tempAddress;
            priorTempAddress->next = NULL;
        }
        void deleteFromPosition(int position){
            Node* tempAddress = head;
            Node* priorTempAddress = head;
            int priorPosition = position;
            while(position > 1){
                if(position == 2){
                    priorTempAddress = tempAddress;
                }
                tempAddress = tempAddress->next;
                position--;
            }
            if (priorPosition > 1){
                priorTempAddress->next = tempAddress->next;
            }
            else {
                head = tempAddress->next;
            }
            delete tempAddress;
        }
};

int main(){
    linkedList list1;
    
    list1.insertAtEnd(10);
    list1.insertAtEnd(20);
    list1.insertAtEnd(30);
    list1.insertAtEnd(40);
    list1.insertAtEnd(50);
    list1.insertAtEnd(60);

    //insertPosition(value, position)
    list1.insertPosition(1, 6);

    list1.deleteFromBeginning();
    list1.deleteFromEnd();
    list1.deleteFromPosition(5);

    list1.display();
    return 0;
}
