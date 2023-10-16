#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {
	Functions list;
	string ans;
	
	ans = "NULL";

	cout << "\n" <<"1.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.push("Harry Potter");
	list.push("Arsene Lupin");
	list.push("Sherlock Holmes");
	ans = "Sherlock Holmes, Arsene Lupin, Harry Potter";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.mergeSort();
	ans = "Arsene Lupin, Harry Potter, Sherlock Holmes";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.push("1984");
	list.push("Cien años de soledad");
	ans = "Cien años de soledad, 1984, Arsene Lupin, Harry Potter, Sherlock Holmes";
	cout << "\n" <<"4.- esperada " << ans<< "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.mergeSort();
	ans = "1984, Arsene Lupin, Cien años de soledad, Harry Potter, Sherlock Holmes";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	cout << "\n" <<"6.- esperada " << -1 << "\n programa " << list.search("Frankenstein") << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	cout << "\n" <<"7.- esperada " << 5 << "\n programa " << list.search("Sherlock Holmes") << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.deleteBook("Harry Potter");
	ans = "1984, Arsene Lupin, Cien años de soledad, Sherlock Holmes";
	
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
	
	list.deleteBook("Arsene Lupin");
	ans = "1984, Cien años de soledad, Sherlock Holmes";
	
	cout << "\n" <<"9.- esperada " << ans << "\n programa " << list.printList() << "\n";
	cout <<	(!ans.compare(list.printList()) ? "success\n" : "fail\n");
}