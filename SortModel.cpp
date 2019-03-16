#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class stdSort {   //State a class named stdSort
private:  //The following is the private part of the class
  int ways;   //private variable ways
  //int sort;  //private variable sort
public:  //The following is the public part of the class
 int sd;
 //SWint ss;
  void setdata() {   //Define the public function setdatain >> ways;  //Enter a value for ways
    cin >> ways;  //Enter a value for Sort
    sd=ways;
  }
}; //class over

void selectSort(int a[], int len) {
  for (int i = 0; i < len - 1; ++i) {
    int minIndex = i;
    for (int j = i; j < len; ++j) {   /* Find the index of the smallest element in the unordered region */
      if (a[j] < a[minIndex]) {
        minIndex = j;
      }
    }
    swap(a[i],a[minIndex]);  /* The first element of the unordered area is swapped with the minimum */
  }
}

void selectSort_unroutine(int a[], int len) {
  for (int i = 0; i < len - 1; ++i) {
    int minIndex = i;
    for (int j = i; j < len; ++j) {   /* Find the index of the smallest element in the unordered region */
      if (a[j] > a[minIndex]) {
        minIndex = j;
      }
    }
    swap(a[i],a[minIndex]);  /* The first element of the unordered area is swapped with the minimum */
  }
}

void sertSort(int a[], int len) {
  for (int i = 1; i < len; ++i) {
    int key = a[i];
    int left = 0, right = i-1;
    while (!(left > right)) {  //Find the position in the interval
      int middle = (left + right) / 2;
      if (a[middle] > key)
           right = middle-1;
      else left = middle+1;
    }
    for (int j = i - 1; !(j<left); --j) {
      a[j+1] = a[j];
    }
    a[left] = key; /* Left is the location where the new element does not need to be inserted */
  }
}

void sertSort_unroutine(int a[], int len) {
  for (int i = 1; i < len; ++i) {
    int key = a[i];
    int left = 0, right = i-1;
    while (!(left > right)) {  //Find the position in the interval
      int middle = (left + right) / 2;
      if (a[middle] < key)
           right = middle-1;
      else left = middle+1;
    }
    for (int j = i - 1; !(j<left); --j) {
      a[j+1] = a[j];
    }
    a[left] = key; /* Left is the location where the new element does not need to be inserted */
  }
}

