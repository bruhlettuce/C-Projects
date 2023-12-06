#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include "FileManager.h"
#include "TextureManager.h"
#include "Tiles.h"
#include "vector"
#include <map>
#include <string>
#include "Random.h"

using namespace std;
int main()
{
    sf::Event event;
    FileManager cfg;
    Tiles tileData;
    map<string, int>windowData;
    cfg.Config(windowData);

    //Game State
    int gameState = 0;
    /*
     * 0 = normal
     * 1 = debug
     */
    int testFile = 0;

    //Sprites
    map<string, sf::Sprite>textureData;
    textureData.emplace("hidden tile", TextureManager::GetTexture("tile_hidden"));
    textureData.emplace("revealed tile", TextureManager::GetTexture("tile_revealed"));
    textureData.emplace("flag", TextureManager::GetTexture("flag"));
    textureData.emplace("happy face", TextureManager::GetTexture("face_happy"));
    textureData.emplace("debug", TextureManager::GetTexture("debug"));
    textureData.emplace("test1", TextureManager::GetTexture("test_1"));
    textureData.emplace("test2", TextureManager::GetTexture("test_2"));
    textureData.emplace("test3", TextureManager::GetTexture("test_3"));
    textureData.emplace("1", TextureManager::GetTexture("number_1"));
    textureData.emplace("2", TextureManager::GetTexture("number_2"));
    textureData.emplace("3", TextureManager::GetTexture("number_3"));
    textureData.emplace("4", TextureManager::GetTexture("number_4"));
    textureData.emplace("5", TextureManager::GetTexture("number_5"));
    textureData.emplace("6", TextureManager::GetTexture("number_6"));
    textureData.emplace("7", TextureManager::GetTexture("number_7"));
    textureData.emplace("8", TextureManager::GetTexture("number_8"));




    //Sprite Positioning (if needed)
    textureData.at("debug").setPosition(448, ((windowData["height"]-100)/32)*32);
    textureData.at("test1").setPosition(512, ((windowData["height"]-100)/32)*32);
    textureData.at("test2").setPosition(576, ((windowData["height"]-100)/32)*32);
    textureData.at("test3").setPosition(640, ((windowData["height"]-100)/32)*32);

    //Window
    sf::RenderWindow window(sf::VideoMode(windowData["width"], windowData["height"]), "Minesweeper");

    //Tile Creation
    tileData.RevealedTiles(windowData["width"],windowData["height"],windowData["tiles"]);
    tileData.HiddenTiles(windowData["width"],windowData["height"],windowData["tiles"]);
    tileData.FriendlyNeighbors(windowData["tiles"]);
    tileData.AddMines(windowData["mines"]);


    //Variables:
    string faceType = "happy";
    bool debugButton = true;
    vector<sf::Sprite> flags;
    int digitCount = 0;
    vector<sf::Sprite> flagCounter = tileData.FlagCounter(tileData.GetDigit(windowData["mines"]), windowData["height"]);
    int tilesRemaining = windowData["tiles"];


    while (window.isOpen()) {

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && faceType == "happy") {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Reveal Teal, maybe try to put this in a class
                    //cout << "Left Key Pressed" << endl;
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

                    //Debug Button
                    sf::FloatRect debugSquare = textureData["debug"].getGlobalBounds();
                    if (debugSquare.contains(mousePosition.x, mousePosition.y) && !debugButton) {
                        debugButton = true;
                        if (gameState == 1) {
                            gameState = 0;
                        }
                    }
                    else if (debugSquare.contains(mousePosition.x, mousePosition.y) && debugButton) {
                        debugButton = false;
                        if (gameState == 0) {
                            gameState = 1;
                        }
                    }

                    //Test 0 Button
                    sf::FloatRect happySquare = Tiles::FaceTile(faceType, windowData["height"]).getGlobalBounds();
                    if (happySquare.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.Mines.clear();
                        tileData.AddMines(windowData["mines"]);
                        testFile = 0;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }


                    //Test 1 Button
                    sf::FloatRect test1Square = textureData["test1"].getGlobalBounds();
                    if (test1Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        cfg.TestFile("boards/testboard1.brd");
                        tileData.TestFiles(cfg.Test);
                        testFile = 1;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }

                    //Test 2 Button
                    sf::FloatRect test2Square = textureData["test2"].getGlobalBounds();
                    if (test2Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard2.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 2;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }

                    //Test 3 Button
                    sf::FloatRect test3Square = textureData["test3"].getGlobalBounds();
                    if (test3Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard3.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 3;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }

                    // Tile left click
                    for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                        sf::FloatRect square = tileData.otherHiddenTiles.at(i).tile.getGlobalBounds();
                        if (square.contains(mousePosition.x, mousePosition.y)) {
                            if (tileData.otherHiddenTiles.at(i).hasFlag) {
                                break;
                            }
                            if (tileData.otherHiddenTiles.at(i).hasBomb) {
                                //flags.clear();
                                faceType = "lose";
                                for (int x = 0; x < tileData.otherHiddenTiles.size(); x++) {
                                    if (tileData.otherHiddenTiles.at(x).hasBomb) {
                                        Tiles::RemoveTile(tileData.otherHiddenTiles.at(x));
                                    }
                                }
                            }
                            Tiles::RemoveSurroundingTiles(tileData.otherHiddenTiles.at(i));
                        }
                    }
                    tilesRemaining = windowData["tiles"];
                    for (int a = 0; a < tileData.otherHiddenTiles.size(); a++) {
                        if (tileData.otherHiddenTiles.at(a).tile.getScale() == sf::Vector2f(0, 0)){
                            tilesRemaining--;
                        }
                    }
                    if (tilesRemaining == windowData["mines"] && testFile == 0) {
                        faceType = "win";
                        digitCount = windowData["mines"];
                    }
                    else if(tilesRemaining == tileData.Test.size() && testFile != 0) {
                        faceType = "win";
                        digitCount = tileData.Test.size();
                    }

                }
                if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
                    //cout << "Right Key Pressed" << endl;
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                        sf::FloatRect square = tileData.otherHiddenTiles.at(i).tile.getGlobalBounds();
                        if (square.contains(mousePosition.x, mousePosition.y)) {
                            if (tileData.otherHiddenTiles.at(i).hasFlag && !flags.empty()) {
                                int tileNumber = tileData.otherHiddenTiles.at(i).removeFlag(square, flags);
                                tileData.otherHiddenTiles.at(i).hasFlag = false;
                                flags.erase(flags.begin() + tileNumber);
                                //cout << "Flag Removed" << endl;
                                digitCount--;
                                if (flags.size() == tileData.Mines.size() || (flags.size() == tileData.Test.size() && !tileData.Test.empty())) {
                                    int flagCount = 0;
                                    for (int x = 0; x < tileData.otherHiddenTiles.size(); x++) {
                                        if (flagCount == tileData.Mines.size() || (flagCount == tileData.Test.size() && !tileData.Test.empty())) {
                                            faceType = "win";
                                        }
                                        if (tileData.otherHiddenTiles.at(x).hasBomb && !tileData.otherHiddenTiles.at(x).hasFlag) {
                                            break;
                                        }
                                        if (tileData.otherHiddenTiles.at(x).hasBomb && tileData.otherHiddenTiles.at(x).hasFlag) {
                                            flagCount++;
                                        }
                                    }
                                }
                                break;
                            }
                            sf::Sprite tempFlag(TextureManager::GetTexture("flag"));
                            sf::Vector2f temp = tileData.otherHiddenTiles.at(i).tile.getPosition();
                            tempFlag.setPosition(temp);
                            flags.push_back(tempFlag);
                            tileData.otherHiddenTiles.at(i).hasFlag = true;
                            digitCount++;

                            // Flag Win Condition
                            if (flags.size() == tileData.Mines.size() || (flags.size() == tileData.Test.size() && !tileData.Test.empty())) {
                                int flagCount = 0;
                                for (int x = 0; x < tileData.otherHiddenTiles.size(); x++) {
                                    if (flagCount == tileData.Mines.size() || (flagCount == tileData.Test.size() && !tileData.Test.empty())) {
                                        faceType = "win";
                                    }
                                    if ((tileData.otherHiddenTiles.at(x).hasBomb && !tileData.otherHiddenTiles.at(x).hasFlag) || (!tileData.otherHiddenTiles.at(x).hasBomb && tileData.otherHiddenTiles.at(x).hasFlag)) {
                                        break;
                                    }
                                    if (tileData.otherHiddenTiles.at(x).hasBomb && tileData.otherHiddenTiles.at(x).hasFlag) {
                                        flagCount++;
                                    }
                                }
                            }
                            //cout << "Tile " << i << " was clicked!" << endl;
                        }
                    }
                }
            }

            // Lose
            if (event.type == sf::Event::MouseButtonPressed && faceType == "lose") {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Reveal Teal, maybe try to put this in a class
                    //cout << "Lose" << endl;
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect happySquare = Tiles::FaceTile(faceType, windowData["height"]).getGlobalBounds();

                    sf::FloatRect test1Square = textureData["test1"].getGlobalBounds();
                    if (test1Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        cfg.TestFile("boards/testboard1.brd");
                        tileData.TestFiles(cfg.Test);
                        testFile = 1;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }

                    //Test 2 Button
                    sf::FloatRect test2Square = textureData["test2"].getGlobalBounds();
                    if (test2Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard2.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 2;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }

                    //Test 3 Button
                    sf::FloatRect test3Square = textureData["test3"].getGlobalBounds();
                    if (test3Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard3.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 3;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];
                    }
                    if (happySquare.contains(mousePosition.x, mousePosition.y)) {
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.Mines.clear();
                        tileData.AddMines(windowData["mines"]);
                        testFile = 0;
                        faceType = "happy";
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];

                    }
                }
            }

            // Win
            if (event.type == sf::Event::MouseButtonPressed && faceType == "win") {
                /*for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                    if (tileData.otherHiddenTiles.at(i).hasBomb) {
                        tileData.otherHiddenTiles.at(i).hasFlag = true;
                    }
                }*/
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    //cout << "Win" << endl;
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect happySquare = Tiles::FaceTile(faceType, windowData["height"]).getGlobalBounds();

                    sf::FloatRect test1Square = textureData["test1"].getGlobalBounds();
                    if (test1Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        cfg.TestFile("boards/testboard1.brd");
                        tileData.TestFiles(cfg.Test);
                        testFile = 1;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];

                    }

                    //Test 2 Button
                    sf::FloatRect test2Square = textureData["test2"].getGlobalBounds();
                    if (test2Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard2.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 2;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];

                    }

                    //Test 3 Button
                    sf::FloatRect test3Square = textureData["test3"].getGlobalBounds();
                    if (test3Square.contains(mousePosition.x, mousePosition.y)) { // if button has not been pressed
                        cfg.TestFile("boards/testboard3.brd");
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.TestFiles(cfg.Test);
                        testFile = 3;
                        digitCount = 0;
                        tilesRemaining = windowData["tiles"];

                    }
                    if (happySquare.contains(mousePosition.x, mousePosition.y)) {
                        Tiles::ResetBoard(tileData.otherHiddenTiles, flags);
                        tileData.Mines.clear();
                        tileData.AddMines(windowData["mines"]);
                        testFile = 0;
                        digitCount = 0;
                        faceType = "happy";
                        tilesRemaining = windowData["tiles"];

                    }
                }
            }
        }


        if (gameState == 0) {
                window.clear(sf::Color(255, 255, 255, 255));
                for (int i = 0; i < windowData["tiles"]; i++) {
                    window.draw(tileData.revealedTiles.at(
                            i).tile); // I could set the position and then draw the same to save space
                }
                if (faceType == "lose")
            for (int i = 0; i < flags.size(); i++) {
                window.draw(flags.at(i));
            }
                if (testFile == 0) {
                    for (int i = 0; i < windowData["mines"]; i++) {
                        window.draw(tileData.Mines.at(i).mine);
                    }
                }
                if (testFile == 1 || testFile == 2 || testFile == 3) {
                    for (int i = 0; i < tileData.Test.size(); i++) {
                        window.draw(tileData.Test.at(i).mine);
                    }
                }
                for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                    window.draw(tileData.otherHiddenTiles.at(
                            i).tile); // I could set the position and then draw the same to save space
                }
                if (faceType == "win") {
                    for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                        if (tileData.otherHiddenTiles.at(i).hasBomb) {
                        textureData["flag"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["flag"]);
                        }
                    }
                }
                for (int i = 0; i < flags.size(); i++) {
                    if (faceType != "lose")
                    window.draw(flags.at(i));
                    if (faceType == "lose" && tileData.FlagChecker(flags.at(i))) {
                        window.draw(flags.at(i));
                    }
                }
                for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 1) {
                        textureData["1"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["1"]);
                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 2) {
                        textureData["2"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["2"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 3) {
                        textureData["3"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["3"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 4) {
                        textureData["4"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["4"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 5) {
                        textureData["5"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["5"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 6) {
                        textureData["6"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["6"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 7) {
                        textureData["7"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["7"]);

                    }
                    if (tileData.otherHiddenTiles.at(i).adjacentMines == 8) {
                        textureData["8"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["8"]);

                    }
                }
                window.draw(textureData.at("debug"));
                window.draw(textureData.at("test1"));
                window.draw(textureData.at("test2"));
                window.draw(textureData.at("test3"));
                window.draw(Tiles::FaceTile(faceType, windowData["height"]));
                if (testFile == 0) {
                    flagCounter = tileData.FlagCounter(tileData.GetDigit(windowData["mines"]-digitCount), windowData["height"]);
                    for (int i = 0; i < flagCounter.size(); i++) {
                        window.draw(flagCounter.at(i));
                    }
                }
            if (testFile == 1 || testFile == 2 || testFile == 3) {
                flagCounter = tileData.FlagCounter(tileData.GetDigit(tileData.Test.size()-digitCount), windowData["height"]);
                for (int i = 0; i < flagCounter.size(); i++) {
                    window.draw(flagCounter.at(i));
                }
            }
                window.display();
        }


        if (gameState == 1) {
            //window.clear();
            for (int i = 0; i < windowData["tiles"]; i++) {
                window.draw(tileData.revealedTiles.at(i).tile); // I could set the position and then draw the same to save space
            }
            for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                window.draw(tileData.otherHiddenTiles.at(
                        i).tile); // I could set the position and then draw the same to save space
            }
            for (const auto &flag: flags) {
                window.draw(flag);
            }
            if (faceType == "win") { // draws flag in debug mode after win FIX ME
                for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                    if (tileData.otherHiddenTiles.at(i).hasBomb) {
                        textureData["flag"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                        window.draw(textureData["flag"]);
                    }
                }
            }
            if (testFile == 0) {
                for (int i = 0; i < windowData["mines"]; i++) {
                    window.draw(tileData.Mines.at(i).mine);
                }
            }
            if (testFile == 1 || testFile == 2 || testFile == 3) {
                for (int i = 0; i < tileData.Test.size(); i++) {
                    window.draw(tileData.Test.at(i).mine);
                }
            }
            for (int i = 0; i < tileData.otherHiddenTiles.size(); i++) {
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 1) {
                    textureData["1"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["1"]);
                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 2) {
                    textureData["2"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["2"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 3) {
                    textureData["3"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["3"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 4) {
                    textureData["4"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["4"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 5) {
                    textureData["5"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["5"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 6) {
                    textureData["6"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["6"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 7) {
                    textureData["7"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["7"]);

                }
                if (tileData.otherHiddenTiles.at(i).adjacentMines == 8) {
                    textureData["8"].setPosition(tileData.otherHiddenTiles.at(i).tile.getPosition());
                    window.draw(textureData["8"]);

                }
            }
            window.draw(textureData.at("debug"));
            window.draw(textureData.at("test1"));
            window.draw(textureData.at("test2"));
            window.draw(textureData.at("test3"));
            window.draw(Tiles::FaceTile(faceType, windowData["height"]));
            if (testFile == 0) {
                flagCounter = tileData.FlagCounter(tileData.GetDigit(windowData["mines"]-digitCount), windowData["height"]);
                for (int i = 0; i < flagCounter.size(); i++) {
                    window.draw(flagCounter.at(i));
                }
            }
            if (testFile == 1 || testFile == 2 || testFile == 3) {
                flagCounter = tileData.FlagCounter(tileData.GetDigit(tileData.Test.size()-digitCount), windowData["height"]);
                for (int i = 0; i < flagCounter.size(); i++) {
                    window.draw(flagCounter.at(i));
                }
            }
            window.display();

        }
    }

    return 0;
}
/* Saved for future reference: if (event.type == sf::Event::MouseButtonPressed) {
                cout << "Mouse Pressed" << endl;
                if (event.key.code == sf::Mouse::Left) {
                    cout << "Left key pressed" << endl;
                }
            }*///tileData.otherHiddenTiles.at(i).tile.setTexture(
//TextureManager::GetTexture("tile_revealed"));