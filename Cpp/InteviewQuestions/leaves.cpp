/*
    Descriptions - A garden is represented as grid of leaves. Where number at each cell represent the number of leaves on the cell.
    There is a wind of Gust flowing in four Directione(Right, Down, Left, Up), with each wind the leaves shifted a cell on the wind
    direction. Once the leaves leave the grid the are flown away forever. Find number of leaves remaining in the Garden.
    input - 
    Grid of leaves (m*n)
    Gust of winds = RRLD
    output - 
    find number of leaves remaining 
*/

#include <iostream>
#include <vector>
using namespace std;

int numLeavesRemaining(vector<vector<int>> leaves, string wind){
    int ans=0;
    deque<int> row(leaves.size());
    deque<int> col(leaves[0].size());

    for(int i=0; i<leaves.size();i++){
        row[i]= i;
    }
    for(int i=0; i<leaves[0].size();i++){
        col[i]= i;
    }
    for(int i=0; i<wind.size();i++){
        if(wind[i]=='R'){
            col.pop_back();
            col.push_front(-1);
        }
        if(wind[i]=='L'){
            col.pop_front();
            col.push_back(-1);
        }
        if(wind[i]=='D'){
            row.pop_back();
            row.push_front(-1);
        }
        if(wind[i]=='U'){
            row.pop_front();
            row.push_back(-1);
        }
    }
    while(!row.empty()){
        int r = row.front();
        row.pop_front();
        if(r==-1){
            continue;
        }
        for(auto it = col.begin();it<col.end(); it++){
            cout<<"col :"<<*it;
            if(*it== -1){
                continue;
            }
            ans += leaves[r][*it];
        }
    }
    return ans;
}

int main(){
    cout<<"sample test 1"<<endl;
    vector<vector<int>> leaves = {{1,0,0,0},
                                {0,2,0,2},
                                {3,0,0,0}};
    string wind ="RRD";
    int ans = numLeavesRemaining(leaves, wind);
    cout<<"number of leaves remaining "<<ans<<endl;

    cout<<"sample test 2"<<endl;
    leaves = {{1,0,0,0},
            {1,2,0,2},
            {0,2,0,2},
            {3,0,0,0}};
    wind ="RRDL";
    ans = numLeavesRemaining(leaves, wind);
    cout<<"number of leaves remaining "<<ans<<endl;

    return 0;
}