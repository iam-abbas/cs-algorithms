#include<iostream>
using namespace std;
class BOOKX {
	private:
		char book_name;
		char book_author;
		int book_price;
		int book_edition;
	public:
		void input() {
			cout<<"Book name:";
			cin>>book_name;
			cout<<endl;
			cout<<"Book author:";
			cin>>book_author;
			cout<<endl;
			cout<<"Book price:";
			cin>>book_price;
			cout<<endl;
			cout<<"book edition:";
			cin>>book_edition;
			cout<<endl;
		}
		void output() {
			cout<<"Book name"<<book_name<<"Author"<<book_author<<"price"<<book_price<<"edition"<<book_edition;
		}
};
int main() {
	BOOKX a;
	a.input();
	a.output();
	return 0;
}
