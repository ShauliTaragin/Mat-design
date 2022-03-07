/**
 * AUTHORS: Shaul Taragin
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "mat.hpp"

using namespace ariel;

#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

string nospaces(string input) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input.erase(remove(input.begin(), input.end(), '\t'), input.end());
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
}

TEST_CASE ("Good input generic numbers") {
            CHECK(nospaces(mat(35, 7, '*', '$')) == nospaces("***********************************\n"
                                                             "*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*\n"
                                                             "*$*******************************$*\n"
                                                             "*$*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*$*\n"
                                                             "*$*******************************$*\n"
                                                             "*$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*\n"
                                                             "***********************************"));

            CHECK(nospaces(mat(3, 17, '_', '-')) == nospaces("___\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "_-_\n"
                                                             "___"));

            CHECK(nospaces(mat(21, 3, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@@@@@\n"
                                                            "@-------------------@\n"
                                                            "@@@@@@@@@@@@@@@@@@@@@"));
            CHECK(nospaces(mat(9, 7, '{', '}')) == nospaces("{{{{{{{{{\n"
                                                            "{}}}}}}}{\n"
                                                            "{}{{{{{}{\n"
                                                            "{}{}}}{}{\n"
                                                            "{}{{{{{}{\n"
                                                            "{}}}}}}}{\n"
                                                            "{{{{{{{{{"));
            CHECK(nospaces(mat(13, 5, '^', '5')) == nospaces("^^^^^^^^^^^^^\n"
                                                             "^55555555555^\n"
                                                             "^5^^^^^^^^^5^\n"
                                                             "^55555555555^\n"
                                                             "^^^^^^^^^^^^^"));
            CHECK(nospaces(mat(17, 11, '@', '-')) == nospaces("@@@@@@@@@@@@@@@@@\n"
                                                            "@---------------@\n"
                                                            "@-@@@@@@@@@@@@@-@\n"
                                                            "@-@-----------@-@\n"
                                                            "@-@-@@@@@@@@@-@-@\n"
                                                            "@-@-@-------@-@-@\n"
                                                            "@-@-@@@@@@@@@-@-@\n"
                                                            "@-@-----------@-@\n"
                                                            "@-@@@@@@@@@@@@@-@\n"
                                                            "@---------------@\n"
                                                            "@@@@@@@@@@@@@@@@@"));
            CHECK(nospaces(mat(21, 11, '8', '3')) == nospaces("888888888888888888888\n"
                                                              "833333333333333333338\n"
                                                              "838888888888888888838\n"
                                                              "838333333333333333838\n"
                                                              "838388888888888883838\n"
                                                              "838383333333333383838\n"
                                                              "838388888888888883838\n"
                                                              "838333333333333333838\n"
                                                              "838888888888888888838\n"
                                                              "833333333333333333338\n"
                                                              "888888888888888888888\n"));
}

TEST_CASE ("Good input Large numbers") {
            CHECK(nospaces(mat(499, 3, '@', '-')) == nospaces(
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@\n"
            "@-----------------------------------------------------------------------------------------------------------------------\n"
            "------------------------------------------------------------------------------------------------------------------------\n"
            "------------------------------------------------------------------------------------------------------------------------\n"
            "------------------------------------------------------------------------------------------------------------------------\n"
            "------------------@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n"
            "@@@@@@@@@@@@@@@@@@@"));
            CHECK(nospaces(mat(65, 17, 'A', 'D')) ==
                  nospaces("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"
                           "ADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDA\n"
                           "ADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADA\n"
                           "ADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADA\n"
                           "ADADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADADA\n"
                           "ADADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADADA\n"
                           "ADADADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADADADA\n"
                           "ADADADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADADADA\n"
                           "ADADADADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADADADADA\n"
                           "ADADADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADADADA\n"
                           "ADADADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADADADA\n"
                           "ADADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADADA\n"
                           "ADADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADADA\n"
                           "ADADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDADA\n"
                           "ADAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAADA\n"
                           "ADDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDA\n"
                           "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"));
}
TEST_CASE ("Good input Edge cases") {
            CHECK(nospaces(mat(3, 5, '3', '5')) == nospaces("333\n"
                                                            "353\n"
                                                            "353\n"
                                                            "353\n"
                                                            "333"));
            CHECK(nospaces(mat(9, 1, '&', 'P')) == nospaces("&&&&&&&&&"));
            CHECK(nospaces(mat(1, 9, '0', '"')) == nospaces("0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0\n"
                                                            "0"));
            CHECK(nospaces(mat(1, 1, '\'', '\\')) == nospaces("'"));
            CHECK(nospaces(mat(7, 9, '#', '#')) == nospaces("#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######\n"
                                                            "#######"));



}

TEST_CASE ("Bad input - Negative number") {
            CHECK_THROWS(mat(-7, 5, ';', '"'));
            CHECK_THROWS(mat(9, -13, '0', '['));
            CHECK_THROWS(mat(-141, -5, '<', 'z'));
            CHECK_THROWS(mat(0, 65, '\'', '\\'));
}

TEST_CASE ("Bad input - Even number") {
            CHECK_THROWS(mat(10, 5, '$', '%'));
            CHECK_THROWS(mat(15, 2, 'a', 'g'));
            CHECK_THROWS(mat(2, 4, '2', '4'));
            CHECK_THROWS(mat(46, 100, '#', '7'));
}



