#include <bits/stdc++.h>
using namespace std;

class ll{
	public:
	int data;
	int pri;
	ll* next=NULL;

	ll(int val , int pri){
		this->data=val;
		this->pri=pri;
		this->next=NULL;
	}

};

class priority{

	ll *head;
	ll *tail;
	public:
	priority(){
		head=NULL;
		tail=NULL;
	}
	void enqeue(int data , int pri){
		ll * newhead = new ll(data,pri);
		cout<<"inserting "<<data <<"priority is "<<pri<<endl;
		if(head==NULL){
			head=newhead;
			tail=newhead;
			return;
		}

		
		tail->next=newhead;
		tail=newhead;

		


	}

	void dequeue(){

		if(head==NULL){
			cout<<"priority is empty"<<endl;
			return;
		}
		
		ll * temp=head;
		ll *maxp=head;
		if(head->next==NULL){
			maxp=head;

			cout<<maxp->data<<" "<<maxp->pri<<endl;
			delete head;
			head=NULL;
			tail=tail=NULL;
			return;
			
		}



		while(temp!=NULL){

			if(maxp->data<temp->data){
				maxp=temp;
			}
			temp=temp->next;
		}
		cout<<maxp->data<<" "<<maxp->pri<<endl;

		if(head==maxp){
			head=head->next;
			delete maxp;
			return;
		}

		while(temp->next!=maxp){
			temp=temp->next;
		}
		if(maxp==tail){
			tail=temp;
		}
		temp->next=maxp->next;

		delete maxp;
		
	


	}


	void print(){

		if(head==NULL){
			cout<<"priority queue is empty"<<endl;
			return;
		}

		ll * temp=head;

		cout<<"printing priority queue"<<endl;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
};
int main(){


	priority pq;
	pq.enqeue(10,5);
	pq.enqeue(20,8);
	pq.enqeue(30,7);
	pq.enqeue(40,9);
	pq.enqeue(50,4);
	pq.print();

}