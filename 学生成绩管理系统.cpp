/*系统架构::头文件*/
#include <iostream>//使用iostream头文件，包含标准输入输出流等
using namespace std;//此程序较简单，故而使用标准命名空间std
#include <conio.h>//使用conio.h头文件，包含_getch()
#include <windows.h>//使用windows.h头文件，调用Windows API相关
#include <strsafe.h>//参考微软文档用法，包含StringCchPrintf()，用以格式化字符串
#include <fstream>//文件写入相关
#include <ctime>//保存成绩同时保存当前时间
/*系统架构::头文件结束*/

/*系统架构::系统功能宏定义*/
#define Cls() system("cls")//宏定义调用system函数执行CMD命令进行清屏操作，暂未找到更好的替代方法
/*系统架构::系统功能宏定义结束*/


/*===================封装系统架构类===================*/
class Framework
{
private://私有成员暂无

protected://保护成员暂无

public://公有成员

	/*系统架构::变量定义*/
	char input_char = NULL;//定义输入的字符，用以判断
	int input_int = NULL;//定义输入的数值，用以判断
	string input_string = "NULL";//定义输入的string类，用以判断
	char CR = NULL;//定义输入字符，用以判断第二次输入的回车键
	bool error = false;//判断是否出错
	/*系统架构::变量定义结束*/

	/*系统架构::设置控制台标题*/
	TCHAR szOldTitle[MAX_PATH] = TEXT("NULL");//保存旧的控制台标题
	TCHAR szNewTitle[MAX_PATH] = TEXT("NULL");//设置新的控制台标题

	void Title(const wchar_t* title)//传入控制台标题
	{
		if (GetConsoleTitle(szOldTitle, MAX_PATH))//获得旧标题
		{
			StringCchPrintf(szNewTitle, MAX_PATH, title, szOldTitle);//参考微软文档用法，返回格式化字符串
			SetConsoleTitle(szNewTitle);//设置新标题
		}
	}
	/*系统架构::设置控制台标题结束*/

	/*系统架构::设置控制台窗口与缓冲区的位置与大小*/
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//获得标准输出句柄

	void Window(int pos_x, int pos_y, int cols, int lines)//设置窗口和缓冲区大小
	{
		SMALL_RECT rc = { SHORT(pos_x),SHORT(pos_y), SHORT(cols - 1), SHORT(lines - 1) };//窗口位置与大小
		SetConsoleWindowInfo(hStdout, true, &rc);//重新设置窗口大小
		COORD size = { SHORT(cols), 9000 };//缓冲区大小，设置9000行缓冲区，输出肯定够用，好使！
		SetConsoleScreenBufferSize(hStdout, size);//重新设置缓冲区大小
	}
	/*系统架构::设置控制台窗口与缓冲区的位置与大小结束*/

	/*系统架构::字体颜色定义*/
	void Black()//白色背景，缺省黑色字体
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	}

	void Black_White()//黑色背景，白色字体
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}

	void Black_Red()//黑色背景，红色字体
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED);
	}

	void Black_Yellow()//黑色背景，黄色字体
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	}

	void Purple()//白色背景，紫色字体
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
	}

	void Red()//白色背景，红色字体
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
	}

	void Green()//白色背景，绿色字体
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);
	}

	void Magenta()//白色背景，紫红色字体
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
	}
	/*系统架构::字体颜色定义结束*/

	/*系统架构::隐藏与显示控制台光标*/
	CONSOLE_CURSOR_INFO cursor_info;//定义控制台光标

	void Hide_cursor()//隐藏光标
	{
		cursor_info.dwSize = 1;//光标厚度为1
		cursor_info.bVisible = false;//隐藏光标
		SetConsoleCursorInfo(hStdout, &cursor_info);//使用标准输出中获得的句柄，设置控制台光标状态
	}

	void Display_cursor()//显示光标
	{
		cursor_info.dwSize = 1;//光标厚度为1
		cursor_info.bVisible = true;//显示光标
		SetConsoleCursorInfo(hStdout, &cursor_info);//使用标准输出中获得的句柄，设置控制台光标状态
	}
	/*系统架构::隐藏与显示控制台光标结束*/

	/*系统架构::暂停控制台输出*/
	void Pause(bool style)//暂停控制台输出
	{
		if (style == true)//主界面样式，尚无机会使用
		{
			cout << "\n\n";//换行两次，用于美观
			Magenta();//白色背景，紫红色字体
			cout << "\t\t\t\t请按任意键继续 >> " << endl;//设置提示字颜色为紫红色
			Black();//回到缺省状态
		}
		else//子界面样式
		{
			cout << "\n\n";//换行两次，用于美观
			Black_Yellow();//黑色背景，黄色字体
			cout << "·请按任意键继续 >> ";//设置提示字颜色为黄色
			Black_White();//回到子界面缺省状态
		}
		char temp = _getch();//使用_getch()函数静候任意字符的输入，结果并无实际意义
	}
	/*系统架构::暂停控制台输出结束*/

	/*系统架构::动态显示输入判断字符*/
	void Input_char(bool style)//输入字符
	{
		if (style == true)//主界面样式
		{
			cout << "\n\n";//换行两次，控制格式的美观
			input_char = _getch();//输入字符
			Green();//白色背景，绿色字体
			do
			{
				cout << "\r\t\t\t\t";//'\r'的应用，重回本行开头
				if (input_char == '\015')//判断是否等于回车键
				{
					cout << "当前选择[ 回车 ]键";
				}
				else if (input_char == '\033')//判断是否等于ESC键
				{
					cout << "当前选择[ Escape ]键";
				}
				else if (input_char == '\010')//判断是否等于退格键
				{
					cout << "当前选择[ Backspace ]键";
				}
				else//其他按键直接输出
				{
					cout << "当前选择[ " << input_char << " ]键";
				}
				CR = _getch();//静候回车键
				if (CR != '\015')//若第二次输入并非回车键
				{
					input_char = CR;//则赋值给input_char
				}
			} while (CR != '\015');//若CR==回车键，则皆大欢喜，停止循环
			Black();//改为缺省黑色字体
		}
		else//子界面样式
		{
			cout << "\n";
			input_char = _getch();//输入字符
			Black_Yellow();//黑色背景，黄色字体
			do
			{
				cout << "\r";//'\r'的应用，重回本行开头
				if (input_char == '\015')//判断是否等于回车键
				{
					cout << "·当前选择[ 回车 ]键";
				}
				else if (input_char == '\033')//判断是否等于ESC键
				{
					cout << "·当前选择[ Escape ]键";
				}
				else if (input_char == '\010')//判断是否等于退格键
				{
					cout << "·当前选择[ Backspace ]键";
				}
				else//其他按键直接输出
				{
					cout << "·当前选择[ " << input_char << " ]键";
				}
				CR = _getch();//静候回车键
				if (CR != '\015')//若第二次输入并非回车键
				{
					input_char = CR;//则赋值给input_char
				}
			} while (CR != '\015');//若CR==回车键，则皆大欢喜，停止循环
			Black_White();//改为缺省黑色字体
		}
	}
	/*系统架构::动态显示输入判断字符结束*/

	/*系统架构::动态显示输入字符错误catch*/
	void Error(bool style)//提示输入错误
	{
		if (style == true)//主界面样式
		{
			Red();//改为红色字体
			cout << "\n\n\t\t";
			if (input_char == '\015')//判断是否等于回车键
			{
				cout << "【输入错误】值为[ 回车 ]键，请重新选择 >>>>>>>> " << endl;
			}
			else if (input_char == '\033')//判断是否等于ESC键
			{
				cout << "【输入错误】值为[ Escape ]键，请重新选择 >>>>>>>> " << endl;
			}
			else if (input_char == '\010')//判断是否等于退格键
			{
				cout << "【输入错误】值为[ Backspace ]键，请重新选择 >>>>>>>> " << endl;
			}
			else//其他按键直接输出
			{
				cout << "【输入错误】值为[ " << input_char << " ]键，请重新选择 >>>>>>>> " << endl;
			}
			Black();//改为缺省黑色字体
			error = false;//最后将error改为缺省值false，表示此次的提示输入错误结束
		}
		else//子界面样式
		{
			Black_Red();//改为黑色背景，红色字体
			cout << "\n";
			if (input_char == '\015')//判断是否等于回车键
			{
				cout << "·【输入错误】值为[ 回车 ]键，请重新选择 >> " << endl;
			}
			else if (input_char == '\033')//判断是否等于ESC键
			{
				cout << "·【输入错误】值为[ Escape ]键，请重新选择 >> " << endl;
			}
			else if (input_char == '\010')//判断是否等于退格键
			{
				cout << "·【输入错误】值为[ Backspace ]键，请重新选择 >> " << endl;
			}
			else//其他按键直接输出
			{
				cout << "·【输入错误】值为[ " << input_char << " ]键，请重新选择 >> " << endl;
			}
			Black_White();//改为白色字体
			error = false;//最后将error改为缺省值false，表示此次的提示输入错误结束
		}
	}
	/*系统架构::动态显示输入字符错误catch结束*/

	~Framework()//析构函数
	{
		CloseHandle(hStdout);//关闭标准输出句柄
	}
};
/*===================封装系统架构类结束===================*/


