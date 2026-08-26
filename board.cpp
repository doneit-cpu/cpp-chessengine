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

// --> new idea for for replacing map of pieces with direct refence varible of check piece array , like i learn that all i need is that track or get picec info whenever i want and map is kind of doing over to much ( like c++ map made tree and complexity behind the since ) , so i'm making code in the language y don't use it specail feature like * pointers
{   // this all is plan for now , but  i would like too do this in future okay 

//what i can do is to give this postion when i need like slider and thing okay ,so when the it goes to last array indec it used , also other function wait while it compeleted it work and send or whatever for wanting other array location how is this ? 
// int bishop_p[2]={65,64}   // just assume postion are really for once ,
// int rook_p[2]={15,64}
// int kight_p[2]={05,64}
// int k_p[2]={35}

// function *look_a(int number){
//   // u can acceses only 3 first array ? 
//   int *care;
//   if(number==3){   //recursion first okay



//     // first take last value of this whatever array u have 
//   }



// }

// above code for it --> { 

//   #include <iostream>

// // Global arrays representing pieces
// int bishop_p[2] = {65, 64};
// int rook_p[2]   = {15, 64};
// int knight_p[2] = {5, 64};  // Note: Avoid leading zeros like '05' in C++ as it means Octal
// int k_p[1]      = {35};

// // A simple lock to make other functions wait if the array is busy
// bool is_array_busy = false;

// // Function returns a pointer to an integer (the start of the selected array)
// int* look_a(int number) {
//     // If the system is busy, you can block or return null
//     if (is_array_busy) {
//         std::cout << "System busy. Waiting...\n";
//         return nullptr; 
//     }

//     // Reference switching logic using standard conditional blocks
//     if (number == 0) return bishop_p;
//     if (number == 1) return rook_p;
//     if (number == 2) return knight_p;
//     if (number == 3) return k_p;

//     return nullptr; // Safety fallback
// }

// int main() {
//     // 1. Accessing an array dynamically via the pointer function
//     int* current_piece = look_a(1); // Selects rook_p

//     if (current_piece != nullptr) {
//         // Lock the system while working
//         is_array_busy = true; 

//         // Read or change values directly
//         std::cout << "Rook initial X: " << current_piece[0] << "\n"; // Outputs 15
        
//         // Simulating work: Modifying the original rook_p array through the pointer
//         current_piece[0] = 20; 

//         // Work finished, unlock the system
//         is_array_busy = false; 
//     }

//     // Verify the original array actually changed
//     std::cout << "Original Rook X updated to: " << rook_p[0] << "\n"; // Outputs 20

//     return 0;
// }

// }

}

