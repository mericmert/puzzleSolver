#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void searchWord(string& input, int& total, vector<vector<char>>& matrix);
bool searchInDiagnol(string &input, vector<vector<char>>& matrix, bool &jokerUse);
bool searchInHorizontal(string &input, vector<vector<char>>& matrix);
bool searchInVertical(string &input, vector<vector<char>>& matrix);


void searchWord(string& input, int& total, vector<vector<char>> &matrix) {
	
	bool jokerUse = false;
	int input_length = input.length();
	int extrapoint = 0;
	if (input_length > 5) extrapoint += 2;

	if (searchInHorizontal(input,matrix)) {

		cout << input << " is found in the row level. It contributes " << input_length + extrapoint 
			<< " points." << endl;
		total += (input_length + extrapoint);
		return;
	}
	else if (searchInVertical(input,matrix)) {
		cout << input << " is found in the column level. It contributes " << input_length + extrapoint
			<< " points." << endl;
		total += (input_length + extrapoint);
		return;
	}
	else if (searchInDiagnol(input, matrix, jokerUse)) {
		if (jokerUse) {
			cout << input << "is found in the diagonal level. One letter was replaced by joker. It contributes "
				<< (input_length + extrapoint) * 2 - 2 << " points." << endl;
			total += (input_length + extrapoint) * 2 - 2;
			return;
		}
		cout << input << " is found in the diagonal level. It contributes " << (input_length + extrapoint) * 2
			<< " points." << endl;
		total += ((input_length + extrapoint) * 2);
		return;
	}
	else {
		cout << input << " is not found in the matrix. 5 points are deducted." << endl;
		total -= 5;
	}

}

bool searchInHorizontal(string& input, vector<vector<char>>& matrix) {
	int inplen = input.length();
	
	for (int i = 0; i < matrix.size(); i++) {
		string temp = "";
		for (int k = 0; k < matrix[0].size(); k++) {
			temp += matrix[i][k];
		}
		string brute;
		for (int startpoint = 0; startpoint < matrix[0].size() - inplen + 1; startpoint++) { //straight order
			brute = temp.substr(startpoint, inplen);
			if (input == brute) {
				return true;
			}
		}
		temp = "";
		for (int k = matrix[0].size() - 1; k >= 0; k--) {
			temp += matrix[i][k];
		}
		for (int startpoint = 0; startpoint < matrix[0].size() - inplen + 1; startpoint++) { //reverse order
			brute = temp.substr(startpoint, inplen);
			if (input == brute) {
				return true;
			}
			
		}

	}

	return false;

}

bool searchInDiagnol(string& input, vector<vector<char>>& matrix, bool &jokerUse) {
	int inplen = input.length();
	for (int i = matrix[0].size()-1; i >= 0; i--) {
		int y = 0;
		int x = i;
		string temp = "";
		while (y < matrix.size() && x >= 0 && x < matrix[0].size()) {
			temp += matrix[y][x];
			y++;
			x++;
		}
		if (temp.length() >= inplen) {
			string brute;
			for (int startpoint = 0; startpoint < temp.length() - inplen + 1; startpoint++) { //straight order
				brute = temp.substr(startpoint, inplen);
				if (input == brute) {
					return true;
				}
				else {
					int counter = 0;
					for (int b = 0; b < inplen; b++) {
						if (brute[b] == input[b]) counter++;
					}
					if (inplen - 1 == counter) {
						jokerUse = true;
						return true;
					}
				}
			}
			reverse(temp.begin(), temp.end());
			for (int startpoint = 0; startpoint < temp.length() - inplen + 1; startpoint++) { //straight order
				brute = temp.substr(startpoint, inplen);
				if (input == brute) {
					return true;
				}
				else {
					int counter = 0;
					for (int b = 0; b < inplen; b++) {
						if (brute[b] == input[b]) counter++;
					}
					if (inplen - 1 == counter) {
						jokerUse = true;
						return true;
					}
				}
			}

		}
		
	}
	cout << endl;
	for (int k = 1; k < matrix.size(); k++) {
		int y = k;
		int x = 0;
		string temp = "";
		while (x < matrix[0].size() && y < matrix.size()) {
			temp += matrix[y][x];
			y++;
			x++;
		}
		if (temp.length() >= inplen) {
			string brute;
			for (int startpoint = 0; startpoint < temp.length() - inplen + 1; startpoint++) { //straight order
				brute = temp.substr(startpoint, inplen);
				if (input == brute) {
					return true;
				}
				else {
					int counter = 0;
					for (int b = 0; b < inplen; b++) {
						if (brute[b] == input[b]) counter++;
					}
					if (inplen - 1 == counter) {
						jokerUse = true;
						return true;
					}
				}
			}
			reverse(temp.begin(), temp.end());
			for (int startpoint = 0; startpoint < temp.length() - inplen + 1; startpoint++) { //straight order
				brute = temp.substr(startpoint, inplen);
				if (input == brute) {
					return true;
				}
				else {
					int counter = 0;
					for (int b = 0; b < inplen; b++) {
						if (brute[b] == input[b]) counter++;
					}
					if (inplen - 1 == counter) {
						jokerUse = true;
						return true;
					}
				}
			}
		}
	}

	
	return false;
}

bool searchInVertical(string& input, vector<vector<char>>& matrix) {
	
	int inplen = input.length();
	for (int i = 0; i < matrix[0].size(); i++) {
		string temp = "";
		for (int k = 0; k < matrix.size(); k++) {
			temp += matrix[k][i];
		}
		string brute;
		for (int startpoint = 0; startpoint < matrix.size() - inplen + 1; startpoint++) { //down order
			brute = temp.substr(startpoint, inplen);
			if (input == brute) {
				return true;
			}
		}
		reverse(temp.begin(), temp.end());
		for (int startpoint = 0; startpoint < matrix.size() - inplen + 1; startpoint++) { //down order
			brute = temp.substr(startpoint, inplen);
			if (input == brute) {
				return true;
			}
		}
	}
	return false;
}


vector<vector<char>> storeInMatrix(ifstream& input) {
	string line;
	vector<vector<char>> matrix;
	while (getline(input, line)) {
		vector<char> rows;
		for (int i = 0; i < line.length(); i++) {
			rows.push_back(line[i]);
		}
		matrix.push_back(rows);
	}
	return matrix;
}


int main() {
	string filename;
	ifstream file;
	cout << "This program allows you to play a Sunday morning puzzle on your computer!" << endl;
	cout << "---" << endl;
	while (true) {
		cout << "Enter the matrix file name: ";
		cin >> filename;
		file.open(filename);
		if (!file.fail()) { cout << "---" << endl; break; }
		else cout << "Invalid file name!" << endl << "---" << endl;
	}
	vector<vector<char>> matrix = storeInMatrix(file);
	int rowsize = matrix.size();
	for (int i = 0; i < rowsize; i++) {
		if (matrix[i].size() != matrix[0].size()) {
			cout << "The matrix does not have row equality, terminating...";
			return 1;
		}
	}
	int totalpoint = 0;
	string input;
	while (true) {
		cout << "Enter a word: ";
		cin >> input;
		if (input.length() < 3) break;
		searchWord(input, totalpoint, matrix);
	}
	cout << "Game has ended!" << endl;
	cout << "Total score of the worlds: " << totalpoint << endl;


	return 0;
}