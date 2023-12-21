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
	string answer;
public:

	bool AddQuestion()
	{

		string useranswer;
		cout << question<<endl;
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
		for (int i = 0; i < 4; i++)
		{
			if (useranswer != answer)
			{
				return false;
			}
			else
			{
				return true;
			}


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
			for (int i = 0; i < 4; i++)
			{
				results += test[i].AddQuestion();
			}
			return results / 4 * 100;
		}
	};
	
class User:Test
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


	void AddUser()
	{
		cout << "Добро пожаловать" << endl;

		string arr[1488];
		fstream file("P:\\Студенты\\П22\\C++\\ООП\\Users.txt");
		int counterLines = 0;
		for (int i = 0; getline(file, arr[i]); i++)
		{
			counterLines++;
		}
		file.close();

		bool Y = true;
		
		do {
			cout << "Введите логин: ";
			cin >> login;
			for (int i = 0; i < counterLines; i += 2)
			{
				if (login == arr[i])
				{
					Y = false;
					break;
				}
				Y = true;
			}
			if (!Y)
			{
				cout << "Имя пользователя занято, попробуте еще раз:";
			}
		} while (!Y);

		cout << "Введите пароль: ";
		cin >> password;
		SaveUser();


	}



	void SaveUser()
	{
		
	
		ofstream file;
			file.open("P:\\Студенты\\П22\\C++\\ООП\\Users.txt");
			for (int i = 0; i < login.size(); i++)
			{
				file << login<<endl;
			}
		for (int i = 0; i < password.size(); i++)
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
		cout << scors;
	}
	
};

int main()
{
	setlocale(LC_ALL, "RU");

	User user;
	user.AddUser();
	user.PassTest();
	//user.ShowResults();
}


