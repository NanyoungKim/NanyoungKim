#include<iostream>
#include<vector>

using namespace std;

int solution(vector<int> stones, int k) {
   int answer = 0;


   bool flag = true;
   int currentStone = 0;

   while (flag) {
      int i = 0;
      //currentStone = 0;

      for (; i < stones.size(); ++i) {

         if (currentStone + k >= stones.size()) {
            answer++; 
         }

         if (stones[i] != 0) {
            stones[i] -= 1;
            currentStone = i;
         }
            else {
            int chkCount = 0;

            for (int j = 0; j < k; j++) {

               

               int check = i;
               if (stones[check + 1] == 0) {
                  check++;
               }
               else {
                  stones[check + 1] -= 1;
                  currentStone = check + 1;
                  i = currentStone;
                  break;
               }


            }

            if (chkCount == k) {
               flag = false;
            }

         }


         if (currentStone >= stones.size()-1) {
            answer++;
         }


      }



   }



   return answer;
}

int main() {


   int K = 3;
   vector<int> Stones = { 2,4,5,3,2,1,4,2,5,1 };

   solution(Stones, K);

   return 0;
}
