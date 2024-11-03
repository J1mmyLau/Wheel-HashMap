#ifndef HASHMAP_H
#define HASHMAP_H
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define newEntry() (Entry)malloc(sizeof(struct entry))
#define newEntryList(length) (Entry)malloc(length * sizeof(struct entry))
typedef struct entry{
    void *value;
    void *key;
    struct entry *next;
}* Entry;
typedef struct hashMap *HashMap;
#define newHashMap() (HashMap)malloc(sizeof(struct hashMap))
typedef int(*HashCode)(HashMap, void *key);
typedef bool(*Equal)(void *key1,void *key2);
typedef void(*Put)(HashMap hashMap,void *key,void *value);
typedef void*(*Get)(HashMap hashMap,void *key);
typedef bool(*Remove)(HashMap hashMap,void *key);
typedef void(*Clear)(HashMap hashMap);
typedef bool(*Exists)(HashMap hashMap,void *key);
typedef struct hashMap{
    int size;
    int listSize;
    HashCode hashCode;
    Equal equal;
    Entry list;
    Put put;
    Get get;
    Clear clear; 
    Remove remove;
    Exists exists;
    bool autoAssign;
}* HashMap;
int defaultHashCode(HashMap hashMap,void *key);
bool defaultEqual(void *key1,void *key2);
void defaultPut(HashMap hashMap,void *key,void *value);
void* defaultGet(HashMap hashMap,void *key);
bool defaultRemove(HashMap hashMap,void *key);
bool defaultExists(HashMap hashMap,void *key);
HashMap createHashMap(HashCode hashCode,Equal equal);
void resetHashMap(HashMap hashMap,int listSize);
typedef struct hashMapIterator {
    Entry entry;
    int count;
    int hashCode;
    HashMap hashMap;
}* HashMapIterator;
#define newHashMapIterator() (HashMapIterator)malloc(sizeof(struct hashMapIterator))
HashMapIterator createHashMapIterator(HashMap hashMap);
bool hasNextHashMapIterator(HashMapIterator iterator);
HashMapIterator nextHashMapIterator(HashMapIterator iterator);
void freeHashMapIterator(HashMapIterator *iterator);
#endif