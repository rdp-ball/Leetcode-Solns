class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,10001));
        for (auto edge : edges){
            matrix[edge[0]][edge[1]]=edge[2];
            matrix[edge[1]][edge[0]]=edge[2];

        }
        for (int i=0; i < n;i++){
            matrix[i][i]=0;
        }
        for (int via=0; via < n;via++){
            for (int i=0; i< n;i++){
                for (int j=0; j < n;j++){
                    matrix[i][j]=min(matrix[i][j],matrix[i][via]+matrix[via][j]);
                }
            }
        }
        int res=0;
        int smallest=n;
        for (int i=0; i< n;i++){
            int count=0;{
                for (int j=0; j< n;j++){
                    if(matrix[i][j] <= distanceThreshold){
                        count++;
                    }
                }
                if(count <=smallest){
                    res=i;
                    smallest=count;
                }
            }
        }
        return res;



        
    }
};