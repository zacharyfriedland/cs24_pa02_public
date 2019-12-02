//movies.h
//Zachary Friedland and Sara Mandic
//06-06-19

#ifndef MOVIES_H
#define MOVIES_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;


class Movie{
public: 
	Movie(string t, double r):title(t), rating(r), left(nullptr), right(nullptr), parent(nullptr){}
	string getTitle() const{return title;}
	double getRating() const{return rating;}
	void setTitle(string t){title = t;}
	void setRating(double r){rating = r;}
	Movie* left;
	Movie* right;
	Movie* parent;
private:
	string title;
	double rating;

};


class BST{
public:
	BST():root(nullptr){}
	~BST();
	BST(BST& source);
	void operator=(BST& source);
	bool insert(Movie m);
	bool search(string t);
	vector<Movie> findPre(string t);
	int findDepth(string t);
	Movie findMovie(string t);
	void printPreOrder();
	vector<Movie> getVector() const;
	int count;
private:
	Movie* root;
	vector<Movie> prefix;
	void clear(Movie* r);
	void copy(Movie* m);
	void printPreOrder(Movie* r);
	bool insertHelper(Movie m, Movie* r);
	bool searchHelper(string t, Movie* r);
	vector<Movie> findPreHelper(string t, Movie* r);
	int findDepthHelper(string t, Movie* r, int level);
};



#endif
