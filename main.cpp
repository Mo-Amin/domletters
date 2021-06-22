#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<cstring>
#include<vector>
using namespace std;
#define ALPHABETMAX 26
#define ASCIILOWERCASE 97
/*
void readfile(string src, int Alphabet[])
{
  string temp;

  //vector <int> word_check;

  int letter_temp;
  ifstream infile;

  infile.open(src);

  if(infile){
    while(getline(infile,temp))
    {
      //cout<<temp;
      for(unsigned int i = 0;i<temp.size();++i)
      {
        if(isupper(temp[i]))
          temp[i] = tolower(temp[i]);
        letter_temp = ( (int) temp[i] ) - ASCIILOWERCASE;

        if(letter_temp >= 0 && letter_temp < ALPHABETMAX)
          Alphabet[letter_temp] += 1;
        
      }
    }

    infile.close();

  }


}
*/

void readfile(string src, int Alphabet[])
{
  string temp;

  vector <int> word_check;

  int letter_temp;

  bool flag = true; //Keep track of space

  ifstream infile;

  infile.open(src);

  if(infile){
    while(getline(infile,temp))
    {
      for(unsigned int i = 0;i<temp.size();++i)
      {
        if(isalpha(temp[i]) && flag)
        {
          if(isupper(temp[i]))
            temp[i] = tolower(temp[i]);
          letter_temp = ( (int) temp[i] ) - ASCIILOWERCASE;
          word_check.push_back(letter_temp);

        }
        else if(temp[i] == ' ')
        {
          if(flag)
          {
            for(unsigned int j = 0; j<word_check.size(); ++j)
              Alphabet[word_check[j]] +=1;
          }
          else
            flag = true;

          word_check.clear();
        }
        else
          flag = false;
        
      }
    }

    infile.close();

  }


}


int main(int argc, char ** argv)
{
  int Alphabet[ALPHABETMAX];
  for(int i = 0; i<ALPHABETMAX; ++i)
    Alphabet[i] = 0;

  readfile(argv[1], Alphabet);

  int max = Alphabet[0];
  for(int i = 1; i<ALPHABETMAX; ++i)
  {
    if(max < Alphabet[i])
      max = Alphabet[i];
  }

  cout<<"MAX = "<<max<<endl;
  
  return 0;
}
