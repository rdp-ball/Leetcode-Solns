class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        int n=n1+n2;
        int index1=n/2;
        int index2=index1-1;
        int count=0;
        int i=0; 
        int j=0;
        int ele1=-1;
        int ele2=-2;
        while (i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                if(count==index1 ) ele1=nums1[i];
                if(count==index2) ele2=nums1[i];
                count++;
                i++;
            }
            else {
                if(count==index1) ele1=nums2[j];
                if(count==index2) ele2=nums2[j];
                count++;
                j++;
            }
        }
        while (i < n1) {
            if (count == index1) ele1= nums1[i];
            if (count == index2) ele2 = nums1[i];
            count++;
            i++;
        }
        while (j < n2) {
            if (count == index1) ele1 = nums2[j];
            if (count == index2) ele2 = nums2[j];
            count++;
            j++;
        }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ele1;
    }

    return (double)((double)(ele1+ ele2)) / 2.0;
        
    }
};