#include<iostream>
#include<string.h>
using namespace std;

struct node
{
 int Tel_no;
 node*next;
}*HashTable[10];

class hashing
{
 public:
        hashing()
        {
         for(int i=0;i<10;i++)
         {
          HashTable[i]==NULL;
         }
        }
    
        int HashFunction(int Tel_no)
        {
         return (Tel_no%10);
        }
        
        
  

        node*create_node(int x)
        {
         node*temp=new node;
         temp->next=NULL;
         temp->Tel_no=x;
         return temp;
        }
       
        void display()
        {
         for(int i=0;i<10;i++)
         {
          node*temp=new node;
          temp=HashTable[i];
          cout<<"a["<<i<<"]:";
          while(temp!=NULL)
          {
           cout<<"->"<<temp->Tel_no;
           temp=temp->next;
          }
          cout<<"\n";
         }
        }
       
        int searchElement(int Tel_no)
        {
         bool flag=false;
         int hash_val=HashFunction(Tel_no);
         node*entry=HashTable[hash_val];
         cout<<"\nElement Fount at:";
         while(entry!=NULL)
         {
          if(entry->Tel_no==Tel_no)
          {
           cout<<hash_val<<":"<<entry->Tel_no<<endl;
           flag==true;
          }
          entry=entry->next;
         }
         if(!flag)
            return 1;
         else
            return 0;
         
        }
        
        
        
        void deleteElement(int Tel_no)
        {
         int hash_val=HashFunction(Tel_no);
         node*entry=HashTable[hash_val];
         if(entry==NULL)
         {
          cout<<"No Element Found";
          return;
         }
         if(entry->Tel_no==Tel_no)
         {
          HashTable[hash_val]=entry->next;
          return;
         }
         while((entry->next)->Tel_no!=Tel_no)
         {
          entry=entry->next;
         }
         entry->next=(entry->next)->next;
        }
        
        
        
        void insertElement(int Tel_no)
        {
         int hash_val=HashFunction(Tel_no);
         node*temp=new node;
         node*head=new node;
         head=create_node(Tel_no);
         temp=HashTable[hash_val];
         if(temp==NULL)
         {
          HashTable[hash_val]=head;
         }
         else
         {
          while(temp->next!=NULL)
          { 
           temp=temp->next;
          }
          temp->next=head;
         }
        }       
};

int main()
{
 int ch;
 int Tel_no,search,del;
 hashing h;
 
 do
 {
   cout<<"\nTELEPHONE BOOK DATABASE:\n1.Insert\n2.Display\n3.Search\n4.Delete\n5.Exit";
   cout<<"\nEnter Your Choice:";
   cin>>ch;
   
   switch(ch)
   {
    case 1: cout<<"\nEnter Phone no to be Inserted:";
            cin>>Tel_no;
            h.insertElement(Tel_no);
            break;
            
    case 2: h.display();
            break;
            
    case 3: cout<<"\nEnter phone no to be Searched:";
            cin>>search;
            if(h.searchElement(search)==-1)
            {
             cout<<"no Element Fount at key";
             continue;
            }
            break;
            
    case 4: cout<<"\nEnter Phone no to be Deleted:";
            cin>>del;
            h.deleteElement(del);
            cout<<"Phone no Delete"<<endl;
            break;
   }
 }while(ch!=5);
  cout<<"THANK YOU FOR USING THIS PROGRAM"<<endl;
  return 0;
}
