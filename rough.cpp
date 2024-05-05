#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;
struct KeyValuePair
{
    string key;
    int value;
    KeyValuePair(string k , int v):key(k) , value(v) {}
};

class HashTable
{
    vector<list<KeyValuePair>>table;
    int capacity;
     int hashFUnction(const string& key)
     {
        int hash=0;
        for (char ch :key)
        {
            hash += ch;

        }
        return hash % capacity;
     }
    public :

    HashTable(int size):capacity(size)

   {
    table.resize(capacity);
   }
   void insert(const string& key , int value)
   
   {
    int index=hashFUnction(key);
    table[index].push_back(KeyValuePair(key , value));
    
   }
}