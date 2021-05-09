#include<iostream>
#include<string>
#include "private.h"
#include<fstream>

using namespace std;

class Operator{
  //Private methods and members

      int getIndex(){
      //Method to get index (count) from the index file

      ifstream indexFile(indexFilename.c_str());
      
      int index;
      indexFile>>index;        //get the index in the form of Integer.
      
      indexFile.close();
      return index;
        
    }
    
    void incrementIndex(){
      ofstream indexFile(indexFilename.c_str(), ios:: trunc);
      indexFile<<++index;
      indexFile.close();             //File opened in truncate mode; the value is updated(replaced) instead of getting added after the previous index. 
    }
  
    string question;
    string putString;
      
    string indexFilename;          //member to store index file path (currently in use after update). 
    string dataResource;           //member to store dataResource file path (currently in use after update). 
      
    int index;

    public:
    Operator(string in, string data): indexFilename(in), dataResource(data){
           index = getIndex();       //get the index value
    }
      
    void add(){

      //Main execution can be considered to start from here..
      cout<<"Enter question:\n";
      std::cin.clear();
      std::cin.ignore(/*std::numeric_limits<std::streamsize>::max(), '\n'*/);
      
      getline(cin, question);           //cin>>question will only take the first word in the input sentence, thus replaced by getline() function. 
          
      string index_ = to_string(index+1); //make a string whose value is (index+1)
                                         //index is the number of questions stored in the dataResource file, thus while adding another question, the index should be incremented.
                                         
      putString = index_ + ". " + question +"\n"; 
                                         //User inputs the question in the form of a sentence; this adds the index number before the question. 
      
      ofstream targetFile(dataResource.c_str(), ios::app);
                                         //Adding the question with index to the resource file in append mode. 
        targetFile<<putString;
        targetFile.close();
      
      incrementIndex();             //increments question count in index file. 
      
      cout<<"\nAdded "<<putString<<endl;
                                         //Confirmation message. 
    }

    void show(){
      cout<<"\nSolved Problems:\n";
      char ch;
      ifstream dataFile(dataResource);
      while (dataFile.get(ch)) {
        cout<<ch;
      }
      
    }

    void count(){
	ifstream indexFile(indexFilename.c_str());                                                                      int index;                                              indexFile>>index;

	cout<<"\nNumber of questions solved: "<<index<<endl<<endl;
    }

    
};
int main()
{
  Operator op(index, data);                           //Self-explanatory stuff..
  int i;
  while(1){
  cout<<"\n////////////////////\n1. Add question\n2. Show Questions\n3.Number of questions Solved\n4. Exit\nEnter your option:";
  cin>>i;
  switch(i){
     case 1: op.add();
	     cout<<"////////////////////\n";
             break;

     case 2: op.show();
	     cout<<"\n////////////////////\n";
             break;
     case 3: op.count();
	     cout<<"////////////////////\n";
	     break;
     case 4: cout<<"////////////////////\n";
	     exit (0);
     default : cout<<"\nInvlaid Option!\n";
	       break;
  }
  }
  exit (0);
}
