/****************************************************/
/*              Min heap implementation             */
/* Based on http://robin-thomas.github.io/min-heap/ */
/****************************************************/
#include "types.h"
#include "param.h"
#include "mmu.h"
#include "stat.h"
#include "user.h"
#include "proc.h"
#include "minheap.h"

#define LCHILD(x) (2*x+1) // Node's left child
#define RCHILD(x) (2*x+2) // Node's right child
#define PARENT(x) (x-1)/2 // Node's parent node


/*
  Computing node's priority based on the formula : runningTime/(currentTime-creationTime)
*/
double 
computePriority(MinHeapNode n, uint currentTime) 
{
  return ((double)n.process->runningTime/(double)(currentTime - n.process->creationTime));
}

/*
  Heap's initialization. Every node has initial priority equal to -1 (Convention: priority == -1 --> Node is empty).
*/
void 
initHeap()
{
  int i;
  for (i = 0; i < HEAPSIZE; i++) {
    minHeap[i].priority = -1.0;
    minHeap[i].process = 0;
  }
}

/*
  Returns the first empty node of the min heap. If every node is full, returns -1
*/
int 
firstEmpty()
{
  int i;
  for (i = 0; i < HEAPSIZE; i++){
    if(minHeap[i].priority == -1.0) {
      return i;
    }
  }
  return -1;
}

/* Abstraction of = for any type */
void 
setValue(MinHeapNode *n1, MinHeapNode n2) 
{
  *n1 = n2; /* basic type assignment */
}

/*
  Inserts new node at the first empty place of the heap while maintains heap's properties
*/
void 
insertAtHeap(MinHeapNode n)
{
  int pos = firstEmpty();
  while(pos && n.priority < minHeap[PARENT(pos)].priority){
    setValue(&minHeap[pos],minHeap[PARENT(pos)]);
    pos = PARENT(pos);
  }
  setValue(&minHeap[pos],n);
} 

/*
  Swap two heap's nodes (in fact just change their data)
*/
void 
swap(MinHeapNode *n1, MinHeapNode *n2) 
{
    MinHeapNode temp;
    setValue(&temp, *n1);
    setValue(n1, *n2);
    setValue(n2, temp);
}

/*
  Called when deleteRoot is called in order to maintain heap's properties
*/
void 
heapify(int index)
{
  int smallest = index;
  if (RCHILD(index) < HEAPSIZE && minHeap[RCHILD(index)].priority !=-1 && minHeap[index].priority > minHeap[RCHILD(index)].priority)
    smallest = RCHILD(index);
  if (LCHILD(index) < HEAPSIZE && minHeap[LCHILD(index)].priority !=-1 && minHeap[smallest].priority > minHeap[LCHILD(index)].priority)
    smallest = LCHILD(index);
  if(smallest != index) {
    swap(&minHeap[smallest],&minHeap[index]);
    heapify(smallest);
  }
}

/*
  Removes from the min heap the root, but returns pointer to the process that was stored in the node
  I will insert again after its time slice
*/
struct proc * 
deleteRoot()
{
  int last;
  struct proc *p = 0;
  if(minHeap[0].priority != -1) { 
    p = minHeap[0].process;
    last = firstEmpty() - 1;
    setValue(&minHeap[0], minHeap[last]);
    minHeap[last].priority = -1.0;
    minHeap[last].process = 0;
    heapify(0);
  }
  return p;
}