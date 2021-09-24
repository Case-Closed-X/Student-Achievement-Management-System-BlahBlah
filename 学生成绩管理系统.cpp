/*ϵͳ�ܹ�::ͷ�ļ�*/
#include <iostream>//ʹ��iostreamͷ�ļ���������׼�����������
using namespace std;//�˳���ϼ�����ҵҪ����ָ����д����̨Ӧ�ó��򣬹ʶ�ʹ�ñ�׼�����ռ�std
#include <conio.h>//ʹ��conio.hͷ�ļ�������_getch()
#include <windows.h>//ʹ��windows.hͷ�ļ�������Windows API���
#include <strsafe.h>//�ο�΢���ĵ��÷�������StringCchPrintf()�����Ը�ʽ���ַ���
#include <fstream>//�ļ�д�����
#include <ctime>//����ɼ�ͬʱ���浱ǰʱ��
/*ϵͳ�ܹ�::ͷ�ļ�����*/

/*ϵͳ�ܹ�::ϵͳ���ܺ궨��*/
#define Cls() system("cls")//�궨�����system����ִ��CMD�������������������δ�ҵ����õ��������
/*ϵͳ�ܹ�::ϵͳ���ܺ궨�����*/

/*===================��װϵͳ�ܹ���===================*/
class Framework
{
private://˽�г�Ա����

protected://������Ա����

public://���г�Ա

	/*ϵͳ�ܹ�::��������*/
	char input_char = NULL;//����������ַ��������ж�
	int input_int = NULL;//�����������ֵ�������ж�
	string input_string = "NULL";//���������string�࣬�����ж�
	char CR = NULL;//���������ַ��������жϵڶ�������Ļس���
	bool error = false;//�ж��Ƿ����
	/*ϵͳ�ܹ�::�����������*/

	/*ϵͳ�ܹ�::���ÿ���̨����*/
	TCHAR szOldTitle[MAX_PATH] = TEXT("NULL");//����ɵĿ���̨����
	TCHAR szNewTitle[MAX_PATH] = TEXT("NULL");//�����µĿ���̨����

	void Title(const wchar_t* title)//�������̨����
	{
		if (GetConsoleTitle(szOldTitle, MAX_PATH))//��þɱ���
		{
			StringCchPrintf(szNewTitle, MAX_PATH, title, szOldTitle);//�ο�΢���ĵ��÷������ظ�ʽ���ַ���
			SetConsoleTitle(szNewTitle);//�����±���
		}
	}
	/*ϵͳ�ܹ�::���ÿ���̨�������*/

