/*	Implementation of Hash Table with Linear and Quadratic Probing
Applications of Hashing:
- Fast data retrieval (symbol tables, databases)
- Caching and indexing
- File systems and compiler symbol tables
*/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

// --- LINEAR PROBING --
int linearprobe(int data[], int m, int hashTable[][2]) {
    int i, j, key, hashIndex;
    int linearcollision = 0;

    // Initialize hash table with -1 indicating empty slots
    for(i = 0; i < SIZE; i++) {
        hashTable[i][0] = -1;
    }

    // Insert keys
    for(i = 0; i < m; i++) {
        key = data[i];
        hashIndex = key % m;

        if(hashTable[hashIndex][0] == -1) {
            hashTable[hashIndex][1] = key;
            hashTable[hashIndex][0] = 0;
        } else {
            for(j = 1; j < m; j++) {
                linearcollision++;
                if(hashTable[(hashIndex + j) % m][0] == -1) {
                    hashTable[(hashIndex + j) % m][1] = key;
                    hashTable[(hashIndex + j) % m][0] = 0;
                    printf("Collision handled using Linear Probing for key %d → Index %d\n", key, (hashIndex + j) % m);
                    break;
                }
            }
        }
    }
    return linearcollision;
}

// ------ QUADRATIC PROBING ----
int quadraticprobe(int data[], int m, int hashTable[][2]) {
    int i, j, key, hashIndex;
    int quadcollision = 0;

    // Initialize hash table
    for(i = 0; i < SIZE; i++) {
        hashTable[i][0] = -1;
    }

    // Insert keys
    for(i = 0; i < m; i++) {
        key = data[i];
        hashIndex = key % m;

        if(hashTable[hashIndex][0] == -1) {
            hashTable[hashIndex][1] = key;
            hashTable[hashIndex][0] = 0;
        } else {
            for(j = 1; j < m; j++) {
                quadcollision++;
                int newIndex = (hashIndex + j*j) % m;
                if(hashTable[newIndex][0] == -1) {
                    hashTable[newIndex][1] = key;
                    hashTable[newIndex][0] = 0;
                    printf("Collision handled using Quadratic Probing for key %d → Index %d\n", key, newIndex);
                    break;
                }
            }
        }
    }
    return quadcollision;
}

// ------ SEARCH FUNCTION ------
void search(int key, int m, int hashTable[][2]) {
    int hashIndex, i, flag = 1;
    hashIndex = key % m;

    if(hashTable[hashIndex][1] == key) {
        printf("\nKey %d is present at index %d", key, hashIndex);
        flag = 0;
    } else {
        for(i = 1; i < m; i++) {
            if(hashTable[(hashIndex + i) % m][1] == key) {
                printf("\nKey %d is present at index %d", key, (hashIndex + i) % m);
                flag = 0;
                break;
            }
        }
    }
    if(flag)
        printf("\nKey %d does not exist in the table.", key);
}

// ------ MAIN FUNCTION ----------
int main() {
    int m, i, key, choice, colli;
    int hashTable[SIZE][2];
    int data[SIZE];

    while(1) {
        printf("\n\n\t\tMENU");
        printf("\n1. Insert Data");
        printf("\n2. Linear Probing");
        printf("\n3. Quadratic Probing");
        printf("\n4. Search Key");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter size of hash table: ");
                scanf("%d", &m);
                for(i = 0; i < m; i++) {
                    printf("Enter key %d to insert: ", i + 1);
                    scanf("%d", &data[i]);
                }
                break;

            case 2:
                colli = linearprobe(data, m, hashTable);
                printf("\nHash Table using Linear Probing:\n");
                for(i = 0; i < m; i++) {
                    if(hashTable[i][0] != -1)
                        printf(" %d : [%d]\n", i, hashTable[i][1]);
                    else
                        printf(" %d : [ ]\n", i);
                }
                printf("\nTotal Collisions: %d\n", colli);
                break;

            case 3:
                colli = quadraticprobe(data, m, hashTable);
                printf("\nHash Table using Quadratic Probing:\n");
                for(i = 0; i < m; i++) {
                    if(hashTable[i][0] != -1)
                        printf(" %d : [%d]\n", i, hashTable[i][1]);
                    else
                        printf(" %d : [ ]\n", i);
                }
                printf("\nTotal Collisions: %d\n", colli);
                break;

            case 4:
                printf("\nEnter Key to Search: ");
                scanf("%d", &key);
                search(key, m, hashTable);
                break;

            case 5:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}

/*
Conclusion:
From this experiment, we learned:
1) How to create a hash table and choose a hash function (h(k) = k % m).
2) How to resolve collisions using Linear and Quadratic Probing techniques.
3) That Linear Probing is simple but can lead to primary clustering.
4) Quadratic Probing reduces clustering by spreading keys more evenly.
5) Hashing provides very efficient data storage and retrieval — 
   average O(1) time complexity for search and insert operations.
*/
