 ///
 /// @file    LadderTest.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-08 09:50:47
 ///
 
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
	//在实现函数的过程中，一个函数的长度最多不要超过50行
	int ladderLength(const string & begWord, 
		const string & endWord,
		const vector<string> & wordList)
	{
		int cnt = count(wordList.begin(), wordList.end(), endWord);
		if(cnt == 0)
			return 0;
		
		unordered_set<string> words(wordList.begin(), wordList.end());
		unordered_set<string> visited;
		unordered_map<string, string> paths;

		queue<string> currentQue;
		queue<string> nextQue;//下一层的节点
		int len = 1;
		currentQue.push(begWord);
		visited.insert(begWord);
		while(!currentQue.empty()) 
		{
			while(!currentQue.empty()) {
				string word = currentQue.front();
				currentQue.pop();
				//求取下一层节点
				vector<string> nextStatus;
				getNextStatus(word, words, visited, nextStatus);
				for(auto & status : nextStatus) {
					nextQue.push(status);
					paths[status] = word;
					if(status == endWord) {
						printPaths(status, paths);	
						return  len + 1;
					}
					visited.insert(status);
				}
			}
			++len;
			swap(currentQue, nextQue);
		}
		return 0;
	}

	//vector<string> getNextStatus(const string & word,
	void getNextStatus(const string & word,
		const unordered_set<string> & words,
		const unordered_set<string> & visited,
		vector<string> & result) //作为输出
	{
		for(auto & candicate : words) {
			if(isValid(word, candicate)) {
				int cnt = visited.count(candicate);
				if(cnt == 0)
					result.push_back(candicate);
			}
		}
	}

	bool isValid(const string & word, const string & candicate) {
		int cnt = 0;
		for(size_t idx = 0; idx != word.size(); ++idx) {
			if(word[idx] != candicate[idx])
				++cnt;
		}
		return cnt == 1;
	}

	void printPaths(const string & end,
		const unordered_map<string, string> & paths) 
	{
		auto it = paths.find(end);
		if(it == paths.end()) {
			cout << end << endl;
			return;
		} else {
			cout << end << " <- ";
			printPaths(it->second, paths);
		}
	}
};
 
int main(void)
{
	vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog" };
	string begWord = "hit";
	string endWord = "cog";

	cout << Solution().ladderLength(begWord, endWord, wordList) << endl;

	return 0;
}
