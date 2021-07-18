#include "TicketQueue.h"
  
TicketQueue::TicketQueue(int cap) 
{ 
    heap_size=0;
	capacity= cap;
	harr= new Ticket [capacity];//complete
} 
  

Ticket TicketQueue::getTicketWithHighestPriority() 
{ 
   return *harr;//complete
} 

void TicketQueue::insertTicket(Ticket k) 
{ 
   harr[heap_size]=k;
   trickleUp(heap_size);
   heap_size++;//complete
} 
  
void TicketQueue::changeTicketPriority(Ticket tkt, int new_priority) 
{ 
int found_index=0;
int priority_tkt, priority_harr,parent_index;
priority_tkt= tkt.getPriority();
   for (int j=0; j<heap_size;j++){
   	priority_harr= harr[j].getPriority();
   		if (priority_tkt== priority_harr){
   			found_index=j;
   			break;
		   }
   }//complete
   harr[found_index].setPriority(new_priority);
   	
   parent_index= parent(found_index);
   if (harr[parent_index].getPriority()>tkt.getPriority()) {
   trickleUp(found_index);
   }
   else{
   	trickleDown(found_index);
   }
 }

void  TicketQueue::trickleUp(int i)
{
	int parentIndex;
   	parentIndex= parent(i);
    while(parentIndex>=0){
    if (harr[i].getPriority()<harr[parentIndex].getPriority()){
            swap(harr[i],harr[parentIndex]);
        i=parentIndex;
        parentIndex=parent(i);
    }
        else
            break;
   }
}


Ticket TicketQueue::ticketProcessed() 
{ 
   Ticket temp=harr[0];
   harr[0]=harr[heap_size-1];
	heap_size--;
	trickleDown(0);
	return temp;
	//complete
	
} 
  
void TicketQueue::deleteTicket(Ticket i) 
{ 
  changeTicketPriority(i,INT_MIN);
  Ticket temp= ticketProcessed(); //complete
} 
  
void TicketQueue::trickleDown(int i) 
{  
int child_left=leftChild(i);
    int child_right=rightChild(i);
    Ticket X;
    if(harr[child_left].getPriority()<harr[child_right].getPriority()){
        X=harr[child_left];
    }
    else{
   X=harr[child_right];
    }
    if(X.getPriority()< harr[i].getPriority()){
        swap(X,harr[i]);
    trickleDown(i);}
}

void TicketQueue::destroyList()
{
   heap_size=0;
   harr=NULL;//complete
}

TicketQueue::~TicketQueue()
{
   destroyList();//complete
}
  
void swap(Ticket *x, Ticket *y) 
{ 
   Ticket *temp;
   temp=x;
   x=y;
   y=temp;
   //complete
} 

