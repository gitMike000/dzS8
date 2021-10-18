//#pragma one  // В Linux c g++ не работает !!!
#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include <algorithm>
#include "dzS1.h"
#include <sstream>

class TestPhoneBook : public testing::Test{
protected:
    void SetUp() override {
        ifstream file("/home/mike/git/dzS8/XXX1"); // путь к файлу PhoneBook.txt
        book=new PhoneBook(file);
    }
    void TearDown() override {
        delete book;
    }
    PhoneBook *book;
};

TEST_F(TestPhoneBook, get_method_PhoneNumber_notfound){
    const PhoneNumber f={7,17,"4559767"};
    auto ans=book->GetPhoneNumber("Ilina");
    EXPECT_EQ(ans.first, "not found");// << "you'll see this in case of an error";
    //EXPECT_EQ(ans.second, f);
}

TEST_F(TestPhoneBook, get_method_PhoneNumber_onefound){
    const PhoneNumber f={7,17,"4559767"};
    auto ans=book->GetPhoneNumber("Ilin");
    EXPECT_EQ(ans.first, "");
    EXPECT_EQ(ans.second, f);
}

TEST_F(TestPhoneBook, get_method_PhoneNumber_morefound){
//    const PhoneNumber f={125,44,"4164751"};
    auto ans=book->GetPhoneNumber("Zaitsev");
    EXPECT_EQ(ans.first, "found more than 1");
//    EXPECT_EQ(ans.second, f);
}

TEST_F(TestPhoneBook, set_method_CnangePhoneNumber){
    const Person p={"Sokolov","Arsenii"};
    const PhoneNumber f={7,17,"4559767"};
    book->ChangePhoneNumber(p,f);
    auto ans=book->GetPhoneNumber("Sokolov");
    EXPECT_EQ(ans.second, f);
}

TEST_F(TestPhoneBook,SortbyName) {
    stringstream test_st;
    test_st <<
          "            Ilin            Petr      Artemovich	  +7(17)4559767\n" <<
          "         Sokolov         Arsenii                   +93(163)1992257 16\n" <<
          "         Zaitsev          Zakhar      Artemovich	  +125(44)4164751\n" <<
          "         Zaitsev          Zakhar      Artemovich	  +125(44)4164751\n";
    book->SortByName();
    stringstream source_st;
    source_st<<*book;

    while(!source_st.eof()) {
      string s1,s2;
      test_st>>s1;
      source_st>>s2;
      EXPECT_EQ(s1,s2);
    }
}

TEST_F(TestPhoneBook,SortbyPhone) {
    stringstream test_st;
    test_st <<
          "            Ilin            Petr      Artemovich	  +7(17)4559767\n" <<
          "         Sokolov         Arsenii                   +93(163)1992257 16\n" <<
          "         Zaitsev          Zakhar      Artemovich	  +125(44)4164751\n" <<
          "         Zaitsev          Zakhar      Artemovich	  +125(44)4164751\n";
    book->SortByPhone();
    stringstream source_st;
    source_st<<*book;

    while(!source_st.eof()) {
      string s1,s2;
      test_st>>s1;
      source_st>>s2;
      EXPECT_EQ(s1,s2);
    }
}

#endif // TESTS_H
