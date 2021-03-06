#include <iostream>
#include <string.h>
#include <strings.h>
#include <cstdlib>
#include <fstream>
#include <cassert>
using namespace std;

int reverse=0, case_sense=1, numeric=0, field=1;
const int MAX=2048, MEMSETOFFSET=8;

void resolveArguments(int & reverse, int & case_sense, 
					int & numeric, int & field, char input_file[], 
					const int argc, char * argv[]);

void getField(char field_buffer[], char line_buffer[], int field);


class String{
private:
	char line[MAX];
	char field[MAX];
public:
	
	String(char line_arg[], char field_arg[]){
		strncpy(line, line_arg, strlen(line_arg)+1);
		strncpy(field, field_arg, strlen(field_arg)+1);
	}
	
	char * getField(){return field;}
	char * getLine() {return line;}
	friend ostream& operator << (ostream& s, String& string_object);
	friend int compareStrings(const void * pstring1, const void * pstring2);
	
};

ostream& operator << (ostream& s, String& string_object){
		s << string_object.line;
		return s;
}

int compareStrings(const void * pstring1, const void * pstring2){
	String ** string1 = (String**) pstring1;
	String ** string2 = (String**) pstring2;
	
	//comparison based on arguments
	if(numeric){
	    int int1 = atoi((*string1)->getField());
	    int int2 = atoi((*string2)->getField());
	    int return_value=0;
	    if(int1>int2){return_value = -1;}
	    else if(int1==int2){return_value = 0;}
	    else {return_value = 1;}
	    if(reverse){
	        return return_value;
	    }
	    else{
	        return (-1)*return_value;
	    }
	    
	}
	else if(reverse){
	      if(case_sense){
		return (-1)*strncmp((*string1)->getField(), (*string2)->getField(), MAX);
	      }
	      else{
		char tempstr1 [MAX];
		char tempstr2 [MAX];
		strcpy(tempstr1, (*string1)->getField());
		strcpy(tempstr2, (*string2)->getField());
		return (-1)*strncasecmp((*string1)->getField(), (*string2)->getField(), MAX);
	      }
	}
	else if(!case_sense){
	      char tempstr1 [MAX];
	      char tempstr2 [MAX];
	      strcpy(tempstr1, (*string1)->getField());
	      strcpy(tempstr2, (*string2)->getField());
	      return strncasecmp((*string1)->getField(), (*string2)->getField(), MAX);
	}
	else{
	      return strncmp((*string1)->getField(), (*string2)->getField(), MAX);
	}
}


int main(int argc, char * argv[]){
	//handle arguments and initialize argument variables.
	//command arguments are stored as global variables so that compareStrings() can access them.
	char input_file[MAX];
	resolveArguments(reverse, case_sense, numeric, field, input_file, argc, argv);
	
	//parse through file and gather lines and fields. 
	//Create Strings to store fields and lines. 
	//Store pointers to each String in line_list. 
	ifstream infile(input_file);
	assert(infile);
	String * line_list[MAX];
	char line_buffer[MAX];
	char field_buffer[MAX];
	int i=0;
	while(1){
		memset(line_buffer, 0, MAX-MEMSETOFFSET);
		memset(field_buffer, 0, MAX-MEMSETOFFSET);
		infile.getline(line_buffer, MAX);
		if(!infile){break;}
		getField(field_buffer, line_buffer, field);
		if(field_buffer[0]){
			line_list[i] = new String(line_buffer, field_buffer);
			i++;
		}
	}
	
	
	//sort line_list using qsort. Comparison function described above.
	qsort(line_list, i, sizeof(line_list[0]), compareStrings);
	
	//print line_list
	for(int j = 0; j<i; j++){
		cout << (*line_list[j]) << endl;
	}

	return 0;


}

void getField(char field_buffer[], char line_buffer[], int field){
	int i;
	for(i=0; line_buffer[i+1]; i++){
		if(isspace(line_buffer[i]) && !isspace(line_buffer[i+1])){
			field--;
		}
		if(field==1){
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
