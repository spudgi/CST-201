/*
 * Main.cpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Caleb Miller
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <iomanip>

using namespace std;

class Coord {
public:
Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
int r() const { return m_r; }
int c() const { return m_c; }
private:
int m_r;
int m_c;
};
int minimum(int a[],int size) {
    int small=a[0];
    for(int i=0;i<size;i++)
        if(a[i]<small)
            small=a[i];
    return small;
}

void determineDistances(const char maze[][10], int sr, int sc, int dist[][10]) {
    stack<Coord> coordStack;
    coordStack.push(Coord(sr,sc));
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
            dist[i][j]=99;
        }
        dist[sr][sc]=0;
        int distarr[11];
        int min;
        int currval;
        while (!coordStack.empty()) {
            Coord inuse = coordStack.top();
            coordStack.pop();
            const int row = inuse.r();
            const int col = inuse.c();

            cout<<"row"<<row<<"col"<<col<<endl;
            distarr[0]=dist[row-1][col];    //      Up
            distarr[1]=dist[row+1][col];    //      Down
            distarr[2]=dist[row][col-1];    //      Left
            distarr[3]=dist[row][col+1];    //      Right
            min=minimum(distarr,11);

            if(dist[row][col]>min+1)
            dist[row][col]=min+1;
            currval=dist[row][col];
            if ((maze[row-1][col] == '.')&&(dist[row-1][col]>(currval+1))) {
            	dist[row-1][col]=currval+1;
            	coordStack.push(Coord(row+1,col));
            }
             if (maze[row+1][col] == '.'&&(dist[row+1][col]>(currval+1))) {
            	 coordStack.push(Coord(row+1,col));
             }
            if (maze[row][col+1] == '.'&&(dist[row][col+1]>(currval+1))) {
            	dist[row][col+1]=currval+1;
            	coordStack.push(Coord(row,col+1));
            }
            if (maze[row][col-1] == '.'&&(dist[row][col-1]>(currval+1))) {
            	dist[row][col-1]=dist[row][col]+1;
            	coordStack.push(Coord(row,col-1));
            }
        }
}

int main () {
	string txt[12];
	string line;

	int i=0;
	ifstream file ("MazeProject\src\input_file.txt");
	if (file.is_open()){
		while (!file.eof()){
			getline(file,line);
			txt[i]=line;
			i++;
		}
	}
	file.close();

    ofstream myfile;
    myfile.open ("maze_project.txt");

    int height = 11;
    int width = 10;

    string open = "1";
    string start = "S";
    string free = "F";
    string wall = "0";

string blockArray[11][10] = {
		{"S","1","1","1","0","1","1","1","1","1"},
		{"1","0","0","0","1","1","0","0","0","1"},
		{"1","0","1","0","1","0","1","0","1","1"},
		{"1","1","1","0","1","0","1","0","1","0"},
		{"1","0","1","0","1","0","1","1","1","1"},
		{"1","1","1","1","1","0","1","1","0","1"},
		{"0","1","1","1","0","1","1","0","0","1"},
		{"0","0","0","0","1","0","1","1","1","0"},
		{"1","1","0","1","1","1","0","1","0","1"},
		{"0","1","1","1","0","1","0","1","1","1"},
		{"1","1","1","F","0","1","1","1","0","1"},
	};


        for (int i = 0; i < height; i++) {

            // run the first time to create numbers
            if(i == 0){
                myfile << "   ";
                for (int j = 0; j < width ; j++) {
                    myfile << " " << j << " ";
                }
                myfile << endl;
                myfile << "   ";
                for (int j = 0; j < width ; j++) {
                    myfile << "_" << "_" << "_";
                }
                myfile << endl;
            }

            // run 3 times to create 3x3 block
            for (int h = 0; h < 3; h ++) {

                if(h == 1 && i < 10){
                    myfile << i << " |";
                }
                else if (h == 1 && i >= 10){
                    myfile << i << "|";
                }
                else {
                    myfile << "  |";
                }

                for (int j = 0; j < width; j++) {
					for (int k = 0; k < 3; k++) {
						if (k != 1) {
							if (blockArray[i][j] == start) {
								myfile << "1";
							} else if (blockArray[i][j] == free) {
								myfile << "1";
							} else if (blockArray[i][j] == wall) {
								myfile << "0";
							} else if (blockArray[i][j] == open) {
								myfile << "1";
							}
						} else {
							if (blockArray[i][j] == start) {
								if (h == 1){
									myfile << "S";
								} else{
									myfile << "1";
								}
							} else if (blockArray[i][j] == free) {
								if (h == 1){
									myfile << "F";
								} else{
									myfile << "1";
								}
							} else if (blockArray[i][j] == wall) {
								myfile << "0";
							} else if (blockArray[i][j] == open) {
								myfile << "1";
							}
						}
					}

				}
                myfile << endl;
            }

        }
    // write maze to file
    myfile.close();

    return 0;

}
