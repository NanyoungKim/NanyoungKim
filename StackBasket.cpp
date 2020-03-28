#include <iostream>
#include <vector>
#include <string>
//#include <cmath>
#include <stack>


using namespace std;



int solution(vector<vector<int>> board, vector<int> moves) {
   int answer = 0;

   int crane = 0;
   int moveSize = moves.size();

   //int boardRowSize = (int)sqrt((double)board.size());
   int boardRowSize = board[0].size();
   
   stack<int> basket;


   for (int i = 0; i < moveSize; i++) {

      crane = moves[i];

      for (int j = 0; j < boardRowSize; j++) {
         
         if (board[j][crane - 1] != 0) {
            basket.push(board[j][crane - 1]);
            board[j][crane - 1] = 0;
            break;
         }
      }

      
      if (basket.size() > 1) {

         int stackTop = basket.top();
         basket.pop();
         int stackUnderTop = basket.top();
         if (stackTop == stackUnderTop) {
            basket.pop();
            answer += 2;
         }
         else {
            basket.push(stackTop);
         }


      }

   }

   

   cout << "답 : " << answer << endl;


   return answer;
}


int main() {


   vector<vector<int>> Board;

   vector<int> v1 = { 0,0,0,0,0 };
   vector<int> v2 = { 0,0,1,0,3 };
   vector<int> v3 = { 0,2,5,0,1 };
   vector<int> v4 = { 4,2,4,4,2 };
   vector<int> v5 = { 3,5,1,3,1 };

   Board.push_back(v1);
   Board.push_back(v2);
   Board.push_back(v3);
   Board.push_back(v4);
   Board.push_back(v5);
   
   
   for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
         cout << Board[i][j] << " ";
      }
      cout << endl;
   }


   vector<int> Moves = { 1,5,3,5,1,2,1,4 };
   

   cout << solution(Board, Moves);

   
   system("out");
   return 0;


}
