//
//  algorithm.cpp
//  algorithms
//
//  Created by DorahMangeni on 1/30/17.
//  Copyright © 2017 DorahMangeni. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include "algorithm.h"

using namespace std;

/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order
 and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8 */

//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//You may assume that each input would have exactly one solution.
Algorithm::Algorithm(){}
vector<int> Algorithm::twoSum(vector<int>& nums, int target){
    vector<int>result;
    
    unordered_map<int, int>indices;
    
    for(int i = 0; i < nums.size(); i++){
        int number_to_find = target - nums[i];
        
        if(indices.find(number_to_find) != indices.end()){
            result.push_back(indices[number_to_find] + 1);
            result.push_back(i+1);
            return result;
        }
        
        //number was not found. Put it in the map.
        indices[nums[i]] = i;
    }
    
    return result;
}
void Algorithm::print(vector<int>&nums){
    for (auto &&num : nums){
        cout << num << " ";
    }
}


//Check if a tree is a binary tree
bool Algorithm::is_binary_search_tree(Node *current_node, int min, int max){
    
    //An empty tree is a binary search tree
    if(current_node){
        return 1;
    }
    else if(current_node->data < min || current_node->data > max){
        return 0;
    }
    else{
        //check if the max value in the left subtree is greater than current node's data
        return is_binary_search_tree(current_node->left,min,current_node->data-1) &&
        
        //Check if the min value in the right subtree is greater than the current node's data
        is_binary_search_tree(current_node->right, current_node->data, max);
    }
}
bool Algorithm::checkBST(Node* root){
    return is_binary_search_tree(root, INT_MIN, INT_MAX);
}


//Check for anagram
//Add the ASCII values and check if the sums are equal
bool Algorithm::is_anagram(string a, string b){
    int sum_a = 0, sum_b = 0;
    
    for(int i = 0; i < a.length(); i++){
        sum_a += a[i];
    }
    
    for(int i = 0; i < b.length(); i++){
        sum_a += b[i];
    }
    
    return sum_a == sum_b;
}

/*bool is_anagram(string a, string b){
    unordered_map<char, int>counter;
    
    if(a.length() != b.length()){
        return 0;
    }
    
    //instantiate a count map
    for(int i = 'a'; i <= 'z'; i++){
        counter[i] = 0;
    }
    
    //Increase the counter for each character
    for(int i = 0; i < a.length(); i++){
        counter[a[i]]++;
    }
    
    //Decrease the counter and check if the counter is zero
    for(int i = 0; i < a.length(); i++){
        counter[a[i]]--;
        
        if(

    }
    
    
    
}*/
