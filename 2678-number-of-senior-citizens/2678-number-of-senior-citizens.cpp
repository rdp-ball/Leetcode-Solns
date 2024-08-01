class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for ( string x : details){
            string l=x.substr(11,2);
            int age=stoi(l);
            if(age > 60 ){
                count++;
            }
        }
        return count;
        
    }
};