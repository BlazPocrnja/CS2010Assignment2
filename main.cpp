#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;
using std::string;

/*
Author : Blaz Pocrnja 
Student ID : 5035473
Assignment #2 
Purpose: Reads a text file, and builds a dictionary of words found in the file. Keeps track of the frequency of words.
*/

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

DICT dictionary;  //your dictionary 
WORD word;        // 
int count[MAX];   //tracks word frequencies

int main (void) {
    int pos;

    while (1) {
       word = GetNextWord();
       if ( 0 == word.length() )  {
           DumpDictionary(dictionary,count);
           break;
       }
       if ((pos = LocateWord(dictionary,word)) >=  0 ) 
           count[pos]++;
       else
           if (!InsertWord(dictionary,word)) cout << "dictionary full " << word << " cannot be added\n";
    }
    return 0;
}

