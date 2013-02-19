//bubble sorting

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputarray(int *p, int length);
void bubblesort(int *p, int length);
void printarray(int *p, int length);

#define N_DEFAULT 100

int main(){
  int array[N_DEFAULT];
  srand(time(0));
//  srand(211);
  cout << time(0) << endl;
  inputarray(array, N_DEFAULT);
  cout << "input array:";
  printarray(array, N_DEFAULT);
  bubblesort(array, N_DEFAULT);
  cout << "sorted array:";
  printarray(array,N_DEFAULT);
  return 0;
}




void inputarray(int *p, int length){

  int i;
  for(i=0;i<length;i++){
//    cout << "please input integers: ";
//    cin >> p[i];
//    cout << endl;
    p[i]=rand()%300;
  }
  cout << "array length is "<< i << endl;
} 

void bubblesort(int* p, int length){

  int i,j;
  int swap;
  for(i=0;i<length;i++){
    for(j=0;j<length-i-1;j++){
      if (p[j]>p[j+1]) {swap=p[j]; p[j]=p[j+1]; p[j+1]=swap;}
    }
  }
}

void printarray(int* p, int length){

  int i;
  for(i=0;i<length;i++){
    cout << *p <<" ";
    p++;
  }
  cout << endl;
}
