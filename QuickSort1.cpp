#include<iostream>
using namespace std;
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void quickSort(int a[], int low, int high) {
  if (low < high) {
    int i = low - 1;
    int j = low;
    int key = a[high]; //基准
    for (int j = low; j <= high; ++j) {  //使比基准小或等于基准的元素前移。
      if (a[j] <=key) {
        ++i; swap(a[i], a[j]);
      }
    }
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
  }
}

int main() {
  int a[] = { 0,4,1,2,3,0,0,0 };
  int len = sizeof(a) / sizeof(a[0]);
  quickSort(a, 0, len - 1);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar();
  return 0;
}
