//quick sorting

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputarray(int *p, int length);
int* partition(int *p,int *q);
void quicksort(int *p,int *q);
void printarray(int *p, int length);
void swap(int* p, int* q);

#define N_DEFAULT 100

int main(){
  int array[N_DEFAULT];
  int *q;
  q=array+N_DEFAULT-1;
  srand(time(0));
  inputarray(array, N_DEFAULT);
  cout << "input array:";
  printarray(array, N_DEFAULT);
  quicksort(array, q);
  cout << "sorted array:";
  printarray(array,N_DEFAULT);
  return 0;
}


void swap(int* p, int* q){
  int inter;
  inter=*p;
  *p=*q;
  *q=inter;
}
  

void inputarray(int *p, int length){

  int i;
  for(i=0;i<length;i++){
//    cout << "please input integers: ";
//    cin >> p[i];
//    cout << endl;
    p[i]=rand()%200;
  }
  cout << "array length is "<< i << endl;
} 
/*
void bubblesort(int* p, int length){

  int i,j;
  int swap;
  for(i=0;i<length;i++){
    for(j=0;j<length-i-1;j++){
      if (p[j]>p[j+1]) {swap=p[j]; p[j]=p[j+1]; p[j+1]=swap;}
    }
  }
}
*/

int* partition(int *p, int *q){

  int *pivotfront;
  int *pivotend;
//  int Nfront, Nend;
//  Nfront=0;
//  Nend=0;
  pivotfront=p;
  pivotend=q;
//  cout << *pivotend << endl;
//  cout << *pivotfront << endl;
  bool front, end, dete;
  dete=0;
  front=0;
  end=0;
  while(pivotfront<pivotend){
    while(!end){
      if (pivotfront==pivotend) {break;}
      if (*pivotfront>*pivotend){ 
        swap(pivotfront, pivotend); 
        end=1;
        pivotfront++;
//        Nfront++;
      }
      else {pivotend--;}
     // cout << *pivotend << endl;
    }
   while(!front){
      if (pivotfront==pivotend) {break;}
      if (*pivotfront>*pivotend){ 
        swap(pivotfront, pivotend); 
        front=1;
        pivotend--;
//        Nend++;
      }
      else {pivotfront++;}
     // cout << *pivotfront << endl;
    }
    front=0;
    end=0;
  }
return pivotfront;
}

void quicksort(int *p, int*q){
  if(q>p){
    int *median;
    median=partition(p,q);
    quicksort(p,median-1);
    quicksort(median+1,q);
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
