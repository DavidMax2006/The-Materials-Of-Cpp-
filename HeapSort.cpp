#include<iostream>
using namespace std;
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void heap(int a[],int node,int len) {
  int nodecopy = a[node];
  for (int i = 2 * node + 1; i < len; i = 2 * i + 1) {  //遍历node所有下属节点
    if(i + 1 < len&&a[i + 1] > a[i]) /*如果右子树节点存在且右子树节点大于左子树，那么将下标移到右子树位置*/
    i++;
    if (a[i] > a[node]) {
      a[node] = a[i];
      node = i;
    }
  }
  a[node] = nodecopy; //确定a[node]最终位置
}
void heapSort(int a[],int len) {
  for (int node = len / 2 - 1; node >= 0; --node) {
    heap(a, node, len);
  }
  for (int i = len-1;i>0; --i) {
    swap(a[0], a[i]);
    heap(a, 0, i);
  }
}

int main() {
  int a[] = { 7,0,1,2,8,5,9, };
  int len = sizeof(a) / sizeof(a[0]);
  heapSort(a, len);
  for (int i = 0; i < len; ++i) {
    cout << " " << a[i];
  }
  //getchar(); 
}
