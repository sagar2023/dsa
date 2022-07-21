#include <bits/stdc++.h>
using namespace std;
#define SIZE 1001
int heap[SIZE];
int heapsize;

void heap_push(int val){

    
     if(heapsize>=SIZE)
    {
        cout<<"Overflow\n";
        return;
    }
    
    heap[heapsize] = val;    //Push 1st element to the end of heap
    int curr = heapsize;
    //percolate-up
    while(curr>0 and heap[(curr-1)/2]<heap[curr])
    {
        int temp = heap[(curr-1)/2];
        heap[(curr-1)/2] = heap[curr];
        heap[curr] = temp;
        curr = (curr-1)/2;    //Current pointer moves to parent
    }
    heapsize += 1;
}
void heapify(int curr,int size)
{
    int largest = curr;
    int l = 2*curr+1;    //left child
    int r = 2*curr+2;    //right child
    if(l<size and heap[l]>heap[largest])
        largest = l;
    if(r<size and heap[r]>heap[largest])
        largest = r;
    if(largest!=curr)
    {
        int temp = heap[curr];
        heap[curr] = heap[largest];
        heap[largest] = temp;
        heapify(largest,size);
    }
}
int heap_pop(){

    int curr=0;
    int popped=heap[curr];
    swap(heap[curr],heap[heapsize-1]);
    heapsize--;
    while(2*curr+1<heapsize){

        int child;
        int left=2*curr+1;
        int right=2*curr+2;
        if(right==heapsize){
            child=left;
        }
        else{
            if(heap[left]>heap[right]){
                child=left;
            }
            else{
                child=right;
            }
        }

        if(heap[curr]<heap[child]){
            swap(heap[curr],heap[child]);
            curr=child;
        }
        else{
            break;
        }
    }

    return popped;

}
void show(){

    for(int i=0;i<heapsize;i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}
void init()
{
    heapsize = 0;
}
int main()
{
    init();
    while(1)
    {
        cout<<"1:Push...2:Pop...3:Show_Heap...4:Terminate\n";
        int option;
        int element;
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter element\n";
                cin>>element;
                heap_push(element);
                break;
            case 2:
                //cout<<"Popped "<<heap_pop()<<"\n";
                break;
            case 3:
                show();
                break;
            default:
                return 0;
        }
    }
}