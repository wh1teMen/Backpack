#include<iostream>
#include <string>
using namespace std;
//Базовый класс растения
class Backpack {
public:
	virtual void in_backpack() = 0;
	virtual  int fetus_picking(int fetus) = 0;
	static int fruit_backpack;
	static int berria_backpack;
};
//класс плоды
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
//класс фрукты
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
//класс ягоды
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
//класс деревья
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
//класс кусты
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
	cout << "\n\nВ Рюкзаке:\nФруктов:" << Backpack::fruit_backpack;
	cout << "\nЯгод: " << Backpack::berria_backpack;
}



int main() {
	system("chcp 1251>nul");
	Tree tree1("дерево 1", 20);
	Tree tree2("дерево 2", 50);
	Bush bush1("куст 1", 90);
	Bush bush2("куст 2", 40);


	cout << "Количество растений: " << Plants::get_count() << endl;
	cout << "Количестов всего фруктов: " << Fetus::fruit_ << endl;
	cout << "Количество всего ягод: " << Fetus::berries_ << endl;
	int n = 10;
	cout << "Осталось фруктов, когда собрали " << n << " штук =  " << Fruits::fetus_picking(n) << endl;
	cout << "Осталось ягод, когда собрали " << n << " штук =  " << Berries::fetus_picking(n) << endl;
	cout << "Общее количество плодов = " << Fetus::all_fetus() << " шт " << endl;

	cout << "\nСбор в рюкзак:\nСобрали с первого дерева 13 фруктов"; tree1.in_backpack(13);
	cout << "\nСобрали с второго дерева  25 фруктов"; tree2.in_backpack(25);
	cout << "\nСобрали с первого куста  11 ягод "; bush1.in_backpack(11);
	cout << "\nСобрали с второго куста  17 ягод "; bush2.in_backpack(17);

	staistic_backpack();

	system("pause>nul");
	return 0;
}