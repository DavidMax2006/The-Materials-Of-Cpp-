#include <iostream> //预处理命令，iostream是C++的一个输入、输出流媒体的声明文件
using namespace std;
int max(int x,int y) //定义max函数，函数值为整型，形式参数x，y 为整型
{      //max函数体开始
  int z;  //变量声明，定义本函数中用到的变量z为整型
  if(x>y) z=x; //if语句，如果x>y，则将x的值赋给z
else z=y;  //否则，将y的值赋给z
  return(z);  //将z的值返回，通过max带回调用处
}  //max函数结束

int main()  //主函数
{    //主函数体开始
  int a,b,m;  //变量声明
    cin>>a>>b;  //输入变量a和b的值
    m=max(a,b); //调用max函数，将得到的值赋给m
    cout << "max=" <<m<<'\n'; //输出大数m的值
    return 0;  //如程序正常结束，向操作系统返回一个零值
}   //主函数结束

/* 如果先写main函数，再写max函数：
##include <iostream>
using namespace std;
int main()
{ int max(int x,int y);
  int a,b,c;
  std::cin >>a>>b;
  c=max(a,b);
  std::cout << "max=" <<c<<'\n';
  return 0;
}

int max(int x,int y)
{ int z;
  if(x>y)z=x;
  else z=y;
  return(z);
}
*/
