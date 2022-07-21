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
