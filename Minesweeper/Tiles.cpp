//
// Created by otish on 4/11/2022.
//

#include "Tiles.h"

Tiles::Tile::Tile(sf::Sprite &sprite) {
    tile = sprite;
}


int Tiles::Tile::removeFlag(sf::FloatRect tempTile, vector<sf::Sprite> flag) {
    for (int i = 0; i < flag.size(); i++) {
        sf::FloatRect flagSize = flag.at(i).getGlobalBounds();
        if (flagSize.intersects(tempTile)) {
            return i;
        }
    }
    return false;
}

Tiles::Mine::Mine(sf::Sprite &sprite) {
    mine = sprite;
}

void Tiles::RemoveTile(Tile &tile) {
    tile.tile.setScale(0, 0);
}
void Tiles::HiddenTiles(int width, int height, int tiles) {
    for (int i = 0; i < tiles; i++) {
        static float positionX = 0;
        static float positionY = 0;
        static int colCount = 0;
        static int rowCount = 0;
        if (rowCount == (height - 100)/32) {
            break;
        }
        if (colCount == width/32) {
            positionX = 0;
            positionY += 32;
            colCount = 0;
            rowCount++;
        }
        else if (i > 0) {
            positionX+= 32;
        }
        sf::Sprite tempHiddenTile(TextureManager::GetTexture("tile_hidden"));
        tempHiddenTile.setPosition(positionX, positionY);
        Tile aTile(tempHiddenTile);
        hiddenTiles.push_back(tempHiddenTile);
        otherHiddenTiles.push_back(aTile);
        colCount++;
    }
}

void Tiles::RevealedTiles(int width, int height, int tiles) {
    for (int i = 0; i < tiles; i++) {
        static float positionX = 0;
        static float positionY = 0;
        static int colCount = 0;
        static int rowCount = 0;
        if (rowCount == (height - 100) / 32) {
            break;
        }
        if (colCount == width / 32) {
            positionX = 0;
            positionY += 32;
            colCount = 0;
            rowCount++;
        } else if (i > 0) {
            positionX += 32;
        }
        sf::Sprite tempRevealedTile(TextureManager::GetTexture("tile_revealed"));
        tempRevealedTile.setPosition(positionX, positionY);
        Tile aTile(tempRevealedTile);
        revealedTiles.push_back(aTile);
        colCount++;
    }
}
void Tiles::FriendlyNeighbors(int numOfTiles) {
    for (int a = 0; a < numOfTiles; a++) {
        sf::Vector2f mainTile = hiddenTiles.at(a).getPosition();
        for (int i = 0; i < numOfTiles; i++) {
            sf::Vector2f comparedTile = hiddenTiles.at(i).getPosition();
            if (i == a) {
                continue;
            }
            if ((mainTile.x+32 == comparedTile.x || mainTile.x-32 == comparedTile.x || mainTile.x == comparedTile.x)
            && (mainTile.y-32 == comparedTile.y || mainTile.y+32 == comparedTile.y || mainTile.y == comparedTile.y)
            ) {
                //Adds sprite objects:
                otherHiddenTiles.at(a).neighboringTiles2.push_back(&hiddenTiles.at(i));

                //Adds tile objects:
                otherHiddenTiles.at(a).neighboringTiles.push_back(&otherHiddenTiles.at(i));
            }
        }
    }
    sf::Sprite digit(TextureManager::GetTexture("digits"));
    digit.setPosition(32, 512);
    for (int i = 0; i <= 231;) {
        digit.setTextureRect(sf::IntRect(i, 0, 21, 32));
        i += 21;
        digits.push_back(digit);
    }
}

void Tiles::NeighborCheck() {
    for (int a = 0; a < 400; a++) {
        sf::Vector2f compare = hiddenTiles.at(a).getPosition();
        cout << "Tile " << a << endl;
        cout << "X Position: " << compare.x << endl;
        cout << "Y Position: " << compare.y << endl;
        cout << "Neighboring Tiles: " << endl;
        for (int i = 0; i < otherHiddenTiles.at(a).neighboringTiles.size(); i++) {
            sf::Vector2f test = otherHiddenTiles.at(a).neighboringTiles.at(i)->tile.getPosition();
            cout << "X Position: " << test.x << endl;
            cout << "Y Position: " << test.y << endl;
            cout << endl;

        }
    }
}

void Tiles::AddMines(int numOfMines) {
    vector<int> randomNumbers;
    int a = 0;
    for (int i = 0; i < numOfMines;) {
        a = Random::Int(0, otherHiddenTiles.size()-1);
        randomNumbers.push_back(a);
        if (Random::SameNumber(randomNumbers, a)) {
            sf::Vector2f bombPlace = otherHiddenTiles.at(a).tile.getPosition();
            otherHiddenTiles.at(a).hasBomb = true;
            revealedTiles.at(a).hasBomb = true;
            sf::Sprite tempMine(TextureManager::GetTexture("mine"));
            tempMine.setPosition(bombPlace.x, bombPlace.y);
            Mine _mine(tempMine);
            Mines.push_back(_mine);
            i++;
        }
    }
}

