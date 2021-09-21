#include <iostream>//输入输出流库
#include <vector>//容器库
#include <fstream>//保存文件库
using namespace std;

#define cls() system("cls")//清屏
#define pause() system("pause")//暂停输出

class Student {//学生类
public:
    string classNumber;//班级号
    string studentNumber;//学号
    string name;//姓名
    string sex;//性别
    int age = 0;//年龄
};

class Class {//班级类
public:
    string classNumber;//班级号
    string className;//班级名

    vector<Student> myStudent;//myStudent学生容器数组

    int howMany = 0;//学生人数
};


vector<Class> myClass;//myClass班级容器数组

void newClass() {//新建班级和学生
    cls();//清屏
    Class newClass;//定义班级类变量
    string input;//定义输入字符串

    cout << "（输入no结束输入）输入班级名称：";
    cin >> input;//输入

    if (input == "no")//如果输入no，停止输入
    {
        return;
    }
    newClass.className = input;//否则，赋值

    cout << "输入班号：";
    cin >> input;
    newClass.classNumber = input;

    do
    {
        Student newStudent;//定义学生类变量
        newStudent.classNumber = newClass.classNumber;//学生类的班级号=班级类的班级号

        cls();//清屏
        cout << "（输入no结束输入）输入" << newClass.className << newClass.classNumber << "班的学生学号：";
        cin >> input;
        newStudent.studentNumber = input;

        if (input == "no")//如果输入no，停止输入
        {
            break;
        }

        cout << "输入学生姓名：";//如文字所见，输入学生信息
        cin >> input;
        newStudent.name = input;

        cout << "输入学生性别：";
        cin >> input;
        newStudent.sex = input;

        int age;
        cout << "输入学生年龄：";
        cin >> age;
        newStudent.age = age;

        newClass.myStudent.push_back(newStudent);

    } while (true);

    newClass.howMany = newClass.myStudent.size();//更新班级的人数

    myClass.push_back(newClass);//将录入好信息的类变量放入myClass容器数组
    
}

void showClass() {//显示
    cls();//清屏

    if (myClass.empty())//如果myClass容器数组空的话，弹出信息
    {
        cout << "尚未录入班级！" << endl;
        pause();
        return;
    }
    else//非空，则
    {
        for (int i = 0; i < myClass.size(); i++) {//输出所有班级号
            cout << "班级号：" << myClass[i].classNumber << endl;
        }
    }
    string input;

    cout << "\n输入要显示的班级号：";
    cin >> input;

    bool find = false;//是否找到班级
    for (int i = 0; i < myClass.size(); i++)//遍历myClass容器数组寻找
    {
        if (myClass[i].classNumber == input)//找到了
        {
            find = true;//找到了
            cout << "班级名：" << myClass[i].className <<endl;//输出信息
            cout << "班级号：" << myClass[i].classNumber << endl;
            cout << "学生人数：" << myClass[i].howMany << endl;
            cout << endl;

            if (myClass[i].myStudent.empty())//学生是否录入？
            {
                cout << "尚未录入学生！" << endl;
                pause();
                return;
            }
            else//录入的话，输出
            {
                for (int j = 0; j < myClass[i].myStudent.size(); j++)//遍历输出myClass容器数组中的myStudent容器数组学生信息
                {
                    cout << "学生学号：" << myClass[i].myStudent[j].studentNumber << endl;
                    cout << "学生姓名：" << myClass[i].myStudent[j].name << endl;
                    cout << "学生性别：" << myClass[i].myStudent[j].sex << endl;
                    cout << "学生年龄：" << myClass[i].myStudent[j].age << endl;
                    cout << endl;
                }
                pause();//暂停显示
            }
        }
    }
    if (find==false)//如果没找到，则输出
    {
        cout << "查无此班！" << endl;
        pause();
    }
}

