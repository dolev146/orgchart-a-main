#include <iostream>
#include <vector>
#include <string>

using namespace std;
namespace ariel
{
 
    class Node
    {
    public:
        Node()
        {
            txt = "";
        }
        Node(string txt)
        {
            this->txt = txt;
            this->childrens = vector<Node *>();
        }
        string txt;
        vector<Node *> childrens;
    };
    class OrgChart
    {
    public:
        string *begin_reverse_order();
        string *reverse_order();
        string *begin_level_order();
        string *end_level_order();
        string *begin() { return begin_level_order(); }
        string *end() { return end_level_order(); }
        string *begin_preorder();
        string *end_preorder();
        friend ostream &operator<<(ostream &, OrgChart &);
        OrgChart &add_root(string);
        OrgChart &add_sub(string, string);
        Node root;
        void fill_level_order(Node &);
        void fill_reverse_order(Node &);
        void fill_preorder(Node &);
        vector<string> test;
    };

}