void shellSort(int a[], int len) {
  int gap = len ;
  while (gap = gap / 2) {   //increment
    cout << "Each column to be sorted："<<endl;
    for (int i = gap; i < len; i++) {
      cout << i << " ";
      int key = a[i];   //Elements to be sorted
      int j = i - gap;
      for (; j+1>0&&a[j ] > key; j -= gap) {  //Insert sort
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

   void shellSort_unroutine(int a[], int len) {
     int gap = len ;
     while (gap = gap / 2) {   //increment
       cout << "Each column to be sorted："<<endl;
       for (int i = gap; i < len; i++) {
         cout << i << " ";
         int key = a[i];   //Elements to be sorted
         int j = i - gap;
         for (; j+1>0&&a[j ] < key; j -= gap) {  //Insert sort
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

void merge_unroutine(int a1[], int na1, int a2[], int na2) {
  int tmp[1000];
  int t = 0, i = 0, j = 0, k = 0;
  while( i < na1&&j < na2){
    if (a1[i] < a2[j]) {
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

void mergeSort_unroutine(int a[],int len) {
  if (len>1) {
    int mid = len / 2;
    int *a1 = a;
    int na1 = mid;
    int *a2 = a + mid ;
    int na2 = len - mid;
    mergeSort_unroutine(a1, na1);
    mergeSort_unroutine(a2, na2);
    merge_unroutine(a1, na1, a2, na2);
  }
}

void quickSort(int a[], int low, int high) {
  if (low < high) {
    int i = low - 1;
    int j = low;
    int key = a[high]; //Standard
    for (int j = low; j <= high; ++j) {  /* To bring forward an element smaller than or equal to a reference */
      if (a[j] <=key) {
        ++i; swap(a[i], a[j]);
      }
    }
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
  }
}

void quickSort2(int a[], int low, int high) {
  if (low >= high)
  return;
  int i, j, key;
  i = low;
  j = high;
  key = a[low];
  while (i < j) {
    while (i<j&&a[j]>=key) {
      j--;
    }
    a[i] = a[j];
    while (i < j&&a[i] <=key) {
      i++;
    }
    a[j] = a[i];
  } a[i] = key; //
  quickSort2(a, low, i - 1);
  quickSort2(a, i + 1, high);
}

void heap(int a[],int node,int len) {
  int nodecopy = a[node];
  for (int i = 2 * node + 1; i < len; i = 2 * i + 1) {  /* Iterate through all of node's subordinate nodes */
    if(i + 1 < len&&a[i + 1] > a[i])  /* If the right subtree node exists and the right subtree node is greater than the left subtree, move the subscript to the right subtree position */
    i++;
    if (a[i] > a[node]) {
      a[node] = a[i];
      node = i;
    }
  }
  a[node] = nodecopy; //Determine the final location of a[node]
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

void countSort(int a[], int len) {
  int low = a[0], high = a[0];
  for (int i = 0; i < len; ++i) {  //Find a range
    low = a[i] < low ? a[i] : low;
    high = a[i] > high ? a[i] : high;
  }
  int range = high - low+1;
  int *count = new int[range];
  //memset(count, 0, sizeof(int)*(range));
  for(int i=0;i<len;++i){  //Statistical frequency
    count[a[i]-low]++;
  }
  for (int i = 0,j=0; i < range; ++i) {  //value
    while (count[i]--) {
      a[j++] = i+low;
    }
  }
}

int getnum(int a[], int len) {
  int max = a[0];
  int num = 1;
  for (int i = 1; i < len; ++i) {
    max=a[i] > max ? a[i] : max;
  }
  while (max /= 10) {
    num++;
  }
  return num;
}
void radixSort(int a[], int len) {
  int num = getnum(a, len); //Get digits
  vector<vector<int> >radix(10);
  for(int k=0;k<num;++k){
    for (int i = 0; i < len; ++i) {  //Storage elements
      int t = int(a[i]);
      radix[t].push_back(a[i]);
    }
    vector<vector<int> >::iterator p;
    vector<int>::iterator q;
    int i = 0;
    for (p = radix.begin(); p != radix.end(); ++p) {  //Remove the element
      for (q = (*p).begin(); q !=(*p).end(); ++q) {
        a[i++] = *q;
      }
    }
    for (int i = 0; i < 10; ++i) {  //Empty the container of elements
      if(!radix[i].empty())
      radix[i].clear();
    }
  }
}

int getRange(vector<int> a, int begin, int end,int &min,int &max) { /* Gets the array element range and extremum */
  for (int i = begin + 1; i <= end; ++i) {
    min = a[i] < min ? a[i] : min;
    max = a[i] > max ? a[i] : max;
  }
  return max - min+1;
}
void bucketSort(vector<int>&a, int begin, int end) { /*The container USES reference passing as a parameter to reverse the order of elements */
  if (end - begin <1) return;  //Recursiv
  int min, max;min=max = a[0];
  int range = getRange(a, begin, end, min, max);   /* Gets the element range and extremum */
  int bucketNum = 5;    //This time set 5 backet
  int gap = range / 5+1;  //Set bucket interval
  vector <vector<int > > bucket(bucketNum);   /* Use a two-dimensional container to hold the barrels */
  for (int i = begin; i <= end; ++i){
    cout << "bucket number： " << (a[i] - min) / gap << "Drop element：" << a[i] << endl;
    bucket[(a[i]-min )/ gap] .push_back( a[i]);
       //The elements are placed in different buckets
  }
  for (int i = 0; i < bucketNum; ++i) {
    bucketSort( bucket[i],0,bucket[i].size()-1);  /* Recursively call bucket sort on the elements in the bucket */
  }
  for (int i = 0,j=0; i < bucketNum; ++i) {
    if (!bucket[i].empty()) {   //The bucket is not empty
      for (vector<int>::iterator p = bucket[i].begin(); p!=bucket[i].end(); ++p) {  /* The elements sorted in the bucket are put back into the original container a */
        a[j++] = *p;
      }
    }
  }
  cout << endl;
}
void swap(int &a, int &b) {
  printf("\n%s%d %d\n", "number0: ",a,b);  //export code
  int tmp = a;
  a = b;
  b = tmp;
  printf("%s%d %d\n", "number: ",a,b); //export code
}
/**
 * [bubbleSort description]
 * @param a   The nums-group that you want to sort
 * @param len The nums-group's figure(lenth)
 */
void bubbleSort(int a[],int len) {
  int low = 0, high = len - 1;int t=1;
        while (low < high) {  //Sort number of times, sort interval [low,high]
          int flag = 0;  //Flag point
          //The first one is bubbling forward
          for (int i = low; i < high; ++i) {
              if (a[i] > a[i+1]) {
                  swap(a[i], a[i + 1]);
                     for (int j = 0; j < 11; ++j)
                        cout <<" "  << a[j];
                      flag = i;
                    }

                  }
                  high = flag;   /*The elements after the marking point have been arranged and the left value of the interval has been reduced */
                  cout <<"---"  << t;
                  t++;

          }
  //printf("%s %c\n", "This is bubbleSort ",stud1.ss);
}

void bubbleSort_unroutine(int a[],int len) {
  int low = 0, high = len - 1;
        while (low < high) {  //Sort number of times, sort interval [low,high]
          int flag = 0;  //Flag point
          //The first one is bubbling forward
          for (int i = low; i < high; ++i) {
              if (a[i] < a[i+1]) {
                  swap(a[i], a[i + 1]);
                     //for (int j = 0; j < 11; ++j)
                      //  cout <<" "  << a[j];
                      flag = i;
                    }
                  }
                  high = flag;   /*The elements after the marking point have been arranged and the left value of the interval has been reduced */
          }
  //printf("%s %c\n", "This is bubbleSort ",stud1.ss);
}

int main(int argc, char const *argv[]) {
number0:
  stdSort stud1;  /* Define stud1 and stud2(useless) as variables of the stdSort class, called objects */
  stud1.setdata();   //Call the setdata function of the object stud1
  //stud2.setdata();   //Call the setdata function of the object stud2(useless)
  int a[] = { 1,2,3,4,5,6,7,8,9};
  //int a[] = { 520,0,1,9,56,100,1,85,5,3,6 };
  int len = sizeof(a) / sizeof(a[0]);
  switch (stud1.sd) {   /* After running, press 1-16 nums(10 sorts,QuickSort has 2 ways,and some sorts have unroutines) to change case, you can change nums-group what you want */
    case 1:
        printf("%s%d\n", "This is bubbleSort ");
        bubbleSort(a, len);
        for (int i = 0; i < len; ++i)
        std::cout << " " << a[i];
        break;
    case 12:
        printf("%s%d\n", "This is bubbleSort(unroutine) ");
        bubbleSort_unroutine(a, len);
        for (int i = 0; i < len; ++i)
        std::cout << " " << a[i];
        break;
    case 2:
        printf("%s\n", "This is selectSort");
        selectSort(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
    case 13:
        printf("%s\n", "This is selectSort(unroutine)");
        selectSort_unroutine(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
   case 3:
        printf("%s\n", "This is insertSort");
        sertSort(a, len);
        for (int i = 0; i < len; ++i)
            cout <<" "  << a[i];
        break;
   case 14:
        printf("%s\n", "This is insertSort(unroutine)");
        sertSort_unroutine(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 4:
        printf("%s\n", "This is shellSort");
        shellSort(a, len);
        cout << "Sort result：";
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 15:
        printf("%s\n", "This is shellSort(unroutine)");
        shellSort_unroutine(a, len);
        cout << "Sort result：";
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 5:
        printf("%s\n", "This is mergeSort");
        mergeSort(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 16:
        printf("%s\n", "This is mergeSort(unroutine)");
        mergeSort_unroutine(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 6:
        printf("%s\n", "This is QuickSort-Way1");
        quickSort(a, 0, len - 1);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 7:
        printf("%s\n", "This is QuickSort-Way2");
        quickSort2(a, 0, len - 1);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 8:
        printf("%s\n", "This is heapSort");
        heapSort(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 9:
        printf("%s\n", "This is countSort");
        heapSort(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 10:
        printf("%s\n", "This is radixSort");
        radixSort(a, len);
        for (int i = 0; i < len; ++i)
          cout <<" "  << a[i];
        break;
  case 11:
        printf("%s\n", "This is BacketSort" );
        vector<int>a;
        for (int i = 0,j=100; i<20; ++i) {
          a.push_back(j--);
        }
        bucketSort(a, 0, a.size()-1);
        cout << "Sort result：" << endl;
        for (int i = 0; i<a.size(); ++i) {
          cout << "  "<<a[i];
        }
        break;

  }
  goto number0;
  return 0;
}
