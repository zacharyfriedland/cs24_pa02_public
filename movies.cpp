//movies.cpp
//Zachary Friedland and Sara Mandic
//06-06-19

#include "movies.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


BST::~BST(){
	clear(root);
}

void BST::clear(Movie* r){
	if(r){
		clear(r->left);
		clear(r->right);
		delete r;
	}
}


void BST::copy(Movie* m){
	if(m){
		insert(*m);
		copy(m->left);
		copy(m->right);
	}
}

BST::BST(BST& source){
	root = nullptr;
	copy(source.root);
}

void BST::operator=(BST& source){
	if(this != &source){
		delete root;
		root = NULL;
		copy(source.root);
	}
}

void BST::printPreOrder(){
	printPreOrder(root);
}

void BST::printPreOrder(Movie* r){
	if(r){
		cout << r->getTitle() << ", " << r->getRating() << ", " << this->findDepth(r->getTitle()) << endl;
		printPreOrder(r->left);
		printPreOrder(r->right);
	}
}


bool BST::insert(Movie m){
	count = 0;
	if(!root){
		root = new Movie(m.getTitle(), m.getRating());
		return true;
	}
	return insertHelper(m, root);
}

bool BST::insertHelper(Movie m, Movie* r){
	count++;
	if(m.getTitle() == r->getTitle())
		return false;
	if(m.getTitle() < r->getTitle()){
		if(r->left)
			return insertHelper(m, r->left);
		else{
			r->left = new Movie(m.getTitle(), m.getRating());
			r->left->parent = r;
			return true;
		}
	}
	else{
		if(r->right)
			return insertHelper(m, r->right);
		else{
			r->right = new Movie(m.getTitle(), m.getRating());
			r->right->parent = r;
			return true;
		}
	}
}

bool BST::search(string t){
	return searchHelper(t, root);
}

bool BST::searchHelper(string t, Movie* r){
	if(r){
		if(r->getTitle() == t)
			return r;
		else{
			if(r->getTitle() > t)
				return searchHelper(t, r->left);
			return searchHelper(t, r->right);
		}
	}
	return false;
}

int BST::findDepth(string t){
	return findDepthHelper(t, root, 0);
}

int BST::findDepthHelper(string t, Movie* r, int level){
	if(!r)
		return 0;
	if(t == r->getTitle())
		return level;
	int nextLevel = findDepthHelper(t, r->left, level+1);
	if(nextLevel!= 0)
		return nextLevel;
	nextLevel = findDepthHelper(t, r->right, level+1);
	return nextLevel;	
} 

vector<Movie> BST::findPre(string t){
	return findPreHelper(t, root);
}

vector<Movie> BST::findPreHelper(string t, Movie* r){
	if(r){
		if(r->getTitle().rfind(t, 0) == 0){
			prefix.push_back(*r);
		}
			findPreHelper(t, r->left);
			findPreHelper(t, r->right);
		
	}
	return prefix;
}

Movie BST::findMovie(string t){
	findPre(t);
	if(prefix.size() > 0){
		Movie max(prefix[0].getTitle(), prefix[0].getRating());
		for(int i = 1; i < prefix.size(); i++){
			if(prefix[i].getRating() > max.getRating()){
				max.setTitle(prefix[i].getTitle());
				max.setRating(prefix[i].getRating());
			}
		}
		return max;
	}
	Movie notFound("prefix not found",0.0);
	return notFound;
}

vector<Movie> BST::getVector() const{
	return prefix;
}
