#include <iostream>
using namespace std;

class Node
{
    public:
    int info;
    
    Node *next;

    Node(int in)
    {
        info=in;
        next=NULL;
    }

};

class Linked_List
{
    public:

    void show(Node *head)
    {
        Node *ptr=head;

        while(ptr!=NULL)
        {
            cout<<ptr->info<<" ";
            ptr=ptr->next;
        }
    }

    void showRec(Node *head)
    {
        Node *ptr=head;

        if(ptr==NULL)
        return;

        cout<<ptr->info<<" ";
        showRec(ptr->next);
    }

    bool exist(Node *head,int wanted)
    {
        Node *ptr=head;
        if(ptr==NULL)
        return false;

        if(ptr->info==wanted)
        return true;

       bool resp= exist(ptr->next,wanted);
       return resp;
    }

    Node *existsGetAddress(Node *ptr,int wanted)
    {
        if(ptr==NULL)
        return NULL;

        if(wanted==ptr->info)
        return ptr;

        Node *resp=existsGetAddress(ptr->next,wanted);
        return resp;
    }

    Node *appendNode(Node*head,int value)  //insertion at last
    {
        Node *nn=new Node(value);

        if(head==NULL)
        return nn;

        Node *ptr=head;

        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        return head;   
    }

    void insertAfter(Node *head,int value,int wanted)
    {
        Node *nn=new Node(value);
        Node *ptr=head;

        while(ptr!=NULL)
        {
            if(wanted==ptr->info)
                break;

            ptr=ptr->next;   
        }
        if(ptr!=NULL)
        {
        nn->next=ptr->next;
        ptr->next=nn;
        return;
        }
        cout<<"\n *********** NOT FOUND ************";
    }

    Node *insertBefore(Node* head,int wanted,int value)
    {
        Node *nn=new Node(value);
        Node *prev=NULL;
        Node *ptr=head;

        if(head->info==wanted)
        {
            nn->next=head;
            return nn;
        }

        while(ptr!=NULL)
        {
            if(ptr->info==wanted)
            break;

            prev=ptr;
            ptr=ptr->next;
        }

        if(ptr!=NULL)
        {
            nn->next=ptr;
            prev->next=nn;
        }
        else
        cout<<"******* NOT FOUND **********";
        return head;
    }

    void findMid(Node *head)
    {
        Node *FP=head,*SP=head;

        while(FP->next!=NULL && FP->next->next!=NULL)
        {
            SP=SP->next;
            FP=FP->next->next;
        }
        cout<<"\nMid="<<SP->info;
    }

    void deleteNode(Node* head,int wanted)
    {
        Node *temp= new Node(-1);

        temp=head;
        

        Node *ptr=head;
        Node *prevPtr=head;
        
        while(ptr->info!=wanted)
        {
            prevPtr=ptr;
            ptr=ptr->next;
        }

        prevPtr->next=ptr->next;

        head=temp->next;
        delete(temp);

    }
};

int main()
{
    Node *head=NULL;
    Node n1(10),n2(20),n3(30),n4(40);     // creation of Nodes of LL

    head=&n1;                            // connecting nodes of LL
    n1.next=&n2;
    n2.next=&n3;
    n3.next=&n4;

//linked list pe functions run krna
    Linked_List obj;
    obj.showRec(head);

    int wanted=20;

    bool resp=obj.exist(head,20);
    cout<<endl<<resp<<endl;
    obj.deleteNode(head,10);
    obj.showRec(head);



}

