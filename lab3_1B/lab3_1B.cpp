// lab3_1B.cpp

#include <iostream> 
#include <iomanip> 
#include <string> 
#include <Windows.h> 

using namespace std;

enum Spec { KN, In, ME, FI, TN };
string specStr[] = { "����'����� �����", "�����������", "���������� � ��������", "Գ���� �� �����������", "������� ��������" };
struct Student {
	string lname;
	int course;
	int physics;
	int math;
	Spec spec;
	union {
		int program;
		int method;
		int pedag;

	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
double AverageGrade(Student s);
double PercentOfStrudents(Student* s, const int N);
void LastNamesOfNotThree(Student* s, const int N);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	Student* s;

	cout << "������ �i���i��� �������i�: "; cin >> N;
	s = new Student[N];

	Create(s, N);
	Print(s, N);

	LastNamesOfNotThree(s, N);
	cout << "- �i������ �������i� i� ������i� ����� �i����� �� 4.5: " << PercentOfStrudents(s, N) << endl;

	system("pause");
	return 0;
}
void Create(Student* s, const int N) {
	int spec;
	for (int i = 0; i < N; i++) {
		cout << "������� #" << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "-�������: ";
		getline(cin, s[i].lname);
		cout << "-����: "; cin >> s[i].course;
		cout << "-������������ (0 - ��, 1 - I�, 2 - ��, 3 - �I, 4 - ��): ";
		cin >> spec;
		s[i].spec = (Spec)spec;
		cout << "-��i��� � ������: "; cin >> s[i].physics;
		cout << "-��i��� � ����������: "; cin >> s[i].math;
		switch (s[i].spec) {
		case 0:
			cout << "-��i��� � �������������: "; cin >> s[i].program; break;
		case 1:
			cout << "-��i��� � ��������� �����i�: "; cin >> s[i].method; break;
		case 2:
		case 3:
		case 4:
			cout << "-��i��� � �������i��: "; cin >> s[i].pedag; break;
		default:
			cout << "����� ������������!"; break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N) {
	cout << "----------------------------------------------------------------------------------\n";
	cout << "| � | ������� | ���� |     ������������     | Գ���� | ���������� | ������������� | ���. ������ | ��������� |\n";
	cout << "----------------------------------------------------------------------------------\n";
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].lname
			<< "| " << setw(5) << left << s[i].course
			<< "| " << setw(22) << specStr[s[i].spec]
			<< "| " << setw(7) << left << s[i].physics
			<< "| " << setw(11) << left << s[i].math;

		switch (s[i].spec) {
		case 0:
			cout << "| " << setw(13) << left << s[i].program << "|\n"; break;
		case 1:
			cout << "| " << "      -      | "
				<< setw(11) << left << s[i].method << "|\n"; break;
		case 2:
		case 3:
		case 4:
			cout << "| " << "      -      | " << "     -     | "
				<< setw(11) << left << s[i].pedag << "|\n"; break;
		}
	}
	cout << "----------------------------------------------------------------------------------\n\n";
}
double AverageGrade(Student s) {
	double sum = s.math + s.physics;
	switch (s.spec) {
	case 0: sum += s.program; break;
	case 1: sum += s.method; break;
	case 2:
	case 3:
	case 4: sum += s.pedag; break;
	}
	return sum / 3.;
}
double PercentOfStrudents(Student* s, const int N) {
	int counter = 0;
	for (int i = 0; i < N; i++) {
		if (AverageGrade(s[i]) > 4.5)
			counter++;
	}
	return round((1.0 * counter / N) * 10000.0) / 100.0;
}
void LastNamesOfNotThree(Student* s, const int N) {
	cout << "- ������� ��������, ��i ������� ��� ��i���:" << endl;
	for (int i = 0; i < N; i++) {
		int thirdSubject;
		switch (s[i].spec) {
		case 0: thirdSubject = s[i].program; break;
		case 1: thirdSubject = s[i].method; break;
		case 2:
		case 3:
		case 4: thirdSubject = s[i].pedag; break;
		}
		if (s[i].math > 3 && s[i].physics > 3 && thirdSubject > 3) {
			cout << s[i].lname << endl;
		}
	}
	cout << endl;
}