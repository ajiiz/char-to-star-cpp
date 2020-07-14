#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>

void characterA(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols);
void characterB(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols);
void characterC(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols);
void characterD(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols);
void vectorResize(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols);
void show(std::vector<std::vector<char>> &tab);
int main(){
    std::vector<std::vector<char>> tab;

    //Litera A
    characterA(tab,5,3);
    show(tab);
    characterA(tab,5,7);
    show(tab);
    characterA(tab,1,1);
    show(tab);

    //Litera B
    characterB(tab,5,3);
    show(tab);
    characterB(tab,6,4);
    show(tab);
    characterB(tab,10,6);
    show(tab);

    //Litera C
    characterC(tab,3,3);
    show(tab);
    characterC(tab,4,7);
    show(tab);
    characterC(tab,8,10);
    show(tab);

    //Litera D
    characterD(tab,3,3);
    show(tab);
    characterD(tab,7,5);
    show(tab);
    characterD(tab,11,8);
    show(tab);

    getchar();
    return EXIT_SUCCESS;
}

void characterA(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols){
    if(numOfRows < 3 || numOfCols < 3){
        std::cout << "Nie da sie wygenerowac litery z uwagi na zbyt maly rozmiar tablicy" << std::endl;
        tab.clear();
    } else {
        vectorResize(tab,numOfRows, numOfCols);
        //Dodawanie '*' w celu utworzenia litery A
        for(int i = 0; i < tab.size(); ++i){
            for(int j = 0; j < tab[0].size(); j++){
                tab[i][j] = '*';
                if(i==0&&(j==0||j==tab[0].size()-1)) tab[i][j] = ' ';
                else if((j>0&&j<tab[0].size()-1)&&i!=round(numOfRows/2)&&i!=0) tab[i][j] = ' ';
            }
        }
    }
}

void characterB(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols){
    if(numOfRows < 5 || numOfCols < 3){
        std::cout << "Nie da sie wygenerowac litery z uwagi na zbyt maly rozmiar tablicy" << std::endl;
        tab.clear();
    } else {
        //Inicjalizacja wektora
        vectorResize(tab,numOfRows, numOfCols);
        //Dodawanie '*' w celu utworzenia litery B
        int half = (numOfRows%2!=0) ? round(numOfRows/2) : round(numOfRows/2)-1;
        for(int i = 0; i < tab.size(); ++i){
            for(int j = 0; j < tab[0].size(); j++){
                tab[i][j] = '*';
                if(i==half){
                    tab[i][numOfCols-1]=' ';
                    continue;
                }
                else if(i!=0 && i!=numOfRows-1&&j!=0&&j!=tab[0].size()-1) tab[i][j] = ' ';
            }
        }
    }
}

void characterC(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols){
    if(numOfRows < 3 || numOfCols < 2){
        std::cout << "Nie da sie wygenerowac litery z uwagi na zbyt maly rozmiar tablicy" << std::endl;
    } else {
        //Inicjalizacja wektora
        vectorResize(tab,numOfRows, numOfCols);
        //Dodawanie '*' w celu utworzenia litery C
        for(int i = 0; i < tab.size(); ++i){
            for(int j = 0; j < tab[0].size(); j++){
                tab[i][j] = '*';
                if(i!=0&&i!=numOfRows-1&&j!=0) tab[i][j] = ' ';
            }
        }
    }
}

void characterD(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols){
    if(numOfRows < 3 || numOfCols < 3){
        std::cout << "Nie da sie wygenerowac litery z uwagi na zbyt maly rozmiar tablicy" << std::endl;
        tab.clear();
    } else {
        //Inicjalizacja wektora
        vectorResize(tab,numOfRows, numOfCols);
        //Dodawanie '*' w celu utworzenia litery D
        for(int i = 0; i < tab.size(); ++i){
            for(int j = 0; j < tab[0].size(); j++){
                if((i==numOfRows-1&&j==numOfCols-1)) tab[i][j] = ' ';
                else if(i==0&&j==numOfCols-1) tab[i][j] = ' ';
                else if(i!=0&&i!=numOfRows-1&&j!=0&&j!=numOfCols-1) tab[i][j] = ' ';
                else tab[i][j] = '*';
            }
        }
    }
}

void vectorResize(std::vector<std::vector<char>> &tab,int numOfRows, int numOfCols){
        //Inicjalizacja wektora
        tab.resize(numOfRows);
        for(int i = 0; i < tab.size(); ++i){
            tab[i].resize(numOfCols);
        }
}

void show(std::vector<std::vector<char>> &tab){
    for(int i = 0; i < tab.size(); ++i){
        for(int j = 0; j < tab[0].size(); j++){
            std::cout << tab[i][j];
        }
        std::cout << "\n";
    }
    std::cout<< "\n";
}