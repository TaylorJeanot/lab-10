#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*In this lab, you are going to implement a trie data structure to count the number of occurrences of a word if it exists in the dictionary. Words will always be in lowercase.
Please apply the following signatures:*/

//void insert(struct Trie *ppTrie, char *word);
//int numberOfOccurances(struct Trie *pTrie, char *word);
//struct Trie *deallocateTrie(struct Trie *pTrie);


struct Trie {

    struct Trie *numChildren[26];
    int numWords;

};

void insert(struct Trie *ppTrie, char *word) {

    if (ppTrie == NULL)
        return;

    struct Trie *temp = ppTrie;

    int length = strlen(word);

    for (int i =0; i <length; i++) {
        int index = word[i] - 'a';
        if ( temp->numChildren[index] == NULL)
             temp->numChildren[index]= malloc(sizeof(struct Trie));
       temp = temp->numChildren[index];
    }
    temp->numWords= temp->numWords+1;
}

int numberOfOccurances(struct Trie *pTrie, char *word){

    struct Trie *temp = pTrie;
    int length = strlen(word);
    for (int i = 0; i < length; i++) {
        int index = word[i]-'a';
        if (temp->numChildren[index] == NULL)
            return 0;
        temp = temp->numChildren[index];
    }
    return temp->numWords;

}

struct Trie *deallocateTrie(struct Trie *pTrie) {

    if (pTrie == NULL)
        return NULL;

    for (int i = 0; i <26; i++){
        if (pTrie->numChildren[i] != NULL)
        deallocateTrie(pTrie->numChildren[i]);
    }
    free(pTrie);
    return NULL;
}
int main(void)
{
    struct Trie *dictionary = malloc(sizeof(struct Trie));
      // parse line by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};

      for (int i =0; i < 5; i++) {
        insert(dictionary, pWords[i]);
      }
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(dictionary, pWords[i]));
     }
    dictionary = deallocateTrie(dictionary);
    if (dictionary != NULL)
       printf("There is an error in this program\n");
    return 0;
}
