#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Product {
    int id;
    int qty;
    int costP;
    int sellingP;
};
struct Query {
    int id;
    int qty;
    int payoff;
};
struct Customer {
    int budget;
    vector<Query> queries;
};
int solve(vector<Query> queries, int budget, int idx, vector<int> sellP) {
    int n = queries.size();
    if (budget == 0 || idx >= n)  {
        return 0;
    }

    int prodId = queries[idx].id;
    int cost = sellP[prodId]; 

    int opt1 = 0;
    if (cost <= budget) {
        opt1 = queries[idx].payoff + solve(queries, budget - cost, idx + 1, sellP);
    }
    int opt2 = solve(queries, budget, idx + 1, sellP);
    return max(opt1, opt2);
}
int main() {
    int num;
    cout << "Enter types of products available:\n";
    cin >> num;
    vector<Product> products(num);
    vector<int> sellP(num); 
    for (int i = 0; i < num; i++) {
        products[i].id = i;
        cout << "Enter Quantity available:\n";
        cin >> products[i].qty;
        cout << "Enter the cost price:\n";
        cin >> products[i].costP;
        cout << "Enter the selling price:\n";
        cin >> products[i].sellingP;
        sellP[i] = products[i].sellingP;
    }

    int n;
    cout << "Enter number of customers:\n";
    cin >> n;

    vector<Customer> vect(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter customer budget:\n";
        cin >> vect[i].budget;
        int m;
        cout << "Enter number of products:\n";
        cin >> m;
        vect[i].queries.resize(m); 
        for (int j = 0; j < m; j++) {
            cout << "Enter Product ID:\n";
            cin >> vect[i].queries[j].id;
            cout << "Enter quantity:\n";
            cin >> vect[i].queries[j].qty;
            cout << "Enter payoff:\n";
            cin >> vect[i].queries[j].payoff;
        }
    }
    vector<int> Payoffs(n);
    for (int i = 0; i < n; i++) {
        int payoff1 = solve(vect[i].queries, vect[i].budget, 0, sellP);
        Payoffs[i] = payoff1;
        cout << "Customer " << i + 1 << " max payoff = " << payoff1 << endl;
    }
    return 0;
}