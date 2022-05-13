#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    OrgChart &OrgChart::add_root(string txt)
    {
        root.txt = txt;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        return *this;
    }
 

    string *OrgChart::begin_level_order()
    {
        return &test[0];
    }

    void OrgChart::fill_level_order(Node &node)
    {
        // add node to test
        test.push_back(node.txt);
    }

    string *OrgChart::end_level_order()
    {
        return &test[test.size()];
    }

    string *OrgChart::begin_reverse_order()
    {
        return &test[0];
    }
    void OrgChart::fill_reverse_order(Node &node)
    {
        // add node to test
        test.push_back(node.txt);
    }
    string *OrgChart::reverse_order()
    {
        return &test[test.size()];
    }

    string *OrgChart::begin_preorder()
    {
        return &test[0];
    }
    void OrgChart::fill_preorder(Node &node)
    {
        // add node to test
        test.push_back(node.txt);
    }
    string *OrgChart::end_preorder()
    {
        return &test[test.size()];
    }
    ostream &operator<<(ostream &os, OrgChart &org)
    {
        for (auto it = org.begin_preorder(); it != org.end_preorder(); ++it)
        {
            os << (*it) << ":-";
        }
        return os;
    }

}