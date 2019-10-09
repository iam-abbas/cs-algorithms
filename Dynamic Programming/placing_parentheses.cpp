#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums, int k) 
{
    int sum0=accumulate(nums.begin(),nums.end(),0);
    if(sum0%k) return 0;
    //discrete knapsack without repeti 
    int n=nums.size();
    vector<vector<int> > value(sum0/k+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)
    {
        int wi=nums[i-1];
        //cout<<wi<<endl;
        for(int w=1;w<=sum0/k;w++) //all smaller problems
        {
            value[w][i]=value[w][i-1];//if w>wi then it use previous value
            if(w>=wi)
            {
                value[w][i]=max(value[w-wi][i-1]+wi,value[w][i-1]);                    
            }
        }
     }
    return value[sum0/k][n]==sum0/k; 
	}

int main(int argc, char const *argv[])
{
	int n, k =3;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	cout << canPartition(nums, k);
	return 0;
}
