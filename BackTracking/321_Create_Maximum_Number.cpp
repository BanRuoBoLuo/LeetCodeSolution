
#include <vector>
#include <string>
#include <iostream>

using namespace std;
    
    void traverse(const vector<int>& nums1, int p1, const vector<int>& nums2, int p2, int k, string& path, string& rst) {
        int M = nums1.size(), N = nums2.size();
        if(M-p1+N-p2 < k) return;
        if(k == 0) {
            rst = max(rst, path);
            return;
        }
        
        if(p1<M) {
            traverse(nums1, p1+1, nums2, p2, k, path, rst);
            path.push_back('0'+nums1[p1]);
            traverse(nums1, p1+1, nums2, p2, k-1, path, rst);
            path.pop_back();
        }
        if(p2 < N) {
            traverse(nums1, p1, nums2, p2+1, k, path, rst);
            path.push_back('0'+nums2[p2]);
            traverse(nums1, p1, nums2, p2+1, k-1, path, rst);
            path.pop_back();
        }
    }
    
    string maxNumberStr(vector<int>& nums1, vector<int>& nums2, int k) {
        string path, rst;
        traverse(nums1, 0, nums2, 0, k, path, rst);
        
        return rst;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> result(k);
        string rst = maxNumberStr(nums1, nums2, k);
        
        transform(rst.begin(), rst.end(), result.begin(), [](char c){return c-'0';});
        return result;
    }

    int main(){
        vector<int> nums1{5,9,3,7,5,6,2,3};
        vector<int> nums2{3,8,1,2,8,6,0,8};

        cout << maxNumberStr(nums1, nums2, 8) <<endl;
        return 0;
    }
