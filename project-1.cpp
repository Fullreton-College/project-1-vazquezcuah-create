#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void orgWords(vector<string> &words, ifstream &file);
 //gets words and organizes into vector words<>. Calls WordOnly()

void wordOnly(string &word);
//removes punctuation and lowercases the whole word to avoid comparison issues. 

void freq(vector<pair<string,int>> &freq, vector<string> words);
//counts word frequency

void readFreq(vector<pair<string,int>> freq);
// outputs each unique word and how many times the word is said. 

 vector<string> words;
// will hold every word in the .txt file

 vector<pair<string,int>> wordFreq;
//will hold pairs of each unique word in the .txt file with an int showing the amount of times a word has been used. 

int main(){
    ifstream homes("homes.txt");

    if(!homes.is_open())
    {
        cout <<"file read error has occured."<<endl;
        return 1;
    }

    orgWords(words,homes);
    freq(wordFreq,words);

    readFreq(wordFreq);

    return 0;
}

void orgWords(vector<string> &words , ifstream &file){
    string word;
    int i=0;

    while (file >> word){
        wordOnly(word);
        words.push_back(word);
        i++;
    }
}

void wordOnly(string &word){
 int wordLen=word.length();
for(int i=0; i < wordLen; i++){
    word.at(i)=tolower(word.at(i));
}
if(!isalpha(word.at(wordLen - 1))){
    word.erase(wordLen - 1,word.at(wordLen - 1));
    }
}

void freq(vector<pair<string,int>> &freq, vector<string> words){
 freq.push_back({words.at(0),1});

  for(int i = 1; i < words.size(); i++){
    for(int f = 0; f < freq.size(); f++)
    {
        if(words.at(i).compare(freq.at(f).first) == 0){
            freq.at(f).second++;
            break;
        }else if(f>=freq.size()-1)
        {
            freq.push_back({words.at(i),1});
            break;
        }
    }
  }  
}

void readFreq(vector<pair<string,int>> freq){
    for(int i=0; i < freq.size(); i++)
    {
        cout<< freq.at(i).first <<"  --  "<< freq.at(i).second << endl; 
    }

}
