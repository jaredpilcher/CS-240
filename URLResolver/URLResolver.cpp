#include <iostream>
#include <string.h>
using namespace std;

const int FILESLASHES = 1;
const int WEBSLASHES = 2;

char * getBaseString(char * base_url){
    int slash_location = 0;
    for(int i = 0; base_url[i] != 0; i++){
        if(base_url[i]=='/'){
            slash_location = i;
        }
    }
    base_url[slash_location + 1] = 0; 
    return base_url;
}

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

char * resolveInternal(char * base, char * url){
    return base;
}

char * resolveRelative(char * base, char * url){
    return base;
}

int main(int argc, char * argv[]){
    if(argc != 3){
        cout << "Improper use. This program is used to resolve url strings. " << endl;
        cout << "Please follow this convention: ./URLResolver <base-url> <relative-url>" << endl;
        return 0;
    }
    
    char * original_base = argv[1];
    char * base_url = getBaseString(argv[1]);
    char * url = argv[2];
    
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
    
    cout << "New URL is: " << url << endl;

    return 0;

}