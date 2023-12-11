#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this->next != NULL) {
            cout<<"this is called"<<endl;
            delete next;
            this->next = NULL;
        }
        cout << "node with data " << value <<" is deleted !" <<endl;
    }

};

void insertAtHead(Node* &head,Node* &tail, int d) {
    if (head==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=head;
        return;
    }
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &head,Node* &tail, int d) {
    if (head==NULL){
        Node* temp = new Node(d);
        head=temp;
        tail=head;
        return;
    }
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}
int getLength(Node* & head) {
    int len = 0;
    Node* temp  = head ;
    if (head==NULL){
        // cout<<"list is empty"<<endl;
        return 0;
    }

    while(temp != NULL) {
        len++;
        temp  = temp -> next;
    }

    return len;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {
    if (position>(getLength(head)+1)){
        cout<<"Position is invalid"<<endl;
        return;
    }
    if(position == 1) {
        insertAtHead(head,tail, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }
    if(temp -> next == NULL) {
        insertAtTail(head,tail,d);
        return ;
    }
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head,Node * & tail) { 
    if (position>(getLength(head))){
        cout<<"position is greater than the length of list!  "<<endl;
        return;
    }
    if(position == 1) {
        if (getLength(head)==1){
            tail=NULL;
        }
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        if (curr->next==NULL){
            tail=prev;
        }
        curr -> next  = NULL;
        delete curr;

    }
}
int main(){
    // Node * n=new Node(6);
    // Node * head =n;
    // Node * tail =n;
    // insertAtHead(head,5);
    // insertAtTail(tail,14);
    // insertAtTail(tail,17);
    // print(head);
    // deleteNode(4,head,tail);
    // cout<<head<<endl;
    // cout<<head->next;
    Node * head =NULL;
    Node * tail= NULL;
    cout<<"1) insert at head: "<<endl;
   cout<<"2) insert at tail: "<<endl;
   cout<<"3) print linked list: "<<endl;
   cout<<"4) give size of linked list: "<<endl;
   cout<<"5) delete node :"<<endl;
   cout<<"6) insert at position: "<<endl;
   cout<<"7) exit from the loop: "<<endl;
   int m;
   while(true) {
      cout<<"Enter choice: "<<endl;
      cin>>m;
      switch(m) {
         case 1: {
            cout<<"enter the value: "<<endl;
            int val;
            cin>>val;
            insertAtHead(head,tail,val);
             break;
         }
         case 2: {
            cout<<"enter the value: "<<endl;
            int val;
            cin>>val;
            insertAtTail(head,tail,val);
             break;
         }
         case 3: {
            print(head);
            break;
         }
         case 4: {
            int val=getLength(head);
            cout<<"The length of the list is:"<<endl;
            cout<<val<<endl;
            break;
        }

         case 5:{
            cout<<"enter the postion of the node to be deleted: "<<endl;
            int val;
            cin>>val;
            deleteNode(val,head,tail);
            break;
         }  
         
         case 6: {
            cout<<"enter the value to be inserted: "<<endl;
            int val;
            cin>>val;
            cout<<"enter the position on which node is inserted:  "<<endl;
            int m;
            cin>>m;
            insertAtPosition(tail,head,m,val);
            break;
         }
         case 7: {
            return 0;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
            return 0;
            break;
         }
        // return 0;
      }
   }
    // cout<<"  v vf  b ";
}