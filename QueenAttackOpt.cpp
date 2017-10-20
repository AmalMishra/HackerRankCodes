#include <iostream>
using namespace std;

int main() {
    int move[8][2];
    int n;
    cin>>n;
    int obNo;
    cin>>obNo;
    int rQueen,cQueen;
    cin>> rQueen >> cQueen;
    int rObj=0,cObj=0;
    move[0][0]=n+1;
    move[0][1]=cQueen;
    move[1][0]=0;
    move[1][1]=cQueen;

    move[2][0]=rQueen;
    move[2][1]=0;
    move[3][0]=rQueen;
    move[3][1]=n+1;

    int sum = rQueen+cQueen;
    int diff = (rQueen>cQueen) ? (rQueen-cQueen) : (cQueen-rQueen);

    if(n-rQueen > cQueen-1) {
        move[4][0] = sum ;
        move[4][1]=0;
        move[5][0] = 0  ;
        move[5][1]= sum ;

    }
    else{

        move[4][0] = n+1;
        move[4][1]= sum-n-1;

        move[5][0]= sum-n-1;
        move[5][1] = n+1;
    }

    if(n-rQueen < n-cQueen) {

        move[6][0] = n+1;
        move[6][1]=n-diff+1;

        move[7][0] = diff;
        move[7][1]=0;

    }
    else{

        move[6][0] = n-diff+1;
        move[6][1]= n+1;

        move[7][1] = diff;
        move[7][0]= 0;
    }

    for (int i = 0; i <obNo ; ++i) {
        cin>>rObj>>cObj;

        if(rObj==rQueen){
            if(cObj>cQueen && cObj < move[3][1]){
                move[3][1]=cObj;
            }
            else if(cObj<cQueen && cObj > move[2][1]){
                move[2][1]=cObj;
            }
        }

        if(cObj==cQueen){
            if(rObj>rQueen && rObj < move[0][0]){
                move[0][0]=rObj;
            }
            else if( rObj < rQueen && rObj > move[1][0]){
                move[1][0]=rObj;
            }
        }

        if(sum == cObj+rObj) {
            if (rObj > rQueen && rObj < move[4][0]) {
                move[4][0] = rObj;
                move[4][1] = cObj;
            }

            if (rObj < rQueen && rObj > move[5][0]) {
                move[5][0] = rObj;
                move[5][1] = cObj;
            }
        }

        if(cQueen-rQueen == cObj-rObj){
                if( rObj > rQueen && rObj < move[6][0]){
                    move[6][0]=rObj;
                    move[6][1]=cObj;
                }

                if( rObj < rQueen && rObj > move[7][0]){
                    move[7][0]=rObj;
                    move[7][1]=cObj;
                }
        }


    }
    int vup = /*(move[0][0]==rQueen) ? 0:*/ (-rQueen+move[0][0]-1);
    int vdwn= /*(move[1][0]== rQueen)? 0: */(rQueen-move[1][0]-1);
    int hl=  /*move[2][1]== cQueen ? 0: */(cQueen-move[2][1]-1);
    int hr=  /*move[3][1]== cQueen ? 0 : */(move[3][1]-cQueen-1);
    int dup=  /*move[4][0]== rQueen ? 0 : */(move[4][0]-rQueen-1);
    int ddwn= /*move[5][0]== rQueen ? 0 :*/(rQueen-move[5][0]-1);
    int d1up= /*move[6][0]== rQueen ? 0  :*/(move[6][0]-rQueen-1);
    int d1dwn= /*move[7][0]== rQueen ? 0 :*/(rQueen-move[7][0]-1);

    int attack = vup+vdwn+hl+hr+d1dwn+d1up+ddwn+dup;
    cout<< attack;

    return 0;
}