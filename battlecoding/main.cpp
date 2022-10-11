/*******
 * Read input from cin
 * Use cout << ... to output your result to STDOUT.
 * Use cerr << ... to output debugging information to STDERR
 * ***/
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
// void findRightArea(std::vector<std::vector<int>>& mapWall, int height, int width, int currentX, int currentY, int& cnt, int& maxArea) {
//     if (currentX > width - 2 || currentY > height - 2) {
//         maxArea = cnt > maxArea ? cnt : maxArea;
//         return;
//     }
//     if (mapWall[currentY - 1][currentX - 1] == 1)
//         ++cnt;

//     findRightArea(mapWall, height, width, currentX + 1, currentY, cnt, maxArea);
//     findRightArea(mapWall, height, width, currentX, currentY + 1, cnt, maxArea);
// }
void question3() {
    std::string line;
    std::vector<std::vector<int>> mapWall;
    std::vector<int> lineConverted;
	while (std::getline(std::cin, line))
	{
        if (line == "") {
            break;
        }
        lineConverted.clear();
        for (auto c : line) {
            if (c == '-') {
                lineConverted.push_back(0);
            }
            else if (c == 'X') {
                lineConverted.push_back(1);
            }
        }
        if (!lineConverted.empty()) {
            mapWall.push_back(lineConverted);
        }
		/*Lisez les données ici et effectuez votre traitement ici */
	}

	/* Vous pouvez aussi effectuer votre traitement une fois que vous avez lu toutes les données.*/
    std::vector<int> result = {1, 1};
    int maxCnt = 0;
    for (int r = 0; r < mapWall.size() - 2; ++r) {
        for (int c = 0; c < mapWall[0].size() - 2; ++c) {
            int cnt = mapWall[r][c] + mapWall[r+1][c] + mapWall[r+2][c] + mapWall[r][c+1] + mapWall[r+1][c+1] + mapWall[r+2][c+1] +
                    mapWall[r][c+2] + mapWall[r+1][c+2] + mapWall[r+2][c+2];
            if (cnt > maxCnt) {
                maxCnt = cnt;
                result = {r + 1,c + 1};
            }
        }
    }
    std::cout<< result[0] << " " << result[1] << std::endl;

    // int cnt = 0;
    // int maxArea = 0;
    // findRightArea(mapWall, mapWall.size(), mapWall[0].size(), 1, 1, cnt, maxArea);
    // for (int c = 0; r < mapWall.size(); ++r) {
    //     for (int c = 0;)
    // }
}

// void question4() {
//     std::string line;
//     std::vector<std::vector<int>> mapWall;
// 	while (std::getline(std::cin, line))
// 	{
// 		/*Lisez les données ici et effectuez votre traitement ici */
//         if (line == "") {
//             break;
//         }
//         std::vector<int> lineConverted;
//         for (auto c : line) {
//             if (c == '-') {
//                 lineConverted.push_back(0);
//             }
//             else if (c == 'X') {
//                 lineConverted.push_back(1);
//             }
//         }
//         if (!lineConverted.empty()) {
//             mapWall.push_back(lineConverted);
//         }
// 	}
//     int minH, minL = 0;
//     int maxH = 0;
//     int maxL = 0;
//     bool firstApply = true;

//     for (int h = 0; mapWall.size(); ++h) {
//         for (int l = 0; mapWall[0].size(); ++l) {
//             if (mapWall[h][l] == 1) {
//                 if (firstApply) {
//                     minH = h;
//                     maxH = h;
//                     minL = l;
//                     maxL = l;
//                     firstApply = false;
//                 }

//             }
//         }
//     }
// }

struct Node {
    int key;
    std::vector<Node*> subNode;
};

Node* newNode(int value) {
    Node* n = new Node;
    n->key = value;
    return n;
}

std::map<int, std::vector<int>> pairToAdd;
std::map<int, bool> locationsMap;

bool insertValue(Node* root, int valueChild, int valueRoot) {
    bool canInsert = false;
    if (root->key == valueRoot) {
        Node* nnode = newNode(valueChild);
        root->subNode.push_back(nnode);
        return true;
    }
    else {
        for (auto node : root->subNode) {
            canInsert = insertValue(node, valueChild, valueRoot);
            if (canInsert) {
                return canInsert;
            }
        }
    }
    return canInsert;

}

void insertToTree(Node *root, int valueChild, int valueRoot) {
    insertValue(root, valueChild, valueRoot);
    for (auto child : pairToAdd[valueChild]) {
        insertToTree(root, child, valueChild);
    }
    pairToAdd[valueChild].clear();
}

void countSubNode(Node* root, int &currentCount) {
    for (auto node : root->subNode) {
        if ((node->subNode.size() == 1 && !locationsMap[root->key]) || (node->subNode.size() == 0)) {
            locationsMap[node->key] = true;
            ++currentCount;
        }
        else {
            locationsMap[node->key] = false;
        }
        countSubNode(node, currentCount);
    }
}

