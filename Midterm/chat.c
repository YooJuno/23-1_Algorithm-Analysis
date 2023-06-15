#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int num_chars = 56; // 56 = 90-65+1+122-97+1+4
char charFreq[num_chars];
char code[num_chars][100]; // [index][char]??

int Char2Index(char letter);
char Index2Char(int index);

struct zNode {
    struct zNode *left;
    struct zNode *right;
    char letter;
    int freq;
};

struct zNode *newZNode(char letter, int freq) {
    struct zNode *temp = (struct zNode *)malloc(sizeof(struct zNode));
    temp->left = NULL;
    temp->right = NULL;
    temp->letter = letter;
    temp->freq = freq;
    return temp;
}

struct QNode {
  struct zNode *key;
  struct QNode *next;
};

struct QNode *newQNode(struct zNode *z) {
    struct QNode *temp = (struct QNode *)malloc(sizeof(struct QNode));
    temp->key = z;
    temp->next = NULL;
    return temp;
}

struct Queue {
    struct QNode *front, *rear;
};

void Insert(struct Queue *Q, struct zNode *z);
struct zNode *ExtractMin(struct Queue *Q);
int CheckQueueLen(struct Queue *Q);

struct zNode *HuffmanCode(char *text);
void GetHuffmanCode(struct zNode *codeTree, char *so_far);
void PrintHuffmanCode(struct zNode *codeTree);

int main(void) {
    char text[] =
        "HGU CSEE is a higher educational institution that cultivates excellent "
        "and honest professionals who will serve God and people by playing a "
        "role as salt and light in the darkening world. A CSEE student should "
        "strive to develop expertise in IT-related fields based on the "
        "unshakable integrity of the Christian spirit exemplified by love and "
        "righteousness. This guideline aims to clarify the standard of honesty, "
        "sincerity and responsibility the students should keep in order that "
        "they may overcome temptations they encounter during their studies and "
        "develop into trustworthy and capable professionals.";
    printf("%s\n", text);
    printf("The length of the given text is %ld\n", strlen(text));

    printf("\n[HuffmanCode function]\n\n");
    struct zNode *codeTree = HuffmanCode(text);

    // print your optimal Huffman code
    printf("\n[PrintHuffmanCode function]\n\n");
    PrintHuffmanCode(codeTree);

    int sum = 0;
    for (int i = 0; i < num_chars; i++) {
        sum += charFreq[i] * strlen(code[i]);
    }
    printf("Total number of bits required for the given text: %d\n", sum);

    return 0;
}

void GetHuffmanCode(struct zNode *codeTree, char *so_far) {
    if (codeTree == NULL)
        return;

    if (codeTree->left == NULL && codeTree->right == NULL) {
        int index = Char2Index(codeTree->letter);
        strcpy(code[index], so_far);
        return;
    }

    char temp[100] = "";
    strcpy(temp, so_far);
    strcat(temp, "0");
    GetHuffmanCode(codeTree->left, temp);

    strcpy(temp, so_far);
    strcat(temp, "1");
    
    GetHuffmanCode(codeTree->right, temp);
}

void PrintHuffmanCode(struct zNode *codeTree) {
    for (int i = 0; i < num_chars; i++)
        strcpy(code[i], "");

    char so_far[100] = "";
    GetHuffmanCode(codeTree, so_far);

    for (int i = 0; i < num_chars; i++) {
        if (charFreq[i] != 0) {
            printf("%c: %s\n", Index2Char(i), code[i]);
        }
    }
}

struct zNode *HuffmanCode(char *text) {
    // character count initialization
    for (int i = 0; i < num_chars; i++)
        charFreq[i] = 0;

    // character count
    int textLen = strlen(text);
    for (int i = 0; i < textLen; i++) {
        charFreq[Char2Index(text[i])]++;
    }

    // character count print
    int sum = 0;
    for (int i=0; i<num_chars; i++) {
        if (charFreq[i] != 0)
            printf("%c: %d\n", Index2Char(i), charFreq[i]);
        sum += charFreq[i];
    }
    printf("%d\n", sum);

    // initialize Queue
    struct Queue Q;
    Q.front = NULL;
    Q.rear = NULL;

    // allocate zNodes for all letters with freq != 0
    int num_total_distinct_chars = 0;
    for (int i = 0; i < num_chars; i++) {
        if (charFreq[i] != 0) {
            struct zNode *z = newZNode(Index2Char(i), charFreq[i]);
            Insert(&Q, z);
            num_total_distinct_chars++;
        }
    }
    printf("The number of total distinct characters: %d\n",
            num_total_distinct_chars);

    for (int i = 0; i < num_total_distinct_chars - 1; i++) {
        struct zNode *z = newZNode(0x00, 0); // 0x00 : NULL
        z->left = ExtractMin(&Q);
        z->right = ExtractMin(&Q);
        z->freq = z->left->freq + z->right->freq;
        Insert(&Q, z);
    }

    return ExtractMin(&Q);
}


void Insert(struct Queue *Q, struct zNode *z) {
    struct QNode *temp = newQNode(z);
    if (Q->rear == NULL) {
        Q->front = temp;
        Q->rear  = temp;
        return;
    }

    struct QNode *current = Q->front;
    struct QNode *prev = NULL;
    while (current != NULL && current->key->freq < z->freq) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        temp->next = Q->front;
        Q->front = temp;
    } else if (current == NULL) {
        Q->rear->next = temp;
        Q->rear = temp;
    } else {
        temp->next = prev->next;
        prev->next = temp;
    }
}

struct zNode *ExtractMin(struct Queue *Q) {
    if (Q->front == NULL)
        return NULL;

    struct QNode *temp = Q->front;
    Q->front = temp->next;

    if (Q->front == NULL)
        Q->rear = NULL;

    struct zNode *minNode = temp->key;
    free(temp);

    return minNode;
}

// ... (rest of the code remains the same) ...







int CheckQueueLen(struct Queue *Q) {
    int i = 0;
    if (Q->rear == NULL)
        return i;
    else {
        struct QNode *curr = Q->front;
        i++;
        while (curr->next != NULL) {
            curr = curr->next;
            i++;
        }
        return i;
    }
}

int Char2Index(char letter) {
  // ASCII number (decimal)
  // A: 65, Z: 90,
  // a: 97, z: 122,
  // Space: 32, ,: 44, -: 45, .: 46

  // Index
  // A: 0
  // Z: 25
  // a: 26
  // z: 51
  // Space: 52
  // ,: 53
  // -: 54
  // .: 55

    if (((int)letter >= 65) && ((int)letter <= 90))
        return (int)letter - 65;
    if (((int)letter >= 97) && ((int)letter <= 122))
        return (int)letter - 97 + 26;

    if ((int)letter == 32)
        return 52;
    if ((int)letter == 44)
        return 53;
    if ((int)letter == 45)
        return 54;
    if ((int)letter == 46)
        return 55;

  return -1;
}

char Index2Char(int index) {
    if ((index >= 0) && (index <= 25))
        return index + 65;
    if ((index >= 26) && (index <= 51))
        return index - 26 + 97;
    if (index == 52)
        return 32;
    if (index == 53)
        return 44;
    if (index == 54)
        return 45;
    if (index == 55)
        return 46;

    return 0;
}
