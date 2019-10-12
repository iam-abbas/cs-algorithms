//Program to convert given number to words

#include<bits/stdc++.h>
using namespace std;

string twoDigit(int num,map<int,string> mp){
	if(mp.find(num) != mp.end())
		return mp[num];
	return mp[(num/10)*10] + " " + mp[num%10];
}

string threeDigit(int num,map<int,string> mp){
	if(num / 100 && num % 100)
		return mp[num/100] + " Hundred " + twoDigit(num%100,mp);
	else if(num/100)
		return mp[num/100] + " Hundred ";
	return twoDigit(num%100,mp); 
}

string numberToWords(long int num,map<int,string> mp){
	if(!num)
		return "Zero";

    int part1 = num % 1000;
    int part2 = (num / 1000) % 1000;
    int part3 = (num / 1000000) % 1000;
    int part4 = num / 1000000000;
    string result = "";
    
    if(part4) 
    	result += twoDigit(part4,mp)+" Billion ";
    if(part3) 
    	result += threeDigit(part3,mp)+" Million ";
    if(part2) 
    	result += threeDigit(part2,mp)+" Thousand ";
    result += threeDigit(part1,mp);
    return result;
}

int main(){
	long int num;
	map<int,string> mp;
	mp[1] = "One"; mp[2] = "Two"; mp[3] = "Three"; mp[4] = "Four"; mp[5] = "Five";
    mp[6] = "Six"; mp[7] = "Seven"; mp[8] = "Eight"; mp[9] = "Nine"; mp[10] = "Ten";
    mp[11] = "Eleven"; mp[12] = "Twelve"; mp[13] = "Thirteen"; mp[14] = "Fourteen";
    mp[15] = "Fifteen"; mp[16] = "Sixteen"; mp[17] = "Seventeen"; mp[18] = "Eighteen";
    mp[19] = "Nineteen"; mp[20] = "Twenty"; mp[30] = "Thirty"; mp[40] = "Forty";
    mp[50] = "Fifty"; mp[60] = "Sixty"; mp[70] = "Seventy";  mp[80] = "Eighty";
    mp[90] = "Ninety";

	cin>>num;
	string result = numberToWords(num,mp);
	cout<<result;
}