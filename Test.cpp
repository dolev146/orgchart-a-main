

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
    OrgChart::operator<<(ostream &, OrgChart &)

*/
TEST_CASE("OrgChart::add_root")
{
    OrgChart org;
    org.add_root("root");
    CHECK(org.root_tree->value == "root");
    // now add 10 times a diffrent root
    for (int i = 0; i < 10; i++)
    {
        org.add_root("root" + to_string(i));
        CHECK(org.root_tree->value == "root" + to_string(i));
    }
}

// /*
//     in add sub , we are testing the following functions:
//     OrgChart::add_sub(string, string)
//     and we are adding a sub to the root
//     and we test to see if it truely added it
// */
TEST_CASE("OrgChart::add_sub")
{
    OrgChart org;
    org.add_root("root");
    org.add_sub("root", "child");

    for (size_t i = 0; i < 10; i++)
    {
        org.add_sub("root", "child" + to_string(i));
    }

    for (size_t i = 0; i < 10; i++)
    {
        CHECK(org.root_tree->children.at(i)->value.compare("child" + to_string(i)));
    }
}

TEST_CASE("Check not throw")
{
    OrgChart org;
    CHECK_NOTHROW(org.add_root("root"));
    CHECK_NOTHROW(org.add_sub("root", "child"));

    for (size_t i = 0; i < 10; i++)
    {
        CHECK_NOTHROW(org.add_sub("root", "child" + to_string(i)));
    }

    CHECK_NOTHROW(org.begin_level_order());
    CHECK_NOTHROW(org.end_level_order());
    auto start = org.begin_level_order();
    auto end = org.end_level_order();

    for (auto it = start; it != end; ++it)
    {
        CHECK_NOTHROW(*it);
    }

    CHECK_NOTHROW(org.begin_reverse_order());
    CHECK_NOTHROW(org.reverse_order());
    auto start_rev = org.begin_reverse_order();
    auto end_rev = org.reverse_order();

    for (auto it = start_rev; it != end_rev; ++it)
    {
        CHECK_NOTHROW(*it);
    }

    CHECK_NOTHROW(org.begin_preorder());
    CHECK_NOTHROW(org.end_preorder());
    auto start_pre = org.begin_preorder();
    auto end_pre = org.end_preorder();

    for (auto it = start_pre; it != end_pre; ++it)
    {
        CHECK_NOTHROW(*it);
    }
}

TEST_CASE("Tree good valaues check")
{
    

    
}
