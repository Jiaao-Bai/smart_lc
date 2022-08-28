/*
2020.5.23
2020.5.24
typedef pair<int, int> tKeyValuePair;
typedef list<tKeyValuePair> tCacheList;
typedef unordered_map<int, tCacheList::iterator> tHashTable;

class LRUCache {
private:
    int cap = 0, capInUsed = 0;
    tCacheList cacheList;
    tHashTable hashTable;
    
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(cap<=0){
            return -1;
        }
        tHashTable::iterator i = hashTable.find(key);
        int res;
        tKeyValuePair pairForMove(key, 0);
        if(i==hashTable.end()){
            return -1;
        }else{
            res = i->second->second;
            pairForMove.second = res;
            cacheList.push_front(pairForMove);
            cacheList.erase(i->second);
            i->second = cacheList.begin();
            return res;
        }
        
    }
    
    void put(int key, int value) {
        if(cap<=0){
            return;
        }
        tCacheList::iterator iList;
        tHashTable::iterator iHash = hashTable.find(key);
        tKeyValuePair pairForMove(key, value);
        tHashTable::iterator iDeleteInHash;

        int keyToDelelt;

        if(iHash==hashTable.end()){
            //not found
            if(capInUsed<cap){
                capInUsed++;
                cacheList.push_front(pairForMove);
                iList = cacheList.begin();
                pair<int, tCacheList::iterator> val(key, iList);
                //hashTable.insert((pair<int, tCacheList::iterator>)(key,--iList));
                hashTable.insert(val);
                return;
            }else{
                //insert in head
                cacheList.push_front(pairForMove);
                iList = cacheList.end();
                iList--;
                keyToDelelt = iList->first;
                iDeleteInHash = hashTable.find(keyToDelelt);
                if(iDeleteInHash==hashTable.end()){
                    //unexpected
                    return;
                }else{
                    hashTable.erase(iDeleteInHash);
                    pair<int, tCacheList::iterator> val2(key, cacheList.begin());
                    //hashTable.insert(key, cacheList.begin());
                    hashTable.insert(val2);
                }
                cacheList.erase(iList);
                return;
            }
        }else{
            if(iHash->second==cacheList.begin()){
                iHash->second->second = value;
                return;
            }else{
                pairForMove = *(iHash->second);
                cacheList.erase(iHash->second);
                pairForMove.second=value;
                cacheList.push_front(pairForMove);
                iHash->second = cacheList.begin();
                return;
            }
        }
    }
};
*/

//2021.12.18
//有bug
class LRUCache {
private:
    struct Value{
        int value = -1;
        list<int>::const_iterator key_it;//const_iterator
    };

    int cap_ = 0;
    //vector<Value> vec_(10001); //用这么大的数组感觉失去了cache的意义
    vector<Value> vec_ = vector<Value>(10001); //用这么大的数组感觉失去了cache的意义
    list<int> list_;
    
public:
    LRUCache(int capacity) {
        cap_ = capacity;
    }
    
    inline void refresh(int key){ //refresh key在list的位置
        list_.erase(vec_[key].key_it);
        list_.push_back(key);
        vec_[key].key_it = list_.cbegin();
    }

    inline void new_key(int key, int value){
        vec_[key].value = value;
        list_.push_back(key);
        vec_[key].key_it = list_.cbegin();
    }

    int get(int key) {
        if(vec_[key].value!=-1){
            refresh(key);
        }
        return vec_[key].value;
    }
    
    void put(int key, int value) {
        if(vec_[key].value!=-1){
            vec_[key].value = value;
            refresh(key);
        }else{
            if(list_.size()<cap_){
                new_key(key, value);
            }else{
                vec_[list_.front()].value = -1;
                list_.erase(vec_[list_.front()].key_it);
                new_key(key, value);
            }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
