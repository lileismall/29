 ///
 /// @file    LRUCache.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-06 10:09:43
 ///
 
#include <iostream>
#include <list>
#include <unordered_map>
using std::cout;
using std::endl;
using std::list;
using std::unordered_map;

class LRUCache
{
	struct CacheNode
	{
		CacheNode(int k, int v)
		: key(k)
		, value(v)
		{}

		int key;
		int value;
	};
public:
	LRUCache(int capacity)
	: _capacity(capacity)
	{}

	void put(int key, int value)
	{
		auto it = _keys.find(key);//O(1)
		if(it == _keys.end()) {
			if(_nodes.size() == _capacity) {
				//淘汰元素
				int deleteKey = _nodes.back().key;
				_nodes.pop_back();
				_keys.erase(deleteKey);
			}
			
			CacheNode node(key, value);
			_nodes.push_front(node);
			_keys.insert(make_pair(key, _nodes.begin()));
			//_keys[key] = _nodes.begin();
		} else {
			// 更新值
			it->second->value = value;
			_nodes.splice(_nodes.begin(), _nodes, it->second);
			_keys[key] = _nodes.begin();
		}
	}

	int get(int key)
	{
		auto it = _keys.find(key);
		if(it == _keys.end()) {
			return -1;
		} else {
			int ret = it->second->value;
			_nodes.splice(_nodes.begin(), _nodes, it->second);
			_keys[key] = _nodes.begin();
			return ret;
		}
	}
	
private:
	int _capacity;
	list<CacheNode> _nodes;
	unordered_map<int, list<CacheNode>::iterator> _keys;
};
 
int main(void)
{
	LRUCache cache(2);
	cache.put(1, 1);
	cout << "get(1) = " << cache.get(1) << endl;
	cache.put(3, 3);
	cout << "get(2) = " << cache.get(2) << endl;
	cache.put(4, 4);
	cout << "get(1) = " << cache.get(1) << endl;
	cout << "get(3) = " << cache.get(3) << endl;
	cout << "get(4) = " << cache.get(4) << endl;
	cache.put(5, 5);
	cout << "get(3) = " << cache.get(3) << endl;
	

 
}
