#include <iostream>
using namespace std;
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void bubbleSort(int a[],int len) {
  int low = 0, high = len - 1;
  while (low < high) {  //排序趟数，排序区间[low,high]
    int flag = 0;  //标志点
    for (int i = low; i < high; ++i) { //第一次正向冒泡
      if (a[i] > a[i+1]) {
        swap(a[i], a[i + 1]);
        flag = i;
      }
    }
    high = flag; //表示标志点之后的元素已经排好，区间左值缩小
  }
}

int main(int argc, char const *argv[]) {
  int a[] = { 520,0,1,9,56,100,1,85,5,3,6 };
  int len = sizeof(a) / sizeof(a[0]);
  bubbleSort(a, len);
  for (int i = 0; i < len; ++i) {
    std::cout << " " << a[i];
  }
  //getchar();
  return 0;
}
