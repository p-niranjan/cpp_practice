#include <vector>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
 public:
  string name;
  vector<Node*> children;

  Node(string str) { name = str; }

  vector<string> depthFirstSearch(vector<string>* array) {
    // Write your code here.
    //vector<string> out;
    array->push_back(this->name);
    for(auto child : children) {
      child->depthFirstSearch(array);
    }
    return *array;
  }

  Node* addChild(string name) {
    Node* child = new Node(name);
    children.push_back(child);
    return this;
  }
};
