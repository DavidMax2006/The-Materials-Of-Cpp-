#include<iostream>
using namespace std;
void swap(int&a, int&b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void shellSort(int a[], int len) {
  int gap = len ;
  while (gap = gap / 2) {   //增量
    cout << "Each column to be sorted："<<endl;
    for (int i = gap; i < len; i++) {
      cout << i << " ";
      int key = a[i];   //待排序元素
      int j = i - gap;
      for (; j+1>0&&a[j ] > key; j -= gap) {  //插入排序
        a[j + gap] = a[j]; } a[j + gap] = key;
      }
      cout << endl;
      cout << "increment" << gap << "sort result：" << endl;
      for (int i = 0; i < len; ++i) {
        cout << " " << a[i];
       }
       cout <<endl;
     }
   }

   int main() {
     int a[] = { 10,8,4,3,1,5,7,9,2,6};
     int len = sizeof(a) / sizeof(a[0]);
     shellSort(a, len);
     cout << "Sort result：";
     for (int i = 0; i < len; ++i) {
        cout << " " << a[i];
      }
      //getchar();
      return 0;
    }
