//目标是十万的高质量代码行

/* Static

#include<iostream> 
using namespace std; 
void demo(){
    static int count;
    cout<<count<<endl;
    count++;
}
class Apple{
    public:
        int notstatic;
        static int i;
        Apple() 
        { 
            i = 0; 
            cout << "Inside Constructor\n"; 
        } 
        static void printMsg() //静态成员函数
        { 
            cout<<"Welcome to Apple!"<<endl; 
            i++;//静态访问静态,不能访问变量
            //notstatic=i; 
            // ERROR:invalid use of member 'Apple::notstatic' in static member function
            // notstatic=i;
            // ^
        } 

        ~Apple() 
        { 
            cout << "Inside Destructor\n"; 
        }

};

int Apple::i=1;//类的静态在声明时定义，比构造函数要早，如果构造时赋值会覆盖声明时的定义

int main(){
    for(int i=0;i<8;i++){
        demo();
    }
    int k=0;
    if(k==0){
        Apple a;//判断静态Apple的构造和析构是否在end of main 前面
        cout<<"Apple::i = "<<Apple::i<<endl;//类名访问静态成员
        Apple::printMsg();
        cout<<"a.i = "<<a.i<<endl;  //对象访问静态成员
        a.printMsg();
        a.notstatic=0;
        a.i=29;
        cout<<"a.i = "<<a.i<<endl;  //对象访问静态成员       
        cout<<a.notstatic<<endl;
        
    }
    cout<<"end of main"<<endl;
    return 0;
}
*/

//关于this的理解，this是这个类的指针,->age，相当于类首地址+偏移地址。任何一个非静态函数都有这样一个隐藏参数，因为类的位置不能变，内容可以变，所以this的类型 应该是class * const this
//常函数int get_age() const{} 调用this时会将this 改成const class * const this, 不允许修改类的内容
//对类的返回很有意思 用Person& 表示函数返回时是类的引用，这样就不会进行拷贝操作， return的是是类，不是类的指针，所以是*this
//    Person& add_age(int a){    Person& add_age(int a){age+=a; return *this; } 
//有个warning，char* name="zhangsan",会waringm,因为这样的写法意味着非常指针指向了常量，是不被允许的，但是为了兼容只会warning。char* name=(char*)"zhangsan"就不会warning，这是一个隐式转换
#include<iostream>
#include<cstring>


using namespace std;
class Person{
public:
    typedef enum{
        BOY=0,
        GIRL
    }SexType;
    Person(char *name,int a, SexType s){
        name=new char[strlen(name)+1];
        age=a;
        sex=s;

    }
    int get_age() const {
        return this->age;
    }
    Person& add_age(int a){
        age+=a;
        return *this;
    }
    ~Person(){
        delete [] name;
    }
private:
    char * name;
    int age;
    SexType sex;
};


int main(){
    char* name = "zhangsan";
    cout<<name<<endl;
    Person p((char*)"zhangsan",20,Person::BOY); 
    cout<<p.get_age()<<endl;
    cout<<p.add_age(2).get_age()<<endl;
    return 0;
}
