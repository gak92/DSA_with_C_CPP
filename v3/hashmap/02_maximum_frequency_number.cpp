int maximumFrequency(vector<int> &arr, int n)
{
  // Write your code here
  int maxFreq = 0;
  int res;
  unordered_map<int, int> count;

  for (int i = 0; i < arr.size(); i++)
  {
    count[arr[i]]++;
    maxFreq = max(maxFreq, count[arr[i]]);
  }

  for (int i = 0; i < arr.size(); i++)
  {
    if (count[arr[i]] == maxFreq)
    {
      res = arr[i];
      break;
    }
  }

  return res;
}