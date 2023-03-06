#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef set<int> Itemset;
typedef vector<set<int>> Sequnce;
typedef vector<vector<set<int>>> Dataset;
typedef map<Sequnce, int> SeqeunceCount;
int access_set(Itemset items, int idx) {
    auto it = items.begin();
    advance(it, idx);
    return *it;
}
void findFreqItems() {
}
void printSequence(Dataset data) {
    for (int i = 0; i < data.size(); ++i) {
        cout << "id:" << i + 1 << " ";
        for (int j = 0; j < data[i].size(); ++j) {
            cout << "(";
            Itemset itemset = data[i][j];
            for (auto it = itemset.begin(); it != itemset.end(); ++it) {
                cout << *it;
                if (next(it) != itemset.end()) cout << " ";
            }
            cout << ")";
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[]) {
    Dataset dataset;
    SeqeunceCount seq_count;
    ifstream infile;
    ofstream outfile;
    infile.open("seqdata.txt");
    outfile.open("output.txt");
    string line;
    while (getline(infile, line)) {
        /* code */
        Sequnce sequnece;
        Itemset itemset;
        int seq_id = 0;
        int item_id = 0;
        int item = 0;
        int curr_id = 0;
        stringstream ss(line);
        ss >> seq_id;
        ss >> curr_id >> item;
        itemset.insert(item);

        // craete database
        while (ss >> item_id >> item) {
            /* code */
            if (item_id != curr_id) {
                sequnece.push_back(itemset);
                itemset.clear();

                curr_id = item_id;
            }
            // new item id item
            itemset.insert(item);
        }
        // in loop end, there still have item in itemset
        // only one itemsets
        sequnece.push_back(itemset);
        dataset.push_back(sequnece);
    }
    // printSequence(dataset);
    //   find 1 frequent items
    for (int i = 0; i < dataset.size(); ++i) {
        if ((i + 1) == 8252) {
            for (int j = 0; j < dataset[i].size(); ++j) {
                Itemset items = dataset[i][j];
                cout << "(";
                for (auto &it : items)
                    cout << it << " ";
                cout << ")";
            }
            cout << endl;
        }
        int c = 0;
        for (int j = 0; j < dataset[i].size(); ++j) {
            Itemset items = dataset[i][j];
            // seperate the items and use the value to create 1-element itemset

            for (auto &item : items) {
                if (item == 9) {
                    ++c;
                }
                Itemset new_item = {item};
                Sequnce seq;
                seq.push_back(new_item);
                if (seq_count.find(seq) == seq_count.end()) {
                    seq_count[seq] = 1;
                } else
                    seq_count[seq]++;
            }
        }
        if (c > 0) cout << i + 1 << " " << c << endl;
    }
    cout << seq_count.size() << endl;
    Itemset tmp = {9};
    Sequnce tmp2;
    tmp2.push_back(tmp);
    cout << seq_count[tmp2] << endl;
    // for (auto it = seq_count.begin(); it != seq_count.end(); ++it) {
    //     Sequnce seq = it->first;
    //     for (auto it2 = seq.begin(); it2 != seq.end(); ++it2) {
    //         Itemset item = *it2;
    //         for (auto &it3 : item)
    //             cout << it3 << " ";
    //     }
    //     cout << ":" << it->second << endl;
    // }
    infile.close();
    outfile.close();
    return 0;
}
