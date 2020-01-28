#include <iostream>
#include <fstream>
#define STOP -1
using namespace std;
ifstream infile("input.txt");
ofstream outfile("output.txt");
class arraylist{
    private:
    int *A, *B;
    int head, n;
    public:
    arraylist(int len){
        head=STOP;
        A=new int[len];
        B=new int[len];
        n=0;
    }
    
    void addnode(int x){
        A[n]=x;
        int t=head;
        int p=-1;
        while(t!=STOP && A[t]<=x){
            p=t;
            t=B[t];
        }
        if(p==-1){
            B[n]=head;
            head=n;
        }
        else{
            B[n]=B[p];
            B[p]=n;
        }
        n++;
    }

    void print(){
        for(int i=0;i<n; i++){
            outfile<<B[i]<<" ";
        }
    }

};

int main(){
    int N;
    infile>>N;
    arraylist* L=new arraylist(N);
    int n;
    for(int i=0; i<N; i++){
        infile>>n;
        L->addnode(n);
    }
    L->print();

}
