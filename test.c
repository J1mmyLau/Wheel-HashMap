#include<stdio.h>
#include "HashMap.h"
int main(void){
    HashMap map = createHashMap(NULL, NULL);
    map->put(map,"asdfasdf", "asdfasdfds");
    map->put(map, "sasdasd", "asdfasdfds");
    map->put(map, "asdhfgh", "asdfasdfds");
    map->put(map, "4545", "asdfasdfds");
    map->put(map,"4545","sdfsadefwef");
    map->put(map, "asdfaasdasdsdf", "asdfasdfds");
    map->put(map, "asdasg", "asdfasdfds");
    map->put(map, "qweqeqwe", "asdfasdfds");
    printf("key: 4545, exists: %s\n", map->exists(map, "4545") ? "true" : "false");
    printf("4545: %s\n", map->get(map, "4545"));
    printf("remove 4545 %s\n", map->remove(map, "4545") ? "true" : "false");
    printf("remove 4545 %s\n", map->remove(map, "4545") ? "true" : "false");
    printf("key: 4545, exists: %s\n", map->exists(map, "4545") ? "true" : "false");

    HashMapIterator iterator = createHashMapIterator(map);
    while (hasNextHashMapIterator(iterator)) {
        iterator = nextHashMapIterator(iterator);
        printf("{ key: %s, value: %s, hashcode: %d }\n",
            (char *)iterator->entry->key, (char *)iterator->entry->value, iterator->hashCode);
    }
    map->clear(map);
    freeHashMapIterator(&iterator);

    return 0;
}