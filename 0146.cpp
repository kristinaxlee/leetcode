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
        if (this->cache.find(key) != cache.end())
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
                    this->tail = ptr->prev; // if tail, update the value
                }

                ptr->next = this->head;
                if (this->head != NULL)
                {
                    head->prev = ptr;
                }
                this->head = ptr;
                if (this->tail == NULL)
                {
                    this->tail = this->head;
                }
                ptr->prev = NULL;
            }

            return;
        }

        // if value not in cache and we're at capacity, delete the LRU
        else if (this->size == this->capacity)
        {
            // erase the node at the tail
            Node *ptr = this->tail->prev;
            this->cache.erase(this->tail->key);
            delete this->tail;
            if (ptr)
            {
                ptr->next = NULL;
            }
            this->tail = ptr;
            if (!this->tail)
            {
                this->head = ptr;
            }
            this->size--;
        }

        // insert new node into the cache
        Node *newNode = new Node;
        newNode->next = this->head;
        newNode->prev = NULL;
        newNode->val = value;
        newNode->key = key;

        if (this->head != NULL)
        {
            head->prev = newNode;
        }

        this->head = newNode;

        if (this->tail == NULL)
        {
            this->tail = this->head;
        }

        this->cache[key] = this->head;
        this->size++;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */