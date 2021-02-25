#include<iostream>
#include <fstream>
#include<string>
#include<string.h>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

using namespace std;
//CLASE - FAZA 1
class Advertising {
private:
	//ar fi trebuit sa folosesc camelCase pentru variabile
	string productname;
	int wayofadvno;
	string* wayofadv;
	float advprice[100];
	int employeesno;
	const float budget;
	//variabilele statice trebuie denumite cu prefixul s_
	static int advproductsno;
public:
	//constructor nr.1
	Advertising(string productname1, int wayofadvno1, string* wayofadv1, float advprice1[100], int employeesno1, float budget1) :budget(budget1) {
		this->productname = productname1;
		this->wayofadvno = wayofadvno1;
		this->wayofadv = new string[this->wayofadvno];
		for (int i = 0; i < this->wayofadvno; i++) {
			this->wayofadv[i] = wayofadv1[i];
			this->advprice[i] = advprice1[i];
		}
		this->employeesno = employeesno1;
		this->advproductsno++;
	}

	//afisare pentru constructor nr.1
	void afisare1() {
		cout << "Numele produsului promovat este: " << this->productname << endl;
		cout << "Numarul de modalitati prin care este promovat este:" << this->wayofadvno << endl;
		cout << "Modalitatile prin care este promovat si costurile acestora sunt: " << endl;
		for (int i = 0; i < this->wayofadvno; i++) {
			cout << this->wayofadv[i] << " " << this->advprice[i] << endl;
		}
		cout << "Numarul de angjati in departamentul de promovare este:" << this->employeesno << endl;
		cout << "Bugetul disponibil este: " << this->budget << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//nu ar fi trebuit sa folosesc comentarii - codul trebuie sa fie self explanatory
	//constructor nr.2
	Advertising(string productname1, int wayofadvno1, string* wayofadv1, float budget1) : budget(budget1) {
		this->productname = productname1;
		this->wayofadvno = wayofadvno1;
		this->wayofadv = new string[this->wayofadvno];
		for (int i = 0; i < this->wayofadvno; i++) {
			this->wayofadv[i] = wayofadv1[i];
		}
	}

	//afisare pentru constructor nr.2
	void afisare2() {
		cout << "Numele produsului promovat este: " << this->productname << endl;
		cout << "Numarul de modalitati prin care este promovat este:" << this->wayofadvno << endl;
		cout << "Modalitatile prin care este promovat: " << endl;
		for (int i = 0; i < this->wayofadvno; i++) {
			cout << this->wayofadv[i] << endl;
		}
		cout << "Bugetul disponibil este: " << this->budget << endl;
		cout << "-------------------------------------------------------------" << endl;

	}

	//constructor de copiere
	Advertising(const Advertising& product) : budget(product.budget) {
		this->productname = product.productname;
		this->wayofadvno = product.wayofadvno;
		this->wayofadv = new string[this->wayofadvno];
		for (int i = 0; i < this->wayofadvno; i++) {
			this->wayofadv[i] = product.wayofadv[i];
			this->advprice[i] = product.advprice[i];
		}
		this->employeesno = product.employeesno;
		this->advproductsno++;
	}

	//destructor
	~Advertising() {
		if (this->wayofadv != NULL) {
			delete[] this->wayofadv;
		}
		this->advproductsno--;
		cout << "Apel destructor clasa Advertising" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}


	//cresterea numarului de angajati cu 2
	void employeesnoadd() {
		this->employeesno = this->employeesno + 2;
	}

	//cost total de promovare al unui produs
	float cost() {
		float x = 0;
		for (int i = 0; i < this->wayofadvno; i++) {
			x = x + this->advprice[i];
		}
		return x;
	}

	//getter-ul trebuia denumit productname(), nu getproductname()
	//getter atribut productname
	string getproductname() {
		return this->productname;
	}
	//setter atribut productname
	void setproductname(string name) {
		this->productname = name;
	}

	//getter atribut wayofadvno
	int getwayofadvno() {
		return this->wayofadvno;
	}

	//getter atribut wayofadv
	string* getwayofadv() {
		return this->wayofadv;
	}
	//setter atribut wayofadv
	void setwayofadv(string *way, int no) {
		if (this->wayofadv != NULL) {
			delete[] this->wayofadv;
		}
		this->wayofadvno = no;
		this->wayofadv = new string[this->wayofadvno];
		for (int i = 0; i < this->wayofadvno; i++) {
			this->wayofadv[i] = way[i];
		}
	}

	//getter pentru un element din atributul advprice
	float getadvprice(int i) {
		return this->advprice[i];
	}
	//setter atribut advprice
	void setadvprice(float price[100], int no) {
		this->wayofadvno = no;
		for (int i = 0; i < this->wayofadvno; i++) {
			this->advprice[i] = price[i];
		}
	}

	// getter atribut employeesno
	int getemployeesno() {
		return this->employeesno;
	}
	//setter atribut employeesno
	void setemployeesno(int no) {
		this->employeesno = no;
	}

	//getter atribut constant budget
	int getbudget() {
		return this->budget;
	}

	//getter atribut static advproductsno
	static int getadvproductsno() {
		return advproductsno;
	}
	//setter atribut static advproductsno
	static void setadvproductsno(int no) {
		Advertising::advproductsno = no;
	}

	//supraincarcare operator ==
	bool operator == (Advertising a) {
		if (this->productname == a.productname && this->wayofadvno == a.wayofadvno)
			return true;
		return false;
	}

	//supraincarcare operator <
	bool operator < (Advertising a) {
		if (this->productname != a.productname && this->wayofadvno < a.wayofadvno) {
			return true;
		}
		return false;
	}

	//supraincarcare operator =
	Advertising& operator = (const Advertising& a) {
		this->productname = a.productname;
		this->wayofadvno = a.wayofadvno;
		this->wayofadv = new string[this->wayofadvno];
		for (int i = 0; i < this->wayofadvno; i++) {
			this->wayofadv[i] = a.wayofadv[i];
			this->advprice[i] = a.advprice[i];
		}
		this->employeesno = a.employeesno;
		return *this;
	}


	//supraincarcarea operatorului <<
	friend ostream& operator << (ostream& out, const Advertising& a) {
		out << "Numele produsului este: " << a.productname << endl;
		out << "Numarul de modalitati prin care este prmovat produsul este: " << a.wayofadvno << endl;
		out << "Modalitatile de promovare si costurile acestora sunt: " << endl;
		for (int i = 0; i < a.wayofadvno; i++) {
			out << a.wayofadv[i] << " " << a.advprice[i] << endl;
		}
		out << "Numarul de angajati in departamentul de promovare este: " << a.employeesno << endl;
		out << "Bugetul alocat promovarii produsului este: " << a.budget << endl;
		out << "Numarul de produse promovat este: " << advproductsno << endl;
		return out;
	}

	//supraincarcarea operatorului >>
	friend istream& operator >> (istream& in, Advertising& a) {
		cout << "Introduceti numele produsului: ";
		in >> a.productname;
		cout << "Introduceti numarul de modalitati prin care este promovat produsul: ";
		in >> a.wayofadvno;
		if (a.wayofadv != NULL) {
			delete[] a.wayofadv;
		}
		a.wayofadv = new string[a.wayofadvno];
		for (int i = 0; i < a.wayofadvno; i++) {
			cout << "Introduceti modalitatea " << i + 1 << " de promovare: ";
			in >> a.wayofadv[i];
		}
		for (int i = 0; i < a.wayofadvno; i++) {
			cout << "Introduceti costul modalitatii " << i + 1 << " de promovare: ";
			in >> a.advprice[i];
		}
		cout << "Introduceti numarul de angajati: ";
		in >> a.employeesno;
		return in;
	}

	//supraincarcare operator ++ prefixat
	Advertising& operator ++ () {
		string* newwayofadv = new string[this->wayofadvno + 1];
		for (int i = 0; i < this->wayofadvno; i++) {
			newwayofadv[i] = this->wayofadv[i];
		}
		newwayofadv[this->wayofadvno] = "Modalitate noua";
		this->advprice[this->wayofadvno] = 50;
		this->wayofadvno++;
		if (this->wayofadv != NULL) {
			delete[] this->wayofadv;
		}
		this->wayofadv = newwayofadv;
		return *this;
	}

	//supraincarcarea operatorului ++ postfixat
	Advertising operator ++ (int) {
		Advertising copie = *this;
		string* newwayofadv = new string[this->wayofadvno + 1];
		for (int i = 0; i < this->wayofadvno; i++) {
			newwayofadv[i] = this->wayofadv[i];
		}
		newwayofadv[this->wayofadvno] = "Modalitate noua";
		this->advprice[this->wayofadvno] = 70;
		this->wayofadvno++;
		if (this->wayofadv != NULL) {
			delete[] this->wayofadv;
		}
		this->wayofadv = newwayofadv;
		return copie;
	}

	//supraincarcarea operatorului *
	Advertising operator * (int val) {
		Advertising copie = *this;
		copie.employeesno *= val;
		return copie;
	}

	//supraincarcarea operatorului /
	Advertising operator / (int val) {
		Advertising copie = *this;
		copie.employeesno /= 2;
		return copie;
	}

	//Supraincarcare operator !
	bool operator ! () {
		if (this->wayofadv != NULL) {
			return false;
		}
		else
			return true;
	}

	//supraincarcare operator cast
	explicit operator float() {
		return this->employeesno;
	}

	//Supraincarcarea operatorului index []
	string& operator[] (int index) {
		if (index < 0 || index > this->wayofadvno) {
			cout << "Index in afara limitelor";
			throw new exception("Exceptie");
		}
		else {
			return this->wayofadv[index];
		}
	}
};
class Shoppingcart {
private:
	const char clientname[40];
	int productsno;
	string* product;
	double price[100];
	static int cartno;
public:
	//constructorul nr.1 cu parametri
	Shoppingcart(int productsnoA, string* productA, double priceA[100]) : clientname("A. Smith") {
		this->productsno = productsnoA;
		this->product = new string[this->productsno];
		for (int i = 0; i < this->productsno; i++) {
			this->product[i] = productA[i];
			this->price[i] = priceA[i];
		}
		this->cartno++;
	}

