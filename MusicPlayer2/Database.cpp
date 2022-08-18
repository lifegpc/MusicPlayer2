#include "stdafx.h"
#include "Database.h"
#define SQLITE_API __declspec(dllimport)
#include "sqlite3/sqlite3.h"
#include "Common.h"

Database::Database() {
}

Database::~Database() {
    Close();
}

string Database::GetErrorStr(int code) {
    return sqlite3_errstr(code);
}

wstring Database::GetErrorWStr(int code) {
    return CCommon::StrToUnicode(GetErrorStr(code), CodeType::UTF8_NO_BOM);
}

int Database::Close() {
    if (m_db) {
        int r = sqlite3_close(m_db);
        if (r == SQLITE_OK) {
            m_db = NULL;
        }
        return r;
    }
    return 0;
}

int Database::ErrCode() {
    if (m_db) {
        return sqlite3_errcode(m_db);
    }
    return 0;
}

int Database::Open(string path) {
    if (m_db) {
        return SQLITE_OK;
    }
    return sqlite3_open_v2(path.c_str(), &m_db, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE | SQLITE_OPEN_FULLMUTEX, "");
}

bool Database::Opened() {
    return m_db != NULL;
}
