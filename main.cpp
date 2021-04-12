#include<iostream>
#include<string>
#include "private.cpp"

using namespace std;

#include<fstream>
#include<string>
#include<sstream>
#include<iostream>




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
    
    void incrementIndex(int index){
      ofstream indexFile(indexFilename.c_str(), ios:: trunc);
      indexFile<<++index;
      indexFile.close();             //File opened in truncate mode; the value is updated(replaced) instead of getting added after the previous index. 
    }
  
    string question;
    string putString;
      
      string indexFilename;          //member file to store index file path (currently not in use). 
      string dataResource;           //member file to store dataResource file path (currently not in use). 
      
    public:
    Operator(string in, string data){

      indexFilename = in;
      dataResource = data;
    }
      
    void add(){

      //Main execution can be considered to start from here..
      cout<<"Enter question:\n";
      getline(cin, question);           //cin>>question will only take the first word in the input sentence, thus replaced by getline function. 
      
      int index = getIndex();           //get the index value
      string index_ = to_string(index+1); //make a string whose value is (index+1)
                                         //In index file, the number of questions Is stored, thus while adding another question, the index should be incremented.
                                         
      putString = index_ + ". " + question +"\n"; 
                                         //User inputs the question in the form ofba sentence; this adds the index number before the question. 
      
      ofstream targetFile(dataResource.c_str(), ios::app);
                                         //Adding the question with index to the resource file in append mode. 
        targetFile<<putString;
        targetFile.close();
      
      incrementIndex(index);             //increments question count in index file. 
      
      cout<<"Added "<<putString<<endl;
                                         //Confirmation message. 
    }
    
};

int main()
{
  Operator op(index, data);                           //Self-explanatory stuff..
  op.add();
  exit (0);
}
