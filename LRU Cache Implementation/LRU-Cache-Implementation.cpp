#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int key,val;
        Node *next,*prev;
        
        Node(int key,int val)
        {
            this->key = key;
            this->val = val;
            next = NULL;
            prev = NULL;
        }
};

class LRUCache {
    
public:
    unordered_map<int,Node*> cache;
    int size;
    int empty_cell;
    Node *head, *tail;
    
    LRUCache(int size){
        this->size = size;
        empty_cell = size;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        /** check if the value is present in the cache then return it and move it to front **/
        if(cache.find(key) != cache.end())
        {
            // key is there in the cache
            // move the block to the front - handle all 3 cases
            // 1 - both front and tail are at the same block
            // 2 - block is at tail 
            // 3 - block is somewhere in the middle
            
            Node *t = cache[key];
            
            int value = 0;
            if(head == t)
            {
                value = head->val;
                return value;
            }
            else if(tail == t)
            {
                tail = tail->prev;
                tail->next = NULL;
                t->prev = NULL;
                t->next = head;
                head->prev = t;
                head = t;
                value = t->val;
                return value;
            }
            else
            {
                value = t->val;
                t->prev->next = t->next;
                t->next->prev = t->prev;
                t->prev = NULL;
                t->next = head;
                head->prev = t;
                head = t;
                return value;
            }
        }
        else
        {
            // key is not there in the cache
            return -1;
        }
    }
    
    void put(int key, int value) {
        /** put the key and the value into the cache 
            check for all 2 cases -
            1 - if key is already there in the cache - move it to front and update the value if any
            2 - if key is not there in the cache - handle 3 subcases
                a - put it into cache if it is the first element 
                b - put it into cache if there is space in the cache
                c - if there is no space then use LRU eviction policy and then put the block into the cache
        **/
        
        if(cache.find(key) != cache.end())
        {
            // key is already there in the cache
            Node *t = cache[key];
            t->val = value;
            int va = get(key);  // this will move the block to the front no matter where it is;
            return;
        }
        else
        {
            // key is not there in the cache 
            Node *t = new Node(key,value);
            cache[key] = t;
            
            // Now insert the block into the linked list
            if(empty_cell == size)
            {
                head = t;
                tail = t;
                empty_cell--;
                return;
            }
            else if(empty_cell != 0)
            {
                t->next = head;
                head->prev = t;
                head = t;
                empty_cell--;
                return;
            }
            else
            {
                // use LRU eviction policy to remove element from the cache and put this new element 
                Node *temp = tail;
                int k = temp->key;
                cache.erase(k);
                if(tail == head)
                {
                    tail = NULL;
                    head = NULL;
                    tail = t;
                    head = t;
                }
                else{
                    tail = tail->prev;
                    t->next = head;
                    head->prev = t;
                    head = t;
                }
                delete temp;
                return;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
 
 int main()
 {
    
   LRUCache* cache = new LRUCache(2);
 	
 	cache->put(1,1);
 	cache->put(2,2);
 	cout<<cache->get(1)<<endl;
 	cache->put(3,3);
 	cout<<cache->get(2)<<endl;
 	cache->put(4,4);
 	cout<<cache->get(1)<<endl;
 	cout<<cache->get(3)<<endl;
 	cout<<cache->get(4)<<endl;

 	return 0;
 }
 