void showTree(Node* root) {
    std::cout << root->key << std::endl;
    for (auto node : root->subNode) {
        showTree(node);
    }
    std::cout << std::endl;
}
void question5() {
    std::string line;
    Node* root = newNode(0);
    int cnt = 0;
    int result = 0;
    int numberLine = 0;
	while (std::getline(std::cin, line))
	{
        if (line == "")
            break;
        if (cnt == 0)
            numberLine += std::stoi(line);
        // if (cnt > numberLine) 
        //     break;

        int numChild;
        int numRoot;
        std::string tmp;
        for (auto c : line) {
            if (c != ' ')  {
                tmp += c;
            }
            else if (c == ' ') {
                numChild = std::stoi(tmp);
                tmp = "";
            }
        }
        numRoot = std::stoi(tmp);
        if (!insertValue(root, numChild, numRoot)) {
            pairToAdd[numRoot].push_back(numChild);
        }
        else {
            if (pairToAdd.find(numChild) != pairToAdd.end()) {
                for (auto child : pairToAdd[numChild]) {
                    insertToTree(root, child, numChild);
                }
                pairToAdd[numChild].clear();
            }
        }
        ++cnt;
		/*Lisez les données ici et effectuez votre traitement ici */
	}
    Node* tmpNode = root;
    // showTree(root);
    if (root->subNode.size() <= 1) {
        locationsMap[root->key] = true;
        ++result;
    }
    countSubNode(root, result);
    std::cout << result << std::endl;
}

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void question6() {
    std::string line;  
    int cnt = 0;
    int height = 0;
    int length = 0;
    vector<vector<char>> mymap;
    vector<int> RowRequired;
    vector<int> ColRequired;
    map<int, vector<int>> starsRow;
    map<int, vector<int>> starsCol;
    
	while (std::getline(std::cin, line)) {
        if (line == "") {
            break;
        }
        if (cnt == 0) {
            auto listInput = split(line, " ");
            height = stoi(listInput[0]);
            length = stoi(listInput[1]);
        }
        else if (cnt <= height) {
            vector<char> lineconverted;
            for (int i = 0; i < line.size(); ++i) {
                lineconverted.push_back(line[i]);
                if (line[i] == '*') {
                    starsRow[cnt - 1].push_back(i);
                    starsCol[i].push_back(cnt - 1);
                }
            }
            mymap.push_back(lineconverted);
        }
        else if (cnt == height + 1) {
            vector<string> tmp = split(line, " ");
            for (auto &sub : tmp) {
                RowRequired.push_back(length - stoi(sub));
            }
        }
        else if (cnt == height + 2) {
            vector<string> tmp = split(line, " ");
            for (auto &sub : tmp) {
                ColRequired.push_back(height - stoi(sub));
            }
        }
        ++cnt;
    }

    for (int r = 0; r < height; ++r) {
        int rrquired = RowRequired[r];
        int cnt = starsRow[r].size();
        if (cnt == rrquired)
            continue;
        if (cnt < rrquired) {
            cout << "NON" << endl;
            return;
        }
        else {
            for (auto col : starsRow[r]) {
                if (ColRequired[col] < starsCol[col].size()) {
                    mymap[r][col] = '-';
                    starsCol[col].erase(remove(starsCol[col].begin(), starsCol[col].end(), r));
                    starsRow[r].erase(remove(starsRow[r].begin(), starsRow[r].end(), col));
                }
                else if (ColRequired[col] == starsCol[col].size())
                    continue;
                else {
                    cout << "NON" << endl;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < ColRequired.size(); ++i) {
        if (starsCol[i].size() != ColRequired[i]) {
            cout << "NON" << endl;
            return;
        }
    }
    for (int i = 0; i < RowRequired.size(); ++i) {
        if (starsRow[i].size() != RowRequired[i]) {
            cout << "NON" << endl;
            return;
        }
    }
    for (auto &r : mymap) {
        for (auto c : r) {
            cout << c;
        }
        cout << std::endl;
    }
}

void question7() {
    std::string line;
    long long valueCanva = 0;
	while (std::getline(std::cin, line))
	{
        if (line == "")
            break;
        valueCanva = stoll(line);
		/*Lisez les données ici et effectuez votre traitement ici */
	}
    // 2a + 2b + a*b
    long long l = 1;
    long long r = valueCanva / 2;
    int cnt = 0;
    while (l < r) {
        long long tmp = 2 * r + 2 * l + r*l;
        if (tmp == valueCanva) {
            cnt++;
            cout << l << " " << r << endl;
            r--;
            l++;
        }
        else if (tmp < valueCanva) {
            l++;
        }
        else {
            r--;
        }
    }
    std::cout << cnt << endl;
}

void question8() {
    string line;
    map<int, vector<int>> mapSalleCouloir;
    int cnt = 0;
    int result = -1;
    int numberSalle = 0;
    while (getline(std::cin, line)) {
        if (line == "")
            break;
        auto listParam = split(line, " ");
        if (cnt != 0) {
            mapSalleCouloir[stoi(listParam[0])].push_back(stoi(listParam[1]));
            mapSalleCouloir[stoi(listParam[1])].push_back(stoi(listParam[0]));
        }
        else if (cnt == 0) {
            numberSalle = stoi(listParam[0]);
        }
        cnt++;
    }
    if (numberSalle > mapSalleCouloir.size())
    {
        std::cout << 0 << std::endl;
        return;
    }

    for (auto &pair : mapSalleCouloir) {
        if (result < 0) {
            result = pair.second.size();
        }
        else if (pair.second.size() < result) {
            result = pair.second.size();
        }
    }
    std::cout << result << std::endl;
}

void findSample(vector<int> listPrices, int target, vector<vector<int>> &listSample, int currentIndex, vector<int> sample, int currentMoney) {
    sample.push_back(listPrices[currentIndex]);
    if (currentMoney + listPrices[currentIndex] == target) {
        listSample.push_back(sample);
        cout << "found sample" << endl;
        for (auto s : sample) {
            cout << s << " ";
        }
        cout << endl;
        return;
    }
    else if (currentIndex >= listPrices.size() || currentMoney + listPrices[currentIndex] > target) {
        return;
    }

    for (int i = currentIndex + 1; i < listPrices.size(); ++i) {
        findSample(listPrices, target, listSample, i, sample, currentMoney + listPrices[currentIndex]);
    }
}
void question9() {
    string line;
    int totalMoney = 0;
    int numberProduit = 0;
    vector<int> listPrices;
    int cnt = 0;
    while (getline(cin, line)) {
        if (line == "")
            break;
        if (cnt == 0) {
            totalMoney = stoi(line);
        }
        else if (cnt == 1) {
            numberProduit = stoi(line);
        }
        else {
            auto listData = split(line, " ");
            for (auto &substr : listData) {
                listPrices.push_back(stoi(substr));
            }
        }
        cnt++;
    }

    sort(listPrices.begin(), listPrices.end());
    vector<vector<int>> listSample;
    for (int i = 0; i < listPrices.size(); ++i) {
        if (i == 0 || i > 0 && listPrices[i - 1] != listPrices[i]) {
            vector<int> sample;
            findSample(listPrices, totalMoney, listSample, i, sample, 0);
        }
    }

    if (listSample.size() == 0) {
        cout << "NON" << endl;
    }
    
    for (int i = 0; i < listSample.size() - 1; ++i) {
        for (int j = i + 1; j < listSample.size(); ++j) {
            vector<int> tmp = listSample[i];
            for (int s : listSample[j]) {
                tmp.push_back(s);
            }
            sort(tmp.begin(), tmp.end());
            if (tmp.size() > listPrices.size()) {
                cout << "OUI" << endl;
                return;
            }
            for (int k = 0; k < tmp.size(); ++k) {
                if (tmp[k] != listPrices[k]) {
                    cout << "OUI" << endl;
                    return;
                }
            }
        }
    }
    cout << "NON" << endl;

}

void question10() {
    string line;
    int cnt = 0;
    vector<int> listData;
    int numberEntier = 0;
    while (getline(cin, line)) {
        if (line == "")
            break;
        if (cnt == 0) {
            numberEntier = stoi(line);
        }
        else {
            auto tmp = split(line, " ");
            for (auto &str : tmp) {
                listData.push_back(stoi(str));
            }
        }
        ++cnt;
    }
    sort(listData.begin(), listData.end());
    int min = listData[2] - listData[0];

    vector<int> result = {listData[0], listData[1], listData[2]};
    for (int i = 1; i < listData.size() - 2; ++i) {
        if (min > listData[i + 2] - listData[i]) {
            result = {listData[i], listData[i + 1], listData[i + 2]};
            min = listData[i + 2] - listData[i];
        }
    }
    for (auto number : result) {
        cout << number << " ";
    }
}

bool compareWord(map<char, int> mapNumberChar, string wordDict) {
    for (auto c : wordDict) {
        if (mapNumberChar[c] > 0) {
            mapNumberChar[c]--;
            if (mapNumberChar[c] == 0) {
                mapNumberChar.erase(c);
            }
        }
        else
            return false;
    }
    if (mapNumberChar.size() > 0)
        return false;
    return true;
}
void question11() {
    string line;
    int cnt = 0;
    string baseWord;
    vector<string> wordsFound;
    map<char, int> mapNumberCharBaseWord;
    while (getline(cin, line)) {
        if (line == "")
            break;
        if (cnt == 0) {
            sort(line.begin(), line.end());
            baseWord = line;
            for (auto c : baseWord) {
                mapNumberCharBaseWord[c]++;
            }
        }
        else if (cnt > 1) {
            if (baseWord.size() != line.size()) {
                continue;
            }
            if (compareWord(mapNumberCharBaseWord, line)) {
                wordsFound.push_back(line);
            }
        } 
        ++cnt;
    }

    for (auto &str : wordsFound) {
        cout << str << endl;
    }
}
int main() {
    question11();
    // int a, b;
    // std::cin >> a >> b;
    // std::cout << a << " " << b << std::endl;
    
    // vector<int> test = {1,2,5,3,4,5,5,6};
    // cout << test.size() << endl;
    // test.erase(std::remove_if(test.begin(), test.end(), [](int i) {
    //     return i == 5;
    // }), test.end());
    // for (auto i : test) {
    //     cout << i << " ";
    // }

    return 0;
}