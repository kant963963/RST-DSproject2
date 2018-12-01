#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int i,j,k1,k2,u,s;
char o;
stack<int> sta_r;
stack<int> sta_c;
queue<int> row,col,row1,col1,tmpr,tmpc,quer,quec;

void det_turn(int a,int b,int c,int d,char**dir,bool *turn,int *turn_point_c,int *turn_point_r){
    if(dir[a][b] == 'd' && dir[c][d] == 'u' && turn[4] == false){turn[4] = true;turn_point_r[4] = c;turn_point_c[4] = d;}
    else if(dir[a][b] == 'r' && dir[c][d] == 'u' && turn[0] == false){turn[0] = true;turn_point_r[0] = c;turn_point_c[0] = d;}
    else if(dir[a][b] == 'l' && dir[c][d] == 'u' && turn[3] == false){turn[3] = true;turn_point_r[3] = c;turn_point_c[3] = d;}
    else if(dir[a][b] == 'r' && dir[c][d] == 'd' && turn[1] == false){turn[1] = true;turn_point_r[1] = c;turn_point_c[1] = d;}
    else if(dir[a][b] == 'l' && dir[c][d] == 'd' && turn[2] == false){turn[2] = true;turn_point_r[2] = c;turn_point_c[2] = d;}
    else if(dir[a][b] == 'l' && dir[c][d] == 'r' && turn[5] == false){turn[5] = true;turn_point_r[5] = c;turn_point_c[5] = d;}
}

void bfs(int r1,int r2,int m,int n,int**dis,char**dir,int**A,int**visited,bool *turn,int *turn_point_c,int *turn_point_r){

    quer.push(r1); quec.push(r2);
    for(i=1;i<m+1;i++) for(j=1;j<n+1;j++) visited[i][j] = 0;
    while(!quer.empty()){
        k1 = quer.front(); quer.pop(); k2 = quec.front(); quec.pop();
        if(!visited[k1-1][k2] && !A[k1-1][k2] && !dis[k1-1][k2]){
            quer.push(k1-1);quec.push(k2);
            dis[k1-1][k2] = dis[k1][k2] + 1;
            u = dis[k1-1][k2];
            visited[k1-1][k2] = true;
            if(k1 == r1 && k2 == r2) dir[k1-1][k2] = 'u';
            else if(dir[k1-1][k2] == 'w') dir[k1-1][k2] = dir[k1][k2];
        }
        else if(!A[k1-1][k2]) det_turn(k1,k2,k1-1,k2,dir,turn,turn_point_c,turn_point_r);

        if(!visited[k1+1][k2] && !A[k1+1][k2] && !dis[k1+1][k2]){
            quer.push(k1+1);quec.push(k2);
            dis[k1+1][k2] = dis[k1][k2] + 1;
            u = dis[k1+1][k2];
            visited[k1+1][k2] = true;
            if(k1 == r1 && k2 == r2) dir[k1+1][k2] = 'd';
            else if(dir[k1+1][k2] == 'w') dir[k1+1][k2] = dir[k1][k2];
        }
        else if(!A[k1+1][k2]) det_turn(k1,k2,k1+1,k2,dir,turn,turn_point_c,turn_point_r);

        if(!visited[k1][k2+1] && !A[k1][k2+1] && !dis[k1][k2+1]){
            quer.push(k1);quec.push(k2+1);
            dis[k1][k2+1] = dis[k1][k2] + 1;
            u = dis[k1][k2+1];
            visited[k1][k2+1] = true;
            if(k1 == r1 && k2 == r2) dir[k1][k2+1] = 'r';
            else if(dir[k1][k2+1] == 'w') dir[k1][k2+1] = dir[k1][k2];
        }
        else if(!A[k1+1][k2]) det_turn(k1,k2,k1,k2+1,dir,turn,turn_point_c,turn_point_r);

        if(!visited[k1][k2-1] && !A[k1][k2-1] && !dis[k1][k2-1]){
            quer.push(k1);quec.push(k2-1);
            dis[k1][k2-1] = dis[k1][k2] + 1;
            u = dis[k1][k2-1];
            visited[k1][k2-1] = true;
            if(k1 == r1 && k2 == r2) dir[k1][k2-1] = 'l';
            else if(dir[k1][k2-1] == 'w') dir[k1][k2-1] = dir[k1][k2];
        }
        else if(!A[k1+1][k2]) det_turn(k1,k2,k1,k2-1,dir,turn,turn_point_c,turn_point_r);
    }
}

