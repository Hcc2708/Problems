class Solution{
    static bool cmp(pair<int, int> &a, pair<int, int> &b)
    {return a.second<b.second;}
public:
  vector<int> maximumToys(int N,vector<int> A,int Q,vector<vector<int>> Queries){
      // code here
       vector<int>D;
       map<int, int>M;
       for(int k = 0; k<A.size(); k++)
       {
          M.insert(pair<int, int>(k, A[k]));
       }

       vector<pair<int,int>>O;
       for(auto& it:M)
       O.push_back(it);
       sort(O.begin(), O.end(), cmp);


      for(int i = 0; i<Q; i++)
      {
          int C = Queries[i][0];
          int K = Queries[i][1];

          vector<int>temp = A;
          for(int x = 2; x<Queries[i].size(); x++)
          {
              temp[Queries[i][x]-1] = -1;
          }

          int count1 = 0;
          int sum = 0;

          for(auto &it : O){
              if(temp[it.first] >= 0)
              {
                  sum += it.second;
                  if(sum>C)
                  break;
                  count1++;

              }

          }
          if(count1 != 0)
          D.push_back(count1);
          if(count1==0)
          D.push_back(0);


      }
      return D;
  }
};
