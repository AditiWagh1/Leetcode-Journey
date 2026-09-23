class LRUCache {
public:
class Node{
    public:
    int key,value;
    Node* prev;
    Node* next;
    Node(int k,int v)
    {
        key=k;
        value=v;
        prev=nullptr;
        next=nullptr;
    }
};
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int limit;
    void addNode(Node* newnode)
    {
        Node* oldnext=head->next;
        head->next=newnode;
        oldnext->prev=newnode;
        newnode->prev=head;
        newnode->next=oldnext;
    }
    void deleteNode(Node* oldnode)
    {
        Node* oldprev=oldnode->prev;
        Node* oldnext=oldnode->next;
        oldprev->next=oldnext;
        oldnext->prev=oldprev;
    }
    LRUCache(int capacity) {
        limit=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        Node* ansnode=mp[key];
        int ans=ansnode->value;
        mp.erase(key);
        deleteNode(ansnode);
        addNode(ansnode);
        mp[key]=ansnode;
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node* oldtemp=mp[key];
            deleteNode(oldtemp);
            mp.erase(key);
        }
        if(mp.size()==limit)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node *newNode=new Node(key,value);
        addNode(newNode);
        mp[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */