#include "WordCount.h"
#include "tddFuncs.h"
#include <iostream>
using namespace std;

int main() {

    cout << "TEST 01" << endl;

    WordCount wc;

    // isWordChar tests
    ASSERT_TRUE(wc.isWordChar('a'));
    ASSERT_TRUE(wc.isWordChar('Z'));
    ASSERT_TRUE(!(wc.isWordChar('1')));
    ASSERT_TRUE(!(wc.isWordChar('!')));
    ASSERT_TRUE(!(wc.isWordChar('-'))); 

    // makeValidWord basic cleanup
    ASSERT_EQUALS(string("hello"), wc.makeValidWord("Hello"));
    ASSERT_EQUALS(string("hello"), wc.makeValidWord("HELLO"));
    ASSERT_EQUALS(string("hello"), wc.makeValidWord("HeLlO"));

    // strip leading/trailing junk
    ASSERT_EQUALS(string("world"), wc.makeValidWord("123world456"));
    ASSERT_EQUALS(string("test"), wc.makeValidWord("!!TeSt!!"));

    // allow internal apostrophe/dash
    ASSERT_EQUALS(string("can't"), wc.makeValidWord("--CAN'T--"));
    ASSERT_EQUALS(string("re-entry"), wc.makeValidWord("++Re-EnTrY++"));

    ASSERT_EQUALS(string(""), wc.makeValidWord("12345!!"));
    ASSERT_EQUALS(string(""), wc.makeValidWord("----"));
    ASSERT_EQUALS(string(""), wc.makeValidWord(""));

    cout << "All testss passed in lab06test01" << endl;

    return 0;
}
