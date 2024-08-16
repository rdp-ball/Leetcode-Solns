class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2)  return 0;
        int n=height.size();
        int leftmax=height[0], rightmax=height[n-1];
        int left=1,right=n-2;
        int ans=0;
        while ( left <=right){
            if(leftmax < rightmax){
                if(height[left] > leftmax){
                    leftmax=height[left];
                }
                else{
                    ans+=leftmax-height[left];
                }
                left++;
            }
            else{
                if(height[right] > rightmax){
                    rightmax=height[right];
                }
                else{
                    ans+=rightmax-height[right];
                }
                right--;

            }
        }
        return ans;
        
    }
};