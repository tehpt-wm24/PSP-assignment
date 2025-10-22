#include <iostream>
#include <iomanip>
#include <string>
#include<cctype>
#include <limits>
using namespace std;

// function prototypes
char mainMenu();
void Logo();
void menu();
void customerNo(int cust_no);
void orderNo(int order_no);
char selectMenuItem();
int getQuantity();
void afterChoose();
double getOrderAmount();
char getDeliveryOption();
void invoiceSummary();
void invoice();
char paymentMethod();
void cashMethod(char method);
void creditCMethod(char method);
void debitCMethod(char method);
void orderSummary();
double receipt(char method);
void totalItem();
void totalmethod();
void report(double moneyReceived);


const double serChargeRate = 0.07, taxRate = 0.06;

const int price1 = 10, price2 = 25, price3 = 7, price4 = 4, price5 = 6, price6 = 5, price7 = 2, price8 = 12;


int burger = 0, pizza = 0, friedChicken = 0, frenchFries = 0, nugget = 0, beverage = 0, iceCream = 0, wrap = 0, // for quantity use
rburger = 0, rpizza = 0, rfriedChicken = 0, rfrenchFries = 0, rnugget = 0, rbeverage = 0, riceCream = 0, rwrap = 0, // for report use
byCash = 0, byEWallet = 0, byCreditCard = 0, byDebitCard = 0; // for report use

double Tprice1 = 0, Tprice2 = 0, Tprice3 = 0, Tprice4 = 0, Tprice5 = 0, Tprice6 = 0, Tprice7 = 0, Tprice8 = 0,
totalAmount = 0, subtotal = 0, serCharge = 0, tax = 0, deliveryFee = 0, payable = 0, amount = 0, change = 0, moneyReceived = 0;

char deliveryChoice;

string item1 = "Burger", item2 = "Pizza", item3 = "Fried Chicken", item4 = "French Fries",
item5 = "Nugget", item6 = "Beverage", item7 = "Ice Cream", item8 = "Wrap";

char mainMenu() {
	char menuChoose;
	cout << endl;
	cout << "Please select (1/2/3)" << endl;
	cout << "1.Order Menu\n";
	cout << "2.Reporting\n";
	cout << "3.Exit\n";
	cout << "---->";
	cin >> menuChoose;
	return menuChoose;
}

void Logo() {
	cout << "\t ___________                __ ___________                     __      ________      .__.__  .__    " << endl;
	cout << "\t \\_   _____/____    _______/  |\\_   _____/___ _____    _______/  |_   /  _____/______|__|  | |  |   " << endl;
	cout << "\t  |    __) \\__  \\  /  ___/\\   __\\    __)/ __ \\\\__  \\  /  ___/\\   __\\ /   \\  __\\_  __ \\  |  | |  |   " << endl;
	cout << "\t  |     \\   / __ \\_\\___ \\  |  | |     \\   ___/ / __ \\_\\___ \\  |  |   \\    \\_\\  \\  | \\/  |  |_|  |__ " << endl;
	cout << "\t  \\___  /  (____  /____  > |__| \\___  / \\___  >____  /____  > |__|    \\______  /__|  |__|____/____/ " << endl;
	cout << "\t      \\/        \\/     \\/           \\/      \\/     \\/     \\/                 \\/                      " << endl;
	cout << "\t\t\t\t\t\tWelcome to FastFeast Grill" << endl;
}

void menu() {
	cout << endl;
	cout << "    |------------------------------------------------|" << endl;
	cout << "    |NO |             MENU                 |  PRICE  |" << endl;
	cout << "    |---+----------------------------------+---------|" << endl;
	cout << "    | 1 |      Burger                      | RM 10   |" << endl;
	cout << "    | 2 |      Pizza                       | RM 25   |" << endl;
	cout << "    | 3 |      Fried Chicken               | RM  7   |" << endl;
	cout << "    | 4 |      French Fries                | RM  4   |" << endl;
	cout << "    | 5 |      Nugget                      | RM  6   |" << endl;
	cout << "    | 6 |      Beverage                    | RM  5   |" << endl;
	cout << "    | 7 |      Ice Cream                   | RM  2   |" << endl;
	cout << "    | 8 |      Wrap                        | RM 12   |" << endl;
	cout << "    |------------------------------------------------|" << endl;
	cout << endl;
}

