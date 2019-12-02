#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <ctime>
#include <algorithm>
#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
  if(argc < 4){
    cerr << "Usage: " << argv[ 0 ] << "arg1 arg2 arg3" << endl;
    exit(1);
  }

  bool flag = false;
  if(strcmp(argv[1], "true") == 0){
    flag = true;
  } else if(strcmp(argv[1], "false") == 0) {
    flag = false;
  } else {
    cerr << "Argument 1 must be a boolean (true/false)" << endl;
    exit(1);
  }
  
  ifstream movieFile (argv[2]);
  string preFix = argv[3];
  string line, movieName;
  double movieRating;

  if (movieFile.fail()){
    cerr << "Could not open file " << argv[1];
    exit(1);
  }

  // Create an objects of the BST class you defined 
  // to contain the name and rating in the input file
	BST b;
  // Read each file and store the name and rating
	vector<string> v;
	int nodeNumber = 1;
	while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
    // Use std::string movieName and double movieRating
    // to construct your Movie objects
    	Movie m(movieName, movieRating);
	b.insert(m);
	cout << "Number of Nodes: " << nodeNumber << " Nodes Visited: " << b.count << endl;
	nodeNumber++;
	v.push_back(m.getTitle());
	//push into vector, use search function at v[i], make 2 for loops, time total and take average.
	  //cout << movieName << " has rating " << movieRating << endl;
  }
  movieFile.close();
  if(flag){  
  b.printPreOrder();
  //cout << endl << "Best movie is the " << b.findMovie(preFix);
  string name = b.findMovie(preFix).getTitle();
  double rating = b.findMovie(preFix).getRating();
  if(b.findMovie(preFix).getTitle() == "prefix not found"){
	  cout<<endl;
	  return 0;
  }
  cout << endl << "Best movie is " << name << " with rating " << rating << endl;
  }

  if(flag == false){
	  cout << endl << "Runtime (microseconds):" << endl;
	  clock_t t;
	  for(int i = 0; i < atoi(argv[3]); i++){
		  t = clock();
		  for(int j = 0; j < v.size(); j++){
			  b.search(v[j]);
		  }
		  t = clock() - t;
		cout << t*1000000.0/CLOCKS_PER_SEC << endl;
  	  }
  }
 return 0;
}

bool parseLine(string &line, string &movieName, double &movieRating) {
  if(line.length() <= 0) return false;
  string tempRating = "";
  bool flag = false;
  movieName = tempRating = "", movieRating = 0.0, flag = false;
  for (int i = 0; i < line.length(); i++){
    if(flag) tempRating += line[i];
    else if(line[i]==','&& line[0]!='"') flag = true;
    else {
	    if(i==0 && line[0] == '"') continue;
	    if(line[i] == '"'){i++; flag = true; continue;}
	    movieName+=line[i];
    }
   }
  movieRating = stod(tempRating);
  return true;
}

/*int main(){
	Movie x("predecess", 5.6);
	Movie y("profound" , 9.9);
	Movie z("a", 4.4);
	Movie a("b", 1.1);
	Movie f("progress",3.2);
	Movie c("f",4.4);
	BST b;
	b.insert(x);
	b.insert(y);
	b.insert(z);
	b.insert(a);
	b.insert(f);
	b.insert(c);
	//cout << &x << " " << (x.right) << " " << &f << " " << f.parent;
	b.findPre("pr");
	for(int i = 0; i < b.getVector().size(); i++){
		cout << b.getVector()[i].getTitle() << " " << b.getVector()[i].getRating() << endl;
	}
	cout << b.findMovie("ch");
}*/
