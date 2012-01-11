#include <iostream>
#include <string.h>
using namespace std;

const int FILESLASHES = 1;
const int WEBSLASHES = 2;

//Removes the file name from the base string that is passed in through the shell.
char * getBaseString(char * base_url){
    int slash_location = 0;
    for(int i = 0; base_url[i] != 0; i++){
        if(base_url[i]=='/'){
            slash_location = i;
        }
    }
    base_url[slash_location] = 0; 
    return base_url;
}

//Smartly concatenates two URL c-strings.
//If the base does not end in a slash, a slash is appended.
//If the url starts with a slash, it is removed
//Both the base and url pointers and values are changed
char * joinURL(char * base, char * url){
    int i =0;
    for(;base[i]!=0; i++){
    }
    if(base[i-1]!='/'){
        strcat(base, "/");
    }
    
    if(url[0]=='/'){
        strncat(base, url+1, strlen(url));
    }
    else{
        strncat(base, url, strlen(url));
    }
    return base;
}

//Collects only the top portion of the URL for resolveRoot function
//Changes the base pointer and value
char * getWebFileBase(char * base, int slashes){
    int slash_count = 0;
    int i = 0;
    for(; base[i]!=0; i++){
        if(base[i] == '/'){
            slash_count++;
        }
        if(slash_count>slashes){
            break;
        }
    }
    base[i+1] = 0;
    return base;
}

//Resolve URLs that start with '/' symbols.
//Both the base and url pointers and values are changed
char * resolveRoot(char * base, char * url){
    if(base[0] == 'h'){
        base = getWebFileBase(base, WEBSLASHES);
        url = joinURL(base, url);
    }
    else{
        base = getWebFileBase(base, FILESLASHES);
        strncat(base, url, strlen(url));
        url = base;
    }
    return url;
}

//Resolve URLs that include internal links with # symbols
//Both the base and url pointers and values are changed
char * resolveInternal(char * base, char * url){
	strncat(base, url, strlen(url));
    return base;
}

//Count the number of parent directories we are moving up
//Return this value
int countRelative(char * url){
	int relative_count = 0;
	for(int i = 0; url[i] != 0 && url[i+1] != 0; i++){
		if(url[i] == '.' && url[i+1] == '.'){
			relative_count++;
		}
	}
	return relative_count;
}

//Remove all of the './' and '../' items in the relative URL
//Return the url pointer
char * cleanRelative(char * url){
	for(int i = 0; url[i] != 0 && url[i+1] != 0; i++){
		if(url[i] >= 'A'){
			url = &url[i];
			break;
		}
	}
	return url;
}

//Go through the base and remove the number of parents specified by relative_count
//Return the base c-string
char * removeParents(char * base, int relative_count){
	for(int i = strlen(base) - 1; i >= 0; i--){
		if(base[i] == '/'){
			base[i + 1] = 0;
			relative_count--;
		}
		if(relative_count == 0) break;
	}
	return base;
}

int countParents(char * base){
	int parent_count = 0;
	for(int i = strlen(base) - 1; i> 0; i--){
		if(base[i] == '/'){
			parent_count++;
			if(base[i-1] == '/') break;
		}
	}	
	return parent_count;
}

//Resolve URL that include relative file symbols.
//These are symbols that include './' and '../'
//Both the base and url pointers and values are changed
char * resolveRelative(char * base, char * url){
	int relative_count = countRelative(url);
	int parent_count = countParents(base);
	if(relative_count > parent_count){
		relative_count = parent_count;
	}
	url = cleanRelative(url);
	base = removeParents(base, relative_count);
	base = joinURL(base,url);
    return base;
}

//Resolve URL concatenation
int main(int argc, char * argv[]){
    if(argc != 3){
        cout << "Improper use. This program is used to resolve url strings. " << endl;
        cout << "Please follow this convention: ./URLResolver <base-url> <relative-url>" << endl;
        return 0;
    }
    
    //Set up original url variables
	char * base_url = 0;
	char * url = argv[2];
	if(url[0] != '#'){
		base_url = getBaseString(argv[1]);
	}
	else{
		base_url = argv[1];
	}
    
    
    
    //Perform actions on url variables
    switch(url[0]){
        cout << "here" << endl;
        case '/':
            url = resolveRoot(base_url, url);
            break;
        case '#':
            url = resolveInternal(base_url, url);
            break;
        default:
            url = resolveRelative(base_url, url);
            break;
    }
    
    //Print out result
    cout << "New URL is: " << url << endl;

    return 0;

}
