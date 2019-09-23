#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;
using std::vector;

#define STRESS_TESTING false

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long) numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

long long MaxPairwiseProductfast(const std::vector<int>& numbers) {
    int n = numbers.size();

    // Find highest index
    int highest_index = -1;
    for (int counter = 0; counter < n; counter++) {
        if (highest_index == -1 || numbers[counter] > numbers[highest_index]) {
            highest_index = counter;
        }
    }

    int highest_index2 = -1; 
    // Find second highest index
    for (int counter = 0; counter < n; counter++) {
        if ((highest_index2 == -1 || numbers[counter] > numbers[highest_index2]) && (counter != highest_index)) {
            highest_index2 = counter;
        }
    }

    return (long long) numbers[highest_index] * numbers[highest_index2];
}

int main() {
    while(STRESS_TESTING){
        int n = rand() % 1000 + 2;
        vector<int> array(n);
        cout << n << "\n";
        for (int i = 0; i < n; i++){
            array[i] = rand() % 100000;
        }

        for (int i = 0; i < n; i++){
            cout << array[i] << " ";
        }
        cout << "\n";

        long long res1 = MaxPairwiseProduct (array);
        long long res2 = MaxPairwiseProductfast(array);

        if (res1 != res2) {
            cout << res1 << " " << res2;
            break;
        }
    }

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    cout << MaxPairwiseProductfast(numbers); 
    cout << "\n";
    return 0;
}
