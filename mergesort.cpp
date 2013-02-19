//merge sorting

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

void inputarray(int *p, int length);
void mergesort(int *p, int length);
void ranking(int *p1, int length1, int *p2, int length2, int *p);
void longranking(int *p1, int length1, int *p2, int length2, int *p);
void pranking(int **p1, int length1, int **p2, int length2, int **p);
void printarray(int *p, int length);
int pow2(int length);
void copy(int * p1, int * p2,int length);

#define N 37
#define TYPE struct segment
#define Null 0

struct segment{
  int len;
  int start;
  struct segment * next;
};

int main(){
  int N_sort,N_remn,l;
  int array[N];
  srand(time(0));
  inputarray(array, N);
  cout << "input array:";
//  cout << "asdfjiasdjfl;";
  printarray(array, N);
//   cout << "asdfjiasdjfl;";
  TYPE * p, * pn, * head;
  head=new TYPE;
  pn=head;
  N_sort=0; N_remn=N;
//  cout << N_remn << endl;
  while(N_remn>0){
    p=pn;
    p->start=N-N_remn;
//    cout << p->start << endl;
    l=pow2(N_remn);
//    cout << l << endl;
//    cout << N_sort <<" "<< N_remn<<"\n";
    N_sort=pow(2,l);
    N_remn=N_remn-N_sort;
    p->len=N_sort;
    p->next= new TYPE;
    pn=p->next;
  }
  p->next=Null;
/*
  pn=head;
  while(pn!=Null){
    p=pn;
//    cout << p->len << " " << p->start << "\n";
    pn=p->next;
  }
*/
  delete pn;
  
  pn=head;
  while(pn!=Null){
    p=pn;
    mergesort(array+p->start,p->len);
    pn=p->next;
  }
  cout << "intermediate step: "; 
  printarray(array,N);  
  int accum=head->len;
  int temp1[N];
  p=head;
  pn=p->next;
  while(pn!=Null){
      p=pn;
      longranking(array,accum, array+p->start, p->len,temp1);
      copy(temp1,array,p->len+accum);
      accum+=p->len;
      pn=p->next;
  }

//  mergesort(array,N);
  cout << "sorted array:";
  printarray(array,N);
  return 0;
}


void copy (int * p1, int * p2, int length){
  int i;
  for(i=0; i<length;i++){
    *(p2+i)=*(p1+i);
  }
}

int pow2(int length){
  int i=0;
  while(pow(2,i)<=length){
    i++;
  }
  return i-1;
}

  
  
void inputarray(int *p, int length){
  
  int i;
  for(i=0;i<length;i++){
    p[i]=rand()%2000;
  }
  cout << "input array length is: " << i << endl;
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
//  cout << n1 <<" "<< n2 << endl;
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
//    cout << *(p+j+(i+1)*n1-1)<< endl;
    partition12[i]=p2+j;
//    if (j==length2) {partition12[i]--;}
  }
  
  for(i=0;i<n2;i++){
    for(j=0;j<length1;j++){
      if(p2[(i+1)*n2-1]<p1[j]){
        break;}
    }
    *(p+j+(i+1)*n2-1)=p2[(i+1)*n2-1];
//    cout << *(p+j+(i+1)*n2-1)<< endl;
    partition21[i]=p1+j;
//    if (j==length1) {partition21[i]--;}
  } 
  
  pranking(partition11,n1,partition21,n2,partitiont1);
  pranking(partition22,n2,partition12,n1,partitiont2);
  
  ranking(p1,partitiont1[0]-p1, p2, partitiont2[0]-p2, p);
  for(i=0;i<n1+n2-1;i++){
//    if((partitiont1[i]-p1<length1)&&(partitiont2[i]-p2<length2)){
    ranking(partitiont1[i],partitiont1[i+1]-partitiont1[i],partitiont2[i],partitiont2[i+1]-partitiont2[i], p+(partitiont1[i]-p1)+(partitiont2[i]-p2));

  }
  if((partitiont1[i]-p1<length1)&&(partitiont2[i]-p2<length2)){
  ranking(partitiont1[n1+n2-1], p1+length1-partitiont1[n1+n2-1], partitiont2[n1+n2-1], p2+length2-partitiont2[n1+n2-1], p+(partitiont1[n1+n2-1]-p1)+(partitiont2[n1+n2-1]-p2));
  }
  else if (partitiont1[i]-p1>=length1){
    for(j=0;j<p2+length2-partitiont2[n1+n2-1];j++){ *(p+(partitiont1[n1+n2-1]-p1)+(partitiont2[n1+n2-1]-p2)+j)=*(partitiont2[n1+n2-1]+j);}
  }
  else if (partitiont2[i]-p2>=length2){
    for(j=0;j<p1+length1-partitiont1[n1+n2-1];j++){ *(p+(partitiont1[n1+n2-1]-p1)+(partitiont2[n1+n2-1]-p2)+j)=*(partitiont1[n1+n2-1]+j);}
  }


}

void mergesort(int *p, int length){
  
  int i,j,k,d;
  int L;//length of temporary
  int temp[length];//temporary pointers for ranking
  for (i=0; i< length; i++){
    temp[i]=0;
  }
  d=int(log2(length));
  for(i=0; i<d; i++){
    L=pow(2,i);
    for(j=0; j<pow(2,d-i-1);j++){
      if(L>100){
        longranking(p+j*2*L, L, p+j*2*L+L, L, temp);
      }
      else {ranking(p+j*2*L, L, p+j*2*L+L, L, temp);}
      for(k=0; k<2*L;k++){
        p[j*2*L+k]=temp[k];
      }
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
