#include <iostream>
#include <map>
#include <string>

using namespace std;

class TrieNode {
public:
    map<char, TrieNode*> children;  // 자식 노드
    bool isEndOfWord;               // 단어 끝 여부
    int subtreeWordCount;           // 현재 노드 이하의 단어 개수

    TrieNode() : isEndOfWord(false), subtreeWordCount(0) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // 단어 삽입
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->subtreeWordCount++;  // 하위 노드 단어 개수 증가
        }
        node->isEndOfWord = true;
    }

    // 단어 삭제
    void erase(const string& word) {
        if (!find(word)) return;  // 단어가 없으면 삭제하지 않음
        TrieNode* node = root;
        for (char c : word) {
            TrieNode* child = node->children[c];
            child->subtreeWordCount--;  // 하위 노드 단어 개수 감소
            if (child->subtreeWordCount == 0) {
                // 하위에 더 이상 단어가 없으면 노드 삭제
                delete child;
                node->children.erase(c);
                return;
            }
            node = child;
        }
        node->isEndOfWord = false;
    }

    // 단어 존재 여부 확인
    bool find(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) return false;
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // 사전순으로 n번째 단어 찾기
    string findNthWord(int n) {
        TrieNode* node = root;
        string result = "";
        while (n > 0) {
            for (auto& child : node->children) {
                if (child.second->subtreeWordCount >= n) {
                    result += child.first;
                    node = child.second;
                    if (node->isEndOfWord) n--;
                    break;
                } else {
                    n -= child.second->subtreeWordCount;
                }
            }
        }
        return result;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("banana");
    trie.insert("grape");
    trie.insert("orange");
    trie.insert("kiwi");

    cout << "3번째 사전순 단어: " << trie.findNthWord(3) << endl;

    return 0;
}
