#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std:: vector;

#define MAX 100

typedef int BOOL;
typedef string WORD;
typedef WORD DICT[MAX];

int LocateWord(DICT, WORD);
BOOL FullDictionary(DICT);
BOOL InsertWord(DICT,WORD);
WORD GetNextWord(void);
void DumpDictionary(DICT ,int[]);

int numfilled;
extern int count[MAX];

BOOL InsertWord(DICT dict, WORD word)
{
/* 
  adds word to dictionary , if word can't be added returns 0 else returns 1
*/
	if (!FullDictionary(dict)){
		dict[numfilled] = word;
                count[numfilled] = 1;
		numfilled++;
		return 1;
	}
	return 0;
}

void DumpDictionary(DICT dict, int count[]) {
/* 
  will sort the dictionary, and display the contents
*/
	int min, freqtmp;
	WORD temp;
	for (int i=0; i < numfilled-1; i++){
		min = i;
    		for (int j=i+1; j < numfilled; j++){
			if(dict[j] < dict[min]){
				min = j;
			}
		}
		if (min != i){
			temp = dict[i];
			freqtmp = count[i];
			dict[i] = dict[min];
			count[i] = count[min];
			dict[min] = temp;
			count[min] = freqtmp;
		}
	}
		
	WORD maxprnt;
	int omittedchars;
	cout << "Word				Frequency" << endl; 
	cout << "-------------------------------------" << endl;
	for (int i = 0; i < numfilled; i++){
		if(dict[i].length() > 20){
			maxprnt = dict[i].substr(0, 20);
			omittedchars = dict[i].length() - maxprnt.length();
			cout << maxprnt << "(" << omittedchars << ") " << "		" << count[i] << endl;
		}
		else {
			cout << dict[i] << "					" << count[i] << endl;
		}

	}
}

WORD GetNextWord(void){
/* 
   will retrieve next word in input stream. Word is defined just as in assignment #1 
   returns WORD or ""(null string) if no more words in input stream
*/
	char ch;
	WORD s;

	while(cin.good()){
		ch = cin.get();
		if (isalpha(ch)){
			s.push_back(tolower(ch));
			
		}
		else if (ch == ' ' || ch == '\n' ){
			if(s.size() != 0){
				return s;
			}
			
		}
	}

	return s; 
}

BOOL FullDictionary(DICT dict) {
/* 
   if dictionary is full, return 1 else 0 
 */

	if (numfilled == MAX){
		return 1;
	}
	return 0;
}

int LocateWord(DICT dict, WORD word) {
/*
   will determine if dictionary contains word. if found, returns position else returns value < 0
*/
	for(int i = 0; i < numfilled; i++){
                //cout << i << "  " << numfilled << " " << dict[i] << " " << word << endl;
		if (dict[i] ==  word){
			return i;
		}
	}
	return -1;	
}
