#include<iostream>
using namespace std;
# define size 10
struct node{
    string name;
    int count;
    struct node *next[size];
};

class G_tree{
    public:
    node *root=new node;
    void create(){
    cout<<"Enter the subject name:";
    cin>>root->name;
    cout<<endl<<"Enter the number of chapters:";
    cin>>root->count;
    int n_chapters=root->count;
    for(int i=0;i<n_chapters;i++){
        root->next[i]=new node;
        cout<<"Enter the chapter "<<(i+1)<<" name:";
        cin>>root->next[i]->name;
        cout<<endl<<"Enter the number of sections:";
        cin>>root->next[i]->count;

        int n_sections=root->next[i]->count;
        for(int j=0;j<n_sections;j++){
            root->next[i]->next[j]=new node;
            cout<<"Enter the Section "<<(j+1)<<" name:";
            cin>>root->next[i]->next[j]->name;
            cout<<endl<<"Enter the number of Subsections:";
            cin>>root->next[i]->next[j]->count;


            int n_subsections=root->next[i]->next[j]->count;
            for (int k = 0;  k<n_subsections; k++)
            {
                root->next[i]->next[j]->next[k]=new node;
                cout<<"Enter the subsections"<<(k+1)<<"name:";
                cin>>root->next[i]->next[j]->next[k]->name;
            }

            

        }
        cout<<endl;
    }

    }
    void display(){
        cout<<endl;
        cout<<"The subject name is:"<<endl;
        cout<<root->name;
        for(int i=0;i<root->count;i++){
            cout<<"\t\tChapter name is:";
            cout<<root->next[i]->name<<endl;
          for(int j=0;j<root->next[i]->count;j++){
              cout<<"\t\tSection name is:"<<endl;
                cout<<root->next[i]->next[j]->name<<endl;
            for (int k = 0;k<root->next[i]->next[j]->count; k++){
              cout<<"\t\tSubsection name is:"; 
              cout<<root->next[i]->next[j]->next[k]->name<<endl;

            }
          }   
          cout<<endl;
        }
    }
};
 int main()
{
    G_tree t;
    t.create();
    t.display();
}