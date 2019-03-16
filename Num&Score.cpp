#include <iostream>  //预处理命令
using namespace std;
class Student {   //声明一个类，类名为Student
private:  //以下为类中的私有部分
  int num;   //私有变量num
  int score;  //私有变量score
public:  //以下为类中的公有部分
  void setdata() {   //定义公用函数setdata
    std::cin >> num;  //输入num的值
    std::cin >> score;  //输入score的值
  }
  void display() {  //定义公用函数display
    std::cout << "num=" <<num<<endl;  //输出num的值
    std::cout << "score=" <<score<<endl;   //输出score的值
  }
};   //类的声明结束
Student stud1,stud2;  //定义stud1和stud2为Student类的变量，称为对象
int main() {   //主函数首部
  stud1.setdata();   //调用对象stud1的setdata函数
  stud2.setdata();   //调用对象stud2的setdata函数
  stud1.display();   //调用对象stud1的display函数
  stud2.display();   //调用对象stud2的setdata函数
  return 0;
}
