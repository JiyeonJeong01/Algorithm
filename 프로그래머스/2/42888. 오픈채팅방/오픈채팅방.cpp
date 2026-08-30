#include <bits/stdc++.h>

using namespace std;

const string ENTER_MSG = "님이 들어왔습니다.";
const string LEAVE_MSG = "님이 나갔습니다.";

enum class MsgType { Enter, Leave, None };

struct Log 
{
    MsgType msgType = MsgType::None;
    string uid = "";
};

void GetTokens(const string& r, string& msgType, string& uid, string& nickname)
{    
    int idx = 0;
    
    for (; idx < r.size(); ++idx)
    {
        if (r[idx] == ' ') break;
        msgType.push_back(r[idx]);
    }
    
    ++idx;
    for (; idx < r.size(); ++idx)
    {
        if (r[idx] == ' ') break;
        uid.push_back(r[idx]);
    }
    
    ++idx;
    for (; idx < r.size(); ++idx)
    {
        if (r[idx] == ' ') break;
        nickname.push_back(r[idx]);
    }
}

MsgType GetMsgType(const string& msgType)
{
    if (msgType == "Enter")
        return MsgType::Enter;
    if (msgType == "Leave")
        return MsgType::Leave;
    return MsgType::None;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    map<string, string> users;
    vector<Log> logs;
    
    for (const string& r : record)
    {
        string msgStr = "", uid = "", nickname = "";
        GetTokens(r, msgStr, uid, nickname);
        
        // 단순 닉네임 변경
        if (msgStr == "Change")
        {
            users[uid] = nickname;
            continue;
        }
        
        // 입퇴장 로그 생성
        MsgType msgType = GetMsgType(msgStr);
        logs.push_back({msgType, uid});
        
        // 입장
        if (msgType == MsgType::Leave)
            continue; 
        if(users.find(uid) != users.end())
            users[uid] = nickname;
        else 
            users.insert({uid, nickname});
        
    }

    for (const auto& log : logs)
    {
        const auto& it = users.find(log.uid);
        const string& nickname = it->second;
        
        if (log.msgType == MsgType::Enter)
            answer.push_back(nickname+ENTER_MSG);
        else if (log.msgType == MsgType::Leave)
            answer.push_back(nickname+LEAVE_MSG);
    }
    
    return answer;
}