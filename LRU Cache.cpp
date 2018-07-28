vector<int> v;
map<int, int> mp;
int cap;
LRUCache::LRUCache(int capacity)
{
    cap = capacity;
    v.clear();
    mp.clear();
}

int LRUCache::get(int key)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), key);
    if(iter != v.end())
    {
        int cp = *iter;
        v.erase(iter);
        v.push_back(cp);
        return mp[cp];
    }
    else
    {
        return -1;
    }
}

void LRUCache::set(int key, int value)
{
    vector<int>::iterator iter = find(v.begin(), v.end(), key);
    if(iter == v.end())
    {
        if(v.size() == cap)
        {
            vector<int>::iterator jter = v.begin();
            v.erase(jter);
        }
        v.push_back(key);
        mp[key] = value;
    }
    else
    {
        if(mp[key] != value)
        {
            mp[key] = value;
        }
        int cp = *iter;
        v.erase(iter);
        v.push_back(cp);
    }
    return;
}
