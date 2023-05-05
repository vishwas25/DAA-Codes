#include<iostream>
using namespace std;

#define MAX 9999

int n=4; // Number of the places  want to visit

int distan[10][10] = {                
                    {0, 10, 15, 20},
                    {5, 0, 9, 10},
                    {6, 13, 0, 12},
                    {8, 8, 9, 0}
};
int completed_visit = (1<<n) -1;

int DP[16][4]; 

int  TSP(int mark,int position){

  if(mark==completed_visit){
  	return distan[position][0];
  }
  if(DP[mark][position]!=-1){
    return DP[mark][position];
  }

  //Here we will try to go to every other places to take the minimum
  // answer
  int answer = MAX;

  //Visit rest of the unvisited cities and mark the . Later find the 
  //minimum shortest path
  for(int city=0;city<n;city++){

    if((mark&(1<<city))==0){ // checking unvisited cities.

      int newAnswer = distan[position][city] + TSP( mark|(1<<city),city);
      answer = min(answer, newAnswer);
    }
  }
  return DP[mark][position] = answer;
}

int main(){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            DP[i][j] = -1;
        }
    }
  cout<<"Minimum Distance Travelled by you is "<<TSP(1,0);
  return 0;
}