/*系统架构::数据存储*/
int M(0);//课程数目
/*数据类*/
class Data//数据类，用于存放数据
{
private://私有成员暂无

protected://保护成员暂无

public://公有成员

	string number;//学号，千万不要赋值为NULL，否则申请内存出现crash（崩溃）
	string name;//姓名，千万不要赋值为NULL，否则申请内存出现crash（崩溃）
	double* score = new double[M];//单科成绩，类中动态申请内存，易造成crash（崩溃），需要重载赋值运算符
	double average = 0.0;//计算学生的平均成绩
	bool delete_mark = false;//删除标记

	/*因为类中有指针变量，无法直接赋值，必须重载赋值运算符，否则会造成crash（崩溃）*/
	Data& operator = (const Data& Copy)//重载赋值运算符
	{
		number = Copy.number;//正常复制常规成员
		name = Copy.name;//正常复制常规成员
		average = Copy.average;//正常复制常规成员

		double* temp = new double[M];//复制指针指向的内容
		memcpy(temp, Copy.score, M * sizeof(double));//调用内存拷贝函数

		delete[] score;//删除原指针指向的内容
		score = temp;//建立新指向
		return *this;//this指针返回当前对象的引用
	}
	/*重载赋值运算符结束，修复排序时交换的crash（崩溃）*/

	/*本想为避免再次出现严重漏洞，顺便编写拷贝构造函数，不成想编译出错：不存在默认构造函数，无法动态申请内存定义类，故此作罢
	Data(const Data& Copy)//拷贝构造函数
	{
		number = Copy.number;//复制常规成员
		name = Copy.name//复制常规成员
		average = Copy.average//复制常规成员

		score= new double[M];//复制指针指向的内容
		memcpy(score, Copy.score, M * sizeof(double));//调用内存拷贝函数
	}
	//拷贝构造函数结束*/

	~Data()//析构函数，释放申请的内存
	{
		delete[] score;
	}

};
/*系统架构::数据存储结束*/


/*===================封装功能模块类，公有继承系统架构类===================*/
class Modular :public Framework
{
private://私有成员

	int count = 0, inside = 0;//用以循环之中计数
	Data swap;//定义交换数值的类

protected://保护成员

	int N = 0;//学生数目
	int N_search = 0;//用于搜索已删除的数据，即学生的完整数目
	string* subject = NULL;//定义string类指针，课程名称
	Data* data = NULL;//定义data类指针，学生数据

public://公有成员

	~Modular()//析构函数，释放申请的内存
	{
		delete[]subject;
		delete[]data;
	}

