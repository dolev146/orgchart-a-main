#include "OrgChart.hpp"
using namespace std;
namespace ariel
{

    OrgChart &OrgChart::add_sub(string parent, string child)
    {
        if (parent.compare(this->root->name))
        {
            Node *new_node = new Node(child);
            root.childrens.push_back(new_node);
        }
        else
        { /*
                loop all the childrens of the root
                and check if the parent is the same as the parent we are looking for
                if it is the same we add the child to the childrens of the parent
          */
            // loop recursivly down the tree
            // using go_down_tree
            // and add the child to the childrens of the parent
            // and return the parent
            // if the parent is not found we return the root
            // if the parent is the root we return the root
            // if the parent is not the root we return the parent
            // if the parent is not found we return the root
            go_down_the_tree_and_look_for_parent(root, parent, child);
        }
        return *this;
    }

    void go_down_the_tree_and_look_for_parent(string parent_to_look, Node *root, string child)
    {
        if (root->txt == parent_to_look)
        {
            // we found the parent
            // now we need to add the child to the childrens of the parent
            // and we need to return
            Node *new_node = new Node(child);
            root.childrens.push_back(new_node);
            return;
        }
        else
        {
            // we didnt find the parent
            // now we need to go down the tree
            // and look for the parent
            for (int i = 0; i < root->childrens.size(); i++)
            {
                go_down_the_tree_and_look_for_parent(parent_to_look, root->childrens[i], child);
            }
        }
    }

}

string *OrgChart::begin_level_order()
{
    // create a string array
    // and return the array
    // and fill it with the level order

    return &test[0];
}


string *OrgChart::end_level_order()
{
    return &test[test.size()];
}

string *OrgChart::begin_reverse_order()
{
    return &test[0];
}

string *OrgChart::reverse_order()
{
    return &test[test.size()];
}

string *OrgChart::begin_preorder()
{
    return &test[0];
}


OrgChart &OrgChart::add_root(string txt)
{

    // if root == NULL create root
    if (root == NULL)
    {
        root = new Node(txt);
    }
    // else, replace the old root by the new root
    else
    {
        root->txt = txt;
    }
    return *this;
}

string *OrgChart::end_preorder()
{
    return &test[test.size()];
}

ostream &operator<<(ostream &os, OrgChart &org)
{
    return os;
}
