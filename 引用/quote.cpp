#include<iostream>

using namespace std;

// 使用引用来交换两个数的值
void numberChange(int &num1, int &num2){
    cout << "num1的地址："<< &num1 << "  num2的地址：" << &num2 << endl;
    int temp = 0;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int main(){
    int num1 = 10;
    int num2 = 20;
    cout << "n1的地址：" << &num1 << "  n2的地址：" << &num2 << endl;
    numberChange(num1, num2);
    cout << "num1:" << num1 << " num2:" << num2 << endl;
    return 0;
}