#include <iostream>
#include <set>

using namespace std;

char m[10][10];
struct Status{
    int face;
    int y;
    int x;
    Status(int f = 0, int y = 0, int x = 0): face(f), y(y), x(x){}
};

bool operator< (const Status& s1, const Status& s2){
    if(s1.face < s2.face){
        return true;
    }
    else{
        if(s1.face == s2.face && s1.y < s2.y){
            return true;
        }
        else{
            if(s1.y == s2.y){
                return s1.x < s2.x;
            }
        }
    }
    return false;
}

Status f, c;

set< pair<Status, Status> > st;

int moves[4][2] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1},
};

void validmove(Status& s, int y, int x){
    if(y>=0 && y<10 && x>=0 && x<10 && m[y][x]!='*'){
        s.y = y;
        s.x = x;
    }
    else{
        s.face++;
        s.face%=4;
    }
}

void makemove(Status& s){
    validmove(s, s.y + moves[s.face][0], s.x + moves[s.face][1]);
}

int main() {
    for(int i = 0; i < 10; i++){
        for (int j = 0; j < 10; ++j) {
            scanf(" %c", &m[i][j]);
            if(m[i][j] == 'F'){
                f = Status(0, i, j);
            }
            else if(m[i][j] == 'C'){
                c = Status(0, i, j);
            }
        }
    }
    int cnt = 0;
    while(++cnt){
        makemove(f); makemove(c);
        if(st.count(make_pair(f, c))){
            break;
        }
        if(f.y == c.y && f.x == c.x){
            cout << cnt << endl;
            return 0;
        }
        st.insert(make_pair(f, c));
    }
    cout << 0 << endl;
    return 0;
}
