#include<iostream>
using namespace std;

template <class T>
struct node
{
    T data;
    struct node *next;
};

template <class T>
struct anode
{
    T data;
    struct anode *next;
    struct anode *prev;
};

template<class T>
class SinglyLL
{
    private:
        struct node<T>* first;
        int Count;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
class SinglyCL
{
    private:
        struct node<T>* first;
        struct node<T>* last;
        int Count;

    public:
        SinglyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
class DoublyLL
{
    private:
        struct node<T> * first;
        int Count;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};

template <class T>
class DoublyCL
{
    private:
        struct node<T> * first;
        struct node<T> * last;
        int Count;

    public:
        DoublyCL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int CountNode();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int ipos);
        void DeleteAtPos(int ipos);
};


template<class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside constructor\n";
    first = NULL;
    Count = 0;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    struct node<T>* newn = NULL;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    struct node<T>* newn = NULL;
    struct node<T>* temp = first;

    newn = new struct node<T>;   
    newn->data = no;
    newn->next = NULL;

    if(first == NULL)   // if(Count == 0)
    {
        first = newn;
    }
    else
    {
        while(temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void SinglyLL<T>::Display()
{
    struct node<T>* temp = first;

    cout<<"Elements of the linked list are : \n";
    
    while(temp != NULL) // Type 1
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp ->next;
    }
    cout<<"NULL \n";
}

template<class T>
int SinglyLL<T>::CountNode()
{
    return Count;
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T>* temp = first;

        first = first->next;
        delete temp;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        struct node<T>* temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    Count--;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no,int ipos)
{
    if((ipos < 1) || (ipos > Count+1))
    {
        return;
    }
     
    if(ipos == 1)
    {
        InsertFirst(no);
    }
    else if(ipos == Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node<T>* newn = new struct node<T>;
        newn->data = no;
        newn->next = NULL;

        struct node<T>* temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;

        Count++;
    }
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int ipos)
{
    if((ipos < 1) || (ipos > Count))
    {
        return;
    }
     
    if(ipos == 1)
    {
        DeleteFirst();
    }
    else if(ipos == Count)
    {
        DeleteLast();
    }
    else
    {
        struct node<T>* temp = first;
        int i = 0;

        for(i = 1; i < ipos-1; i++)
        {
            temp = temp -> next;
        }

        struct node<T>* targatednode = temp->next;
        temp->next = temp->next->next;
        delete targatednode;

        Count--;
    }
}

template <class T>
SinglyCL<T>::SinglyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template <class T>
void SinglyCL<T>::InsertFirst(T no)
{
    struct node <T>* newn = NULL;
    newn = new struct node <T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first; 
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    Count++;
}

template <class T>
void SinglyCL<T>::InsertLast(T no)
{
    struct node <T>* newn = NULL;
    struct node <T>* temp = first;
    newn = new struct node <T>;
    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first; 
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    Count++;
}

template <class T>
void SinglyCL<T>::Display()
{
    cout<<"Elements of the circular linked list are: " <<endl;

    if(first != NULL && last!= NULL)
    {
        do 
        {
            cout<<"| "<<first->data<<"|->";
            first = first->next;
        }while(first!=last->next);
        cout<<"Address of first node"<<endl;
    }
}

template <class T>
int SinglyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if((first->next == NULL)&& (last->next==NULL))
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        struct node <T>* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if((first->next == NULL)&& (last->next==NULL))
    {
        delete (first);
        first = NULL;
        last = NULL;
    }
    else
    {
        struct node <T>* temp = first;
        while(temp->next!=first)
        {
            temp = temp->next;
        }
        delete last;
        last = temp;
        last->next = first;
    }
    Count--;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T no,int ipos)
{
    struct node <T>* newn = NULL;
    newn = new struct node <T>;
    int i = 0;

    if(ipos<1 || ipos>Count+1)
    {
        cout<<"Invalid Position";
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct node <T>* temp = first;
        newn->data = no;
        newn->next = NULL;

        for(i=1; i<ipos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        Count++;
    }
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int ipos)
{
    int i = 0;

    if(ipos<1 || ipos>Count)
    {
        cout<<"Invalid Position";
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==Count)
    {
        DeleteLast();
    }
    else
    {
        struct node <T>* temp = first;

        for(i=1; i<ipos-1; i++)
        {
            temp = temp->next;
        }
        struct node <T>* TargetedNode = temp->next;
        temp->next = TargetedNode->next;
        delete TargetedNode;
        Count--;
    }
}

template <class T>
DoublyLL<T>::DoublyLL()
{
    first = NULL;
    Count = 0;
}

template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    struct anode<T> * newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first ==NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    Count++;
}

template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    struct anode<T> * newn = NULL;
    newn = new struct node<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first ==NULL)
    {
        first = newn;
    }
    else
    {
        struct anode<T> * temp = first;

        while(temp->next !=NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}

template <class T>
void DoublyLL<T>::Display()
{
    cout<<"Elements of linked list are "<<endl;

    cout<<"NULL<=>";
    while(first!=NULL)
    {
        cout<<"| "<<first->data<<" |<=>";
        first = first->next;
    }
    cout<<"NULL "<<endl;
}

template <class T>
int DoublyLL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first==NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first->next;
        first == NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    Count --;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(first==NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first->next;
        first == NULL;
    }
    else
    {
        struct anode<T>* temp = NULL;
       while(temp->next->next!=NULL)
       {
            temp = temp->next;
       }
       delete temp->next;
       temp->next = NULL; 
    }
    Count --;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T no,int ipos)
{
    if(ipos<1 || ipos<Count+1)
    {
        return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos = Count+1)
    {
        InsertLast(no);
    }
    else
    {
        struct anode<T>* temp = first;
        int i = 0;
        struct anode<T>* newn = NULL;
        newn = new struct anode<T>;
        newn->data = no;
        newn->next =NULL;
        newn->prev =NULL;

        for(i=1; i<ipos-1; i++)
        {
            temp= temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        Count ++;
    }
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int ipos)
{
    if(ipos<1 || ipos<Count)
    {
        return;
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos = Count)
    {
        DeleteLast();
    }
    else
    {
        struct anode<T>* temp = first;
        int i = 0;
        
        for(i=1; i=ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;
        Count--;
    }
}

template <class T>
DoublyCL<T>::DoublyCL()
{
    first = NULL;
    last = NULL;
    Count = 0;
}

template <class T>
void DoublyCL<T>::InsertFirst(T no)
{
    struct anode<T> * newn = NULL;
    newn = new struct anode<T>;

    newn->data = no;
    newn->prev = NULL;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
    first->prev = last;
    last->next = first;
    Count++;
}

template <class T>
void DoublyCL<T>::InsertLast(T no)
{
    struct anode<T> * newn = NULL;
    newn = new struct anode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }
    first->prev = last;
    last->next = first;
    Count++;
}

template <class T>
void DoublyCL<T>::Display()
{
    cout<<"Elements of Linked List are "<<endl;

    if(first!=NULL && last!=NULL)
    {
        do 
        {
            cout<<"| "<<first->data<<" |<=>";
            first = first->next;
        }while(first!=last->next);
    }
    cout<<"Address of first element"<<endl;
}

template <class T>
int DoublyCL<T>::CountNode()
{
    return Count;
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
        first->prev = last;
    }
    Count--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(first==NULL && last==NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete  last->next;
        first->prev = last;
        last->next = first;
    }
    Count--;
    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T no,int ipos)
{
    struct anode<T> * newn = NULL;
    newn = new struct anode<T>;

    if(ipos<1 || ipos>Count+1)
    {
        return;
    }
    if(ipos==1)
    {
        InsertFirst(no);
    }
    else if(ipos==Count+1)
    {
        InsertLast(no);
    }
    else
    {
        int i = 0;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;
        struct anode<T> * temp = first;
        for(i=1; i<ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        Count++;
    }
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int ipos)
{
    if(ipos<1 || ipos>Count)
    {
        return;
    }
    if(ipos==1)
    {
        DeleteFirst();
    }
    else if(ipos==Count)
    {
        DeleteLast();
    }
    else
    {
        int i = 0;
        struct anode<T> * temp = first;
        for(i=1; i<ipos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        Count--;
    }   
}