// ascii , position , i don't really need the pawn position they can only attack one block ahead , so do it removing is best move ,
map<int, vector<int>> pieces = {     // make it for runtime or something like that , like ? dynamic which change thing on it's own something like that 
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
bool king_guard[9]={0,0,0,0,0,0,0,0,0};
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


map<int,bool> lo_p; // lower case paawn
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
  if( (int(b)==75) || (int(b)==107) ) return false ; // u can't king and remove it got it  
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

int pathsafty(int kingpos,int target){
  // this put in tough stistuation , like do count king with 9 safe way or only 8 surroding king ?? 
  int sum=0;

  int diff=kingpos-target/8;

  if(target==int('r') || target==int('R')){
    sum+=3;
    // if it's at 2 layen or also in other sence 3 layer anything from king it's damage it 3 , if bleow any level damage is 6 or 5 depend it's digonal to king or not 
  }else if(target==int('b') || target==int('B')){
    sum+=2;
    // always 3 or two depend it's digonal to king or not 
  }else if(target==int('n') || target==int('N')){      // i will have to think about it bro , okay 
    // 4 layer it's 1 , 2 , 3 layer it's 1 and kind of 2 bcs it's directly attack king ,
  }else if(target==int('q') || target==int('Q')){
    if(diff==4){
      sum+=4;
    }else if(diff==3){
      sum+=5;
    }else if(diff==2){
      sum+=7;
    }
    // 4 layer it's 4 , 3 will 5 , and at layer 2 it's 7  
  }else if(target==int('p') || target==int('P')){
    if(diff>=-1){
      sum=0;
    }else{
      sum++;
    }
    // tick to much bro ? only have more it's above direct center of king m top , it's 2 , and other 1 ,but after king bleow give me king 2 layer , it would zero no mattter 
  }else{
    sum+=3;
    // king always of other 3 
  }
  if(diff==(diff*8)%8){
    sum++;
  }

  return sum;  
};


bool binarySearch(vector<int>& arr,int st,int ed ,int diff,bool innergard,int king) {
  // ed-st = diff // so it carry charge or direction where to go 
  if(innergard){
    int diff;
     if(st >= 0 && st <= 63 ){
      diff=st-63;
     }else if( ed >= 0 && ed <= 63){
      diff=
     }
  }

  if(st >= 0 && st <= 63 && ed >= 0 && ed <= 63){
    int target=st+(diff);

    int right = lower_bound(arr.begin(), arr.end(), ed) - arr.begin();
    int left = lower_bound(arr.begin(), arr.end(), st) - arr.begin();
    left=min(right,left);
    right=max(right,left);
    
    if (right >= arr.size()) right = arr.size() - 1;
    if (left < 0) left = 0;

    int reset=-1;   // used as reset point for another serach 
    int step=abs(ed-st)/abs(diff);
    while(step){      // what end is already small from beging bro ? 
      
      while (left <= right) {
        
        int mid = left + (right - left) / 2;
        
        if(innergard && target==king){
          target+=diff;
        }
        
        if (arr[mid] == target) {
          if(innergard){
            pathsafty(king,arr[mid]);        
          }else{
            return true;
          }
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
}
  

bool indirect_attacked(vector<vector<char>>& board,char a,bool block,int ky,int kx){   // this run behind the code , so don't need this shit char a first 
  sort(temp.begin(), temp.end());
  int keep[6]={66,81,82,98,113,114}; // 
  int postion=pieces[75][0];
  int st=3;
  int ed=5;
  if(low_case(a)){
    st=0;
    ed=2;
    postion=pieces[107][0];
  };
  if(block){
    postion=8*ky+kx;
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
            return binarySearch(temp,postion,pieces[keep[i]][j],diff*charge,false,postion);
          }else if((keep[i]!=66) && (keep[i]!=98) && (diff%8==0)){ // now just have stop the // same here ? 
            return binarySearch(temp,postion,pieces[keep[i]][j],diff*charge,false,postion);
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
              return binarySearch(temp,postion,pieces[keep[i]][j],1*charge,false,postion);
              //binarySearch(vector<int>& arr,int st,int ed ,int diff,bool innergard,int king)
          }
      };
    }
  return false;
}


bool isSafemove(vector<vector<char>>& board, int ky, int kx, int ky_m, int kx_m) {

  if (ky_m < 0 || ky_m > 7 || kx_m < 0 || kx_m > 7) {
    return false;
  }

  char a = board[ky][kx];
  int pos = 0;      
  char pos_p;       
  int pos_k = 0;    

  if (low_case(a)) {
    pos = 78;       
    pos_p = 'P';    
    pos_k = 75;     
  } else {
    pos = 110;      
    pos_p = 'p';    
    pos_k = 107;    
  }

  if (board[ky_m][kx_m] != '.') {
    if (low_case(board[ky_m][kx_m]) == low_case(a)) {
      return false;
    }
  }

  if (indirect_attacked(board, a, true, ky_m, kx_m)) {
    return false;
  }

  int x;
  int y;
  for (int i = 0; i < pieces[pos].size(); i++) {
    x = abs(ky_m - (pieces[pos][i] / 8));
    y = abs(kx_m - (pieces[pos][i] % 8)); // Fixed: use kx_m for column
    if ((x == 1 && y == 2) || (x == 2 && y == 1)) {
      return false; // Attacked by Knight -> NOT safe
    }
  }

  int pawn_y = low_case(a) ? (ky_m + 1) : (ky_m - 1);
  if (pawn_y >= 0 && pawn_y < 8) {
    if (kx_m - 1 >= 0 && board[pawn_y][kx_m - 1] == pos_p) {
      return false; // Attacked by Pawn -> NOT safe
    }
    if (kx_m + 1 < 8 && board[pawn_y][kx_m + 1] == pos_p) {
      return false; // Attacked by Pawn -> NOT safe
    }
  }

  if (pieces[pos_k].size() > 0) {
    x = abs(ky_m - (pieces[pos_k][0] / 8));
    y = abs(kx_m - (pieces[pos_k][0] % 8)); 
    if (x <= 1 && y <= 1) {
      return false; 
    }
  }

  
  return true;
}

// after move we would have see if this an checkmate or not , 
// we cover all the path first // we only have look at kings piece if any those nine squre piece then we have active  this function 
void checkmate(vector<vector<char>>& board ,int ay,int ax){ // first we have see if king has no way to go , and we don't have piece which can't move then win other side , or we safe with reamining piece , but we don't move so 

  if(low_case(board[ay][ax])){
  // lower case king
  
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

// 0 41 2      0 0 0  ==  (--i, --j)   (--i,  j)   (--i, ++j) 
// 3 48 5  ==  0 1 0      (  i, --j)   (  i,  j)   (  i, ++j) 
// 6 56 8      0 0 0      (++i, --j)   (++i,  j)   (++i, ++j)

void king_innner_gaurd(int king_pos){

  int kingl;
  int digonal[]={7,-7,9,-9};
  int vetical[]={8,-8,1,-1};
  int steps=3;
  int dirc[5]={-9,-8,-7,-1,+9};
  int dirc_r[5]={-7,-8,-9,1,7};
  int dic[6]={-9,-8,-7,-9,1,7};

  for(int i = 0; i < 5; i++){

    if(i<=2){
      steps++;
    }else{
      steps--;
    }

    int st = king_pos + dirc[i];
  
     for(int j=0;j<=1;j++){
       binarySearch(temp,st,st+(digonal[j]*steps) ,digonal[j], true, king_pos);
       j++;
       steps++;
        binarySearch(temp,st,st+(digonal[j]*3) ,digonal[j], true, king_pos);
      }

      st = king_pos + dirc_r[i];

      for(int j=2;j<=3;j++){
        binarySearch(temp,st,st+(digonal[j]*3) ,digonal[j], true, king_pos);
        j++;
        binarySearch(temp,st,st+(digonal[j]*5) ,digonal[j], true, king_pos);
      };
  }


    // vertical sacnning 
   for(int i = 0; i < 6; i++){

    int st = king_pos + dic[i];
    
     if (st < 0 || st > 63) continue;
     
      for(int j=0;j< 4;j++){
        if(i<=2 && j<=1){
          binarySearch(temp,st,st+(vetical[j]*3) ,vetical[j], true, king_pos);
        }else{
          binarySearch(temp,st,st+(vetical[j]*3) ,vetical[j], true, king_pos);          
        }

      }
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


// // this below u can see how it's working 
// void jojo() {
//     int x=41-59;  // king number - 9 -given postion in inner circle 
//     x=abs(x);     
//     cout << x << "\n";
//     int y=(x/8)*3+(x-(x/8)*8);   // (x-(x/8)*8) this work like remaider , and at y is number of map key which repesent the king inner circle 
//     cout << y << "\n";
// }


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
 



/////still thking 