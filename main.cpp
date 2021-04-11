#include<iostream>
#include<string>
//#include"Operators.h"

using namespace std;
string indexFilename = "index.txt";
string dataResource = "dataResource.txt";

#include<fstream>
#include<string>
#include<sstream>
#include<iostream>





class Operator{
  
      int getIndex(){
      ifstream indexFile(/*indexFilename.c_str()*/ "index.txt");
      
      if(indexFile.is_open()){
        cout<<"open"<<endl;
      }
      else{cout<<"error\n";}
      
      char ch;
      
      indexFile.get(ch);
      stringstream str;
      str<<ch;
      
      int index;
      str>>index;
      cout<<"Index in getIndex(): "<<index<<endl;
      indexFile.close();
      return index;
      
     /* //indexFile.get(index);
      //stringstream index = index;
      index = (int)index;
      //cout<<"Index in getIndex() method : "<<index<<endl;
      
      indexFile.close();
      return index;*/
        
    }
    
    void incrementIndex(int index){
      ofstream indexFile(/*indexFilename.c_str()*/"index.txt", ios:: trunc);
      indexFile<<++index;
      indexFile.close();
    }
  
    string question;
    string putString;
    
    public:
      
      string indexFilename;
      string dataResource;
      
      /*Operator(string index, string data){
        indexFilename = index;
        dataResource = data;
      }*/
      
    void add(){
      cout<<"Enter question:\n";
      getline(cin, question);
      
      int index = getIndex();
      cout<<"Index in add() after calling getIndex(): \n"<<index<<endl;       
      
      // char index_ = char(index+1);
      
      string index_ = to_string(index+1);cout<<index_<<endl;
      
      putString = index_ + ". " + question +"\n";
      cout<<"String entered is "<<putString;
      incrementIndex(index);
      ofstream targetFile("dataResource.txt", ios::app);
      
      
      if(targetFile.is_open()){
        cout<<"open"<<endl;
      }
      else{cout<<"error\n";}
      
      
      targetFile<<putString;
      targetFile.close();
      
    }
    
};

int main()
{
  Operator op;
  op.add();
  exit (0);
}
