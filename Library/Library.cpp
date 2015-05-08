
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>

using namespace std;

class Library
{
private:
	int isbn;
	string title;
	bool checkedOut;
	string borrowName;
public:

	Library(int i, string t, bool c, string b) : isbn(i), title(t), checkedOut(c), borrowName(b) {}

	int getIsbn()
	{
		return isbn;
	}
	string getTitle()
	{
		return title;
	}
	bool getCheckedOut()
	{
		return checkedOut;
	}
	string getBorrowName()
	{
		return borrowName;
	}

	void setIsbn(int i)
	{
		isbn = i;
	}
	void setTitle(string s)
	{
		title = s;
	}
	void setCheckedOut(bool b)
	{
		checkedOut = b;
	}
	void setBorrowName(string s)
	{
		borrowName = s;
	}


	virtual void checkOut(string name) = 0;
	virtual void to_string() = 0;
	virtual void addWeek() = 0;
	
	virtual ~Library() {}
};



class Reading : public Library
{
public:
	Reading(int i, string t, bool c, string b) : Library(i, t, c, b) {}
	

	virtual void checkOut(string name) = 0;
	virtual void to_string() = 0;
	virtual void addWeek() = 0;
	virtual void setFine(double x) = 0;
};

class Book : public Reading
{
private:
	int weeks = 0;
	double fine_ = 0.1;

public:
	Book(int i, string t, bool c = false, string b = "") : Reading(i, t, c, b) {}

	void addWeek()
	{
		++weeks;
		if (weeks >= 3)
			cout << "your book is late, your getting charged " << fine_ << endl;
		else
			cout << "not late yet, but watch out" << endl;
	}

	void setFine(double x)
	{
		fine_ = x;
	}
	
	void lost()
	{
		cout << "your book is lose, your getting charged " << (fine_ * 30) << endl;
	}
	
	void checkOut(string name)
	{
		setCheckedOut(true);
		setBorrowName(name);
	}
	
	void to_string()
	{
		if (getCheckedOut())
			cout << "This is a book with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << "\nchecked out by:" << getBorrowName() << endl;
		else if (!getCheckedOut())
			cout << "This is a book with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << endl;
	}

};

class eBook : public Reading
{
private:
	int weeks = 0;
	double fine_ = 0;

public:
	eBook(int i, string t, bool c = false, string b = "") : Reading(i, t, c, b) {}

	void addWeek()
	{
		++weeks;
		if (weeks >= 3)
			cout << "your ebook is late, so we're deleteing it " << endl;
		else
			cout << "not late yet, but watch out" << endl;
	}

	void lost()
	{
		cout << "you can lose a ebook, idiot "<< endl;
	}
	
	void setFine(double x)
	{
		fine_ = x;
	}

	void checkOut(string name)
	{
		setCheckedOut(true);
		setBorrowName(name);
	}

	void to_string()
	{
		if (getCheckedOut())
			cout << "This is a ebook with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << "\nchecked out by:" << getBorrowName() << endl;
		else if (!getCheckedOut())
			cout << "This is a ebook with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << endl;
	}

};


class Video : public Library
{
public:
	Video(int i, string t, bool c, string b) : Library(i, t, c, b) {}


	virtual void checkOut(string name) = 0;
	virtual void to_string() = 0;
	virtual void addWeek() = 0;
	virtual void setFine(double x) = 0;
};

class DVD : public Video
{
private:
	int weeks = 0;
	 double fine_ = 1.0;

public:
	DVD(int i, string t, bool c = false, string b = "") : Video(i, t, c, b) {}

	void addWeek()
	{
		++weeks;
		if (weeks >= 3)
			cout << "your DVD is late, your getting charged " << fine_ << endl;
		else
			cout << "not late yet, but watch out" << endl;
	}

	void lost()
	{
		cout << "your DVD is lose, your getting charged " << (fine_ * 30) << endl;
	}

	void setFine(double x)
	{
		fine_ = x;
	}

	void checkOut(string name)
	{
		setCheckedOut(true);
		setBorrowName(name);
	}

	void to_string()
	{
		if (getCheckedOut())
			cout << "This is a DVD with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << "\nchecked out by:" << getBorrowName() << endl;
		else if (!getCheckedOut())
			cout << "This is a DVD with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << endl;
	}
};

class BlueRay : public Video
{
private:
	int weeks = 0;
	double fine_ = 1.5;

public:
	BlueRay(int i, string t, bool c = false, string b = "") : Video(i, t, c, b) {}

	void addWeek()
	{
		++weeks;
		if (weeks >= 3)
			cout << "your BlueRay is late, your getting charged " << fine_ << endl;
		else
			cout << "not late yet, but watch out" << endl;
	}

	void lost()
	{
		cout << "your BlueRay is lose, your getting charged " << (fine_ * 30) << endl;
	}

	void setFine(double x)
	{
		fine_ = x;
	}

	void checkOut(string name)
	{
		setCheckedOut(true);
		setBorrowName(name);
	}

	void to_string()
	{
		if (getCheckedOut())
			cout << "This is a BlueRay with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << "\nchecked out by:" << getBorrowName() << endl;
		else if (!getCheckedOut())
			cout << "This is a BlueRay with the ISBN of:" << getIsbn() << "\nAnd Title of:" << getTitle() << endl;
	}
};



int main()
{
	



	vector<shared_ptr<Library>> library;

	srand(unsigned(time(NULL)));

	int ran;

	for (unsigned i = 1; i < 31; ++i)
	{
		ran = rand() % 5;
		if (ran == 1)
			library.push_back(shared_ptr<Library>(new Book(i, "Text Book")));
		else if (ran == 2)
			library.push_back(shared_ptr<Library>(new eBook(i, "Novels")));
		else if (ran == 3)
			library.push_back(shared_ptr<Library>(new DVD(i, "Zombie Land")));
		else if (ran == 4)
			library.push_back(shared_ptr<Library>(new BlueRay(i, "High Def")));
	}
	cout << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
	cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;

	for (auto x : library)
	{
		x->to_string();
		cout << endl;

		x->checkOut("John");
	}

	cout << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
	cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;

	for (auto x : library)
	{
		x->to_string();
		cout << endl;
	}

	cout << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\" << endl;
	cout << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/" << endl;
	
	for (auto x : library)
	{
		x->addWeek();
		cout << endl;
		x->addWeek();
		cout << endl;
		x->addWeek();
		cout << endl;
	}

}






