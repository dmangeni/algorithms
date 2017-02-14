//
//  algorithm.h
//  algorithms
//
//  Created by DorahMangeni on 1/30/17.
//  Copyright © 2017 DorahMangeni. All rights reserved.
//

#ifndef algorithm_h
#define algorithm_h

#include <vector>
#include <iostream>

using namespace std;

class Algorithm{
public:
    
    struct Node {
        int data;
        Node* left;
        Node * right;
    };

    Algorithm();
    vector<int> twoSum(vector<int>& nums, int target);
    void print(vector<int>&nums);
    bool is_binary_search_tree(Node *current_node, int min, int max);
    bool checkBST(Node* root);
    bool is_anagram(string a, string b);
    
private:
    
};

#endif /* algorithm_h */