void path(int i,int j,int **V,int **dis,char **dir,queue<int> &row,queue<int> &col){

    k1 = i; k2 = j;
    while(dis[k1][k2] > 0){
        V[k1][k2] = 1;
        tmpr.push(k1);tmpc.push(k2);
        sta_r.push(k1);sta_c.push(k2);
        if(dis[k1-1][k2] == dis[k1][k2] -1 && (dir[k1-1][k2] == dir[k1][k2] || dir[k1-1][k2] == 'o')) k1--;
        else if(dis[k1][k2+1] == dis[k1][k2] -1 && (dir[k1][k2+1] == dir[k1][k2] || dir[k1][k2+1] == 'o')) k2++;
        else if(dis[k1][k2-1] == dis[k1][k2] -1 && (dir[k1][k2-1] == dir[k1][k2] || dir[k1][k2-1] == 'o')) k2--;
        else if(dis[k1+1][k2] == dis[k1][k2] -1 && (dir[k1+1][k2] == dir[k1][k2] || dir[k1+1][k2] == 'o')) k1++;
    }
    tmpr.push(k1);tmpc.push(k2);
    while(sta_r.size()>1){
        k1 = sta_r.top(); k2 = sta_c.top();
        row.push(k1); col.push(k2);
        sta_r.pop(); sta_c.pop();
    }
    sta_r.pop(); sta_c.pop();
    while(!tmpr.empty()){
        k1 = tmpr.front(); k2 = tmpc.front();
        row.push(k1); col.push(k2);
        tmpr.pop(); tmpc.pop();
    }
}

void go(int i,int j,int **V,int **dis,char **dir,queue<int> &row,queue<int> &col){

    k1 = i; k2 = j;
    while(dis[k1][k2]>0){
        V[k1][k2] = 1;
        sta_r.push(k1);sta_c.push(k2);
        if(dis[k1-1][k2] == dis[k1][k2] -1 && (dir[k1-1][k2] == dir[k1][k2] || dir[k1-1][k2] == 'o')) k1--;
        else if(dis[k1][k2+1] == dis[k1][k2] -1 &&(dir[k1][k2+1] == dir[k1][k2] || dir[k1][k2+1] == 'o')) k2++;
        else if(dis[k1][k2-1] == dis[k1][k2] -1 &&(dir[k1][k2-1] == dir[k1][k2] || dir[k1][k2-1] == 'o')) k2--;
        else if(dis[k1+1][k2] == dis[k1][k2] -1 &&(dir[k1+1][k2] == dir[k1][k2] || dir[k1+1][k2] == 'o')) k1++;
    }

    while(sta_r.size()>1){
        k1 = sta_r.top(); k2 = sta_c.top();
        row.push(k1); col.push(k2);
        sta_r.pop(); sta_c.pop();
    }
     sta_r.pop(); sta_c.pop();
}

void go_back(int i,int j,int **V,int **dis,char **dir,queue<int> &row,queue<int> &col){

    k1 = i; k2 = j;
    while(dis[k1][k2] > 0){
        V[k1][k2] = 1;
        row.push(k1);col.push(k2);
        if(dis[k1-1][k2] == dis[k1][k2] -1 && (dir[k1-1][k2] == dir[k1][k2] || dir[k1-1][k2] == 'o')) k1--;
        else if(dis[k1][k2+1] == dis[k1][k2] -1 &&(dir[k1][k2+1] == dir[k1][k2] || dir[k1][k2+1] == 'o')) k2++;
        else if(dis[k1][k2-1] == dis[k1][k2] -1 &&(dir[k1][k2-1] == dir[k1][k2] || dir[k1][k2-1] == 'o')) k2--;
        else if(dis[k1+1][k2] == dis[k1][k2] -1 &&(dir[k1+1][k2] == dir[k1][k2] || dir[k1+1][k2] == 'o')) k1++;
    }
    row.push(k1);col.push(k2);
}

void turn_path(int i,char a,char b,int *turn_point_r,int *turn_point_c,int **V,int **dis,char **dir,queue<int> &row,queue<int> &col){
    o = dir[turn_point_r[i]][turn_point_c[i]];
    dir[turn_point_r[i]][turn_point_c[i]] = a;
    go(turn_point_r[i],turn_point_c[i],V,dis,dir,row,col);
    dir[turn_point_r[i]][turn_point_c[i]] = b;
    go_back(turn_point_r[i],turn_point_c[i],V,dis,dir,row,col);
    dir[turn_point_r[i]][turn_point_c[i]] = o;
}


