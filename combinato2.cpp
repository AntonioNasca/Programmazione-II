#include <iostream>
#include <fstream>
using namespace std;

class List{
    private:
    int *keys, *indexes;
    int size, head;
    public:
    List(int dim){
        keys = new int[dim];
        indexes = new int[dim];
        size = 0;
        head = -1;
    }

    void insert(int key)
    {
        keys[size] = key;
        int prev = -1;
        int cursor = head;
        
        while(cursor!=-1 && keys[cursor]<=key)
        {
            prev = cursor;
            cursor = indexes[cursor];
        }
        
        if(prev==-1)
        {
            indexes[size] = head;
            head = size;
        } 
        
        else
        {
            indexes[prev] = size;
            indexes[size] = cursor;
        }
        
        size++;
    }

    void canc(int key)
    {
        int prev = -1;
        int cursor = head;
        while(cursor != -1 && keys[cursor]<key)
        {
            prev = cursor;
            cursor = indexes[cursor];
        }
        
        if(prev==-1)
            head = indexes[cursor];
        else
            indexes[prev] = indexes[cursor];
        if(head == size-1)
            head = cursor;
        keys[cursor] = keys[size-1];
        indexes[cursor] = indexes[size-1];
        for(int i = 0; i<size; i++)
            if(indexes[i] == (size-1))
                indexes[i] = cursor;
        size--;
    }

    void printIndexes(ofstream& out)
    {
        for(int i = 0; i<size; i++)
            out << indexes[i] << " ";
        out << endl;
    }
};

int main()
{
    ifstream in("input.txt"); 
    ofstream out("output.txt");
    
    for(int i = 0; i<100; i++)
    {
        string command;
        int N;
        in >> N;
        List *l = new List(N);
        
        for(int j=0; j<N; j++)
        {
            in >> command;
            if(command[0] == 'i')
                l->insert(atoi(command.substr(1).c_str()));
            else
                l->canc(atoi(command.substr(1).c_str()));
        }
        
        l->printIndexes(out);
    }
    
    return 0;
}
