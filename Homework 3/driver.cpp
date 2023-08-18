#include "heap.cpp"
#include <cstdlib>
#include <time.h>


bool test(Heap testHeap){
  bool returnVal = true;
  int minDataVal [500];
  int numInserted = 0;
  int minVal;
  
  for(int i = 0; i < 500; i++){
    Node min = testHeap.min();
    testHeap.dequeue();
    
    minVal = min.getData();
    
    minDataVal[i] = minVal;
    numInserted++;
    
    for(int j = 0; j < numInserted; j++){
      if(minDataVal[i] > minDataVal[j]){
        return false;
      } 
    }    
  }
  return returnVal;
}
  
  
int main(){
  srand (time(NULL));
  Heap testHeap = Heap(500);
  
  int key;
  
  for(int i = 0; i < 500; i++){
    key = rand() % 100 + 1;
    bool returnVal = testHeap.enqueue(key, key);
  }
  
  bool result = test(testHeap);
  cout << result;
  
  return 0;
}



