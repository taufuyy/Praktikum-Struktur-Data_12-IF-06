//Taofik Hafit Zakaria
//103112430093
//main.cpp

  #include <iostream>
  #include "queue_unguided.h"
  #include "queue_unguided.cpp"
  using namespace std;
  
  int main() {
      cout << "Hello World!" << endl;
      Queue Q;
      createQueue(Q);
      
      cout << "----------------------" << endl;
      cout << " H - T \t | Queue Info" << endl;
      cout << "----------------------" << endl;
      
      printInfo(Q);              
      enqueue(Q, 5); printInfo(Q);  
      enqueue(Q, 2); printInfo(Q);  
      enqueue(Q, 7); printInfo(Q);  
      dequeue(Q); printInfo(Q); 
      dequeue(Q); printInfo(Q);     
      enqueue(Q, 4); printInfo(Q);  
      dequeue(Q); printInfo(Q);     
      dequeue(Q); printInfo(Q);     
      
      return 0;
  }