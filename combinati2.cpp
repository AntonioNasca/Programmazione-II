#include<sstream>
#include<stdlib.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
class lista{
private:
    int head, n;
    int *A, *N;
public:
    lista(){
        head=-1;
        n=0;
        A=new int[10001];
        N=new int[10001];
    }

    void insert(int x){
        A[n]=x;
        int t=head;
        int p=-1;
        while(t!=-1 && A[t]<=x){
            p=t;
            t=N[t];
        }
        if(p==-1){
            N[n]=head;
            head=n;
        }
        else{
            N[n]=N[p];
            N[p]=n;
        }
        n++;
    }

    void canc(int x){
        int t=head;
        int p=-1;
        while(t!=-1 && A[t]<x){
            p=t;
            t=N[t];
        }

        if(t==-1 || A[t]>x) return;
        if(p==-1){
            head=N[t];
        }
        else{
            N[p]=N[t];
        }
        A[t]=A[n-1];
        N[t]=N[n-1];
        if(head==n-1){
            head=t;
        }
        for(int i=0; i<n; i++)if(N[i]==n-1)N[i]=t;
        n--;
    }

    void print(){
        for(int i=0; i<n; i++){
            out<<N[i]<<" ";
        }
        out<<endl;
    }
};


int main(){
    for(int p=0; p<100; p++){
        int N;
        in>>N;
        lista l;
        for(int i=0; i<N; i++){
            string a;
            in>>a;
            if(a[0]=='i'){
                string b;
                int n;
                for(int j=1; j<a.length(); j++){
                    b+=a[j];
                }
                stringstream ss;
                ss<<b;
                ss>>n;
                l.insert(n);
            }
            else{
                string b;
                int n;
                for(int j=1; j<a.length(); j++){
                    b+=a[j];
                }
                stringstream ss;
                ss<<b;
                ss>>n;
                l.canc(n);
            }
        }
        l.print();
    }
}

