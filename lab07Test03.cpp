#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

  cout << "TEST 03" << endl;

  WordCount wc;

  // Start empty
  ASSERT_EQUALS(0, wc.getTotalWords());
  ASSERT_EQUALS(0, wc.getNumUniqueWords());

  // Build counts for dog and cat
  ASSERT_EQUALS(1, wc.incrWordCount("dog"));
  ASSERT_EQUALS(2, wc.incrWordCount("dog"));
  ASSERT_EQUALS(1, wc.incrWordCount("cat"));

  ASSERT_EQUALS(3, wc.getTotalWords());      // dog x2, cat x1
  ASSERT_EQUALS(2, wc.getNumUniqueWords());  // "dog", "cat"
  ASSERT_EQUALS(2, wc.getWordCount("dog"));
  ASSERT_EQUALS(1, wc.getWordCount("cat"));

  // Decrement dog from 2 -> 1
  ASSERT_EQUALS(1, wc.decrWordCount("DoG"));
  ASSERT_EQUALS(1, wc.getWordCount("dog"));
  ASSERT_EQUALS(2, wc.getTotalWords());
  ASSERT_EQUALS(2, wc.getNumUniqueWords());

  // Decrement dog from 1 -> removed
  ASSERT_EQUALS(0, wc.decrWordCount("dog"));
  ASSERT_EQUALS(0, wc.getWordCount("dog"));
  ASSERT_EQUALS(1, wc.getTotalWords());      // only cat left
  ASSERT_EQUALS(1, wc.getNumUniqueWords());

  // Decrement non-existent word
  ASSERT_EQUALS(-1, wc.decrWordCount("fish"));
  ASSERT_EQUALS(0, wc.getWordCount("fish"));
  ASSERT_EQUALS(1, wc.getTotalWords());
  ASSERT_EQUALS(1, wc.getNumUniqueWords());

  // Decrement cat until table is empty
  ASSERT_EQUALS(0, wc.decrWordCount("cat"));
  ASSERT_EQUALS(0, wc.getWordCount("cat"));
  ASSERT_EQUALS(0, wc.getTotalWords());
  ASSERT_EQUALS(0, wc.getNumUniqueWords());

  // Invalid word: no letters -> should return -1
  ASSERT_EQUALS(-1, wc.decrWordCount("1234!!"));
  ASSERT_EQUALS(0, wc.getTotalWords());
  ASSERT_EQUALS(0, wc.getNumUniqueWords());

  return 0;
}
