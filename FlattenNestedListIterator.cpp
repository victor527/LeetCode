/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// Trial 1 Use a queue and dfs to find the elements of each integer in the nested list
class NestedIterator {
public:
    queue<int> q;
    void dfs(queue<int>& q, vector<NestedInteger>& nestedList){
        for(int i = 0; i < nestedList.size(); i++){
            if(nestedList[i].isInteger()){
                q.push(nestedList[i].getInteger());
            }
            else{
                dfs(q, nestedList[i].getList());
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(q, nestedList);
    }

    int next() {
        if(hasNext()){
            int num = q.front();
            q.pop();
            return num;
        }
        return -1;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

// Trial 2 with a stack to store all the variables. Stack is FILO so we are reading the integer from the end of the nestedList.
class NestedIterator {
private:
    stack<NestedInteger> s;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--){
            s.push(nestedList[i]);
        }
    }

    int next() {
        NestedInteger t = s.top();
        s.pop();
        return t.getInteger();
    }

    bool hasNext() {
        while(!s.empty()){
            NestedInteger t = s.top();
            if(t.isInteger()) return true;
            s.pop();
            for(int i = t.getList().size() - 1; i >= 0; i--){
                s.push(t.getList()[i]);
            }
        }
        return false;
    }
};

// Trial 3 with deque - double-ended queue is an index sequence allows fast insertion and deletion at both its beginning and its end.
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            d.push_back(a);
        }
    }

    int next() {
        NestedInteger t = d.front(); d.pop_front();
        return t.getInteger();
    }

    bool hasNext() {
        while (!d.empty()) {
            NestedInteger t = d.front();
            if (t.isInteger()) return true;
            d.pop_front();
            for (int i = 0; i < t.getList().size(); ++i) {
                d.insert(d.begin() + i, t.getList()[i]); // Different from stack, insert the number into the queue.
            }
        }
        return false;
    }

private:
    deque<NestedInteger> d;
};

