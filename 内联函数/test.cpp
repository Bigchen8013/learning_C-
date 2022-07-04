#include<iostream>
#include<string.h>

using namespace std;

int add(int number1=100, int number2=200, bool isok = 0){
    cout << "调用第一个函数" << endl;
    return number1 + number2;
}

int add(int number1, int number2){
    cout << "调用第二个函数" << endl;
    return number1 + number2;
}

int add(int number1, int number2, ine number3){
    cout << "调用第三个函数" << endl;
    return number1 + number2 + number3;
}

int main(){
    cout << add(1) << endl;
    cout << add(1,2) << endl;
    return 0;
}