/*
重點: Derived class以public方式繼承Base class
1. Derived class產生的物件，只能呼叫與存取Base class中具有public存取權限的資料成員和成員函數。
2. 可在Derived class的成員函數呼叫與存取Base class中具有public或protected存取權限的資料成員和成員函數
*/
#include <iostream>
using namespace std;

class Base{
private:
    int pri_att;
    void pri_show(){
        cout << "Base::pri_show() is called." << endl;
    }
protected:
    int pro_att;
    void pro_show(){
        cout << "Base::pro_show() is called." << endl;
    }
public:
    Base():pri_att(1), pro_att(2), pub_att(3){}

    int pub_att;
    void pub_show(){
        cout << "Base::pub_show() is called." << endl;
    }
};


// 以public成員函數繼承Base類別
class Derived : public Base{
public:
    void call_fun();
    void show();
};
// 存取繼承自Base類別的"資料成員"
void Derived::show(){
    cout << endl;
    cout << "Derived::show() is called." << endl;
    cout << "Base::pub_att = " << pub_att << endl;
    cout << "Base::pro_att = " << pro_att << endl;
    // 無法存取private"資料成員"
    // cout << "Base::pri_att = " << pri_att << endl;
}
// 呼叫繼承自Base類別的"成員函數"
void Derived::call_fun(){
    cout << endl;
    cout << "Derived::call_fun() is called." << endl;
    pub_show();
    pro_show();
    // 無法呼叫private"成員函數"
    // pri_show();
}


int main(){

    Derived A_Derived;
    // 透過Derived物件呼叫繼承自Base類別的"資料成員"
    cout << "Accessing Derived's data members"
         << "inherited from Base..." << endl;
    // 可以存取public的"資料成員"
    cout << "Derived::pub_att = " << A_Derived.pub_att << endl;
    // 無法存取protected和private"資料成員"
    // cout << "Derived::pro_att = " << A_Derived.pro_att << endl; 
    // cout << "Derived::pri_att = " << A_Derived.pri_att << endl; 
    cout << endl;

    // 透過Derived物件呼叫繼承自Base類別的"成員函數"
    cout << "Call Derived's member functions"
         << "inherited from Base..." << endl;
    // 可存取public"成員函數"
    A_Derived.pub_show();
    // 無法存取protected和private"成員函數"
    // A_Derived.pro_show();
    // A_Derived.pri_show();

    // 呼叫Derived物件的show()"成員函數"
    // 測試Derived類別之成員函數是否可呼叫繼承自Base類別的"資料成員"
    A_Derived.show();

    // 呼叫Derived物件的call_fun()成員函數。
    // 測試Derived類別之成員函數是否可呼叫繼承自Base類別的"成員函數"
    A_Derived.call_fun();

    return 0;
}