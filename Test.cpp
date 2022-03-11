/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHOR: <Haim Or Hadad>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
    SUBCASE("short input"){
	    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n @-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
        CHECK(nospaces(mat(3,1,'=','^')) == nospaces("==="));
        CHECK(nospaces(mat(5,3,'$','&')) == nospaces("$$$$$\n$&&&$\n$$$$$\n"));
        CHECK(nospaces(mat(7,5,'%','*')) == nospaces("%%%%%%%\n%*****%\n%*%%%*%\n%*****%\n%%%%%%%"));
        CHECK(nospaces(mat(7,3,'@','#')) == nospaces("@@@@@@@\n@#####@\n@@@@@@@"));
    }
    SUBCASE("long input"){
        CHECK(nospaces(mat(15, 17, '+', '-')) == nospaces("+++++++++++++++\n+-------------+\n+-+++++++++++-+\n+-+---------+-+\n+-+-+++++++-+-+\n+-+-+-----+-+-+\n+-+-+-+++-+-+-+\n+-+-+-+-+-+-+-+\n+-+-+-+-+-+-+-+\n+-+-+-+-+-+-+-+\n+-+-+-+++-+-+-+\n+-+-+-----+-+-+\n+-+-+++++++-+-+\n+-+---------+-+\n+-+++++++++++-+\n+-------------+\n+++++++++++++++"));
        CHECK(nospaces(mat(77,3,'(','&')) == nospaces("(((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((\n(&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&(\n((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((("));
        CHECK(nospaces(mat(121,5,'!','-')) == nospaces("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n!-----------------------------------------------------------------------------------------------------------------------!\n!-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!-!\n!-----------------------------------------------------------------------------------------------------------------------!\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));
    }
}

TEST_CASE("good and bad numbers"){
    SUBCASE("Odd number"){
        CHECK(nospaces(mat(9, 5, '$', '%')) == nospaces("$$$$$$$$$\n$%%%%%%%$\n$%$$$$$%$\n$%%%%%%%$\n$$$$$$$$$"));
        CHECK(nospaces(mat(3,1,'#','$')) == nospaces("###"));
        CHECK(nospaces(mat(21,3,'^','&')) == nospaces("^^^^^^^^^^^^^^^^^^^^^\n^&&&&&&&&&&&&&&&&&&&^\n^^^^^^^^^^^^^^^^^^^^^"));
    }
    SUBCASE("Even number"){
        CHECK_THROWS(nospaces(mat(10,5,'!','@')));
        CHECK_THROWS(nospaces(mat(4,2,'#','$')));
        CHECK_THROWS(nospaces(mat(30,12,'&','*')));
    }
    SUBCASE("negative number"){
        CHECK_THROWS(nospaces(mat(-7,5,'!','@')));
        CHECK_THROWS(nospaces(mat(-3,2,'#','$')));
        CHECK_THROWS(nospaces(mat(-1,-11,'&','*')));
    }
    SUBCASE("zero"){
        CHECK_THROWS(nospaces(mat(0,5,'!','@')));
        CHECK_THROWS(nospaces(mat(0,0,'!','@')));
        CHECK_THROWS(nospaces(mat(3,0,'!','@')));
        CHECK_THROWS(nospaces(mat(4,8,'!','@')));
    }
}
