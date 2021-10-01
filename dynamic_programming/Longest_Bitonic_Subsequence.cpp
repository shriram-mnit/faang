class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    vector<int> right(nums.size(),1),left(nums.size(),1);
	    for(int i=nums.size()-1;i>=0;i--)
	    {
	        for(int j=nums.size()-1;j>i;j--)
	        {
	            if(nums[i]>nums[j])
	             right[i]=max(right[j]+1,right[i]);
	        }
	    }
	    for(int i=0;i<nums.size();i++)
	    {
	        for(int j=0;j<i;j++)
	          {
	              if(nums[i]>nums[j])
	              left[i]=max(left[j]+1,left[i]);
	          }
	    }
	    int ans=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        ans=max(left[i]+right[i]-1,ans);
	    }
	    return ans;
	}
};
