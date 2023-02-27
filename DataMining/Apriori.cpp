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
void prune(ItemsetCount &itemset_count, Dataset &data, int min_support) {
    for (auto it = itemset_count.begin(); it != itemset_count.end();) {
        int count = 0;
        for (Itemset itemset : data) {
            if (includes(itemset.begin(), itemset.end(), it->first.begin(), it->first.end())) {
                count++;
            }
        }
        if (count < min_support) {
            it = itemset_count.erase(it);
        } else {
            it++;
        }
    }
}
ItemsetCount frequentItemSet(Dataset &dataset, int k, int min_support = 2) {
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

    // prune(itemset_count, dataset, min_support);
    for (auto it = itemset_count.begin(); it != itemset_count.end(); ++it) {
        Itemset item = it->first;
        for (auto i : item)
            cout << i;
        cout << ":" << it->second << endl;
    }
    if (itemset_count.empty()) {
        return itemset_count;
    }
    return itemset_count;
}
int main(int argc, char const *argv[]) {
    /* code */
    Dataset dataset;

    ifstream infile("input.txt");
    string line;
    int total_lines = 0;
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
    frequentItemSet(dataset, dataset.size(), total_lines * 0.5);
    return 0;
}
