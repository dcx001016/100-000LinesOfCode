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