#include <iostream>
#include <vector>
using namespace std;
int getRange(vector<int> a, int begin, int end,int &min,int &max) { //获得数组元素范围和极值
  for (int i = begin + 1; i <= end; ++i) {
    min = a[i] < min ? a[i] : min;
    max = a[i] > max ? a[i] : max;
  }
  return max - min+1;
}
void bucketSort(vector<int>&a, int begin, int end) { //容器做参数时用引用传递来调换元素顺序
  if (end - begin <1) return;  //递归出口
  int min, max;min=max = a[0];
  int range = getRange(a, begin, end, min, max);   //获得元素范围和极值
  int bucketNum = 5;    //本次定义了5个桶
  int gap = range / 5+1;  //设定桶区间
  vector <vector<int > > bucket(bucketNum);   //用二维容器来装桶
  for (int i = begin; i <= end; ++i){
    cout << "bucket number： " << (a[i] - min) / gap << "Drop element：" << a[i] << endl;
    bucket[(a[i]-min )/ gap] .push_back( a[i]);
       //元素放在不同的桶里
  }
  for (int i = 0; i < bucketNum; ++i) {
    bucketSort( bucket[i],0,bucket[i].size()-1);  //对桶里的元素递归调用桶排序
  }
  for (int i = 0,j=0; i < bucketNum; ++i) {
    if (!bucket[i].empty()) {   //桶非空判断
      for (vector<int>::iterator p = bucket[i].begin(); p!=bucket[i].end(); ++p) {  //桶里排序好的元素放回原容器a
        a[j++] = *p;
      }
    }
  }
  cout << endl;
}

int main() {
  vector<int>a;
  for (int i = 0,j=100; i<20; ++i) {
    a.push_back(j--);
  }
  bucketSort(a, 0, a.size()-1);
  cout << "Sort result：" << endl;
  for (int i = 0; i<a.size(); ++i) {
    cout << "  "<<a[i];
  }
  return 0;
}
