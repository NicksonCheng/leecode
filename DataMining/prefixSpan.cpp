#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef set<int> Itemset;
typedef vector<set<int>> Sequence;
typedef vector<vector<set<int>>> Dataset;
typedef map<Sequence, int> SeqeunceCount;
int access_set(Itemset items, int idx) {
    auto it = items.begin();
    advance(it, idx);
    return *it;
}
void pruning(SeqeunceCount &seq_count, int k) {
    for (auto it = seq_count.begin(); it != seq_count.end(); ++it) {
        Sequence seq = it->first;
        // if(seq.size())
    }
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
void printSupport(SeqeunceCount seq_count) {
    for (auto it = seq_count.begin(); it != seq_count.end(); ++it) {
        Sequence seq = it->first;
        for (auto it2 = seq.begin(); it2 != seq.end(); ++it2) {
            Itemset item = *it2;
            for (auto &it3 : item)
                cout << it3 << " ";
        }
        cout << ":" << it->second << endl;
    }
}
int countFrequence(Sequence candidate_seq, Dataset data) {
    int count = 0;
    for (int i = 0; i < data.size(); ++i) {
        Sequence trans_seq = data[i];
        if (includes(trans_seq.begin(), trans_seq.end(), candidate_seq.begin(), candidate_seq.end()))
            ++count;
    }
    return count;
}
SeqeunceCount generateCandidate(SeqeunceCount seq_count, Dataset data, set<int> all_items, int min_freq) {
    SeqeunceCount candidate_seq_count;
    for (auto it = seq_count.begin(); it != seq_count.end(); ++it) {
        Sequence candidate_seq(it->first.begin(), it->first.end());

        for (auto &it2 : all_items) {
            // expand the sequence set
            // generate sequence set <(1)> -> <(1)(2)> <(1)(3)> ....
            Itemset itemset = {it2};
            candidate_seq.push_back(itemset);
            int c = countFrequence(candidate_seq, data);
            if (c >= min_freq)
                candidate_seq_count[candidate_seq] = c;
        }
        candidate_seq = it->first;
        Itemset last_itemset = candidate_seq.back();
        candidate_seq.pop_back();
        for (auto &it2 : all_items) {
            // expand the itemset in sequence
            // generate itemset  <(1)> -> <(1,2)> <(1,3)> ....
            last_itemset.insert(it2);
            candidate_seq.push_back(last_itemset);
            int c = countFrequence(candidate_seq, data);
            if (c >= min_freq)
                candidate_seq_count[candidate_seq] = c;
        }
    }
    return candidate_seq_count;
}
int main(int argc, char const *argv[]) {
    Dataset dataset;
    SeqeunceCount seq_count;
    set<int> all_items;
    ifstream infile;
    ofstream outfile;
    infile.open("seqdata.txt");
    outfile.open("output.txt");
    string line;
    double min_sup = 0.01;

    while (getline(infile, line)) {
        /* code */
        Sequence sequnece;
        Itemset itemset;
        int seq_id = 0;
        int item_id = 0;
        int item = 0;
        int curr_id = 0;

        stringstream ss(line);
        ss >> seq_id;
        ss >> curr_id >> item;
        itemset.insert(item);
        all_items.insert(item);
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
            all_items.insert(item);
        }
        // in loop end, there still have item in itemset
        // only one itemsets
        sequnece.push_back(itemset);
        dataset.push_back(sequnece);
    }
    // printSequence(dataset);
    //   find 1 frequent items
    for (int i = 0; i < dataset.size(); ++i) {
        for (int j = 0; j < dataset[i].size(); ++j) {
            Itemset items = dataset[i][j];
            // seperate the items and use the value to create 1-element itemset
            for (auto &item : items) {
                Itemset new_item = {item};
                Sequence seq;
                seq.push_back(new_item);
                if (seq_count.find(seq) == seq_count.end()) {
                    seq_count[seq] = 1;
                } else
                    seq_count[seq]++;
            }
        }
    }
    cout << seq_count.size() << " " << all_items.size() << endl;

    while (!seq_count.empty()) {
        /* code */
        SeqeunceCount seq_count = generateCandidate(seq_count, dataset, all_items, (int)min_sup * dataset.size());
        cout << seq_count.size() << endl;
        printSupport(seq_count);
        break;
    }

    infile.close();
    outfile.close();
    return 0;
}