	/*ϵͳ�ܹ�::���ÿ���̨�����뻺������λ�����С*/
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);//��ñ�׼������

	void Window(int pos_x, int pos_y, int cols, int lines)//���ô��ںͻ�������С
	{
		SMALL_RECT rc = { SHORT(pos_x),SHORT(pos_y), SHORT(cols - 1), SHORT(lines - 1) };//����λ�����С
		SetConsoleWindowInfo(hStdout, true, &rc);//�������ô��ڴ�С
		COORD size = { SHORT(cols), 9000 };//��������С������9000�л�����������϶����ã���ʹ��
		SetConsoleScreenBufferSize(hStdout, size);//�������û�������С
		SetWindowLongPtrA(//ʹ����̨�����޷����Ĵ�С������bug
			GetConsoleWindow(),
			GWL_STYLE,
			GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)
			& ~WS_SIZEBOX
		);//& ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX���������С����ť
	}
	/*ϵͳ�ܹ�::���ÿ���̨�����뻺������λ�����С����*/

	/*ϵͳ�ܹ�::����*/
	/*void Cls() {//������������̫���ã���Ȼ�ᵼ������״����������Ŀǰ��bug
		CONSOLE_SCREEN_BUFFER_INFO cursor;
		GetConsoleScreenBufferInfo(hStdout, &cursor);//�õ���ǰ���λ��

		SetConsoleCursorPosition(hStdout, { 0,0 });//���ù��λ��Ϊ{ 0,0 }
		for (SHORT i = 0; i <= cursor.dwCursorPosition.Y ; i++)//ÿ�ж����
		{
			for (size_t i = 1; i < 80 + 1; i++)//i������=0
			{
				cout << ' ';//����Backspace̫���˵�bug
			}
		}
		SetConsoleCursorPosition(hStdout, { 0,0 });//���ù��λ��Ϊ{ 0,0 }
	}*/
	/*ϵͳ�ܹ�::��������*/

	/*ϵͳ�ܹ�::������ɫ����*/
	void Black()//��ɫ������ȱʡ��ɫ����
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
	}

	void Black_White()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}

	void Black_Red()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED);
	}

	void Black_Yellow()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	}

	void Purple()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
	}

	void Red()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED);
	}

	void Green()//��ɫ��������ɫ����
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_GREEN);
	}

	void Magenta()//��ɫ�������Ϻ�ɫ����
	{
		SetConsoleTextAttribute(hStdout, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE);
	}
	/*ϵͳ�ܹ�::������ɫ�������*/

	/*ϵͳ�ܹ�::��������ʾ����̨���*/
	CONSOLE_CURSOR_INFO cursor_info;//�������̨���

	void Hide_cursor()//���ع��
	{
		cursor_info.dwSize = 1;//�����Ϊ1
		cursor_info.bVisible = false;//���ع��
		SetConsoleCursorInfo(hStdout, &cursor_info);//ʹ�ñ�׼����л�õľ�������ÿ���̨���״̬
	}

	void Display_cursor()//��ʾ���
	{
		cursor_info.dwSize = 1;//�����Ϊ1
		cursor_info.bVisible = true;//��ʾ���
		SetConsoleCursorInfo(hStdout, &cursor_info);//ʹ�ñ�׼����л�õľ�������ÿ���̨���״̬
	}
	/*ϵͳ�ܹ�::��������ʾ����̨������*/

	/*ϵͳ�ܹ�::��ͣ����̨���*/
	void Pause(bool style)//��ͣ����̨���
	{
		if (style == true)//��������ʽ�����޻���ʹ��
		{
			cout << "\n\n";//�������Σ���������
			Magenta();//��ɫ�������Ϻ�ɫ����
			cout << "\t\t\t\t�밴��������� >> " << endl;//������ʾ����ɫΪ�Ϻ�ɫ
			Black();//�ص�ȱʡ״̬
		}
		else//�ӽ�����ʽ
		{
			cout << "\n\n";//�������Σ���������
			Black_Yellow();//��ɫ��������ɫ����
			cout << "���밴��������� >> ";//������ʾ����ɫΪ��ɫ
			Black_White();//�ص��ӽ���ȱʡ״̬
		}
		char temp = _getch();//ʹ��_getch()�������������ַ������룬�������ʵ�����壨�밴�����������
	}
	/*ϵͳ�ܹ�::��ͣ����̨�������*/

	/*ϵͳ�ܹ�::��̬��ʾ�����ж��ַ�*/
	void Input_char(bool style)//�����ַ�
	{
		if (style == true)//��������ʽ
		{
			cout << "\n\n";//�������Σ����Ƹ�ʽ������
			input_char = _getch();//�����ַ�
			Green();//��ɫ��������ɫ����
			do
			{
				cout << "\r";//'\r'��Ӧ�ã��ػر��п�ͷ
				for (size_t i = 1; i < 80; i++)//i������=0����Ϊ�ᵼ�»���
				{
					cout << ' ';//����Backspace̫���˵�bug
				}
				cout << "\r\t\t\t\t";//'\r'��Ӧ�ã��ػر��п�ͷ

				switch (input_char)
				{
				case '\015':cout << "��ǰѡ��[ �س� ]��"; break;//�ж��Ƿ���ڻس���
				case '\033':cout << "��ǰѡ��[ Escape ]��"; break;//�ж��Ƿ����ESC��
				case '\010':cout << "��ǰѡ��[ Backspace ]��"; break;//�ж��Ƿ�����˸��
				default:
					cout << "��ǰѡ��[ " << input_char << " ]��";//��������ֱ�����
					break;
				}
				/*if (input_char == '\015')
				{
					cout << "��ǰѡ��[ �س� ]��";
				}
				else if (input_char == '\033')
				{
					cout << "��ǰѡ��[ Escape ]��";
				}
				else if (input_char == '\010')
				{
					cout << "��ǰѡ��[ Backspace ]��";
				}
				else
				{
					cout << "��ǰѡ��[ " << input_char << " ]��";
				}*/
				CR = _getch();//����س���
				if (CR != '\015')//���ڶ������벢�ǻس���
				{
					input_char = CR;//��ֵ��input_char
				}
			} while (CR != '\015');//��CR==�س�������Դ�ϲ��ֹͣѭ��
			Black();//��Ϊȱʡ��ɫ����
		}
		else//�ӽ�����ʽ
		{
			cout << "\n";
			input_char = _getch();//�����ַ�
			Black_Yellow();//��ɫ��������ɫ����
			do
			{
				cout << "\r";//'\r'��Ӧ�ã��ػر��п�ͷ
				for (size_t i = 1; i < 80; i++)
				{
					cout << ' ';//����Backspace̫���˵�bug
				}
				cout << "\r";
				switch (input_char)
				{
				case '\015':cout << "����ǰѡ��[ �س� ]��"; break;//�ж��Ƿ���ڻس���
				case '\033':cout << "����ǰѡ��[ Escape ]��"; break;//�ж��Ƿ����ESC��
				case '\010':cout << "����ǰѡ��[ Backspace ]��"; break;//�ж��Ƿ�����˸��
				default:
					cout << "����ǰѡ��[ " << input_char << " ]��";//��������ֱ�����
					break;
				}
				CR = _getch();//����س���
				if (CR != '\015')//���ڶ������벢�ǻس���
				{
					input_char = CR;//��ֵ��input_char
				}
			} while (CR != '\015');//��CR==�س�������Դ�ϲ��ֹͣѭ��
			Black_White();//��Ϊȱʡ��ɫ����
		}
	}
	/*ϵͳ�ܹ�::��̬��ʾ�����ж��ַ�����*/

	/*ϵͳ�ܹ�::��̬��ʾ�����ַ�����catch*/
	void Error(bool style)//��ʾ�������
	{
		if (style == true)//��������ʽ
		{
			Window(0, 0, 80, 34);//���ô��ڴ�С
			Red();//��Ϊ��ɫ����
			cout << "\n\n\t\t";
			switch (input_char)
			{
			case '\015':cout << "���������ֵΪ[ �س� ]����������ѡ�� >>>>>>>> " << endl; break;//�ж��Ƿ���ڻس���
			case '\033':cout << "���������ֵΪ[ Escape ]����������ѡ�� >>>>>>>> " << endl; break;//�ж��Ƿ����ESC��
			case '\010':cout << "���������ֵΪ[ Backspace ]����������ѡ�� >>>>>>>> " << endl; break;//�ж��Ƿ�����˸��
			default://��������ֱ�����
				cout << "���������ֵΪ[ " << input_char << " ]����������ѡ�� >>>>>>>> " << endl;
				break;
			}
			/*if (input_char == '\015')
			{
				cout << "���������ֵΪ[ �س� ]����������ѡ�� >>>>>>>> " << endl;
			}
			else if (input_char == '\033')
			{
				cout << "���������ֵΪ[ Escape ]����������ѡ�� >>>>>>>> " << endl;
			}
			else if (input_char == '\010')
			{
				cout << "���������ֵΪ[ Backspace ]����������ѡ�� >>>>>>>> " << endl;
			}
			else
			{
				cout << "���������ֵΪ[ " << input_char << " ]����������ѡ�� >>>>>>>> " << endl;
			}*/
			Black();//��Ϊȱʡ��ɫ����
			error = false;//���error��Ϊȱʡֵfalse����ʾ�˴ε���ʾ����������
		}
		else//�ӽ�����ʽ
		{
			Window(0, 0, 80, 34);
			Black_Red();//��Ϊ��ɫ��������ɫ����
			cout << "\n";
			switch (input_char)
			{
			case '\015':cout << "�����������ֵΪ[ �س� ]����������ѡ�� >> " << endl; break;//�ж��Ƿ���ڻس���
			case '\033':cout << "�����������ֵΪ[ Escape ]����������ѡ�� >> " << endl; break;//�ж��Ƿ����ESC��
			case '\010':cout << "�����������ֵΪ[ Backspace ]����������ѡ�� >> " << endl; break;//�ж��Ƿ�����˸��
			default://��������ֱ�����
				cout << "�����������ֵΪ[ " << input_char << " ]����������ѡ�� >> " << endl;
				break;
			}
			Black_White();//��Ϊ��ɫ����
			error = false;//���error��Ϊȱʡֵfalse����ʾ�˴ε���ʾ����������
		}
	}
	/*ϵͳ�ܹ�::��̬��ʾ�����ַ�����catch����*/

	~Framework()//��������
	{
		CloseHandle(hStdout);//�رձ�׼������
	}
};
/*===================��װϵͳ�ܹ������===================*/


/*ϵͳ�ܹ�::���ݴ洢*/
int M(0);//�γ���Ŀ
/*������*/
class Data//�����࣬���ڴ������
{
private://˽�г�Ա����

protected://������Ա����

public://���г�Ա

	string number;//ѧ�ţ�ǧ��Ҫ��ֵΪNULL�����������ڴ����crash��������
	string name;//������ǧ��Ҫ��ֵΪNULL�����������ڴ����crash��������
	double* score = new double[M];//���Ƴɼ������ж�̬�����ڴ棬�����crash������������Ҫ���ظ�ֵ�������������STL������ԭ��δ��ʩ�У�ֻ���ֶ���
	double average = 0.0;//����ѧ����ƽ���ɼ�
	bool delete_mark = false;//ɾ�����

	/*��Ϊ������ָ��������޷�ֱ�Ӹ�ֵ���������ظ�ֵ���������������crash��������*/
	Data& operator = (const Data& Copy)//���ظ�ֵ�����
	{
		number = Copy.number;//�������Ƴ����Ա
		name = Copy.name;//�������Ƴ����Ա
		average = Copy.average;//�������Ƴ����Ա

		double* temp = new double[M];//����ָ��ָ�������
		memcpy(temp, Copy.score, M * sizeof(double));//�����ڴ濽������

		delete[] score;//ɾ��ԭָ��ָ�������
		score = temp;//������ָ��
		return *this;//thisָ�뷵�ص�ǰ���������
	}
	/*���ظ�ֵ������������޸�����ʱ������crash��������*/

