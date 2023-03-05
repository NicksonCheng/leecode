#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>
using namespace std;
typedef set<int> Itemset;
typedef vector<set<int>> Sequnce;
typedef vector<vector<set<int>>> Dataset;
typedef map<int, Sequnce> SeqeunceCount;
int access_set(Itemset items, int idx) {
    auto it = items.begin();
    // return advance(it, idx);
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
        while (ss >> item_id >> item) {
            /* code */
            if (item_id != curr_id) {
                sequnece.push_back(itemset);
                itemset.clear();

                curr_id = item_id;
            }
            itemset.insert(item);
        }
        if (sequnece.empty())
            sequnece.push_back(itemset);
        dataset.push_back(sequnece);
    }
    printSequence(dataset);
    // find 1 frequent items
    for (int i = 0; i < dataset.size(); ++i) {
        for (int j = 0; j < dataset[i].size(); ++i) {
            Itemset items = dataset[i][j];
            if (items.size() < 2) {
                // int item = items.;
                // if (seq_count.find(item]) == seq_count.end())
                //     seq_count[items]
            }
        }
    }

    infile.close();
    outfile.close();
    return 0;
}
