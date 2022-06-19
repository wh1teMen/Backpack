#include<iostream>
#include <string>
using namespace std;
//������� ����� ��������
class Backpack {
public:
	virtual void in_backpack() = 0;
	virtual  int fetus_picking(int fetus) = 0;
	static int fruit_backpack;
	static int berria_backpack;
};
//����� �����
class Fetus {
public:
	static int fruit_;
	static int berries_;
	Fetus() {}
	virtual~Fetus() {}
	static int all_fetus() {
		return fruit_ + berries_;
	}
	void staistic_backpack() {
		
	}

};
//����� ������
class Fruits :public Fetus {
public:

	Fruits() {}

	virtual~Fruits() {}
	static int fetus_picking(int fetus) {
		fruit_ -= fetus;
		return fruit_;
	}
	static int get_fruits() {
		return fruit_;
	}
};
//����� �����
class Berries :public Fetus {
public:
	Berries() {}
	virtual~Berries() {}
	static int fetus_picking(int fetus) {
		berries_ -= fetus;
		return berries_;
	}

};
int Fetus::fruit_ = 0;
int Fetus::berries_ = 0;
class Plants {
public:
	Plants() {
		count_++;
	}
	Plants(string name, int value) :Plants() {
		name_ = name;
		Fetus::fruit_ += value;
	}

	virtual~Plants() {
		count_--;
	}
	
	void set_name(string name) {
		this->name_ = name;
	}
	string get_name() {
		return name_;
	}
	static int get_count() {
		return count_;
	}
	
private:
	string name_;
	static int count_;
};
//����� �������
class Tree :public Plants {
public:
	Tree() {}
	Tree(string name, int value) : Plants(name, value) {}
	virtual~Tree() {}
	 void in_backpack(int num) {
		Fetus::fruit_ -= num;
		Backpack::fruit_backpack += num;
	}
	

};
//����� �����
class Bush :public Plants {
public:
	Bush() {}
	Bush(string name, int value) {
		Plants::set_name(name);
		Fetus::berries_ += value;
	}
	virtual~Bush() {}
	void in_backpack(int num) {
		Fetus::berries_ -= num;
		Backpack::berria_backpack += num;
	}
};
int Plants::count_ = 0;
int Backpack::fruit_backpack = 0;
int	Backpack::berria_backpack = 0;
void staistic_backpack() {
	cout << "\n\n� �������:\n�������:" << Backpack::fruit_backpack;
	cout << "\n����: " << Backpack::berria_backpack;
}



int main() {
	system("chcp 1251>nul");
	Tree tree1("������ 1", 20);
	Tree tree2("������ 2", 50);
	Bush bush1("���� 1", 90);
	Bush bush2("���� 2", 40);


	cout << "���������� ��������: " << Plants::get_count() << endl;
	cout << "���������� ����� �������: " << Fetus::fruit_ << endl;
	cout << "���������� ����� ����: " << Fetus::berries_ << endl;
	int n = 10;
	cout << "�������� �������, ����� ������� " << n << " ���� =  " << Fruits::fetus_picking(n) << endl;
	cout << "�������� ����, ����� ������� " << n << " ���� =  " << Berries::fetus_picking(n) << endl;
	cout << "����� ���������� ������ = " << Fetus::all_fetus() << " �� " << endl;

	cout << "\n���� � ������:\n������� � ������� ������ 13 �������"; tree1.in_backpack(13);
	cout << "\n������� � ������� ������  25 �������"; tree2.in_backpack(25);
	cout << "\n������� � ������� �����  11 ���� "; bush1.in_backpack(11);
	cout << "\n������� � ������� �����  17 ���� "; bush2.in_backpack(17);

	staistic_backpack();

	system("pause>nul");
	return 0;
}