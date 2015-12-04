// I declare that the work I am submitting for assessing by the Institute examiner(s) is entirely my own
// work, save for any portion(s) thereof where the author or source has been duly referenced and
// attributed.Signed: Niall Milsom (C00179300)”

#include <iostream>
#include "SLinkedList.h"

using namespace std;
    
int main() {

    SLinkedList<int, SListIterator<int>> list;
	std::list<int> stdList;
	
    list.insertLast(20);
    list.insertLast(10);
	list.insertLast(5);
	stdList.push_back(20);
	stdList.push_back(10);
	stdList.push_back(5);
	SListIterator<int> start = list.begin();
	list.insertAfter( start, -1 );
	list.insertBefore(list.end(), -2);
	start++;
	list.splice(start, stdList);
	list.splice(list.end(), stdList);
	start = list.begin();	
	list.remove( start );

	SLinkedList<int, SListIterator<int>> dest;
	std::list<int> randList;
	for (int i = 0; i < 20; i++)
	{
		randList.push_back(rand() % 10 + 1);
	}

	std::list<int>::iterator after2 = (std::find(randList.rbegin(), randList.rend(), 2)).base();
	std::list<int>::iterator before4 = std::find(after2, randList.end(), 4);

	dest.splice(dest.begin(), std::list<int>(after2, before4));

	cout << list.size() << endl;
    system("PAUSE");
}

