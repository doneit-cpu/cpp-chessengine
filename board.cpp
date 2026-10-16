#include<iostream>
#include<vector>
using namespace std;

bool low_case(char a){   // i want to conver a char into ascii number which  did then u have it 
  int x=0-a;
  return (97<= x && x <=122)?1:0;
}

pair <int,int>lower_k={0,4};  //white
pair <int,int>upper_K={7,4};  // black
bool active; // 0 means whiete and 1 mean black , 

int safecheck(vector<vector<char>>& board){  //king inner circle   
  // all direction for it first 
  int dic_x[9]={0,-1,-1,-1,0,0,+1,+1,+1};
  int dic_y[9]={0,-1,0,+1,-1,+1,-1,0,+1};  

  pair <int,int> p=active?upper_K:lower_k;  // king_p
  int es_root=0; 

      for(int i=1;i<8;i++){   //  n 
        int k=0;
        int x=p.second+dic_x[i];;
      int y=p.first+dic_y[i]; 
      while(k<9){     // n 
          while(y >= 0 && y < 8 && x >=0 && x < 8){  // n/2   // don't check means bigger then zero and less then 8 , so
          if(board[y+=dic_y[k]][x+=dic_x[k]]!='.'){          
              es_root++;
          }
          k++;
        }
      }
    }
  

  return es_root;

}


bool under_at(vector<vector<char>>& board){  // can i put king to new position ,king under attacked or not  
  // all direction for it first 
  int dic_x[9]={0,-1,-1,-1,0,0,+1,+1,+1};
  int dic_y[9]={0,-1,0,+1,-1,+1,-1,0,+1};  

  pair p=active?upper_K:lower_k;  // king_p

  try{
      for(int i=1;i<8;i++){
        int x=p.second;
        int y=p.first;
      while(x >= 0 && x < 8 && y >=0 && y < 8){
        if(board[y+=dic_y[i]][x+=dic_x[i]]!='.'){
          if(low_case(board[y][x])!=active){
            return true;
          }
        }
      }
    }
  }catch(const std::exception& e){
    cout << "we got problem here" << e.what() << "\n";
  }
  
  return false;

}


bool empaty_path(vector<vector<char>>& board, int ay,int ax,int dy,int dx){   
  int y=dy-ay; // whether we have look up or down
  int x=dx-ax;  // same here , if any of there are zero it's pretty simple just add or minus too find if something between or not , 
  if(abs(y)==abs(x)){ // we have go diagonal here 
    int n=abs(y);
    if(y<0 && x<0){   // -1 , -1 , x ,y
      for(int i=n;i>0;i--){
        if (board[ay++][ax++] != '.') return false;  // so this make sure betwen bishop and attack piece is nothing by checking each piece in diagonal way and "." this block has nothing got it 
      }
    }else if(x<0){    // -1  , 1
      for(int i=n;i>0;i--){   
        if (board[ay--][ax++] != '.') return false;  // same here with each one 
      }
    }else if(y<0){    //  1 , -1
      for(int i=n;i>0;i--){
        if (board[ay++][ax--] != '.') return false;
      }
    }else{            //  1 , 1 
      for(int i=n;i>0;i--){
        if (board[ay--][ax--] != '.') return false;
      }
    };
  }else if(y==0||x==0){ // rook moves
      if(y==0){
        if(x<0){     // -1 ,0  -down
          for(int i=abs(x);i>0;i--){      // like above things explain i put it there , it only check the vertifcal or horital way for the piece 
            if (board[ay--][ax] != '.') return false;
          }
        }else{      // 1 ,0    -up
          for(int i=abs(x);i>0;i--){
            if (board[ay++][ax] != '.') return false;
          }
        }
      }else{
        if(y<0){    //  0,-1  <-y
          for(int i=abs(y);i>0;i--){
            if (board[ay][ax--] != '.') return false;
          }
        }else{     //  0 ,1   y->
          for(int i=abs(y);i>0;i--){
            if (board[ay][ax++] != '.') return false;
          }
        }
      }
  }
  return true;
}

bool attack_af(char a , char b, int ay,int ax,int dy,int dx){

  
};

// we will calling function problem check that for sure , 
void changed_m(vector<vector<char>>& board ,char a,int ay,int ax,int dy,int dx){

}

void checkmate(vector<vector<char>>& board ,int ay,int ax){ // first we have see if king has no way to go , and we don't have piece which can't move then win other side , or we safe with reamining piece , but we don't move so 


}

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
            // pieces[int('b')].push_back(dy*8+dx);
          }else{
            // pieces[int('B')].push_back(dy*8+dx);
          }
          break;

      case 'r':
      case 'R':
          if(low_case(choice)){
            // pieces[int('r')].push_back(dy*8+dx);
          }else{
            // pieces[int('R')].push_back(dy*8+dx);
          }
          break;

      case 'q':
      case 'Q':
          if(low_case(choice)){
            // pieces[int('q')].push_back(dy*8+dx);
          }else{
            // pieces[int('Q')].push_back(dy*8+dx);
          }
          break;

      case 'n':
      case 'N':
          if(low_case(choice)){
            // pieces[int('n')].push_back(dy*8+dx);
          }else{
            // pieces[int('N')].push_back(dy*8+dx);
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
    
  }
  
}

// 0 41 2      0 0 0  ==  (--i, --j)   (--i,  j)   (--i, ++j) 
// 3 48 5  ==  0 1 0      (  i, --j)   (  i,  j)   (  i, ++j) 
// 6 56 8      0 0 0      (++i, --j)   (++i,  j)   (++i, ++j)

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



~/.local/bin/antigravity
