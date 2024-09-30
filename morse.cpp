// morse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
using namespace std;
#include <iostream>
#include <string>


class node {
public:
    char ch;
    node* dot;
    node* dash;
    struct tuple {
        char alph;
        string code;
    };
    node() {
        this->ch = NULL;
        this->dash = NULL;
        this->dot = NULL;
    }
    node (char letter) {
        this->ch = letter;
        this->dot = NULL;
        this->dash = NULL;

    }
    void init (node* root, tuple letter) {
        int i = 0;
        node* current = root;
        for (i = 0; i < letter.code.length(); i++) {
            
            switch (letter.code[i]) {
            case '.':
                if (current->dot == NULL) current->dot = new node('+');
                    current = current->dot;
                   
                                   
            case '-':
                if (current->dash == NULL) current->dash = new node('+');
                current = current->dash;
                
            };
            
        }
        current->ch = letter.alph;
        
        
        
    }
    char get(node* basenode, string tone) {
        int i = 0;
        node* currentptr = basenode;
        for (i = 0; i < tone.length(); i++) {
            
            if (tone[i] == '.') {
                currentptr = currentptr->dot;
             }
            if (tone[i] == '-') {
                currentptr = currentptr->dash;
                
            }
        }
        return currentptr->ch;
    }
    
};



int main(int argc, char* argv[]) {

    node root(' ');
    node& base = root;
    node::tuple morse[36] = { 'A',".-",'B',"-...",'C',"-.-.",
               'D',"-..",'E',".",'F',"..-.",'G',"--.",'H',"....",
               'I',"..",'J',".---",'K',"-.-",'L',".-..",
               'M',"--",'N',"-.",'O',"---",'P',".--.",'Q',"--.-",
               'R',".-.",'S',"...",'T',"-",'U',"..-",'V',"...-",
               'W',".--",'X',"-..-",'Y',"-.--",'Z',"--..",
               '1',".----",'2',"..---",'3',"...--",'4',"....-",
               '5',".....",'6',"- ....",'7',"--...",'8',"---..",
               '9',"----.",'0',"-----" };
    int i = 0;
    for (i = 0; i < sizeof(morse) / sizeof(node::tuple); i++) {
        root.init(&root, morse[i]);
        
    }
    
    for (i = 1; i < argc; i++ ) {
        cout << root.get(&root, argv[i]);
    }
    

}

