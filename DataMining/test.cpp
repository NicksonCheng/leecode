#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
int main(int argc, char const *argv[]) {
    ifstream infile;
    ofstream outfile;
    infile.open("seqdata.txt");
    outfile.open("output.txt");
    string line;

    int line_idx = 1;

    while (getline(infile, line)) {
        /* code */
        stringstream ss(line);
        int seq_id;
        int value;
        int item_id;
        int count = 0;
        ss >> seq_id;
        if (seq_id == 8252)
            cout << line << endl;
        while (ss >> item_id >> value) {
            if (value == 9) {
                ++count;
                // cout << seq_id << endl;
                //  cout << line << endl;
                //    cout << "---------------------------" << endl;
            }

            /* code */
        }
        if (count > 0) cout << seq_id << " " << count << endl;
        ++line_idx;
    }

    infile.close();
    outfile.close();
    return 0;
}
