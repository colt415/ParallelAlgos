//just ranking

#include <iostream>
#include <cmath>

using namespace std;

void inputarray(int *p, int length);
void ranking(int *p1, int length1, int *p2, int length2, int *p);
void printarray(int *p, int length);

#define N_DEFAULT1 5
#define N_DEFAULT2 1

int main(){
  
  int array1[N_DEFAULT1];
  int array2[N_DEFAULT2];
  int mergearray[N_DEFAULT1+N_DEFAULT2];
  
  inputarray(array1, N_DEFAULT1);
  inputarray(array2, N_DEFAULT2);
  cout << "input array:";
  printarray(array1, N_DEFAULT1);
  printarray(array2, N_DEFAULT2);
  ranking(array1, N_DEFAULT1, array2, N_DEFAULT2,mergearray);
//  longranking(array1, N_DEFAULT1, array2, N_DEFAULT2, mergearray);
  cout << "sorted array:";
  printarray(mergearray,N_DEFAULT1+N_DEFAULT2);
  return 0;
}

void inputarray(int *p, int length){

  int i;
  for(i=0;i<length;i++){
    cout << "please input integers: ";
    cin >> p[i];
    cout << endl;
  }
  cout << "array length is"<< i << endl;
} 

void ranking(int *p1, int length1, int *p2, int length2, int *p){

  int length=length1+length2;
  int i, j;
  for(i=0;i<length1;i++){
    for(j=0; j<length2; j++){
      if (p1[i]<=p2[j]) {break;}
     }
    *(p+i+j)=p1[i];
  }

  for(i=0;i<length2;i++){
    for(j=0; j<length1; j++){
      if (p2[i]<p1[j]) {break;}
     }
    *(p+i+j)=p2[i];
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


