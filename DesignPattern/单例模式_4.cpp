// 懒汉式线程同步

#include <iostream>
using namespace std;

class Singleton {  // 定义Singleton类
public:
    static Singleton *get_instance();  // 定义静态成员函数
    int get_var();
    void set_var(int);
private:
    Singleton(); //声明构造函数为私有成员
    virtual ~Singleton(); //声明虚析构函数
    static Singleton *instance; //定义静态数据成员
    int var;
};

Singleton::Singleton() {  //定义构造函数
    var = 20;
    cout << "Singleton constructor!" << endl;
} 

Singleton::~Singleton() {  //定义析构函数
    delete instance;
} 

Singleton *Singleton::instance = NULL;  // 对静态数据成员进行初始化

// 定义静态成员函数get_instance()， 该函数操作静态数据成员instance
// 第一次调用本函数时， 为instance提供有效值并一直保留到程序运行完毕
Singleton *Singleton::get_instance() {
    if (NULL == instance){  
        //本函数第一次调用时， 创建一个Singleton对象， 对象地址由instance记录
        //该对象将一直存在直到程序结束
        instance = new Singleton();
    } 
    return instance;
} 

int Singleton::get_var() { //定义get_var()成员函数
    return var;
} 

void Singleton::set_var(int n) {  //定义set_var()成员函数
    var = n;
} 

int main() {
    //定义两个Singleton*变量， 并通过get_instance()函数为其初始化
    //第一次调用get_instance()时创建对象， 对象地址记录在p1中
    Singleton *p1 = Singleton::get_instance();
    //第二次调用get_instance()时， 不再创建对象， p2与p1记录同一个对象地址
    Singleton *p2 = Singleton::get_instance();
    cout << "p1 var = " << p1->get_var() << endl;
    cout << "p2 var = " << p2->get_var() << endl;
    p1->set_var(5);
    cout << "p1 var = " << p1->get_var() << endl;
    cout << "p2 var = " << p2->get_var() << endl;
    system("pause");
    return 0;
}


// ===============

// #include <iostream>
// #include <string>
// using namespace std;

// // #define public private
// class { 
// public:
// protected:
// private:
// }a1;

// class Singleton { 
// private:
//     int i;
//     static Singleton *instance;
//     Singleton(int i) {
//         this->i = i;
//     }
// public:
//     static Singleton *getInstance() {
//         return instance;
//     } 
//     void show() {
//         cout << i << endl;
//     }
// };

// Singleton* Singleton::instance = new Singleton(8899);

// class A :public Singleton { 
// };

// int mainJ() {
//     Singleton *s = Singleton::getInstance();
//     Singleton *s2 = A::getInstance();
//     cout << (s == s2) << endl;
//     cin.get();
//     return 0;
// }
