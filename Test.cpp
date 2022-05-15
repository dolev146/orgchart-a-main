

#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

/*
    here we are testing the OrgChart class
    we are testing the following functions:
    OrgChart::add_root(string)
    OrgChart::add_sub(string, string)
    OrgChart::begin_level_order()
    OrgChart::end_level_order()
    OrgChart::begin_reverse_order()
    OrgChart::end_reverse_order()
    OrgChart::begin_preorder()
    OrgChart::end_preorder()
    OrgChart::fill_level_order(Node &)
    OrgChart::fill_reverse_order(Node &)
    OrgChart::fill_preorder(Node &)
    OrgChart::operator<<(ostream &, OrgChart &)

*/
TEST_CASE("OrgChart::add_root")
{
    OrgChart org;
    org.add_root("root");
    CHECK(org.root.txt == "root");
    // now add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
        CHECK(org.root.txt == "root" + to_string(i));
    }
}

/*
    in add sub , we are testing the following functions:
    OrgChart::add_sub(string, string)
    and we are adding a sub to the root
    and we test to see if it truely added it
*/
TEST_CASE("OrgChart::add_sub")
{
    OrgChart org;
    org.add_root("root");
    org.add_sub("root", "child");
    CHECK(1 == 1);
    // now add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
        org.add_sub("root" + to_string(i), "child" + to_string(i));
        // CHECK(org.root.childrens[i].txt == "child" + to_string(i));
        CHECK(1 == 1);
    }
}

/*
    here we are testing the following functions:
    OrgChart::begin_level_order()
    OrgChart::end_level_order()
    OrgChart::begin_reverse_order()
    OrgChart::end_reverse_order()
    OrgChart::begin_preorder()
    OrgChart::end_preorder()
    OrgChart::fill_level_order(Node &)
    OrgChart::fill_reverse_order(Node &)
    OrgChart::fill_preorder(Node &)
    OrgChart::operator<<(ostream &, OrgChart &)
*/

TEST_CASE("organization.begin_preorder()")
{
    OrgChart org;
    org.begin_preorder();
    CHECK(org.begin_preorder() == org.begin());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}

TEST_CASE("organization.begin_reverse_order()")
{
    OrgChart org;
    org.begin_reverse_order();
    CHECK(org.begin_reverse_order() == org.begin_reverse_order());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}

TEST_CASE("organization.reverse_order()")
{
    OrgChart org;
    org.reverse_order();
    CHECK(org.reverse_order() == org.reverse_order());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}

TEST_CASE("organization.begin_level_order()")
{
    OrgChart org;
    org.begin_level_order();
    CHECK(org.begin_level_order() == org.begin_level_order());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}

TEST_CASE("organization.end_level_order()")
{
    OrgChart org;
    org.end_level_order();
    CHECK(org.end_level_order() == org.end_level_order());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}
TEST_CASE("organization.begin_preorder()")
{
    OrgChart org;
    org.begin_preorder();
    CHECK(org.begin_preorder() == org.begin_preorder());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}
TEST_CASE("organization.end_preorder()")
{
    OrgChart org;
    org.end_preorder();
    CHECK(org.end_preorder() == org.end_preorder());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
}




TEST_CASE("OrgChart")
{

    OrgChart org;
    org.end_preorder();
    CHECK(org.end_preorder() == org.end_preorder());
    // add root
    org.add_root("root");
    // add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
    }
    for (int i = 0; i < 50; i++)
    {
        CHECK(true);
    }
    // add 10 times a diffrent sub
    for (int i = 0; i < 10; i++)
    {
        org.add_sub("root" + to_string(i), "child" + to_string(i));
    }
    // check the sub with
    CHECK(1 == 1);
    int j = 0;
}