	/*����Ϊ�����ٴγ�������©����˳���д�������캯����������������������Ĭ�Ϲ��캯�����޷���̬�����ڴ涨���࣬�ʴ�����
	Data(const Data& Copy)//�������캯��
	{
		number = Copy.number;//���Ƴ����Ա
		name = Copy.name//���Ƴ����Ա
		average = Copy.average//���Ƴ����Ա

		score= new double[M];//����ָ��ָ�������
		memcpy(score, Copy.score, M * sizeof(double));//�����ڴ濽������
	}
	//�������캯������*/

	~Data()//�����������ͷ�������ڴ�
	{
		delete[] score;
	}

};
/*ϵͳ�ܹ�::���ݴ洢����*/


/*===================��װ����ģ���࣬���м̳�ϵͳ�ܹ���===================*/
class Modular :public Framework
{
private://˽�г�Ա

	int count = 0, inside = 0;//����ѭ��֮�м���
	Data swap;//���彻����ֵ����

protected://������Ա

	int N = 0;//ѧ����Ŀ
	int N_search = 0;//����������ɾ�������ݣ���ѧ����������Ŀ
	string* subject = NULL;//����string��ָ�룬�γ�����
	Data* data = NULL;//����data��ָ�룬ѧ������

public://���г�Ա

	~Modular()//�����������ͷ�������ڴ�
	{
		delete[]subject;
		delete[]data;
	}