int main(int argc,char *argv[]){
	int i,j,m,n,energy,r1,r2,*turn_point_c,*turn_point_r;
	bool *turn,flag = true;
	char **dir;
	turn = new bool[6];
	turn_point_c = new int[6];
	turn_point_r = new int[6];
	for(i=0;i<6;i++){turn[i] = false; turn_point_r[i] = -1; turn_point_c[i] = -1;}

    fstream fin;
    string str(argv[1]);
    fin.open(str+"/floor.data" , ios::in);

    if(!fin) return 1;
    fin>>m>>n>>energy;

    char B[m+2][n+2];
    int **A,**V,**dis,**visited;
    dir = new char*[m+2];
    A = new int*[m+2];
    V = new int*[m+2];
    visited = new int*[m+2];
    dis = new int*[m+2];
    for(i=0;i<m+2;i++) {A[i] = new int[n+2]; V[i] = new int[n+2]; dis[i] = new int[n+2]; visited[i] = new int[n+2]; dir[i] = new char[n+2];}

    for(i=0;i<n+2;i++){
    	A[0][i] = -1;
		A[m+1][i] = -1;
		dis[0][i] = -1;
		dis[m+1][i] = -1;
	}

	for(j=1;j<m+1;j++){A[j][0] = -1; A[j][n+1] = -1;dis[j][0] = -1; dis[j][n+1] = -1;}
    for(j=1;j<m+1;j++) for(i=1;i<n+1;i++){
			fin>>B[j][i];
			if(B[j][i] == '1') {A[j][i] = -1;dis[j][i] = -1;}
			else if(B[j][i] == '0') {A[j][i] = 0;dis[j][i] = 0;}
			else if(B[j][i] == 'R'){
				A[j][i] = -2;
				dis[j][i] = 0;
				r1 = j;
				r2 = i;
			}
		}

	for(i=0;i<m+2;i++) for(j=0;j<n+2;j++) {V[i][j] = A[i][j]; dir[i][j] = 'w';}
	dir[r1][r2] = 'o';

	bfs(r1,r2,m,n,dis,dir,A,visited,turn,turn_point_c,turn_point_r);

	s = u;
	while(u>0){
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++){
            if(A[j][i] == 0 && V[j][i] == 0 && dir[j][i] == 'u'  && dis[j][i] == u){
                path(j,i,V,dis,dir,row,col);
            }
        }
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++) if(V[j][i] == 0) flag = false;
        if(flag == true) break;
		u--;
	}

	if(turn[0]){
        turn_path(0,'u','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[4] && turn[1]){
		turn_path(4,'u','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(1,'d','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[3] && turn[5]){
		turn_path(3,'u','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(5,'l','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[4] && turn[2] && turn[5]){
		turn_path(4,'u','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(2,'d','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(5,'l','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[3] && turn[2] && turn[1]){
		turn_path(3,'u','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(2,'l','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(1,'d','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}

	u = s;
    while(u>0){
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++){
            if(A[j][i] == 0 && V[j][i] == 0 && dir[j][i] == 'r'  && dis[j][i] == u){
                path(j,i,V,dis,dir,row,col);
            }
        }
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++) if(V[j][i] == 0) flag = false;
        if(flag == true) break;
        u--;
    }

	if(turn[1]){
		turn_path(1,'r','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[0] && turn[4]){
		turn_path(0,'r','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(4,'u','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[5] && turn[2]){
		turn_path(5,'r','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(2,'l','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[0] && turn[3] && turn[2]){
		turn_path(0,'r','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(3,'u','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(2,'l','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[5] && turn[3] && turn[4]){
		turn_path(5,'r','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(3,'l','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(4,'u','d',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}

	u = s;
    while(u>0){
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++){
            if(A[j][i] == 0 && V[j][i] == 0 && dir[j][i] == 'd' && dis[j][i] == u){
                path(j,i,V,dis,dir,row,col);
            }
        }
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++) if(V[j][i] == 0) flag = false;
        if(flag == true) break;
        u--;
    }

	if(turn[2]){
		turn_path(2,'d','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[4] && turn[3]){
		turn_path(4,'d','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(3,'u','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[1] && turn[5]){
		turn_path(1,'d','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(5,'r','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[4] && turn[0] && turn[5]){
		turn_path(4,'d','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(0,'u','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(5,'r','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}
	else if(turn[1] && turn[0] && turn[3]){
		turn_path(1,'d','r',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(0,'r','u',turn_point_r,turn_point_c,V,dis,dir,row,col);
		turn_path(3,'u','l',turn_point_r,turn_point_c,V,dis,dir,row,col);
	}

	u = s;
    while(u>0){
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++){
            if(A[j][i] == 0 && V[j][i] == 0 && dir[j][i] == 'l' && dis[j][i] == u){
                path(j,i,V,dis,dir,row,col);
            }
        }
        for(j=1;j<m+1;j++) for(i=1;i<n+1;i++) if(V[j][i] == 0) flag = false;
        if(flag == true) break;
        u--;
    }

	fin.close();
	fin.open(str+"/final.path",ios::out);
	fin<<row.size()<<endl;
	while(row.size() >0){
        fin<<row.front()-1<<" "<<col.front()-1<<endl;
		row.pop(); col.pop();
	}
	fin.close();
	return 0;
}

