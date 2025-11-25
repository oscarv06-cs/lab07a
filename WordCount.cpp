// WordCount.cpp

#include "WordCount.h"
#include <cctype> //include for iswordchar func
#include <algorithm> //for sort
#include <sstream> //for istringstream
using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	// STUB - your solution from Lab06 goes here
	int total = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		for (size_t j = 0; j < table[i].size(); j++){
			total += table[i][j].second;
		}  
	}
	return total;
}

int WordCount::getNumUniqueWords() const {
	// STUB - your solution from Lab06 goes here
	int total = 0;
	for (size_t i = 0; i < CAPACITY; i++){
		total += table[i].size();  
	}
	return total;
}

int WordCount::getWordCount(std::string word) const {
	// STUB - your solution from Lab06 goes here
	std::string validWord = makeValidWord(word); //making word valid for the test cases
	if (validWord == ""){
		return 0; 
	}
	size_t index = hash(validWord);
	const std::vector<std::pair<std::string, int>> &bucket = table[index];

	for (size_t i = 0; i < bucket.size(); i++){
		if (bucket[i].first == validWord){
			return bucket[i].second; //return it once its found
		}
	}
	return 0; 
}
	
int WordCount::incrWordCount(std::string word) {
	// STUB - your solution from Lab06 goes here
	std::string validWord = makeValidWord(word); //making word valid for the test cases
	if (validWord == ""){
		return 0; 
	}
	size_t index = hash(validWord);
	std::vector<std::pair<std::string, int>> &bucket = table[index];

    for (size_t i = 0; i < bucket.size(); i++){
		if (bucket[i].first == validWord){
			bucket[i].second++;
			return bucket[i].second; //return it once its found
		}
	}
	bucket.push_back(std::make_pair(validWord, 1));
	return 1; 
}

int WordCount::decrWordCount(std::string word) {
	// STUB - your solution from Lab06 goes here
	std::string validWord = makeValidWord(word); //making word valid for the test cases
	if (validWord == ""){
		return -1; 
	}

	size_t index = hash(validWord);
	std::vector<std::pair<std::string, int>> &bucket = table[index];

    for (size_t i = 0; i < bucket.size(); i++){
		if (bucket[i].first == validWord){
			if (bucket[i].second > 1){
				bucket[i].second--;
				return bucket[i].second; //return it once its found
			}
			bucket.erase(bucket.begin() + i);
			return 0;
		}
	}
	return -1; // if the word was never found 
}


bool WordCount::isWordChar(char c) {
	// STUB - your solution from Lab06 goes here
	return isalpha(c);
}

std::string WordCount::makeValidWord(std::string word) {
	// STUB - your solution from Lab06 goes here
	std::string output; 
	for (char c : word){
		if (isWordChar(c)){
			output += tolower(c);
		}
		else if (c == '\'' || c == '-'){
			output += c;
		}
	}
	if (output == ""){
		return "";
	}

	while (!output.empty() && (output.front() == '-' ||output.front() == '\'' )){//trim the - or ' at the beginning 
		output.erase(output.begin());
	}

	while (!output.empty() && (output.back() == '-'||output.back() == '\'' )){ //trim the - or ' at the end
		output.pop_back();
	}
	
    return output;
}


void WordCount::dumpWordsSortedByWord(std::ostream &out) const {
	// STUB
	//My understanding of this function: dump/print all the words but in alphabetical order
	std::vector<std::string> words;
	for (size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			words.push_back(table[i][j].first);
		}
	}
	sort(words.begin(), words.end());
	for (const std::string &word : words){
		out << word << " " << getWordCount(word) << endl;
	}
}

void WordCount::dumpWordsSortedByOccurence(std::ostream &out) const {
	// STUB
	//My understanding: dump/print all the words in order of how many times they occur.
	std::vector<std::pair<std::string, int>> count;
	for (size_t i = 0; i < CAPACITY; i++){
		for(size_t j = 0; j < table[i].size(); j++){
			count.push_back(table[i][j]);
		}
	}
	sort(count.begin(), count.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b){
		if (a.second == b.second){
			return a.first < b.first; //if they are the same count then sort by words
		}
		return a.second < b.second; //Sort by count and return
	});
	for (const auto &pair : count){
		out << pair.first << " " << pair.second << endl;
	}
}
	

void WordCount::addAllWords(std::string text) {
	// STUB
	//My understandingL: take a string of text and add each word to the hash table
	std::istringstream iss(text);
	std::string word;
	while (iss >> word){
		incrWordCount(word);
	}
}
