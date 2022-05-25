

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
    OrgChart organization;
    organization.add_root("CEO")
        .add_sub("CEO", "CTO")    // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")    // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")    // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW")  // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI"); // Now the VP_BI is subordinate to the COO

    CHECK_NOTHROW(cout << organization << endl); /* Prints the org chart in a reasonable format. For example:
         CEO
         |--------|--------|
         CTO      CFO      COO
         |                 |
         VP_SW             VP_BI
   */
    vector<string> string_iter;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        string_iter.push_back(*it);
    } // prints: CEO CTO CFO COO VP_SW VP_BI

    CHECK_EQ(string_iter.at(0), "CEO");
    CHECK_EQ(string_iter.at(1), "CTO");
    CHECK_EQ(string_iter.at(2), "CFO");
    CHECK_EQ(string_iter.at(3), "COO");
    CHECK_EQ(string_iter.at(4), "VP_SW");
    CHECK_EQ(string_iter.at(5), "VP_BI");

    vector<string> string_iter_rev;

    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        string_iter_rev.push_back(*it);
    } // prints: VP_SW VP_BI CTO CFO COO CEO

    CHECK_EQ(string_iter_rev.at(0), "VP_SW");
    CHECK_EQ(string_iter_rev.at(1), "VP_BI");
    CHECK_EQ(string_iter_rev.at(2), "CTO");
    CHECK_EQ(string_iter_rev.at(3), "CFO");
    CHECK_EQ(string_iter_rev.at(4), "COO");
    CHECK_EQ(string_iter_rev.at(5), "CEO");

    vector<string> string_iter_pre;
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
        string_iter_pre.push_back(*it);
    } // prints: CEO CTO VP_SW CFO COO VP_BI

    CHECK_EQ(string_iter_pre.at(0), "CEO");
    CHECK_EQ(string_iter_pre.at(1), "CTO");
    CHECK_EQ(string_iter_pre.at(2), "VP_SW");
    CHECK_EQ(string_iter_pre.at(3), "CFO");
    CHECK_EQ(string_iter_pre.at(4), "COO");
    CHECK_EQ(string_iter_pre.at(5), "VP_BI");

    vector<string> string_iter_regular;
    for (auto element : organization)
    {
        // this should work like level order
        string_iter_regular.push_back(element);
        cout << element << " ";
    } // prints: CEO CTO CFO COO VP_SW VP_BI

    CHECK_EQ(string_iter_regular.at(0), "CEO");
    CHECK_EQ(string_iter_regular.at(1), "CTO");
    CHECK_EQ(string_iter_regular.at(2), "CFO");
    CHECK_EQ(string_iter_regular.at(3), "COO");
    CHECK_EQ(string_iter_regular.at(4), "VP_SW");
    CHECK_EQ(string_iter_regular.at(5), "VP_BI");

    vector<size_t> int_iter_check_size;
    // demonstrate the arrow operator:
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        int_iter_check_size.push_back(it->size());
        cout << it->size() << " ";
    } // prints: 3 3 3 3 5 5

    CHECK_EQ(int_iter_check_size.at(0), 3);
    CHECK_EQ(int_iter_check_size.at(1), 3);
    CHECK_EQ(int_iter_check_size.at(2), 3);
    CHECK_EQ(int_iter_check_size.at(3), 3);
    CHECK_EQ(int_iter_check_size.at(4), 5);
    CHECK_EQ(int_iter_check_size.at(5), 5);
}
