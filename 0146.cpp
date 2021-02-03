struct Node
{
    int val;
    int key;
    Node *next = NULL;
    Node *prev = NULL;
};

class LRUCache
{
public:
    unordered_map<int, Node *> cache;
    int capacity;
    int size;
    Node *head;
    Node *tail;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }

    int get(int key)
    {
        if (this->cache.find(key) == cache.end())
        {
            return -1;
        }
        put(key, this->cache[key]->val);
        return this->cache[key]->val;
    }

    void put(int key, int value)
    {

        // if value is in cache, then update the head and return
        if (cache.find(key) != cache.end())
        {

            Node *ptr = this->cache[key];
            ptr->val = value;

            if (head != ptr)
            { // we only need to change the position if it's not at the head already

                ptr->prev->next = ptr->next; // since it's not the head node, then it has a prev

                if (ptr->next)
                { // if the ptr isn't the tail
                    ptr->next->prev = ptr->prev;
                }

                else
                {
                    tail = ptr->prev; // if tail, update the value
                }

                ptr->next = this->head;
                if (head != NULL)
                {
                    head->prev = ptr;
                }
                head = ptr;
                if (tail == NULL)
                {
                    tail = head;
                }
                ptr->prev = NULL;
            }

            return;
        }

        // if value not in cache and we're at capacity, delete the LRU
        else if (size == capacity)
        {
            // erase the node at the tail
            Node *ptr = tail->prev;
            cache.erase(tail->key);
            delete tail;
            if (ptr)
            {
                ptr->next = NULL;
            }
            tail = ptr;
            if (!tail)
            {
                head = ptr;
            }
            size--;
        }

        // insert new node into the cache
        Node *newNode = new Node;
        newNode->next = head;
        newNode->prev = NULL;
        newNode->val = value;
        newNode->key = key;

        if (head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;

        if (tail == NULL)
        {
            tail = head;
        }

        cache[key] = newNode;
        size++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */