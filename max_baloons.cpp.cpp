#include <iostream>
using namespace std;

int maxCoins(vector<int>& nums) {
    /* O(n^3) Time and O(n^2) Space diffent values */
    int size = nums.size();
    if(size == 0)
        return 0;
        
    int i, j, k;
    vector< vector<int> > dp(size, vector<int>(size, 0));
       
    for(int len = 1; len <= size; len++){
        for(i = 0; i <= size - len; i++){
            j = len + i - 1;
            for(k = i; k <= j; k++){ 
                /* Left/Right Value has default 1 but holds prev and after ballon value if k is in middle */
                int leftValue  = 1;
                int rightValue = 1;
                    
                if(i != 0)
                    leftValue  = nums[i-1];
                if(j != size-1)
                    rightValue = nums[j+1];
                        
                /* Before and After - current k balloon is last to burst select the left side and right side to burst */
                int before = 0;
                int after  = 0;
                    
                if(i != k)
                    before = dp[i][k-1];
                if(j != k)
                    after  = dp[k+1][j];
                    
                dp[i][j] = max(dp[i][j], 
                         leftValue * nums[k] * rightValue + before + after);
            }   
        }
    }    
    return dp[0][size-1];
}

int maxcoins(int A[],int siz) //same values
{
    int nums[siz+2];
    int n=1;
 
    for(int i=0;i<siz;i++)
    {
        if(A[i]>0)
        {
            nums[n] = A[i];
            n++;
        }
    }
    nums[0] = nums[n] = 1;
    n++;
 
    int dp[n][n] = {};
 
    for(int j=2;j<n;j++)
    {
        for(int left=0;left<n-j;left++)
        {
            int right = left+j;
            for(int i = left+1;i<right;i++)
            {
                if(left==0 && right==n-1)
                    dp[left][right] = max(nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
                else
                    dp[left][right] = max(nums[left]*nums[right] + dp[left][i] + dp[i][right],dp[left][right]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return dp[0][n-1];
}
 
int main()
{
    int siz;
    cin >> siz;
    int A[siz];
    for(int i=0;i<siz;i++)
        cin >> A[i];
 
    int ans = maxcoins(A,siz);
    cout << ans << endl;
    return 0;
}

