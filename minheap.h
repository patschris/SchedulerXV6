#define HEAPSIZE 64

struct MinHeapNode 
{
  double priority;
  struct proc *process;
};

typedef struct MinHeapNode MinHeapNode;

MinHeapNode minHeap[HEAPSIZE];

double computePriority(MinHeapNode, uint);
void initHeap(void);
int firstEmpty(void);
void insertAtHeap(MinHeapNode);
void swap(MinHeapNode *, MinHeapNode *);
void heapify(int);
struct proc * deleteRoot(void);