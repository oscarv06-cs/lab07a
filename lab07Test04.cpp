// lab07Test04.cpp
#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
#include <sstream> // for ostringstream
using namespace std;

int main() {

  cout << "TEST 04 (Lab07a new functions)" << endl;
  {
    WordCount wc;
    wc.addAllWords("Hello hello world!!");
    // shoulg go from:
    // "Hello"  -> "hello"
    // "hello"  -> "hello"
    // "world!!" -> "world"
    // So: hello x2, world x1
    ASSERT_EQUALS(3, wc.getTotalWords());
    ASSERT_EQUALS(2, wc.getNumUniqueWords());
    ASSERT_EQUALS(2, wc.getWordCount("hello"));
    ASSERT_EQUALS(1, wc.getWordCount("world"));

    // Check dumpWordsSortedByWord
    ostringstream byWord;
    wc.dumpWordsSortedByWord(byWord);
    string expectedByWord =
      "hello 2\n"
      "world 1\n";
    ASSERT_EQUALS(expectedByWord, byWord.str());

    // Check dumpWordsSortedByOccurence
    ostringstream byOcc;
    wc.dumpWordsSortedByOccurence(byOcc);
    // Most frequent first: hello (2), then world (1)
    string expectedByOcc =
      "hello 2\n"
      "world 1\n";
    ASSERT_EQUALS(expectedByOcc, byOcc.str());
  }

  {
    WordCount wc;

    wc.addAllWords("banana apple banana cat apple banana");
    // Counts should be:
    // banana x3, apple x2, cat x1
    ASSERT_EQUALS(6, wc.getTotalWords());
    ASSERT_EQUALS(3, wc.getNumUniqueWords());
    ASSERT_EQUALS(3, wc.getWordCount("banana"));
    ASSERT_EQUALS(2, wc.getWordCount("apple"));
    ASSERT_EQUALS(1, wc.getWordCount("cat"));

    // Sorted by word (alphabetical)
    ostringstream byWord;
    wc.dumpWordsSortedByWord(byWord);
    string expectedByWord =
      "apple 2\n"
      "banana 3\n"
      "cat 1\n";
    ASSERT_EQUALS(expectedByWord, byWord.str());

    // Sorted by occurrence (descending), tie-break by word
    ostringstream byOcc;
    wc.dumpWordsSortedByOccurence(byOcc);
    string expectedByOcc =
      "banana 3\n"
      "apple 2\n"
      "cat 1\n";
    ASSERT_EQUALS(expectedByOcc, byOcc.str());
  }
  {
    WordCount wc;

    wc.addAllWords("1234 !!! ??? ....");
    // No valid words should be added
    ASSERT_EQUALS(0, wc.getTotalWords());
    ASSERT_EQUALS(0, wc.getNumUniqueWords());

    ostringstream byWord;
    wc.dumpWordsSortedByWord(byWord);
    ASSERT_EQUALS(string(""), byWord.str());

    ostringstream byOcc;
    wc.dumpWordsSortedByOccurence(byOcc);
    ASSERT_EQUALS(string(""), byOcc.str());
  }
  return 0;
}
