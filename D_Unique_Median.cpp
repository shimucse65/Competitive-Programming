#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = 2e18 + 7;

ll calculate_bad_subarrays(vector<int> &values, int n, vector<int> &original_values, int x) {
    vector<int> prefix_sum(n + 1, 0);
    vector<int> transformed_prefix(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + values[i];
        transformed_prefix[i] = 2 * prefix_sum[i] - i;
    }

    map<int, int> odd_count, even_count;
    even_count[0] = 1;
    ll count_bad_subarrays = 0;
    int last_index = 0;
    bool median_found = false;

    for (int i = 1; i <= n; i++) {
        if (original_values[i] == x) {
            median_found = true;
            while (last_index != (i - 1)) {
                last_index++;
                if (last_index % 2 == 1) {
                    odd_count[transformed_prefix[last_index]]++;
                } else {
                    even_count[transformed_prefix[last_index]]++;
                }
            }
        }

        if (i % 2 == 1) {
            if (median_found) {
                count_bad_subarrays += odd_count[transformed_prefix[i]];
            }
        } else {
            if (median_found) {
                count_bad_subarrays += even_count[transformed_prefix[i]];
            }
        }
    }

    return count_bad_subarrays;
}

void solve() {
    int n;
    cin >> n;
    vector<int> original_values(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> original_values[i];
    }

    int max_value = 10;
    ll total_subarrays = static_cast<ll>(n) * (n + 1) / 2;
    ll bad_subarray_count = 0;

    vector<int> is_present(max_value + 1, 0);
    for (int i = 1; i <= n; i++) {
        is_present[original_values[i]] = 1;
    }

    for (int i = 1; i <= max_value; i++) {
        if (!is_present[i]) continue;

        vector<int> binary_transformed(n + 1);
        for (int j = 1; j <= n; j++) {
            binary_transformed[j] = (original_values[j] <= i) ? 0 : 1;
        }

        bad_subarray_count += calculate_bad_subarrays(binary_transformed, n, original_values, i);
    }

    cout << total_subarrays - bad_subarray_count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    for (int test = 1; test <= test_cases; test++) {
        solve();
    }

    return 0;
}
