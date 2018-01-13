#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Trie
{
    bool eow;
    struct Trie *arr[26];
};
struct Trie* createNode()
{
    struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie)); 
    node->eow = false;
    for(int i=0;i<26;i++)
    {
        node->arr[i]=NULL;
    }
    return node;
}

void insert(struct Trie *t, char *ch)
{
    //cout<<*ch;
    if(*ch == NULL)
    {
        t->eow = true;
        return;
    }
    struct Trie *node = t->arr[( (int(*ch) )-97)];
    if(node == NULL)
    {
        node = createNode();
        t->arr[( (int(*ch) )-97)] = node;
        
    }
    insert(node,ch+1);
}
bool hasAnyChild(struct Trie *t)
{
    for(int i=0;i<25;i++)
    {
        if(t->arr[i] !=NULL)
        return true;
    }
    return false;
    
    
}
bool search(struct Trie *t, char *ch, bool searchPrefix)
{
    //cout<<*ch;
  if(*ch == NULL)
  {
      if(t->eow == true)
      return true;
      if(searchPrefix)
      return true;
      else 
      return false;
      
  }
  struct Trie *node = t->arr[(int(*ch)-97)];
  if(node ==NULL)
  {
   cout<<*ch;      
   return false;    
  }
  
  //cout<<"End of word "<<node->eow;
  return search(node,ch+1,searchPrefix);
}

int deleteWord(struct Trie *head, char *ch)
{
    if(*ch == NULL)
  {
      head->eow = false;
      if(hasAnyChild(head))
      {
          return -1;
      }
      else return 1;
  }
  struct Trie *node = head->arr[(int(*ch)-97)];
  if(node != NULL)
  {
    int a = deleteWord(node,ch+1);
    if(a==1)
    {
        head->arr[(int(*ch)-97)] = NULL;
        if(head->eow == true || hasAnyChild(head))
        {
            return -1; //Need not to be deleted
        }
        else return 1;    
    }
    
  }
  return -1;
}
int main() 
{
    struct Trie *head = createNode();
    char ch[] ={'h','e','l','l','o',NULL};
    char ch1[] ={'h','e','l','d',NULL};
    char ch2[] ={'h','e','l','l',NULL};
    char *word = ch;
    insert(head,word);
    word = ch1;
    insert(head,word);
    word = ch2;
    insert(head,word);
    
    char ch3[] ={'h','e','l','l','o',NULL};
    char ch4[] ={'h','e','l','d',NULL};
    char ch5[] ={'h','e','l','l',NULL};
    char *searchWord = ch3;
    cout<<search(head,searchWord,false); //searching hello
    searchWord = ch4;
    cout<<search(head,searchWord,false); //searching held
    searchWord = ch5;
    cout<<search(head,searchWord,false); //searching hell
    
    deleteWord(head,searchWord);  //deleting hell
    
    cout<<searchWord<<endl;
    cout<<search(head,searchWord,true); //search held
    cout<<search(head,searchWord,false); //search held
    cout<<search(head,ch3,false); //search held
    cout<<search(head,ch4,false); //search held
    cout<<search(head,ch5,false); //search held
    //searchWord = ch4
   // cout<<search(head,searchWord,true);
    
}
