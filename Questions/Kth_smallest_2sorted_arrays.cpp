#include <iostream>
#include <vector>
#include <algorithm>



int kthSmallestElement(const std::vector<int>& A, const std::vector<int>& B, int k) {
    int m = A.size();
    int n = B.size();
    if (m > n) {
        return kthSmallestElement(B, A, k); // Ensure A is the smaller array
    }

    int low = std::min(A[0], B[0]);
    int high = std::max(A[m - 1], B[n - 1]);
    int result = 0;

    while (low < high) {
        int mid = low + (high - low) / 2;
        int countA = std::upper_bound(A.begin(), A.end(), mid) - A.begin();
        int countB = std::upper_bound(B.begin(), B.end(), mid) - B.begin();
        int totalCount = countA + countB;

        if (totalCount < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

int main() {
    std::vector<int> A = {0, 1, 3, 6, 11, 15, 18, 22, 32, 45};
    std::vector<int> B = {2, 5, 8, 12, 29};
    int k = 9;

    int kthElement = kthSmallestElement(A, B, k);
    std::cout << "The " << k << "th smallest element is: " << kthElement << std::endl;

    return 0;
}
