#pragma once
typedef struct sqlite3 sqlite3;

class Database {
    public:
        Database();
        ~Database();
        static string GetErrorStr(int code);
        static wstring GetErrorWStr(int code);
        int Open(string path);
        int Close();
        int ErrCode();
        bool Opened();
    private:
        sqlite3* m_db = nullptr;
};
