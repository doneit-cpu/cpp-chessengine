// 1  make the attack or swap things functions now , also make the piece don't jump over any of the once , also we have castel move where king and rook changed 
// 2  move function which also changed position also that changed in the and mapping that also may used 
// checkmate function which used (1) (2) function keep king safe , also stop other from moving other side 
// make pawn a four other piece when it's reach end of both lines 
// two kings can't attack each others ** bcs simple for both it's danger and it can't go there 
// for diff piece white with 1 , black with -1 , none moves 0 ** this only to show which moves are valid and that it  
// one more function need we need to change our other piece position so we need to make function do that , like pawn kill queen then we need to know that queen is dead so we don't check at the checkmate function   
// meed to make vecotor or place which can tell i have piece or not , to help make sure it's checkmate or not , 
// we need to stop the game all the piece if the king is in direct site or danger first move the king , nothing move utill king out of danger
// we had made the inner circle which can tell whether move king there or not , but we also have make reactive based on the if attacker moved , killed , or someone comes between them after attacker has attacked 
#include<iostream>
#include<vector>
#include<map>
#include <algorithm>
using namespace std;

// ascii , position , i don't really need the pawn position they can only attack one block ahead , so do it removing is best move ,
map<int, vector<int>> pieces = {
    {81,  {59}},                 // Q
    {113, {3}},                  // q
    {75,  {60}},                  // K  // we also don't need king here , bcs 
    {107, {4}},                  // k
    {98,  {2,5}},                // b
    {66,  {58,61}},              // B
    {110, {1,6}},                // n
    {78,  {57,62}},              // N
    {82,  {56,63}},              // R
    {114, {0,7}},                // r: positions 0*8+0, 0*8+7 ,, positions/8 , positons%8
    {80,  {48,49,50,51,52,53,54,55}}, // P
    {112, {8,9,10,11,12,13,14,15}}, // p
};