	//afisare pentru constructorul nr.1
	void afisare1() {
		cout << "Nume client: " << this->clientname << endl;
		cout << "Nr produse aflate in cos:" << this->productsno << endl;
		cout << "Produsele aflate in cos si preturile lor sunt: " << endl;
		for (int i = 0; i < this->productsno; i++) {
			cout << this->product[i] << "   " << this->price[i] << endl;
		}
		cout << "Acesta este cosul cu numarul " << this->cartno << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructorul nr.2 cu parametri
	Shoppingcart(int productsnoB, string* productB) : clientname("M. Anderson") {
		this->productsno = productsnoB;
		this->product = new string[this->productsno];
		for (int i = 0; i < this->productsno; i++) {
			this->product[i] = productB[i];
		}
		this->cartno++;
	}

	//afisare pt constructorul nr.2
	void afisare2() {
		cout << "Nume client: " << this->clientname << endl;
		cout << "Nr produse aflate in cos:" << this->productsno << endl;
		cout << "Produsele aflate in cos sunt: " << endl;
		for (int i = 0; i < this->productsno; i++) {
			cout << this->product[i] << endl;
		}
		cout << "Acesta este cosul cu numarul " << this->cartno << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//destructor
	~Shoppingcart() {
		if (this->product != NULL) {
			delete[] this->product;
		}
		this->cartno--;
		cout << "Apel destructor clasa Shoppingcart" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructor de copiere
	Shoppingcart(const Shoppingcart& c) :clientname("Z. Holt") {
		this->productsno = c.productsno;
		this->product = new string[this->productsno];
		for (int i = 0; i < this->productsno; i++) {
			this->product[i] = c.product[i];
			this->price[i] = c.price[i];
		}
		this->cartno++;
	}

	//reducerea preturilor cu 30%
	void reducerepreturi1() {
		for (int i = 0; i < this->productsno; i++) {
			this->price[i] = this->price[i] - 0.3*this->price[i];
		}
	}

	//modificarea produsului de pe pozitia i
	void modificareprodus(int i) {
		if (i < this->productsno) {
			this->product[i] = "product q";
			this->price[i] = 170;
		}
	}

	//getter atribut constant
	char const * getclientname() {
		return this->clientname;
	}

	//getter numar de produse
	int getproductsno() {
		return this->productsno;
	}

	//getter vector de produse 
	string* getproduct() {
		return this->product;
	}

	//setter vector de produse
	void setproduct(string *newproduct, int no) {
		if (this->product != NULL) {
			delete[] this->product;
		}
		this->productsno = no;
		this->product = new string[this->productsno];
		for (int i = 0; i < this->productsno; i++) {
			this->product[i] = newproduct[i];
		}
	}

	//getter preturi
	double getprice(int i) {
		return this->price[i];
	}
	//setter vector de preturi
	void setpreturi(double newprice[100], int no) {
		this->productsno = no;
		for (int i = 0; i < this->productsno; i++) {
			this->price[i] = newprice[i];
		}
	}

	//getter numar cos
	static int getcartno() {
		return cartno;
	}
	//setter numar cos
	static void setcartno(int newcartno) {
		Shoppingcart::cartno = newcartno;
	}

	//supraincarcarea operatorului =
	Shoppingcart& operator=(const Shoppingcart& p) {
		this->productsno = p.productsno;
		this->product = new string[this->productsno];
		for (int i = 0; i < this->productsno; i++) {
			this->product[i] = p.product[i];
			this->price[i] = p.price[i];
		}
		return *this;
	}

	//supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, const Shoppingcart& p) {
		out << "Nume client:" << p.clientname << endl;
		out << "Numar de produse: " << p.productsno << endl;
		out << "Produsele si preturile lor sunt : " << endl;
		for (int i = 0; i < p.productsno; i++) {
			out << p.product[i] << " " << p.price[i] << endl;
		}
		out << "Cosul de cumparaturi numarul " << p.cartno << endl;
		cout << "-------------------------------------------------------------" << endl;
		return out;
	}

	//supraincarcarea operatorului >>
	friend istream& operator>>(istream& in, Shoppingcart& p) {
		cout << "Numar de produse :";
		in >> p.productsno;
		cout << endl;
		if (p.product != NULL) {
			delete[] p.product;
		}
		p.product = new string[p.productsno];
		for (int i = 0; i < p.productsno; i++) {
			cout << "Produsul " << i + 1 << " este: ";
			in >> p.product[i];
		}
		for (int i = 0; i < p.productsno; i++) {
			cout << "Pretul produsului " << i + 1 << " este: ";
			in >> p.price[i];
		}

		return in;
	}

	//supraincarcare operator index []
	string& operator[](int index) {
		if (index < 0 || index > this->productsno) {
			cout << "Index in afara limitelor";
			throw new exception("Exceptie");
		}
		else {
			return this->product[index];
		}
	}

	//supraincarcare operator ==
	bool operator==(Shoppingcart p) {
		if (this->productsno != p.productsno)
			return false;
		for (int i = 0; i < this->productsno; i++) {
			if (this->product[i] != p.product[i])
				return false;
		}
		return true;

	}

	//supraincarcare operator <
	bool operator<(Shoppingcart p) {
		if (this->productsno < p.productsno)
			return true;
		return false;
	}

	//supraincarcare opreator cast
	explicit operator double() {
		return this->productsno;
	}

	//supraincarcare operator !
	bool operator!() {
		if (this->product != NULL)
			return false;
		return true;
	}

	//supraincarcare operator ++ prefixat
	Shoppingcart& operator++() {
		string* newproduct = new string[this->productsno + 1];
		for (int i = 0; i < this->productsno; i++) {
			newproduct[i] = this->product[i];
		}
		newproduct[this->productsno] = "new product";
		this->price[this->productsno] = 100;
		this->productsno++;
		if (this->product != NULL) {
			delete[] this->product;
		}
		this->product = newproduct;
		return *this;
	}

	//supraincarcare operator ++ sufixat
	Shoppingcart operator++(int) {
		Shoppingcart copie = *this;
		string* newproduct = new string[this->productsno + 1];
		for (int i = 0; i < this->productsno; i++) {
			newproduct[i] = this->product[i];
		}
		newproduct[this->productsno] = "new product";
		this->price[this->productsno] = 120;
		this->productsno++;
		if (this->product != NULL) {
			delete[] this->product;
		}
		this->product = newproduct;
		return copie;
	}

	//supraincarcare operator *
	Shoppingcart operator * (int value) {
		Shoppingcart copie = *this;
		for (int i = 0; i < copie.productsno; i++) {
			copie.price[i] = copie.price[i] * value;
		}
		return copie;
	}

	//supraincarcare operator / pentru apel obiect/2
	Shoppingcart operator/(int valoare) {
		Shoppingcart copie = *this;
		copie.productsno /= valoare;
		return copie;
	}

};
//clasa Product contine o metoda virtuala
class Product {
private:
	string productname;
	int manufacturersno;
	int idmanufacturers[20];
	string * manufacturernames;
	double price;
	//variabilele bool trebuie denumite cu prefixul b, urmat de un nume camelCase
	bool isonsale;
	const string category;
	static int productsno;
public:
	//constructor nr.1 cu parametri
	Product(string productnameA, int manufacturersnoA, int idmanufacturersA[20], string * manufacturernamesA, double priceA, bool isonsaleA) :category("Clothes") {
		this->productname = productnameA;
		this->manufacturersno = manufacturersnoA;
		this->manufacturernames = new string[this->manufacturersno];
		for (int i = 0; i < this->manufacturersno; i++) {
			this->idmanufacturers[i] = idmanufacturersA[i];
			this->manufacturernames[i] = manufacturernamesA[i];
		}
		this->price = priceA;
		this->isonsale = isonsaleA;
		this->productsno++;
	}

	//afisare pentru constructor nr.1 cu parametri
	virtual void afisare1() {
		cout << "Nume produs: " << this->productname << endl;
		cout << "Numar de producatori: " << this->manufacturersno << endl;
		cout << "ID-urile producatorilor si numele lor sunt: " << endl;
		for (int i = 0; i < this->manufacturersno; i++) {
			cout << this->idmanufacturers[i] << " " << this->manufacturernames[i] << endl;
		}
		cout << "Pret: " << this->price << endl;
		if (isonsale == 1)
			cout << "Produsul este redus " << endl;
		else
			cout << "Produsul nu este redus " << endl;

		cout << "Numar de produse:  " << this->productsno << endl;
		cout << "Categorie: " << this->category << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructor cu parametri nr.2
	Product(string productnameA, int manufacturersnoA, string * manufacturernamesA) : category("clothes") {
		this->productname = productnameA;
		this->manufacturersno = manufacturersnoA;
		this->manufacturernames = new string[this->manufacturersno];
		for (int i = 0; i < this->manufacturersno; i++) {
			this->manufacturernames[i] = manufacturernamesA[i];
		}
		this->productsno++;
	}

	//afisare pentru constructor nr.2 cu parametri
	void afisare2() {
		cout << "Nume produs: " << this->productname << endl;
		cout << "Numar de producatori: " << this->manufacturersno << endl;
		cout << "Numele producatorilor sunt: " << endl;
		for (int i = 0; i < this->manufacturersno; i++) {
			cout << this->manufacturernames[i] << endl;
		}
		cout << "Numar de produse:  " << this->productsno << endl;
		cout << "Categorie: " << this->category << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructor de copiere
	Product(const Product& p) :category("clothes") {
		this->productname = p.productname;
		this->manufacturersno = p.manufacturersno;
		this->manufacturernames = new string[this->manufacturersno];
		for (int i = 0; i < this->manufacturersno; i++) {
			this->idmanufacturers[i] = p.idmanufacturers[i];
			this->manufacturernames[i] = p.manufacturernames[i];
		}
		this->price = p.price;
		this->isonsale = p.isonsale;
		this->productsno++;
	}

	//destructor
	~Product() {
		if (this->manufacturernames != NULL) {
			delete[] this->manufacturernames;
		}
		this->productsno--;
		cout << "Apel destructor clasa Product " << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//getter nume produs
	string getproductname() {
		return this->productname;
	}
	//setter nume produs
	void setproductname(string productnameA) {
		this->productname = productnameA;
	}

	//getter numar producatori
	int getmanufacturersno() {
		return this->manufacturersno;
	}
	//setter numar producatori
	void setmanufacturersno(int no) {
		this->manufacturersno = no;
	}

	//getter ID producator de pe pozitia i
	int getidmanufacturers(int i) {
		return idmanufacturers[i];
	}
	//setter ID Producatori
	void setidmanufacturers(int no, int id[20]) {
		this->manufacturersno = no;
		for (int i = 0; i < this->manufacturersno; i++) {
			this->idmanufacturers[i] = id[i];
		}
	}

	//getter nume producatori
	string* getmanufacturernames() {
		return this->manufacturernames;
	}
	//setter nume producatori
	void setmanufacturernames(int no, string *manufacturers) {
		if (this->manufacturernames != NULL) {
			delete[] this->manufacturernames;
		}

		this->manufacturersno = no;
		this->manufacturernames = new string[this->manufacturersno];
		for (int i = 0; i < this->manufacturersno; i++) {
			this->manufacturernames[i] = manufacturers[i];
		}
	}

	//getter pret
	double getprice() {
		return this->price;
	}
	//setter pret
	void setprice(double aux) {
		this->price = aux;
	}

	//getter isonsale
	bool getisonsale() {
		return this->isonsale;
	}

	//setter isonsale
	void setisonsale(bool b) {
		this->isonsale = b;
	}

	//getter atribut constant (category)
	string getcategory() {
		return this->category;
	}

	//getter atribut static(productsno)
	static int getproductsno() {
		return productsno;
	}
	//setter atribut constant(productsno)
	static void setproductsno(int no) {
		Product::productsno = no;
	}

	//crestere pret cu 10%
	void priceincrease() {
		this->price = 1.1*this->price;
	}

	//supraincarcare operator ==
	bool operator == (Product p) {
		if (this->productname == p.productname && this->manufacturersno == p.manufacturersno)
			return true;
		return false;
	}

	//supraincarcare operator >
	bool operator > (Product p) {
		if (this->productname == p.productname && this->manufacturersno > p.manufacturersno)
			return true;
		return false;
	}

	//supraincarcare operator !
	bool operator ! () {
		if (this->manufacturernames != NULL) {
			return false;
		}
		return true;
	}

	//supraincarcare operator =
	Product& operator =(const Product p) {
		this->productname = p.productname;
		this->manufacturersno = p.manufacturersno;
		this->manufacturernames = new string[this->manufacturersno];
		for (int i = 0; i < this->manufacturersno; i++) {
			this->idmanufacturers[i] = p.idmanufacturers[i];
			this->manufacturernames[i] = p.manufacturernames[i];
		}
		this->price = p.price;
		this->isonsale = p.isonsale;
		return *this;

	}

	//supraincarcare operator <<
	friend ostream& operator << (ostream& out, const Product& p) {
		out << "Numele produsului este: " << p.productname << endl;
		out << "Numarul de producatori este: " << p.manufacturersno << endl;
		out << "ID-urile si numele producatorilor sunt: " << endl;
		for (int i = 0; i < p.manufacturersno; i++) {
			out << p.idmanufacturers[i] << " " << p.manufacturernames[i] << endl;
		}
		out << "Pretul produsului este: " << p.price << endl;
		if (p.isonsale == 1) {
			out << "Produsul este redus" << endl;
		}
		else {
			out << "Produsul nu este redus" << endl;
		}
		out << "Categoria din care face parte produsul este: " << p.category << endl;
		out << "Numarul de produse este: " << productsno << endl;
		out << "-------------------------------------------------------------" << endl;
		return out;

	}

	//supraincarcare operator >>
	friend istream& operator >> (istream& in, Product& p) {
		cout << "Introduceti numele produsului: ";
		in >> p.productname;
		cout << "Introduceti numarul de producatori: ";
		in >> p.manufacturersno;
		if (p.manufacturernames != NULL) {
			delete[] p.manufacturernames;
		}
		p.manufacturernames = new string[p.manufacturersno];
		for (int i = 0; i < p.manufacturersno; i++) {
			cout << "Introduceti ID-ul pentru producatorul nr. " << i + 1 << " ";
			in >> p.idmanufacturers[i];
			cout << "Introduceti numele pentru producatorul nr. " << i + 1 << " ";
			in >> p.manufacturernames[i];
		}
		cout << "Introduceti pretul produsului: ";
		in >> p.price;
		cout << "Specificati daca produsul este redus sau nu: ";
		in >> p.isonsale;
		return in;
	}

	//supraincarcare operator << pentru afisare in fisier
	friend ofstream& operator << (ofstream& out, Product p) {
		out << p.productname << endl;
		out << p.manufacturersno << endl;
		for (int i = 0; i < p.manufacturersno; i++) {
			out << p.idmanufacturers[i] << endl;
		}
		for (int i = 0; i < p.manufacturersno; i++) {
			out << p.manufacturernames[i] << endl;
		}
		out << p.price << endl;
		out << p.isonsale << endl;
		out << p.category << endl;
		out << productsno << endl;
		//out << "-------------------------------------------------------------" << endl;
		return out;
	}

	//suprascriere operator >> pentru citire din fisier
	friend ifstream& operator >> (ifstream& in, Product &p) {
		getline(in, p.productname);
		in >> p.manufacturersno;
		if (p.manufacturernames != NULL) {
			delete[] p.manufacturernames;
		}
		p.manufacturernames = new string[p.manufacturersno];
		for (int i = 0; i < p.manufacturersno; i++) {
			in >> p.idmanufacturers[i];
		}
		in.get();
		for (int i = 0; i < p.manufacturersno; i++) {
			getline(in, p.manufacturernames[i]);
		}

		in >> p.price;
		in >> p.isonsale;
		return in;
	}

	//supraincarcare operator ++ prefixat
	Product& operator ++ () {
		string *aux = new string[this->manufacturersno + 1];
		for (int i = 0; i < this->manufacturersno; i++) {
			aux[i] = manufacturernames[i];
		}
		aux[this->manufacturersno] = "Producator nou";
		this->idmanufacturers[this->manufacturersno] = 20;
		this->manufacturersno++;
		if (this->manufacturernames != NULL)
			delete[] this->manufacturernames;
		this->manufacturernames = aux;
		return *this;
	}

	//supraincarcare operator ++ postfixat
	Product& operator ++ (int) {
		Product aux = *this;
		string * auxstr = new string[this->manufacturersno + 1];
		for (int i = 0; i < this->manufacturersno; i++) {
			auxstr[i] = this->manufacturernames[i];
		}
		auxstr[this->manufacturersno] = "Producator nou";
		this->idmanufacturers[this->manufacturersno] = 21;
		this->manufacturersno++;
		if (this->manufacturernames != NULL)
			delete[] this->manufacturernames;
		this->manufacturernames = auxstr;
		return aux;
	}

	//supraincarcare operator cast
	explicit operator float() {
		return this->price;
	}

	//supraincarcare operator index
	string& operator[] (int index) {
		if (index < 0 || index >this->manufacturersno) {
			cout << "Index in afara limitelor " << endl;
			throw new exception("Exceptie");
		}
		else {
			return this->manufacturernames[index];
		}
	}

	//supraincarcare operator *
	Product operator * (int value) {
		Product aux = *this;
		aux.price = aux.price *value;
		return aux;
	}

	//supraincarcare operator /
	Product operator / (int value) {
		Product aux = *this;
		aux.price = aux.price / value;
		return aux;
	}

};

int Advertising::advproductsno = 0;
int Shoppingcart::cartno = 0;
int Product::productsno = 0;

//CLASE - FAZA 2
//clasa OnlineCampaign este o clasa abstracta(contine o metoda virtuala pura) si mosteneste clasa Advertising(relatie is a)
class OnlineCampaign : public Advertising {
protected:
	string platformname;
	int campaignlife;
public:
	//constructor cu parametri
	OnlineCampaign(string productname1, int wayofadvno1, string* wayofadv1, float advprice1[100], int employeesno1, string platformname1, int campaignlife1, float budget1) :Advertising(productname1, wayofadvno1, wayofadv1, advprice1, employeesno1, budget1) {
		this->platformname = platformname1;
		this->campaignlife = campaignlife1;
	}

	//puteam sa suprascriu o metoda de afisare din clasa Advertising
	//afisare
	void afisareOnlineCampaign() {
		cout << "Numele produsului promovat este: " << this->getproductname() << endl;
		int wayofadvno1 = this->getwayofadvno();
		cout << "Numarul de modalitati prin care este promovat este:" << wayofadvno1 << endl;
		cout << "Modalitatile prin care este promovat si costurile acestora sunt: " << endl;
		string *wayofadv1 = new string[wayofadvno1];
		wayofadv1 = this->getwayofadv();
		for (int i = 0; i < wayofadvno1; i++) {
			cout << wayofadv1[i] << " " << this->getadvprice(i) << endl;
		}
		cout << "Numarul de angjati in departamentul de promovare este:" << this->getemployeesno() << endl;
		cout << "Bugetul disponibil este: " << this->getbudget() << endl;
		cout << "Numele platformei prin care este promovat produsul este: " << this->platformname << endl;
		cout << "Durata de desfasurare a campaniei este de: " << this->campaignlife << " zile " << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructor de copiere
	OnlineCampaign(const OnlineCampaign &a) : Advertising(a) {
		this->platformname = a.platformname;
		this->campaignlife = a.campaignlife;
	}

	//destructor 
	virtual ~OnlineCampaign() {
		cout << "Apel destructor clasa OnlineCampaign" << endl;
		cout << "-------------------------------------------------------------" << endl;

	}


	//getter pentru numele platformei
	string getplatformname() {
		return this->platformname;
	}
	//setter pentru numele platformei
	void setplatformname(string name) {
		this->platformname = name;
	}

	//getter pentru durata in care se desfasoaea campania
	int getcampaignlife() {
		return this->campaignlife;
	}
	//setter pentru durata in care se desfasoara campania
	void setcampaignlife(int life) {
		this->campaignlife = life;
	}

	//metoda virtual pura
	virtual void advcost() = 0;

};

//Interfata
class Icosts {
public:
	virtual void affordadv() = 0;
};

//numele clasei nu este sugestiv
//Clasa Awareness mosteneste clasa OnlineCampaign si implementeaza interfata Icosts(relatie is a)
class Awareness : public OnlineCampaign, public Icosts {
private:
	int reach;
public:
	virtual void advcost() {
		int dim = this->getwayofadvno();
		float totalsum = 0;
		for (int i = 0; i < dim; i++) {
			totalsum = totalsum + this->getadvprice(i);
		}
		cout << "Costul total pentru promovarea produsului este: " << totalsum << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	virtual void affordadv() {
		int dim = this->getwayofadvno();
		float totalsum = 0;
		for (int i = 0; i < dim; i++) {
			totalsum = totalsum + this->getadvprice(i);
		}
		if (totalsum < this->getbudget())
			cout << "Exista fonduri necesare pentru a promova produsul astfel." << endl;
		else
			cout << "Nu exista fonduri suficiente pentru a promova astfel produsul." << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//constructor cu parametri
	Awareness(string productname1, int wayofadvno1, string* wayofadv1, float advprice1[100], int employeesno1, string platformname1, int campaignlife1, int reach1, float budget1) :OnlineCampaign(productname1, wayofadvno1, wayofadv1, advprice1, employeesno1, platformname1, campaignlife1, budget1) {
		this->reach = reach1;
	}

	//constructor de copiere
	Awareness(const Awareness& a) :OnlineCampaign(a) {
		this->reach = a.reach;
	}

	~Awareness() {
		cout << "Apel destructor clasa Awareness" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//afisare
	void afisare() {
		cout << "Numele produsului promovat este: " << this->getproductname() << endl;
		int wayofadvno1 = this->getwayofadvno();
		cout << "Numarul de modalitati prin care este promovat este:" << wayofadvno1 << endl;
		cout << "Modalitatile prin care este promovat si costurile acestora sunt: " << endl;
		string *wayofadv1 = new string[wayofadvno1];
		wayofadv1 = this->getwayofadv();
		for (int i = 0; i < wayofadvno1; i++) {
			cout << wayofadv1[i] << " " << this->getadvprice(i) << endl;
		}
		cout << "Numarul de angjati in departamentul de promovare este:" << this->getemployeesno() << endl;
		cout << "Bugetul disponibil este: " << this->getbudget() << endl;
		cout << "Numele platformei prin care este promovat produsul este: " << this->platformname << endl;
		cout << "Durata de desfasurare a campaniei este de: " << this->campaignlife << " zile " << endl;
		cout << "Mesajul a ajuns la " << this->reach << " persoane" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	int getreach() {
		return this->reach;
	}

	void setreach(int reach1) {
		this->reach = reach1;
	}

};

//clasa Food mosteneste clasa Product(relatie is a)
class Food :public Product {
protected:
	string expirationdate;
	bool isbio;
public:
	//constructor cu parametri
	Food(string productname1, int manufacturersno1, int idmanufacturers1[20], string* manufacturernames1, double price1, bool isonsale1, string expirationdate1, bool isbio1) :Product(productname1, manufacturersno1, idmanufacturers1, manufacturernames1, price1, isonsale1) {
		this->expirationdate = expirationdate1;
		this->isbio = isbio1;
	}

	//constructor de copiere
	Food(const Food& f) :Product(f) {
		this->expirationdate = f.expirationdate;
		this->isbio = f.isbio;
	}

	//destructor
	~Food() {
		cout << "Apel destructor clasa Food" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//afisare
	void afisare1()override {
		cout << "Nume produs: " << this->getproductname() << endl;
		cout << "Numar de producatori: " << this->getmanufacturersno() << endl;
		cout << "ID-urile si numele producatorilor sunt: " << endl;
		int no = this->getmanufacturersno();
		string * names = new string[no];
		names = this->getmanufacturernames();
		for (int i = 0; i < no; i++) {
			cout << this->getidmanufacturers(i) << " " << names[i] << endl;
		}
		cout << "Pret: " << this->getprice() << endl;
		if (this->getisonsale() == 1)
			cout << "Produsul este redus " << endl;
		else
			cout << "Produsul nu este redus " << endl;
		cout << "Produsul expira la data de: " << this->expirationdate << endl;
		if (this->isbio == 1)
			cout << "Produsul este bio " << endl;
		else
			cout << "Produsul nu este bio " << endl;
		cout << "Numar de produse: " << this->getproductsno() << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//getter data de expirare
	string getexpirationdate() {
		return this->expirationdate;
	}
	//setter data de expirare
	void setexpirationdate(string date) {
		this->expirationdate = date;
	}

	//getter isbio
	bool getisbio() {
		return this->isbio;
	}
	//setter isbio
	void setisbio(bool is) {
		this->isbio = is;
	}
};

//Clasa AdvertisingTeam mosteneste clasa Advertising(relatia has a)
class AdverstisingTeam {
private:
	Advertising** advertisedproduct;
	int projectsno;
public:
	//constructor cu parametri
	AdverstisingTeam(Advertising** adv1, int projectsno1) {
		this->projectsno = projectsno1;
		this->advertisedproduct = new Advertising*[this->projectsno];
		for (int i = 0; i < this->projectsno; i++) {
			this->advertisedproduct[i] = adv1[i];
		}
	}

	//destructor
	~AdverstisingTeam() {
		if (this->advertisedproduct != NULL) {
			delete[]this->advertisedproduct;
		}
	}

	//afisare
	void afisare() {
		cout << "Numarul de proiecte ale echipei: " << this->projectsno << endl;
		cout << "Proiecte:" << endl;
		for (int i = 0; i < this->projectsno; i++) {
			this->advertisedproduct[i]->afisare1();
		}
	}
};

int main() {
	//FAZA 1

	//ADVERTISING

	//apel constructor cu parametri nr.1
	string productname1 = "blouse";
	int wayofadvno1 = 4;
	string* wayofadv1 = new string[wayofadvno1];
	float advprice1[100];
	for (int i = 0; i < wayofadvno1; i++) {
		wayofadv1[i] = "way " + to_string(i + 1);
		advprice1[i] = 50 + i * 15;
	}
	int employeesno1 = 10;
	Advertising a(productname1, wayofadvno1, wayofadv1, advprice1, employeesno1, 5000);
	a.afisare1();
	cout << a.getbudget() << endl;

	string productname2 = "boots";
	int wayofadvno2 = 5;
	string* wayofadv2 = new string[wayofadvno2];
	float advprice2[100];
	for (int i = 0; i < wayofadvno2; i++) {
		wayofadv2[i] = "way " + to_string(i + 7);
		advprice2[i] = 100 + i * 10;
	}
	int employeesno2 = 5;
	Advertising* b = new Advertising(productname2, wayofadvno2, wayofadv2, advprice2, employeesno2, 2000);
	b->afisare1();

	//apel constructori cu parametri nr.2
	string productname3 = "dress";
	for (int i = 0; i < wayofadvno1; i++) {
		wayofadv1[i] = "way " + to_string(i + 3);
	}
	Advertising c(productname3, wayofadvno1, wayofadv1, 1000);
	c.afisare2();

	//apel constructor de copiere
	Advertising d = a;
	d.afisare1();

	Advertising e(a);
	e.afisare1();

	//cresterea numarului de angajati cu 2
	b->employeesnoadd();
	b->afisare1();

	//calcularea costului total de promovare al unui produs
	cout << "Costul de promovare al produsului corespondent obiectului b este:" << b->cost();
	cout << endl << "-------------------------------------------------------------" << endl;

	//apel getter si setter pentru numele produsului
	cout << "Numele produsului promovat ce corespunde obiectului a este: " << a.getproductname() << endl;
	string productname4 = "t-shirt";
	a.setproductname(productname4);
	cout << "Numele noului produs promovat ce corespunde obiectului a este: " << a.getproductname() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter si setter pentru numarul de modalitati de promovare si pentru modalitatile de promovare
	cout << "Numarul de modalitati prin care este promovat produsul ce corespunde obiectului a este: " << a.getwayofadvno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	int auxdim = a.getwayofadvno();
	string *aux = new string[auxdim];
	aux = a.getwayofadv();
	cout << "Modalitatile de promovare ale produsului ce corespunde obiectului a sunt: " << endl;
	for (int i = 0; i < auxdim; i++)
		cout << aux[i] << endl;
	cout << "-------------------------------------------------------------" << endl;

	int no = 4;
	a.setwayofadv(wayofadv2, no);
	int auxdim1 = a.getwayofadvno();
	string *aux1 = new string[auxdim1];
	aux1 = a.getwayofadv();
	cout << "Noile modalitati de promovare ale produsului ce corespunde obiectului a sunt: " << endl;
	for (int i = 0; i < auxdim1; i++)
		cout << aux1[i] << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter si setter pentru costurile aferente modalitatilor de promovare
	cout << "Costurile aferente modalitatilor de promovare ale produsului ce corespunde obiectului a sunt:" << endl;
	for (int i = 0; i < a.getwayofadvno(); i++) {
		cout << a.getadvprice(i) << endl;
	}
	cout << "Noile costuri de promovare aferente produsului promovat ce corespunde obiectului a sunt: " << endl;
	a.setadvprice(advprice2, wayofadvno2);
	for (int i = 0; i < a.getwayofadvno(); i++) {
		cout << a.getadvprice(i) << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel getter si setter pentru numarul de angajati din departamentul de promovare
	cout << "Numarul de angajati din departamentul de promovare ce corespunde obiectului a este: " << a.getemployeesno() << endl;
	a.setemployeesno(3);
	cout << "Noul numar de angajati din departamentul de promovare ce corespunde obiectului a este:" << a.getemployeesno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter atribut constant
	cout << "Bugetul alocat promovarii produsului ce corespunde obiectului a este: " << a.getbudget() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter si setter pentru numarul de produse promovate
	cout << "Numarul de produse promovate este: " << Advertising::getadvproductsno() << endl;
	Advertising::setadvproductsno(10);
	cout << "Noul numar de produse promovate este: " << Advertising::getadvproductsno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	a.setadvproductsno(3);

	//apel supraincarcare operatori == si <
	string productname5 = "shirt";
	int wayofadvno4 = 6;
	string* wayofadv4 = new string[wayofadvno4];
	float advprice4[100];
	for (int i = 0; i < wayofadvno4; i++) {
		wayofadv4[i] = "way " + to_string(i + 1);
		advprice4[i] = 50 + i * 15;
	}
	int employeesno4 = 10;
	Advertising f(productname5, wayofadvno4, wayofadv4, advprice4, employeesno4, 5000);
	f.afisare1();


	//apel supraincarcare operator ==
	if (a == f) {
		cout << "Cele doua produse sunt identice" << endl;
	}
	else
		//apel supraincarcare operator <
		if (a < f) {
			cout << "Produsele sunt diferite si/sau produsul aferent obiectului a este promovat mai putin decat produsul aferent obiectului f" << endl;
		}
		else
			cout << "Produsele sunt diferite si/sau produsul aferent obiectului f este promovat mai putin decat produsul aferent obiectului a" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator =
	a = f;
	a.afisare1();

	//apel supraincarcare operator <<
	cout << f;
	cout << "-------------------------------------------------------------" << endl;

	cout << *b;
	cout << "-------------------------------------------------------------" << endl;

	/*
	//apel supraincarcare operator >>
	cin >> f;
	cout << f;
	*/

	//apel supraincarcare ++ prefixat
	++f;
	cout << f;

	//apel supraincarcare ++ postfixat
	f++;
	cout << f;

	//apel supraincarcare operator *
	f = f * 2;
	cout << "Noul numar de angajati din departamentul de promovare este: " << f.getemployeesno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator /
	f = f / 2;
	cout << "Noul numar de angajati din departamentul de promovare este: " << f.getemployeesno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator !
	if (!f) {
		cout << "Adevarat" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}
	else {
		cout << "Fals" << endl;
		cout << "-------------------------------------------------------------" << endl;
	}

	//supraincarcare operator cast
	cout << "Numarul de angajati ai departamentului de promovare ce corespunde obiectului f este: " << (float)f << endl;
	cout << "-------------------------------------------------------------" << endl;

	//supraincarcare operator index []
	cout << "Prima modalitate de promovare ce corespunde obiectului f este: " << f[0] << endl;
	cout << "-------------------------------------------------------------" << endl;



	//SHOPPINGCART


	int productsno1 = 3;
	string* product1;
	product1 = new string[productsno1];
	double price1[100];
	for (int i = 0; i < productsno1; i++) {
		product1[i] = "product " + to_string(i + 1);
		price1[i] = 100 + i * 10;
	}

	//apel constructor cu parametri nr.1
	Shoppingcart* g = new Shoppingcart(productsno1, product1, price1);
	g->afisare1();

	//apel constructor cu parametri nr.2
	Shoppingcart* h = new Shoppingcart(productsno1, product1);
	h->afisare2();

	//apel constructor de copiere
	Shoppingcart* k = g;
	k->afisare1();
	Shoppingcart l(productsno1, product1, price1);
	l.afisare1();
	Shoppingcart m = l;
	m.afisare1();

	delete k;

	//reducerea preturilor produselor aflate in cos cu 30%
	l.reducerepreturi1();
	l.afisare1();

	//modificarea produsului de pe pozitia i
	int i = 2;
	l.modificareprodus(i);
	l.afisare1();

	//apel getter pentru atributul constant
	cout << "Numele clientului de la obiectul l este: " << l.getclientname() << endl;

	//apel getter pentru numarul de produse din cos
	cout << "Numarul de produse aflate in cos este: " << l.getproductsno() << endl;

	//apel getter produse
	int dimproduse = l.getproductsno();
	string *auxproduse = new string[dimproduse];
	auxproduse = l.getproduct();
	cout << "Produsele aflate in cos sunt: " << endl;
	for (int i = 0; i < dimproduse; i++) {
		cout << auxproduse[i] << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel getter preturi
	cout << "Preturile produselor aflate in cos sunt: " << endl;
	for (int i = 0; i < dimproduse; i++) {
		cout << "Pretul produsului de pe pozitia " << i + 1 << " este: " << l.getprice(i) << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	int productno2 = 4;
	string* product2 = new string[productno2];
	double price2[100];
	for (int i = 0; i < productno2; i++) {
		product2[i] = "product " + to_string(i + 10);
		price2[i] = 5 + (i + 1) * 20;
	}

	//apel setter produse
	l.setproduct(product2, productno2);
	auxproduse = l.getproduct();
	cout << "Produsele aflate in cos sunt: " << endl;
	for (int i = 0; i < dimproduse; i++) {
		cout << auxproduse[i] << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel setter preturi
	l.setpreturi(price2, productno2);
	cout << "Preturile produselor aflate in cos sunt: " << endl;
	for (int i = 0; i < dimproduse; i++) {
		cout << "Pretul produsului de pe pozitia " << i + 1 << " este: " << l.getprice(i) << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel getter numar cosuri
	cout << "Numarul initial de cosuri este: " << l.getcartno() << endl;

	//apel setter numar cosuri
	Shoppingcart::setcartno(5);
	cout << "Numarul de cosuri este: " << l.getcartno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	int productno3 = 5;
	string* product3 = new string[productno3];
	double price3[100];
	for (int i = 0; i < productno3; i++) {
		product3[i] = "product " + to_string(i * 2 + 1);
		price3[i] = 105 + i * 10;
	}

	//apel supraincarcarea operatorului =
	Shoppingcart n(productno3, product3, price3);
	n.afisare1();
	l = n;
	l.afisare1();

	//apel supraincarcarea operatorului <<
	cout << l;

	//apel supraincarcarea operatorului >>
	/*cin >> l;
	cout << l;
	*/

	//apel supraincarcarea operatorului []
	cout << "Produsul de pe pozitia a doua este:" << l[1] << endl;
	try {
		cout << l[2] << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1";
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl;
	}


	int productno4 = 6;
	string* product4 = new string[productno4];
	double price4[100];
	for (int i = 0; i < productno4; i++) {
		product4[i] = "product " + to_string(i * 3 + 2);
		price4[i] = 20 + i * 10;
	}
	Shoppingcart o(productno4, product4, price4);
	o.afisare1();

	//apel supraincarcare operator ==
	if (o == l)
		cout << "Cele doua cosuri de cumparaturi contin aceleasi produse." << endl;
	else
		if (o < l)
			cout << "Cosul o contine mai putine produse decat cosul l. " << endl;
		else
			cout << "Cosul l contine mai putine produse decat cosul o. " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator cast
	cout << "In cosul l se afla " << double(l) << " produse" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator !
	if (!l)
		cout << "Adevarat" << endl;
	else
		cout << "Fals" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator ++ prefixat
	cout << l;
	++l;
	cout << l;

	//apel supraincarcare operator ++sufixat
	l++;
	cout << l;

	//apel supraincarcare operator *
	l = l * 2;
	int diml = l.getproductsno();
	for (int i = 0; i < diml; i++) {
		cout << l.getprice(i) << endl;
	}


	//apel supraincarcare operator /
	l = l / 1;
	cout << l.getproductsno() << endl;
	cout << "-------------------------------------------------------------" << endl;


	//PRODUCT


	string productname11 = "skirt";
	int manufacturersno11 = 2;
	int idmanufacturers11[20];
	string *manufacturernames11 = new string[manufacturersno11];
	for (int i = 0; i < manufacturersno11; i++) {
		idmanufacturers11[i] = i + 1;
		manufacturernames11[i] = "name " + to_string(i + 1);
	}
	double price11 = 100;
	bool boo = 1;
	//apel constructor nr.1 cu parametri
	Product p1(productname11, manufacturersno11, idmanufacturers11, manufacturernames11, price11, boo);
	p1.afisare1();

	string productname12 = "jeans";
	int manufacturersno12 = 3;
	int idmanufacturers12[20];
	string *manufacturernames12 = new string[manufacturersno12];
	for (int i = 0; i < manufacturersno12; i++) {
		manufacturernames12[i] = "name " + to_string(i + 1);
	}

	//apel constructor nr.2 cu parametri
	Product p2(productname12, manufacturersno12, manufacturernames12);
	p2.afisare2();

	//apel 1 constructor de copiere
	Product p3 = p1;
	p3.afisare1();

	//apel 2 constructor de copiere
	Product p4(p1);
	p4.afisare1();

	//apel getter nume produs
	cout << "Numele produsului este: " << p1.getproductname() << endl;
	//apel setter nume produs
	p1.setproductname("gloves");
	cout << "Noul nume al produsului este: " << p1.getproductname() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter numar de producatori
	cout << "Numarul de producatori este: " << p1.getmanufacturersno() << endl;
	p1.setmanufacturersno(1);
	cout << "Noul numar de producatori este: " << p1.getmanufacturersno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter pentru id-urile producatorilor
	cout << "ID-urile producatorilor sunt: " << endl;
	for (int i = 0; i < p1.getmanufacturersno(); i++) {
		cout << p1.getidmanufacturers(i) << endl;
	}

	int manufacturersno13 = 2;
	int idmanufacturers13[20];
	for (int i = 0; i < manufacturersno13; i++) {
		idmanufacturers13[i] = i + 7;
	}
	//apel setter pentru id-urile producatorilor
	p1.setidmanufacturers(manufacturersno13, idmanufacturers13);
	cout << "Noile ID-urile ale producatorilor sunt: " << endl;
	for (int i = 0; i < p1.getmanufacturersno(); i++) {
		cout << p1.getidmanufacturers(i) << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel getter nume producatori
	int no1 = p1.getmanufacturersno();
	string *manufacturers = new string[no1];
	manufacturers = p1.getmanufacturernames();
	cout << "Numele producatorilor sunt: " << endl;
	for (int i = 0; i < no1; i++) {
		cout << manufacturers[i] << endl;
	}

	no1 = 3;
	string *auxstring = new string[no1];
	for (int i = 0; i < no1; i++) {
		auxstring[i] = "name " + to_string(i + 4);
	}

	//apel setter nume producatori
	p1.setmanufacturernames(no1, auxstring);
	no1 = p1.getmanufacturersno();
	string * auxstring2 = new string[no1];
	auxstring2 = p1.getmanufacturernames();
	cout << "Numele noilor producatorilor sunt: " << endl;
	for (int i = 0; i < no1; i++) {
		cout << auxstring2[i] << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//apel getter pret
	cout << "Pretul produsului este: " << p1.getprice() << endl;
	//apel setter pret
	p1.setprice(50);
	cout << "Noul pret al produsului este: " << p1.getprice() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter isonsale
	if (p1.getisonsale() == 1)
		cout << "Produsul este redus" << endl;
	else
		cout << "Produsul nu este redus " << endl;

	//apel setter isonsale
	bool val = 0;
	p1.setisonsale(val);
	if (p1.getisonsale() == 1)
		cout << "Produsul este redus" << endl;
	else
		cout << "Produsul nu este redus " << endl;

	//apel getter categorie(atribut constant)
	cout << "Categoria din care face parte produsul este: " << p1.getcategory() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel getter numar de produse(atribut static)
	cout << "Numarul initial de produse este: " << Product::getproductsno() << endl;
	Product::setproductsno(5);
	cout << "Numarul actual de produse este: " << Product::getproductsno() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel priceincrease
	p3.priceincrease();
	cout << "Pretul crescut este: " << p3.getprice() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator ==
	if (p4 == p3)
		cout << "Produsele sunt la fel si au acelasi numar de producatori " << endl;
	else
		if (p4 > p3)
			cout << "Produsele sunt la fel, dar p4 are mai multi producatori decar p3" << endl;
		else
			cout << "Produsele sunt diferite sau p4 are mai putini producatori decat p3" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator !
	if (!p3)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator =
	p1 = p3;
	p1.afisare1();
	p3.afisare1();

	//apel supraincarcare operator <<
	cout << p3;

	/*
	//apel supraincarcare operator >>
	cin >> p1;
	cout << p1;
	*/

	//apel supraincarcare operator ++ prefixat
	++p1;
	cout << p1;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator ++ postfixat
	p1++;
	cout << p1;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator float
	cout << float(p1) << endl;
	cout << "-------------------------------------------------------------" << endl;

	//apel supraincarcare operator []
	cout << "Al doilea producator este: " << p1[1] << endl;
	try {
		cout << p1[2] << endl;
	}
	catch (exception* e1) {
		cout << e1->what() << endl;
		cout << "Exceptie prinsa 1" << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//supraincarcare operator *
	p1 = p1 * 2;
	cout << p1.getprice() << endl;
	cout << "-------------------------------------------------------------" << endl;

	p1 = p1 / 2;
	cout << p1.getprice() << endl;
	cout << "-------------------------------------------------------------" << endl;


	//FAZA 2

	//Clasele OnlineCampaign, Awareness

	string productname21 = "jacket";
	int wayofadvno21 = 3;
	string* wayofadv21 = new string[wayofadvno21];
	float advprice21[100];
	for (int i = 0; i < wayofadvno21; i++) {
		wayofadv21[i] = "way " + to_string(i + 1);
		advprice21[i] = 100 + i * 20;
	}
	int employeesno21 = 5;
	string platformname21 = "Instagram";
	int campaignlife21 = 14;
	int reach21 = 1000;

	//Apel constructor cu parametri
	Awareness *oc1 = new Awareness(productname21, wayofadvno21, wayofadv21, advprice21, employeesno21, platformname21, campaignlife21, reach21, 2000);
	Awareness oc2(productname21, wayofadvno21, wayofadv21, advprice21, employeesno21, platformname21, campaignlife21, reach21, 2000);

	//Apel metoda de afisare
	oc2.afisare();

	//Apel constructor de copiere
	Awareness oc4(oc2);
	oc4.afisare();

	//Apel metoda care calculeaza costul proovarii unui produs
	oc2.advcost();

	//Apel metoda care decide daca exista fonduri suficiente pentru a promova produsul astfel
	oc2.affordadv();

	//apel getter reach
	cout << "Mesajul a ajuns la " << oc2.getreach() << " de persoane" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel setter reach
	oc2.setreach(200);
	cout << "Mesajul a ajuns la " << oc2.getreach() << " de persoane" << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel getter productname (atribut din clasa parinte, getter din clasa parinte)
	cout << "Numele produsului promovat este: " << oc2.getproductname() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel setter productname (atribut din clasa parinte, getter din clasa parinte)
	oc2.setproductname("coat");
	cout << "Numele produsului promovat este: " << oc2.getproductname() << endl;
	cout << "-------------------------------------------------------------" << endl;

	OnlineCampaign *oc3 = new Awareness(productname21, wayofadvno21, wayofadv21, advprice21, employeesno21, platformname21, campaignlife21, reach21, 2000);
	oc3->afisare1();
	oc3->advcost();

	//Clasa food
	string productname22 = "milk";
	int manufacturersno22 = 5;
	int idmanufacturers22[20];
	string* manufacturernames22 = new string[manufacturersno22];
	for (int i = 0; i < manufacturersno22; i++) {
		manufacturernames22[i] = "manufacturer " + to_string(i + 1);
		idmanufacturers22[i] = i + 1;
	}
	double price22 = 15;
	bool isonsale22 = 0;
	string expirationdate22 = "11-01-2020";
	bool isbio22 = 1;

	//Apel constructor cu parametri
	Food foo1(productname22, manufacturersno22, idmanufacturers22, manufacturernames22, price22, isonsale22, expirationdate22, isbio22);
	//Apel metoda de afisare
	foo1.afisare1();

	string productname23 = "pistachio";
	int manufacturersno23 = 3;
	int idmanufacturers23[20];
	string* manufacturernames23 = new string[manufacturersno23];
	for (int i = 0; i < manufacturersno23; i++) {
		manufacturernames23[i] = "manufacturer " + to_string(i + 1);
		idmanufacturers23[i] = i + 1;
	}
	double price23 = 40;
	bool isonsale23 = 0;
	string expirationdate23 = "11-05-2020";
	bool isbio23 = 1;

	Food *foo2 = new Food(productname23, manufacturersno23, idmanufacturers23, manufacturernames23, price23, isonsale23, expirationdate23, isbio23);
	foo2->afisare1();

	//Apel constructor de copiere
	Food foo3(foo1);
	foo3.afisare1();

	//Apel getter pantru atributul isbio
	if (foo1.getisbio() == 1)
		cout << "Produsul este bio " << endl;
	else
		cout << "Produsul nu este bio " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel setter pentru atributul isbio
	foo1.setisbio(0);
	if (foo1.getisbio() == 1)
		cout << "Produsul este bio " << endl;
	else
		cout << "Produsul nu este bio " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel getter pentru atributul expirationdate
	cout << "Produsul expira la data de: " << foo1.getexpirationdate() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel setter pentru atributul expirationdate
	foo1.setexpirationdate("20-01-2020");
	cout << "Produsul expira la data de: " << foo1.getexpirationdate() << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel getter pentru atributul isonsale(atribut si getter din clasa parine)
	if (foo1.getisonsale() == 1)
		cout << "Produsul este redus " << endl;
	else
		cout << "Produsul nu este redus " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Apel setter pentru atributul isonsale(atribut si getter din clasa parine)
	foo1.setisonsale(1);
	if (foo1.getisonsale() == 1)
		cout << "Produsul este redus " << endl;
	else
		cout << "Produsul nu este redus " << endl;
	cout << "-------------------------------------------------------------" << endl;


	//UPCASTING
	string productname24 = "honey";
	int wayofadvno22 = 3;
	string* wayofadv22 = new string[wayofadvno22];
	float advprice22[100];
	for (int i = 0; i < wayofadvno22; i++) {
		wayofadv22[i] = "way " + to_string(i + 1);
		advprice22[i] = 100 + i * 20;
	}
	int employeesno22 = 4;
	string platformname22 = "TV";
	int campaignlife22 = 10;
	int reach22 = 5000;
	Awareness a1(productname24, wayofadvno22, wayofadv22, advprice22, employeesno22, platformname22, campaignlife22, reach22, 2000);
	a1.afisare();

	string productname25 = "car";
	int wayofadvno25 = 5;
	string* wayofadv25 = new string[wayofadvno25];
	float advprice25[100];
	for (int i = 0; i < wayofadvno25; i++) {
		wayofadv25[i] = "way " + to_string(i + 1);
		advprice25[i] = 100 + i * 20;
	}
	int employeesno25 = 4;
	string platformname25 = "Podcast";
	int campaignlife25 = 30;
	int reach25 = 20000;
	Awareness a2(productname25, wayofadvno25, wayofadv25, advprice25, employeesno25, platformname25, campaignlife25, reach25, 7000);
	a2.afisare();

	Advertising* advertising[3] = { &oc2, &a1, &a2 };

	//DOWNCASTING
	cout << "Mesajul a ajuns la " << ((Awareness*)advertising[1])->getreach() << " de persoane " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//clasa AdvertisingTeam
	AdverstisingTeam at1(advertising, 3);
	at1.afisare();


	//FAZA 3


	//afisare in fisier text

	ofstream fileWrite;
	fileWrite.open("fisier.txt", ios::out);
	fileWrite << p1;
	fileWrite.close();

	//afisare in fisier binar
	ofstream fileWriteBin;
	fileWriteBin.open("fisier_binar.dat", ios::binary | ios::out);
	fileWriteBin << p1;
	fileWriteBin.close();

	//citire din fisier text
	ifstream fileRead;
	fileRead.open("fisier.txt", ios::in);
	fileRead >> p3;
	cout << "Obiect citit din fisier text: " << endl << p3;
	fileRead.close();

	//citire din fisier binar
	ifstream fileReadBin;
	fileReadBin.open("fisier_binar.dat", ios::binary | ios::in);
	fileReadBin >> p4;
	cout << "Obiect citit din fisier binar: " << endl << p4;
	fileReadBin.close();
	
	//STL

	//STL vector

	vector<string> newProducts;
	newProducts.push_back("honey");
	newProducts.push_back("bread");
	newProducts.push_back("pistachio");

	for (int i = 0; i < newProducts.size(); i++) {
		cout << newProducts[i] << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	sort(newProducts.begin(), newProducts.end());

	//iterator
	cout << "iterator 1" << endl;
	cout << "Produsele ordonate in ordine alfabetica: " << endl;
	vector<string>::iterator it;
	for (it = newProducts.begin(); it != newProducts.end(); it++) {
		cout << *it << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "iterator 2" << endl;
	newProducts.pop_back();
	for (it = newProducts.begin(); it != newProducts.end(); it++) {
		cout << *it << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//STL lista

	list<float> lista;
	lista.push_front(73.25f);
	lista.push_back(10.3f);
	lista.push_front(90.1f);
	lista.push_back(2.2f);

	cout << "Lista contine numerele: " << endl;
	list<float>::iterator it2;
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "Afisarea elementelor listei dupa apel pop_front" << endl;
	lista.pop_front();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "Afisarea elementelor listei dupa apel pop_back" << endl;
	lista.pop_back();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "Afisarea elementelor listei in ordine crescatoare " << endl;
	lista.sort();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "Afisarea elementelor listei in ordine inversa " << endl;
	lista.reverse();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//STL set

	set<string> culori;
	culori.insert("verde");
	culori.insert("albastru");
	culori.insert("gri");
	culori.insert("galben");
	culori.insert("verde");

	cout << "Afisarea culorilor din set" << endl;
	set<string> ::iterator it3;
	for (it3 = culori.begin(); it3 != culori.end(); it3++) {
		cout << *it3 << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	it3 = culori.find("verde");
	if (it3 != culori.end()) {
		cout << "Culoare verde se afla in set" << endl;
	}
	else {
		cout << "Culoarea verde nu se afla in set" << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	//STL map

	string produs[3] = { "honey", "butter", "bread" };
	map<int, string> produse;
	produse.insert(make_pair(20, "honey"));
	produse.insert(make_pair(15, "butter"));
	produse.insert(make_pair(5, "bread"));
	map<int, string>::iterator it4;
	for (it4 = produse.begin(); it4 != produse.end(); it4++) {
		cout << it4->second << " has a price of " << it4->first << endl;
	}
	cout << "-------------------------------------------------------------" << endl;

	cout << "Apel map dupa cheie produse[20] = " << produse[20] << endl;
	cout << "-------------------------------------------------------------" << endl;


	//Meniu

	vector<string> cos;
	int tasta;
	cout << "Meniu" << endl;
	cout << "Doriti sa cumparati fructe de padure?" << endl;
	cout << "0. NU" << endl << "1. DA" << endl;
	cin >> tasta;
	if (tasta == 1) {
		cout << "Alegeti produsul pe care doriti sa il cumparati: " << endl;
		cout << "2. mure" << endl;
		cout << "3. afine" << endl;
		cout << "4. zmeura" << endl;
		cin >> tasta;
		if (tasta == 2) {
			cos.push_back("mure");
		}
		else
			if (tasta == 3) {
				cos.push_back("afine");
			}
			else
				if (tasta == 4) {
					cos.push_back("zmeura");
				}
				else
					cout << "Ati apasat tasta gresita " << endl;
	}

	cout << "5. Afisati produsul cumparat" << endl;
	vector<string>::iterator it5;
	cin >> tasta;
	if (tasta == 5) {
		cout << "Ati cumparat: " << endl;
		for (it5 = cos.begin(); it5 != cos.end(); it5++) {
			cout << *it5 << endl;
		}
	}
	else
		cout << "Ati apasat tasta gresita " << endl;

	return 0;
}