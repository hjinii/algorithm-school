#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream f_read("bridge.inp");
ofstream f_write("bridge.out");

int main(void) {
	vector<char> player;
	player.push_back('N');
	player.push_back('E');
	player.push_back('S');
	player.push_back('W');
	
	vector<string> s(13);
	vector<string> w(13);
	vector<string> n(13);
	vector<string> e(13);

	char dealer;
	int start;
	f_read >> dealer;
	for (int i = 0; i < 4; i++) {
		if (player[i] == dealer)
			start = i;
	}




	f_read.close();
	f_write.close();
}