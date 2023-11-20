#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 23

typedef struct KeyValue {
    char *key;
    char *value;
    bool isDeleted;
} KeyValue;

typedef struct {
    KeyValue **array;
    int size;
    float load_factor;
    int num_keys;
    int num_occupied_indices;
    int num_ops;
} HashTable;

KeyValue *createKeyValue(char *key, char *value) {
    KeyValue *newKeyValue = (KeyValue *)malloc(sizeof(KeyValue));
    if (newKeyValue != NULL) {
        newKeyValue->key = strdup(key);
        newKeyValue->value = strdup(value);
        newKeyValue->isDeleted = false;
    }
    return newKeyValue;
}

HashTable *createHashTable() {
    HashTable *newTable = (HashTable *)malloc(sizeof(HashTable));
    newTable->array = (KeyValue **)malloc(TABLE_SIZE * sizeof(KeyValue *));
    for (int i = 0; i < TABLE_SIZE; i++)
        newTable->array[i] = NULL;

    newTable->size = TABLE_SIZE;
    newTable->load_factor = 0;
    newTable->num_keys = 0;
    newTable->num_occupied_indices = 0;
    newTable->num_ops = 0;
    return newTable;
}

int key_to_int(char *key) {
    int sum = 0;
    while (*key) {
        sum += *key;
        key++;
    }
    return sum;
}

int hash_function(char *key, int size) {
    return key_to_int(key) % size;
}

int insert_key_value(HashTable *ht, char *key, char *value) {
    if (ht == NULL || key == NULL || value == NULL)
        return -1;

    // Check load factor and resize if necessary
    if ((float)(ht->num_occupied_indices + 1) / ht->size > ht->load_factor) {
        // Resize and rehash
        // (omitted for simplicity)
    }

    int index = hash_function(key, ht->size);
    int original_index = index;
    int i = 1; // Quadratic probing counter

    // Quadratic probing to handle collisions
    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted)
            return -1; // Key already exists, insertion failed

        index = (original_index + i * i) % ht->size;
        i++;

        // Check if we have traversed the entire table
        if (index == original_index)
            return -1; // Table is full, insertion failed
    }

    // Insert the key-value pair
    ht->array[index] = createKeyValue(key, value);
    ht->num_keys++;
    ht->num_occupied_indices++;
    ht->num_ops++;

    return index;
}

char *search_key(HashTable *ht, char *key) {
    if (ht == NULL || key == NULL)
        return NULL;

    int index = hash_function(key, ht->size);
    int original_index = index;
    int i = 1; // Quadratic probing counter

    // Quadratic probing to handle collisions
    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted)
            return ht->array[index]->value;

        index = (original_index + i * i) % ht->size;
        i++;

        // Check if we have traversed the entire table
        if (index == original_index)
            break;
    }

    return NULL; // Key not found
}

int delete_key(HashTable *ht, char *key) {
    if (ht == NULL || key == NULL)
        return -1;

    int index = hash_function(key, ht->size);
    int original_index = index;

    // Linear probing to handle collisions
    while (ht->array[index] != NULL) {
        if (strcmp(ht->array[index]->key, key) == 0 && !ht->array[index]->isDeleted) {
            // Mark the entry as deleted
            ht->array[index]->isDeleted = true;
            ht->num_keys--;
            ht->num_ops++;
            return index;
        }

        index = (index + 1) % ht->size;

        // Check if we have traversed the entire table
        if (index == original_index)
            break;
    }

    return -1; // Key not found
}

int get_load_factor(HashTable *ht) {
    if (ht == NULL || ht->size == 0)
        return -1;

    return (float)ht->num_keys / ht->size;
}

int get_avg_probes(HashTable *ht) {
    if (ht == NULL || ht->num_ops == 0)
        return -1;

    return ht->num_ops / ht->num_keys;
}

void display(HashTable *ht) {
    if (ht == NULL)
        return;

    printf("Hash Table:\n");
    for (int i = 0; i < ht->size; i++) {
        printf("[%d]: ", i);
        if (ht->array[i] != NULL) {
            printf("(%s, %s)", ht->array[i]->key, ht->array[i]->value);
        }
        printf("\n");
    }
}

int main() {
    HashTable *ht = createHashTable();

    // Insert key-value pairs
    insert_key_value(ht, "first name", "John");
    insert_key_value(ht, "last name", "Doe");
    insert_key_value(ht, "uid", "12345");
    insert_key_value(ht, "sport", "Basketball");
    insert_key_value(ht, "food", "Pizza");
    insert_key_value(ht, "holiday", "Hawaii");
    insert_key_value(ht, "role_model", "Albert Einstein");
    insert_key_value(ht, "subject", "Computer Science");
    insert_key_value(ht, "song", "Bohemian Rhapsody");
    insert_key_value(ht, "movie", "Inception");
    insert_key_value(ht, "colour", "Blue");
    insert_key_value(ht, "book", "1984");

    // Test search and delete operations
    char *search_result = search_key(ht, "sport");
    if (search_result != NULL) {
        printf("Search Result for 'sport': %s\n", search_result);
    } else {
        printf("Key 'sport' not found.\n");
    }

    int delete_result = delete_key(ht, "holiday");
    if (delete_result != -1) {
        printf("Deleted key 'holiday' at index %d.\n", delete_result);
    } else {
        printf("Key 'holiday' not found for deletion.\n");
    }

    // Display the hash table
    display(ht);

    // Clean up memory
    // (omitted for simplicity)

    return 0;
}
