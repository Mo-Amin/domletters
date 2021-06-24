//Dominant Letter count - Mohamed-Amin Cheaito
//June 2021

#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include<cstring>
#include<vector>
using namespace std;

#define ALPHABETMAX 26

//ASCII code for a is 97 and subtracting lowercase letters ASCII code with 97 provides us with 0-25.
#define ASCIILOWERCASE 97

//Find dominant letter used.
//Maxiumum within alphabet array
int max(int Alphabet [])
{
  int max = Alphabet[0];
  for(int i = 1; i<ALPHABETMAX; ++i)
  {
    if(max < Alphabet[i])
      max = Alphabet[i];
  }
  return max;
}
//Alphabet array holds the alphabetic letters and how much they were used
//temp vector holds what we letters we have used for the occuring word so we reset the letters we have used
//within alphabet array.
void reset(int Alphabet [], vector <int> temp)
{
  for(unsigned int i = 0; i<temp.size(); ++i)
    Alphabet[temp[i]] = 0;
}

int readfile(int Alphabet[])
{
  string temp;
  
  //Store letters within vector
  //We don't know if it is a valid word so we need this as a temp
  //to hold onto the letters
  vector <int> word_check;
  
  //Helps us know where letter is located
  //within our alphabetical array.
  int letter_temp;

  //The dominant letter counts
  int num = 0;

  //Helps determine if we have a proper word or not
  bool flag = true; 
  
  //I couldn't recall how to read text file from standard input So I had to use stack overflow 
  //(https://stackoverflow.com/questions/25985639/passing-text-file-to-standard-input)
  //The two lines below that contain while and if statements with cin, I got that from the
  //above link
  while(cin){
    //Get line and store it in temp string
    if(getline(cin,temp))
    {
      //Go through the line that we just read
      for(unsigned int i = 0;i<temp.size();++i)
      {
        //If we have a alphabetical letter and word
        //that seems alphabetical then enter
        if(isalpha(temp[i]) && flag)
        {
          //If we have an uppercase letter then
          //enter and make sure we lowercase it
          if(isupper(temp[i]))
            temp[i] = tolower(temp[i]);

          //We know where letter is stored within alphabet array
          letter_temp = ( (int) temp[i] ) - ASCIILOWERCASE;

          //We don't know if it is a proper word yet, store in temp
          word_check.push_back(letter_temp);

        }
        else if(temp[i] == ' ')
        {
          //If flag holds true throughout then we
          //know that it is a proper word
          if(flag)
          {
            //Since we know word is valid then we can account for dominant
            //letters
            for(unsigned int j = 0; j<word_check.size(); ++j)
              //Add 1 to the letters that occured within the word
              Alphabet[word_check[j]] +=1;

            //Find dominant letter and add to num
            num += max(Alphabet);

            //Reset letters within alphabet array as we are working
            //with new word possibly
            reset(Alphabet,word_check);
          }
          //We don't have a proper word so reset to account for next word
          else
            flag = true;

          //Clear previous word letter history
          //so we can use for next word.
          word_check.clear();
        }
        //No alphabetical letter, which means it doesn't meet word requriements
        else
          flag = false;
        
      }
      //If we have a word and didn't account for it yet
      //then lets account for it within dominant word count.
      if(flag && !word_check.empty())
      {
            for(unsigned int j = 0; j<word_check.size(); ++j)
              Alphabet[word_check[j]] +=1;
            num += max(Alphabet);
      }
      //Make sure we reset for next word
      reset(Alphabet,word_check);
      word_check.clear();
      flag = true;
      
    }

  }
  //Return dominant word count
  return num;
}
int main()
{
  int Alphabet[ALPHABETMAX];
  for(int i = 0; i<ALPHABETMAX; ++i)
    Alphabet[i] = 0;

  int num = readfile(Alphabet);

  cout<<"Dominant letters Count = "<<num<<endl;
  
  return 0;
}
