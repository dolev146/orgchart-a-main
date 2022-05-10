#include "OrgChart.hpp"
using namespace std;
namespace ariel
{
    OrgChart::OrgChart()
    {
    }
    OrgChart &OrgChart::add_root(string name)
    {
        root.name = name;
        return *this;
    }
    OrgChart &OrgChart::add_sub(string dad, string son)
    {
        add_sub(root, dad, son);
        return *this;
    }
    bool OrgChart::add_sub(Node &node, string &dad, string &son)
    {
        if (!node.name.compare(dad))
        {
            Node temp;
            temp.name = son;
            node.sones.push_back(temp);
            return true;
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            if (add_sub(node.sones[i], dad, son))
            {
                return true;
            }
        }
        return false;
    }
    deque<string>::iterator OrgChart::begin_level_order()
    {
        q_level_order.clear();
        q_level_order.push_back(root.name);
        fill_level_order(root);
        return q_level_order.begin();
    }
    void OrgChart::fill_level_order(Node &node)
    {
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            q_level_order.push_back(node.sones[i].name);
        }
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_level_order(node.sones[i]);
        }
    }
    deque<string>::iterator OrgChart::end_level_order()
    {
        return q_level_order.end();
    }

    deque<string>::iterator OrgChart::begin_reverse_order()
    {
        q_reverse_order.clear();
        q_reverse_order.push_front(root.name);
        fill_reverse_order(root);
        return q_reverse_order.begin();
    }
    void OrgChart::fill_reverse_order(Node &node)
    {
        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            q_reverse_order.push_front(node.sones[(size_t)i].name);
        }
        for (int i = node.sones.size() - 1; i >= 0; i--)
        {
            fill_reverse_order(node.sones[(size_t)i]);
        }
    }
    deque<string>::iterator OrgChart::reverse_order()
    {
        return q_reverse_order.end();
    }

    deque<string>::iterator OrgChart::begin_preorder()
    {
        q_preorder.clear();
        fill_preorder(root);
        return q_preorder.begin();
    }
    void OrgChart::fill_preorder(Node &node)
    {
        q_preorder.push_back(node.name);
        for (size_t i = 0; i < node.sones.size(); i++)
        {
            fill_preorder(node.sones[i]);
        }
    }
    deque<string>::iterator OrgChart::end_preorder()
    {
        return q_preorder.end();
    }
    OrgChart::~OrgChart()
    {
    }
    ostream &operator<<(ostream &os, OrgChart &org)
    {
        for (auto it = org.begin_preorder(); it != org.end_preorder(); ++it)
        {
            os << (*it) << ", ";
        }
        return os;
    }
}