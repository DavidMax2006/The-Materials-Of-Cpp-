#include<iostream>
using namespace std;
void merge(int a1[], int na1, int a2[], int na2) {
  int tmp[1000];
  int t = 0, i = 0, j = 0, k = 0;
  while( i < na1&&j < na2){
    if (a1[i] > a2[j]) {
    tmp[t++] = a2[j++];
  }
  else tmp[t++] = a1[i++];
  }
  while (i < na1) {
    tmp[t++] = a1[i++];
  }
  while (j < na2) {
    tmp[t++] = a2[j++];
  }
  while(k<t){
    a1[k] = tmp[k++];
  }
 }
 void mergeSort(int a[],int len) {
   if (len>1) {
     int mid = len / 2;
     int *a1 = a;
     int na1 = mid;
     int *a2 = a + mid ;
     int na2 = len - mid;
     mergeSort(a1, na1);
     mergeSort(a2, na2);
     merge(a1, na1, a2, na2);
   }
 }

int main() {
  int a[] = {0,7,5,2,1,3,8,4,6,9 };
  int len = sizeof(a) / sizeof(a[0]);
  mergeSort(a,len);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
