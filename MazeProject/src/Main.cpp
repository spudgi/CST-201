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

using namespace std;

int main () {
	string txt[12];
	string line;

	int i=0;
	ifstream file ("input_file.txt");
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
									myfile << "s";
								} else{
									myfile << "1";
								}
							} else if (blockArray[i][j] == free) {
								if (h == 1){
									myfile << "f";
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