void manageClass() {//增删查改班级和学生
    cls();//清屏

    if (myClass.empty())//如果myClass容器数组为空，输出
    {
        cout << "尚未录入班级！" << endl;
        pause();
        return;
    }
    else//否则，不为空，继续
    {
        for (int i = 0; i < myClass.size(); i++) {//遍历myClass容器数组输出班级号
            cout << "班级号：" << myClass[i].classNumber << endl;
        }
    }
    string input;

    cout << "\n输入要修改的班级号：";
    cin >> input;

    bool find = false;//是否找到，默认为否
    for (int i = 0; i < myClass.size(); i++)//遍历myClass容器数组查找
    {
        if (myClass[i].classNumber == input)//找到了
        {
            find = true;//标记为真，表示找到了
            cout << "（输入no删除班级）班级名修改为：";
            cin >> input;

            if (input == "no")//如果输入no，则删除班级，并结束函数
            {
                myClass.erase(myClass.begin()+i);
                cout << "已删了！"<<endl;
                pause();
                return;
            }

            myClass[i].className=input;//修改班级名

            cout << "班级号修改为：";
            cin >> input;
            myClass[i].classNumber=input;//修改班级号

            cout << endl;//换行

            if (myClass[i].myStudent.empty())//如果myClass容器数组中的myStudent容器数组为空，输出
            {
                cout << "尚未录入学生！" << endl;
                pause();
            }
            else//不为空，说明有学生数据
            {
                cls();//清屏
                for (int j = 0; j < myClass[i].myStudent.size(); j++)//遍历myClass容器数组中的myStudent容器数组
                {
                    myClass[i].myStudent[j].classNumber = myClass[i].classNumber;//同步学生的班级号
                    
                    cout << "学生学号：" << myClass[i].myStudent[j].studentNumber << endl;//输出所有学号
                }

                cout << "\n输入要修改的学生学号：";
                cin >> input;

                bool findStudent = false;//标记学生是否找到，默认为否

                for (int j = 0; j < myClass[i].myStudent.size(); j++)//遍历myClass容器数组中的myStudent容器数组
                {
                    if (myClass[i].myStudent[j].studentNumber == input) {//找到了
                        findStudent = true;//标记找到了
                        cout << "（输入no删除学生）学生学号修改为：";
                        cin >> input;

                        if (input == "no")//输入no则删除
                        {
                            myClass[i].myStudent.erase(myClass[i].myStudent.begin() + j);//删除操作
                            cout << "已删了！" << endl;

                            myClass[i].howMany = myClass[i].myStudent.size();//更新学生人数
                            pause();
                            return;//结束函数
                        }
                        myClass[i].myStudent[j].studentNumber = input;//更改值

                        cout << "学生姓名修改为：";
                        cin >> input;
                        myClass[i].myStudent[j].name = input;//更改学生姓名

                        cout << "学生性别修改为：";
                        cin >> input;
                        myClass[i].myStudent[j].sex = input;

                        int age;
                        cout << "学生年龄修改为：";
                        cin >> age;
                        myClass[i].myStudent[j].age = age;
                        
                        pause();//暂停屏幕输出
                    }
                }
                if (findStudent == false)//如果没找到，输出
                {
                    cout << "查无此人！" << endl;
                    pause();
                }
            }
            //无论有没有学生，都接着增加学生
            do
            {
                Student newStudent;//Student类变量
                newStudent.classNumber = myClass[i].classNumber;//更新班级号

                cls();//清屏
                cout << "（输入no结束输入）增加学生：输入" << myClass[i].className << myClass[i].classNumber << "班的学生学号：";
                cin >> input;
                newStudent.studentNumber = input;

                if (input == "no")//输入no跳出循环，不增加了
                {
                    break;
                }

                cout << "输入学生姓名：";
                cin >> input;
                newStudent.name = input;//写入学生姓名，下同

                cout << "输入学生性别：";
                cin >> input;
                newStudent.sex = input;

                int age;
                cout << "输入学生年龄：";
                cin >> age;
                newStudent.age = age;

                myClass[i].myStudent.push_back(newStudent);//将学生类变量放入myClass[i]容器数组中的myStudent容器数组中，增加学生

            } while (true);

            myClass[i].howMany = myClass[i].myStudent.size();//更新学生人数
        }
    }
    if (find == false)//没找到班级，输出
    {
        cout << "查无此班！" << endl;
        pause();
    }
}

void save() {//保存输出数据
    ofstream outfile;//创建输出文件流对象
    
    cls();//清屏

    if (myClass.empty())//如果myClass容器数组为空，提示
    {
        cout << "尚未录入班级！" << endl;
        pause();//暂停显示
        return;//结束函数
    }
    else//否则不为空
    {
        for (int i = 0; i < myClass.size(); i++) {//遍历输出班级号
            cout << "班级号：" << myClass[i].classNumber << endl;
        }
    }
    string input;

    cout << "\n输入要保存的班级号：";
    cin >> input;//输入要保存的班级号

    bool find = false;//找到没？
    for (int i = 0; i < myClass.size(); i++)//遍历myClass容器数组
    {
        if (myClass[i].classNumber == input)//找到了
        {
            outfile.open("班级和学生信息档案.txt", ios_base::out | ios_base::app);//打开文件，无则创建，有则新数据添在末尾
            find = true;//标记找到了
            outfile << "班级名：" << myClass[i].className << endl;//往硬盘txt文件中写入数据
            outfile << "班级号：" << myClass[i].classNumber << endl;
            outfile << "学生人数：" << myClass[i].howMany << endl;
            outfile << endl;

            if (myClass[i].myStudent.empty())//学生为空提示
            {
                cout << "尚未录入学生！" << endl;
                pause();
                return;
            }
            else//否则，学生有数据
            {
                for (int j = 0; j < myClass[i].myStudent.size(); j++)//遍历myClass容器数组中的myStudent容器数组
                {
                    outfile << "学生学号：" << myClass[i].myStudent[j].studentNumber << endl;//将数据写入txt文件中
                    outfile << "学生姓名：" << myClass[i].myStudent[j].name << endl;
                    outfile << "学生性别：" << myClass[i].myStudent[j].sex << endl;
                    outfile << "学生年龄：" << myClass[i].myStudent[j].age << endl;
                    outfile << endl;
                }
                cout << "保存成功（理论上）！" << endl;
                outfile.close();//关闭输出文件
                pause();
            }
        }
    }
    if (find == false)//否则，没找到班级，直接结束
    {
        cout << "查无此班！" << endl;
        pause();
    }
}

int main()//主函数，程序从这里开始执行
{
    string input;//定义输入字符串。用于判断输入功能

    do//循环
    {
        cls();//清屏

        cout << "输入[1]新建班级和学生信息档案\n";
        cout << "输入[2]显示班级和学生信息档案\n";
        cout << "输入[3]管理班级和学生信息档案\n";
        cout << "输入[4]保存班级和学生信息档案\n";
        cout << "输入[q]退出管理系统\n\n";

        cin >> input;//输入字符串

        if (input == "1") {//根据输入的字符串，判断调用哪个函数
            newClass();//新建
        }
        else if (input == "2")
        {
            showClass();//显示
        }
        else if (input == "3")
        {
            manageClass();//管理
        }
        else if (input == "4")
        {
            save();//保存
        }
        else if (input == "q")
        {
            return 0;//退出
        }
        else//如果输出其他字符串，则提示输出错误
        {
            cout << "输入错误！" << endl;
            pause();//暂停屏幕输出
        }
    } while (true);//除非输入"q"，否则一直循环
}