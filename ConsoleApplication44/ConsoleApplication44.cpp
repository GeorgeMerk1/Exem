#include <iostream>
#include <string>
#include "io.h"
#include <fstream>
using namespace std;

//login paswor score

class Question
{
private:
	string question;
	int answer;
public:

	bool AddQuestion()
	{

		string useranswer;
		cout << question << endl;
		cout << "Введите ответ: ";
		cin >> useranswer;
		for (int i = 0; i < useranswer.size(); i++)
		{
			if (!isdigit(useranswer[i]))
			{

				if (i == 0 and useranswer[i] == '-')
				{
					continue;
				}
				return false;
			}

		}
		if (to_string(answer) == useranswer)
		{
			return true;
		}
		else {
			return false;
		}
	}
	void SetQuestion(string str)
	{
		question = str;
	}

	void SetAnswer(int answer)
	{
		this->answer = answer;
	}
};
class Test : public Question
{
private:
	Question test[4];
	int results = 0;
public:
	void SetTest()
	{

		fstream file("P:\\Студенты\\П22\\C++\\ООП\\Вопросы.txt");
		string str;
		for (int i = 0; i < 4; i++)
		{
			getline(file, str);
			test[i].SetQuestion(str);
		}
		file.close();

		fstream file2("P:\\Студенты\\П22\\C++\\ООП\\Ответы.txt");
		string str2;
		for (int i = 0; i < 4; i++)
		{
			getline(file2, str2);
			test[i].SetAnswer(atoi(str2.c_str()));
		}
		file2.close();
	}

	double Pass()
	{
		ofstream file("P:\\Студенты\\П22\\C++\\ООП\\Answers.txt");
		for (int i = 0; i < 4; i++)
		{
			results += test[i].AddQuestion();
		}
		file << results / 4 * 100;
		file.close();
		return results / 4 * 100;
	}
};

class User :Test
{
	string login;
	string password;
	double scors[1024];
	int scorsAmount;
public:
	User()
	{
		scorsAmount = 0;
		SetTest();
	}



	void registration()
	{

		string arr[1488];
		fstream file;
		file.open("P:\\Студенты\\П22\\C++\\ООП\\Users.txt");
		int counterLines = 0;
		for (int i = 0; getline(file, arr[i]); i++)
		{
			counterLines++;
		}
		file.close();

		cout << "Введите логин: ";
		cin >> login;
		for (int i = 0; i < counterLines; i += 2)
		{
			if (login != arr[i])
			{
				cout << "Введите пароль: ";
				cin >> password;
			}
			else
			{
				break;
			}
		}
	}
			
		void  Enter()
		{

			string arr[1488];
			fstream file;
			file.open("P:\\Студенты\\П22\\C++\\ООП\\Users.txt");
			int counterLines = 0;
			for (int i = 0; getline(file, arr[i]); i++)
			{
				counterLines++;
			}
			file.close();

			cout << "Введите логин: ";
			cin >> login;
			for (int i = 1; i < counterLines; i += 2)
			{
				if (login == arr[i])
				{
					while (arr[i] != password)
					{
						cout << "Пароль нерпавильный, попробуйте еще раз:";
						cin >> password;
						cout << endl;

					}
				}
				else
				{
					break;
				}
			}
		}
		
		void SaveUser()
		{


			ofstream file;
			file.open("P:\\Студенты\\П22\\C++\\ООП\\Users.txt");
			for (int i = 0; i < 1; i++)
			{
				file << login << endl;
			}
			for (int i = 0; i < 1; i++)
			{
				file << password << endl;
			}
		}

		void PassTest()
		{
			scors[scorsAmount] = Pass();
			scorsAmount++;

		}

		void ShowResults()
		{
			for (int i = 0; i < 1; i++)
			{
				cout << scors[i];
			}
			cout << '%';
		}
};

		int main()
		{
			setlocale(LC_ALL, "RU");
			User user;
			cout << "Введите 1, если вы хотите создать пользователя; Введите 2, если вы хоите войти;";
			cout << endl;
			int x;
			cin >> x;
				/*if (x != 1 or x != 2)
				{
					cout << "Введите цифру еще раз";

				}*/
			 
			switch (x)
			{
			case 1:
				user.registration();
				;

			case 2:
				user.Enter();
				;
				user.SaveUser();
			}

			user.PassTest();
			user.ShowResults();
		}


