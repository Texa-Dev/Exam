#include <iostream>
#include <nlohmann/json.hpp>
#include <stdio.h>
#include <time.h>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#pragma warning(disable:4996)
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


using namespace std;
using namespace nlohmann;
class Plan
{
public:
	string time;
	string content;
	string type;



};
bool Data() {
	time_t     now;
	struct tm* ts;
	char       buf[80];


	time(&now);


	ts = localtime(&now);
	int year, month, day, hour, minute, sec;

	cout << "������� ���: ";
	cin >> year;
	if (year < (ts->tm_year + 1900)) {
		cout << "���� ��� ��� ������" << endl;
		Data();
	}
	else {
		cout << "������� �����: ";
		cin >> month;
		if (year == (ts->tm_year + 1900) && month < (ts->tm_mon)) {
			cout << "���� ����� ��� ������" << endl;
			Data();

		}
		else if (year >= (ts->tm_year + 1900)) {
			cout << "������� ����: ";
			cin >> day;
			if (day > 31 || day < 0) {
				cout << "�� ���������� ����" << endl;
				Data();

			}
			else {
				cout << "������� ����: ";
				cin >> hour;
				if (hour > 24 || hour < 0) {
					cout << "�� ���������� �����" << endl;
					Data();

				}
				else {
					cout << "������� ������: ";
					cin >> minute;
					if (minute < 0 || minute > 59) {
						cout << "�� ���������� �����" << endl;
						Data();

					}
					else {
						cout << "������� �������:";
						cin >> sec;
						if (sec < 0 || sec > 59) {
							cout << "�� ���������� �����" << endl;
							Data();

						}
						else {
							cout << "�� ��������� ������� �����" << endl;
						}
					}

				}
			}
		}
		else if (year == (ts->tm_year + 1900) && month == (ts->tm_mon) && month > 0 && month <= 12) {
			cout << "������� ����: ";
			cin >> day;
			if (day < ts->tm_mday) {
				cout << "�� ���������� ����" << endl;
				Data();
			}
			else if (day >= ts->tm_mday && day <= 31) {
				cout << "������� ����: ";
				cin >> hour;
				if (hour < ts->tm_hour) {
					cout << "�� ���������� ���" << endl;
					Data();
				}
				else if (hour >= ts->tm_hour && hour <= 23) {
					cout << "������� ������: ";
					cin >> minute;
					if (minute < ts->tm_min) {
						cout << "�� ���������� ������" << endl;
						Data();
					}
					else if (minute > ts->tm_min && minute <= 59) {
						cout << "������� �������: ";
						cin >> sec;
						if (sec < 0 || sec >= 59) {
							cout << "�� ���������� �������" << endl;
							Data();
						}
					}

				}

			}
		}
		else if (year == (ts->tm_year + 1900) && month > (ts->tm_mon) && month > 0 && month <= 12) {
			cout << "������� ����: ";
			cin >> day;
			if (day < 0 || day > 31) {
				cout << "�� ���������� ����" << endl;
				Data();
			}
			else {
				cout << "������� ����: ";
				cin >> hour;
				if (hour < 0 || hour > 23) {
					cout << "�� ���������� ���" << endl;
					Data();

				}
				else {
					cout << "������� ������: ";
					cin >> minute;
					if (minute < 0 || minute > 59) {
						cout << "�� ���������� ������" << endl;
						Data();
					}
					else {
						cout << "������� �������: ";
						cin >> sec;
						if (sec < 0 || sec > 59) {
							cout << "�� ���������� c������" << endl;
							Data();
						}
					}
				}

			}

		}

	}
	if (month < 10) { // �����
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (hour < 10) { // ����
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (minute < 10) { // ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (sec < 10) { // �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10) { // ���
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and day < 10) { // ����� ���
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and hour < 10) { // ����� ����
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 && minute < 10) { // ����� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and sec < 10) { // ����� �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 and hour < 10) { // ���� ���� 
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 and minute < 10) { // ���� ������ 
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 and sec < 10) { // ���� �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (hour < 10 and minute < 10) { // ���� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (hour < 10 and sec < 10) { // ���� �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (minute < 10 and sec < 10) { // ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (month < 10 and day < 10 and hour < 10) { // ����� ���� ���� 
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << "0" << hour << ":" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 and day < 10 and minute < 10) { // ����� ���� ������ 
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 && day < 10 and sec < 10) { // ����� ���� �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (month < 10 && hour < 10 and minute < 10) { // ����� ���� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (month < 10 && hour < 10 and sec < 10) { // ����� ���� ������� 
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (month < 10 && minute < 10 and sec < 10) { // ����� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && hour < 10 and minute < 10) { // ���� ���� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 && hour < 10 and sec < 10) { // ���� ���� ��������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and sec < 10) { // ���� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and sec < 10) { // ���� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // ����� ���� ���� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // ����� ���� ���� �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << "0" << hour << ":" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // ����� ���� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // ����� ���� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && minute < 10 and hour < 10 && minute < 10) { // ���� ���� ������ �������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << "0" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day < 10 && month < 10 and hour < 10 && minute < 10 && sec < 10) { // ���� ���� ������ ������� ������
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << "0" << month << "-" << "0" << day << "T" << "0" << hour << ":" << "0" << minute << ":" << "0" << sec << endl;
		}
	}
	if (day >= 10 && month >= 10 and hour >= 10 && minute >= 10 && sec >= 10) {
		std::ofstream out;
		out.open("temp.txt");
		if (out.is_open())
		{
			out << year << "-" << month << "-" << day << "T" << hour << ":" << minute << ":" << sec << endl;
		}
	}







	return true;
}
bool add() {
	string type, content, time;

	cout << "�������� ��� ��������:\n1) ��������� ����������\n2) �������� ����������e\n4)���������� ���������" << endl;
	cout << "��� �����: ";
	int key = 0;
	cin >> key;
	if (key == 1) {
		type = "Load";
		cout << "������� ������ ���� � ������������ �����: ";
		cin >> content;
		cout << "������� ���� � ������� [2022-07-08 18:30:25]:";
		cout << endl;
		Data();

	}
	else if (key == 2) {
		type = "Message";
		cout << "������� ����� �����������: ";
		cin >> content;
		cout << "������� ���� � ������� [2022-07-08 18:30:25]:";
		cout << endl;
		Data();
	}
	else if (key == 4) {
		exit;
	}
	else {
		system("cls");
		add();
	}
	std::string line;
	string line2;
	std::ifstream in("temp.txt"); // �������� ���� ��� ������
	if (in.is_open())
	{
		while (getline(in, line))
		{
			std::cout << line << std::endl;
			line2 = line;
		}
	}

	Plan plan;
	plan.time = line2;
	plan.content = content;
	plan.type = type;

	json object;

	object["Content"] = plan.content;
	object["Type"] = plan.type;
	object["Time"] = plan.time;






	string j = object.dump();
	cout << j << endl;
	ofstream o("..\\output.json", ios::app);
	o << j << endl;
	o.close();

	return true;
}
bool see() {
	ifstream file("..\\output.json"); // ���� �� �������� ������ (��� ������ ���� ����� ��������� �� �������)
	string jsonString;
	int i = 0;
	while (getline(file, jsonString)) { // ���� �� ��������� ����� ����� ������ ��������� ������ � ���������� (s)
		json object = json::parse(jsonString);
		string type = object["Type"].get<string>();
		string content = object["Content"].get<string>();
		string time = object["Time"].get<string>();



		i++;
		cout << "������ " << i << ":" << "���: " << type << " ����������: " << content << " ����� ����������: " << time << ";" << endl;

	}

	file.close();
	return true;
}
bool deleted() {
	see();
	vector<string> vec;
	int dell;
	cout << "������� ����� ������ ��� �������� : ";
	cin >> dell;
	dell = dell - 1;
	ifstream file("..\\output.json");
	if (file.is_open())
	{
		string str;
		while (getline(file, str))
			vec.push_back(str);
		file.close();
		if (vec.size() < dell)
			return false;
		vec.erase(vec.begin() + dell);
		ofstream outfile("..\\output.json");
		if (outfile.is_open())
		{
			copy(vec.begin(), vec.end(),
				ostream_iterator<string>(outfile, "\n"));
			outfile.close();
			return true;
		}
		return false;
	}
	return false;
}

bool settings() {
	cout << "�� ����� � ���������. ��������� ���������:\n1) ���������� ��� ������������ ������\n2) ������� ������\n3) �������� ������\n0)�������" << endl;
	int x;
	int y;
	cin >> x;
	if (x == 1) {

		see();

		cout << "��� ����������� � ��������� ������� 1: ";
		cin >> y;
		if (y == 1) {
			settings();

		}
	}
	else if (x == 2) {
		system("cls");
		deleted();

		cout << "��� ����������� � ��������� ������� 1: ";
		cin >> y;
		if (y == 1) {
			system("cls");
			settings();

		}
	}
	else if (x == 3) {
		system("cls");
		add();

		cout << "��� ����������� � ��������� ������� 1: ";
		cin >> y;
		if (y == 1) {
			settings();

		}

	}
	else if (x == 0) {
		exit;
	}
	else {
		system("cls");
		settings();
	}


	return true;
}
bool menu() {
	cout << "����� ���������� � ����� ��� 2017. C����� ��������� ��������: \n1) ���������� ������\n2) ��������� ������� �����\n3) ������� ����������" << endl;
	int x;
	int y;
	cin >> x;
	if (x == 1) {
		system("cls");
		add();

		cout << "��� ����������� � ���� ������� 1: ";
		int x;
		cin >> x;
		if (x == 1) {
			system("cls");
			menu();

		}
	}
	else if (x == 2) {
		system("cls");
		settings();

		cout << "��� ����������� � ���� ������� 1: ";
		cin >> y;
		if (y == 1) {
			system("cls");
			menu();

		}
	}
	else if (x == 3) {
		exit;

	}
	else {
		system("cls");
		menu();
	}


	return true;
}
int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	menu();
}
