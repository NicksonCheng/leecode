#include <algorithm>
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
void prune(ItemsetCount &itemset_count, Dataset &data, double min_support) {
    for (auto it = itemset_count.begin(); it != itemset_count.end();) {
        int count = 0;
        for (Itemset itemset : data) {
            if (includes(itemset.begin(), itemset.end(), it->first.begin(), it->first.end())) {
                count++;
            }
        }
        if (count < data.size() * min_support) {
            it = itemset_count.erase(it);
        } else {
            it++;
        }
    }
}

ItemsetCount generateCandidate(ItemsetCount itemset_count, Dataset &data, double min_sup) {
    // generate Ck+1 from Lk
    ItemsetCount candidate_count;
    for (auto it1 = itemset_count.begin(); it1 != itemset_count.end(); ++it1) {
        for (auto it2 = next(it1); it2 != itemset_count.end(); ++it2) {
            Itemset candidate_itemset(it1->first.begin(), it1->first.end());
            candidate_itemset.insert(it2->first.begin(), it2->first.end());
            candidate_count[candidate_itemset] = 0;
            // check is frequent itemsets
            for (int j = 0; j < data.size(); ++j) {
                Itemset transactions = data[j];
                if (includes(transactions.begin(), transactions.end(), candidate_itemset.begin(), candidate_itemset.end())) {
                    candidate_count[candidate_itemset]++;
                }
            }
            prune(candidate_count, data, min_sup);
        }
    }
    return candidate_count;
}
int main(int argc, char const *argv[]) {
    /* code */
    Dataset dataset;

    ifstream infile("input.txt");
    string line;
    int total_lines = 0;
    double min_sup = 0.2;
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
        total_lines++;
    }
    // Ck: Candidate itemset of size k
    // Lk : frequent itemset of size k
    //  find frequent item set with L1
    ItemsetCount itemset_count;
    for (Itemset itemset : dataset) {
        // cout << itemset.size() << endl;
        for (auto it = itemset.begin(); it != itemset.end(); ++it) {
            Itemset item = {*it};
            if (itemset_count.find(item) == itemset_count.end()) {
                // can't find any item in itemset_count
                itemset_count[item] = 1;
            } else {
                itemset_count[item]++;
            }
        }
    }
    // prune the itemset less than minimum support
    prune(itemset_count, dataset, min_sup);

    while (!itemset_count.empty()) {
        /* code */
        // find Lk frequent itemset
        for (auto it = itemset_count.begin(); it != itemset_count.end(); ++it) {
            Itemset item = it->first;
            for (auto i : item)
                cout << i;
            cout << ":" << it->second << endl;
        }
        itemset_count = generateCandidate(itemset_count, dataset, min_sup);
    }

    return 0;
}
