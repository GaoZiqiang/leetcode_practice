/* T146:LRU 缓存 https://leetcode-cn.com/problems/lru-cache/
 * 思路：
 * 参考：https://leetcode-cn.com/problems/lru-cache/solution/146-lru-huan-cun-ji-zhi-cxiang-xi-ti-jie-ulv8/
 * 方法：双向链表+哈希表 O(1)
 * */

// 定义双向链表
struct Node {
    int key, value;
    Node* pre, *next;
    Node(int _key, int _value) : key(_key), value(_value), pre(nullptr), next(nullptr) {}
}*L, *R;

// 存放所有(key, value)的hashmap，用于快速查找O(1)
unordered_map<int, Node*> cache;

int capacity;

void remove(Node* p) {
    p->pre->next = p->next;
    p->next->pre = p->pre;
}

void insert(Node* p) {// 插到头结点L的后边
    p->next = L->next;
    p->pre = L;
    L->next->pre = p;
    L->next = p;
}

LRUCache(int capacity) {
    this->capacity = capacity;
    L = new Node(-1, -1), R = new Node(-1, -1);
    L->next = R;
    R->pre = L;
}

int get(int key) {
    if (cache.count(key) == 0) return -1;// 不存在
    auto p = cache[key];
    remove(p);
    insert(p);// p插入到表头
    return p->value;
}

void put(int key, int value) {
    if (cache.count(key) != 0) {// 已存在
        auto p = cache[key];
        p->value = value;// 更新value值
        remove(p);
        insert(p);
    } else {// 不存在
        if (cache.size() == this->capacity) {// cache已满
            auto p = R->pre;// 最右边节点R->pre
            remove(p);// 删除双链表中最右边/最不常用节点
            cache.erase(p->key);
            delete p;// 释放内存
            // p = nullptr;
        }
        // cache未满，插入(key, value)
        auto p = new Node(key, value);
        cache[key] = p;
        insert(p);
    }
    return;
}