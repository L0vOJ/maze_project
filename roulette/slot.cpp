//#include"../lib/getch.cpp"
#include"../maze_frame_2/command.cpp"
#include"../maze_frame_2/main_frame.h"

using namespace std;

int modify_slot(int* input,int cursor){
    command bring;
    int decision = bring.keybinding(getch());
    switch(decision){
        case 1:
            if(cursor<5) input[cursor]++;
            return cursor;
        case 2:
            if(cursor<5) input[cursor]+=10;
            return cursor;
        break;
        case 3:
            if(cursor<5) input[cursor]+=100;
            return cursor;
        case 4:
            return cursor-1;
        break;
        case 5:
            return 5;
        break;
        case 6:
            return cursor+1;
        break;
        case 7:
            if(cursor<5) input[cursor] = input[cursor]?input[cursor]-1:input[cursor];
        break;
        case 8:
            if(cursor<5) input[cursor] = input[cursor]?input[cursor]-10:input[cursor];
        break;
        case 9:
            if(cursor<5) input[cursor] = input[cursor]?input[cursor]-100:input[cursor];
        break;
    }
    return cursor;
}