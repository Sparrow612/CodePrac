//
//  test.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/4/17.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>

using namespace std;

//class Base{
//public:
//    virtual void print(){
//        cout<<"Base"<<endl;
//    }
//    virtual void print(int i){
//        cout<<"Base:"<<i<<endl;
//    }
//    virtual void purevir()=0;
//};
//
//class Derive:public Base{
//public:
//    void purevir(){
//        Base::purevir();//复用父类的实现
////        cout<<"a impl of pure"<<endl;
//    }
//};
//
//void Base::purevir(){
//    cout<<"a pure virtual function"<<endl;
//}//纯虚函数也是可以被定义、调用的！

//int main(){
//    Derive d;
//    d.purevir();
//}

// A file to test cpp syntax
class B{
protected:
    int val=17;
public:
    void f(){
        cout<<"class B"<<endl;
    }
};

class C{
public:
    void f(){
        cout<<"class C"<<endl;
    }
};

class D:public B {
//public:
//    void f(){
//        B::f();
//        C::f();
//    }
public:
    void f(D& d){
        cout<<d.val<<endl;
    }
    
};

class Champion{
private:
    int hp=10;
public:
    void fight(Champion& b){
        b.hp--;
        cout<<hp<<endl<<b.hp<<endl;
    }
};

//int main(){
////    Champion a;
////    Champion b;
////    a.fight(b);
////    D a;
////    D d;
////    a.f(d);
//    int a[]={1,2,3};
//    cout<<a[1];
//}

