#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef vector<set<int>> Dataset;
typedef set<int> Itemset;
typedef map<Itemset, int> ItemsetCount;
void frequentItemSet(vector<set<int>> dataset, int k, int min_support = 2) {
    for (Itemset itemset : dataset) {
        // cout << itemset.size() << endl;
        for (auto it = itemset.begin(); it != itemset.end(); ++it) {
            cout << *it << endl;
        }
    }
}
int main(int argc, char const *argv[]) {
    /* code */
    Dataset dataset;

    ifstream infile("input.txt");
    string line;
    while (getline(infile, line)) {
        cout << line << endl;
        int item;
        Itemset itemset;
        stringstream ss(line);

        while (ss >> item) {
            /* code */
            itemset.insert(item);
        }
        dataset.push_back(itemset);
    }
    frequentItemSet(dataset, dataset.size(), 2);
    return 0;
}
