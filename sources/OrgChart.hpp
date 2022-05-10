#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace ariel
{

    // write Node class here
    class Node
    {

    public:
        Node(string name)
        {
            this->name = name;
        }
        string getName()
        {
            return this->name;
        }
        void addSon(Node son)
        {
            this->sons.push_back(son);
        }
        vector<Node> getSons()
        {
            return this->sons;
        }

    private:
        string name;
        vector<Node> sons;
    };

    class OrgChart
    {
    private:
        Node root;
        bool add_sub(Node &node, string &dad, string &son);

        vector<string> q_level_order;
        void fill_level_order(Node &node);

        vector<string> q_reverse_order;
        void fill_reverse_order(Node &node);

        vector<string> q_preorder;
        void fill_preorder(Node &node);

    public:
        OrgChart();
        OrgChart &add_root(string name);
        OrgChart &add_sub(string dad, string son);

        vector<string>::iterator begin_level_order();
        vector<string>::iterator end_level_order();

        vector<string>::iterator begin_reverse_order();
        vector<string>::iterator reverse_order();

        vector<string>::iterator begin_preorder();
        vector<string>::iterator end_preorder();
        ~OrgChart();
        friend ostream &operator<<(ostream &os, OrgChart &root);
    };
}