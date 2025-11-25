#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

  cout << "TEST 02" << endl;

  WordCount wc;

  // start with empty table
  ASSERT_EQUALS(0, wc.getTotalWords());
  ASSERT_EQUALS(0, wc.getNumUniqueWords());

  // single word, once
  ASSERT_EQUALS(1, wc.incrWordCount("hello"));
  ASSERT_EQUALS(1, wc.getWordCount("hello"));
  ASSERT_EQUALS(1, wc.getTotalWords());
  ASSERT_EQUALS(1, wc.getNumUniqueWords());

  // same word, different case
  ASSERT_EQUALS(2, wc.incrWordCount("HeLLo"));
  ASSERT_EQUALS(2, wc.getWordCount("HELLO"));
  ASSERT_EQUALS(2, wc.getTotalWords());
  ASSERT_EQUALS(1, wc.getNumUniqueWords());

  // new word
  ASSERT_EQUALS(1, wc.incrWordCount("world"));
  ASSERT_EQUALS(1, wc.getWordCount("world"));
  ASSERT_EQUALS(3, wc.getTotalWords());
  ASSERT_EQUALS(2, wc.getNumUniqueWords());

  // makeValidWord integration with punctuation
  ASSERT_EQUALS(3, wc.incrWordCount("!!hello!!"));
  ASSERT_EQUALS(3, wc.getWordCount("hello"));
  ASSERT_EQUALS(4, wc.getTotalWords());
  ASSERT_EQUALS(2, wc.getNumUniqueWords());

  // invalid word (no letters) should not change counts
  ASSERT_EQUALS(0, wc.incrWordCount("1234!!"));
  ASSERT_EQUALS(4, wc.getTotalWords());
  ASSERT_EQUALS(2, wc.getNumUniqueWords());

  cout << "All tests passed in lab06Test02" << endl;

  return 0;
}
