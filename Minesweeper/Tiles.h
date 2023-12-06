//
// Created by otish on 4/11/2022.
//
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include "TextureManager.h"
#include "iostream"
#include "Random.h"
#ifndef MINESWEEPER_TILES_H
#define MINESWEEPER_TILES_H
using namespace std;

#endif //MINESWEEPER_TILES_H
class Tiles {

    static int tileNeighborCount;
public:
    struct Tile {
        Tile(sf::Sprite &sprite);
        sf::Sprite tile;
        vector<Tile*> neighboringTiles;
        vector<sf::Sprite*> neighboringTiles2;
        bool hasBomb = false;
        bool hasFlag = false;
        //static bool hasFlag(sf::FloatRect tempTile, vector<sf::Sprite> flag);
        int removeFlag(sf::FloatRect tempTile, vector<sf::Sprite> flag);
        int adjacentMines = 0;
    };
    struct Mine {
        Mine(sf::Sprite &sprite);
        sf::Sprite mine;

    };
    void HiddenTiles(int width, int height, int tiles);
    void RevealedTiles(int width, int height, int tiles);
    void FriendlyNeighbors(int numOfTiles);
    void NeighborCheck();
    void AddMines(int numOfMines);
    void TestFiles(vector<int> test);
    static void ResetBoard(vector<Tile> tiles, vector<sf::Sprite> &flags);
    static void RemoveSurroundingTiles(Tile &tile);
    static sf::Sprite FaceTile(const string& face, int height);
    static void RemoveTile(Tile &tile);
    vector<int> GetDigit(int num);
    vector<sf::Sprite> FlagCounter(vector<int> nums, int height);
    bool FlagChecker(sf::Sprite flag);
    vector<sf::Sprite> hiddenTiles;
    vector<Tile> otherHiddenTiles;
    vector<Mine> Mines;
    vector<Tile> revealedTiles;
    vector<Mine> Test;
    vector<sf::Sprite> digits;

    //vector<sf::Sprite*> neighboringTiles;

};