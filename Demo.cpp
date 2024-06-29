/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{

    Node<double> root_node =Node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);
    Node<double> n1 = Node(1.2);
    Node<double> n2 = Node(1.3);
    Node<double> n3 = Node(1.4);
    Node<double> n4 = Node(1.5);
    Node<double> n5 = Node(1.6);
    Node<double> n6 = Node(1.7);
    Node<double> n7 = Node(1.8);


    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);
   
    // The tree should look like:
    /**
     *       root = 1.1
     *     /       \
     *    1.2      1.3
     *   /  \      /
     *  1.4  1.5  1.6
     */


    cout<<"Pre order traversal: \n";
    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node-> get_value() <<" ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout<<endl;
    cout<<"Post order traversal: \n";
    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1
    cout<<endl;
    
    cout<<"In order traversal: \n";
    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << " ";
        
    } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3
    cout<<endl;
    cout<<"bfs scan:"<<endl;
    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<endl;
    cout<<"bfs scan:"<<endl;
    for (auto node : tree)
    {
        cout << node.get_value() <<  " ";
    } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6
    cout<<endl;
    cout<<"dfs scan:"<<endl;
    for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
    {
        cout << node->get_value() << " ";
    } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6
    cout<<endl;
    cout << "Min-Heap Traversal:" << endl;
    for (auto it = tree.myHeap(); it != Tree<double>::MinHeapIterator(nullptr); ++it) {
        cout << it->get_value() << " ";
    }
    cout << endl;
    // cout << tree; // Should print the graph using GUI.

    // Tree<double> three_ary_tree(3); // 3-ary tree.
    // three_ary_tree.add_root(root_node);
    // for (auto neighbor : three_ary_tree.getRoot()->neighbors)
    // {
    //     cout << neighbor->get_value() << " ";
    // } // prints: 1.2, 1.3, 1.4
    // three_ary_tree.add_sub_node(root_node, n1);
    // three_ary_tree.add_sub_node(root_node, n2);
    // three_ary_tree.add_sub_node(root_node, n3);
    // three_ary_tree.add_sub_node(n1, n4);
    // three_ary_tree.add_sub_node(n2, n5);
    // cout<<"In order traversal: \n";
    // for (auto node = three_ary_tree.begin_post_order(); node != three_ary_tree.end_post_order(); ++node)
    // {
    //     cout << node->get_value() << " ";
        
    // }
    // cout<<endl;
     // The tree should look like:
    /**
     *       root = 1.1
     *     /      |     \
     *    1.2    1.3    1.4
     *   /        |
     *  1.5      1.6
     */
    return 0;
    
}