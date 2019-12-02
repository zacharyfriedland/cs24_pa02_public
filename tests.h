//tests.h
//Zachary Friedland
//06-06-19

#ifndef TESTS_H
#define TESTS_H

#include <iostream>
using namespace std;

void runAll();
void test_constructor();
void test_destructor();
void test_assignmentoperator();
void test_copyconstructor();
void test_getTitle();
void test_getRating();
void test_pointers();
void test_insert();
void test_insertEmpty();
void test_insertSingle();
void test_search();
void test_searchTrue();
void test_searchFalse();
void test_searchEmpty();
void test_findDepth();
void test_findDepthRoot();
void test_findDepthMulti();
void test_printPreOrder();
void test_printPreOrderRoot();
void test_printPreOrderMulti();
void test_findPre();
void test_findPreFalse();
void test_findPreTrue();
void test_findPreEmpty();
void test_findMovie();
void test_findMovieFalse();
void test_findMovieTrue();
void test_findMovieEmpty();

void START_TEST(string testname){
	cout << "Start " << testname << endl;
}

void END_TEST(string testname){
	cout << "End " << testname << endl << endl;
}

void assertEquals(string expected, string actual, string test){
	if(expected == actual)
		cout << "PASSED " << endl;
	else
		cout << "FAILED: " << test << endl << " Expected: " << expected << " Actual: " << actual << endl;
}

void assertEquals(bool expected, bool actual, string test){
	if(expected == actual)
		cout << "PASSED " << endl;
	else
		cout << "FAILED: " << test << endl << " Expected: " << expected << " Actual: " << actual << endl;
}

void assertEquals(double expected, double actual, string test){
	if(expected == actual)
		cout << "PASSED " << endl;
	else
		cout << "FAILED: " << test << endl << " Expected: " << expected << " Actual: " << actual << endl;
}

void assertEquals(int expected, int actual, string test){
	if(expected == actual)
		cout << "PASSED " << endl;
	else
		cout << "FAILED: " << test << endl << " Expected: " << expected << " Actual: " << actual << endl;
}

#endif
