#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

const int MAX=2048;

void resolveArguments(int & reverse, int & case_sense, int & numeric, int & field, char input_file[], const int argc, char * argv[]);

void getField(char field_buffer[], char line_buffer[], int field);


class String{
private:
	char line[MAX];
	
public:
	char field[MAX];
	String(char line_arg[], char field_arg[]){
		strncpy(line, line_arg, strlen(line_arg)+1);
		strncpy(field, field_arg, strlen(field_arg)+1);
	}
};



int main(int argc, char * argv[]){
	//handle arguments and initialize argument variables
	int reverse=0, case_sense=1, numeric=0, field=1;
	char input_file[MAX];
	resolveArguments(reverse, case_sense, numeric, field, input_file, argc, argv);
	
	ifstream infile(input_file);
	int i=0;
	String * line_list[MAX];
	char line_buffer[MAX];
	char field_buffer[MAX];
	
	while(1){
		memset(line_buffer, 0, MAX);
		memset(field_buffer, 0, MAX);
		infile.getline(line_buffer, MAX);
		if(!infile){break;}
		getField(field_buffer, line_buffer, field);
		if(field_buffer[0]){
			line_list[i] = new String(line_buffer, field_buffer);
			cout << line_list[i]->field << endl;
			i++;
		}
		
	}

	return 0;


}

void getField(char field_buffer[], char line_buffer[], int field){
	int i;
	for(i=0; line_buffer[i+1]; i++){
		if(isspace(line_buffer[i]) && !isspace(line_buffer[i+1])){
			field--;
		}
		if(!field){
			break;
		}
	}
	int j=i;
	while(1){
		if(!isspace(line_buffer[j]) && isspace(line_buffer[j+1])){
			break;
		}
		j++;
	}
	if(!i){
		strncpy(field_buffer, &line_buffer[i], j-i+1);
	}
	else{
		strncpy(field_buffer, &line_buffer[i+1], j-i);
	}
	
	return;

	
}

void resolveArguments(int & reverse, int & case_sense, int & numeric, int & field, 
			char input_file[], const int argc, char * argv[]){
	if(argc == 4){
		if(argv[1][0] == '-'){
			for(int i = 1; i<strlen(argv[1]); i++){
				switch(argv[1][i]){
					case 'r':
						reverse = 1;
						break;
					case 'i':
						case_sense=0;
						break;
					case 'n':
						numeric=1;
						break;
				}
			}
		}
		else{
			cout << "Must specify an argument using a \'-\'" << endl;
			exit(0);
		}
		field = atoi(argv[2]);
		strncpy(input_file, argv[3], strlen(argv[3])+1);
	}
	else if(argc==3){
		field = atoi(argv[1]);
		strncpy(input_file, argv[2], strlen(argv[2])+1);
	}
	else{
		cout << "Invalid Number of arguments" << endl;
		exit(0);
	}
}
