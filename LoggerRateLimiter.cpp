
class Logger{
public:
    /** Initialize your data structure here. */
    Logger() {}
    ~Logger() {}
    
    unordered_map<string, int> map;
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(timestamp < map[message]){
            return false;
        }
        map[message] = timestamp + 10;
        return true;
    }
};