	/*ģ��1::�ɼ�����*/
	void Input()//�ɼ�¼��
	{
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ�¼��"));//���ñ���
		Window(0, 0, 80, 34);//���ô��ڴ�СΪ80��34�У�����ԭ��64�е��趨����ȫû��Ҫ��
		Black_White();//����ǰ��ɫ������ɫ
		Cls();//����
		if ((data != NULL) || (subject != NULL))//����Ϊ�գ�˵���Ѿ�¼������
		{
			if (IDCANCEL == MessageBox(GetConsoleWindow(), TEXT("��⵽���ݿ����Ѵ������ݣ�ȷ������¼��������"), TEXT("��ʾ��Ϣ"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
			{
				//����Windows API�����Ի���ȱʡֵΪȡ��
				Window(0, 0, 80, 34);//�������µ������ڣ��������bug
				return;//��ֵΪȡ������˺������ý���
			}
		}
		Display_cursor();//��ʾ���
		//do
		//{
		Cls();//����
		cout << "\n��������ѧ����������";
		cin >> N;//¼��ѧ������
		cin.clear();//����������ĸ�����crash�������������������ʶ
		cin.ignore(1024, '\n');//����������ĸ�����crash�������������������
		cout << "\n��������γ̵�������";
		cin >> M;//¼��γ�����
		cin.clear();//����������ĸ�����crash�������������������ʶ
		cin.ignore(1024, '\n');//����������ĸ�����crash�������������������
		if (N <= 0 || M <= 0)//���N��M��С�ڵ���0��catch�������
		{
			Black_Red();//��ɫ��������ɫ����
			cout << "\n�����������ֵ����С�ڻ����0" << endl;
			Black_White();//��ɫ��������ɫ����
			Pause(false);//��ͣ��Ļ���
			return;//ֱ�ӷ���
		}
		//} while (N <= 0 || M <= 0);//���N��M��С�ڵ���0������ѭ��
		N_search = N;//����������ɾ�������ݣ�������������ѧ������
		delete[]subject;//����ڴ�й©����ε��ú���ʱ���Ȱ���ǰ���ڴ�ռ��ͷŵ�
		delete[]data;//����ڴ�й©����ε��ú���ʱ���Ȱ���ǰ���ڴ�ռ��ͷŵ�
		data = new Data[N];//��̬�����ڴ�
		subject = new string[M];//��̬�����ڴ�
		Cls();//����
		for (count = 0; count < M; count++)//�˴���STL�Ļ���ð�ܶ࣬�Ͳ�����ȷ�������ˣ���ϧ�����ø�
		{
			cout << "\n���������[ " << count + 1 << " ]�ſε����ƣ�";
			cin >> *(subject + count);//ָ�����string��Ŀγ�����
		}
		Cls();//����
		for (count = 0; count < N; count++)
		{
			cout << "\n���������[ " << count + 1 << " ]λѧ���� >> " << endl;
			cout << "\n  ѧ�ţ�";
			cin >> (data + count)->number;//����ѧ��
			cout << "\n  ������";
			cin >> (data + count)->name;//��������
			for (inside = 0; inside < M; inside++)//�ڲ�ѭ��������ɼ�
			{
				cout << "\n";
				do
				{
					cout << "  �γ̡�" << *(subject + inside) << "���ĳɼ���";
					cin >> (data + count)->score[inside];//����ɼ�
					cin.clear();//����������ĸ�����crash�������������������ʶ
					cin.ignore(1024, '\n');//����������ĸ�����crash�������������������
					if ((data + count)->score[inside] < 0)//catch��������
					{
						cout << "  ���ɼ�����С��0��" << endl;
					}
				} while ((data + count)->score[inside] < 0);//������ȷ���룬�ſ�������ѭ��
				(data + count)->average += (data + count)->score[inside];//����ѧ���ĳɼ��ܺ�
			}
			(data + count)->average /= (double)(M);//����ѧ����ƽ���ɼ�
			Cls();//����
		}
		Window(0, 0, 80, 34);//���������ô��ڴ�С
	}
	/*ģ��1::�ɼ��������*/

	/*ģ��2::�ɼ���ʾ*/
	void Output()//�ɼ���ʾ�����û�����9000�е����ƣ���������ȫ�����
	{
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ���ʾ"));//���ñ���
		Window(0, 0, 80, 34);//���ô��ڴ�СΪ80��34��
		Black_White();//����ǰ��ɫ������ɫ
		Cls();//����
		Display_cursor();//��ʾ���
		if (data == NULL || subject == NULL)//���ָ��Ϊ�գ�����û��¼��ɼ�
		{
			cout << "\n����δ¼��ѧ�����ݣ������������˵�..." << endl;
			Pause(false);//��ͣ��Ļ���
			return;
		}
		//���򣬱����Ѿ�¼��ɼ�

		if (N != 0)//N��Ϊ0�������Ѿ�ȫ�������ɾ��
		{
			for (count = 0; count < N; count++)//���ѭ������ѧ�����
			{
				cout << "\n�����Ϊ[ " << count + 1 << " ]��ѧ���� >> " << endl;
				cout << "\n  ѧ�ţ�" << (data + count)->number << endl;//���ѧ��
				cout << "\n  ������" << (data + count)->name << endl;//�������
				for (inside = 0; inside < M; inside++)//�ڲ�ѭ�������γ����
				{
					cout << "\n  �γ̡�" << *(subject + inside) << "���ĳɼ���" << (data + count)->score[inside] << endl;//����ɼ�
				}
				cout << "\n  ƽ���ɼ���" << (data + count)->average << endl;//���ƽ���ɼ�
			}
		}
		else
		{
			cout << "\n��������ȫ�����Ϊɾ��" << endl;
		}
		Pause(false);//��ͣ��Ļ���//��ͣ��ʾ�Եȴ���һ������

		Window(0, 0, 80, 34);//���������ô��ڴ�С
	}
	/*ģ��2::�ɼ���ʾ����*/

	/*ģ��3::�ɼ�����*/
	void Sort()//�ɼ���������ҵҪ���ֶ�ʵ�ּ������㷨���Ͳ�������
	{
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ�����"));//���ñ���
		Window(0, 0, 80, 34);//���ô��ڴ�СΪ80��34��
		Black_White();//����ǰ��ɫ������ɫ
		Cls();//����
		Display_cursor();//��ʾ���
		if (data == NULL || subject == NULL)//ָ��Ϊ�գ���δ¼��
		{
			cout << "\n����δ¼��ѧ�����ݣ������������˵�..." << endl;
			Pause(false);//��ͣ��Ļ���
			return;
		}

		Hide_cursor();//���ع��
		do//do-whileѭ������ִ��һ��
		{
			Black_White();//��ɫ��������ɫ����
			Cls();//����
			cout << "\n����ѡ������ʽ��" << endl;
			cout << "\n\t��u������" << endl;
			cout << "\n\t��d������" << endl;
			cout << "\n\t��r������������" << endl;
			cout << "\n\t��q���˳�ϵͳ" << endl;
			if (error == true)//catch���󣬵��ú���
			{
				Error(false);//����Error����
			}
			Input_char(false);//�����ַ�
			switch (input_char)//�ж�������ַ�
			{
			case 'u':break;//Ϊu������switch���
			case 'd':break;//Ϊd������switch���
			case 'r':Window(0, 0, 80, 34); return; break;//ֱ�ӽ����������ã����������棬����֮ǰ���������ô��ڴ�С
			case 'q':exit(0); break;//q��ֱ���˳�ϵͳ������ֵ0
			default: error = true;//�����������
			}
		} while (input_char != 'u' && input_char != 'd');//�����벻Ϊu��d������ѭ��
		if (input_char == 'u')//������ʵ��ô��if...else�ǲ����Ƶķ������������ø���
		{
			do//do-whileѭ������ִ��һ��
			{
				Black_White();//��ɫ��������ɫ����
				Cls();//����
				cout << "\n����ѡ��������ԣ�" << endl;
				cout << "\n\t��s��ѧ��" << endl;
				cout << "\n\t��n������" << endl;
				cout << "\n\t��a��ƽ���ɼ�" << endl;
				cout << "\n\t��k���γ̳ɼ�" << endl;
				cout << "\n\t��r������������" << endl;
				cout << "\n\t��q���˳�ϵͳ" << endl;
				if (error == true)//catch���󣬵��ú���
				{
					Error(false);
				}
				Input_char(false);//�����ַ�
				switch (input_char)//�ж�������ַ�
				{
				case 's'://��������
					for (count = 1; count < N; count++)//����1��N
					{
						for (inside = count; inside > 0; inside--)//�ڲ�Ӵ�Сѭ��
						{
							if (((data + inside)->number) < ((data + inside - 1)->number))//����ڶ���ֵС�ڵ�һ���Ļ�
							{
								swap = *(data + inside);//�����������ֵ
								*(data + inside) = *(data + inside - 1);
								*(data + inside - 1) = swap;
							}
							else//���ڵĻ�ɶҲ����˵��ֱ�������ڲ�ѭ��
							{
								break;//������ѭ��
							}
						}
					}
					break;//break������
				case 'n'://����������ǰ��ͬ���ٲ�׸��
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
								break;//������ѭ��
							}
						}
					}
					break;
				case 'a'://����������ǰ��ͬ���ٲ�׸��
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
								break;//������ѭ��
							}
						}
					}
					break;
				case 'k':
					do
					{
						Cls();//����
						for (inside = 0; inside < M; inside++)//����γ��������Ϣ
						{
							cout << "\n  ��" << inside << "��" << *(subject + inside) << endl;
						}
						if (error == false)//�������
						{
							cout << "\n����ѡ������γ̣�";
						}
						else//catch error������
						{
							Black_Red();
							cout << "\n  ���������������ѡ������γ̣�";
							Black_White();
							error = false;
						}
						cin >> input_int;//�������
						cin.clear();//����������ĸ�����crash�������������������ʶ
						cin.ignore(1024, '\n');//����������ĸ�����crash�������������������
						if (input_int < 0 || input_int >= M)//�����Ų���0~M����ô�����������
						{
							error = true;//error���ϰ���
						}
					} while (input_int < 0 || input_int >= M);//�����Ų���0~M����ô����ѭ��
					//����������ǰ��ͬ���ٲ�׸��
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
								break;//������ѭ��
							}
						}
					}
					break;
				case 'r':Window(0, 0, 80, 34); return; break;//ֱ�ӽ����������ã����������棬��Ȼ��Ҫ�������û�������С����������bug
				case 'q':exit(0); break;//q��ֱ���˳�ϵͳ������ֵ0
				default: error = true;//�����������
				}
			} while (input_char != 's' && input_char != 'n' && input_char != 'a' && input_char != 'k');//�����֤���е���࣬��4����ĸ
		}
		else if (input_char == 'd')//����
		{
			do//do-whileѭ������ִ��һ��
			{
				Black_White();//��ɫ��������ɫ����
				Cls();//����
				cout << "\n����ѡ��������ԣ�" << endl;
				cout << "\n\t��s��ѧ��" << endl;
				cout << "\n\t��n������" << endl;
				cout << "\n\t��a��ƽ���ɼ�" << endl;
				cout << "\n\t��k���γ̳ɼ�" << endl;
				cout << "\n\t��r������������" << endl;
				cout << "\n\t��q���˳�ϵͳ" << endl;
				if (error == true)//catch���󣬵��ú���
				{
					Error(false);
				}
				Input_char(false);//�����ַ�
				switch (input_char)//�ж�������ַ�
				{
				case 's'://ð������
					for (count = 0; count < N - 1; count++)//���count��0��ʼ��N-1����ѭ��
					{
						for (inside = 0; inside < N - count - 1; inside++)//�ڲ�inside��0��ʼ��N-count-1����ѭ��
						{
							if (((data + inside)->number) < ((data + inside + 1)->number))//�����һ������ֵС�ڵڶ�������ֵ�Ļ�
							{
								swap = *(data + inside);//�����������ֵ
								*(data + inside) = *(data + inside + 1);
								*(data + inside + 1) = swap;
							}
							else
							{
								break;//������ѭ��
							}
						}
					}
					break;
				case 'n'://ð������
					for (count = 0; count < N - 1; count++)//���count��0��ʼ��N-1����ѭ��
					{
						for (inside = 0; inside < N - count - 1; inside++)//�ڲ�inside��0��ʼ��N-count-1����ѭ��
						{
							if (((data + inside)->name) < ((data + inside + 1)->name))//�����һ������ֵС�ڵڶ�������ֵ�Ļ�
							{
								swap = *(data + inside);//�����������ֵ
								*(data + inside) = *(data + inside + 1);
								*(data + inside + 1) = swap;
							}
							else
							{
								break;//������ѭ��
							}
						}
					}
					break;
				case 'a'://ð��������ǰ��ͬ���ٲ�׸��
					for (count = 0; count < N - 1; count++)//���count��0��ʼ��N-1����ѭ��
					{
						for (inside = 0; inside < N - count - 1; inside++)//�ڲ�inside��0��ʼ��N-count-1����ѭ��
						{
							if (((data + inside)->average) < ((data + inside + 1)->average))//�����һ������ֵС�ڵڶ�������ֵ�Ļ�
							{
								swap = *(data + inside);//�����������ֵ
								*(data + inside) = *(data + inside + 1);
								*(data + inside + 1) = swap;
							}
							else
							{
								break;//������ѭ��
							}
						}
					}
					break;
				case 'k':
					do
					{
						Cls();//����
						for (inside = 0; inside < M; inside++)//����γ���Ϣ
						{
							cout << "\n  ��" << inside << "��" << *(subject + inside) << endl;
						}
						if (error == false)
						{
							cout << "\n����ѡ������γ̣�";
						}
						else
						{
							Black_Red();
							cout << "\n  ���������������ѡ������γ̣�";
							Black_White();
							error = false;
						}
						cin >> input_int;//�������
						cin.clear();//������������ĸ�����crash��������
						cin.ignore(1024, '\n');//������������ĸ�����crash��������
						if (input_int < 0 || input_int >= M)//һֱ�ж�catchһֱˬ
						{
							error = true;
						}
					} while (input_int < 0 || input_int >= M);//һֱѭ��һֱˬ
					//ð������
					for (count = 0; count < N - 1; count++)//���count��0��ʼ��N-1����ѭ��
					{
						for (inside = 0; inside < N - count - 1; inside++)//�ڲ�inside��0��ʼ��N-count-1����ѭ��
						{
							if (((data + inside)->score[input_int]) < ((data + inside + 1)->score[input_int]))//�����һ������ֵС�ڵڶ�������ֵ�Ļ�
							{
								swap = *(data + inside);//�����������ֵ
								*(data + inside) = *(data + inside + 1);
								*(data + inside + 1) = swap;
							}
							else
							{
								break;//������ѭ��
							}
						}
					}
					break;
				case 'r':Window(0, 0, 80, 34); return; break;//ֱ�ӽ����������ã����������棬˵�ܶ���ˣ���˵��
				case 'q':exit(0); break;//q��ֱ���˳�ϵͳ������ֵ0
				default: error = true;//�����������
				}
			} while (input_char != 's' && input_char != 'n' && input_char != 'a' && input_char != 'k');//��ʵ���ǽ�������ճ���󷨣�Ȼ��ļ���С�ں�~���Ϊ�˽���
		}

		Window(0, 0, 80, 34);//�Է���һ������ʾbug����Ȼ����
	}
	/*ģ��3::�ɼ��������*/

	/*ģ��4::�ɼ��޸�*/
	void Update()//�ɼ��޸ġ�������ɾ��
	{
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ��޸�"));//���ñ���
		Window(0, 0, 80, 34);//���ô��ڴ�СΪ80��34��
		Black_White();//����ǰ��ɫ������ɫ
		Cls();//����
		if (data == NULL || subject == NULL)//Ϊ������һʧ����Ȼ��Ҫ��֤�Ƿ��Ѿ�¼������
		{
			Display_cursor();//��ʾ���
			cout << "\n����δ¼��ѧ�����ݣ������������˵�..." << endl;
			Pause(false);//��ͣ��Ļ���
			return;
		}
		//������Ѿ��������ݣ�Ȼ��ѡ��������

		do//do-whileѭ������ִ��һ��
		{
			Hide_cursor();//���ع��
			Black_White();//��ɫ��������ɫ����
			Cls();//����
			cout << "\n����ѡ��������" << endl;
			cout << "\n\t��o�����" << endl;
			cout << "\n\t��s��ѧ��" << endl;
			cout << "\n\t��n������" << endl;
			cout << "\n\t��r������������" << endl;
			cout << "\n\t��q���˳�ϵͳ" << endl;
			if (error == true)//catch���󣬵�����ʾ������
			{
				Error(false);
			}
			Input_char(false);//�����ַ�
			switch (input_char)//�ж�������ַ�
			{
			case 'o'://���
				do
				{
					Display_cursor();//��ʾ���
					Cls();//����
					if (error == false)//���������ȷ��ֱ�����
					{
						cout << "\n�������������ţ�";
					}
					else//���������󣬾ͷ���
					{
						Black_Red();//����������ɫΪ��ɫ
						cout << "\n  ��������󡿼����������˵�...";
						Black_White();//����������ɫΪ��ɫ
						error = false;
						Pause(false);
						return;
					}
					cin >> input_int;//����һ����ֵ
					cin.clear();//������������ĸ�����crash��������
					cin.ignore(1024, '\n');//������������ĸ�����crash��������
					if (input_int <= 0 || input_int > N_search)//����У�鵽�ѱ��ɾ��������
					{
						error = true;
					}
				} while (input_int <= 0 || input_int > N_search);//У�����N_search����N�����ֵ��
				Cls();//����
				cout << "\n���޸����Ϊ[ " << input_int << " ]��ѧ�������� >> " << endl;
				cout << "\n  ԭѧ�ţ�" << (data + input_int - 1)->number << endl;
				cout << "\n  ԭ������" << (data + input_int - 1)->name << endl;
				for (inside = 0; inside < M; inside++)
				{
					cout << "\n  �γ̡�" << *(subject + inside) << "����ԭ�ɼ���" << (data + input_int - 1)->score[inside] << endl;
				}
				if (IDOK == MessageBox(GetConsoleWindow(), TEXT("�Ƿ�ɾ����ѧ�������ݣ�"), TEXT("ɾ������"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
				{
					//����Windows API�����Ի���ȱʡֵΪȡ��
					(data + input_int - 1)->delete_mark = true;
					for (int temp = input_int - 1; temp < N - 1; temp++)//ð�����򷨽�����ɾ����ǵ���������
					{
						swap = *(data + temp);//ǧƪһ�ɵĽ�������
						*(data + temp) = *(data + temp + 1);
						*(data + temp + 1) = swap;
					}
					N--;//ѧ��������һ
					Window(0, 0, 80, 34);//������������ǰ���������µ������ڣ��������bug
					return;//��ֵΪȷ����ɾ������˺������ý���
				}
				else//�������ֵΪȡ���Ļ�
				{
					if ((data + input_int - 1)->delete_mark == true)//��ɾ������
					{
						(data + input_int - 1)->delete_mark = false;//���ݻش���
						N++;//ѧ������+1��yeah
					}
				}
				cout << "\n��ѧ���޸�Ϊ��";
				cin >> (data + input_int - 1)->number;//����ѧ��
				cout << "\n�������޸�Ϊ��";
				cin >> (data + input_int - 1)->name;//��������
				(data + input_int - 1)->average = 0.0;//ѧ����ƽ��ֵ��ֵΪ0.0
				for (inside = 0; inside < M; inside++)//ѭ���޸Ŀγ���Ϣ
				{
					do {//һ�����doѭ�����ƣ�
						cout << "\n���γ̡�" << *(subject + inside) << "���ĳɼ��޸�Ϊ��";
						cin >> (data + input_int - 1)->score[inside];//����ɼ�
						cin.clear();//������������ĸ�����crash��������
						cin.ignore(1024, '\n');//������������ĸ�����crash��������
						if ((data + input_int - 1)->score[inside] < 0)//һ�������У�����
						{
							cout << "  ���ɼ�����С��0��" << endl;
						}
					} while ((data + input_int - 1)->score[inside] < 0);//��Ϥ��whileѭ��
					(data + input_int - 1)->average += (data + input_int - 1)->score[inside];//�ۼӺ�
				}
				(data + input_int - 1)->average /= (double)(M);//�ۼ�����֮��ֱ�ӳ�����ƽ��ֵ
				break;
			case 's'://ѧ��
				do
				{
					Display_cursor();//��ʾ���
					Cls();//��������ʵ����������Ӧ���г�����ѧ�ţ����������ü�
					if (error == false)//���������ȷ����������
					{
						cout << "\n�����������ѧ�ţ�";
					}
					else//���������󣬾ͷ���
					{
						Black_Red();//����������ɫΪ��ɫ
						cout << "\n  ��������󡿼����������˵�...";
						Black_White();//����������ɫΪ��ɫ
						error = false;
						Pause(false);
						return;
					}
					cin >> input_string;//�����ַ��������ԶԱ��ж�
					error = true;//��˵��ģ��ȸ�����error��˵
					for (count = 0; count < N_search; count++)
					{
						if (input_string == (data + count)->number)//ֻ��������ַ������ҵ�
						{
							error = false;//���ܽ��error������error==true��һֱѭ��һֱѭ��
							break;
						}
					}
				} while (error != false);//���߿���ֱ���ж�input_string != (data + count)->number
				Cls();//����
				cout << "\n���޸����Ϊ[ " << count + 1 << " ]��ѧ�������� >> " << endl;
				cout << "\n  ԭѧ�ţ�" << (data + count)->number << endl;
				cout << "\n  ԭ������" << (data + count)->name << endl;
				for (inside = 0; inside < M; inside++)
				{
					cout << "\n  �γ̡�" << *(subject + inside) << "����ԭ�ɼ���" << (data + count)->score[inside] << endl;
				}
				if (IDOK == MessageBox(GetConsoleWindow(), TEXT("�Ƿ�ɾ����ѧ�������ݣ�"), TEXT("ɾ������"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
				{
					//����Windows API�����Ի���ȱʡֵΪȡ��
					(data + count)->delete_mark = true;
					for (int temp = count; temp < N - 1; temp++)//ð�����򷨽�����ɾ����ǵ���������
					{
						swap = *(data + temp);//��Ȼ��������
						*(data + temp) = *(data + temp + 1);
						*(data + temp + 1) = swap;
					}
					N--;//ѧ��������һ
					Window(0, 0, 80, 34);//�������µ������ڣ��������bug
					return;//��ֵΪȷ����ɾ������˺������ý���
				}
				else//�������ֵΪȡ���Ļ�
				{
					if ((data + count)->delete_mark == true)//��ɾ�����������ض�˵
					{
						(data + count)->delete_mark = false;//��ɾ����Ǹ�Ϊ�٣�ȡ��ɾ��
						N++;//ѧ��������һ
					}
				}
				cout << "\n��ѧ���޸�Ϊ��";
				cin >> (data + count)->number;//¼��ѧ��
				cout << "\n�������޸�Ϊ��";
				cin >> (data + count)->name;//¼������
				(data + count)->average = 0.0;//��ƽ��ֵ����Ϊ0
				for (inside = 0; inside < M; inside++)//�޸Ŀγ̳ɼ�
				{
					do {
						cout << "\n���γ̡�" << *(subject + inside) << "���ĳɼ��޸�Ϊ��";
						cin >> (data + count)->score[inside];//����ɼ�
						cin.clear();//������������ĸ�����crash��������
						cin.ignore(1024, '\n');//������������ĸ�����crash��������
						if ((data + count)->score[inside] < 0)//У��ɼ��Ƿ�С��0
						{
							cout << "  ���ɼ�����С��0��" << endl;
						}
					} while ((data + count)->score[inside] < 0);//���ɼ�С��0�����������һֱѭ��ֱ��������ȷ
					(data + count)->average += (data + count)->score[inside];//�ۼӼ���ɼ��ĺ�
				}
				(data + count)->average /= (double)(M);//�ۼ���ɺ��������ƽ��ֵ
				break;
			case 'n'://����
				do
				{
					Display_cursor();//��ʾ���
					Cls();//��������ʵ����������Ӧ���г�����ѧ�ţ����������ü�
					if (error == false)//���errorΪ��˵��������ȷ
					{
						cout << "\n�����������������";
					}
					else//�����������
					{
						Black_Red();
						cout << "\n  ��������󡿼����������˵�...";//����������ɫΪ��ɫ�����Ϊ��ɫ
						Black_White();
						error = false;//�˴�error��������ֵΪ��
						Pause(false);
						return;
					}
					cin >> input_string;//����һ���ַ������ڼ���
					error = true;
					for (count = 0; count < N_search; count++)//��0�����ѧ��������ʼ����
					{
						if (input_string == (data + count)->name)//������
						{
							error = false;//�Ž�error��Ϊ�٣����ҵ���ƥ����ַ���
							break;
						}
					}
				} while (error != false);//���߿���ֱ���ж�input_string != (data + count)->name
				Cls();//����
				cout << "\n���޸����Ϊ[ " << count + 1 << " ]��ѧ�������� >> " << endl;
				cout << "\n  ԭѧ�ţ�" << (data + count)->number << endl;
				cout << "\n  ԭ������" << (data + count)->name << endl;
				for (inside = 0; inside < M; inside++)//����γ�ԭ�ɼ�
				{
					cout << "\n  �γ̡�" << *(subject + inside) << "����ԭ�ɼ���" << (data + count)->score[inside] << endl;
				}
				if (IDOK == MessageBox(GetConsoleWindow(), TEXT("�Ƿ�ɾ����ѧ�������ݣ�"), TEXT("ɾ������"), MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2))
				{
					//����Windows API�����Ի���Ĭ��ֵΪȡ��
					(data + count)->delete_mark = true;
					for (int temp = count; temp < N - 1; temp++)//ð�����򷨽�����ɾ����ǵ���������
					{
						swap = *(data + temp);//����ѧ������
						*(data + temp) = *(data + temp + 1);
						*(data + temp + 1) = swap;
					}
					N--;//ѧ��������һ
					Window(0, 0, 80, 34);//�������µ������ڣ��������bug
					return;//��ֵΪȷ����ɾ������˺������ý���
				}
				else
				{
					if ((data + count)->delete_mark == true)//��ɾ��
					{
						(data + count)->delete_mark = false;//��ɾ����Ǹ�Ϊ�٣�ȡ��ɾ������
						N++;//ѧ������+1
					}
				}
				cout << "\n��ѧ���޸�Ϊ��";
				cin >> (data + count)->number;//����ѧ��
				cout << "\n�������޸�Ϊ��";
				cin >> (data + count)->name;//��������
				(data + count)->average = 0.0;//ƽ��ֵ��Ȼ��0��ʼ
				for (inside = 0; inside < M; inside++)//�����γ�
				{
					do {
						cout << "\n���γ̡�" << *(subject + inside) << "���ĳɼ��޸�Ϊ��";
						cin >> (data + count)->score[inside];//¼��ɼ��޸�
						cin.clear();//������������ĸ�����crash��������
						cin.ignore(1024, '\n');//������������ĸ�����crash��������
						if ((data + count)->score[inside] < 0)//�ж��Ƿ��������
						{
							cout << "  ���ɼ�����С��0��" << endl;
						}
					} while ((data + count)->score[inside] < 0);//���������󣬾�һֱѭ��
					(data + count)->average += (data + count)->score[inside];//����ɼ����ۼ�ֵ
				}
				(data + count)->average /= (double)(M);//���Կγ���������ѧ����ƽ���ɼ�
				break;
			case 'r':Window(0, 0, 80, 34); return; break;//ֱ�ӽ����������ã�����������
			case 'q':exit(0); break;//q��ֱ���˳�ϵͳ������ֵ0
			default: error = true;//�����������
			}
		} while (input_char != 'o' && input_char != 's' && input_char != 'n');//���ˣ�������������������������������ĸ�������ѭ��

		Window(0, 0, 80, 34);//�ճ�bugԤ�����������ô��ڴ�С
	}
	/*ģ��4::�ɼ��޸Ľ���*/

	/*ģ��5::�ɼ�ͳ��*/
	void Statistics()//�ɼ�ͳ��
	{
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ�ͳ��"));//�����ñ���
		Window(0, 0, 80, 34);//���ô��ڴ�СΪ80��34��
		Black_White();//����ǰ��ɫ������ɫ
		Cls();//����
		Hide_cursor();//���ع��
		double average(0.0);//����ֲ��������������ƽ��ֵ
		int max_count(0), statistic(0);//�������ֵ�����ͳ������
		if (data == NULL || subject == NULL)//�ճ�У��
		{
			cout << "\n����δ¼��ѧ�����ݣ������������˵�..." << endl;
			Pause(false);//��ͣ��Ļ���
			return;
		}
		if (N != 0)//���Ƿ�ȫɾ�ɾ���
		{
			for (inside = 0; inside < M; inside++)//���ڲ㡱Ϊ�ȣ���Ϊ������Կγ�Ϊ���ǣ����ǲ�����ѧ��
			{
				average = 0.0;//ƽ��ֵ��Ҫ��0��ʼ����
				statistic = 0;//ÿ�ſγ̶�Ҫ��0��ʼ����
				for (max_count = 0, count = 0; count < N; count++)//max_countѭ������ȡ���ֵID
				{
					if ((data + max_count)->score[inside] < (data + count)->score[inside])//Ҫ�����˸ұ�max_count�ĳɼ��ߣ��Ǳ�ȻҪ��max_count��ֵ��߳ɼ������
					{
						max_count = count;//ȡ��ÿ�ſγ̳ɼ����ѧ����ID��������ʾ��Ϣ
					}
					average += (data + count)->score[inside];//���ۼӺ�
				}
				average /= (double)(N);//����ÿ�ſγ̵�ƽ���ɼ�������Data�е�average��ͬ��ĪҪ����
				for (count = 0; count < N; count++)//ͳ������������ѭ��
				{
					if ((data + count)->score[inside] > average)//Ҫ����ѧ���ĳɼ���ƽ��ֵ�������
					{
						statistic++;//ͳ�Ƴ���ÿ�ſγ�ƽ���ɼ���ѧ������
					}
				}//������һɫȫ�����
				cout << "\n���γ̡�" << *(subject + inside) << "������߳ɼ���" << (data + max_count)->score[inside] << endl;
				cout << "\n  �����Ϊ[ " << max_count + 1 << " ]��ѧ�� >> " << endl;
				cout << "\n  ѧ�ţ�" << (data + max_count)->number << endl;
				cout << "\n  ������" << (data + max_count)->name << endl;
				for (int temp(0); temp < M; temp++)//ѭ������ɼ�
				{
					cout << "\n  �γ̡�" << *(subject + temp) << "���ĳɼ���" << (data + max_count)->score[inside] << endl;
				}
				cout << "\n  ����ƽ���ɼ���" << (data + max_count)->average << endl;
				cout << "\n���γ̡�" << *(subject + inside) << "����ƽ���ɼ���" << average << endl;
				cout << "\n�������γ̡�" << *(subject + inside) << "��ƽ���ɼ���ѧ��������" << statistic << endl;
				cout << "\n";
			}
		}
		else//�������Ƿ�ȫ��ɾ�ˣ�ȫ��ɾ�˵Ļ�������ʾ��ȫɾ
		{
			cout << "\n��������ȫ�����Ϊɾ��" << endl;
		}
		Pause(false);//��ͣ��Ļ��ʾ�Եȴ���һ������

		Window(0, 0, 80, 34);//Ԥ��bug���������ô��ڴ�С
	}
	/*ģ��5::�ɼ�ͳ�ƽ���*/

	/*ϵͳ�ܹ�::�ɼ�����*/
	void Save()//����ɼ�
	{
		//system("mode con cols=80 lines=32");//�ı��ߣ��ʼ���÷��������Windows API�������ѷ���
		//system("color f0");//�ı���ɫ���ʼ���÷��������Windows API�������ѷ���
		//system("title ѧ���ɼ�����ϵͳ::����");//���±��⣬�ʼ���÷��������Windows API�������ѷ���
		Title(TEXT("ѧ���ɼ�����ϵͳ::�ɼ�����"));//����Title���������ӽ���ı���
		Window(0, 0, 80, 34);//���ô��ڴ�С
		Purple();//��ɫ��������ɫ����
		Cls();//����
		cout << "\n�����ڱ���..." << endl;//��Ϊ��ɫ����
		Black();//��ɫ������ȱʡ��ɫ����
		if (data == NULL || subject == NULL || N == 0)//���ָ��Ϊ�ջ���NΪ0��˵��û��¼��ɼ������Ѿ�ȫ��ɾ��������Windows API������ʾ��Ϣ
		{
			MessageBox(GetConsoleWindow(), TEXT("��δ¼��ѧ�����ݻ�������ȫ��ɾ�����޷����档"), TEXT("����ʧ��"), MB_OK | MB_ICONEXCLAMATION | MB_DEFBUTTON1);
			return;
		}

		time_t now = time(0);//��ȡ��ǰʱ��
		char time[100];//�����ַ����飬���ڴ洢ʱ���ַ���
		ctime_s(time, 100, &now);//��ʱ���ʽ��Ϊ�ַ���
		ofstream outfile;//��������ļ�������
		outfile.open("ѧ���ɼ���Ϣ.txt", ios_base::out | ios_base::app);//�������ʽ���ļ������򴴽���������ԭ�ļ��������������ĩβ
		if (!outfile)//�����ļ�ʧ�ܣ��϶���û������ԱȨ�ޣ��ǻ��˵ã����뵯���Ի�������
		{
			MessageBox(GetConsoleWindow(), TEXT("�����ļ�ʧ�ܣ����Թ���Ա������д˳���"), TEXT("����ʧ��"), MB_OK | MB_ICONHAND | MB_DEFBUTTON1);
		}
		else//����һ��˳��
		{
			outfile << "������ʱ�䡿" << time;//д��
			for (count = 0; count < N; count++)//���ѭ������ѧ�����ݱ���
			{
				outfile << "\n�����Ϊ[ " << count + 1 << " ]��ѧ���� >> " << endl;
				outfile << "\n  ѧ�ţ�" << (data + count)->number << endl;//����ѧ��
				outfile << "\n  ������" << (data + count)->name << endl;//��������
				for (inside = 0; inside < M; inside++)//�ڲ�ѭ�������γ̱���
				{
					outfile << "\n  �γ̡�" << *(subject + inside) << "���ĳɼ���" << (data + count)->score[inside] << endl;//����ɼ�
				}
				outfile << "\n  ƽ���ɼ���" << (data + count)->average << endl;//����ƽ���ɼ�
			}
			outfile << "\n==================================\n" << endl;//��Ϊ�ָ���
			MessageBox(GetConsoleWindow(), TEXT("�������ݳɹ����ļ���Ϊ��Ŀ¼�µġ�ѧ���ɼ���Ϣ.txt��"), TEXT("����ɹ�"), MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);//�����ɹ���Ϣ
			outfile.close();//�ر�����ļ�
		}

		Window(0, 0, 80, 34);//�����ô��ڴ�С
	}
	/*ϵͳ�ܹ�::�ɼ�����*/

	/*ϵͳ�ܹ�::������Ϣ*/
	void About(int argc, char** argv)//���������Ϣ
	{
		//system("mode con cols=80 lines=32");//�ı��ߣ��ʼ���÷��������Windows API�������ѷ���
		//system("color f0");//�ı���ɫ���ʼ���÷��������Windows API�������ѷ���
		//system("title ѧ���ɼ�����ϵͳ::����");//���±��⣬�ʼ���÷��������Windows API�������ѷ���
		Title(TEXT("ѧ���ɼ�����ϵͳ::����"));//����Title���������ӽ���ı���
		Window(0, 0, 80, 34);//���ô��ڴ�С
		do//do-whileѭ������ִ��һ��
		{
			Purple();//��ɫ��������ɫ����
			Cls();//����
			cout << "\n\n\n\t\t\t\t    [ ���� ]" << endl;//��Ϊ��ɫ����
			Black();//��ɫ������ȱʡ��ɫ����
			cout << "\n\n\t\t\t������汾��1.1.99.275" << endl;//�Զ���汾��
			cout << "\n\n\t\t\t�����������" << argc << endl;//���ó���ʱ�����޸�������Ĳ���
			cout << "\n\n\t\t\t������·����" << *argv << endl;//�������·��
			cout << "\n\n\t\t\t�����빤�ߡ�Microsoft Visual Studio" << endl;//�Զ�����빤��
			cout << "\n\n\t\t\t����Ȩ������CaseClosedX@outlook.com" << endl;//��Ȩ��Ϣ
			cout << "\n\n\t\t\t\t��r������������" << endl;
			cout << "\n\n\t\t\t\t��q���˳�ϵͳ" << endl;
			if (error == true)//catch���󣬵��ú���
			{
				Error(true);
			}
			Input_char(true);//�����ַ�
			switch (input_char)//�ж�������ַ�
			{
			case 'r':Window(0, 0, 80, 34); break;//����ѭ����������һ�����������棬�˴�û��ֱ��return;��Ϊ��Ԫ������
			case 'q':exit(0); break;//q��ֱ���˳�ϵͳ������ֵ0
			default: error = true;//�����������
			}
		} while (input_char != 'r');//Ϊr��˺������ý���
		Window(0, 0, 80, 34);//�����ô��ڴ�С
	}
	/*ϵͳ�ܹ�::�ɼ�����&&������Ϣ*/
};
/*===================��װ����ģ���࣬�̳�ϵͳ�ܹ������===================*/


/*ϵͳ�ܹ�::����������*/
int main(int argc, char** argv, char** envp)//����������������Ϊ��ʹ��CMD�������н���ʱ�����������������Ŀ¼��ϵͳ��������
{
	Framework Build;//����ϵͳ�ܹ���
	Modular Function;//���幦��ģ����
	do//do-whileѭ������ִ��һ��
	{
		Build.Title(TEXT("ѧ���ɼ�����ϵͳ::������"));//���ñ��⣬����Build��
		Build.Black();//����ǰ��ɫ������ɫ
		Build.Hide_cursor();//���ع��
		Build.Window(0, 0, 80, 34);//���ô��ڴ�С
		Cls();//����
		//cout << "\033[2J";//Linux�µ��������ʼʹ�ã����ѷ�������������Windows 7������ϵͳ��Windows 10�����°汾Ҳ��Ҫ��������
		Build.Purple();//��ɫ��������ɫ���壬beautiful
		cout << "\n\n\n\t\t\t      [ ��ѡ��ϵͳ������ ]" << endl;//��Ϊ��ɫ���壬��ָ�ȱʡ��ɫ����
		Build.Black();//�ָ�ȱʡ��ɫ
		cout << "\n\n\t\t\t\t��a���ɼ�¼��" << endl;
		cout << "\n\n\t\t\t\t��b���ɼ���ʾ" << endl;
		cout << "\n\n\t\t\t\t��c���ɼ�����" << endl;
		cout << "\n\n\t\t\t\t��d���ɼ��޸�" << endl;
		cout << "\n\n\t\t\t\t��e���ɼ�ͳ��" << endl;
		cout << "\n\n\t\t\t\t��f���ɼ�����" << endl;
		cout << "\n\n\t\t\t\t��q������" << endl;//Ϊ�˲��ƻ���֣����˳�������¼�������
		if (Build.error == true)//catch������󣬵��ú���
		{
			Build.Error(true);//����Ϊ������ר�ò�����������Ͽ�
		}
		Build.Input_char(true);//�����ַ�
		switch (Build.input_char)//�ж�������ַ�
		{
		case 'a':Function.Input();  break;//�ɼ�¼��
		case 'b':Function.Output(); break;//�ɼ���ʾ
		case 'c':Function.Sort(); break;//�ɼ�����
		case 'd':Function.Update(); break;//�ɼ��޸�
		case 'e':Function.Statistics(); break;//�ɼ�ͳ��
		case 'f':Function.Save(); break;//�ɼ�����
		case 'q':Function.About(argc, argv); break;//���ù��ں��������˳����ܣ����������Ϣ�����У�envp߯���ˣ�Ӱ�����ۣ��Ͳ�������
		default: Build.error = true;//����������󣬷���catch error
		}
	} while (1);//��ѭ�����ϳ���ǰ��Build.input_char != 'q'

	return 0;//����ִ����ϣ�����ֵ0
}
/*ϵͳ�ܹ�::���������ý���*/