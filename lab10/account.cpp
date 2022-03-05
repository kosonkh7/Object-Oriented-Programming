A-2. Listing 14.2
#include <iostream>
#include <string>
#include <vector>
class Account {
public:
	// String representing the name of the account's owner
	std::string name;
	// The account number
	int id;
	// The current account balance
	double balance;
};
// Allows the user to enter via the keyboard information
// about an account and adds that account to the database.
void add_account(std::vector<Account>& accts) {
	std::string name;
	int number;
	double amount;
	std::cout << "Enter name, account number, and account balance: ";
	std::cin >> name >> number >> amount;
	Account acct;
	acct.name = name;
	acct.id = number;
	acct.balance = amount;
	accts.push_back(acct);
}
// Print all the accounts in the database
void print_accounts(const std::vector<Account>& accts) {
	int n = accts.size();
	for (int i = 0; i < n; i++)
		std::cout << accts[i].name << "," << accts[i].id
		<< "," << accts[i].balance << '\n';
}
void swap(Account& er1, Account& er2) {
	Account temp = er1;
	er1 = er2;
	er2 = temp;
}
bool less_than_by_name(const Account& e1, const Account& e2) {
	return e1.name < e2.name;
}
bool less_than_by_id(const Account& e1, const Account& e2) {
	return e1.id < e2.id;
}
bool less_than_by_balance(const Account& e1, const Account& e2) {
	return e1.balance < e2.balance;
}
// Sorts a bank account database into ascending order
// The comp parameter determines the ordering
void sort(std::vector<Account>& db,
	bool (*comp)(const Account&, const Account&)) {
	int size = db.size();
	for (int i = 0; i < size - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < size; j++)
			if (comp(db[j], db[smallest]))
				smallest = j;
		if (smallest != i)
			swap(db[i], db[smallest]);
	}
}
// Allows a user interact with a bank account database.
int main() {
	// The simple database of bank accounts
	std::vector<Account> customers;
	// User command
	char cmd;
	// Are we done yet?
	bool done = false;
	do {
		std::cout << "[A]dd [N]ame [I]D [B]alance [Q]uit==> ";
		std::cin >> cmd;
		switch (cmd) {
		case 'A':
		case 'a':
			// Add an account
			add_account(customers);
			break;
		case 'P':
		case 'p':
			// Print customer database
			print_accounts(customers);
			break;
		case 'N':
		case 'n':
			// Sort database by name
			sort(customers, less_than_by_name);
			print_accounts(customers);
			break;
		case 'I':
		case 'i':
			// Sort database by ID (account number)
			sort(customers, less_than_by_id);
			print_accounts(customers);
			break;
		case 'B':
		case 'b':
			// Sort database by account balance
			sort(customers, less_than_by_balance);
			print_accounts(customers);
			break;
		case 'Q':
		case 'q':
			done = true;
			break;
		}
	} while (!done);
}


/*
메인 함수를 보면 Account 클래스로 벡터 하나 만든 뒤 스위치문을 작동한다.
스위치문은 기능에 따라 함수들을 불러와 실행하는데
케이스 a는 add_account함수 사용
add_account함수는 데이터를 입력 받아 새로운 계좌를 추가하는 기능이다
케이스 p는 print_accounts함수 사용
print_accounts함수는 반복문을 통해 클래스 내 모든 계좌 정보를 출력하는 기능이다
케이스 n은 이름순으로 정렬한 뒤 print_accounts함수를 사용하여 출력하는 기능이다 
케이스 i는 id순으로 정렬한 뒤 print_accounts함수를 사용하여 출력하는 기능이다.
케이스 b는 balance순으로 정렬한 뒤 print_accounts함수를 사용하여 출력하는 기능이다.
케이스 q는 스위치문을 종료해준다.
*/
