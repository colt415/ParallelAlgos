//merge sorting

#include <iostream>
#include <cmath>
using namespace std;

void inputarray1(int *p, int length);
void inputarray2(int *p, int length);
void ranking(int *p1, int length1, int *p2, int length2, int *p);
void longranking(int *p1, int length1, int *p2, int length2, int *p);
void pranking(int **p1, int length1, int **p2, int length2, int **p);
void printarray(int *p, int length);

#define N_DEFAULT1 102
#define N_DEFAULT2 102

int main(){
  int array1[N_DEFAULT1];
  int array2[N_DEFAULT2];
  int mergearray[N_DEFAULT1+N_DEFAULT2];
  inputarray1(array1, N_DEFAULT1);
  inputarray2(array2, N_DEFAULT2);
  cout << "input array:";
  printarray(array1, N_DEFAULT1);
  printarray(array2, N_DEFAULT2);
//  ranking(array1, N_DEFAULT1, array2, N_DEFAULT2,mergearray);
  longranking(array1, N_DEFAULT1, array2, N_DEFAULT2, mergearray);
  cout << "sorted array:";
  printarray(mergearray,N_DEFAULT1+N_DEFAULT2);
  return 0;
}

void inputarray1(int *p, int length){
  
  int i;
  for(i=0;i<length;i++){
    p[i]=pow(i,2);
  }
}

void inputarray2(int *p, int length){
  
  int i;
  for(i=0;i<length;i++){
    p[i]=11*i+1;
  }
}




/*
void inputarray(int *p, int length){

  int i;
  for(i=0;i<length;i++){
    cout << "please input integers: ";
    cin >> p[i];
    cout << endl;
  }
  cout << "array length is"<< i << endl;
} 
*/


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

void pranking(int **p1, int length1, int **p2, int length2, int **p){

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


void longranking(int *p1, int length1, int *p2, int length2, int *p){
  
  int length=length1+length2;
  int n1, n2;
  n1=floor(pow(length1,0.5));
  n2=floor(pow(length2,0.5));
  cout << n1 <<" "<< n2 << endl;
  int i,j;
  int *partition11[n1], *partition22[n2], *partition12[n1], *partition21[n2];
  int *partitiont1[n1+n2], *partitiont2[n1+n2];
  
  for(i=0;i<n1;i++){
    partition11[i]=p1+(i+1)*n1-1;
  }
  
  for(i=0;i<n2;i++){
    partition22[i]=p2+(i+1)*n2-1;
  }
 
  for(i=0;i<n1;i++){
    for(j=0;j<length2;j++){
      if(p1[(i+1)*n1-1]<=p2[j]){
        break;}
    }
    *(p+j+(i+1)*n1-1)=p1[(i+1)*n1-1];
    cout << *(p+j+(i+1)*n1-1)<< endl;
    partition12[i]=p2+j;
    if (j==length2) {partition12[i]--;}
  }
  
  for(i=0;i<n2;i++){
    for(j=0;j<length1;j++){
      if(p2[(i+1)*n2-1]<p1[j]){
        break;}
    }
    *(p+j+(i+1)*n2-1)=p2[(i+1)*n2-1];
    cout << *(p+j+(i+1)*n2-1)<< endl;
    partition21[i]=p1+j;
    if (j==length1) {partition21[i]--;}
  } 
  
  pranking(partition11,n1,partition21,n2,partitiont1);
  pranking(partition22,n2,partition12,n1,partitiont2);
  
  ranking(p1,partitiont1[0]-p1, p2, partitiont2[0]-p2, p);
  for(i=0;i<n1+n2-1;i++){
    ranking(partitiont1[i],partitiont1[i+1]-partitiont1[i],partitiont2[i],partitiont2[i+1]-partitiont2[i], p+(partitiont1[i]-p1)+(partitiont2[i]-p2));
  }
  ranking(partitiont1[n1+n2-1], p1+length1-partitiont1[n1+n2-1], partitiont2[n1+n2-1], p2+length2-partitiont2[n1+n2-1], p+(partitiont1[n1+n2-1]-p1)+(partitiont2[n1+n2-1]-p2));

}



void printarray(int* p, int length){

  int i;
  for(i=0;i<length;i++){
    cout << *p <<" ";
    p++;
  }
  cout << endl;
}
