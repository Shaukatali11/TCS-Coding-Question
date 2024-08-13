Q1.

  Given two integer n and m, calculate the sum of cube of all number in the range.

-----------------------<>-------------------------SOLUTION-------------------<>----------------------------------------
#include<bits/stdc++.h>
using namespace std;

    int cubeSum(int n, int m){
    int sum=0;
    for(int i=n ;i<=m;i++){
        sum+=i*i*i;
    }
    return sum;
}


int main(){
    int n=4;
    int m=9;
    cout<< cubeSum(n,m);
    return 0;
}





---------------------------------<>----------------------QUESTION 2-------------------------------<>---------------------------------------------------<>---------------------

  Q2.
  You are given a list of sales queries. Each query consists of three parameters: item, quantity, and price. Your task is to perform the following operations:

Find the highest selling item: The item with the highest total sales (quantity multiplied by price).
Find the total sales of all items: The sum of the total sales for all items.
Find the average sales per item: The average of the total sales for each item.


Input:
Queries = [
    {"item": "apple", "quantity": 10, "price": 2},
    {"item": "banana", "quantity": 5, "price": 1},
    {"item": "orange", "quantity": 8, "price": 3},
    {"item": "apple", "quantity": 7, "price": 2}
]

Output:
Highest selling item: apple
Total sales: 55
Average sales per item: 18.33


---------------------------------<>-------------------------------------------------SOLUTION--------------------------------------------<>------------------------------------

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct Sale {
    string item;
    int quantity;
    double price;
};

void processSales(const vector<Sale> &queries) {
    unordered_map<string, double> salesMap;
    double totalSales = 0;
    string highestSellingItem;
    double highestSalesAmount = 0;

    for (const auto &query : queries) {
        double saleAmount = query.quantity * query.price;
        salesMap[query.item] += saleAmount;
        totalSales += saleAmount;

        if (salesMap[query.item] > highestSalesAmount) {
            highestSalesAmount = salesMap[query.item];
            highestSellingItem = query.item;
        }
    }

    double avgSales = totalSales / salesMap.size();

    cout << "Highest selling item: " << highestSellingItem << endl;
    cout << "Total sales: " << totalSales << endl;
    cout << "Average sales per item: " << avgSales << endl;
}

int main() {
    vector<Sale> queries = {
        {"apple", 10, 2.0},
        {"banana", 5, 1.0},
        {"orange", 8, 3.0},
        {"apple", 7, 2.0}
    };

    processSales(queries);

    return 0;
}
