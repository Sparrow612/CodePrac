//
//  test.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/4/17.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include "test2.hpp"

using namespace std;

extern template void myfunc<int>(int);


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
    B(){
        
    }
    B(int a){
        cout<<"B: "<<a<<endl;
    }
    virtual B* clone(){
        cout<<"clone B"<<endl;
        return this;
    }
    virtual void f(int a=0){
        cout<<"class B"<<a<<endl;
    }
};

class C{
public:
    void f(){
        cout<<"class C"<<endl;
    }
};

//class D:public B {
////public:
////    void f(){
////        B::f();
////        C::f();
////    }
//public:
//    D(){
//
//    }
//    D(int a): B(a){
//        cout<<"D: "<<a<<endl;
//    }
//    D* clone(){
//        cout<<"clone D"<<endl;
//        return this;
//    }
//    void f(int a=1){
//        cout<<"class D"<<a<<endl;
//        cout<<a<<endl;
//    }
//
//};

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
    static int a;
    Member(){
        cout<<"Member"<<endl;
    }
    ~Member(){
        cout<<"Member"<<endl;
    }
    void f() const{
        cout<<a++<<endl;
        cout<<a<<endl;
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
//int main(){
//    int res[0];
//    int * end =res;
//    cout<<(end-1>end)<<endl;
//}
//int main(){
//    D d(3);
//}

//int main(){
//    vector<int> res;
//    int a = res.size();
//    cout<<a<<endl;
//}

void h() {
    cout << "调用h" << endl;
    throw "abcd";
}

void g() {
    cout << "调用g" << endl;
    try {
        h();
    }
    catch (int) {
        cout << "int被g捕获" << endl;
    }
}

void f() {
    cout << "调用f" << endl;
    try {
        g();
    }
    catch (int) {
        cout << "int被f捕获" << endl;
    }
    catch (const char *) {
        cout << "const char *被f捕获" << endl;
    }
}

enum t { zero, null = 0, one, ones = 1 };

//int main() {
//    t a = zero;
//    cout<<(zero==null)<<endl;
//    cout<<(one==ones)<<endl;
//    switch (a) {
//        case null:
//            cout<<"null!"<<endl;
//            break;
//
//        default:
//            break;
//    }
//    char * a = "abc";
//    const char * b = "abc";
//    char c[4] = "abc";
//    cout<<a<<endl<<b<<endl<<c<<endl;
//    cout<<(int *)a<<endl<<(void *)b<<endl<<&c<<endl;
//    vector<int> * d = new vector<int>;
//    d->push_back(1);
//    cout<<(*d)[0]<<endl;
//    int e = 5;
//    array<int, 5> f;
//}

class Worker{
public:
    Worker(){
        cout<<"Default Cons!"<<endl;
    }
    Worker(int i){
        cout<<i<<endl;
        cout<<"You made it!";
    }
};

class Singer: virtual public Worker{
public:

    Singer(int i): Worker(i){
        // Banned by cpp
    }
};

class Waiter: virtual public Worker{
public:
    
    Waiter(int i): Worker(i){
        // Banned by cpp
    }
};

class SingingWaiter: public Singer, public Waiter{
public:
    SingingWaiter(int i): Worker(i), Singer(i), Waiter(i){
        // 不能通过中间类传信息给基类，这里会调用基类默认构造函数
        // Default Cons!
        // 除非显示声明基类构造
    }
};

int Member::a = 1; // 定义不能在方法中

template <class T>
class auto_ptr{
private:
    T * ptr;
public:
    auto_ptr(){}
    auto_ptr(T* p) { ptr = p; }
    ~auto_ptr(){ delete ptr; }
};

class D {
public:
    D() { d1=d2=0; cout<<"Default constructor callrd.\n";}
D(int i,int j) {
d1=i; d2=j;
cout<<"Constructor called."<<"d1="<<d1<<','
<<"d2="<<d2<<endl;
    
}
~D() { cout<<"Destructor called."<<"d1=" <<d1<<','<<"d2="<<d2<<endl; }
void Set(int i,int j) {
    d1 = i;
    d2 = j;
}
private:
    int d1,d2;
};

class Rational{
    static const int a = 1;
public:
    int n, d;
    Rational(int a, int b): n(a), d(b){}
    const Rational& operator * (const Rational& r)const{
        Rational *result  = new Rational(n*r.n, d*r.d);
        return *result;
    }
};

class TestBase{
public:
    void test(){
        cout<<"TestBase"<<endl;
    }
};

class TestDerived: public TestBase{
public:
    void test(){
        cout<<"TestDerived!!!!!"<<endl;
    }
};


//int main(){
//
//    TestDerived * t = new TestDerived;
//    t->test();
//
////    const char c[4] = "abc";
////    const char d[4] = "abc";
////
////    const char * a = "abc";
////    const char * b = "abc";
////
////    cout<<(a==b)<<endl;
////    cout<<(c==d)<<endl;
//
////    Rational w(0,0);
////    Rational x(1,1), y(2,2), z(3,3);
////    w = x*y;
////    w.n= 0;
////    cout<<w.n<<endl<<w.d<<endl;
//
//
////    SingingWaiter * s = new SingingWaiter(1);
////    B* b = new D;
////    b->f();
////    myfunc(1);
////    int * p = new int[5];
////    delete[] p;
////    list<int> v;
//
////    int a[3][3] = {{0,2,1},{1,0,2},{1,2,0}};
////    for (int i=0;i<=2;i++){
////        for (int j=0; j<=2; j++) {
////            a[i][j] = a[a[i][j]] [a[j][i]];
////        }
////    }
////    for (int i=0;i<=2;i++){
////        for (int j=0; j<=2; j++) {
////            cout<<a[i][j];
////        }
////        cout<<endl;
////    }
////
////
////
////    Member * m = new Member;
////
////    m->f();
//
////    int x = 9999; int countx = 0;
////    while(x){ x = x & (x-1);
////    countx++; }
////    cout<<countx<<endl;
//
////    int n =10, m =20;
////    D d[4] = {D(5,7),D(3,6),D(7,9),D(1,4)};
////    for (int i=0;i<4;i++)
////        d[i].Set(n++, m++);
//
//}


// 该类供测试语法用
