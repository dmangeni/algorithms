//  Created by DorahMangeni on 1/2/17.
//  Copyright © 2017 DorahMangeni. All rights reserved.

#include <iostream>
#include <vector>
#include "time.h"
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#include "algorithm.h"

using namespace std;

/*Replace two adjacent digits with an average of the two digits that will provide the largest number
 For example, from the integer X = 233614, you can obtain:
 
 33614 (by replacing 23 with 3);
 23614 (by replacing 33 with 3 )
 23514 (by replacing 36 with 5);
 23344 (by replacing 61 with 4);
 23363 (by replacing 14 with 3);
 
 The maximum number in this case will be 33,614 
 
 */

int find_maximum_replacement(int num){
    int retval = 0;
    
    vector<int>new_vector;
    int temp = num;
    
    //integers are inserted in reverse order
    while(temp > 0){
        new_vector.push_back(temp % 10);
        temp = temp / 10;
    }
    
    //reverse the order of the vector
    reverse(new_vector.begin(), new_vector.end());
    
    //int max_digit = INT_MIN;
    //int index_to_replace = 0;
    
    for(int i = 0; i < new_vector.size(); i++){
        
        //Add 0.5 because the compiler will always truncate when rounding to an int
        int result = ((double)((new_vector[i] + new_vector[i+1])/2.0)) + 0.5;
        
        //Check if the result is greater than the digit at the current position
        if(result > new_vector[i]){
            new_vector[i] = result;
            new_vector.erase(new_vector.begin()+ (i+1));
            break;
        }
    }
    
    size_t j = new_vector.size()-1;
    for(int i = 0; i < new_vector.size(); i++){
        retval = retval + (new_vector[i] * pow(10.0, (double)j));
        j--;
    }
    
    return retval;
}


/*Insider Trader: 

Find the trader that satisfies the demand that the profit made and loss prevented within 3 days is after
buying the stock is greater than or equal to $5 million, assuming there is only one stock. The trader's transaction is
like 11|Bob|BUY|100000 which is day|tradername|TYPE|amount. and the stock price is day|price, like 22|13. and the ouput in
day sorted first and then by traderName sorted 
 
*/

int number_needed(string a, string b) {
    unordered_map<char, int>counter;
    
    unsigned int deletions = 0;
    
    //instantiate a count map
    for(char i = 'a'; i <= 'z'; i++){
        counter[i] = -1;
    }
    
    //Increase the counter for each character
    for(int i = 0; i < a.length(); i++){
        counter[a[i]]++;
    }
    
    //increase the counter for each character and
    //check if the counter is an even number
    for(int i = 0; i < b.length(); i++){
        counter[b[i]]++;
    }
    
    for(auto &it : counter){
        if((it.second % 2) == 0){
            deletions++;
        }
    }
    return deletions;
}

int main(int argc, const char * argv[]) {
    
    /*/Test cases. Will be implementing these using CATCH soon!
    
    cout << find_maximum_replacement(623315) <<endl; //63315
    cout << find_maximum_replacement(233614) <<endl; //33614
    cout << find_maximum_replacement(123) <<endl; //23
    cout << find_maximum_replacement(1234) <<endl; //234
    cout << find_maximum_replacement(2321) <<endl; //321
    cout << find_maximum_replacement(23) <<endl;*/
    
    /*vector<int>nums = { 1, 3, 5, 6, 7, 9};
    int target = 12;
    
    Algorithm a;
    vector<int>temp = a.twoSum(nums, target);
    a.print(temp);*/
    
    string a = "cde";
    string b = "abc";
    
    cout << number_needed(a,b) <<endl;
    
    return 0;
    
}