	/*模块1::成绩输入*/
	void Input()//成绩录入
	{
		Title(TEXT("学生成绩管理系统::成绩录入"));//设置标题
		Window(0, 0, 64, 34);//设置窗口大小为64行34列
		Black_White();//更新前景色、背景色
		Cls();//清屏
		if ((data != NULL) || (subject != NULL))//若不为空，说明已经录入数据
		{
			if (IDCANCEL == MessageBox(GetConsoleWindow(), TEXT("检测到数据库中已存在数据，确定重新录入数据吗？"), TEXT("提示信息"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
			{
				//调用Windows API弹出对话框，缺省值为取消
				Window(0, 0, 80, 34);//必须重新调整窗口，否则出现bug
				return;//若值为取消，则此函数调用结束
			}
		}
		Display_cursor();//显示光标
		do
		{
			Cls();//清屏
			cout << "\n·请输入学生的人数：";
			cin >> N;//录入学生人数
			cin.clear();//修正输入字母引起的crash（崩溃），改正错误标识
			cin.ignore(1024, '\n');//修正输入字母引起的crash（崩溃），清空输入流
			cout << "\n·请输入课程的门数：";
			cin >> M;//录入课程门数
			cin.clear();//修正输入字母引起的crash（崩溃），改正错误标识
			cin.ignore(1024, '\n');//修正输入字母引起的crash（崩溃），清空输入流
			if (N <= 0 || M <= 0)//如果N或M都小于等于0，catch输入错误
			{
				Black_Red();//黑色背景，红色字体
				cout << "\n【输入错误】数值不能小于或等于0，请重新输入" << endl;
				Black_White();//黑色背景，白色字体
				Pause(false);//暂停屏幕输出
			}
		} while (N <= 0 || M <= 0);//如果N或M都小于等于0，继续循环
		N_search = N;//用于搜索已删除的数据，即保存完整的学生人数
		delete[]subject;//规避内存泄漏，多次调用函数时，先把以前的内存空间释放掉
		delete[]data;//规避内存泄漏，多次调用函数时，先把以前的内存空间释放掉
		data = new Data[N];//动态申请内存
		subject = new string[M];//动态申请内存
		Cls();//清屏
		for (count = 0; count < M; count++)
		{
			cout << "\n·请输入第[ " << count + 1 << " ]门课的名称：";
			cin >> *(subject + count);//指针输出string类的课程名称
		}
		Cls();//清屏
		for (count = 0; count < N; count++)
		{
			cout << "\n·请输入第[ " << count + 1 << " ]位学生的 >> " << endl;
			cout << "\n  学号：";
			cin >> (data + count)->number;//输入学号
			cout << "\n  姓名：";
			cin >> (data + count)->name;//输入姓名
			for (inside = 0; inside < M; inside++)//内层循环，输入成绩
			{
				cout << "\n";
				do
				{
					cout << "  课程【" << *(subject + inside) << "】的成绩：";
					cin >> (data + count)->score[inside];//输入成绩
					cin.clear();//修正输入字母引起的crash（崩溃），改正错误标识
					cin.ignore(1024, '\n');//修正输入字母引起的crash（崩溃），清空输入流
					if ((data + count)->score[inside] < 0)//catch错误输入
					{
						cout << "  【成绩不能小于0】" << endl;
					}
				} while ((data + count)->score[inside] < 0);//必须正确输入，才可以跳出循环
				(data + count)->average += (data + count)->score[inside];//计算学生的成绩总和
			}
			(data + count)->average /= (double)(M);//计算学生的平均成绩
			Cls();//清屏
		}
		Window(0, 0, 80, 34);//须重新设置窗口大小
	}
	/*模块1::成绩输入结束*/

	/*模块2::成绩显示*/
	void Output()//成绩显示，利用缓冲区9000行的优势，采用竖排全部输出
	{
		Title(TEXT("学生成绩管理系统::成绩显示"));//设置标题
		Window(0, 0, 64, 34);//设置窗口大小为64列34行
		Black_White();//更新前景色、背景色
		Cls();//清屏
		Display_cursor();//显示光标
		if (data == NULL || subject == NULL)//如果指针为空，代表没有录入成绩
		{
			cout << "\n·尚未录入学生数据，即将返回主菜单..." << endl;
			Pause(false);//暂停屏幕输出
		}
		else//否则，便是已经录入成绩
		{
			if (N != 0)//N若为0则数据已经全部被标记删除
			{
				for (count = 0; count < N; count++)//外层循环遍历学生输出
				{
					cout << "\n·序号为[ " << count + 1 << " ]的学生的 >> " << endl;
					cout << "\n  学号：" << (data + count)->number << endl;//输出学号
					cout << "\n  姓名：" << (data + count)->name << endl;//输出姓名
					for (inside = 0; inside < M; inside++)//内层循环遍历课程输出
					{
						cout << "\n  课程【" << *(subject + inside) << "】的成绩：" << (data + count)->score[inside] << endl;//输出成绩
					}
					cout << "\n  平均成绩：" << (data + count)->average << endl;//输出平均成绩
				}
			}
			else
			{
				cout << "\n·数据已全部标记为删除" << endl;
			}
			Pause(false);//暂停屏幕输出//暂停显示以等待下一步操作
		}
		Window(0, 0, 80, 34);//须重新设置窗口大小
	}
	/*模块2::成绩显示结束*/

	/*模块3::成绩排序*/
	void Sort()//成绩排序
	{
		Title(TEXT("学生成绩管理系统::成绩排序"));//设置标题
		Window(0, 0, 64, 34);//设置窗口大小为64行34列
		Black_White();//更新前景色、背景色
		Cls();//清屏
		Display_cursor();//显示光标
		if (data == NULL || subject == NULL)//指针为空，尚未录入
		{
			cout << "\n·尚未录入学生数据，即将返回主菜单..." << endl;
			Pause(false);//暂停屏幕输出
		}
		else
		{
			Hide_cursor();//隐藏光标
			do//do-while循环，先执行一次
			{
				Black_White();//黑色背景，白色字体
				Cls();//清屏
				cout << "\n·请选择排序方式：" << endl;
				cout << "\n\t【u】升序" << endl;
				cout << "\n\t【d】降序" << endl;
				cout << "\n\t【r】返回主界面" << endl;
				cout << "\n\t【q】退出系统" << endl;
				if (error == true)//catch错误，调用函数
				{
					Error(false);//调用Error函数
				}
				Input_char(false);//输入字符
				switch (input_char)//判断输入的字符
				{
				case 'u':break;//为u则跳出switch语句
				case 'd':break;//为d则跳出switch语句
				case 'r':Window(0, 0, 80, 34); return; break;//直接结束函数调用，返回主界面，返回之前须重新设置窗口大小
				case 'q':exit(0); break;//q则直接退出系统，返回值0
				default: error = true;//否则，输入错误
				}
			} while (input_char != 'u' && input_char != 'd');//若输入不为u和d，继续循环
			if (input_char == 'u')//升序
			{
				do//do-while循环，先执行一次
				{
					Black_White();//黑色背景，白色字体
					Cls();//清屏
					cout << "\n·请选择排序策略：" << endl;
					cout << "\n\t【s】学号" << endl;
					cout << "\n\t【n】姓名" << endl;
					cout << "\n\t【a】平均成绩" << endl;
					cout << "\n\t【k】课程成绩" << endl;
					cout << "\n\t【r】返回主界面" << endl;
					cout << "\n\t【q】退出系统" << endl;
					if (error == true)//catch错误，调用函数
					{
						Error(false);
					}
					Input_char(false);//输入字符
					switch (input_char)//判断输入的字符
					{
					case 's'://插入排序
						for (count = 1; count < N; count++)//外层从1到N
						{
							for (inside = count; inside > 0; inside--)//内层从大到小循环
							{
								if (((data + inside)->number) < ((data + inside - 1)->number))//如果第二个值小于第一个的话
								{
									swap = *(data + inside);//交换两个类的值
									*(data + inside) = *(data + inside - 1);
									*(data + inside - 1) = swap;
								}
								else//大于的话啥也不用说，直接跳出内层循环
								{
									break;//跳出内循环
								}
							}
						}
						break;//break不相忘
					case 'n'://插入排序，与前面同，再不赘述
						for (count = 1; count < N; count++)
						{
							for (inside = count; inside > 0; inside--)
							{
								if (((data + inside)->name) < ((data + inside - 1)->name))
								{
									swap = *(data + inside);
									*(data + inside) = *(data + inside - 1);
									*(data + inside - 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'a'://插入排序，与前面同，再不赘述
						for (count = 1; count < N; count++)
						{
							for (inside = count; inside > 0; inside--)
							{
								if (((data + inside)->average) < ((data + inside - 1)->average))
								{
									swap = *(data + inside);
									*(data + inside) = *(data + inside - 1);
									*(data + inside - 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'k':
						do
						{
							Cls();//清屏
							for (inside = 0; inside < M; inside++)//输出课程序号与信息
							{
								cout << "\n  【" << inside << "】" << *(subject + inside) << endl;
							}
							if (error == false)//正常情况
							{
								cout << "\n·请选择排序课程：";
							}
							else//catch error后的输出
							{
								Black_Red();
								cout << "\n  【输入错误】请重新选择排序课程：";
								Black_White();
								error = false;
							}
							cin >> input_int;//输入序号
							cin.clear();//修正输入字母引起的crash（崩溃），改正错误标识
							cin.ignore(1024, '\n');//修正输入字母引起的crash（崩溃），清空输入流
							if (input_int < 0 || input_int >= M)//如果序号不是0~M，那么输入的有问题
							{
								error = true;//error马上安排
							}
						} while (input_int < 0 || input_int >= M);//如果序号不是0~M，那么继续循环
						//插入排序，与前面同，再不赘述
						for (count = 1; count < N; count++)
						{
							for (inside = count; inside > 0; inside--)
							{
								if (((data + inside)->score[input_int]) < ((data + inside - 1)->score[input_int]))
								{
									swap = *(data + inside);
									*(data + inside) = *(data + inside - 1);
									*(data + inside - 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'r':Window(0, 0, 80, 34); return; break;//直接结束函数调用，返回主界面，仍然需要重新设置缓冲区大小，否则会出现bug
					case 'q':exit(0); break;//q则直接退出系统，返回值0
					default: error = true;//否则，输入错误
					}
				} while (input_char != 's' && input_char != 'n' && input_char != 'a' && input_char != 'k');//这回验证的有点儿多，有4个字母
			}
			else if (input_char == 'd')//降序
			{
				do//do-while循环，先执行一次
				{
					Black_White();//黑色背景，白色字体
					Cls();//清屏
					cout << "\n·请选择排序策略：" << endl;
					cout << "\n\t【s】学号" << endl;
					cout << "\n\t【n】姓名" << endl;
					cout << "\n\t【a】平均成绩" << endl;
					cout << "\n\t【k】课程成绩" << endl;
					cout << "\n\t【r】返回主界面" << endl;
					cout << "\n\t【q】退出系统" << endl;
					if (error == true)//catch错误，调用函数
					{
						Error(false);
					}
					Input_char(false);//输入字符
					switch (input_char)//判断输入的字符
					{
					case 's'://冒泡排序
						for (count = 0; count < N - 1; count++)//外层count从0开始到N-1进行循环
						{
							for (inside = 0; inside < N - count - 1; inside++)//内层inside从0开始到N-count-1进行循环
							{
								if (((data + inside)->number) < ((data + inside + 1)->number))//如果第一个数的值小于第二个数的值的话
								{
									swap = *(data + inside);//交换两个类的值
									*(data + inside) = *(data + inside + 1);
									*(data + inside + 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'n'://冒泡排序
						for (count = 0; count < N - 1; count++)//外层count从0开始到N-1进行循环
						{
							for (inside = 0; inside < N - count - 1; inside++)//内层inside从0开始到N-count-1进行循环
							{
								if (((data + inside)->name) < ((data + inside + 1)->name))//如果第一个数的值小于第二个数的值的话
								{
									swap = *(data + inside);//交换两个类的值
									*(data + inside) = *(data + inside + 1);
									*(data + inside + 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'a'://冒泡排序，与前面同，再不赘述
						for (count = 0; count < N - 1; count++)//外层count从0开始到N-1进行循环
						{
							for (inside = 0; inside < N - count - 1; inside++)//内层inside从0开始到N-count-1进行循环
							{
								if (((data + inside)->average) < ((data + inside + 1)->average))//如果第一个数的值小于第二个数的值的话
								{
									swap = *(data + inside);//交换两个类的值
									*(data + inside) = *(data + inside + 1);
									*(data + inside + 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'k':
						do
						{
							Cls();//清屏
							for (inside = 0; inside < M; inside++)//输出课程信息
							{
								cout << "\n  【" << inside << "】" << *(subject + inside) << endl;
							}
							if (error == false)
							{
								cout << "\n·请选择排序课程：";
							}
							else
							{
								Black_Red();
								cout << "\n  【输入错误】请重新选择排序课程：";
								Black_White();
								error = false;
							}
							cin >> input_int;//输入序号
							cin.clear();//修正输入多个字母引起的crash（崩溃）
							cin.ignore(1024, '\n');//修正输入多个字母引起的crash（崩溃）
							if (input_int < 0 || input_int >= M)//一直判断catch一直爽
							{
								error = true;
							}
						} while (input_int < 0 || input_int >= M);//一直循环一直爽
						//冒泡排序
						for (count = 0; count < N - 1; count++)//外层count从0开始到N-1进行循环
						{
							for (inside = 0; inside < N - count - 1; inside++)//内层inside从0开始到N-count-1进行循环
							{
								if (((data + inside)->score[input_int]) < ((data + inside + 1)->score[input_int]))//如果第一个数的值小于第二个数的值的话
								{
									swap = *(data + inside);//交换两个类的值
									*(data + inside) = *(data + inside + 1);
									*(data + inside + 1) = swap;
								}
								else
								{
									break;//跳出内循环
								}
							}
						}
						break;
					case 'r':Window(0, 0, 80, 34); return; break;//直接结束函数调用，返回主界面，说很多次了，不说了
					case 'q':exit(0); break;//q则直接退出系统，返回值0
					default: error = true;//否则，输入错误
					}
				} while (input_char != 's' && input_char != 'n' && input_char != 'a' && input_char != 'k');//其实就是将升序复制粘贴大法，然后改几个小于号~便成为了降序
			}
		}
		Window(0, 0, 80, 34);//以防万一出现显示bug，依然故我
	}
	/*模块3::成绩排序结束*/

	/*模块4::成绩修改*/
	void Update()//成绩修改、检索与删除
	{
		Title(TEXT("学生成绩管理系统::成绩修改"));//设置标题
		Window(0, 0, 64, 34);//设置窗口大小为64行34列
		Black_White();//更新前景色、背景色
		Cls();//清屏
		if (data == NULL || subject == NULL)//为了万无一失，依然需要验证是否已经录入数据
		{
			Display_cursor();//显示光标
			cout << "\n·尚未录入学生数据，即将返回主菜单..." << endl;
			Pause(false);//暂停屏幕输出
		}
		else//否则就已经存在数据，然后选择检索类别
		{
			do//do-while循环，先执行一次
			{
				Hide_cursor();//隐藏光标
				Black_White();//黑色背景，白色字体
				Cls();//清屏
				cout << "\n·请选择检索类别：" << endl;
				cout << "\n\t【o】序号" << endl;
				cout << "\n\t【s】学号" << endl;
				cout << "\n\t【n】姓名" << endl;
				cout << "\n\t【r】返回主界面" << endl;
				cout << "\n\t【q】退出系统" << endl;
				if (error == true)//catch错误，调用显示错误函数
				{
					Error(false);
				}
				Input_char(false);//输入字符
				switch (input_char)//判断输入的字符
				{
				case 'o'://序号
					do
					{
						Display_cursor();//显示光标
						Cls();//清屏
						if (error == false)//如果输入正确就直接输出
						{
							cout << "\n·请输入检索序号：";
						}
						else//如果输入错误，就让重新输出
						{
							Black_Red();//设置字体颜色为红色
							cout << "\n  【输入错误】请重新输入检索序号：";
							Black_White();//设置字体颜色为白色
							error = false;
						}
						cin >> input_int;//输入一个数值
						cin.clear();//修正输入多个字母引起的crash（崩溃）
						cin.ignore(1024, '\n');//修正输入多个字母引起的crash（崩溃）
						if (input_int <= 0 || input_int > N_search)//可以校验到已标记删除的数据
						{
							error = true;
						}
					} while (input_int <= 0 || input_int > N_search);//校验的是N_search，即N的最大值，
					Cls();//清屏
					cout << "\n·修改序号为[ " << input_int << " ]的学生的数据 >> " << endl;
					cout << "\n  原学号：" << (data + input_int - 1)->number << endl;
					cout << "\n  原姓名：" << (data + input_int - 1)->name << endl;
					for (inside = 0; inside < M; inside++)
					{
						cout << "\n  课程【" << *(subject + inside) << "】的原成绩：" << (data + input_int - 1)->score[inside] << endl;
					}
					if (IDOK == MessageBox(GetConsoleWindow(), TEXT("是否删除该学生的数据？"), TEXT("删除操作"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
					{
						//调用Windows API弹出对话框，缺省值为取消
						(data + input_int - 1)->delete_mark = true;
						for (int temp = input_int - 1; temp < N - 1; temp++)//冒泡排序法将带有删除标记的类放在最后
						{
							swap = *(data + temp);//千篇一律的交换操作
							*(data + temp) = *(data + temp + 1);
							*(data + temp + 1) = swap;
						}
						N--;//学生个数减一
						Window(0, 0, 80, 34);//结束函数调用前，必须重新调整窗口，否则出现bug
						return;//若值为确定，删除后则此函数调用结束
					}
					else//否则如果值为取消的话
					{
						if ((data + input_int - 1)->delete_mark == true)//逆删除操作
						{
							(data + input_int - 1)->delete_mark = false;//数据回春大法
							N++;//学生个数+1，yeah
						}
					}
					cout << "\n·学号修改为：";
					cin >> (data + input_int - 1)->number;//输入学号
					cout << "\n·姓名修改为：";
					cin >> (data + input_int - 1)->name;//输入姓名
					(data + input_int - 1)->average = 0.0;//学生的平均值赋值为0.0
					for (inside = 0; inside < M; inside++)//循环修改课程信息
					{
						do {//一如既往do循环，淦！
							cout << "\n·课程【" << *(subject + inside) << "】的成绩修改为：";
							cin >> (data + input_int - 1)->score[inside];//输入成绩
							cin.clear();//修正输入多个字母引起的crash（崩溃）
							cin.ignore(1024, '\n');//修正输入多个字母引起的crash（崩溃）
							if ((data + input_int - 1)->score[inside] < 0)//一如既往的校验操作
							{
								cout << "  【成绩不能小于0】" << endl;
							}
						} while ((data + input_int - 1)->score[inside] < 0);//熟悉的while循环
						(data + input_int - 1)->average += (data + input_int - 1)->score[inside];//累加和
					}
					(data + input_int - 1)->average /= (double)(M);//累加完了之后直接除，算平均值
					break;
				case 's'://学号
					do
					{
						Display_cursor();//显示光标
						Cls();//清屏
						if (error == false)//如果输入正确，正常输入
						{
							cout << "\n·请输入检索学号：";
						}
						else//如果输入错误，就让重新输出
						{
							Black_Red();//设置字体颜色为红色
							cout << "\n  【输入错误】请重新输入检索学号：";
							Black_White();//设置字体颜色为白色
							error = false;
						}
						cin >> input_string;//输入字符串，用以对比判断
						error = true;//甭说别的，先给来个error再说
						for (count = 0; count < N_search; count++)
						{
							if (input_string == (data + count)->number)//只有输入的字符串能找到
							{
								error = false;//才能解除error，否则error==true就一直循环一直循环
								break;
							}
						}
					} while (error != false);//或者可以直接判断input_string != (data + count)->number
					Cls();//清屏
					cout << "\n·修改序号为[ " << count + 1 << " ]的学生的数据 >> " << endl;
					cout << "\n  原学号：" << (data + count)->number << endl;
					cout << "\n  原姓名：" << (data + count)->name << endl;
					for (inside = 0; inside < M; inside++)
					{
						cout << "\n  课程【" << *(subject + inside) << "】的原成绩：" << (data + count)->score[inside] << endl;
					}
					if (IDOK == MessageBox(GetConsoleWindow(), TEXT("是否删除该学生的数据？"), TEXT("删除操作"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
					{
						//调用Windows API弹出对话框，缺省值为取消
						(data + count)->delete_mark = true;
						for (int temp = count; temp < N - 1; temp++)//冒泡排序法将带有删除标记的类放在最后
						{
							swap = *(data + temp);//依然交换操作
							*(data + temp) = *(data + temp + 1);
							*(data + temp + 1) = swap;
						}
						N--;//学生个数减一
						Window(0, 0, 80, 34);//必须重新调整窗口，否则出现bug
						return;//若值为确定，删除后则此函数调用结束
					}
					else//否则如果值为取消的话
					{
						if ((data + count)->delete_mark == true)//逆删除操作，不必多说
						{
							(data + count)->delete_mark = false;//将删除标记改为假，取消删除
							N++;//学生个数加一
						}
					}
					cout << "\n·学号修改为：";
					cin >> (data + count)->number;//录入学号
					cout << "\n·姓名修改为：";
					cin >> (data + count)->name;//录入姓名
					(data + count)->average = 0.0;//让平均值重置为0
					for (inside = 0; inside < M; inside++)//修改课程成绩
					{
						do {
							cout << "\n·课程【" << *(subject + inside) << "】的成绩修改为：";
							cin >> (data + count)->score[inside];//输入成绩
							cin.clear();//修正输入多个字母引起的crash（崩溃）
							cin.ignore(1024, '\n');//修正输入多个字母引起的crash（崩溃）
							if ((data + count)->score[inside] < 0)//校验成绩是否小于0
							{
								cout << "  【成绩不能小于0】" << endl;
							}
						} while ((data + count)->score[inside] < 0);//若成绩小于0，就输入错误，一直循环直到输入正确
						(data + count)->average += (data + count)->score[inside];//累加计算成绩的和
					}
					(data + count)->average /= (double)(M);//累加完成后除，计算平均值
					break;
				case 'n'://姓名
					do
					{
						Display_cursor();//显示光标
						Cls();//清屏
						if (error == false)//如果error为假说明输入正确
						{
							cout << "\n·请输入检索姓名：";
						}
						else//否则输入错误
						{
							Black_Red();
							cout << "\n  【输入错误】请重新输入检索姓名：";//更改字体颜色为红色，后改为白色
							Black_White();
							error = false;//此次error结束，赋值为假
						}
						cin >> input_string;//输入一个字符串用于检索
						error = true;
						for (count = 0; count < N_search; count++)//从0到最大学生人数开始检索
						{
							if (input_string == (data + count)->name)//如果相等
							{
								error = false;//才将error改为假，即找到了匹配的字符串
								break;
							}
						}
					} while (error != false);//或者可以直接判断input_string != (data + count)->name
					Cls();//清屏
					cout << "\n·修改序号为[ " << count + 1 << " ]的学生的数据 >> " << endl;
					cout << "\n  原学号：" << (data + count)->number << endl;
					cout << "\n  原姓名：" << (data + count)->name << endl;
					for (inside = 0; inside < M; inside++)//输出课程原成绩
					{
						cout << "\n  课程【" << *(subject + inside) << "】的原成绩：" << (data + count)->score[inside] << endl;
					}
					if (IDOK == MessageBox(GetConsoleWindow(), TEXT("是否删除该学生的数据？"), TEXT("删除操作"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
					{
						//调用Windows API弹出对话框，默认值为取消
						(data + count)->delete_mark = true;
						for (int temp = count; temp < N - 1; temp++)//冒泡排序法将带有删除标记的类放在最后
						{
							swap = *(data + temp);//交换学生数据
							*(data + temp) = *(data + temp + 1);
							*(data + temp + 1) = swap;
						}
						N--;//学生个数减一
						Window(0, 0, 80, 34);//必须重新调整窗口，否则出现bug
						return;//若值为确定，删除后则此函数调用结束
					}
					else
					{
						if ((data + count)->delete_mark == true)//逆删除
						{
							(data + count)->delete_mark = false;//将删除标记改为假，取消删除操作
							N++;//学生人数+1
						}
					}
					cout << "\n·学号修改为：";
					cin >> (data + count)->number;//输入学号
					cout << "\n·姓名修改为：";
					cin >> (data + count)->name;//输入姓名
					(data + count)->average = 0.0;//平均值依然从0开始
					for (inside = 0; inside < M; inside++)//遍历课程
					{
						do {
							cout << "\n·课程【" << *(subject + inside) << "】的成绩修改为：";
							cin >> (data + count)->score[inside];//录入成绩修改
							cin.clear();//修正输入多个字母引起的crash（崩溃）
							cin.ignore(1024, '\n');//修正输入多个字母引起的crash（崩溃）
							if ((data + count)->score[inside] < 0)//判断是否输入错误
							{
								cout << "  【成绩不能小于0】" << endl;
							}
						} while ((data + count)->score[inside] < 0);//如果输入错误，就一直循环
						(data + count)->average += (data + count)->score[inside];//计算成绩的累加值
					}
					(data + count)->average /= (double)(M);//除以课程数，计算学生的平均成绩
					break;
				case 'r':Window(0, 0, 80, 34); return; break;//直接结束函数调用，返回主界面
				case 'q':exit(0); break;//q则直接退出系统，返回值0
				default: error = true;//否则，输入错误
				}
			} while (input_char != 'o' && input_char != 's' && input_char != 'n');//到此，函数基本结束，若非输入这三个字母，则继续循环
		}
		Window(0, 0, 80, 34);//日常bug预防，重新设置窗口大小
	}
	/*模块4::成绩修改结束*/

	/*模块5::成绩统计*/
	void Statistics()//成绩统计
	{
		Title(TEXT("学生成绩管理系统::成绩统计"));//日设置标题
		Window(0, 0, 64, 34);//设置窗口大小为64行34列
		Black_White();//更新前景色、背景色
		Cls();//清屏
		Hide_cursor();//隐藏光标
		double average(0.0);//定义局部变量，用于输出平均值
		int max_count(0), statistic(0);//定义最大值序号与统计人数
		if (data == NULL || subject == NULL)//日常校验
		{
			cout << "\n·尚未录入学生数据，即将返回主菜单..." << endl;
			Pause(false);//暂停屏幕输出
		}
		else
		{
			if (N != 0)//看是否全删干净了
			{
				for (inside = 0; inside < M; inside++)//“内层”为先，因为这次是以课程为主角，主角并不是学生
				{
					average = 0.0;//平均值都要从0开始计算
					statistic = 0;//每门课程都要从0开始计数
					for (max_count = 0, count = 0; count < N; count++)//max_count循环，获取最大值ID
					{
						if ((data + max_count)->score[inside] < (data + count)->score[inside])//要是有人敢比max_count的成绩高，那必然要给max_count赋值最高成绩的序号
						{
							max_count = count;//取得每门课程成绩最高学生的ID，用以显示信息
						}
						average += (data + count)->score[inside];//求累加和
					}
					average /= (double)(N);//计算每门课程的平均成绩，与类Data中的average不同，莫要混淆
					for (count = 0; count < N; count++)//统计人数的友善循环
					{
						if ((data + count)->score[inside] > average)//要是有学生的成绩比平均值大，则计数
						{
							statistic++;//统计超过每门课程平均成绩的学生人数
						}
					}//下面清一色全是输出
					cout << "\n·课程【" << *(subject + inside) << "】的最高成绩：" << (data + max_count)->score[inside] << endl;
					cout << "\n  属序号为[ " << max_count + 1 << " ]的学生 >> " << endl;
					cout << "\n  学号：" << (data + max_count)->number << endl;
					cout << "\n  姓名：" << (data + max_count)->name << endl;
					for (int temp(0); temp < M; temp++)//循环输出成绩
					{
						cout << "\n  课程【" << *(subject + temp) << "】的成绩：" << (data + max_count)->score[inside] << endl;
					}
					cout << "\n  各科平均成绩：" << (data + max_count)->average << endl;
					cout << "\n·课程【" << *(subject + inside) << "】的平均成绩：" << average << endl;
					cout << "\n·超过课程【" << *(subject + inside) << "】平均成绩的学生人数：" << statistic << endl;
					cout << "\n";
				}
			}
			else//看数据是否全被删了，全被删了的话，就显示已全删
			{
				cout << "\n·数据已全部标记为删除" << endl;
			}
			Pause(false);//暂停屏幕显示以等待下一步操作
		}
		Window(0, 0, 80, 34);//预防bug，重新设置窗口大小
	}
	/*模块5::成绩统计结束*/

	/*系统架构::成绩保存&&关于信息*/
	void Save_About(int argc, char** argv)//保存成绩与输出关于信息
	{
		//system("mode con cols=80 lines=32");//改变宽高，最开始的用法，因调用Windows API，故现已废弃
		//system("color f0");//改变颜色，最开始的用法，因调用Windows API，故现已废弃
		//system("title 学生成绩管理系统::关于");//更新标题，最开始的用法，因调用Windows API，故现已废弃
		Title(TEXT("学生成绩管理系统::成绩保存&&关于"));//调用Title函数设置子界面的标题
		Window(0, 0, 80, 34);//设置窗口大小
		Purple();//白色背景，紫色字体
		Cls();//清屏
		cout << "\n·正在保存..." << endl;//改为紫色字体
		Black();//白色背景，缺省黑色字体
		if (data == NULL || subject == NULL || N == 0)//如果指针为空或者N为0，说明没有录入成绩或者已经全部删除，调用Windows API弹出提示信息
		{
			MessageBox(GetConsoleWindow(), TEXT("尚未录入学生数据或数据已全部删除，无法保存。"), TEXT("保存失败"), MB_OK | MB_ICONEXCLAMATION | MB_DEFBUTTON1);
		}
		else//否则，便是已经录入成绩
		{
			time_t now = time(0);//获取当前时间
			char time[100];//定义字符数组，用于存储时间字符串
			ctime_s(time, 100, &now);//将时间格式化为字符串
			ofstream outfile;//创建输出文件流对象
			outfile.open("学生成绩信息.txt", ios_base::out | ios_base::app);//以输出方式打开文件，无则创建，若已有原文件则新数据添加在末尾
			if (!outfile)//创建文件失败，肯定是没给管理员权限，那还了得，必须弹出对话框提醒
			{
				MessageBox(GetConsoleWindow(), TEXT("创建文件失败！请以管理员身份运行此程序。"), TEXT("创建失败"), MB_OK | MB_ICONHAND | MB_DEFBUTTON1);
			}
			else//否则，一切顺利
			{
				outfile << "【保存时间】" << time;//写入
				for (count = 0; count < N; count++)//外层循环遍历学生数据保存
				{
					outfile << "\n·序号为[ " << count + 1 << " ]的学生的 >> " << endl;
					outfile << "\n  学号：" << (data + count)->number << endl;//保存学号
					outfile << "\n  姓名：" << (data + count)->name << endl;//保存姓名
					for (inside = 0; inside < M; inside++)//内层循环遍历课程保存
					{
						outfile << "\n  课程【" << *(subject + inside) << "】的成绩：" << (data + count)->score[inside] << endl;//保存成绩
					}
					outfile << "\n  平均成绩：" << (data + count)->average << endl;//保存平均成绩
				}
				outfile << "\n==================================\n" << endl;//作为分隔符
				MessageBox(GetConsoleWindow(), TEXT("保存数据成功！"), TEXT("保存成功"), MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);//弹出成功信息
				outfile.close();//关闭输出文件
			}
		}
		do//do-while循环，先执行一次
		{
			Purple();//白色背景，紫色字体
			Cls();//清屏
			cout << "\n\n\n\t\t\t\t    [ 关于 ]" << endl;//改为紫色字体
			Black();//白色背景，缺省黑色字体
			cout << "\n\n\t\t\t【程序版本】1.1.99.275" << endl;//自定义版本号
			cout << "\n\n\t\t\t【程序参数】" << argc << endl;//调用程序时，有无附带输入的参数
			cout << "\n\n\t\t\t【程序路径】" << *argv << endl;//输出程序路径
			cout << "\n\n\t\t\t【编译工具】Microsoft Visual Studio" << endl;//自定义编译工具
			cout << "\n\n\t\t\t【版权所属】CaseClosedX@outlook.com" << endl;//版权信息
			cout << "\n\n\t\t\t\t【r】返回主界面" << endl;
			cout << "\n\n\t\t\t\t【q】退出系统" << endl;
			if (error == true)//catch错误，调用函数
			{
				Error(true);
			}
			Input_char(true);//输入字符
			switch (input_char)//判断输入的字符
			{
			case 'r':Window(0, 0, 80, 34); break;//跳出循环，返回上一级，即主界面，此次没有直接return;是为多元化考虑
			case 'q':exit(0); break;//q则直接退出系统，返回值0
			default: error = true;//否则，输入错误
			}
		} while (input_char != 'r');//为r则此函数调用结束
		Window(0, 0, 80, 34);//须设置窗口大小
	}
	/*系统架构::成绩保存&&关于信息*/
};
/*===================封装功能模块类，继承系统架构类结束===================*/


/*系统架构::主函数调用*/
int main(int argc, char** argv, char** envp)//主函数，参数依次为：使用CMD窗口运行进程时输入参数个数，程序目录，系统环境变量
{
	Framework Build;//定义系统架构类
	Modular Function;//定义功能模块类
	do//do-while循环，先执行一次
	{
		Build.Title(TEXT("学生成绩管理系统::主界面"));//设置标题，调用Build类
		Build.Black();//更新前景色、背景色
		Build.Hide_cursor();//隐藏光标
		Build.Window(0, 0, 80, 34);//设置窗口大小
		Cls();//清屏
		//cout << "\033[2J";//Linux下的清屏，最开始使用，现已废弃，不适用于Windows 7及以下系统，Windows 10非最新版本也需要掂量掂量
		Build.Purple();//白色背景，紫色字体，beautiful
		cout << "\n\n\n\t\t\t      [ 请选择系统功能项 ]" << endl;//改为紫色字体，后恢复缺省黑色字体
		Build.Black();//恢复缺省颜色
		cout << "\n\n\t\t\t\t【a】成绩录入" << endl;
		cout << "\n\n\t\t\t\t【b】成绩显示" << endl;
		cout << "\n\n\t\t\t\t【c】成绩排序" << endl;
		cout << "\n\n\t\t\t\t【d】成绩修改" << endl;
		cout << "\n\n\t\t\t\t【e】成绩统计" << endl;
		cout << "\n\n\t\t\t\t【f】成绩保存&&关于" << endl;
		cout << "\n\n\t\t\t\t【q】退出系统" << endl;
		if (Build.error == true)//catch输入错误，调用函数
		{
			Build.Error(true);//参数为主界面专用参数（主界面较宽）
		}
		Build.Input_char(true);//输入字符
		switch (Build.input_char)//判断输入的字符
		{
		case 'a':Function.Input();  break;//成绩录入
		case 'b':Function.Output(); break;//成绩显示
		case 'c':Function.Sort(); break;//成绩排序
		case 'd':Function.Update(); break;//成绩修改
		case 'e':Function.Statistics(); break;//成绩统计
		case 'f':Function.Save_About(argc, argv); break;//输出关于信息，其中，envp忒长了，影响美观，就不传入了
		default: Build.error = true;//否则，输入错误，方便catch error
		}
	} while (Build.input_char != 'q');//为q则此循环结束

	return 0;//程序执行完毕，返回值0
}
/*系统架构::主函数调用结束*/