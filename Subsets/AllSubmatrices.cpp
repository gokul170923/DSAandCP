#include<bits/stdc++.h>
using namespace std;

void printSubmatrices(vector<vector<int>>& arr) {
    
    int n = arr.size(),m = arr[0].size();
    for(int OuterRow =0; OuterRow<n; OuterRow++){

        for(int OuterCol =0; OuterCol<m; OuterCol++){

            for(int InnerRow =0; InnerRow <=OuterRow; InnerRow++){

                for(int InnerCol=0; InnerCol <= OuterCol; InnerCol++){

                    //printing submatrix
                    for(int i= InnerRow; i<= OuterRow; i++){
                        for(int j= InnerCol; j<= OuterCol; j++){
                            cout<<arr[i][j]<<' ';
                        }
                        cout<<endl;
                    }
                    cout<<endl;
                }
            }
        }
    }

}


int main(){
    vector<vector<int>>arr={{1,2},{3,4}};
    printSubmatrices(arr);
}