void Tiles::TestFiles(vector<int> test) {
    Test.clear();
    for (int i = 0; i < test.size(); i++) {
        if (test.at(i) == 1) {
            sf::Vector2f bombPlace = otherHiddenTiles.at(i).tile.getPosition();
            otherHiddenTiles.at(i).hasBomb = true;
            sf::Sprite tempMine(TextureManager::GetTexture("mine"));
            tempMine.setPosition(bombPlace.x, bombPlace.y);
            Mine _mine(tempMine);
            Test.push_back(_mine);
        }
    }
}

void Tiles::ResetBoard(vector<Tile> tiles, vector<sf::Sprite> &flags) {
    flags.clear();
    for (int i = 0; i < tiles.size(); i++) {
        tiles.at(i).hasFlag = false;
        for (int a = 0; a < tiles.at(i).neighboringTiles.size(); a++) {
            tiles.at(i).neighboringTiles.at(a)->hasBomb = false;
            tiles.at(i).neighboringTiles.at(a)->hasFlag = false;
            tiles.at(i).neighboringTiles.at(a)->tile.setScale(1, 1);
            tiles.at(i).neighboringTiles.at(a)->adjacentMines = 0;
        }
    }
}

void Tiles::RemoveSurroundingTiles(Tile &tile) { // I have to figure out how to make the tiles next to the bomb stay hidden
    sf::Vector2f compare(0, 0);
    if (tile.hasBomb) {
        RemoveTile(tile);
    }
    if (!tile.hasBomb) {
        RemoveTile(tile);
        for (int i = 0; i < tile.neighboringTiles.size(); i++) {
            if (tile.neighboringTiles.at(i)->hasBomb) {
                for (int x = 0; x < tile.neighboringTiles.size(); x++) {
                    if (tile.neighboringTiles.at(x)->hasBomb) {
                        tile.adjacentMines++;
                    }
                }
                break;
            }
            if (i >= tile.neighboringTiles.size() - 1) {
                for (int a = 0; a < tile.neighboringTiles.size(); a++) {
                    //sf::FloatRect square = tile.neighboringTiles.at(a)->tile.getGlobalBounds();
                    if (tile.neighboringTiles.at(a)->tile.getScale() != compare && !tile.neighboringTiles.at(a)->hasFlag)
                        RemoveSurroundingTiles(*tile.neighboringTiles.at(a));
                }
            }
        }
    }
}

sf::Sprite Tiles::FaceTile(const string& face, int height) {
    sf::Sprite happy(TextureManager::GetTexture("face_happy"));
    happy.setPosition(320, ((height-100)/32)*32);
    if (face == "happy") {
        return happy;
    }
    if (face == "win") {
        happy.setTexture(TextureManager::GetTexture("face_win"));
    }
    if (face == "lose") {
        happy.setTexture(TextureManager::GetTexture("face_lose"));
    }
    return happy;
}

vector <int> Tiles::GetDigit(int num) {
    vector<int> numDigits;
    int remainders = 0;
    if (num == 0) {
        numDigits.insert(numDigits.begin(), 0);
    }
    while (num != 0) {
        remainders = num % 10;
        num = num/10;
        numDigits.insert(numDigits.begin(), remainders);
    }
    if (numDigits.size() < 2) {
        numDigits.insert(numDigits.begin(), 0);
    }
    if (numDigits.size() < 3) {
        numDigits.insert(numDigits.begin(), 0);
    }
    /*for(int i = 0; i < numDigits.size(); i++) {
        cout << numDigits.at(i);
        if (i == numDigits.size()-1) {
            cout << endl;
        }
    }
    cout << numDigits.size() << endl;*/
    return numDigits;
}

vector<sf::Sprite> Tiles::FlagCounter(vector<int> nums, int height) {
    vector<sf::Sprite> flagNums;
    sf::Sprite temp;
    height = ((height-100)/32)*32;
    int x;
    for (int i = 0; i < nums.size(); i++) {
        if (nums.at(i) < 0) {
            temp = digits.at(10);
            temp.setPosition(9, height);
            flagNums.insert(flagNums.begin(), temp);
            for (int x = 0; x < nums.size(); x++) {
                nums.at(x) *= -1;
            }
        }
        x = (i * 21) + 32;
        temp = digits.at(nums.at(i));
        temp.setPosition(x, height);
        flagNums.push_back(temp);
    }
    return flagNums;
}

bool Tiles::FlagChecker(sf::Sprite flag) {
    for (int i = 0; i < otherHiddenTiles.size(); i++) {
        if (!otherHiddenTiles.at(i).hasBomb && otherHiddenTiles.at(i).hasFlag && otherHiddenTiles.at(i).tile.getPosition() == flag.getPosition()) {
            return true;
        }
    }
    return false;
}