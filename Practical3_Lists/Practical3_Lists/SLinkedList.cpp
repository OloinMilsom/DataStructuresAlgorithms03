// I declare that the work I am submitting for assessing by the Institute examiner(s) is entirely my own
// work, save for any portion(s) thereof where the author or source has been duly referenced and
// attributed.Signed: Niall Milsom (C00179300)”

#include <iostream>
#include "SLinkedList.h"

using namespace std;
    
int main() {

    SLinkedList<int, SListIterator<int>> list;

	// used for testing splice function
	std::list<int> stdList;
	
	// initialise the lists
    list.insertLast(20);
    list.insertLast(10);
	list.insertLast(5);
	stdList.push_back(20);
	stdList.push_back(10);
	stdList.push_back(5);

	// start of slinkedlist
	SListIterator<int> iter = list.begin();
	
	// test insert after
	list.insertAfter(iter, -1);
	iter++;

	// test insert before
	list.insertBefore(iter, -2);

	// test splice
	list.splice(iter, stdList);
	list.splice(list.end(), stdList);

	// test remove
	iter = list.begin();
	list.remove(iter);

	// declare lists for part 3
	std::list<int> dest;
	std::list<int> randList;

	// initialise randlist
	for (int i = 0; i < 20; i++)
	{
		randList.push_back(rand() % 10 + 1);
	}

	// go backwards through the list and find the last occurence of two
	std::list<int>::iterator after2 = (std::find(randList.rbegin(), randList.rend(), 2)).base();

	// go forwards from the last occurence of two and find the next 4
	std::list<int>::iterator before4 = std::find(after2, randList.end(), 4);

	// splice our new list onto the dest list
	dest.splice(dest.begin(), std::list<int>(after2, before4));

	cout << list.size() << endl;
    system("PAUSE");
}

