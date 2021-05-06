//目标是十万的高质量代码行
//类名和结构名用大驼峰，变量和函数用小驼峰法

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

/*
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

*/

//argc 代表参数个数, *argv[] 代表参数指针数组 argv[0]程序路径，argv[1++] 参数

// #include<iostream>
// using namespace std;
// int main(int argc, char const *argv[])
// {
//     for(int i=0;i<argc;i++)
// 	{
// 		cout<<"argument["<<i<<"] is: "<<argv[i]<<endl;
// 	}
//     system("pause");
//     return 0;
// }

//****************
//终端输出
// PS E:\Code\MyRepository\100-000LinesOfCode\DengHongcheng> .\demo.exe 1 2 3 qaa
// argument[0] is: E:\Code\MyRepository\100-000LinesOfCode\DengHongcheng\demo.exe
// argument[1] is: 1
// argument[2] is: 2
// argument[3] is: 3
// argument[4] is: qaa



/*
//5.5阿里云二面，二叉树的序列化和反序列化，是剑指第37题，没有做到这里，有思路但是没能实现，任何一种遍历思想，只要存入空节点，就能确定唯一的二叉树（我：层序遍历

//1 层次遍历的代码, 用vector<vector<int>>  外层向量存每一层，内层向量存这一层的数值；队列存入这一层的所有树节点
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution{
    public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> ret;
        if(!root){
            return ret;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLevelSize = q.size();
            ret.push_back(vector<int> ());//一个复制构造，main中确认效果
            for(int i=1;i<currentLevelSize;q.size()){
                auto node=q.front();q.pop();
                ret.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
        }
    }
    }
};

int main(){
    vector<int> a = vector<int> (); //一个复制构造，确认上面的作用
    if(a.empty()){
        cout<<"empty"<<endl;
    }
    //string 练习
    string s="this is a good day";
    s.push_back('3');
    cout<<s<<endl;
    return 0;
}
*/

//2 二叉树的序列化和反序列化 剑指37 未完成




/*
#include<iostream>
using namespace std;
//相同的内存地址
union myun //联合体名  联合体共享空间，新变量不会清除数据，只会覆盖，覆盖从联合体实例的首地址开始
{
    struct { int x; int y; int z; }u;//结构体实例u 
    int k; 
}a; //联合体实例a
int main() 
{ 
    myun b;//联合体实例b
    b.u.x =4;
    b.u.y =5; 
    b.u.z =6; 
    b.k = 0; //覆盖掉第一个int空间值
    printf("%d %d %d %d\n",b.u.x,b.u.y,b.u.z,b.k);
    system("pause");
    return 0;
}
*/