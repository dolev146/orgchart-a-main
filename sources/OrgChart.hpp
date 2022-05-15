#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <exception>
// include deque for double ended queue
// #include <deque>

using namespace std;
namespace ariel
{

    class Node
    {
    public:
        Node()
        {
            txt = "";
            this->childrens = vector<Node *>();
            throw "emply node created\n";
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
        OrgChart()
        {
            this->root = NULL;
        };
        OrgChart(string txt) {}
        ~OrgChart() {}

        vector<string> test_try;

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
    };

}