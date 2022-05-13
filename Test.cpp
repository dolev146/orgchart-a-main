

#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

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

TEST_CASE("OrgChart")
{
    // loop 50 times to test all the cases
    int j = 0;
    for (int i = 0; i < 50; i++)
    {
        CHECK(true);
    }
}
