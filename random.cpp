//generate random integers

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//int rand(void);

int main(){

  int ran_num;
  srand(time(0));
  for(int i=0; i<100; i++){
    
    ran_num=rand()%200;
    cout<< ran_num << " ";
  }

return 0;
}
