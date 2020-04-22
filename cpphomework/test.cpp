//
//  test.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/4/17.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>

using namespace std;

class Base{
public:
    virtual void print(){
        cout<<"Base"<<endl;
    }
    virtual void print(int i){
        cout<<"Base:"<<i<<endl;
    }
    virtual void purevir()=0;
};

class Derive:public Base{
public:
    void purevir(){
        Base::purevir();//复用父类的实现
//        cout<<"a impl of pure"<<endl;
    }
};

void Base::purevir(){
    cout<<"a pure virtual function"<<endl;
}//纯虚函数也是可以被定义、调用的！

//int main(){
//    Derive d;
//    d.purevir();
//}

// A file to test cpp syntax


