#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
        int arr[100];
        int size=0;
        void insert(int value)
        {
             size++;
            int index=size;
            arr[index]=value;
           
            while(index>1)
            {
                int parent=index/2;
                if(arr[parent]<arr[index]){
                    swap(arr[parent],arr[index]);
                    index=parent;
                }
                else {
                    return ;
                }
            }
        }
        void delte()
        {
            if(size==0) return ;
            else{
                 //swap first node to last node 
                swap(arr[1],arr[size]);
                //root node ko actual position pe le aayo 
                size--;
                int i=1;
                while(i<size)
                {
                    int lef=2*i;
                    int rig=2*i+1;
                    if(lef<size && arr[i]<arr[lef]){
                         swap(arr[i],arr[lef]);
                         i=lef;

                    }
                    else if(rig<size && arr[i]<arr[rig]) {
                        swap(arr[i],arr[lef]);
                         i=rig;

                    }
                    else return ;
                }

            }

           
            
        }
};

void heapify(int arr[],int n ,int i)
{
    int lar=i;
    int left=2*i;
    int right=2*i+1;
    if(left<n && arr[lar]<arr[left] ) lar=left;
    if(right<n && arr[lar]<arr[right]) lar=right;
    if(i!=lar)
    {
        swap(arr[i],arr[lar]);
        heapify(arr,n,lar);
    }    
}

//buildfunction takes o(N) time complexity to make an array in priority quueu;


void heapsort(int arr[], int n)
{   //1. build heap 
    //2. sorting algo 

    int size=n;
    while(size>1)
    {
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

//priority_queue


int main()
{
    //min heap 
    priority_queue<int,vector<int>,greater<int>>p;
    //max heap
    priority_queue<int>p1;
    //top
    cout<<p1.top()<<endl;

}