#include <iostream>
using namespace std;
int parent[300001];  // decide the people pair
int sum[300001];
int find(int n) {
    if (parent[n] == n)
        return parent[n];
    else
        return find(parent[n]);
}
int main(int argc, char const *argv[]) {
    /* code */
    int num_data = 0;
    cin >> num_data;
    for (int i = 0; i < num_data; ++i) {
        int n, m;
        int largest_groups = 0;
        cin >> n >> m;
        for (int j = 0; j < n; ++j) {
            parent[j] = j;
            sum[j] = 1;
        }

        for (int j = 0; j < m; ++j) {
            int n1, n2;
            cin >> n1 >> n2;
            int p_1 = find(n1);
            int p_2 = find(n2);

            if (p_1 != p_2) {
                // p1 p2 is not same pair
                // if it is the new group just decode one as parent
                // if it is exist group just assign the new number index to parent

                parent[p_2] = p_1;
                sum[p_1] += sum[p_2];
                if (sum[p_1] > largest_groups)
                    largest_groups = sum[p_1];
            }
        }
        cout << largest_groups << endl;
    }
    return 0;
}
