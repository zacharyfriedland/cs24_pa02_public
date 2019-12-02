//tests.cpp
//Zachary Friedland and Sara Mandic
//06-06-19

#include "tests.h"
#include "movies.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
	runAll();
	return 0;
}

void runAll(){
	 test_constructor();
	 test_destructor();
	 test_copyconstructor();
	 test_assignmentoperator();
	 test_getTitle();
	 test_getRating();
	 test_pointers();
	 test_insert();
	 test_search();
	 test_findDepth();
	 test_printPreOrder();
	 test_findPre();
	 test_findMovie();
}

void test_constructor(){
	START_TEST("test_constructor");
	Movie m("Hola", 4.5);
	cout << "If no errors brought up, constructor works" << endl;
	END_TEST("test_constructor");
}

void test_destructor(){
	START_TEST("test_destructor");
	cout << "run on valgrind and if no memory leaks, works properly" << endl;
	END_TEST("test_destructor");
}

void test_copyconstructor(){
	START_TEST("test_copyconstructor");
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.9);
	BST b1;
	b1.insert(m1);
	b1.insert(m2);
	BST b2(b1);
	cout << "b1: ";  
	b1.printPreOrder(); 
	cout<< endl;
	cout << "b2: ";
	b2.printPreOrder();
	cout<< endl;
	END_TEST("test_copyconstructor");
}

void test_assignmentoperator(){
	START_TEST("test_assignmentoperator");
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.9);
	BST b1;
	b1.insert(m1);
	b1.insert(m2);
	BST b2;
	b2 = b1;
	cout << "b1: ";
	b1.printPreOrder();
	cout << endl;
	cout << "b2: ";
	b2.printPreOrder();
	cout << endl;
	END_TEST("test_assignmentoperator");
}

void test_getTitle(){
	START_TEST("test_getTitle");
	Movie m1("Hola", 4.5);
	assertEquals("Hola", m1.getTitle(), "getTitle()");
	END_TEST("test_getTitle");
}

void test_getRating(){
	START_TEST("test_getRating");
	Movie m1("Hola", 4.5);
	assertEquals(4.5, m1.getRating(), "getRating()");
	END_TEST("test_getRating");
}

void test_pointers(){
	START_TEST("test_pointers");
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.5);
	Movie m3("Josh", 6.6);
	m1.right = &m3;
	m1.left = &m2;
	m2.parent = &m1;
	m3.parent = &m1;
	assertEquals("Josh", m1.right->getTitle(), "right");
	assertEquals("Hello", m1.left->getTitle(), "left");
	assertEquals("Hola", m2.parent->getTitle(), "parent of Hello");
	assertEquals("Hola", m3.parent->getTitle(), "parent of Josh");
	END_TEST("test_pointers");
}

void test_insert(){
	START_TEST("test_insert");
	test_insertEmpty();
	test_insertSingle();
	END_TEST("test_insert");
}

void test_search(){
	START_TEST("test_search");
	test_searchTrue();
	test_searchFalse();
	test_searchEmpty();
	END_TEST("test_search");
}

void test_findDepth(){
	START_TEST("test_findDepth");
	test_findDepthRoot();
	test_findDepthMulti();
	END_TEST("test_findDepth");
}

void test_printPreOrder(){
	START_TEST("test_printPreOrder");
	test_printPreOrderRoot();
	test_printPreOrderMulti();
	END_TEST("test_printPreOrder");
}

void test_findPre(){
	START_TEST("test_findPre");
	test_findPreFalse();
	test_findPreTrue();
	test_findPreEmpty();
	END_TEST("test_findPre");
}

void test_findMovie(){
	START_TEST("test_findMovie");
	test_findMovieFalse();
	test_findMovieTrue();
	test_findMovieEmpty();
	END_TEST("test_findMovie");
}

void test_insertEmpty(){
	BST empty;
	Movie m1("Hola",4.5);
	empty.insert(m1);
	empty.printPreOrder();
}

void test_insertSingle(){
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.9);
	b1.insert(m1);
	b1.insert(m2);
	b1.printPreOrder();
}

void test_searchTrue(){
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.9);
	b1.insert(m1);
	b1.insert(m2);
	assertEquals(true,b1.search("Hola"), "test_true");
}

void test_searchFalse(){
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hello", 5.9);
	b1.insert(m1);
	b1.insert(m2);
	assertEquals(false, b1.search("BYE"), "test_false");
}

void test_searchEmpty(){
	BST b1;
	assertEquals(false, b1.search("Hola"), "test_empty");
}

void test_findDepthRoot(){
	BST b1;
	Movie m1("Hola", 4.5);
	b1.insert(m1);
	assertEquals(0, b1.findDepth("Hola"), "test_rootdepth");
}

void test_findDepthMulti(){
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hi", 3.3);
	Movie m3("C", 2.2);
	Movie m4("Kreen", 5.5);
	Movie m5("Apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	assertEquals(2, b1.findDepth("C"), "test_rootdepth");
}

void test_printPreOrderRoot(){
	BST b1;
	Movie m1("Hola", 4.5);
	b1.insert(m1);
	b1.printPreOrder();
}

void test_printPreOrderMulti(){	
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hi", 3.3);
	Movie m3("C", 2.2);
	Movie m4("Kreen", 5.5);
	Movie m5("Apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	b1.printPreOrder();
}

void test_findPreFalse(){
	BST b1;
	Movie m1("Hola", 4.5);
	Movie m2("Hot", 3.3);
	Movie m3("C", 2.2);
	Movie m4("Hospital", 5.5);
	Movie m5("Apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	string compare = "";
	b1.findPre("ch");
	for(int i = 0; i < b1.getVector().size(); i++){
		compare += (b1.getVector()[i].getTitle() + " ");
	}
	assertEquals("", compare, "test_findPreFalse");
}

void test_findPreTrue(){
	BST b1;
	Movie m1("hola", 4.5);
	Movie m2("hot", 3.3);
	Movie m3("c", 2.2);
	Movie m4("hospital", 5.5);
	Movie m5("apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	string compare = "";
	b1.findPre("ho");
	for(int i = 0; i < b1.getVector().size(); i++){
		compare += (b1.getVector()[i].getTitle() + " ");
	}
	assertEquals("hola hot hospital ", compare, "test_findPreTrue");
}

void test_findMovieFalse(){
	BST b1;
	Movie m1("hola", 4.5);
	Movie m2("hot", 3.3);
	Movie m3("c", 2.2);
	Movie m4("hospital", 5.5);
	Movie m5("apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	assertEquals("prefix not found", b1.findMovie("ch").getTitle(), "test_findMovieFalse");
}

void test_findMovieTrue(){
	BST b1;
	Movie m1("hola", 4.5);
	Movie m2("hot", 3.3);
	Movie m3("c", 2.2);
	Movie m4("hospital", 5.5);
	Movie m5("apple", 2.4);
	b1.insert(m1);
	b1.insert(m2);
	b1.insert(m3);
	b1.insert(m4);
	b1.insert(m5);
	assertEquals("hospital", b1.findMovie("ho").getTitle(), "test_findMovieTrue");
}

void test_findPreEmpty(){
	BST b1;
	b1.findPre("ch");
	string compare = "";
	for(int i = 0; i < b1.getVector().size(); i++){
		compare += (b1.getVector()[i].getTitle() + " ");
	}
	assertEquals("", compare, "test_findPreEmpty");
}


void test_findMovieEmpty(){
	BST b1;
	assertEquals("prefix not found", b1.findMovie("ch").getTitle(), "test_findMovieEmpty");
}


