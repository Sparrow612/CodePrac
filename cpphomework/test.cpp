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
};

class Derive:public Base{
public:
    using Base::print;
    virtual void print(){
        cout<<"Derive"<<endl;
    }
};

//int main(){
//    Derive d;
//    d.print();
//    d.print(8);
//}

// A file to test cpp syntax


