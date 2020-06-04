//
//  test.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/4/17.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>
#define maxl(a,b) (a)>(b)?(a):(b)

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

class MyExceptionBase{
public:
    ~MyExceptionBase(){
        cout<<"Delete MyExceptionBase"<<endl;
    }
};

class MyExceptionDerived: public MyExceptionBase{
public:
    ~MyExceptionDerived(){
        cout<<"Delete MyExceptionDerived"<<endl;
    }
};


void f(MyExceptionBase& e){
    cout<<"throw the base"<<endl;
}


class Base{
public:
    Base(){
        cout<<"Base"<<endl;
    }
    ~Base(){
        cout<<"Base"<<endl;
    }
};

class Member{
public:
    Member(){
        cout<<"Member"<<endl;
    }
    ~Member(){
        cout<<"Member"<<endl;
    }
};

class Derived: public Base{
private:
    Member m;
public:
    Derived(){
        cout<<"Derived"<<endl;
        throw -1;
    }
    ~Derived(){
        cout<<"Derived"<<endl;
    }
};

//int main (){
//    Derived * d;
//    try{
//        d=new Derived;
//        cout<<"!"<<endl;
//    }catch(...){
//        
//        cout<<"------------catch"<<endl;
//    }
//    cout<<"!"<<endl;
//}

//int main(){
////    Champion a;
////    Champion b;
////    a.fight(b);
////    D a;
////    D d;
////    a.f(d);
////    int a[]={1,2,3};
////    cout<<a[1];
//    char s[5];
//    char a[5];
//    char c[5];
//    cin.get(s,5);
//    cin.get(a,5);
//    char d=cin.get();
//    cin.get(c,5);
//    cout<<s<<endl;
//    cout<<a<<endl;
//    cout<<c<<endl;
//}
//int main(){
////    string a = "aacd";
////    cout<<a<<endl;
////    a[1]='b';
////    cout<<a<<endl;
////    a[1]='c';
////    cout<<a<<endl;
//    int a[6]={0,1,2,3,4,5};
//    int *p=a;
//    int ** e=&p;
//    cout<<e[0][5]<<endl;
//}