void customerNo(int custNum) {
	cout << "Customer : " << custNum << "\t\t\t\t" << __DATE__ << endl;
}
void orderNo(int orderNum) {
	cout << "ORDER    : " << orderNum << "\t\t\t\t" << __TIME__ << endl << endl;
}

char selectMenuItem() {
	char selectedItem;
	do {
		cout << "What food you want to purchase (1-8) > ";
		cin >> selectedItem;
		if (selectedItem < '1' || selectedItem > '8') {
			cout << "\nInvalid choice, please select between 1 and 8 " << endl;
		}
	} while (selectedItem < '1' || selectedItem > '8');
	return selectedItem;
}

int getQuantity() {
	int quantity = 0;
	do {
		cout << "\nEnter the quantity that you want to purchase > ";
		if (cin >> quantity) {
			if (quantity < 1) {
				cout << "\nInvalid quantity, please re-enter " << endl;
			}
			else {
				break;
			}
		}
		else {
			cout << "\nInvalid input.Please enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
	} while (true);
	return quantity;
}

double getOrderAmount() {
	char selectedItem;
	int quantity = 0;
	menu();

	selectedItem = selectMenuItem();
	quantity = getQuantity();
	switch (selectedItem) {
	case '1':
		burger += quantity; // store quantity into burger(another variable)( for cal. use)
		rburger += quantity; // store quantity into rburger(another variable)( for report use)
		Tprice1 = 10 * burger;
		break;
	case '2':
		pizza += quantity;
		rpizza += quantity;
		Tprice2 = 25 * pizza;
		break;
	case '3':
		friedChicken += quantity;
		rfriedChicken += quantity;
		Tprice3 = 7 * friedChicken;
		break;
	case '4':
		frenchFries += quantity;
		rfrenchFries += quantity;
		Tprice4 = 4 * frenchFries;
		break;
	case '5':
		nugget += quantity;
		rnugget += quantity;
		Tprice5 = 6 * nugget;
		break;
	case '6':
		beverage += quantity;
		rbeverage += quantity;
		Tprice6 = 5 * beverage;
		break;
	case '7':
		iceCream += quantity;
		riceCream += quantity;
		Tprice7 = 2 * iceCream;
		break;
	case '8':
		wrap += quantity;
		rwrap += quantity;
		Tprice8 = 12 * wrap;
		break;
	default:
		cout << "Invalid input, Please enter 1 - 8 to choose your food..." << endl;
	}
	totalAmount = Tprice1 + Tprice2 + Tprice3 + Tprice4 + Tprice5 + Tprice6 + Tprice7 + Tprice8;
	return totalAmount;
}

char getDeliveryOption() {
	do {
		cout << "Do you want the food delivered? Delivery Fee (RM5)" << endl;
		cout << "(Y / N) > ";
		cin >> deliveryChoice;
		if (deliveryChoice != 'Y' && deliveryChoice != 'y' && deliveryChoice != 'N' && deliveryChoice != 'n') {
			cout << "\nInvalid Input, please re-enter..." << endl;

		}
	} while (deliveryChoice != 'Y' && deliveryChoice != 'y' && deliveryChoice != 'N' && deliveryChoice != 'n');
	return deliveryChoice;
}
void invoiceSummary() {
	int numbering = 1;
	if (Tprice1 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item1 << "-->" << setw(8) << burger << " x " << setw(4) << "RM" << price1 << setw(18) << "RM" << Tprice1 << endl;
	}
	if (Tprice2 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item2 << "-->" << setw(8) << pizza << " x " << setw(4) << "RM" << price2 << setw(18) << "RM" << Tprice2 << endl;
	}
	if (Tprice3 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item3 << "-->" << setw(8) << friedChicken << " x " << setw(4) << "RM" << price3 << setw(19) << "RM" << Tprice3 << endl;
	}
	if (Tprice4 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item4 << "-->" << setw(8) << frenchFries << " x " << setw(4) << "RM" << price4 << setw(19) << "RM" << Tprice4 << endl;
	}
	if (Tprice5 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item5 << "-->" << setw(8) << nugget << " x " << setw(4) << "RM" << price5 << setw(19) << "RM" << Tprice5 << endl;
	}
	if (Tprice6 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item6 << "-->" << setw(8) << beverage << " x " << setw(4) << "RM" << price6 << setw(19) << "RM" << Tprice6 << endl;
	}
	if (Tprice7 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item7 << "-->" << setw(8) << iceCream << " x " << setw(4) << "RM" << price7 << setw(19) << "RM" << Tprice7 << endl;
	}
	if (Tprice8 > 0) {
		cout << setw(20) << numbering++ << ". " << setw(14) << item8 << "-->" << setw(8) << wrap << " x " << setw(4) << "RM" << price8 << setw(18) << "RM" << Tprice8 << endl;
	}
}
void invoice() {
	int  invoiceNo = 1;
	cout << "Invoice : " << endl;
	cout << setw(65) << "FastFeast Grill System" << endl;
	cout << setw(70) << "======================\t\t\t\t\t" << endl;
	cout << setw(71) << "Tel: 012-3456789    \t\t\t\t\t" << endl;
	cout << setw(40) << "Invoice No : " << invoiceNo << setw(40) << __DATE__ << endl;
	invoiceNo++;
	invoiceSummary();
	subtotal = totalAmount;
	serCharge = serChargeRate * subtotal;
	tax = taxRate * subtotal;
	if (deliveryChoice == 'Y' || deliveryChoice == 'y') {
		deliveryFee += 5.0;
	}
	else {
		deliveryFee += 0.0;
	}
	payable = subtotal + tax + serCharge + deliveryFee;
	cout << setw(81) << "=============" << endl;

	cout << setw(40) << "Subtotal : " << setw(34) << "RM" << subtotal << endl;
	cout << setw(40) << "Service charge (7%) : " << setw(34) << "RM" << fixed << setprecision(2) << serCharge << endl;
	cout << setw(40) << "Tax (6%) : " << setw(34) << "RM" << fixed << setprecision(2) << tax << endl;

	if (deliveryChoice == 'Y' || deliveryChoice == 'y') {
		cout << setw(39) << "Delivery Fee :" << setw(35) << "RM" << deliveryFee << endl;
	}
	else {

		cout << setw(39) << "Delivery Fee :" << setw(35) << "RM" << deliveryFee << endl;
	}

	cout << setw(81) << "=============" << endl;
	cout << setw(40) << "Total Payable : " << setw(34) << setprecision(2) << "RM" << payable << endl;
}

char paymentMethod() {
	char method;
	do {
		cout << "A. Cash \n";
		cout << "B. TNG eWallet \n";
		cout << "C. Credit Card \n";
		cout << "D. Debit Card \n";
		cout << "Please select your payment method (A , B , C , D ) > ";
		cin >> method;
		if (method != 'A' && method != 'a' && method != 'B' && method != 'b' && method != 'C' && method != 'c' &&
			method != 'D' && method != 'd') {
			cout << "\nInvalid Input, please re-enter..." << endl;
		}
	} while (method != 'A' && method != 'a' && method != 'B' && method != 'b' && method != 'C' && method != 'c' &&
		method != 'D' && method != 'd');

	return method;
}


void cashMethod(char method) {
	// check amount and change
	do {
		cout << setw(42) << "Payment Amount : RM";
		if (cin >> amount) {

			if (amount < payable) {
				cout << "Amount Received is Too Less, Please enter amount > " << "RM" << payable << endl;
			}
			else {
				break;
			}
		}
		else {
			cout << "\nInvalid input.Please enter a number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (true);
	change = amount - payable;

}
void creditCMethod(char method) {
	int  i;
	string cardNum, cardName, month, year;
	bool valid;

	do {
		cout << "Card Number : " << endl;
		cout << "Please Enter 16 Digits only Without Spaces : ";
		cin >> cardNum;
		valid = true;

		if (cardNum.length() != 16) {
			cout << "\nInvalid card number, re-enter...." << endl;
			valid = false;
		}
		else {
			for (i = 0; i < cardNum.length(); i++) {
				if (!isdigit(cardNum[i])) {
					cout << "Please enter number only." << endl;
					valid = false;
					break;
				}
			}
		}
	} while (!valid);


	do {
		string cardName;
		cout << "Name on Card: ";
		cin.get();
		getline(cin, cardName);

		valid = true;

		for (int i = 0; i < cardName.length(); i++) {
			if (!isalpha(cardName[i]) && cardName[i] != ' ') {
				cout << "Invalid name. Please enter letters and spaces only." << endl;
				valid = false;
				break;
			}
		}
		if (!valid) {
			cout << "Please try again." << endl;
		}

	} while (!valid);


	do {
		cout << "Expiry Date (MM/YY): " << endl;
		cout << "month : ";
		cin >> month;
		cout << "year : ";
		cin >> year;
		valid = true;

		// Validate month (should be between 01 and 12)
		if (month.length() != 2 || stoi(month) < 1 || stoi(month) > 12) {
			cout << "\nInvalid month. Please enter the correct month (01-12)." << endl;
			valid = false;
		}

		// Validate year (optional: should be a reasonable future year)
		if (year.length() != 2) {
			cout << "\nInvalid year. Please enter the last two digits of the year." << endl;
			valid = false;
		}
	} while (!valid);


}

void debitCMethod(char method) {
	int  i;
	string cardNum, cardName, month, year;
	bool valid;

	do {
		cout << "Card Number : " << endl;
		cout << "Please Enter 16 Digits only Without Spaces : ";
		cin >> cardNum;
		valid = true;

		if (cardNum.length() != 16) {
			cout << "\nInvalid card number, re-enter...." << endl;
			valid = false;
		}
		else {
			for (i = 0; i < cardNum.length(); i++) {
				if (!isdigit(cardNum[i])) {
					cout << "Please enter number only." << endl;
					valid = false;
					break;
				}
			}
		}
	} while (!valid);

	do {
		string cardName;
		cout << "Name on Card: ";
		cin.get();
		getline(cin, cardName);

		valid = true;

		for (int i = 0; i < cardName.length(); i++) {
			if (!isalpha(cardName[i]) && cardName[i] != ' ') {
				cout << "Invalid name. Please enter letters and spaces only." << endl;
				valid = false;
				break;
			}
		}
		if (!valid) {
			cout << "Please try again." << endl;
		}

	} while (!valid);


	do {
		cout << "Expiry Date (MM/YY): " << endl;
		cout << "month : ";
		cin >> month;
		cout << "year : ";
		cin >> year;
		valid = true;

		// Validate month (should be between 01 and 12)
		if (month.length() != 2 || stoi(month) < 1 || stoi(month) > 12) {
			cout << "\nInvalid month. Please enter the correct month (01-12)." << endl;
			valid = false;
		}

		// Validate year (optional: should be a reasonable future year)
		if (year.length() != 2) {
			cout << "\nInvalid year. Please enter the last two digits of the year." << endl;
			valid = false;
		}
	} while (!valid);

}
void orderSummary() {
	int numbering = 1;
	cout << "Receipt : " << endl;
	cout << setw(65) << "FastFeast Grill System" << endl;
	cout << setw(70) << "======================\t\t\t\t\t" << endl;
	cout << setw(71) << "Tel: 012-3456789    \t\t\t\t\t" << endl;
	cout << setw(40) << "Receipt : " << setw(40) << __DATE__ << endl;

	invoiceSummary();

	cout << setw(81) << "=============" << endl;
	cout << setw(40) << "Subtotal : " << setw(34) << "RM" << subtotal << endl;
	cout << setw(40) << "Service Charge (7%) : " << setw(34) << "RM" << fixed << setprecision(2) << serCharge << endl;
	cout << setw(40) << "Tax (6%) : " << setw(34) << "RM" << fixed << setprecision(2) << tax << endl;
	cout << setw(39) << "Delivery Fee :" << setw(35) << "RM" << deliveryFee << endl;
	cout << setw(81) << "=============" << endl;
	cout << setw(40) << "Total Payable : " << setw(34) << fixed << setprecision(2) << "RM" << payable << endl;
}

double receipt(char method) {
	int numbering = 1;

	switch (method) {
	case 'A':
	case 'a':
		// pay by cash
		cout << setw(44) << "Payment Method : Cash" << endl;
		cashMethod(method);
		system("cls");
		orderSummary();
		cout << setw(41) << "Amount Received : RM" << setw(6) << fixed << setprecision(2) << amount << endl;
		cout << setw(42) << "Change : RM" << setw(5) << fixed << setprecision(2) << change << endl;
		byCash++;
		break;
	case 'B':
	case 'b':
		// TNG eWallet
		system("cls");
		orderSummary();
		cout << setw(51) << "Payment Method : TNG eWallet" << endl;
		byEWallet++;
		break;
	case 'C':
	case 'c':
		// credit card
		cout << setw(51) << "Payment Method : Credit Card" << endl;
		creditCMethod(method);
		system("cls");
		orderSummary();
		cout << setw(51) << "Payment Method : Credit Card" << endl;
		byCreditCard++;
		break;
	case 'D':
	case 'd':
		//debit card
		cout << setw(50) << "Payment Method : Debit Card" << endl;
		debitCMethod(method);
		system("cls");
		orderSummary();
		cout << setw(50) << "Payment Method : Debit Card" << endl;
		byDebitCard++;
		break;
	}

	moneyReceived += payable;
	return moneyReceived;
}


void afterChoose() {
	int cust_no = 1, order_no = 1, method;
	char add, nextCus, deliveryOption;
	do {
		do {
			cout << endl;
			customerNo(cust_no);
			orderNo(order_no);
			getOrderAmount();
			do {
				cout << "\nAny Item to Add ? (Y/N) > ";
				cin >> add;
				if (add != 'Y' && add != 'y' && add != 'N' && add != 'n') {
					cout << "\nInvalid input, please re-enter..." << endl;
				}

			} while (add != 'Y' && add != 'y' && add != 'N' && add != 'n');
			if (add == 'y' || add == 'Y') {
				order_no++;
			}
		} while (add == 'y' || add == 'Y');
		cout << endl;
		deliveryOption = getDeliveryOption();
		system("cls");
		invoice();
		cout << endl;
		method = paymentMethod();
		receipt(method);
		do {
			cout << "Continue to Next Customer? (Y/N) -->";
			cin >> nextCus;

			if (nextCus != 'Y' && nextCus != 'y' && nextCus != 'N' && nextCus != 'n') {
				cout << "\nInvalid input, please re-enter..." << endl;
			}

		} while (nextCus != 'Y' && nextCus != 'y' && nextCus != 'N' && nextCus != 'n');

		if (nextCus == 'Y' || nextCus == 'y') {
			system("cls");
			order_no = 0;
			cust_no++, order_no++;
			Tprice1 = 0, Tprice2 = 0, Tprice3 = 0, Tprice4 = 0, Tprice5 = 0, Tprice6 = 0, Tprice7 = 0, Tprice8 = 0,
				burger = 0, pizza = 0, friedChicken = 0, frenchFries = 0, nugget = 0, beverage = 0, iceCream = 0, wrap = 0,

				totalAmount = 0, subtotal = 0, deliveryFee = 0;
		}
		else if (nextCus == 'N' || nextCus == 'n') {
			system("cls");
		}
	} while (nextCus == 'Y' || nextCus == 'y');
}
void totalItem() {
	cout << endl;
	cout << "Total Burger Sold        : " << rburger << endl;
	cout << "Total Pizza Sold         : " << rpizza << endl;
	cout << "Total Fried Chicken Sold : " << rfriedChicken << endl;
	cout << "Total French Fries Sold  : " << rfrenchFries << endl;
	cout << "Total Nugget Sold        : " << rnugget << endl;
	cout << "Total Beverage Sold      : " << rbeverage << endl;
	cout << "Total Ice-Cream Sold     : " << riceCream << endl;
	cout << "Total Wrap Sold          : " << rwrap << endl;
}
void totalmethod() {
	cout << endl;
	cout << "Payment Method Use --> " << endl;
	cout << "Pay by Cash        : " << byCash << endl;
	cout << "Pay by TNG eWallet : " << byEWallet << endl;
	cout << "Pay by Credit Card : " << byCreditCard << endl;
	cout << "Pay by Debit Card  : " << byDebitCard << endl;
	cout << endl;
}
void report(double moneyReceived) {


	cout << "\n\n\nFastFeast Grill System" << endl;
	cout << "-----------------------\n" << endl;
	cout << " DAILY SALES REPORT " << endl;
	cout << "Total Sales Amount is : RM" << setprecision(2) << moneyReceived << endl;
	totalItem();
	totalmethod();
}


int main() {
	char menuChoose;
	do {

		Logo();
		menuChoose = mainMenu();
		switch (menuChoose) {
		case '1': {
			system("cls");
			afterChoose();
			break;
		}
		case '2':
			system("cls");
			report(moneyReceived);

			break;

		case '3':
			cout << "EXIT \n" << "Thank You For Using Our System!!!" << endl << endl;
			break;

		default:
			cout << "Invalid input, Please choose again..." << endl << endl;
		}

	} while (menuChoose != '3');
	return 0;
}