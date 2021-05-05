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
      
      cout<<"Added "<<putString<<endl;
                                         //Confirmation message. 
    }

    void show(){
      cout<<"Solved Problems:\n";
      char ch;
      ifstream dataFile(dataResource);
      while (dataFile.get(ch)) {
        cout<<ch;
      }
    }
    
};

int main()
{
  Operator op(index, data);                           //Self-explanatory stuff..
  int i;

  cout<<"1. Add question\n2. Show Questions\nEnter your option:"
  switch(i){
     case: 1{op.add();break;}

     case: 2{op.show;break;}
  }
  exit (0);
}
