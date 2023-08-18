
#include "heap.h"

Heap::~Heap(){delete [] _heap;}

bool Heap::enqueue(int key, int data){
    if (_heapSize > _numElements){
        Node aNode(key, data);
        _numElements++;
        _heap[_numElements] = aNode;
        upHeap(_numElements);
        return true;
    }
    else
        return false;
}
void Heap::upHeap(int anIndex){
    /*************************
     * To be implemented
     * **********************/
  	if (_ROOT_INDEX < anIndex)
	{
		if (_heap[anIndex/2].getKey() > _heap[anIndex].getKey())
		{
			Node temp = _heap[anIndex/2];
			_heap[anIndex/2] = _heap[anIndex];
			_heap[anIndex] = temp;
			upHeap(anIndex/2);
		}
	}
}

Node Heap::dequeue(){
    Node temp;
    if (!empty()){
        temp = _heap[_ROOT_INDEX];
        _heap[_ROOT_INDEX] = _heap[_numElements];
        _numElements--;
        downHeap(_ROOT_INDEX);
    }
    return temp;
}
void Heap::downHeap(int anIndex){
    /*************************
     * To be implemented
     * **********************/
  	int left = anIndex*2;
	int right = anIndex*2+1;
	int minChild = _numElements+1;
	
	if (left <= _numElements)
	{
		if (left <= _numElements)
			minChild = left;
		else
			minChild = (_heap[left]._key >= _heap[right]._key)? right:left;
			
	}
	
	if ((minChild <= _numElements) && (_heap[anIndex]._key > _heap[minChild]._key))
	{
		Node temp = _heap[minChild];
		_heap[minChild] = _heap[anIndex];
		_heap[anIndex] = temp;
		downHeap(minChild);
	}
}


Node Heap::min(){
    return _heap[_ROOT_INDEX];
}
int Heap::size(){
    return _numElements;
}
bool Heap::empty(){
    return (_numElements == 0);
}
void Heap::inOrderTraversal(int anIndex){
    if (anIndex <= _numElements){
        cout << "(";
        inOrderTraversal(anIndex*2);//visit left
        cout << _heap[anIndex]._key << ":" << _heap[anIndex]._data; //visit node
        inOrderTraversal(anIndex*2+1);//visit right
        cout << ")";
    }
}
void Heap::dumpArray(){
    for(int i=_ROOT_INDEX; i<=_numElements; i++)
     {
          cout << "Element index" << i << ". key=" << _heap[i]._key << 
                    "  data=" << _heap[i]._data << endl;
     }
}
void Heap::inOrderDump(){
    inOrderTraversal(_ROOT_INDEX);
}

ostream& operator<<(ostream& sout, const Node& node) {
  sout << node.getKey() << ":" << node.getData() << endl;
  return sout;
}