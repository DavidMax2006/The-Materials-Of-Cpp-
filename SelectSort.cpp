#include<iostream>
using namespace std;
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void selectSort(int a[], int len) {
  for (int i = 0; i < len - 1; ++i) {
    int minIndex = i;
    for (int j = i; j < len; ++j) {   //找出无序区最小元素的下标
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    swap(a[i],a[minIndex]);  //无序区第一个元素与最小值交换
  }
}

int main(int argc, char const *argv[]) {
  int a[] = { 5,89,562,4,2,0,56512,4512 };
  int len = sizeof(a) / sizeof(a[0]);
  selectSort(a,len);
  for (int i = 0; i < len; ++i) {
    std::cout << " " << a[i];
  }
  //getchar();
  return 0;
}
