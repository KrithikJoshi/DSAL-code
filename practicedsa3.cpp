#include<iostream>
using namespace std;
#define size 10
struct node{
    string name;
    int count;
    struct node *next[size];
};

class G_tree{
    public:
    node *root=new node;
    void create(){
    cout<<"Enter the name of the subject"<<endl;
    cin>>root->name;
    cout<<"Enter the number of the chapters"<<endl;
    cin>>root->count;
    int n_chapters = root->count;
    for(int i = 0; i<n_chapters; i++){
        root->next[i]=new node;
        cout<<"Enter the name of the "<<(i+1)<<"chapter"<<endl;
        cin>>root->next[i]->name;
        cout<<"Enter the number of Sections"<<endl;
        cin>>root->next[i]->count;
        int n_sections=root->next[i]->count;
        for(int j=0; j<n_sections; j++){
            root->next[i]->next[j]=new node;
            cout<<"Enter the name of the"<<(j+1)<<"Section"<<endl;
            cin>>root->next[i]->next[j]->name;
            cout<<"Enter the number of subesections"<<endl;
            cin>>root->next[i]->next[j]->count;
            int n_subsections=root->next[i]->next[j]->count;
            for(int k=0; k<n_subsections;k++){
                root->next[i]->next[j]->next[k]=new node;
                cout<<"Enter the name of the"<<(k+1)<<"Subsection"<<endl;
                cin>>root->next[i]->next[j]->next[k]->name;

            }

        }
    }
    
    }
    void display(){
        cout<<"The subject name is"<<endl;
        cout<<root->name<<endl;
        for(int i =0; i<root->count; i++){
            cout<<"Chapter name is";
            cout<<root->next[i]->name<<endl;
            for(int j= 0; j<root->next[i]->count;j++){
                cout<<"Section name is";
                cout<<root->next[i]->next[j]->name<<endl;
                for(int k= 0; k<root->next[i]->next[j]->count;k++){
                    cout<<"Subsection name is";
                    cout<<root->next[i]->next[j]->next[k]->name<<endl;
                }
            }

        }
    }


};

int main(){
    G_tree t;
    t.create();
    t.display();

}