vector<int> temp={8,9,10,11,12,13,14,15,48,49,50,51,52,53,54,55,0,7,56,63,57,62,1,6,58,61,2,5,4,60,3,59};
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low; j < high; j++) {
//         if (arr[j] < pivot) {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[i + 1], arr[high]);

//     return i + 1;
// }

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         int p = partition(arr, low, high);

//         quickSort(arr, low, p - 1);
//         quickSort(arr, p + 1, high);
//     }
// }


map<int,bool> lo_p; // lower case pawn
map<int,bool> Up_p; // higeher case pawn

map <int,bool>k_inner; // kings inner circke srrounding 9 , this would changed each time we move king so make this note 

bool low_case(char a){
  return (97<int(a)<122)?1:0;
}


// rather than just finding number we just make sure , which way or direction we had taken , then just add it same , make it number than we can get a piece betweeen them if looking 
// also when we can't move our piece , this case here explain first we have check the is there any piece between the king and attacker , if yes then we can't move , but also we don't any of this , king has changed the site , d
vector<vector<int>> moves;// moves 
// ahh , we can do one thing just do the sequnce(used the number rather then x,y) , like starting positon and end position , after we can used the binary search here , like see 
// this only check if any of the slides like rook , bishop , queen don't jump of the any piece which exsit


bool empaty_path(vector<vector<char>>& board, int ay,int ax,int dy,int dx){   
 { // int diff=abs((dy*8+dx)-(ay*8+ax));// we will per sort baed on the diff , both number here , then put those number for another round to find
  // vector<int>temp;    // this kind of doing taking every piece in between two piece , like if i got two piece and check how many are between them it's not check by path but simple how many between , like take whole between path rather digonal way , okay  
  // for(const auto& pair:pieces){
  //   for(int i=0;i<pair.second;i++){
  //     if((ay*8+ax)-diff<pair.second[i] && pair.second[i]<(dy*8+dx)){  
  //       temp.push_back(pair.second[i]);
  //     }
  //   }
  // }
 }
  int x=dy-ay; // whether we have look up or down
  int y=dx-ax;  // same here , if any of there are zero it's pretty simple just add or minus too find if something between or not , 
  if(abs(x)==abs(y)){ // we have go diagonal here 
    int n=abs(x);
    if(x<0 && y<0){   // -1 , -1 , y ,x
      for(int i=n;i>0;i--){
        if (board[ay++][ax++] != '.') return false;  // so this make sure betwen bishop and attack piece is nothing by checking each piece in diagonal way and "." this block has nothing got it 
      }
    }else if(y<0){    // -1  , 1
      for(int i=n;i>0;i--){   
        if (board[ay--][ax++] != '.') return false;  // same here with each one 
      }
    }else if(x<0){    //  1 , -1
      for(int i=n;i>0;i--){
        if (board[ay++][ax--] != '.') return false;
      }
    }else{            //  1 , 1 
      for(int i=n;i>0;i--){
        if (board[ay--][ax--] != '.') return false;
      }
    };
  }else if(x==0||y==0){ // rook moves
      if(x==0){
        if(y<0){     // -1 ,0  -down
          for(int i=abs(y);i>0;i--){      // like above things explain i put it there , it only check the vertifcal or horital way for the piece 
            if (board[ay--][ax] != '.') return false;
          }
        }else{      // 1 ,0    -up
          for(int i=abs(y);i>0;i--){
            if (board[ay++][ax] != '.') return false;
          }
        }
      }else{
        if(x<0){    //  0,-1  <-x
          for(int i=abs(x);i>0;i--){
            if (board[ay][ax--] != '.') return false;
          }
        }else{     //  0 ,1   x->
          for(int i=abs(x);i>0;i--){
            if (board[ay][ax++] != '.') return false;
          }
        }
      }
  }
  return true;
}

bool attack_af(char a , char b, int ay,int ax,int dy,int dx){
  // a attack b and remove b positoin from map
  if(int(b) = 75 || 107 ) return false ; // u can't king and remove it got it  
  if(low_case(a)!=low_case(b)){  // this make sure i;m firendly fire (b position removed from the map)
    for(int i =0;i<=pieces[int(b)].size();i++){  // here we get every b piece postion of board (above i have map )
      if(pieces[int(b)][i]==(dy*8+dx)){ // here i check that attacked piece got from map
        swap(pieces[int(b)][i],(pieces[int(b)].back()));// here i put selected the attacked pice
      }
    };
    pieces[int(b)].pop_back(); // here that last piece has gone last poistion and pop
  }else{ 
    return false;
  };
  return true;
  
};

// we will calling function problem check that for sure , 
void changed_m(vector<vector<char>>& board ,char a,int ay,int ax,int dy,int dx){
  // a has killed the b , and now it's goes b position so a will take b position 
    for(int i =0;i<=pieces[int(a)].size();i++){
      if(pieces[int(a)][i]==(ay*8+ax)){
        swap(pieces[int(a)][i],(pieces[int(a)].back()));
      }
    }
    pieces[int(a)].pop_back();
    pieces[int(a)].push_back((dy*8+dx));
    board[dy][dx]=board[ay][ax];
    board[ay][ax]='.';
}

// king is attack , only piece move which is in the of blocking that attack or king move safey if not check mate simple or attack and remove the piece which attacking the king got it , and this run each time when piece moved ,okay like , important thing i attack king of other one , and stop movment of other party  ,, 
bool direct_attacked(vector<vector<char>>& board ,int ay,int ax ,int ky,int kx){
    int x=abs(ay-ky);
    int y=abs(ax-kx); 
    if(( x==0 || y==0 || x==y )){  // bishop , rook , queen
      if(empaty_path(board,ay,ax,ky,kx)){ //

            return true;
          }
      }else if(( x==1 && y==2 ) || ( x==2 && y==1) ){ 

        // king has to move or attack attcking knight 
        return true;
      }else if(x==1 && (y==-1 || y==1)){

        // just move the king 
        return true;
      }
      return false;
  }

// bool godgod(vector<vector<char>>& board ,int r,int king_p){
//     for(int i=0;i<=7;i++){
//       int j =(king_p+(r));
//       int k=(king_p+(r));
//       if((0<=j+k<=63) && board[j][k]!='.'){
//         return false;
//       }
//       king_p=j+k;
//     }
//     return true;
// }

bool binarySearch(vector<int>& arr,int st,int ed ,int diff) {
  // ed-st = diff // so it carry charge or direction where to go 
  int target=st+(diff);
  int right = lower_bound(arr.begin(), arr.end(), ed) - arr.begin();
  int left = lower_bound(arr.begin(), arr.end(), st) - arr.begin();
  int reset=-1;   // used as reset point for another serach 
  int step=abs(ed-st)/abs(diff);
  while(step){      // what end is already small from beging bro ? 
      
      while (left <= right) {
        
        int mid = left + (right - left) / 2;
       
        if (arr[mid] == target) {
          return true;
        }

        else if (arr[mid] < target) { 
          // i'm going to left ? okay , and my target already become bigger then there is no way to check for thing from here to left anymore it's sorted array and uiniqe or pass value or it was never then ? so i choose new search from here okay ? 
          if(mid - 1 >= 0 && target > arr[mid - 1]){
            reset=mid;
            break;
          }
          left = mid + 1;
        }
       
        else {
           // i'm going to right ? okay , and my target already become smaller then next mid+1 there is nothing more to left to check  
           if(mid + 1 <= right && target < arr[mid + 1]){
            reset=mid;
            break;
          }
          right = mid - 1;
        }
      }
      if(reset!=-1){
        if(diff<0){
          right=reset;
        }else{
          left=reset;
        }
      }
      step--;
      target+=(diff);
    }
    return false;
}

bool indirect_attacked(vector<vector<char>>& board,char a){   // this run behind the code , so don't need this shit char a first 
  sort(temp.begin(), temp.end());
  int keep[6]={66,81,82,98,113,114}; // 
  int postion=pieces[75][0];
  int st=3;
  int ed=5;
  if(low_case(a)){
    st=0;
    ed=2;
    postion=pieces[107][0];
  }
    for (int i=st;i<=ed;i++) {
      for (int j=0;j<pieces[keep[i]].size();j++){  //
          int charge=1;
          int diff=pieces[keep[i]][j]-postion;    // this give distance between them 
          if(diff<0){
            charge=-1;
          }
          if((keep[i]!=82) && (keep[i]!=114)  && (diff%9 == 0) || (diff%7 ==0)  ){ // how stop rook getting here ? , this give or tell it's would be bishop or queen ,now when got diff -5 , means piece is ahead of king so we minus from the king  ,,,
            {

              // godgod()  // wil call and give diff to , it would 9 or 7 , it will it diagonal number repeat , and u know godgod is doing or checking if those number has anything between them got it 
              // (a!='r') && (a!='R')  && (diff%9 == 0) || (diff%7 ==0) , i think this would stop rook , first it let anything but small r came it will block in first plan and it's gone , assume now bigger rook came it not caught first trap abut other will stop which 1 and bcs 1 three dvide it's gone to right ?? 
            }
              if(diff%9 == 0){
                diff=9;
              }else{
                diff=7;
              }
             binarySearch(temp,postion,pieces[keep[i]][j],diff*charge);
          }else if((keep[i]!=66) && (keep[i]!=98) && (diff%8==0)){ // now just have stop the // same here ? 
              binarySearch(temp,postion,pieces[keep[i]][j],diff*charge);
          }else if ((keep[i]!=66) && (keep[i]!=98) &&  ((postion/8)==(pieces[keep[i]][j]/8)) ){ // this will never right , 
            {

              // int i=abs(diff);   // here i had to came and check the things between king and rook in same raw
              
              // find between king and 
              // now run binary for the small 1 2 3 in binary okay ? 
              
              // while(i>=0){
                //   if(diff>0){  // if diff plus as side it behind king means bigger number 
                //     if(((postion/8)+7>=pieces[keep[i]][j]) && board[postion/8][(postion%8)+1]!='.')return false;   // ths's y i add this ?(postion/8)+7>=pieces[keep[i]][j] ,, this will make sure u don't for more then king raw okay 
                //   }else{
                  //     if(((postion/8)-7<=pieces[keep[i]][j])&& board[postion/8][(postion%8)-1]!='.')return false;  // same here ?? 
                  //   }
                  //   i--;
                  // }
              }
              binarySearch(temp,postion,pieces[keep[i]][j],1*charge);
          }
      };
    }
  
}


// after move we would have see if this an checkmate or not , 
// we cover all the path first // we only have look at kings piece if any those nine squre piece then we have active  this function 
void checkmate(vector<vector<char>>& board ,int ay,int ax){ // first we have see if king has no way to go , and we don't have piece which can't move then win other side , or we safe with reamining piece , but we don't move so 

  // lower case king
  if(low_case(board[ay][ax])){


  }else{
    int x=pieces[75][0]/8; // send as k_s
    int y=pieces[75][0]%8; // send as k_e

  }


}



// black are in lowecase ,

void viewboard(){
  
}



// first we need to check that it black or white , then we can if that defalut position then it's only move forward 2 else only 1 , and diagonal while we have any pawn near that area , 
void pawnmove(vector<vector<char>>& board , int ay, int ax , int dy , int dx){ 
  // check if it's default positon   
  bool move=0;
  if(low_case(board[ay][ax])){ // making sure it's only forward for both side pawn
    swap(ay,dy);
  }
  if( ay==1 || ay== 6 && abs(ay - dy) <= 2){
    move=1; // specail moves forward by two or one +
  }else if(board[dy][dx]!='.' && ( dy-ay == 1 && abs(ax-dx)==1)){   // this dy-ay=1 make it move only forward 
    // if(low_case(board[ay][ax])!=low_case(board[dy][dx])){
    //   // swap(board[ay][ax],board[dy][dx]); stop this 

    // just put our attack function this don't take p which make our other stuff easy  
    if(board[dy][dx]!='p' || board[dy][dx]!='P'){
      attack_af(board[ay][ax],board[dy][dx],ay,ax,dy,dx);
      }
      move=1;
  }
  else if ( dy-ay == 1  &&  board[dy][dx] == '.' ){
    if( (dy == 7 || dy == 0)){   // after it reach the wall it would become a any four q , n, r , b 
    char choice;
    switch (choice) {  
      case 'b':
      case 'B':  // grouped — handles both lowercase and uppercase
          if(low_case(choice)){
            pieces[int('b')].push_back(dy*8+dx);
          }else{
            pieces[int('B')].push_back(dy*8+dx);
          }
          break;

      case 'r':
      case 'R':
          if(low_case(choice)){
            pieces[int('r')].push_back(dy*8+dx);
          }else{
            pieces[int('R')].push_back(dy*8+dx);
          }
          break;

      case 'q':
      case 'Q':
          if(low_case(choice)){
            pieces[int('q')].push_back(dy*8+dx);
          }else{
            pieces[int('Q')].push_back(dy*8+dx);
          }
          break;

      case 'n':
      case 'N':
          if(low_case(choice)){
            pieces[int('n')].push_back(dy*8+dx);
          }else{
            pieces[int('N')].push_back(dy*8+dx);
          }
          break;
      }
    }
    move=1; 
  }
  if( move==1){
    //moving function // putting up this in the 
  }
}

void bishopmove(vector<vector<char>>& board, int ay, int ax , int dy , int dx){
  
  if(abs(ax-dx)==abs(ay-dy)){
    // move function also we have put action at same time here , 
  };

  //view
}

void rookmove(vector<vector<char>>& board, int ay, int ax , int dy , int dx){
  // add specail move castel move here
  if((abs(ax-dx)<=8 && abs(ay-dy)==0 ) || ( abs(ax-dx)==0 && abs(ay-dy)<=8 ) ){
    // move function and attack 
  };

  // view
}

void queenmove(vector<vector<char>>& board, int ay, int ax , int dy , int dx){

  if((abs(ax-dx)<=8 && abs(ay-dy)==0 ) || ( abs(ax-dx)==0 && abs(ay-dy)<=8)){
    // move function 
  }else if(abs(ax-dx)==abs(ay-dy)){
    // move function also we have put action at same time here , 
  };


}

// this piece done idepementally whole , it just fixed jump so we can check there 
void kigntmove(vector<vector<char>>& board, int ay, int ax , int dy , int dx){

  if( (abs(ax-dx)==1 && abs(ay-dy)==2)  || (abs(ax-dx)==2 && abs(ay-dy)==1) ){
    // moving and actions also moves ,
    
  };

  // view 
}


void kingmove(vector<vector<char>>& board, int ay, int ax , int dy , int dx){

  // king must don't move at any of range just place king at safe pount only 
  if(abs(ax-dx)<=1 || abs(ay-dy)<=1){
    if(){     // king capture the piece , but it don't have backed by other one , means it's okay as long it's stayed along side it don't attack king ,

    };
  }

}
int main(){
  vector<vector<char>>board{
    {'r','n','b','q','k','b','n','r'}, //0
    {'p','p','p','p','p','p','p','p'}, //1
    {'.','.','.','.','.','.','.','.'}, //2
    {'.','.','.','.','.','.','.','.'}, //3
    {'.','.','.','.','.','.','.','.'}, //4
    {'.','.','.','.','.','.','.','.'}, //5
    {'P','P','P','P','P','P','P','P'}, //6
    {'R','N','B','Q','K','B','N','R'}, //7
  //  0   1   2   3   4   5   6   7
  };
  
  return 0; 
}
// each piece can target by at least 4 maximum side ,also how can i tell if it's coming from which direction , or what direction 





// now to cover up slide line , first we can do thing we just need to directions , just make sure when they reach king inner circle , will would lunch attck or somthing like that from innerr to make we have block or not  if it's diagonal then we just need 7 one trick , like we minus 7 to see if we below number or not ,  



// 0 1 2      0 0 0  == (--i , --j)  (++i ,  0)  (--i , ++j) 
// 3 4 5  ==  0 1 0     (0 , --j)    (0  ,  0)    (0 , ++j) 
// 6 7 8      0 0 0     (++i , --j)  (--i , 0)   (++i , ++j) 
//  --i , --j
//  --i , ++j 
//  ++i , --j 
//  ++i , ++j 
//  ++i ,  0
//  --i , 0   
//  0 , --j    
//  0 , ++j 
//  0  ,  0    
// void printedcude(vector<vector<string>>arr){
// vector<string>input;
// int n=arr.size();
// int k=0;
// for(int i=1;i<n;i+=3){  
//   for(int j=1;j<n;j+=3){
//     input.push_back(arr[i-1][j-1]); 
//     input.push_back(arr[i-1][j]); 
//     input.push_back(arr[i-1][j+1]); 
//     input.push_back(arr[i][j-1]); 
//     input.push_back(arr[i][j]); 
//     input.push_back(arr[i][j+1]); 
//     input.push_back(arr[i+1][j-1]); 
//     input.push_back(arr[i+1][j]); 
//     input.push_back(arr[i+1][j+1]); 
//     cude[to_string(i)+to_string(j)]=input;
//     // cude[to_string(k++)]=input;
//     // cout << (to_string(i)+to_string(j)) << " -- cube keys "<<  endl;
//     input.clear();
//     }
//   }
//   for(auto& pair:cude){
//     for(auto& val: pair.second){
//         cout << val ;
//     };
//     cout << "-" << pair.first  << endl;
//   }
// }


// this below u can see how it's working 
void jojo() {
    int x=41-59;  // king number - 9 -given postion in inner circle 
    x=abs(x);     
    cout << x << "\n";
    int y=(x/8)*3+(x-(x/8)*8);   // (x-(x/8)*8) this work like remaider , and at y is number of map key which repesent the king inner circle 
    cout << y << "\n";
}


// i don't want used that map yet , there might any othe way we can might do that ? but how 


//  0  1  2  3  4  5  6  7
//  8  9 10 11 12 13 14 15
// 16 17 18 19 20 21 22 23
// 24 25 26 27 28 29 30 31
// 32 33 34 35 36 37 38 39
// 40 41 42 43 44 45 46 47
// 48 49 50 51 52 53 54 55
// 56 57 58 59 60 61 62 63


// for ( whether to remove piece from the king front or not we would take diff x and y) this i just see if king attacked x==0 || y==0  || x==y , after i would do the oppsite signs , postion to neagative also visa -versa , and check that piece can attack we stay if not remove  , it's easit and optimize compare to always look all piece , or king arround check , here we just need check one time , and that's it  [this would work if linear sliding piece are attacking ]
// find draw condition also





